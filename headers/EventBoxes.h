#ifndef EVENTBOXES_H
#define EVENTBOXES_H

#include <gtk/gtk.h>

#include "../headers/GUIConst.h"

class ActionSetter;

class EventBoxes
{

private:
	GtkWidget* Box;
	int X_Value; 
	int Y_Value;
	EventBoxes* Self;

	ActionSetter* Action;



public:
	EventBoxes();
	~EventBoxes();

		void Move();

	void setCord(int x, int y, ActionSetter* LinkToAction);

	int getx();
	int gety();

	static void DoMoveCB (GtkWidget *widget, EventBoxes* data) {data->Move();}

	//--Return pointer to GTK Score Banner Widget--//
	GtkWidget* GetWidget();
};

#endif