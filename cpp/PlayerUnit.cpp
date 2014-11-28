#include <gtk/gtk.h>
#include <iostream>
#include <cstdlib>
#include <string>

#include "../headers/PlayerUnit.h"
#include "../headers/GUIConst.h"

using namespace std;


//--Constructor--//
PlayerUnit::PlayerUnit(string File2Load) 
{
	InUse = false;
	//GdkWidget* Pixbuff;
	Image = gtk_image_new_from_file(File2Load.c_str());
}


//--Destructor--//
PlayerUnit::~PlayerUnit() 
{
}

GtkWidget* PlayerUnit::GetImage(int &Error)
{
	return Image;
}