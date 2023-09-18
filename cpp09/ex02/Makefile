# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g3 -std=c++98 -MMD
#Run debug with make DEBUG=1
ifdef DEBUG
CXXFLAGS += -DDEBUG
endif

# Test source files and target
# TEST_SRCS = test_pairs.cpp
# TEST_TARGET = test_pairs

# TEST_IT_SRCS = test_it.cpp
# IT_TARGET = test_it

# STACK_SRCS = test_stack.cpp
# STACK_TARGET = test_stack

# FJ_SRCS = test_fj.cpp Leaf.cpp AbstractPairs.cpp
# FJ_TARGET = test_fj

# LEAF_SRCS = test_leaf.cpp Leaf.cpp
# LEAF_TARGET = test_leaf

# ABSTRACT_PAIR_SRCS = test_abstract_pair.cpp AbstractPairs.cpp Leaf.cpp
# ABSTRACT_PAIR_TARGET = test_abstract_pairs

# Source files and target
SRCS = main.cpp
TARGET = PmergeMe

# Object files
OBJS = $(SRCS:.cpp=.o)
# TEST_OBJS = $(TEST_SRCS:.cpp=.o)
# STACK_OBJS = $(STACK_SRCS:.cpp=.o)
# FJ_OBJS = $(FJ_SRCS:.cpp=.o)
# LEAF_OBJS = $(LEAF_SRCS:.cpp=.o)
# ABSTRACT_PAIR_OBJS = $(ABSTRACT_PAIR_SRCS:.cpp=.o)
# TEST_IT_OBJS = $(TEST_IT_SRCS:.cpp=.o)

# Default rule: build the target
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build and run the tests
# test: $(TEST_OBJS)
# 	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $^
# 	./$(TEST_TARGET)

# test_it: $(TEST_IT_OBJS)
# 	$(CXX) $(CXXFLAGS) -o $(IT_TARGET) $^

# stack: $(STACK_OBJS)
# 	$(CXX) $(CXXFLAGS) -o $(STACK_TARGET) $^
# 	./$(STACK_TARGET)

# fj: $(FJ_OBJS)
# 	$(CXX) $(CXXFLAGS) -o $(FJ_TARGET) $^
# 	./$(FJ_TARGET)

# leaf: $(LEAF_OBJS)
# 	$(CXX) $(CXXFLAGS) -o $(LEAF_TARGET) $^
# 	./$(LEAF_TARGET)

# pair: $(ABSTRACT_PAIR_OBJS)
# 	$(CXX) $(CXXFLAGS) -o $(ABSTRACT_PAIR_TARGET) $^
# 	./$(ABSTRACT_PAIR_TARGET)


# Rule to build object files from source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Rule to clean up build artifacts
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

# Rule to run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run re
