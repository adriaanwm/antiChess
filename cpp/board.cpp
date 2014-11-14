#include "../headers/board.h"

Board::Board(){

	for (int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			soldier[i][j]=NULL;
		}
	}
	for (int k=0;k<16;k++){
		whiteDeadSoldier[k] = NULL;
		blackDeadSoldier[k] = NULL;
	}
	asciiSetup();

}

string Board::opponent(string cp){
	if(cp == "w") return "b";
	else return "w";
	return "w";
}

bool Board::move(int r, int c, int nr, int nc, string cp){
	if(r<0 || r>7 || c<0 || c>7 || nr<0 || nr>7 || nc<0 || nc>7) return false;

	//check if piece belongs to current player (or if there's a piece at all)
	if(!belongsToPlayer(cp,r,c)) return false;
	//check if trying to move onto own piece
	if(belongsToPlayer(cp, nr, nc))return false;
	//check if it is an attack or just a move
	//if it's an attack
	if(isAttack(nr,nc,cp)){
		//check if it's a valid attack
		if(soldier[r][c]->isValidAttack(r,c,nr,nc)){
			//do the attack
			performAttack(r,c,nr,nc);
		}
		return true;
	}
	//if it is just a move
	else{
		if(hasAvailableAttack(cp)) return false;
		else{
			//check if it's a valid move
			if(soldier[r][c]->isValidMove(r,c,nr,nc)){
				//do the move
				performMove(r,c,nr,nc);
			}
			return true;
		}
	}
	return false;
}

bool Board::belongsToPlayer(string color, int r, int c){
	if(soldier[r][c] == NULL) return false;
	if(soldier[r][c]->getColor() == color) return true;
	return false;
}

bool Board::isAttack(int r, int c, string cp){
	if(soldier[r][c] != NULL && soldier[r][c]->getColor() == opponent(cp)) return true;
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

bool Board::performMove(int r, int c, int nr, int nc){

	soldier[nr][nc] = soldier[r][c];
	soldier[r][c] = NULL;
	return true;
}

bool Board::hasAvailableAttack(string player){

	//check each piece belonging to current player for a possible attack
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(soldier[i][j] != NULL){
				if(soldier[i][j]->getColor() == player){
					if(soldier[i][j]->isKing()){
						if(hasAttackIsKing(i,j,player)) return true;
					}else if(soldier[i][j]->isKnight()){
						if(hasAttackIsKnight(i,j,player)) return true;
					}
				}
			}
		}
	}
	//hasAttackVertical?
	//hasAttackHorizontal?
	//hasAttackDiagonal?
	//hasAttackIsKnight?
	//hasAttackIsKing?
	//hasAttackIsPawn?
	return false;
}

bool Board::removeSoldierFromBoard(int r , int c, string color){
	int i=0;
	if(color == "w"){
		while(whiteDeadSoldier[i] != NULL && i<16){
			i++;
		}
		whiteDeadSoldier[i] = soldier[r][c];
		soldier[r][c] = NULL;
		return true;
	}
	else if(color == "b"){
		while(blackDeadSoldier[i] != NULL && i<16){
			i++;
		}
		blackDeadSoldier[i] = soldier[r][c];
		soldier[r][c] = NULL;
		return true;
	}
	return false;
}

bool Board::gameOver(){
	if(whiteDeadSoldier[15]!=NULL || blackDeadSoldier[15]!=NULL){
		return true;
	}
	return false;
}

bool Board::hasAttackIsKing(int r, int c, string player){
	//check right column
	if(c<7){
		if(isAttack(r,c+1,player))
			return true;
		if(r<7){
			if(isAttack(r+1,c+1,player))
				return true;
		} 
		if(r>0){
			if(isAttack(r-1,c+1,player))
				return true;
		}
	}
	//check center column
	if(r<7){
		if(isAttack(r+1,c,player))
			return true;
	}
	if(r>0){
		if(isAttack(r-1,c,player))
			return true;
	}

	//check left column
	if(c>0){
		if(isAttack(r,c-1,player))
			return true;
		if(r<7){
			if(isAttack(r+1,c-1,player))
				return true;
		}
		if(r>0){
			if(isAttack(r-1,c-1,player))
				return true;
		}
	}

	return false;
}

bool Board::hasAttackIsKnight(int r,int c,string player){
	if(c>0){
		if(r>1 && isAttack(r-2,c-1,player)) return true;
		if(r<6 && isAttack(r+2,c-1,player)) return true;
		if(c>1){
			if(r>0 && isAttack(r-1,c-2,player)) return true;
			if(r<7 && isAttack(r+1,c-2,player)) return true;
		}
	}
	if(c<7){
		if(r>1 && isAttack(r-2,c+1,player)) return true;
		if(r<6 && isAttack(r+2,c+1,player)) return true;
		if(c<6){
			if(r>0 && isAttack(r-1,c+2,player)) return true;
			if(r<7 && isAttack(r+1,c+2,player)) return true;
		}
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

	cout << "black dead soldiers: " ;
	for (int i=0;i<15;i++){
		if(blackDeadSoldier[i] != NULL){
			cout << blackDeadSoldier[i]->getAsciiName() << " " ;
		}
	}
	cout << endl;
	cout << "white dead soldiers: " ;
	for (int i=0;i<15;i++){
		if(whiteDeadSoldier[i] != NULL){
			cout << whiteDeadSoldier[i]->getAsciiName() << " " ;
		}
	}
	cout << endl;
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

//GUI
void Board::status(string arr[][8]){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(soldier[i][j] == NULL)
				arr[i][j] = " ";
			else
				arr[i][j] = soldier[i][j]->getAsciiName();
		}
	}
}