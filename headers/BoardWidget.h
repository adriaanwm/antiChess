#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <gtk/gtk.h>

#include "../headers/GUIConst.h"
#include "../headers/EventBoxes.h"
#include "../headers/ImageFiles.h"

class BoardWidget
{

private:
	GtkWidget* BoardTable;

	EventBoxes ChessSquare[XChessSquares][YChessSquares];
	//ImageFiles UnitPicture;
	void AttachBoxes();

public:
	BoardWidget();
	~BoardWidget();

	//--Return pointer to GTK Score Banner Widget--//
	GtkWidget* GetWidget();




};

#endif