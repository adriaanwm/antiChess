#include <gtk/gtk.h>
#include <string>
#include <sstream>
#include <iostream>


#include "../headers/ScoreWidget.h"
#include "../headers/GUIConst.h"

//--Think about inheriting names from TopWindow()--//

using namespace std;

//--Constructor--//
ScoreWidget::ScoreWidget()
{
	p1Score = 0;
	p2Score = 0;
	p1Name = p1NameConst;
	p2Name = p2NameConst;

	//--Create Bottom Widget to Display Status--//
	ScoreBanner = gtk_label_new("ScoreBanner");

	//--Set sizes and allignment--//
	gtk_widget_set_size_request(ScoreBanner, TopBannerX, TopBannerY);
    gtk_label_set_justify(GTK_LABEL(ScoreBanner), GTK_JUSTIFY_FILL);

    //--Draws Score Banner with Current Information--//
	ReDrawBanner();
}

//--Destructor--//
ScoreWidget::~ScoreWidget()
{
	cout << "Deleting Score Widget" << endl; 

}

//--Draws Score Banner with Current Information--//
void ScoreWidget::ReDrawBanner()
{
	//--Combined Names, and Scores--//
	stringstream tempStream;
	tempStream << p1Name 
			  << p1Score
			  << Spaces20 
			  << p2Name
			  << p2Score;

   //--Set Score Banner--//
   gtk_label_set_text (GTK_LABEL(ScoreBanner), tempStream.str().c_str());
}

//--Return pointer to GTK Score Banner Widget--//
GtkWidget* ScoreWidget::GetWidget()
{
	return ScoreBanner;
}