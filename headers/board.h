#ifndef BOARD
#define BOARD
#include <iostream>
#include "pawn.h"
using namespace std;

class Board{
private:
	char squares[8][8];
	char WhiteSquare;
	char BlackSquare;
	Pawn *soldiers[8][8];
	Pawn *playerOne[16];
	int numPlayerOneDead;
	int numPlayerTwoDead;
	Pawn *playerTwo[16];
	void setupBoard();
public:
	Board();
	void printBoard();
	Pawn *getSoldier(int r, int c);
	void updateSquares();
	void updateSoldiers(int r, int c, int nr, int nc);
	bool move(int r, int c, int nr, int nc);
	bool occupied(int r, int c);
	bool attack(int r, int c, int nr, int nc);
	bool soldierCleanup(int r, int c);
	bool handleMoveRequest(int r, int c, int nr, int nc);

	//check movement direction
	bool isDiagonal(int r, int c, int nr, int nc);
	bool isVertical(int r, int c, int nr, int nc);
	bool isHorizontal(int r, int c, int nr, int nc);
	bool isL(int r, int c, int nr, int nc);

	//check if move is blocked by soldiers
	bool emptyDiagonal(int r, int c, int nr, int nc);
	bool emptyVertical(int r, int c, int nr);
	bool emptyHorizontal(int r, int c, int nc);

	//check if attack is valid
	bool canAttack(int r, int c, int nr, int nc);
	bool canMove(int r, int c, int nr, int nc);
	bool isAttack(int nr, int nc);

	//check for attack
	bool scanAttack(int r, int c);
	bool scanTopRightDiagonal(int r, int c, int a[]);
	bool scanTopLeftDiagonal(int r, int c, int a[]);
	bool scanBottomLeftDiagonal(int r, int c, int a[]);
	bool scanBottomRightDiagonal(int r, int c, int a[]);

	//check if it's opponent
	bool isOpponent(int r, int c, int nr, int nc);
};

#endif
