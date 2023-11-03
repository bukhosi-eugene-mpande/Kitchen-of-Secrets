# Specify the compiler
CXX = g++

# Specify the C++ standard
CXXFLAGS = -std=c++11

# Add any other flags you need
CXXFLAGS += -Wall -Wextra -pedantic

# Specify the target (output) file
TARGET = my_program

# Specify the source files
SRCS = Main.cpp Drinks.cpp DrinksMenuFactory.cpp Food.cpp FoodMenuFactory.cpp Menu.cpp  HalloweenOrderBuilder.cpp Order.cpp OrderBuilder.cpp Waiter.cpp Customer.cpp Management.cpp OrderProcess.cpp 

# Specify the object files
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<  -o $@

clean:
	$(RM) $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)
