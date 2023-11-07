#include <mutex>
#include <vector>
#include <string>
#include <unordered_set>

#include "crow.h"
#include "crow/middlewares/cors.h"

#include "../tests/includes/include_all.h"
#include "../tests/includes/include_all.cpp"

int main()
{
    std::mutex mtx;
    crow::App<crow::CORSHandler> app;

    GameRunner* gameRunner = new GameRunner();

    crow::websocket::connection* c_Eat = nullptr;
    crow::websocket::connection* c_Order = nullptr;
    crow::websocket::connection* c_Payment = nullptr;
    crow::websocket::connection* c_Reservation = nullptr;

    crow::websocket::connection* s_Cook = nullptr;
    crow::websocket::connection* s_Order = nullptr;
    crow::websocket::connection* s_Floor = nullptr;
    crow::websocket::connection* s_Accounting = nullptr;
    crow::websocket::connection* s_Reservations = nullptr;

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
                else if (s_Cook == nullptr && data == "S-Cook")
                {
                    s_Cook = &conn;
                    CROW_LOG_INFO << "Staff Cook Connected";
                }
                else if (c_Eat == nullptr && data == "C-Eat")
                {
                    c_Eat = &conn;
                    CROW_LOG_INFO << "Staff Cook Connected";
                }
                else if (s_Floor == nullptr && data == "S-Floor")
                {
                    s_Floor = &conn;
                    CROW_LOG_INFO << "Customer Floor Connected";
                }
                else if (c_Payment == nullptr && data == "C-Payment")
                {
                    c_Payment = &conn;
                    CROW_LOG_INFO << "Customer Payment Connected";
                }
                else if (s_Accounting == nullptr && data == "S-Accounting")
                {
                    s_Accounting = &conn;
                    CROW_LOG_INFO << "Staff Accounting Connected";
                }
                else if (data == "C-Reservation" || data == "S-Reservations" || data == "C-Order" || data == "S-Order" || data == "S-Cook" || data == "C-Eat" || data == "C-Payment" || data == "S-Accounting" || data == "S-Floor")
                {
                    CROW_LOG_INFO << "Connection already established";
                }
                else
                {
                    json jsonData = json::parse(data);

                    if (jsonData["type"] == "make-res")
                    {
                        std::cout << jsonData.dump(4) << std::endl;
                        std::cout << jsonData["data"]["section"] << std::endl;
                        gameRunner->requestReservation(jsonData["data"]["section"]);
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
                        std::unordered_map<std::string,int> food;
                        std::vector<json> foodOrder = jsonData["data"]["order"]["food"];

                        for (json item:foodOrder)
                        {
                            food.insert({item["name"],1});
                        }

                        std::unordered_map<std::string,int> beverages;
                        std::vector<json> beverageOrder = jsonData["data"]["order"]["beverages"];

                        for (json item:beverageOrder)
                        {
                            beverages.insert({item["name"],1});
                        }

                        gameRunner->sendFoodOrder(food);
                        gameRunner->sendBeverageOrder(beverages);

                        s_Order->send_text(data);
                        c_Payment->send_text(data);
                        CROW_LOG_INFO << "Order request sent to staff";
                    }
                    else if(jsonData["type"] == "receive-order")
                    {
                        c_Order->send_text(data);
                        CROW_LOG_INFO << "Order accepted by staff";
                    }
                    else if(jsonData["type"] == "cook-order")
                    {
                        s_Cook->send_text(data);
                        CROW_LOG_INFO << "Order cooking by staff";
                    }
                    else if (jsonData["type"] == "change-mood")
                    {
                        s_Cook->send_text(data);
                        gameRunner->changeMood();
                        CROW_LOG_INFO << "Mood changed by customer";
                    }
                    else if(jsonData["type"] == "serve-order")
                    {
                        c_Eat->send_text(data);
                        CROW_LOG_INFO << "Order served to customer";
                    }
                    else if(jsonData["type"] == "do-rounds")
                    {
                        s_Floor->send_text(data);
                        gameRunner->doRoundsWaiter();
                        CROW_LOG_INFO << "Checking on customers";
                    }
                    else if(jsonData["type"] == "open-tab")
                    {
                        std::cout<<jsonData.dump(4)<<std::endl;

                        //gameRunner->addToTab(total);
                        s_Accounting->send_text(data);
                        CROW_LOG_INFO << "Tab opened";
                    }
                    else if(jsonData["type"] == "make-payment")
                    {
                        s_Accounting->send_text(data);
                        gameRunner->payment(jsonData["data"]["paymentMethod"], jsonData["data"]["total"]);
                        CROW_LOG_INFO << "Payment received by staff";
                    }
                    else
                    {
                        CROW_LOG_INFO << "Unknown message received";
                    }
                }
            }
        }
    );

    app.port(8000).multithreaded().run();
}