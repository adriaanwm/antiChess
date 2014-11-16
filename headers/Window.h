#ifndef WINDOW_H
#define WINDOW_H 

#include <gtk/gtk.h>

class Window {

private:
   GtkWidget *TopWindow;
   GtkWidget *MainFrame;
public:
   Window();
   ~Window() {};

   void SetUpWindow();
   void MakeMainfr();

   GtkWidget* GetTop();

};


#endif