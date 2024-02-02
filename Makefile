CXX = g++
CXXFLAGS = -Wall -std=c++11

.PHONY: test
test: msdscript
	./msdscript --test

all: msdscript

msdscript: Assignment2/msdscript/main.o Assignment2/msdscript/cmdline.o Assignment2/msdscript/Expr.o Assignment2/msdscript/Test.o
	$(CXX) $(CXXFLAGS) -o msdscript Assignment2/msdscript/main.o Assignment2/msdscript/cmdline.o Assignment2/msdscript/Expr.o Assignment2/msdscript/Test.o

Assignment2/msdscript/main.o: Assignment2/msdscript/main.cpp Assignment2/msdscript/cmdline.hpp Assignment2/msdscript/Expr.hpp
	$(CXX) $(CXXFLAGS) -c Assignment2/msdscript/main.cpp

Assignment2/msdscript/cmdline.o: Assignment2/msdscript/cmdline.cpp Assignment2/msdscript/cmdline.hpp
	$(CXX) $(CXXFLAGS) -c Assignment2/msdscript/cmdline.cpp

Assignment2/msdscript/Expr.o: Assignment2/msdscript/Expr.cpp Assignment2/msdscript/Expr.hpp
	$(CXX) $(CXXFLAGS) -c Assignment2/msdscript/Expr.cpp

Assignment2/msdscript/Test.o: Assignment2/msdscript/Test.cpp Assignment2/msdscript/Test.hpp
	$(CXX) $(CXXFLAGS) -c Assignment2/msdscript/Test.cpp

clean:
	rm -f msdscript Assignment2/msdscript/*.o
