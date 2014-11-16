#include <gtk/gtk.h>
#include <iostream>


#include "../headers/StatusWidget.h"
#include "../headers/GUIConst.h"

using namespace std;

//--Constructor--//
StatusWidget::StatusWidget() 
{
    //--Create Bottom Widget to Display Status--//
    Status = gtk_label_new("Error");

    //--Set label Size and Justification--//
    gtk_widget_set_size_request(Status, BottomBannerX, BottomBannerY);
    gtk_label_set_justify(GTK_LABEL(Status), GTK_JUSTIFY_FILL);

    //--Set to the Default Working--//
	Working();
}

//--Destructor--//
StatusWidget::~StatusWidget() 
{
	cout << "Deleting Status Widget" << endl; 
}

//--Sets the status bar to working--//
void StatusWidget::Working() 
{
	gtk_label_set_text (GTK_LABEL(Status), WorkingMSG);

    //--Creates a Green Color for Text--//
    GdkColor WorkingGreen;
    gdk_color_parse (MEDIUMGREEN, &WorkingGreen);
    gtk_widget_modify_fg (Status, GTK_STATE_NORMAL, &WorkingGreen);
}

//--Returns status bar widget--//
GtkWidget* StatusWidget::GetWidget()
{
	return Status;
}