#ifndef SOLDIER
#define SOLDIER

#include <iostream>
#include <complex>

using namespace std;

class Soldier{
	private:
		string asciiName;

	protected:
		string color;

	public:
		Soldier(string player, string name);
		~Soldier();

		//string getSquareName();
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

class Rook: public Soldier{
	public:
		Rook(string player);
		~Rook();
		bool isKing();
		bool isQueen();
		bool isPawn();
		bool isBishop();
		bool isRook();
		bool isKnight();

		bool isValidAttack(int r, int c, int nr, int nc);
		bool isValidMove(int r, int c, int nr, int nc);
};

class Knight: public Soldier{
	public:
		Knight(string player);
		~Knight();
		bool isKing();
		bool isQueen();
		bool isPawn();
		bool isBishop();
		bool isRook();
		bool isKnight();

		bool isValidAttack(int r, int c, int nr, int nc);
		bool isValidMove(int r, int c, int nr, int nc);
};

class Bishop: public Soldier{
	public:
		Bishop(string player);
		~Bishop();
		bool isKing();
		bool isQueen();
		bool isPawn();
		bool isBishop();
		bool isRook();
		bool isKnight();

		bool isValidAttack(int r, int c, int nr, int nc);
		bool isValidMove(int r, int c, int nr, int nc);
};


class Queen: public Soldier{
	public:
		Queen(string player);
		~Queen();
		bool isKing();
		bool isQueen();
		bool isPawn();
		bool isBishop();
		bool isRook();
		bool isKnight();

		bool isValidAttack(int r, int c, int nr, int nc);
		bool isValidMove(int r, int c, int nr, int nc);
};

class King: public Soldier{
	public:
		King(string player);
		~King();
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








