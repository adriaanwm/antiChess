#include "../headers/soldier.h"

Soldier::Soldier(string player){
	if(player == "w" || player == "b")
		color = player;
	asciiName = color + "s";
}

string Soldier::getColor(){
	return color;
}

bool Soldier::isValidAttack(int r, int c, int nr, int nc){
	return true;
}

bool Soldier::isValidMove(int r, int c, int nr, int nc){
	return true;
}

string Soldier::getAsciiName(){
	return asciiName;
}

bool Soldier::isKing(){return false;}
bool Soldier::isQueen(){return false;}
bool Soldier::isPawn(){return true;}
bool Soldier::isBishop(){return false;}
bool Soldier::isRook(){return false;}
bool Soldier::isKnight(){return false;}