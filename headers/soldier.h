#ifndef SOLDIER
#define SOLDIER

#include <iostream>

using namespace std;

class Soldier{
	private:
		char color;


	public:
		Soldier(char player);
		~Soldier();

		bool isValidMoveDirection(int r, int c, int nr, int nc);
		char getSquareName();
		bool isValidAttackDirection(int r,int c,int nr,int nc);
		int getColor();

};


#endif