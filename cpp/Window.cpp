#include <gtk/gtk.h>
#include <sstream>

#include "../headers/Window.h"
#include "../headers/GUIConst.h"

using namespace std;

Window::Window()
{
   SetUpWindow();

}

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

   
}

GtkWidget* Window::GetTop() 
{
   return TopWindow;
}
