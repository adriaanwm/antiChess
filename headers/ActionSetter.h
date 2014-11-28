#ifndef ACTIONSETTER_H
#define ACTIONSETTER_H

#include "../headers/board.h"
#include "../headers/BoardWidget.h"


class ActionSetter
{
private:
	bool Player1Turn;
	bool Player1Action;
	bool Player2Turn;
	bool Player2Action;

	bool InvalidMove;
	bool InactiveSquare;


	//Board GameBoard;
	BoardWidget* GUIBoard;

public:
	ActionSetter();
	~ActionSetter();

	void MoveRequest(int xCord, int yCord);

	void SetBoardWidget(BoardWidget* Passed);
};

#endif