#ifndef SOLDIER
#define SOLDIER

#include <iostream>

using namespace std;

class Soldier{
	private:
		string asciiName;

	protected:
		string color;

	public:
		Soldier(string player, string name);
		~Soldier();

		string getSquareName();
		virtual bool isValidAttack(int r, int c, int nr, int nc);
		virtual bool isValidMove(int r, int c, int nr, int nc);
		string getColor();

		//what kind of soldier?
		virtual bool isKing();
		virtual bool isQueen();
		virtual bool isPawn();
		virtual bool isBishop();
		virtual bool isRook();
		virtual bool isKnight();

		//ascii
		string getAsciiName();


};
#endif

#ifndef PAWN
#define PAWN
class Pawn: public Soldier{
	public:
		Pawn(string player);
		~Pawn();
		bool isKing();
		bool isQueen();
		bool isPawn();
		bool isBishop();
		bool isRook();
		bool isKnight();

		bool isValidAttack(int r, int c, int nr, int nc);
		bool isValidMove(int r, int c, int nr, int nc);

};
#endif









