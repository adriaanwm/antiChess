all: main.o scores.o 
	g++ main.o scores.o -o out `pkg-config --cflags --libs gtk+-3.0`


main.o: main.cpp FileNameConst.h GUIConst.h scores.h
	g++ -c main.cpp `pkg-config --cflags --libs gtk+-3.0`

scores.o: scores.h scores.cpp
	g++ -c scores.cpp `pkg-config --cflags --libs gtk+-3.0`