#include "../headers/board.h"

Board::Board(){

	for (int i=7;i>=0;i--){
		for(int j=7;j>=0;j--){
			soldier[i][j]=NULL;
		}
	}
	asciiSetup();

}

bool Board::move(int r, int c, int nr, int nc, string cp){
	//check if piece belongs to current player
	//if(!belongsToPlayer(cp,r,c)) return false;
	//check if it is an attack or just a move
	//if it's an attack
	if(isAttack(nr,nc)){
		//check if it's a valid attack
		cout << "one" << endl;
		soldier[r][c]->isValidAttack(r,c,nr,nc);
		cout << "two" << endl;
		//do the attack
		performAttack(r,c,nr,nc);
		cout << "one" << endl;
		return true;
	}
	else{

	}
	//if it is just a move then scanforattack
		//check if it is a valid movement
		//do the move
	return false;
}



bool Board::belongsToPlayer(string color, int r, int c){
	cout << "zero" << endl;
	if(soldier[r][c]->getColor() == color) return true;
	return false;
}

bool Board::isAttack(int r, int c){
	if(soldier[r][c] != NULL) return true;
	return false;
}

bool Board::performAttack(int r, int c, int nr, int nc){
	if(soldier[nr][nc]->getColor() == "w"){
		removeSoldierFromBoard(nr,nc,"w");
		soldier[nr][nc] = soldier[r][c];
		soldier[r][c] = NULL;
		return true;
	}else if(soldier[nr][nc]->getColor() == "b"){
		removeSoldierFromBoard(nr,nc,"b");
		soldier[nr][nc] = soldier[r][c];
		soldier[r][c] = NULL;
		return true;
	}
	return false;
}

bool Board::removeSoldierFromBoard(int r , int c, string color){
	Soldier *temp;
	int i=1;
	if(color == "w"){
		temp = whiteDeadSoldier[0];
		while(temp != NULL && i<16){
			temp = whiteDeadSoldier[i];
			i++;
		}
		temp = soldier[r][c];
		soldier[r][c] = NULL;
		return true;
	}
	else if(color == "b"){
		temp = blackDeadSoldier[0];
		while(temp != NULL && i<16){
			temp = blackDeadSoldier[i];
			i++;
		}
		temp = soldier[r][c];
		soldier[r][c] = NULL;
		return true;
	}
	return false;
}


//ascii
void Board::display(){

	for (int i=0;i<8;i++){
		cout << i << " ";
		for(int j=0;j<8;j++){
			if (soldier[i][j]!=NULL) cout << soldier[i][j]->getAsciiName() << " ";
			else cout << square[i][j] << " ";
		}
		cout << endl;
	}
	cout << "  0  1  2  3  4  5  6  7"<<endl;
	return;
}

void Board::asciiSetup(){
	string WhiteSquare = " ";
	string BlackSquare = "\u2588";

	for(int i=0;i<8;i+=2){
		for(int j=0;j<8;j+=2){
			square[i][j] = WhiteSquare + WhiteSquare;
			square[i][j+1] = BlackSquare + BlackSquare;
		}
	}
	for(int i=1;i<8;i+=2){
		for(int j=0;j<8;j+=2){
			square[i][j] = BlackSquare + BlackSquare;
			square[i][j+1] = WhiteSquare + WhiteSquare;
		}
	}
	for(int i=0;i<8;i++){
		soldier[1][i] = new Soldier("w");
		soldier[6][i] = new Soldier("b");
	}
	return;
}