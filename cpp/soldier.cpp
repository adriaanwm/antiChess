#include "../headers/soldier.h"

Soldier::Soldier(string player){
	if(player == "w" || player == "b")
		color = player;
}

string Soldier::getColor(){
	return color;
}