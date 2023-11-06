# Name: Chenoa Perkett
# Student Number: u19109572

# My Responsibilities In The Project: 
-Customer care and front-end development

# System Name: CustomerCare
# What Is The Customer Care Systems's Purpose:
-Customer care involves the Satisfaction of the customer, the includes To manage customer experience in your restaurant simulator and manage rounds and visit tables by the  the Chefs as well as waiters and managers may do to ensure that the customer is happy and good service has been provided

# What Are The Customer Care System's Components:
Customer Care System's Components include the state of the customer and the rounds and visit tables by the Chefs as well as waiters and managers

# What Design Patterns Does The Customer Care System Use:
Customer ares uses 
- the State Pattern:

Implement the State pattern to model different states of customer satisfaction. The customer's satisfaction level can transition between states like "happy," "neutral," and "unhappy" based on their interactions with the staff and the service they receive.

- Observer Pattern:

Implement the Observer pattern to manage customer satisfaction. The customers can be subjects, and the restaurant staff (waiters, chefs, and managers) can be observers. When staff members visit a table or take specific actions (e.g., addressing complaints or providing fast service), they can notify the customer about the service improvements, which can affect the customer's happiness/state

- Command Pattern and the Iterator Pattern 
In the context of managing the round-robin scheduling of chefs and waiters visiting tables, where each visit is encapsulated as a command

Incorporating the Iterator Pattern into your design will allow chefs and waiters to take turns visiting tables in a round-robin fashion, ensuring a fair distribution of tasks and interactions with customers. This ensures that all tables receive attention and that customers have their needs addressed in a balanced manner.

The Command Pattern, can be used to encapsulate the actions performed during these visits (e.g., addressing customer complaints, providing quick service). The round-robin scheduling with the Iterator Pattern ensures that each staff member gets an equal opportunity to interact with customers.

This combination of patterns can help you efficiently manage and balance customer service while ensuring that every table is visited and customers' needs are addressed.

Chefs and waiters can request the next table visit command by using the iterator created by the TableQueue (ConcreteAggregate). The CommandQueue manages the queue of commands and executes them, ensuring that each table is visited in a round-robin manner, and specific actions are taken during the visit, as encapsulated by the Command objects.

# What Other Systems Does The Customer Care System Interact With:
- Management System
= Strategy Pattern:

Use the Strategy pattern for managing customer satisfaction strategies. Define different strategies for improving customer satisfaction, such as providing complimentary items, offering discounts, or addressing complaints. The restaurant staff can apply these strategies based on customer feedback or behavior.

= Chain of Responsibility Pattern:

Use the Chain of Responsibility pattern to handle customer complaints. Create a chain of complaint handlers, such as waiters, managers, or customer service representatives. When a customer registers a complaint, it can be passed through the chain of handlers, each responsible for addressing specific types of complaints.

# Diagrams

## UML Class Diagrams
![UML Class Diagram](Additional_Material/CustomerCare.png)

## Other UML Diagrams (activity, state, etc.)
