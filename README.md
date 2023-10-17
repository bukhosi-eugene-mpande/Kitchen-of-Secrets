# COS214-Project
This repository will hold the final project for cos-214

BRIDGE PATTERN TEMP UML:

+---------------------------------------------------+
|                  SeatingPlan                      |
+---------------------------------------------------+
| -table: TableImplementation                       |
+---------------------------------------------------+
| +assignTable(): void                             |
| +markTableOccupied(): void                       |
| +isTableAvailable(): bool                        |
+---------------------------------------------------+
                    /             |             \
                   /              |              \
                  /               |               \
+-----------------+ +-----------------+ +-----------------+
| SmokingSection  | | PrivateSection  | | GeneralSection  |
+-----------------+ +-----------------+ +-----------------+
| +assignTable(): void | +assignTable(): void | +assignTable(): void |
| +markTableOccupied(): void | +markTableOccupied(): void | +markTableOccupied(): void |
| +isTableAvailable(): bool | +isTableAvailable(): bool | +isTableAvailable(): bool |
+-----------------+ +-----------------+ +-----------------+

+---------------------------------------------------+
|                TableImplementation                |
+---------------------------------------------------+
| +isAvailable(): bool                            |
| +assignTable(): void                            |
| +markOccupied(): void                           |
+---------------------------------------------------+
            /              |              \
           /               |               \
          /                |                \
+-----------------+ +-----------------+ +-----------------+
| SmokingTable    | | PrivateTable    | | GeneralTable    |
+-----------------+ +-----------------+ +-----------------+
| +isAvailable(): bool | +isAvailable(): bool | +isAvailable(): bool |
| +assignTable(): void | +assignTable(): void | +assignTable(): void |
| +markOccupied(): void | +markOccupied(): void | +markOccupied(): void |
+-----------------+ +-----------------+ +-----------------+

- Abstraction (SeatingPlan): The SeatingPlan class represents the higher-level part of the system that interacts with clients and customers. It defines high-level operations related to managing seating, such as assignTable(), markTableOccupied(), and isTableAvailable(). This class will maintain a reference to an Implementor object.
- Refined Abstractions (SmokingSection, PrivateSection, GeneralSection): These classes extend the SeatingPlan Abstraction and use specific Implementors for table management. For example, the SmokingSection class extends SeatingPlan and uses a SmokingTable Implementor to perform table management tasks specific to the smoking section.
- Implementor (TableImplementation): The TableImplementation interface defines the lower-level operations that are common to all table types. It includes methods like isAvailable(), assignTable(), and markOccupied(). This interface is used by the Abstraction class to delegate the actual table management tasks.
- Concrete Implementors (SmokingTable, PrivateTable, GeneralTable): These are the concrete classes that implement the TableImplementation interface. Each class represents a different type of table, such as SmokingTable, PrivateTable, or GeneralTable. Each Concrete Implementor provides specific implementations of isAvailable(), assignTable(), and markOccupied() based on the characteristics of the table type.


OBSERVER PATTERN TEMP UML:

                                                +------------------------------------------------+
                                                |                  SeatingPlanSubject            |
                                                +------------------------------------------------+
                                                | -observers: std::vector<Observer*>             |
                                                §
                                                +------------------------------------------------+
                                                | +registerObserver(observer: Observer): void    |
                                                | +removeObserver(observer: Observer): void      |
                                                | +notifyObservers(): void                       |
                                                +------------------------------------------------+

                  /                                                     |                                   \
                 /                                                      |                                    \
                /                                                       |                                     \
+--------------------------------------------+ +--------------------------------------------+ +--------------------------------------------+
|              SmokingSectionSubj            | |            PrivateSectionSubj              | |             GeneralSectionSubj             |
+--------------------------------------------+ +--------------------------------------------+ +--------------------------------------------+
| +registerObserver(observer: Observer): void| | +registerObserver(observer: Observer): void| | +registerObserver(observer: Observer): void|
| +removeObserver(observer: Observer): void  | | +removeObserver(observer: Observer): void  | | +removeObserver(observer: Observer): void  |
| +notifyObservers(): void                   | | +notifyObservers(): void                   | | +notifyObservers(): void                   |
+--------------------------------------------+ +--------------------------------------------+ +--------------------------------------------+

+------------------------------------------------+
|                   Observer                     |
+------------------------------------------------+
| +update(): void                                |
+------------------------------------------------+

                  /           |             \
                 /            |              \
                /             |               \
+------------------+ +------------------+ +------------------+
|      Waiter     | |      Manager    | |     Customer       |
+------------------+ +------------------+ +------------------+
| +update(): void  | | +update(): void  | | +update(): void  |
+------------------+ +------------------+ +------------------+

- Subject (SeatingPlanSubject): Create a SeatingPlanSubject class that represents the subject, which is responsible for maintaining a list of observers and notifying them when there are changes in the seating plan. This class would contain the state and methods for managing observers.
- Concrete Subjects (SmokingSectionSubject, PrivateSectionSubject, GeneralSectionSubject): Create concrete subject classes for each section, such as SmokingSectionSubject, PrivateSectionSubject, and GeneralSectionSubject. These classes would extend SeatingPlanSubject and implement section-specific logic.
- Observer Interface (Observer): Define an Observer interface that declares an update() method. This method will be called when a change in the seating plan occurs, and it will allow observers to react to those changes.
- Concrete Observers (Waiter, Manager, Customer): Create concrete observer classes for entities that need to be notified. For example, you can have Waiter, Manager, and Customer classes that implement the Observer interface and define how they respond to seating plan changes.
- Registration and Notification: In the subject (SeatingPlanSubject) classes, provide methods for observers to register and unregister themselves. When changes occur, such as table assignments, call the notifyObservers() method to inform all registered observers.