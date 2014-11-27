#include <gtk/gtk.h>

#include "../headers/chessgame.h"
#include "../headers/Window.h"

using namespace std;

//--THINGS DAVID WILL DO, MAKE SCORE WID INIT IN MAIN THEN PASS TO WINDOW SO NAMES--//

int main(int argc, char *argv[]){

	string Name1 = "David", Name2 = "Player 2";

	//--ASCII Menu, gets names and passes to window object--//

	gtk_init(&argc, &argv);
	//ChessGame game;

	Window MainWindow(Name1, Name2);

    gtk_widget_show_all(MainWindow.GetWidget());

 
	gtk_main();


	//game.asciiPlay();




	return 0;

}
