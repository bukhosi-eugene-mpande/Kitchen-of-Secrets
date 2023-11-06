studentmain.out: main.o Receptionist.o ReservationSystem.o SeatingPlan.o Table.o PrivateSection.o GeneralSection.o PrivateTable.o GeneralTable.o 
	g++ -std=c++11 main.o Receptionist.o ReservationSystem.o SeatingPlan.o Table.o PrivateSection.o GeneralSection.o PrivateTable.o GeneralTable.o -o studentmain.out

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

Receptionist.o: Receptionist.cpp
	g++ -c -std=c++11 Receptionist.cpp

ReservationSystem.o: ReservationSystem.cpp
	g++ -c -std=c++11 ReservationSystem.cpp

SeatingPlan.o: SeatingPlan.cpp
	g++ -c -std=c++11 SeatingPlan.cpp

Table.o: Table.cpp
	g++ -c -std=c++11 Table.cpp

PrivateSection.o: PrivateSection.cpp
	g++ -c -std=c++11 PrivateSection.cpp

GeneralSection.o: GeneralSection.cpp
	g++ -c -std=c++11 GeneralSection.cpp

PrivateTable.o: PrivateTable.cpp
	g++ -c -std=c++11 PrivateTable.cpp

GeneralTable.o: GeneralTable.cpp
	g++ -c -std=c++11 GeneralTable.cpp


run:
	./studentmain.out

clean:
	rm -f *.o studentmain.out

thato:
	make && make run && make clean
