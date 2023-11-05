CC = g++
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