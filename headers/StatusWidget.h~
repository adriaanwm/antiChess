#ifndef  STATUSWIDGET_H
#define STATUSWIDGET_H 

#include <gtk/gtk.h>

const char BadMoveMSG[] = "Invalid Move";
const char WorkingMSG[] = "No Move Errors :)";

class StatusWidget
{
	
private:
	GtkWidget* Status;

public:
	StatusWidget();
	~StatusWidget();

	//--Returns status bar widget--//
	GtkWidget* GetWidget();

	//--Sets the status bar to working--//
	void Working();

	//--Sets the status bar to Invlaid move--//
	void InvalidMove();
};

#endif