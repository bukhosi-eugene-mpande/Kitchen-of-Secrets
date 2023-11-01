#include "crow.h"
#include "accounting/Accounting.h"
#include "crow/middlewares/cors.h"

#include <mutex>
#include <unordered_set>

int main()
{
    crow::App<crow::CORSHandler> app;

    std::mutex mtx;

    crow::websocket::connection* staff = nullptr;
    crow::websocket::connection* customer = nullptr;

    auto accounting = std::make_shared<Accounting>();

    CROW_ROUTE(app, "/close")([accounting](){
        crow::response res(std::string(accounting->closeTab().dump()));
        res.add_header("Content-Type", "application/json");
        return res;
    });

    CROW_ROUTE(app, "/pay")([accounting](){
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
        .onopen([&](crow::websocket::connection& /*conn*/){

            std::lock_guard<std::mutex> _(mtx);

            CROW_LOG_INFO << "New Connection";
        })

        .onclose([&](crow::websocket::connection& /*conn*/, const std::string& reason){
            CROW_LOG_INFO << reason;
        })

        .onerror([&](crow::websocket::connection& /*conn*/) {
            CROW_LOG_INFO << "Websocket Error!";
        })

        .onmessage([&](crow::websocket::connection& conn, const std::string& data, bool is_binary){
            std::lock_guard<std::mutex> _(mtx);

            if (is_binary)
            {
                CROW_LOG_INFO << "Binary message received";
            }
            else if (data == "Customer")
            {
                customer = nullptr;
                customer = &conn;
            }
            else if (data == "Staff")
            {
                staff = nullptr;
                staff = &conn;
            }
            else
            {
                json jsonData = json::parse(data);

                if (jsonData["type"] == "make-res")
                {
                    staff->send_text(data);
                }
                else if(jsonData["type"] == "accept-res")
                {
                    customer->send_text(data);
                }
            }
        }
    );

    app.port(8000).multithreaded().run();
}