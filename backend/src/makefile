CC = g++
<<<<<<< HEAD
CFLAGS = -Wall -Wextra -pedantic -std=c++11 -lpthread

SRCS = server.cpp accounting/Accounting.cpp accounting/Billing/*.cpp accounting/Tab/*.cpp accounting/Inventory/*.cpp

OBJS = server.o accounting/Accounting.o
OBJS += $(patsubst %.cpp, %.o, $(wildcard accounting/Billing/*.cpp))
OBJS += $(patsubst %.cpp, %.o, $(wildcard accounting/Tab/*.cpp))
OBJS += $(patsubst %.cpp, %.o, $(wildcard accounting/Inventory/*.cpp))

EXEC = server

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
=======
CFLAGS = -std=c++11 -g
LDFLAGS =
SOURCES = main.cpp 
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = my_program

.PHONY: all run run_gdb clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

run: $(EXECUTABLE)
	./$(EXECUTABLE)

run_gdb: $(EXECUTABLE)
	gdb ./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
>>>>>>> kitchen-Intergration
