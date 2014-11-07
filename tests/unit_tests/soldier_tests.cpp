#include "../../headers/soldier.h"
#include <iostream>

int main(){
	//Soldier(string player)
	Soldier *testSoldier = new Soldier("w");
	cout << "created soldier" << endl;

	testSoldier->getColor();


	return 0;
}