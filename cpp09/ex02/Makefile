# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g3 -std=c++98

# Test source files and target
TEST_SRCS = test_pairs.cpp
TEST_TARGET = test_pairs

# Source files and target
SRCS = main.cpp PmergeMe.cpp
TARGET = PmergeMe

# Object files
OBJS = $(SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

# Default rule: build the target
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build and run the tests
test: $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $^
	./$(TEST_TARGET)

# Rule to build object files from source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Rule to clean up build artifacts
clean:
	rm -f $(OBJS)
	rm -f $(TEST_OBJS)

fclean: clean
	rm -f $(TARGET)
	rm -f $(TEST_TARGET)

re: clean all

# Rule to run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run re
