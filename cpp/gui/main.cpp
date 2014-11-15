//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
// Title:                           AntiChess GUI                                      //
//                                                                                     //
// File Name:     | main.cpp                                                           //
// Creation Date: | 12/11/14                                                           //
// Author:        | David Aarsen                                                       //
//                                                                                     //
// Purpose: To Provide a Graphical User Interface for the AntiChess Game.              //
//          Displays a Chess Board and Unit locations, also submits moves              //
//          to logic.                                                                  //
//                                                                                     //
// Notes: Place all members of the board within a GTK event box.                       //
//        Load images to pixbufffs, then new image from pixbuf.                        //
//                                                                                     //
// References: http://zetcode.com/tutorials/gtktutorial/                               //
//             https://developer.gnome.org/gtk-tutorial/2.90/                          //
//                                                                                     //
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


//=====INCLUDED LIBRARIES==============================================================//
#include <gtk/gtk.h>
#include <string>
#include <iostream>
#include <sstream>

//=====INCLUDED FILES==================================================================//

//--Includes Many Constants used by the window, (Size, Layout, title, ect...)--//
#include "GUIConst.h"

//--Includes the filenames of Images and Folders for resources--//
#include "FileNameConst.h"

//=====NAMESPACES======================================================================//
using namespace std;

//=====ENUMERATED DATATYPES============================================================//
//--NONE--//

//=====GLOBAL CONSTANTS================================================================//
//--Number of Squares on the ChessBoard--//
const int XChessSquares = 8;
const int YChessSquares = 8;
const int TotalSquares = (XChessSquares * YChessSquares);



const int intFAILBIT = -6660666;


//=====PROTOTYPES======================================================================//
//--Applies Desired Properties (Dimensions, Title, Pos ect.) to the main window--//
int TopWindowSetup(GtkWidget *TopWindow);

//--Tests window layout with color block images--//
//void TestLayout(GtkWidget *MainFrame);

//--Loads Images, Checks for Errors while Loading
int LoadImages();

//--Attaches Widgets to Window (MainFrame)--//
int AttachWidgets(
   GtkWidget *MainFrame, 
   GtkWidget *TopWidget, 
   GtkWidget *BoardTable, 
   GtkWidget *BottomWidget
);

//--Updates the Score at the top of the window--//
int UpdateScoreBanner(GtkWidget* Passed, Score *Scores);

//--Attaches Event Boxes to chess board--//
int AttachEventBoxes(GtkWidget *ChessBoard, GtkWidget *EventBoxes[]);


int DrawBoard();



//=====MAIN ROUTIENE===================================================================//
int main(int argc, char *argv[]) {

   gtk_init(&argc, &argv);

   GtkWidget 
      *TopWindow,    //--Main Window Container--//
      *MainFrame,    //--Table to hold all the contents of the window--//
      *BoardTable,   //--Chessboard Table--//
      *TopWidget,    //--Top Text box for Score--// 
      *BottomWidget, //--Bottom for status--//
      *AppIcon,
      *BlackPIX,     
      *WhitePIX,
      *UnitPIX,
      *WhiteBoardSquare[(TotalSquares/2)],
      *BlackBoardSquare[(TotalSquares/2)],
      *EventBoxes[TotalSquares]
   ;

   Score *PlayerScores = new Score;
   if (PlayerScores == NULL) {
     // ErrorPopup(MEMORYERROR);
      cout << "Memeory Error" << endl;
      return 0;
   } else {
      PlayerScores->p1 = 0;
      PlayerScores->p2 = 0;
      PlayerScores->ScoreBar = TopWidget;
   }

   //--Creates New GTK window Object--//
   TopWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   TopWindowSetup(TopWindow);

   //--Container Objects Must be Initialized Here, otherwise GTK will have errors--//
   //--Creates the Main Container to house all the objects in the window--//
   //--FALSE because tables is not Homogeneous (Not all blocks are the same)--//
   MainFrame = gtk_table_new(CcountX, CcountY, FALSE); 

   //--Creates a New Table Object to Act as the ChessBoard--//
   //--TRUE because tables is Homogeneous (All blocks are the Same Size)--//
   BoardTable = gtk_table_new(XChessSquares, YChessSquares, TRUE);

   //--Create Top Widget to Display Score--//
   TopWidget = gtk_label_new("Error!");

   //--Create Bottom Widget to Display Status--//
   BottomWidget = gtk_label_new("Working");

   //--Create new Event Boxes for the Chess Board--//
   for (int p = 0; p <= TotalSquares - 1; p++) {
      EventBoxes[p] = gtk_event_box_new();
      gtk_widget_set_size_request(EventBoxes[p], 
         (TableSizeX / XChessSquares), 
         (TableSizeY / YChessSquares)
      );

      g_signal_connect_swapped(
         G_OBJECT(EventBoxes[p]), 
         "button_press_event", 
         G_CALLBACK(gtk_main_quit), 
         NULL
      );   
   }

   AttachEventBoxes(BoardTable, EventBoxes);

               //--Tests Window Layout w. Images--//
               //TestLayout(MainFrame);

   AttachWidgets(
      MainFrame,
      TopWidget,
      BoardTable,
      BottomWidget
   );

   //UpdateScoreBanner(TopWindow, TopWidget, p1Score, p2Score);


   //if (LoadImages() == intFAILBIT) {
   //   ErrorPopup(ImageLoadError);
   //   return 0;
   //}






   //-- Attach MainFrame table to the window--//
   gtk_container_add(GTK_CONTAINER(TopWindow), MainFrame);

   //--Show Window & Contents--//
   gtk_widget_show_all(TopWindow);

   gtk_main();



   return 0;
}


//=====TopWindowSetup==================================================================// *TopWindowSetup*
//--Applies Desired Properties (Dimensions, Title, Pos, ect.) to the main window--//
int TopWindowSetup(GtkWidget *TopWindow) 
{
   //--Create a Window title that forces the window title to be displayed on the left--//
   stringstream TempTitle;
   TempTitle << Window_Title;
   for (int i = 0; i < Win_SizeX; i++) {
      TempTitle << Spaces20;
   }

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
   return 0;
}


//=====AttachWidgets===================================================================// *AttachWidgets*
//--Attaches Widgets to Window (MainFrame)--//
int AttachWidgets(
   GtkWidget *MainFrame, 
   GtkWidget *TopWidget, 
   GtkWidget *BoardTable, 
   GtkWidget *BottomWidget
)
{
   //--Set Object Sizes, and Properties--//
   //--MainFrame--//
   gtk_widget_set_size_request(MainFrame, Win_SizeX, Win_SizeY);

   //--Top Widget--//
   gtk_widget_set_size_request(TopWidget, TopBannerX, TopBannerY);
   gtk_label_set_justify(GTK_LABEL(TopWidget), GTK_JUSTIFY_LEFT);

   //--BoardTable--//
   gtk_widget_set_size_request(BoardTable, TableSizeX, TableSizeY);

   //--Bottom Widget--//
   gtk_widget_set_size_request(BottomWidget, BottomBannerX, BottomBannerY);
   gtk_label_set_justify(GTK_LABEL(BottomWidget), GTK_JUSTIFY_FILL);

   //--Creates a Green Color for Text--//
   GdkColor WorkingGreen;
   gdk_color_parse (MEDIUMGREEN, &WorkingGreen);
   gtk_widget_modify_fg (BottomWidget, GTK_STATE_NORMAL, &WorkingGreen);

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
   return 0;
}

//=====AttachEventBoxes================================================================// *AttachEventBoxes*
//--Attaches Event Boxes to chess board--//
int AttachEventBoxes(GtkWidget *ChessBoard, GtkWidget *EventBoxes[])
{
   GdkColor Black;
   gdk_color_parse ("#FFFFFF", &Black);

   GdkColor White;
   gdk_color_parse ("#000000", &White);

   int Printed = 0;

   int X_Start= 0;
   int X_End = 1;

   int Y_Start = 0;
   int Y_End = 1;

   for (int i = 0; i < TotalSquares; i++) {
      gtk_table_attach(
         GTK_TABLE(ChessBoard), 
         EventBoxes[i],
         X_Start,
         X_End, 
         Y_Start,
         Y_End,
         GTK_FILL, GTK_FILL,
         0, 0
      );

      if (((Printed % 2) != 0)) {
         gtk_widget_modify_bg (EventBoxes[i], GTK_STATE_NORMAL, &White);
      } else {
         gtk_widget_modify_bg (EventBoxes[i], GTK_STATE_NORMAL, &Black);
      }

      X_Start = X_End;
      X_End = X_Start + 1;

      if ((((i + 1) % 8) == 0) && (i > 2)) {
         Y_Start = Y_End;
         Y_End = Y_Start + 1;

         X_Start = 0;
         X_End = 1;
         //Printed++;
      } else {
         Printed++;
      }

   }
}

//=====UpdateScoreBanner===============================================================// *UpdateScoreBanner*
//--Updates the Score at the top of the window--//
int UpdateScoreBanner(GtkWidget* Passed, Score *Scores)
{
   int p1Score = Scores->p1;
   int p2Score = Scores->p2;
   //--Combined Names, and Scores--//
   stringstream tempStream;
   tempStream << p1Name << p1Score << Spaces20 << p2Name << p2Score;

   //--Set Score Banner--//
   gtk_label_set_text (GTK_LABEL(Scores->ScoreBar), tempStream.str().c_str());
   cout << "LOL";

   Scores->p1++;
   Scores->p2++;

   return 0;
}



//=====TestLayout======================================================================// *TestLayout*
//--Tests window layout with color block images--//
/*
void TestLayout(GtkWidget *MainFrame)
{
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
} */