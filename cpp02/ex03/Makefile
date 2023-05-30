# Compiler and flags
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

# Source files and target
SRCS = Fixed.cpp main.cpp Point.cpp
TARGET = fixed

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule: build the target
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build object files from source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Rule to clean up build artifacts
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: clean all

# Rule to run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run re

