# compiler and flags
cxx = c++
cxxflags = -wall -wextra -werror

# source files and target
srcs = main.cpp
target = test

# object files
objs = $(srcs:.cpp=.o)

# default rule: build the target
all: $(target)

# rule to build the target
$(target): $(objs)
	$(cxx) $(cxxflags) -o $@ $^

# rule to build object files from source files
%.o: %.cpp
	$(cxx) $(cxxflags) -c -o $@ $<

# rule to clean up build artifacts
clean:
	rm -f $(objs)

fclean: clean
	rm -f $(target)

re: clean all

# rule to run the program
run: $(target)
	./$(target)

.phony: all clean run re

