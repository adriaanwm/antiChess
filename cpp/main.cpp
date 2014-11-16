#include <gtk/gtk.h>

#include "../headers/chessgame.h"
#include "../headers/Window.h"

using namespace std;

int main(int argc, char *argv[]){

	gtk_init(&argc, &argv);
	ChessGame game;

	Window MainWindow;

    gtk_widget_show_all(MainWindow.GetTop());

 
	gtk_main();


	//game.asciiPlay();




	return 0;

}
