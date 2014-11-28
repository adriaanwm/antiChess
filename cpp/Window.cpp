#include <gtk/gtk.h>
#include <sstream>
#include <iostream>

#include "../headers/Window.h"
#include "../headers/GUIConst.h"
#include "../headers/ScoreWidget.h"
#include "../headers/BoardWidget.h"
#include "../headers/StatusWidget.h"

using namespace std;


Window::Window(std::string Name1, std::string Name2)
{
   MakeMainfr();
   SetUpWindow();

   TopScore.SetNames(Name1, Name2);

   AttachContainers();
   StateSet.SetBoardWidget(&GUIBoard);
   GUIBoard.setActionSetter(&StateSet);
}

Window::~Window()
{
   cout << "Deleting Window Object";
}

void Window::AttachContainers()
{
   //--Attach Objects to MainFrame--//
   gtk_table_attach(
      GTK_TABLE(MainFrame), 
      TopScore.GetWidget(), 
      TopWidgetXStart, 
      TopWidgetXEnd, 
      TopWidgetYStart, 
      TopWidgetYEnd, 
      GTK_FILL, GTK_FILL, 
      0, 0
   );

   gtk_table_attach(
      GTK_TABLE(MainFrame), 
      GUIBoard.GetWidget(), 
      BoardXStart, 
      BoardXEnd, 
      BoardYStart, 
      BoardYEnd, 
      GTK_FILL, GTK_FILL, 
      0, 0
   );

   gtk_table_attach(
      GTK_TABLE(MainFrame), 
      BottomStatus.GetWidget(), 
      BottomWidgetXStart, 
      BottomWidgetXEnd, 
      BottomWidgetYStart, 
      BottomWidgetYEnd, 
      GTK_FILL, GTK_FILL, 
      0, 0
   ); 

   //-- Attach MainFrame table to the window--//
   gtk_container_add(GTK_CONTAINER(TopWindow), MainFrame);
}

//--Applies Desired Properties (Dimensions, Title, Pos ect.) to the main window--//
void Window::SetUpWindow()
{
   //--Create a Window title that forces the window title to be displayed on the left--//
   stringstream TempTitle;
   TempTitle << Window_Title;
   for (int i = 0; i < Win_SizeX; i++) {
      TempTitle << Spaces20;
   }

   TopWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);

   //--Set the Window Title, Constant char Array--//
   gtk_window_set_title(GTK_WINDOW(TopWindow), TempTitle.str().c_str());

   //--Set the Window Size, (GTKWidget, Width, Height)--//
   gtk_widget_set_size_request(TopWindow, Win_SizeX, Win_SizeY);

   //--Make the Window not Realizable--//
   gtk_window_set_resizable(GTK_WINDOW(TopWindow), Resizable);

   //--Centers the Window--//
   gtk_window_set_position(GTK_WINDOW(TopWindow), GTK_WIN_POS_CENTER);

   //--CallBack -- Makes the program close when the 'X' is pressed--//
   g_signal_connect_swapped(
      G_OBJECT(TopWindow), 
      "destroy", 
      G_CALLBACK(gtk_main_quit), 
      NULL
   );
}

void Window::MakeMainfr()
{
   //--Container Objects Must be Initialized Here, otherwise GTK will have errors--//
   //--Creates the Main Container to house all the objects in the window--//
   //--FALSE because tables is not Homogeneous (Not all blocks are the same)--//
   MainFrame = gtk_table_new(CcountX, CcountY, FALSE); 

   //--Set Object Sizes, and Properties--//
   //--MainFrame--//
   gtk_widget_set_size_request(MainFrame, Win_SizeX, Win_SizeY);
}



GtkWidget* Window::GetWidget() 
{
   return TopWindow;
}
