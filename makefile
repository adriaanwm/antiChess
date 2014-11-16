#GTK Package Confg
gtkVer = 3.0
GTKpack = `pkg-config --cflags --libs gtk+-$(gtkVer)`

#ASCII ESCAPE CODES
#Bd = 

#compilation
Compiler = g++
CFlags = -Wall
PreCompArg= -c
Outarg = -o

#paths
HeaderPath = headers/
ObjectPath = obj/
ExPath = bin/
Src = cpp/
TestPath = tests/unit_tests/

all: antichess soldier_tests

antichess: $(ObjectPath)main.o $(ObjectPath)chessgame.o $(ObjectPath)board.o $(ObjectPath)soldier.o $(ObjectPath)Window.o $(ObjectPath)StatusWidget.o $(ObjectPath)ScoreWidget.o
	$(Compiler) $(CFlags) $(Outarg) $(ExPath)antichess $(ObjectPath)main.o $(ObjectPath)chessgame.o $(ObjectPath)board.o $(ObjectPath)soldier.o $(ObjectPath)Window.o $(ObjectPath)StatusWidget.o $(ObjectPath)ScoreWidget.o $(GTKpack)

soldier_tests: $(ObjectPath)soldier.o $(ObjectPath)soldier_tests.o
	$(Compiler) $(CFlags) $(Outarg) $(ExPath)soldier_tests $(ObjectPath)soldier.o $(ObjectPath)soldier_tests.o

$(ObjectPath)main.o: $(Src)main.cpp $(HeaderPath)chessgame.h $(HeaderPath)board.h $(HeaderPath)soldier.h 
	$(Compiler) $(PreCompArg) $(Src)main.cpp $(Outarg) $(ObjectPath)main.o $(GTKpack)

$(ObjectPath)chessgame.o: $(HeaderPath)chessgame.h $(Src)chessgame.cpp $(HeaderPath)board.h $(HeaderPath)soldier.h
	$(Compiler) $(PreCompArg) $(Src)chessgame.cpp $(Outarg) $(ObjectPath)chessgame.o

$(ObjectPath)board.o: $(HeaderPath)board.h $(Src)board.cpp $(HeaderPath)soldier.h
	$(Compiler) $(PreCompArg) $(Src)board.cpp $(Outarg) $(ObjectPath)board.o

$(ObjectPath)soldier.o: $(HeaderPath)soldier.h $(Src)soldier.cpp
	$(Compiler) $(PreCompArg) $(Src)soldier.cpp $(Outarg) $(ObjectPath)soldier.o

$(ObjectPath)soldier_tests.o: $(TestPath)soldier_tests.cpp $(HeaderPath)soldier.h
	$(Compiler) $(PreCompArg) $(TestPath)soldier_tests.cpp $(Outarg) $(ObjectPath)soldier_tests.o

$(ObjectPath)Window.o: $(HeaderPath)Window.h $(HeaderPath)GUIConst.h $(HeaderPath)ScoreWidget.h $(HeaderPath)StatusWidget.h $(HeaderPath)ScoreWidget.h $(Src)Window.cpp
	$(Compiler) $(PreCompArg) $(Src)Window.cpp $(Outarg) $(ObjectPath)Window.o $(GTKpack)

$(ObjectPath)StatusWidget.o: $(HeaderPath)StatusWidget.h $(Src)StatusWidget.cpp
	$(Compiler) $(PreCompArg) $(Src)StatusWidget.cpp $(Outarg) $(ObjectPath)StatusWidget.o $(GTKpack)

$(ObjectPath)ScoreWidget.o: $(HeaderPath)ScoreWidget.h $(Src)ScoreWidget.cpp
	$(Compiler) $(PreCompArg) $(Src)ScoreWidget.cpp $(Outarg) $(ObjectPath)ScoreWidget.o $(GTKpack)



clean:
	rm $(ExPath)antichess $(ExPath)soldier_tests $(ObjectPath)*.o
