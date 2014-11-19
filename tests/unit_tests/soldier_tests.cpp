#include "../../headers/soldier.h"
#include <iostream>

int main(){
	cout << "SOLDIER TESTS **********" << endl;

	int passingTests = 0;
	int failingTests = 0;

	Soldier *soldier[7];
	soldier[0] = new Pawn("w");
	soldier[1] = new Rook("w");
	soldier[2] = new Knight("w");
	soldier[3] = new Bishop("w");
	soldier[4] = new Queen("w");
	soldier[5] = new King("w");
	soldier[6] = new Pawn("b"); //test one black pawn since pawns move differently depending on the color

//COLOR AND NAME TESTS
	cout << "running color and name tests" << endl;
	//color
	for(int i=0;i<6;i++){
		if(soldier[i]->getColor() == "w") passingTests ++;
		else {
			cout << "wrong color for soldier " << i << endl;
			failingTests++;
		}
	}
	if(soldier[6]->getColor() == "b") passingTests ++;
	else {
			cout << "wrong color for soldier " << 6 << endl;
			failingTests++;
	}
	//name
	string asciiName[7] = {"wp","wr","wn","wb","wq","wk","bp"};
	for(int i=0;i<7;i++){
		if(soldier[i]->getAsciiName() == asciiName[i]) passingTests ++;
		else {
			cout << "wrong asciiname for soldier " << i << endl;
			failingTests++;
		}
	}

	
	//ATTACK TESTS
	cout << "running attack tests" << endl;
	int testAttacks[14][4][4] =
			{{{1,1,1,2},{1,1,2,1},{1,1,3,1},{1,0,2,-1}} // whitepawnfail
			,{{1,1,2,2},{1,1,2,0},{6,2,7,1},{4,2,5,1}} //whitepawnpass
			,{{1,1,1,1},{7,3,8,4},{3,2,3,-1},{4,2,9,2}} //rookfail
			,{{1,1,2,1},{4,3,4,7},{0,3,7,3},{1,2,0,2}} //rookpass
			,{{0,0,-1,-2},{0,0,2,-1},{7,7,8,9},{3,3,5,5}} //knightfail
			,{{0,0,2,1},{0,0,1,2},{3,3,4,5},{4,4,2,3}} //knightpass
			,{{3,4,2,2},{0,0,-2,-2},{4,5,0,6},{2,5,3,3}} //bishopfail
			,{{3,6,1,4},{2,4,3,3},{0,0,6,6},{3,3,1,1}} //bishoppass
			,{{3,4,2,2},{0,0,-2,-2},{3,2,3,-1},{4,2,9,2}} //queenfail
			,{{1,1,2,1},{4,3,4,7},{3,6,1,4},{2,4,3,3}} //queenpass
			,{{2,2,4,2},{2,2,2,2},{0,0,-1,0},{7,7,6,5}} //kingfail
			,{{5,5,6,5},{1,1,0,0},{2,4,3,4},{5,6,5,5}} //kingpass
			,{{5,3,4,3},{0,4,-1,3},{1,2,2,3},{4,4,4,4}} //blackpawnfail
			,{{6,3,5,2},{1,0,0,1},{4,4,3,5},{5,1,4,0}}}; //blackpawnpass


	for(int i=0;i<14;i = i+2){
		for(int j=0;j<4;j++){
			if(soldier[i/2]->isValidAttack(testAttacks[i][j][0],testAttacks[i][j][1],testAttacks[i][j][2],testAttacks[i][j][3])){
				failingTests ++;
				cout << "soldier " << i/2 << " accepted the move " << testAttacks[i][j][0]<<testAttacks[i][j][1]<<testAttacks[i][j][2]<<testAttacks[i][j][3] << endl;
			}
			else passingTests ++;
			if(!soldier[i/2]->isValidAttack(testAttacks[i+1][j][0],testAttacks[i+1][j][1],testAttacks[i+1][j][2],testAttacks[i+1][j][3])){
				failingTests ++;
				cout << "soldier " << i/2 << " rejected the move " << testAttacks[i+1][j][0]<<testAttacks[i+1][j][1]<<testAttacks[i+1][j][2]<<testAttacks[i+1][j][3] << endl;
			}
			else passingTests ++;
		}
	}

	//KIND OF SOLDIER TESTS
	cout << "running Kind of Soldier Tests" << endl;
	for(int i=0;i<7;i++){
		if(i!=0 && i!=6){
			if(soldier[i]->isPawn()){
				cout << "soldier" << i << " thinks it's a pawn" << endl;
				failingTests ++;}
			else passingTests++;
		}
		if(i!=1){
			if(soldier[i]->isRook()){
				cout << "soldier" << i << " thinks it's a rook" << endl;
				failingTests ++;}
			else passingTests++;
		}
		if(i!=2){
			if(soldier[i]->isKnight()){
				cout << "soldier" << i << " thinks it's a knight" << endl;
				failingTests ++;}
			else passingTests++;
		}
		if(i!=3){
			if(soldier[i]->isBishop()){
				cout << "soldier" << i << " thinks it's a bishop" << endl;
				failingTests ++;}
			else passingTests++;
		}
		if(i!=4){
			if(soldier[i]->isQueen()){
				cout << "soldier" << i << " thinks it's a queen" << endl;
				failingTests ++;}
			else passingTests++;
		}
		if(i!=5){
			if(soldier[i]->isKing()){
				cout << "soldier" << i << " thinks it's a king" << endl;
				failingTests ++;}
			else passingTests++;
		}
	}

	//results
	cout << passingTests << " passing tests" << endl;
	cout << failingTests << " failing tests" << endl;

	return 0;
}