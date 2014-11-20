#ifndef EVENTBOXES_H
#define EVENTBOXES_H

#include <gtk/gtk.h>

#include "../headers/GUIConst.h"
#include "../headers/board.h"

class EventBoxes
{

private:
	GtkWidget* Box;

public:
	EventBoxes();
	~EventBoxes();

	//void SetColor(GDK COLOR);

	//--Return pointer to GTK Score Banner Widget--//
	GtkWidget* GetWidget();


};

#endif