CXX = g++
CXXFLAGS = -std=c++17
LIBS = -lgtest -lgtest_main -pthread
SRC_DIR = .
BUILD_DIR = ./build
TEST_SOURCES := $(wildcard $(SRC_DIR)/*Tests.cpp)
TEST_EXECUTABLES := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%,$(TEST_SOURCES))

all: $(TEST_EXECUTABLES)

$(BUILD_DIR)/%: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $< $(LIBS)

run_tests: all
	@for test in $(TEST_EXECUTABLES); do \
		echo "Running $$test..."; \
		$$test; \
	done

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run_tests clean
