#include "../../headers/board.h"
#include "../../headers/soldier.h"
#include <iostream>
using namespace std;

int main(){
	cout << "*****BOARD TESTS*****" << endl;

	int passingTests = 0;
	int failingTests = 0;
	Board board;

	//emptyStraightLane
	if(!board.emptyStraightLane(3,3,6,3)){
		cout << "returns false for empty lane at 3 3 5 3" << endl;
		failingTests ++;
	}else passingTests ++;
	if(board.emptyStraightLane(3,3,7,3)){
		cout << "returns true for empty lane at 3 3 7 3" << endl;
		failingTests ++;
	}else passingTests ++;

	//emptyDiagonalLane
	if(!board.emptyDiagonalLane(3,3,6,6)){
		cout << "returns false for empty lane at 3 3 6 6" << endl;
		failingTests ++;
	}else passingTests ++;
	if(board.emptyDiagonalLane(0,0,2,2)){
		cout << "returns true for empty lane at 0 0 2 2" << endl;
		failingTests ++;
	}else passingTests ++;


	//results
	cout << passingTests << " passing tests" << endl;
	cout << failingTests << " failing tests" << endl;


	return 0;
}