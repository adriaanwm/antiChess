#ifndef SOLDIER
#define SOLDIER

#include <iostream>

using namespace std;

class Soldier{
	private:
		string color;
		string asciiName;


	public:
		Soldier(string player);
		~Soldier();

		string getSquareName();
		bool isValidAttack(int r, int c, int nr, int nc);
		bool isValidMove(int r, int c, int nr, int nc);
		string getColor();

		//what kind of soldier?
		bool isKing();
		bool isQueen();
		bool isPawn();
		bool isBishop();
		bool isRook();
		bool isKnight();

		//ascii
		string getAsciiName();


};


#endif