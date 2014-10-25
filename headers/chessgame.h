#ifndef CHESSGAME
#define CHESSGAME

#include <iostream>
#include "../headers/board.h"


using namespace std;

class ChessGame{
   private:
      Board board;
      bool over;
      string currentPlayer;

   public:
      ChessGame();
      void play();

      //handle whose turn it is
      void startingPlayer();
      char changePlayer();

};


#endif
