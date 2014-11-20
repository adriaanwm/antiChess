#include <gtk/gtk.h>

#include "../headers/chessgame.h"
#include "../headers/Window.h"

using namespace std;

//--THINGS DAVID WILL DO, MAKE SCORE WID INIT IN MAIN THEN PASS TO WINDOW SO NAMES--//

int main(int argc, char *argv[]){

	gtk_init(&argc, &argv);
	ChessGame game;

	Window MainWindow;

    gtk_widget_show_all(MainWindow.GetWidget());

 
	gtk_main();


	//game.asciiPlay();




	return 0;

}
