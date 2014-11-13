// Place all memebers of the board within a GTK event box.
// Load images to pixbufffs, then new image from pixbuf.


#include <gtk/gtk.h>
#include <cstring>
#include <string>
#include <iostream>

#include "GUIConst.h"
#include "FileNameConst.h"

using namespace std;


///===CONSTANTS FOR GAMEPLAY===//

//--Number of Squares on the ChessBoard--//
const int XChessSquares = 8;
const int YChessSquares = 8;
const int TotalSquares = (XChessSquares * YChessSquares);



int main(int argc, char *argv[]) {

   gtk_init(&argc, &argv);


      //--Main Window Container--//
   GtkWidget *TopWindow;

   //--Table to hold all the contents of the window--//
   GtkWidget *MainFrame;

   //--Chessboard Table--//
   GtkWidget *BoardTable;

   //--Top Textbox for Score, and bottom for status--//
   GtkWidget *TopWidget, *BottomWidget;


   //--Creates New GTK window Object--//
   TopWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);

   //--Set the Window Title, Constant char Array--//
   gtk_window_set_title(GTK_WINDOW(TopWindow), Window_Title);

   //--Set the Window Size, (GTKWidget, Width, Height)--//
   gtk_widget_set_size_request(TopWindow, Win_SizeX, Win_SizeY);

   //--Make the Window not Resizeable--//
   gtk_window_set_resizable(GTK_WINDOW(TopWindow), Resizable);

   //--Centers the Window--//
   gtk_window_set_position(GTK_WINDOW(TopWindow), GTK_WIN_POS_CENTER);

   //--CallBack -- Makes the program close when the 'X' is pressed--//
   g_signal_connect_swapped(G_OBJECT(TopWindow), "destroy", G_CALLBACK(gtk_main_quit), NULL);




   TopWidget = gtk_label_new("Foo Accepts c_str()");
   gtk_widget_set_size_request(TopWidget, TopBannerX, TopBannerY);
   gtk_label_set_justify(GTK_LABEL(TopWidget), GTK_JUSTIFY_CENTER);

   //--Creates a New Table Object to Act as the ChessBoard--//
   BoardTable = gtk_table_new(XChessSquares, YChessSquares, TRUE);
   gtk_widget_set_size_request(BoardTable, TableSizeX, TableSizeY);

   BottomWidget = gtk_label_new("Working");
   gtk_widget_set_size_request(BoardTable, BottomBannerX, BottomBannerY);
   gtk_label_set_justify(GTK_LABEL(BottomWidget), GTK_JUSTIFY_CENTER);


   //--Creates the Main Container to house all the objects in the window--//
   MainFrame = gtk_table_new(CcountX, CcountY, FALSE);
   gtk_widget_set_size_request(MainFrame, Win_SizeX, Win_SizeY);


   //--Attach Objects to MainFrame--//
   gtk_table_attach(
      GTK_TABLE(MainFrame), 
      TopWidget, 
      TopWidgetXStart, 
      TopWidgetXEnd, 
      TopWidgetYStart, 
      TopWidgetYEnd, 
      GTK_FILL, GTK_FILL, 
      0, 0
   );

   gtk_table_attach(
      GTK_TABLE(MainFrame), 
      BoardTable, 
      BoardXStart, 
      BoardXEnd, 
      BoardYStart, 
      BoardYEnd, 
      GTK_FILL, GTK_FILL, 
      0, 0
   );

   gtk_table_attach(
      GTK_TABLE(MainFrame), 
      BottomWidget, 
      BottomWidgetXStart, 
      BottomWidgetXEnd, 
      BottomWidgetYStart, 
      BottomWidgetYEnd, 
      GTK_FILL, GTK_FILL, 
      0, 0
   );

   /* Test Layout with Images
{  // These Brackets exist to enable hiding this segment of code in sublime (Text Editor)
   Test Image Files Load Suff 
   GtkWidget *TopTestIMG, *BoardTestIMG, *BottomTestIMG;

   const string TopFN = ImgFolder + "tpbrd.png";
   const string BotFN = ImgFolder + "btmbrd.png";
   const string BrdFN = ImgFolder + "brd.png";

   cout << "Image File Names:" << endl;
   cout << TopFN << endl << BotFN << endl << BrdFN << endl;
   cout << "Loading Images..." << endl;

   cout << "Loading: " << TopFN.c_str() << " | ";
   TopTestIMG = gtk_image_new_from_file(TopFN.c_str());   
   cout << "Complete" << endl;

   cout << "Loading: " << BotFN.c_str() << " | ";
   BottomTestIMG = gtk_image_new_from_file(BotFN.c_str());   
   cout << "Complete" << endl;

   cout << "Loading: " << BrdFN.c_str() << " | ";
   BoardTestIMG = gtk_image_new_from_file(BrdFN.c_str());   
   cout << "Complete" << endl;

   gtk_table_attach(GTK_TABLE(MainFrame), TopTestIMG, TopWidgetXStart, TopWidgetXEnd, TopWidgetYStart, TopWidgetYEnd, GTK_FILL, GTK_FILL, 0, 0);
   gtk_table_attach(GTK_TABLE(MainFrame), BoardTestIMG, BoardXStart, BoardXEnd, BoardYStart, BoardYEnd, GTK_FILL, GTK_FILL, 0, 0);
   gtk_table_attach(GTK_TABLE(MainFrame), BottomTestIMG, BottomWidgetXStart, BottomWidgetXEnd, BottomWidgetYStart, BottomWidgetYEnd, GTK_FILL, GTK_FILL, 0, 0);
}
   */






  //GdkColor color;
  //gdk_color_parse ("red", &color);
  //gtk_widget_modify_fg (MainFrame, GTK_STATE_NORMAL, &color);






   //-- Attach MainFrame table to the window--//
   gtk_container_add(GTK_CONTAINER(TopWindow), MainFrame);

   //--Show Window & Contents--//
   gtk_widget_show_all(TopWindow);

   gtk_main();



   return 0;
}

//compile with "g++ main.cpp -o out `pkg-config --cflags --libs gtk+-3.0`"
// 2.0 if at school

