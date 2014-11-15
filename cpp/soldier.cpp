#include "../headers/soldier.h"

Soldier::Soldier(string player, string name){
	color = player;
	asciiName = color + name;
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
bool Soldier::isPawn(){return false;}
bool Soldier::isBishop(){return true;}
bool Soldier::isRook(){return false;}
bool Soldier::isKnight(){return false;}


//PAWN
Pawn::Pawn(string player): Soldier(player, "p"){}

bool Pawn::isKing(){return false;}
bool Pawn::isQueen(){return false;}
bool Pawn::isPawn(){return true;}
bool Pawn::isBishop(){return false;}
bool Pawn::isRook(){return false;}
bool Pawn::isKnight(){return false;}

bool Pawn::isValidAttack(int r, int c, int nr, int nc){
	if(color == "w"){
		if((nr<8 && nr == r+1) && ((nc<8 && nc == c+1) | (nc>=0 && nc == c-1))) return true;
	}else{
		if((nr>=0 && nr == r-1) && ((nc<8 && nc == c+1) | (nc>=0 && nc == c-1))) return true;
	}
	return false;
}

bool Pawn::isValidMove(int r, int c, int nr, int nc){
	if(color == "w"){
		if(nr < 8 && nr == r+1) return true;
		if(r == 1 && nr == r+2) return true;
		return false;
	}else{
		if(nr >= 0 && nr == r-1) return true;
		if(r ==6 && nr == r-2) return true;
		return false;
	}
	return false;
}







