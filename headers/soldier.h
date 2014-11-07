#ifndef SOLDIER
#define SOLDIER

#include <iostream>

using namespace std;

class Soldier{
	private:
		string color;


	public:
		Soldier(string player);
		~Soldier();

		bool isValidMoveDirection(int r, int c, int nr, int nc);
		string getSquareName();
		bool isValidAttackDirection(int r,int c,int nr,int nc);
		string getColor();

};


#endif