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


      //ascii
      void asciiSetup();
      void display();

};

#endif
