#ifndef WINDOW_H
#define WINDOW_H 

#include <gtk/gtk.h>

class Window {

private:
   GtkWidget *TopWindow;
public:
   Window();
   ~Window() {};

   GtkWidget* GetTop();

};


#endif