#include "../headers/chessgame.h"
#include "../cpp/helpers.cpp"
#include <stdlib.h>


ChessGame::ChessGame(){
	over = false;
	startingPlayer();


}

void ChessGame::play(){

	Board board;

	while(!over){

		cout << "starting player is: " << currentPlayer << endl;

		board.display();

		string request = "which piece would you like to use?\n> ";
		int piece[2];
		N::userSelectSquare(piece,request);

		string request2 = "where would you like to move it?\n> ";
	   int newPosition[2];
	   N::userSelectSquare(newPosition,request2);

	   if(!board.move(piece[0],piece[1],newPosition[0],newPosition[1])){
	   	cout << "invalid move" << endl;
	   };

	   //userSelect(newPosition); //STUB
	   //handleRequestedMove(piece,newPosition);



	}
   return;
}

void ChessGame::startingPlayer(){
	if(rand()<0.5) currentPlayer = "W";
	else currentPlayer = "B";
	return;
}