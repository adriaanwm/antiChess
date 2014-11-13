#include <gtk/gtk.h>
#include <cstring>
#include <iostream>

class BoardLocation {
   private:
      int X;
      int Y;
   public:
      BoardLocation();
      ~BoardLocation() {};
      int getX();
      int getY();
      void setY(int PassedY);
      void setX(int PassedX);
};

using namespace std;

const int Win_SizeX = 600;
const int Win_SizeY = 600;

const int XChessSquares = 8;
const int YChessSquares = 8;
const int TotalSquares = (XChessSquares * YChessSquares);

const char BLKNAME[] = "blvk.png";
const char WHTNAME[] = "wht.png";

const gboolean Resize = false;

const bool Resizable = false;

const char Window_Title[] = "Anti-Chess";

BoardLocation::BoardLocation() {
   X = 0;
   Y = 0;
}

int BoardLocation::getX() {
   return X;
}

int BoardLocation::getY() {
   return Y;
}

void BoardLocation::setX(int PassedX) {
   X = PassedX;
}

void BoardLocation::setY(int PassedY) {
   Y = PassedY;
}

/*void UpdateImage(GtkWidget *widget)
{
  widget = gtk_image_new_from_file(WhiteSquareFileName);
}*/

  void DrawTable(GtkWidget *Table, GtkWidget *Square[]) {
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
         if ( (OutCount % (YChessSquares - 1)) == 0) {
            YStart = YEnd + 1;
            YEnd = YStart + 1;
            XStart = 0;
            XEnd = 1;
         }
      }

      /*gtk_table_attach(GTK_TABLE(Table), Square[0], 0, 1, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
      gtk_table_attach(GTK_TABLE(Table), Square[1], 0, 1, 2, 3, GTK_FILL, GTK_FILL, 0, 0);
      gtk_table_attach(GTK_TABLE(Table), Square[2], 0, 1, 4, 7, GTK_FILL, GTK_FILL, 0, 0);*/

  }

int main(int argc, char *argv[]) {

   GtkWidget *MyWindow, *Table, *Square[TotalSquares], *Minus;

   gtk_init(&argc, &argv);

   MyWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);

   //--Set the Window Title, Constant char Array--//
   gtk_window_set_title(GTK_WINDOW(MyWindow), Window_Title);

   //--Set the Window Size, (GTKWidget, Width, Height)--//
   gtk_widget_set_size_request(MyWindow, Win_SizeX, Win_SizeY);

   //--Make the Window not Resizeable--//
   gtk_window_set_resizable(GTK_WINDOW(MyWindow), Resizable);

   //--Centers the Window--//
   gtk_window_set_position(GTK_WINDOW(MyWindow), GTK_WIN_POS_CENTER);

  //Minus = gtk_button_new_with_label("Plus Button (+)");


   //--START OF LOOP--//
   int P_COUNT = 0;
   int rowCount = 0;
   for (int i = 0; i <= TotalSquares; i++) {

      if ((rowCount % 2) == 0) {

         if ((i % 2) == 0) {
            Square[i] = gtk_image_new_from_file(WHTNAME);
            cout << " W ";
            P_COUNT++;
            
         } else {
            Square[i] = gtk_image_new_from_file(BLKNAME);
            cout << " B ";
            P_COUNT++;
         }

      } else {

         if ((i % 2) != 0) {
            Square[i] = gtk_image_new_from_file(WHTNAME);
            cout << " W ";
            P_COUNT++;
            
         } else {
            Square[i] = gtk_image_new_from_file(BLKNAME);
            cout << " B ";
            P_COUNT++;
         }
      }

      if ((P_COUNT % 8) == 0) { cout << endl; rowCount++;}

   } //--EMD OF LOOP --//


   //--Makes the program close when the 'X' is pressed--//
   g_signal_connect_swapped(G_OBJECT(MyWindow), "destroy", G_CALLBACK(gtk_main_quit), NULL);



   Table = gtk_table_new(XChessSquares, YChessSquares, 0);


   // LOOP DOESN"TWORK
   //int Pos = 0;
   //while (Pos <= TotalSquares) {
   DrawTable(Table, Square);
      



      /*gtk_table_attach(GTK_TABLE(Table), WhiteSquare, 1, 2, 1, 2, GTK_FILL, GTK_FILL, 0, 0);
      gtk_table_attach(GTK_TABLE(Table), BlackSquare2, 2, 3, 2, 3, GTK_FILL, GTK_FILL, 0, 0);
      gtk_table_attach(GTK_TABLE(Table), WhiteSquare2, 3, 4, 3, 4, GTK_FILL, GTK_FILL, 0, 0);*/


      //Pos++;
   //}



   //g_signal_connect_swapped(G_OBJECT(BlackSquare2), "click", G_CALLBACK(UpdateImage), NULL);


   gtk_container_add(GTK_CONTAINER(MyWindow), Table);
   



   //--Show Window & Contents--//
   gtk_widget_show_all(MyWindow);
   gtk_main();

   return 0;

}

//compile with "g++ main.cpp -o out `pkg-config --cflags --libs gtk+-3.0`"
// 2.0 if at school
