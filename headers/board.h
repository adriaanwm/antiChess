#ifndef BOARD
#define BOARD

#include <iostream>
#include "../headers/board.h"
#include "../headers/soldier.h"

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

      //check if player is trying to move their own piece
      bool belongsToPlayer(string color, int r, int c);
      //check if the move is an attack (only checks of square is occupied)
      bool isAttack(int r, int c);
      //Perform attack
      bool performAttack(int r, int c, int nr, int nc);
      //check if player has any pieces that can attack
      bool hasAvailableAttack();
      //perform move
      bool performMove(int r, int c, int nr, int nc);

      bool gameOver();

      //ascii
      void asciiSetup();
      void display();

      //GUI
      void status(string arr[][8]);

};

#endif
