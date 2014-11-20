#include <gtk/gtk.h>
#include <iostream>

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

   AttachBoxes();
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
	do{
		x++;
		y++;

	} while ((x < XChessSquares) && (y <= YChessSquares));
}