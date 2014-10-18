#include "../headers/pawn.h"

Pawn::Pawn(char n, int pl){
	alive = true;
	squareName = n;
	player = pl;
}

Pawn::~Pawn(){}

bool Pawn::isValidMoveDirection(int r, int c, int nr, int nc){
	if (c != nc) return false;
	if (player == 1){
		if (r==1){
			if(nr == 2 || nr == 3) return true;
		} else if (nr-r == 1) return true;
		return false;
	}else if (player == 2){
		if (r==6){
			if(nr == 5 || nr == 4) return true;
		} else if (r-nr == 1) return true;
		return false;
	}
	return false;
}

char Pawn::getSquareName(){
	return squareName;
}

bool Pawn::isAlive(){
	return alive;
}

bool Pawn::isPlayerOne(){
	if (player == 1) return true;
	return false;
}
bool Pawn::isPlayerTwo(){
	if (player == 2) return true;
	return false;
}

bool Pawn::isValidAttackDirection(int r,int c,int nr,int nc){
	if (player == 1){
		if(nr-r == 1 && (nc-c == 1 || c-nc == 1))
			return true;
		return false;
	} else {
		if(r-nr == 1 && (nc-c == 1 || c-nc == 1))
			return true;
		return false;
	}
	return false;
}

int Pawn::getPlayer(){
	return player;
}

