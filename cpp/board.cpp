#include "../headers/board.h"

Board::Board(){

	for (int i=7;i>=0;i--){
		for(int j=7;j>=0;j--){
			soldier[i][j]=NULL;
		}
	}
	asciiSetup();

}

bool Board::move(int r, int c, int nr, int nc){
	return true;
}

//ascii
void Board::display(){

	for (int i=7;i>=0;i--){
		cout << i << " ";
		for(int j=7;j>=0;j--){
			if (soldier[i][j]!=NULL) cout << "S" << " ";
			else cout << square[i][j] << " ";
		}
		cout << endl;
	}
	cout << "  0 1 2 3 4 5 6 7"<<endl;
	return;
}

void Board::asciiSetup(){
	string WhiteSquare = " ";
	string BlackSquare = "\u2588";

	for(int i=0;i<8;i+=2){
		for(int j=0;j<8;j+=2){
			square[i][j] = WhiteSquare;
			square[i][j+1] = BlackSquare;
		}
	}
	for(int i=1;i<8;i+=2){
		for(int j=0;j<8;j+=2){
			square[i][j] = BlackSquare;
			square[i][j+1] = WhiteSquare;
		}
	}
	for(int i=0;i<8;i++){
		soldier[1][i] = new Soldier('W');
		soldier[6][i] = new Soldier('B');
	}
	return;
}