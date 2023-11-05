# Directories
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

# Target
TARGET := $(BIN_DIR)/program.out

# Source files (recursively find all .cpp and .h files)
SRCS := $(shell find $(SRC_DIR) -type f \( -name "*.cpp" -o -name "*.h" \))
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(filter %.cpp,$(SRCS)))

# Create a list of directories in the obj directory that mirror the src directory structure
OBJ_DIRS := $(sort $(dir $(OBJS)))

# Compiler settings
CXX := g++
CXXFLAGS := -std=c++17

# Rules
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Make sure the obj directories are created before compiling
$(OBJS): | $(OBJ_DIRS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	$(TARGET)

clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)

.PHONY: run clean

$(BIN_DIR):
	mkdir -p $@

# Create the obj directories with the same structure as src directory
$(OBJ_DIRS):
	mkdir -p $@


