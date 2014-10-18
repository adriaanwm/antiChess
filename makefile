#compilation
Compiler = g++
CFlags = -Wall

#paths
HeaderPath = headers/
ObjectPath = objects/
ExPath = bin/
Cpp = cpp/

main: $(ObjectPath)main.o $(ObjectPath)board.o $(ObjectPath)pawn.o
	$(Compiler) $(CFlags) -o $(ExPath)main $(ObjectPath)main.o $(ObjectPath)board.o $(ObjectPath)pawn.o

$(ObjectPath)main.o: $(Cpp)main.cpp $(HeaderPath)board.h $(HeaderPath)pawn.h
	g++ -c $(Cpp)main.cpp -o $(ObjectPath)main.o

# $(ObjectPath)soldier.o: $(HeaderPath)soldier.h $(Cpp)soldier.cpp
# 	g++ -c $(Cpp)soldier.cpp -o $(ObjectPath)soldier.o

$(ObjectPath)board.o: $(HeaderPath)board.h $(Cpp)board.cpp $(HeaderPath)pawn.h 
	g++ -c $(Cpp)board.cpp -o $(ObjectPath)board.o

$(ObjectPath)pawn.o: $(HeaderPath)pawn.h $(Cpp)pawn.cpp
	g++ -c $(Cpp)pawn.cpp -o $(ObjectPath)pawn.o

clean:
	rm $(ExPath)main $(ObjectPath)main.o $(ObjectPath)board.o $(ObjectPath)pawn.o