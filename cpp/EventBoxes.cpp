#include <gtk/gtk.h>
#include <iostream>

#include "../headers/EventBoxes.h"
#include "../headers/GUIConst.h"

using namespace std;

//--Constructor--//
EventBoxes::EventBoxes() 
{
	cout << "New Event Box" << endl;
}


//--Destructor--//
EventBoxes::~EventBoxes() 
{
	cout << "Deleting EventBoxes" << endl; 
}

//--Return pointer to GTK Score Banner Widget--//
GtkWidget* EventBoxes::GetWidget()
{
	return Box;
}