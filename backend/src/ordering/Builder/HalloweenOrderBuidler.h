#ifndef HALLOWEENORDERBUILDER_H
#define HALLOWEENORDERBUILDER_H
#include "OrderBuilder.h"
#include "DrinksMenuFactory.h"
#include "FoodMenuFactory.h"
class HalloweenOrderBuilder: public OrderBuilder{
    	
    private:
        DrinksMenuFactory drinksMenuFactory;
        FoodMenuFactory foodMenuFactory;

    public:
        HalloweenOrderBuilder();
        void addDrink() override;
        void addFood() override;
};
#endif
