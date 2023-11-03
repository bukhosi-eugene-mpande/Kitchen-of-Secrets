# Accounting System

## Author
- Name: **Ashley Kapaso**
- Student Number: **u21525600**

## Responsibilities
- Designing and implementing the **Accounting System** of our restaurant game.

## System Information

### Purpose
The accounting system is responsible for managing all the accounting related features. It ensures that:

- Tabs are able to be managed 🗂
- Customers have a variety of billing options 💵
- Inventory is correctly tracked 📦

### System Components
The accounting system is divided into three sub-systems:

1. **Tab System**
    - Responsible for managing the tabs to ensure they are up-to-date 🔄.

2. **Billing System**
    - Responsible for billing customers in various ways 💵.

3. **Inventory System**
    - Responsible for tracking inventory and ensuring stock is available 📊.

### Design Patterns
The system uses the following design patterns, one for each sub-system:

1. **State Pattern: 🔁**
   - Used in the Tab System.
   - Allows the tabs to have three states: open, closed, and overdue.
   - Enables different behaviors for tabs depending on their state.

2. **Strategy Pattern: 💡**
   - Used in the Billing System.
   - Allows for billing customers in different ways, such as card, cash, and multiple.
   - Provides flexibility for billing multiple clients at one table with different payment types.

3. **Observer Pattern: 👀**
   - Used in the Inventory System.
   - Observes the kitchen and allows the system to update the inventory as the kitchen uses ingredients.
   - Ensures correct tracking of stock availability.

### Interactions with Other Systems
The Accounting System interacts with two other systems:

1. **Management System**
   - Communicates with the Tab System.
   - Calls the `addOrderCost()` function of the Tab System to add the cost of the order to the customer's tab 🛒.

   - Communicates with the Billing System.
   - Calls the `pay()` function of the Billing System to pay off the customer's bill 👥.

2. **Cooking System**
   - Communicates with the Inventory System.
   - Calls the `useItem()` function, which notifies the inventory that stock has been used ❄.

## Diagrams

### UML Class Diagrams

#### Billing System
![Billing System UML Class Diagram](<Billing System.png>)

#### Tab System
![Tab System UML Class Diagram](<image.png>)

#### Inventory System
![Inventory System UML Class Diagram](<Inventory System.png>)

### Other UML Diagrams (activity, state, etc.)
Coming soon...