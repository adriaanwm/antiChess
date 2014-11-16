#ifndef SCOREWIDGET_H
#define SCOREWIDGET_H 

#include <gtk/gtk.h>
#include <string>

class ScoreWidget
{
private:
	int p1Score;
	int p2Score;
	std::string p1Name;
	std::string p2Name;

	GtkWidget* ScoreBanner;

    //--Draws Score Banner with Current Information--//
	void ReDrawBanner();
public:
	ScoreWidget();
	~ScoreWidget();
	
	//--Return pointer to GTK Score Banner Widget--//
	GtkWidget* GetWidget();
};

#endif