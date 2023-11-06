// TODO: implement the class
#include "Waiter.h"
#include "../cooking/Drink.h"
#include "../cooking/Cuisine.h"
#include "Beverage.h"
#include "Food.h"
#include "../reservation/Table.h"

int Waiter::nextId = 1;

Waiter::Waiter(Section* section, Management* management){
    this->section = section;
    this->management = management;
    this->orderBuilder = std::make_shared<OrderBuilder>();
    this->createMenus();
    this->id = Waiter::nextId++;
    this->payType="";
}

Waiter::~Waiter() {

}

void Waiter::sendOrdersToKitchen()
{
    for(auto order : this->orders) {
        this->management->sendOrderToKitchen(order);
    }
}

void Waiter::sendBillToAccounting(double bill)
{
    accounting->receiveBill(bill);
}

// void Waiter::sendTypeToAccounting(std::string payType)
// {}

void Waiter::getPaymentTypeFromCustomer(std::shared_ptr<CustomerTemplate> customer)
{
    payType=customer->getPaymentType();
    accounting->receivePaymentType(payType);
}

std::vector<std::shared_ptr<MenuItem>> Waiter::takeDrinksOrder(std::shared_ptr<CustomerTemplate> customer,std::shared_ptr<Table> table) {
    //get payment type
    getPaymentTypeFromCustomer(customer);
    //commenc with order
    std::vector<std::shared_ptr<MenuItem>> beverages;
    std::unordered_map<std::string, int> drinks = customer->requestBeverageOrder(this->BeverageMenu);
    for(auto drk : drinks) {
        std::shared_ptr<Drink> drink = management->getDrink(drk.first);
        //Beverage(bool isAlcoholic,double price,std::string name, std::unordered_map<std::string,int> ingredients)
        std::shared_ptr<Beverage> bev = this->createDrinkItem(drink->getIsAlcoholic(),drink->getPrice(),drink->getName(),drink->getIngredients());
        int num = drk.second - 1;
        beverages.push_back(bev);
        for(int i = 0; i < num; i++) {
            std::shared_ptr<MenuItem> bevClone = bev->clone();
            beverages.push_back(bevClone);
        }
    }
    return beverages;
}

std::vector<std::shared_ptr<MenuItem>> Waiter::takeFoodOrder(std::shared_ptr<CustomerTemplate> customer,std::shared_ptr<Table> table) {
    
    //ask for payment type again if customeer didnt order drinks
    if(payType=="")
        getPaymentTypeFromCustomer(customer);
    
    std::vector<std::shared_ptr<MenuItem>> foods;
    std::unordered_map<std::string, int> meals = customer->requestFoodOrder(this->FoodMenu);
    for(auto meal : meals) {
        std::shared_ptr<Cuisine> cuisine = management->getCusine(meal.first);
        //Food(double price,std::string name, std::unordered_map<std::string,int> ingredients);
        std::shared_ptr<Food> cus = this->createFoodItem(cuisine->getPrice(),cuisine->getName(),cuisine->getIngredients());
        int num = meal.second - 1;
        foods.push_back(cus);
        for(int i = 0; i < num; i++) {
            std::shared_ptr<MenuItem> cusClone = cus->clone();
            foods.push_back(cusClone);
        }
    }
    return foods;
}

void Waiter::doOrderRounds() {
    orders.clear();
    orderBuilder->setWaiter(this);
    std::vector<std::shared_ptr<Table>> tables = this->section->getTables();
    for(auto table : tables ) {
        if(table->getIsOccupied() == false) {
            continue;
        }
        orderBuilder->reset();
        orderBuilder->setTable(table);
        std::vector<std::shared_ptr<CustomerTemplate>> customer = table->getCustomers();

        for(int i = 0; i < (int) customer.size(); i++) {
            std::vector<std::shared_ptr<MenuItem>> beverages = this->takeDrinksOrder(customer[i],table);
            std::vector<std::shared_ptr<MenuItem>> foods = this->takeFoodOrder(customer[i],table);
            for(auto bev : beverages) {
                this->orderBuilder->addMeal(bev);
            }
            for(auto food : foods) {
                this->orderBuilder->addMeal(food);
            }
        }
        std::shared_ptr<Order> order = orderBuilder->getOrder();
        this->orders.push_back(order);
    }
    this->sendOrdersToKitchen();
}

void Waiter::serveOrder(std::shared_ptr<Order> order) {
    std::vector<std::shared_ptr<Table>> tables = this->section->getTables();
    for(auto table : tables ) {
        if(table==order->getTable()) {
            std::vector<std::shared_ptr<CustomerTemplate>> customers = table->getCustomers();
            for(int i = 0; i < (int) customers.size(); i++) {
                customers[i]->setFinishedOrder(order);
                customers[i]->setDoneEating(true);
            }
        }
    }

}

double Waiter::billOrder(std::shared_ptr<Order> order) {
    return order->calculatePrice();
}

std::shared_ptr<Food> Waiter::createFoodItem(double price,std::string name, std::unordered_map<std::string,int> ingredients) {
    return std::make_shared<Food>(price,name,ingredients);
}

std::shared_ptr<Beverage> Waiter::createDrinkItem(bool isAlcoholic,double price,std::string name, std::unordered_map<std::string,int> ingredients) {
    return std::make_shared<Beverage>(isAlcoholic,price,name,ingredients);
}

void  Waiter::createMenus() {
    this->BeverageMenu=std::make_shared<Menu>(this->management->getDrinksMenu());
    this->FoodMenu=std::make_shared<Menu>(this->management->getCuisineMenu());
}

void Waiter::getCanceledOrderFromKitchen() {
    std::shared_ptr<Order> order = this->management->getCanceledOrderFromKitchen(this);
    this->serveOrder(order);
}

void Waiter::getOrderFromKitchen() {
    std::shared_ptr<Order> order = this->management->getOrderFromKitchen(this);
    this->serveOrder(order);
}

int Waiter::getId() {
    return this->id;
}

void Waiter::serveBill(){
    std::vector<std::shared_ptr<Table>> tables = this->section->getTables();
    for(auto table : tables ) {
        std::vector<std::shared_ptr<CustomerTemplate>> customers = table->getCustomers();
        for(int i = 0; i < (int) customers.size(); i++) {
            if(customers[i]->getDoneEating()){
                double bill = this->billOrder(customers[i]->getFinishedOrder());
                customers[i]->setTotalBill(bill);
                std::string reciept = this->management->pay(customers[i]->getPaymentType(),bill);
                reciepts.push_back(reciept);
                if(customers[i]->getName()!="NPC"){
                    customers[i]->leave();
                }
            }
            
        }
    }
    for(auto table : tables ) {
        std::vector<std::shared_ptr<CustomerTemplate>> customers = table->getCustomers();
        for(int i = 0; i < (int) customers.size(); i++) {
            if(customers[i]->getHasGuests()==true && customers[i]->getName()=="NPC"){
                customers[i]->leave();
            }
        }
    }
}

std::vector<std::string> Waiter::getRecipts(){
    return this->reciepts;
}









