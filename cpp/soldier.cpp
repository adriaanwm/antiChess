#include "../headers/soldier.h"

Soldier::Soldier(string player){
	color = player;
}

string Soldier::getColor(){
	return color;
}