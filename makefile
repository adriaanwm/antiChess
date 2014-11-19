#compilation
Compiler = g++
CFlags = -Wall

#paths
HeaderPath = headers/
ObjectPath = obj/
ExPath = bin/
Cpp = cpp/
TestPath = tests/unit_tests/

all: antichess soldier_tests tests

tests: soldier_tests

antichess: $(ObjectPath)main.o $(ObjectPath)chessgame.o $(ObjectPath)board.o $(ObjectPath)soldier.o 
	$(Compiler) $(CFlags) -o $(ExPath)antichess $(ObjectPath)main.o $(ObjectPath)chessgame.o $(ObjectPath)board.o $(ObjectPath)soldier.o

soldier_tests: $(ObjectPath)soldier.o $(ObjectPath)soldier_tests.o
	$(Compiler) $(CFlags) -o $(ExPath)soldier_tests $(ObjectPath)soldier.o $(ObjectPath)soldier_tests.o

$(ObjectPath)main.o: $(Cpp)main.cpp $(HeaderPath)chessgame.h $(HeaderPath)board.h $(HeaderPath)soldier.h
	$(Compiler) -c $(Cpp)main.cpp -o $(ObjectPath)main.o

$(ObjectPath)chessgame.o: $(HeaderPath)chessgame.h $(Cpp)chessgame.cpp $(HeaderPath)board.h $(HeaderPath)soldier.h
	$(Compiler) -c $(Cpp)chessgame.cpp -o $(ObjectPath)chessgame.o

$(ObjectPath)board.o: $(HeaderPath)board.h $(Cpp)board.cpp $(HeaderPath)soldier.h
	$(Compiler) -c $(Cpp)board.cpp -o $(ObjectPath)board.o

$(ObjectPath)soldier.o: $(HeaderPath)soldier.h $(Cpp)soldier.cpp
	$(Compiler) -c $(Cpp)soldier.cpp -o $(ObjectPath)soldier.o

$(ObjectPath)soldier_tests.o: $(TestPath)soldier_tests.cpp $(HeaderPath)soldier.h
	$(Compiler) -c $(TestPath)soldier_tests.cpp -o $(ObjectPath)soldier_tests.o

tests: 
	./bin/soldier_tests

clean:
	rm $(ExPath)antichess $(ExPath)soldier_tests $(ObjectPath)soldier_tests.o $(ObjectPath)main.o $(ObjectPath)chessgame.o $(ObjectPath)board.o $(ObjectPath)soldier.o 
