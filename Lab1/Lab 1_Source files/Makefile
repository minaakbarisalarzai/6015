# Compiler
CXX := c++

# Compiler flags
CFLAGS := -std=c++11 -Wall -Wextra

# Macros for source and header files
CXXSOURCE := $(wildcard *.cpp)
HEADERS := $(wildcard *.h)

# Macros for compiling and linking options
CXXFLAGS := -c
LDFLAGS := -o



# Target: printM
# Purpose: Print the values of macros for testing
printM:
	@echo "CXX: $(CXX)"
	@echo "CFLAGS: $(CFLAGS)"
	@echo "CXXSOURCE: $(CXXSOURCE)"
	@echo "HEADERS: $(HEADERS)"
	@echo "CXXFLAGS: $(CXXFLAGS)"
	@echo "LDFLAGS: $(LDFLAGS)"


# Rule to create object files from source files
%.o: %.cpp %.h
	$(CXX) $(CFLAGS) $(CXXFLAGS) $< -o $@




# Target: my_program (executable)
# Purpose: Link object files to create the executable program.
my_program: $(CXXSOURCE:.cpp=.o)
	$(CXX) $(CFLAGS) $^ $(LDFLAGS) $@




# Target: clean
# Purpose: Remove all generated files and the executable.
clean:
	rm -rf my_program *.o
	echo "The clean target has been run." > clean


.PHONY: clean


