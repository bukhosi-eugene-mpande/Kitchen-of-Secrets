#ifndef HALLOWEEN_ORDER_BUILDER_H
#define HALLOWEEN_ORDER_BUILDER_H

#include "OrderBuilder.h"
#include "DrinksMenuFactory.h"
#include "FoodMenuFactory.h"

class HalloweenOrderBuilder: public OrderBuilder{	
    private:
        std::shared_ptr<DrinksMenuFactory> drinksMenuFactory;
        std::shared_ptr<FoodMenuFactory> foodMenuFactory;
    public:
        HalloweenOrderBuilder();
        ~HalloweenOrderBuilder();
        void addDrink();
        void addFood();
};
#endif
