#include "../headers/chessgame.h"
#include "../cpp/helpers.cpp"
#include <stdlib.h>
#include <time.h>


ChessGame::ChessGame(){
	over = false;
	startingPlayer();

}

void ChessGame::asciiPlay(){

	Board *board = new Board;

	while(!over){
		cout << "current player is: " << currentPlayer << endl;
		board->display();

		string request = "which piece would you like to use? (r c)\n> ";
		int piece[2];
		N::userSelectSquare(piece,request);

		string request2 = "where would you like to move it? (r c)\n> ";
	   int newPosition[2];
	   N::userSelectSquare(newPosition,request2);

	   if(!board->move(piece[0],piece[1],newPosition[0],newPosition[1],currentPlayer)){
	   	cout << "invalid move" << endl;
	   }else{
	   	changePlayer();
	   }

	   // if(board->stalemate()){
	   // 	cout << "No more attacks can. The winner is " << currentPlayer << endl;
	   // 	over = true;
	   // }


	   if(board->gameOver()){
	   	cout << "The winner is " << board->winner() << endl;
	   	over = true;
	   }

	}
   return;
}

void ChessGame::guiPlay(){
	return;
}

void ChessGame::startingPlayer(){
	time_t t;
	srand((unsigned) time(&t));
	if(rand()%2+1==1){
		currentPlayer = "w";
	}
	else currentPlayer = "b";
	return;
}

void ChessGame::changePlayer(){
	if(currentPlayer == "w")
		currentPlayer = "b";
	else currentPlayer = "w";
}

