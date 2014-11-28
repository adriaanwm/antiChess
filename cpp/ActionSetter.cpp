#include <gtk/gtk.h>
#include <iostream>
#include <cstdlib>

#include "../headers/board.h"
#include "../headers/ActionSetter.h"

using namespace std;

ActionSetter::ActionSetter()
{
	Player1Turn = false;
	Player1Action = false;
	Player2Turn = false;
	Player2Action = false;

	InvalidMove = false;
	InactiveSquare = false;
}

ActionSetter::~ActionSetter()
{
}

void ActionSetter::SetBoardWidget(BoardWidget* Passed)
{
	GUIBoard = Passed;
	if (GUIBoard == NULL) {cerr << "Mem Error" << endl; exit(1);};
}

void ActionSetter::MoveRequest(int xCord, int yCord) 
{
	cout << "Moved " << xCord << yCord << endl;
}