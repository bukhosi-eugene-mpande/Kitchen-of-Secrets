# 🌟🍽️ **Kitchen System Documentation** 🍽️🌟

![Kitchen Banner](Additional_Material/kitchenBanner.jpg)

## Project Details

- **Student Number:** 21573558
- **My Responsibilities In The Project:** 🚀
  1. **Designing the Kitchen System:** Led the design phase, defining system architecture, and user interface. 🔨
  2. **Implementing the Kitchen System:** Developed the core functionalities and features of the kitchen system. 💻
  3. **DevOps:** Managed the deployment, continuous integration, and infrastructure setup for the project. ⚙️

## System Overview

- **System Name:** Kitchen 🍳
- **Purpose:** 🍽️

   The kitchen is the hub of activity where the entire order fulfillment process takes place. It plays a crucial role in ensuring smooth operations in a restaurant. Here's a breakdown of the kitchen's purpose and workflow:

   1. An order is initiated by a waiter and sent to the kitchen.
   2. Orders are handled as they come in and assigned to different chefs based on the type of meal.
   3. Various chefs work collaboratively on an order, making different components of the meal.
   4. The order may move between different chefs for various preparations before reaching the head chef.
   5. The head chef ensures the final assembly and quality check of the order.
   6. Once the order is complete, the kitchen notifies the waiter for order pickup. 🎉

## System Components

List the key components and modules of the Kitchen system: 🧰

1. Order
2. Meal
3. Chef
4. Kitchen

## Design Patterns for the Kitchen 🎨

1. **Template Method Pattern:** 📜
   To accommodate the diverse cooking methods required for different meals, we implement a Template Method pattern. Each meal type (e.g., chicken panini, beef panini) has a dedicated "cook" function. Within these functions, specific primitive operations, such as "addFilling," are executed to customize the cooking process. 🍔

2. **Composite Pattern:** 📊
   We employ the Composite pattern to determine the total price of an order and the necessary ingredients. The "Order" class acts as the composite, providing methods like "calculatePrice" and "calculateIngredients" to facilitate these calculations. 📋

3. **Observer Pattern:** 🔍
   For efficient order management, we utilize the Observer pattern. When an order is complete and added to the finished orders queue, the waiter is instantly notified. This notification prompts the waiter to retrieve the order and deliver it to the customer promptly. 🚀

4. **State Pattern:** 🚦
   Our chef hierarchy incorporates the State pattern, assigning different responsibilities to chefs at each level. For instance, a Level 1 Head Chef oversees administration, burger, and drink preparation. In Level 2, the Head Chef handles paninis and administration, while in Levels 3 and 4, the Head Chef exclusively manages administrative tasks. 👨‍🍳

5. **Chain of Responsibility Pattern:** 🔄
   To streamline the meal preparation process, we implement the Chain of Responsibility pattern. Each chef is responsible for a specific meal in an order. When an order is received, the Head Chef first performs administrative duties and then passes the order to the appropriate chef. Eventually, it circles back to the Head Chef for final delivery. For example, in a Level 1 kitchen, if an order includes a burger, chips, and a drink combo, the Head Chef manages administration, burger, and drink preparation before forwarding it to the fry chef for the chips, and finally, it returns to the Head Chef for serving. 🍟

## System Interactions in the Restaurant 🏢

1. **Accounting System:**
   The kitchen interacts with the accounting system to maintain ingredient inventory. When ingredient shortages are detected, the kitchen notifies the accounting system to order more supplies. Additionally, any upgrades or modifications to the kitchen's level are communicated to the accounting system to ensure accurate financial records. 💰

2. **Customer Care:**
   The head chef takes an active role in customer care by periodically checking on customers to ensure their satisfaction levels remain high. 😊

3. **Ordering System:**
   The ordering system facilitates the flow of orders within the restaurant. Customers place their orders with the waiter, who communicates these orders to the kitchen staff. In return, the kitchen notifies the waiter when an order is completed and ready for serving. This interaction ensures that orders are efficiently prepared and delivered to the customers in a timely manner. 📝

## Diagrams 📊

### UML Class Diagram

![UML Class Diagram](Additional_Material/UML-ClassDiagram.svg)
