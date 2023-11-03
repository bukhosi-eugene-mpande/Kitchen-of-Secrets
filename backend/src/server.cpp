#include "crow.h"
#include "accounting/Accounting.h"
#include "crow/middlewares/cors.h"

#include <mutex>
#include <unordered_set>

int main()
{
    crow::App<crow::CORSHandler> app;

    std::mutex mtx;

    crow::websocket::connection* c_Order = nullptr;
    crow::websocket::connection* c_Reservation = nullptr;


    crow::websocket::connection* s_Order = nullptr;
    crow::websocket::connection* s_Reservations = nullptr;


    auto accounting = std::make_shared<Accounting>();

    CROW_ROUTE(app, "/close")([accounting](){
        crow::response res(std::string(accounting->closeTab().dump()));
        res.add_header("Content-Type", "application/json");
        return res;
    });

    CROW_ROUTE(app, "/payy")([accounting](){
        crow::response res(std::string(accounting->pay(35, "cash").dump()));
        res.add_header("Content-Type", "application/json");
        return res;
    });

    CROW_ROUTE(app, "/reservation").methods("POST"_method)([](const crow::request& req){

        std:: cout << "Reservation Request: \n" + req.body << std::endl;

        crow::response res("{\"available\": \"yes\"}");
        res.add_header("Content-Type", "application/json");
        res.code = 200;
        
        return res;
    });

    CROW_ROUTE(app, "/ws")
        .websocket()
        .onopen([&](crow::websocket::connection& conn){
            std::lock_guard<std::mutex> _(mtx);
            CROW_LOG_INFO << "New Connection: " + conn.get_remote_ip();
        })

        .onclose([&](crow::websocket::connection& conn, const std::string& reason){
            CROW_LOG_INFO << "Connection: " + conn.get_remote_ip() + " closed because " + reason;
        })

        .onmessage([&](crow::websocket::connection& conn, const std::string& data, bool is_binary){
            std::lock_guard<std::mutex> _(mtx);

            if (is_binary)
            {
                CROW_LOG_INFO << "Binary message received";
            }
            else
            {
                if (c_Reservation == nullptr && data == "C-Reservation")
                {
                    c_Reservation = &conn;
                    CROW_LOG_INFO << "Customer Reservation Connected";
                }
                else if (s_Reservations == nullptr && data == "S-Reservations")
                {
                    s_Reservations = &conn;
                    CROW_LOG_INFO << "Staff Reservations Connected";
                }
                else if (c_Order == nullptr && data == "C-Order")
                {
                    c_Order = &conn;
                    CROW_LOG_INFO << "Customer Order Connected";
                }
                else if (s_Order == nullptr && data == "S-Order")
                {
                    s_Order = &conn;
                    CROW_LOG_INFO << "Staff Order Connected";
                }
                else if (data == "C-Reservation" || data == "S-Reservations" || data == "C-Order" || data == "S-Order")
                {
                    CROW_LOG_INFO << "Connection already established";
                }
                else
                {
                    json jsonData = json::parse(data);

                    if (jsonData["type"] == "make-res")
                    {
                        s_Reservations->send_text(data);
                        CROW_LOG_INFO << "Reservation request sent to staff";
                    }
                    else if(jsonData["type"] == "accept-res")
                    {
                        c_Reservation->send_text(data);
                        CROW_LOG_INFO << "Reservation accepted by staff";
                    }
                    else if(jsonData["type"] == "make-order")
                    {
                        s_Order->send_text(data);
                        CROW_LOG_INFO << "Order request sent to staff";
                    }
                    else if(jsonData["type"] == "cook-order")
                    {
                        c_Order->send_text(data);
                        CROW_LOG_INFO << "Order accepted by staff";
                    }
                }
            }
        }
    );

    app.port(8000).multithreaded().run();
}