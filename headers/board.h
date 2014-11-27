#ifndef BOARD
#define BOARD

#include <iostream>
#include <complex>
#include "../headers/board.h"
#include "../headers/soldier.h"
//#include "../headers/pawn.h"

using namespace std;

class Board{
   private:
	Soldier *soldier[8][8];
      Soldier *whiteDeadSoldier[16];
      Soldier *blackDeadSoldier[16];

      //ascii
      string square[8][8];

      //add soldier to dead list
      bool removeSoldierFromBoard(int r, int c, string color);

   public:
      Board();
      bool move(int r, int c, int nr, int nc, string cp);

      //get whose turn it isn't
      string opponent(string cp);
      //check if player is trying to move their own piece
      bool belongsToPlayer(string color, int r, int c);
      //check if the move is an attack (only checks of square is occupied)
      bool isAttack(int r, int c, string cp);
      //Perform attack
      bool performAttack(int r, int c, int nr, int nc);
      //check if player has any pieces that can attack
      bool hasAvailableAttack(string player);
      //perform move
      bool performMove(int r, int c, int nr, int nc);

      bool makeQueenIfNecessary(int r, int c, string player);

      bool gameOver();
      //bool stalemate();

      string winner();

      //checkForAvailableAttacks
      bool hasAttackIsKing(int,int,string);
      bool hasAttackIsKnight(int,int,string);
      bool hasAttackIsPawn(int,int,string);
      bool hasAttackStraight(int,int,string);
      bool hasAttackDiagonal(int,int,string);

      //check if there are any pieces in the way of a move (up to but not including)
      bool emptyStraightLane(int r, int c, int nr, int nc);
      bool emptyDiagonalLane(int r, int c, int nr, int nc);
      
      bool isStraight(int r, int c, int nr, int nc);
      bool isDiagonal(int r, int c, int nr, int nc);

      //ascii
      void asciiSetup();
      void display();

      //GUI
      void status(string arr[][8]);

};

#endif
