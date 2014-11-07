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

string Soldier::getAsciiName(){
	return asciiName;
}