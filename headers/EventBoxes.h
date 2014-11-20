#ifndef EVENTBOXES_H
#define EVENTBOXES_H

#include <gtk/gtk.h>

#include "../headers/GUIConst.h"

class EventBoxes
{

private:
	GtkWidget* Box;

public:
	EventBoxes();
	~EventBoxes();

	//--Return pointer to GTK Score Banner Widget--//
	GtkWidget* GetWidget();


};

#endif