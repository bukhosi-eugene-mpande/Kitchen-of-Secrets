CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++11

SRCS = main.cpp Accounting.cpp Billing/*.cpp Tab/*.cpp Inventory/*.cpp

OBJS = main.o Accounting.o
OBJS += $(patsubst %.cpp, %.o, $(wildcard Billing/*.cpp))
OBJS += $(patsubst %.cpp, %.o, $(wildcard Tab/*.cpp))
OBJS += $(patsubst %.cpp, %.o, $(wildcard Inventory/*.cpp))

EXEC = main

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)