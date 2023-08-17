# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g3 -std=c++98

# Test source files and target
TEST_SRCS = test_pairs.cpp
TEST_TARGET = test_pairs

STACK_SRCS = test_stack.cpp
STACK_TARGET = test_stack

FJ_SRCS = test_fj.cpp
FJ_TARGET = test_fj

# Source files and target
SRCS = main.cpp PmergeMe.cpp
TARGET = PmergeMe

# Object files
OBJS = $(SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)
STACK_OBJS = $(STACK_SRCS:.cpp=.o)
FJ_OBJS = $(FJ_SRCS:.cpp=.o)

# Default rule: build the target
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build and run the tests
test: $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $^
	./$(TEST_TARGET)

stack: $(STACK_OBJS)
	$(CXX) $(CXXFLAGS) -o $(STACK_TARGET) $^
	./$(STACK_TARGET)

fj: $(FJ_OBJS)
	$(CXX) $(CXXFLAGS) -o $(FJ_TARGET) $^
	./$(FJ_TARGET)

# Rule to build object files from source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Rule to clean up build artifacts
clean:
	rm -f $(OBJS)
	rm -f $(TEST_OBJS)
	rm -f $(STACK_OBJS)
	rm -f $(FJ_OBJS)

fclean: clean
	rm -f $(TARGET)
	rm -f $(TEST_TARGET)
	rm -f $(STACK_TARGET)
	rm -f $(FJ_TARGET)

re: clean all

# Rule to run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run re
