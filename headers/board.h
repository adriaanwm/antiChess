#ifndef BOARD
#define BOARD

#include <iostream>
#include "../headers/board.h"
#include "../headers/soldier.h"

using namespace std;

class Board{
   private:
		Soldier *soldier[8][8];

		//ascii
		string square[8][8];

   public:
      Board();
      bool move(int r, int c, int nr, int nc);

      //check if player is trying to move their own piece
      bool isColor(string color, int r, int c);


      //ascii
      void asciiSetup();
      void display();

};

#endif
