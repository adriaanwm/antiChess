#ifndef PAWN
#define PAWN

#include <iostream>

using namespace std;

class Pawn{
	private:
		char squareName;
		bool alive;
		int player;

	public:
		Pawn(char n, int pl);
		~Pawn();

		bool isValidMoveDirection(int r, int c, int nr, int nc);
		char getSquareName();
		bool isAlive();
		string getType();
		bool isPlayerOne();
		bool isPlayerTwo();
		bool isValidAttackDirection(int r,int c,int nr,int nc);
		int getPlayer();

};


#endif