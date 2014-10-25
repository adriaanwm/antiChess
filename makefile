#compilation
Compiler = g++
CFlags = -Wall

#paths
HeaderPath = headers/
ObjectPath = obj/
ExPath = bin/
Cpp = cpp/


antichess: $(ObjectPath)main.o $(ObjectPath)chessgame.o $(ObjectPath)board.o $(ObjectPath)soldier.o
	$(Compiler) $(CFlags) -o $(ExPath)antichess $(ObjectPath)main.o $(ObjectPath)chessgame.o $(ObjectPath)board.o $(ObjectPath)soldier.o

$(ObjectPath)main.o: $(Cpp)main.cpp $(HeaderPath)chessgame.h $(HeaderPath)board.h $(HeaderPath)soldier.h
	$(Compiler) -c $(Cpp)main.cpp -o $(ObjectPath)main.o

$(ObjectPath)chessgame.o: $(HeaderPath)chessgame.h $(Cpp)chessgame.cpp $(HeaderPath)board.h $(HeaderPath)soldier.h
	$(Compiler) -c $(Cpp)chessgame.cpp -o $(ObjectPath)chessgame.o

$(ObjectPath)board.o: $(HeaderPath)board.h $(Cpp)board.cpp $(HeaderPath)soldier.h
	$(Compiler) -c $(Cpp)board.cpp -o $(ObjectPath)board.o

$(ObjectPath)soldier.o: $(HeaderPath)soldier.h $(Cpp)soldier.cpp
	$(Compiler) -c $(Cpp)soldier.cpp -o $(ObjectPath)soldier.o


clean:
	rm $(ExPath)antichess $(ObjectPath)main.o $(ObjectPath)chessgame.o $(ObjectPath)board.o $(ObjectPath)soldier.o
