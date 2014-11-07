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
      void asciiPlay();
      void guiPlay();

      //handle whose turn it is
      void startingPlayer();
      void changePlayer();

};


#endif
