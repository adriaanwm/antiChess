#include <gtk/gtk.h>
#include <iostream>
#include <cstdlib>

#include "../headers/BoardWidget.h"
#include "../headers/GUIConst.h"
#include "../headers/EventBoxes.h"


using namespace std;

//--Constructor--//
BoardWidget::BoardWidget() 
{
   //--Creates a New Table Object to Act as the ChessBoard--//
   //--TRUE because tables is Homogeneous (All blocks are the Same Size)--//
   BoardTable = gtk_table_new(XChessSquares, YChessSquares, TRUE);

   //--BoardTable--//
   gtk_widget_set_size_request(BoardTable, TableSizeX, TableSizeY);
}


//--Destructor--//
BoardWidget::~BoardWidget() 
{
	cout << "Deleting BoardWidget" << endl; 
}

//--Return pointer to GTK Score Banner Widget--//
GtkWidget* BoardWidget::GetWidget()
{
	return BoardTable;
}


void BoardWidget::AttachBoxes()
{
	int x = 0;
	int y = 0;

	int x_Start = 0;
	int x_End   = 1;

	int y_Start = 0;
	int y_End   = 1;

	int Printed = 0;

	while ((x < XChessSquares) && (y < YChessSquares)) {

		ChessSquare[x][y] = new EventBoxes;
		if (ChessSquare[x][y] == NULL) {cerr << "Memeory Error" << endl; exit(1);} 


		ChessSquare[x][y]->setCord(x,y, ActionSetterPtr);

		gtk_table_attach(
			GTK_TABLE(GTK_TABLE(BoardTable)), 
			ChessSquare[x][y]->GetWidget(), 
			x_Start, 
			x_End, 
			y_Start, 
			y_End, 
			GTK_FILL, GTK_FILL, 
			0, 0
		);

		x_Start = x_End;
		x_End = x_Start + 1;

		if ( (((x + 1) % XChessSquares) == 0) && (x > 2)) {
			x_Start = 0;
			x_End = 1;
			x = 0;

			y_Start = y_End;
			y_End = y_Start + 1;
			y++;
		} else {
			x++;	
		}

	};
}


void BoardWidget::setActionSetter(ActionSetter* Passed)
{
	ActionSetterPtr = Passed;
    AttachBoxes();	
}