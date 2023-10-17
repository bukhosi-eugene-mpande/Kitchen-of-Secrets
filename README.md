# COS214-Project
This repository will hold the final project for cos-214

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
