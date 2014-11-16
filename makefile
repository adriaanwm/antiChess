#GTK Package Confg
#use version 2.0 at viu.
gtkVer = 3.0
GTKpack = `pkg-config --cflags --libs gtk+-$(gtkVer)`

#ASCII ESCAPE CODES
#bold
bld = \033[1m
#reset
cls = \033[0m

#Command Hide
hidden = @

#Print Command
print = $(hidden)echo

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
	$(print) "$(bld) Make All$(cls)"

antichess: $(ObjectPath)main.o $(ObjectPath)chessgame.o $(ObjectPath)board.o $(ObjectPath)soldier.o $(ObjectPath)Window.o $(ObjectPath)StatusWidget.o $(ObjectPath)ScoreWidget.o
	$(print) "$(bld) Make AntiChess$(cls)"
	$(Compiler) $(CFlags) $(Outarg) $(ExPath)antichess $(ObjectPath)main.o $(ObjectPath)chessgame.o $(ObjectPath)board.o $(ObjectPath)soldier.o $(ObjectPath)Window.o $(ObjectPath)StatusWidget.o $(ObjectPath)ScoreWidget.o $(GTKpack)

soldier_tests: $(ObjectPath)soldier.o $(ObjectPath)soldier_tests.o
	$(print) "$(bld) Make soldier tests$(cls)"	
	$(Compiler) $(CFlags) $(Outarg) $(ExPath)soldier_tests $(ObjectPath)soldier.o $(ObjectPath)soldier_tests.o

$(ObjectPath)main.o: $(Src)main.cpp $(HeaderPath)chessgame.h $(HeaderPath)board.h $(HeaderPath)soldier.h 
	$(print) "$(bld) Compiling main.o$(cls)"
	$(Compiler) $(PreCompArg) $(Src)main.cpp $(Outarg) $(ObjectPath)main.o $(GTKpack)

$(ObjectPath)chessgame.o: $(HeaderPath)chessgame.h $(Src)chessgame.cpp $(HeaderPath)board.h $(HeaderPath)soldier.h
	$(print) "$(bld) Compiling chessgame.o$(cls)"
	$(Compiler) $(PreCompArg) $(Src)chessgame.cpp $(Outarg) $(ObjectPath)chessgame.o

$(ObjectPath)board.o: $(HeaderPath)board.h $(Src)board.cpp $(HeaderPath)soldier.h
	$(Compiler) $(PreCompArg) $(Src)board.cpp $(Outarg) $(ObjectPath)board.o

$(ObjectPath)soldier.o: $(HeaderPath)soldier.h $(Src)soldier.cpp
	$(print) "$(bld) Compiling soldier.o$(cls)"
	$(Compiler) $(PreCompArg) $(Src)soldier.cpp $(Outarg) $(ObjectPath)soldier.o

$(ObjectPath)soldier_tests.o: $(TestPath)soldier_tests.cpp $(HeaderPath)soldier.h
	$(print) "$(bld) Compiling soldier_tests.o$(cls)"
	$(Compiler) $(PreCompArg) $(TestPath)soldier_tests.cpp $(Outarg) $(ObjectPath)soldier_tests.o

$(ObjectPath)Window.o: $(HeaderPath)Window.h $(HeaderPath)GUIConst.h $(HeaderPath)ScoreWidget.h $(HeaderPath)StatusWidget.h $(HeaderPath)ScoreWidget.h $(Src)Window.cpp
	$(print) "$(bld) Compiling Window.o$(cls)"
	$(Compiler) $(PreCompArg) $(Src)Window.cpp $(Outarg) $(ObjectPath)Window.o $(GTKpack)

$(ObjectPath)StatusWidget.o: $(HeaderPath)StatusWidget.h $(Src)StatusWidget.cpp
	$(print) "$(bld) Compiling StatusWidget.o$(cls)"
	$(Compiler) $(PreCompArg) $(Src)StatusWidget.cpp $(Outarg) $(ObjectPath)StatusWidget.o $(GTKpack)

$(ObjectPath)ScoreWidget.o: $(HeaderPath)ScoreWidget.h $(Src)ScoreWidget.cpp
	$(print) "$(bld) Compiling ScoreWidget.o$(cls)"
	$(Compiler) $(PreCompArg) $(Src)ScoreWidget.cpp $(Outarg) $(ObjectPath)ScoreWidget.o $(GTKpack)



clean:
	$(print) "$(bld) Clean: Removing Object Files and Binary Files$(cls)"
	rm $(ExPath)antichess $(ExPath)soldier_tests $(ObjectPath)*.o
