#include "GameEngine.h"

/*
void GameEngine::createGameComponents() {
    tab = std::make_shared<Tab>(this);
    billing = std::make_shared<Billing>(this);
    foodInventory = std::make_shared<FoodInventory>(this);
    beverageInventory = std::make_shared<BeverageInventory>(this);
    baker = std::make_shared<Baker>();
    cook = std::make_shared<Cook>();
    grillChef = std::make_shared<GrillChef>();
    fryChef = std::make_shared<FryChef>();
    headChef = std::make_shared<HeadChef>();
    kitchen = std::make_shared<Kitchen>();
    food = std::make_shared<Food>();
    beverage = std::make_shared<Beverage>();
    order = std::make_shared<Order>();
}
*/
GameEngine::GameEngine() : Engine() {}

GameEngine::~GameEngine() {}

void GameEngine::notify(std::shared_ptr<GameComponent> sender, std::string event) {
    for (std::shared_ptr<GameComponent> component : components) {
        if (component != sender) {
            component->receiveEvent(event);
        }
    }
}

void GameEngine::registerComponent(std::shared_ptr<GameComponent> component) {
    components.push_back(component);
}

void GameEngine::unregisterComponent(std::shared_ptr<GameComponent> component) {
   auto it = std::find(components.begin(), components.end(), component);
    if (it != components.end()) {
        components.erase(it);
    }
}

/*
void GameEngine::notify(std::shared_ptr<GameComponent> sender, std::string message) {
    std::shared_ptr<GameComponent> gameComponent;
    if (gameComponent == billing) {
        //TODO: NEED TO FIND A WAY TO PUT IN THE CUSTOMER AMOUNT
        billing->pay(200000.00);
    } else if (gameComponent == tab) {
        std::shared_ptr<TabState> state;
        if (message == "Open Tab") {
            state = std::make_shared<OpenTab>(tab);
            tab->setState(state);
        } else if (message == "Close Tab") {
            state = std::make_shared<CloseTab>(tab);
            tab->setState(state);
        } else if (message == "Overdue Tab") {
            state = std::make_shared<OverdueTab>(tab);
        } else if (message == "Get Bill Total") {
            state->getBillTotal();
        } else {
            //TODO: NEED TO FIND A WAY TO PUT IN THE CUSTOMER AMOUNT
            state->addOrderCost(200000.00);
        }
    } else if (gameComponent == foodInventory) {
        //TODO: NEED TO FIND A WAY TO PUT IN THE ITEMS
        foodInventory->update();
    } else if (gameComponent == beverageInventory) {
        //TODO: NEED TO FIND A WAY TO PUT IN THE ITEMS
        beverageInventory->update();
    } else if (gameComponent == baker) {
        baker->prepareOrder();
    } else if (gameComponent == cook) {
        cook->prepareOrder();
    } else if (gameComponent == grillChef) {
        grillChef->prepareOrder();
    } else if (gameComponent == fryChef) {
        fryChef->prepareOrder();
    } else if (gameComponent == headChef) {
        if (message == "GO ON ROUNDS") {
            headChef->goOnRounds();
        } 
        if (message == "HANDLE COMPLAINT") {
            headChef->handleComplaint();
        }
    } else if (gameComponent == kitchen) {
        if (message == "ADD MEAL") {
            kitchen->addMeal();
        }
        if (message == "ADD ORDER") {
            kitchen->addOrder();
        }
        if (message == "REMOVE MEAL") {
            kitchen->removeMeal();
        }
        if (message == "GET PREPARED ORDER") {
            kitchen->getPreparedOrder();
        }
        if (message == "GET CANCELED ORDER") {
            kitchen->getCanceledOrder();
        }
    } else if (gameComponent == food) {
        if (message == "CALCULATE PRICE") {
            food->calculatePrice();
        } else {
            food->calculateIngredients();
        }
    } else if (gameComponent == beverage) {
        if (message == "IS ALCHOLIC") {
            beverage->calculateIngredients();
        } else if (message == "CALCULATE PRICE") {
            beverage->calculatePrice();
        }
    } else if (gameComponent == order) {
        if (message == "CALCULATE PRICE") {
            order->calculatePrice();
        } else if (message == "CALCULATE INGREDIENTS") {
            order->calculateIngredients();
        } else if (message == "ADD MEAL") {
            order->addMeal();
        } else if (message == "REMOVE MEAL") {
            order->removeMeal();
        } else if (message == "CANCEL MEAL") {
            order->setIsCancelled(false);
        } else if (message == "ORDER TABLE NUMBER") {
            order->getTableNumber();
        }
    } else if 
}


void GameEngine::reactOnGameComponent(int index) {
}
*/