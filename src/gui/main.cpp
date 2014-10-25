#include <gtk/gtk.h>
#include <cstring>
#include <iostream>

using namespace std;

//--Size Of the Window in pixels--//
const int Win_SizeX = 600;
const int Win_SizeY = 600;

//--Number of Squares on the ChessBoard--//
const int XChessSquares = 8;
const int YChessSquares = 8;
const int TotalSquares = (XChessSquares * YChessSquares);

//--FileNames of Images to Be loaded--//
const char DarkNAME[] = "blvk.png";
const char LightNAME[] = "wht.png";
//-Used If to show the player what spots are Availible--//
const char HoverNAME[] = "Highlighted.png";

//--Is the Window Resizeable? False = No, because The gameboard doesn't scale--//
const bool Resizable = false;

//--Window Title--//
const char Window_Title[] = "Anti-Chess";

   //-Rudamentry Function, just trying to draw the board. David will Re-Write--//
   void DrawChessBoard(GtkWidget *Table, GtkWidget *Square[]) {
      int OutCount = 0
      ;
      int YStart = 0;
      int YEnd = 1;
      int XStart = 0;
      int XEnd = 1;

      for (int i = 0; i <= TotalSquares - 1; i++) { 
         gtk_table_attach(GTK_TABLE(Table), Square[i], YStart, YEnd, XStart, XEnd, GTK_FILL, GTK_FILL, 0, 0);
         XStart = XEnd + 1;
         XEnd = XStart + 1;
         OutCount++;
         if ( (OutCount % (YChessSquares)) == 0) {
            YStart = YEnd + 1;
            YEnd = YStart + 1;
            XStart = 0;
            XEnd = 1;
         }
      }

  }

int main(int argc, char *argv[]) {

   GtkWidget *MyWindow, *Table, *Square[TotalSquares], *Minus;

   gtk_init(&argc, &argv);

   //--Creates New GTK window Object--//
   MyWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);

   //--Set the Window Title, Constant char Array--//
   gtk_window_set_title(GTK_WINDOW(MyWindow), Window_Title);

   //--Set the Window Size, (GTKWidget, Width, Height)--//
   gtk_widget_set_size_request(MyWindow, Win_SizeX, Win_SizeY);

   //--Make the Window not Resizeable--//
   gtk_window_set_resizable(GTK_WINDOW(MyWindow), Resizable);

   //--Centers the Window--//
   gtk_window_set_position(GTK_WINDOW(MyWindow), GTK_WIN_POS_CENTER);


   //--WIll re wirte with new method only needed to load the images once per file--//
   //--START OF LOOP, Creates new Image Object--//
   int P_COUNT = 0;
   int rowCount = 0;
   for (int i = 0; i <= TotalSquares; i++) {

      if ((rowCount % 2) == 0) {

         if ((i % 2) == 0) {
            Square[i] = gtk_image_new_from_file(LightNAME);
            cout << " W ";
            P_COUNT++;
            
         } else {
            Square[i] = gtk_image_new_from_file(DarkNAME);
            cout << " B ";
            P_COUNT++;
         }

      } else {

         if ((i % 2) != 0) {
            Square[i] = gtk_image_new_from_file(LightNAME);
            cout << " W ";
            P_COUNT++;
            
         } else {
            Square[i] = gtk_image_new_from_file(DarkNAME);
            cout << " B ";
            P_COUNT++;
         }
      }

      if ((P_COUNT % 8) == 0) { cout << endl; rowCount++;}

   } //--EMD OF LOOP --//


   //--CallBack -- Makes the program close when the 'X' is pressed--//
   g_signal_connect_swapped(G_OBJECT(MyWindow), "destroy", G_CALLBACK(gtk_main_quit), NULL);


   //--Creates a New Table obkect--//
   Table = gtk_table_new(XChessSquares, YChessSquares, 0);

   //--Trial Function to draw table--//
   DrawChessBoard(Table, Square);
   

   //--Adds the table to the Window--//
   gtk_container_add(GTK_CONTAINER(MyWindow), Table);
   

   //--Show Window & Contents--//
   gtk_widget_show_all(MyWindow);
   gtk_main();

   return 0;
}

//compile with "g++ main.cpp -o out `pkg-config --cflags --libs gtk+-3.0`"
// 2.0 if at school
