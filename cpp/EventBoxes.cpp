#include <gtk/gtk.h>
#include <iostream>

#include "../headers/EventBoxes.h"
#include "../headers/BoardWidget.h"
#include "../headers/GUIConst.h"

using namespace std;

//--Constructor--//
EventBoxes::EventBoxes() 
{
	Box = gtk_event_box_new();
	X_Value = 0;
	Y_Value = 0;

    gtk_widget_set_size_request(Box, TableSizeX / XChessSquares, TableSizeY / YChessSquares);
}


//--Destructor--//
EventBoxes::~EventBoxes() 
{
	cout << "Deleting EventBoxes" << endl; 
}

void EventBoxes::setCord(int x, int y)
{
	X_Value = x;
	Y_Value = y;

    GdkColor Color;

    //--Assign background colors to chess board--//
	//--If X & Y share pairity then they are White, else they are black.--//
	if ((X_Value % 2) == (Y_Value % 2)) {
		gdk_color_parse(LightSquare, &Color);
	} else {
		gdk_color_parse(DarkSquare, &Color);
	}

	gtk_widget_modify_bg(Box, GTK_STATE_NORMAL, &Color);
}

//--Return pointer to GTK Score Banner Widget--//
GtkWidget* EventBoxes::GetWidget()
{
	return Box;
}