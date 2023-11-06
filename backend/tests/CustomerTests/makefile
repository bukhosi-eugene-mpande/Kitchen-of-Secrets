# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -g -Wall -std=c++11

# Google Test flags
GTEST_LL = -l gtest -l gtest_main -pthread

# Directories
SRC_DIR = .
BUILD_DIR = ./build
OUT_DIR = ./out
TEST_DIR = ./tests

# Find all the cpp files in the root directory
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
TEST_FILES = $(wildcard $(TEST_DIR)/*Tests.cpp)

# Object files will have the same name as cpp files, but with .o extension
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))
TEST_OBJ_FILES = $(patsubst $(TEST_DIR)/%,$(BUILD_DIR)/%,$(TEST_FILES))

# Default target
all: run_tests

# Rule to create object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%Tests.o: $(TEST_DIR)/%Tests.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to create the build directory
$(BUILD_DIR):
	mkdir -p $@

# Rule to create the out directory
$(OUT_DIR):
	mkdir -p $@

# Rule to compile and run tests
run_tests: $(OBJ_FILES) $(TEST_OBJ_FILES) | $(OUT_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $(OUT_DIR)/run_tests $(GTEST_LL)
	$(OUT_DIR)/run_tests

# Clean up the build and out directories
clean:
	rm -rf $(BUILD_DIR) $(OUT_DIR)


