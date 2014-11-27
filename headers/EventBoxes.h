#ifndef EVENTBOXES_H
#define EVENTBOXES_H

#include <gtk/gtk.h>

#include "../headers/GUIConst.h"
#include "../headers/board.h"
//#include "../headers/board.h"

class EventBoxes
{

private:
	GtkWidget* Box;
	Board* ChessBoardPtr;
	int X_Value; 
	int Y_Value;

public:
	EventBoxes();
	~EventBoxes();

	void setCord(int x, int y);

	//--Return pointer to GTK Score Banner Widget--//
	GtkWidget* GetWidget();


};

#endif