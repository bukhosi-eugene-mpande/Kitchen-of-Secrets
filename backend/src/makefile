CC = g++
CFLAGS = -std=c++11 
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
