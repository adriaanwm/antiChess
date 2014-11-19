#compilation
Compiler = g++
CFlags = -Wall

#paths
HeaderPath = headers/
ObjectPath = obj/
ExPath = bin/
Cpp = cpp/
TestPath = tests/unit_tests/
Objects = $(ObjectPath)main.o $(ObjectPath)chessgame.o $(ObjectPath)board.o $(ObjectPath)soldier.o 

all: antichess soldier_tests board_tests tests

tests: soldier_tests board_tests chessgame_tests

antichess: $(Objects)
	$(Compiler) $(CFlags) -o $(ExPath)antichess $(Objects)

soldier_tests: $(ObjectPath)soldier.o $(ObjectPath)soldier_tests.o
	$(Compiler) $(CFlags) -o $(ExPath)soldier_tests $(ObjectPath)soldier.o $(ObjectPath)soldier_tests.o

board_tests: $(ObjectPath)board.o $(ObjectPath)soldier.o $(ObjectPath)board_tests.o
	$(Compiler) $(CFlags) -o $(ExPath)board_tests $(ObjectPath)board.o $(ObjectPath)soldier.o $(ObjectPath)board_tests.o

chessgame_tests: $(ObjectPath)chessgame.o $(ObjectPath)board.o $(ObjectPath)soldier.o $(ObjectPath)chessgame_tests.o
	$(Compiler) $(CFlags) -o $(ExPath)chessgame_tests $(ObjectPath)chessgame.o $(ObjectPath)board.o $(ObjectPath)soldier.o $(ObjectPath)chessgame_tests.o

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

$(ObjectPath)board_tests.o: $(TestPath)board_tests.cpp $(HeaderPath)board.h $(HeaderPath)soldier.h
	$(Compiler) -c $(TestPath)board_tests.cpp -o $(ObjectPath)board_tests.o

$(ObjectPath)chessgame_tests.o: $(TestPath)chessgame_tests.cpp $(HeaderPath)board.h $(HeaderPath)soldier.h $(HeaderPath)chessgame.h
	$(Compiler) -c $(TestPath)chessgame_tests.cpp -o $(ObjectPath)chessgame_tests.o

tests: 
	./bin/soldier_tests 
	./bin/board_tests
	./bin/chessgame_tests

clean:
	rm $(ExPath)antichess $(ExPath)soldier_tests $(ExPath)board_tests $(ExPath)chessgame $(Objects) $(ObjectPath)chessgame_tests.o $(ObjectPath)board_tests.o $(ObjectPath)soldier_tests.o
