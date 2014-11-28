#ifndef WINDOW_H
#define WINDOW_H 

#include <gtk/gtk.h>

#include "../headers/ScoreWidget.h"
#include "../headers/BoardWidget.h"
#include "../headers/StatusWidget.h"
#include "../headers/ActionSetter.h"



//#include "..//"

class Window {

private:
   ActionSetter StateSet;

   GtkWidget *TopWindow;
   GtkWidget *MainFrame;
   GtkWidget *BoardTable;

   ScoreWidget TopScore;
   BoardWidget GUIBoard;
   StatusWidget BottomStatus;



   //--Applies Desired Properties (Dimensions, Title, Pos ect.) to the main window--//
   void SetUpWindow();


   void MakeMainfr();
   void AttachContainers();

public:
   Window(std::string Name1, std::string Name2);
   ~Window();

   GtkWidget* GetWidget();

};


#endif