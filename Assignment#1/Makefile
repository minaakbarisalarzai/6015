# Defines the compiler variable (CXX) and sets it to the g++ compiler.
CXX = g++

# Defines the compiler flags variable (CXXFLAGS) with options like -Wall (enable all warnings) and -std=c++11 (use C++11 standard).
CXXFLAGS = -Wall -std=c++11

# Specifies the target compileAndLink, which depends on the msdscript target.
compileAndLink: msdscript

# Specifies the target msdscript, which depends on main.o and cmdline.o. It compiles and links these object files to create the msdscript executable.
msdscript: main.o cmdline.o
	$(CXX) $(CXXFLAGS) -o msdscript main.o cmdline.o

# Specifies the target main.o, which depends on main.cpp and cmdline.hpp. It compiles main.cpp into the object file main.o.
main.o: main.cpp cmdline.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# Specifies the target cmdline.o, which depends on cmdline.cpp and cmdline.hpp. It compiles cmdline.cpp into the object file cmdline.o.
cmdline.o: cmdline.cpp cmdline.hpp
	$(CXX) $(CXXFLAGS) -c cmdline.cpp

# Specifies the clean target, which removes the executable msdscript and any object files (*.o). This target is used to clean up after building.
clean:
	rm -f msdscript *.o


