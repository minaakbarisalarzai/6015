# Defines the compiler variable (CXX) and sets it to the g++ compiler.
CXX = g++

# Defines the compiler flags variable (CXXFLAGS) with options like -Wall (enable all warnings) and -std=c++11 (use C++11 standard).
CXXFLAGS = -Wall -std=c++11

# Specifies the target compileAndLink, which depends on the msdscript target.
all: msdscript

# Specifies the target msdscript, which depends on main.o, cmdline.o, Expr.o, Num.o, Add.o, and Mult.o.
# It compiles and links these object files to create the msdscript executable.
msdscript: main.o cmdline.o Expr.o Test.o
	$(CXX) $(CXXFLAGS) -o msdscript main.o cmdline.o Expr.o Test.o

# Specifies the target main.o, which depends on main.cpp, cmdline.hpp, Expr.hpp, Num.hpp, Add.hpp, and Mult.hpp.
# It compiles main.cpp into the object file main.o.
main.o: main.cpp cmdline.hpp Expr.hpp 
	$(CXX) $(CXXFLAGS) -c main.cpp

# Specifies the target cmdline.o, which depends on cmdline.cpp and cmdline.hpp.
# It compiles cmdline.cpp into the object file cmdline.o.
cmdline.o: cmdline.cpp cmdline.hpp
	$(CXX) $(CXXFLAGS) -c cmdline.cpp

# Specifies the target Expr.o, which depends on Expr.cpp and Expr.hpp.
# It compiles Expr.cpp into the object file Expr.o.
Expr.o: Expr.cpp Expr.hpp
	$(CXX) $(CXXFLAGS) -c Expr.cpp

# Specifies the target Test.o, which depends on Test.cpp and Test.hpp.
# It compiles Test.cpp into the object file Test.o.
Test.o: Test.cpp Test.hpp
	$(CXX) $(CXXFLAGS) -c Test.cpp
Test: msdscript
	./msdscript --test
	
# Specifies the clean target, which removes the executable msdscript and any object files (*.o).
# This target is used to clean up after building.
clean:
	rm -f msdscript *.o


