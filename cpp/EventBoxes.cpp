#include <gtk/gtk.h>
#include <iostream>

#include "../headers/EventBoxes.h"
#include "../headers/BoardWidget.h"
#include "../headers/GUIConst.h"
#include "../headers/ActionSetter.h"


using namespace std;

void EventBoxes::Move()
{	
	Action->MoveRequest(X_Value, Y_Value); 
}


//--Constructor--//
EventBoxes::EventBoxes() 
{
	Box = gtk_event_box_new();
    gtk_widget_set_size_request(Box, TableSizeX / XChessSquares, TableSizeY / YChessSquares);


	g_signal_connect_swapped(
		G_OBJECT(Box), 
		Clicked, 
		G_CALLBACK(DoMoveCB), 
		this
	); 

	X_Value = 0;
	Y_Value = 0;
}


//--Destructor--//
EventBoxes::~EventBoxes() 
{
}

void EventBoxes::setCord(int x, int y, ActionSetter* LinkToAction)
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

int EventBoxes::getx()
{
	return X_Value;
}

int EventBoxes::gety() 
{
	cout << "gety" << Y_Value << endl;

	return Y_Value;
}