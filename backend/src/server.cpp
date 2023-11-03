#include "crow.h"
#include "accounting/Accounting.h"

int main()
{
    crow::SimpleApp app;

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

    CROW_ROUTE(app, "/ws").websocket()
        .onopen([](crow::websocket::connection& conn) {
            std::cout << "new websocket connection" << std::endl;
        })

        .onerror([](crow::websocket::connection& conn, const std::string& error_message){
            std::cout << "error: " << error_message << std::endl;
        })

        .onclose([](crow::websocket::connection& conn) {
            std::cout << "websocket connection closed" << std::endl;
        })

        .onmessage([](crow::websocket::connection& conn, const std::string& data) {
            std::cout << "text message received: " << data << std::endl;
            conn.send_text("Received message: " + data);
        });

    app.port(8000).multithreaded().run();
}