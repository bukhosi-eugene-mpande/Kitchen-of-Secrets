## Name: Joshua Tristan Wereley
## Student Number: u21506915

# My Responsibilities In The Project: 
1. **Implementing Management System:** Designed and extended the final UML class diagram and coded the functionality to interact with the different game components.
3. **Designing The UML Sequence Diagram:** 

# System Name: Management
# What Is The Management Systems's Purpose:
The management system's purpose is to employ a strategic approach to oversee interactions among the different game components; ensuring that each component's requests are harmoniously coordinated.

# What Are The Management System's Components:
The management system is divided into two subsystems, namely:
* **Game Engine System:** This subsystem serves as the focal point for managing interactions among a group of objects; encapsulating the way they communicate with each other. 
* **Player Interaction System:** This subsystem is responsible for encapsulating requests into objects, providing a means for parameterized clients to generate requests, manage request queues, and facilitate the reversal of changes.

# What Design Patterns Does The Management System Use:
The management system will use two design patterns; one for each subsystem:
* Mediator Pattern: 
    * **Objective:** To define an object that encapsulates interactions among a group of objects, fostering loose coupling by avoiding direct references between objects and enabling independent variations in their interactions.
    * **Rationale for Use:** The Mediator Pattern facilitates interaction between game components by notifying each component of changes and how these changes may impact other components.
    * **Illustrative Use Case:** For instance, the Accounting System could communicate with the Cooking System to check if there are sufficient ingredients for a particular dish.
* Command Pattern:
    * **Objective:** To encapsulate a request as an object, enabling the parameterization of clients with different requests, queuing or logging of requests, and supporting undoable operations.
    * **Rationale for Use:** This design pattern is applied to queue all requests made by various game components, ensuring that when these specific requests are invoked, they generate the required output.
    * **Illustrative Use Case:** Consider a scenario where a customer provides their order to the waiter. The waiter records the order and places it on the order counter, signaling "Order up!" The order object contains all the instructions for the cook to prepare the meal, and it is then handed to the customer through the waiter.

# What Other Systems Does Management System Interact With:
The management system will interact with all the systems, namely:
* **Accounting System:**
* **Reservation System:**
* **Customer Care System:**
* **Ordering System:**
* **Cooking System:**

# Diagrams

## UML Class Diagrams

## Other UML Diagrams (activity, state, etc.)
