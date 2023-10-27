#include "crow.h"
#include "accounting/Accounting.h"

int main()
{
    crow::SimpleApp app;

    auto accounting = std::make_shared<Accounting>();

    CROW_ROUTE(app, "/close")([accounting](){
        return crow::response(std::string(accounting->closeTab().dump()));
    });

    CROW_ROUTE(app, "/pay")([accounting](){
        return crow::response(std::string(accounting->pay(35, "cash").dump()));
    });

    app.port(18080).multithreaded().run();
}