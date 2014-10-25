#include "../headers/pawn.h"
#include "../headers/board.h"
#include <iostream>
#include <sstream>
using namespace std;

const char White = 'w';
const char Black = 'b';
const char soldier = 'p';

void getPosition(string request, int *arr);

int main(){

	Board *board = new Board;

	board->printBoard();

	bool keepGoing = true;
	istringstream iss, iss1;
	string userString, temp1, temp2;

	while(keepGoing){
		string request = "Enter the row and column of the soldier you'd like to move, separated by a space\n>";
		int currentPos[2];
		getPosition(request,currentPos);


		request = "Where would you like to move it\n";
		int newPos[2];
		getPosition(request,newPos);

		board->handleMoveRequest(currentPos[0],currentPos[1],newPos[0],newPos[1]);
		board->printBoard();
	}


	return 0;
}

void getPosition(string request, int arr[]){
	cout << request;
	istringstream iss;
	string userString, temp1, temp2;
	int row, column;
	getline(cin, userString);
	iss.str(userString);
	iss >> temp1 >> temp2;
	row = atoi(temp1.c_str());
	column = atoi(temp2.c_str());
	arr[0] = row;
	arr[1] = column;
	iss.str("");
	return;
}
//get piece to be moved from user
//check if piece belongs to that player
//show where that piece can be moved
//select which place to move it
//move the piece
//
