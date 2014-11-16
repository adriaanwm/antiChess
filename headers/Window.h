#ifndef WINDOW_H
#define WINDOW_H 

#include <gtk/gtk.h>

#include "../headers/ScoreWidget.h"
#include "../headers/StatusWidget.h"


//#include "..//"

class Window {

private:
   GtkWidget *TopWindow;
   GtkWidget *MainFrame;
   GtkWidget *BoardTable;

   ScoreWidget TopScore;
   StatusWidget BottomStatus;

   //--Applies Desired Properties (Dimensions, Title, Pos ect.) to the main window--//
   void SetUpWindow();


   void MakeMainfr();
   void MakeBoard();
   void AttachContainers();

public:
   Window();
   ~Window();

   GtkWidget* GetTop();

};


#endif