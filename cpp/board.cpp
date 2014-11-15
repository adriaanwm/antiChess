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
			if(soldier[r][c]->isQueen()){
				if(isStraight(r,c,nr,nc)){
					if(emptyStraightLane(r,c,nr,nc)){
						if(performAttack(r,c,nr,nc)) return true;
						return false;
					}
					return false;
				}
				if(isDiagonal(r,c,nr,nc)){
					if(emptyDiagonalLane(r,c,nr,nc)){
						if(performAttack(r,c,nr,nc)) return true;
						return false;
					}
					return false;
				}
			} else if(soldier[r][c]->isRook()){
				if(isStraight(r,c,nr,nc)){
					if(emptyStraightLane(r, c, nr, nc)){
						if(performAttack(r,c,nr,nc)) return true;
						return false;
					}
				}
				return false;
			} else if(soldier[r][c]->isBishop()){
				if(isDiagonal(r,c,nr,nc)){
					if(emptyDiagonalLane(r,c,nr,nc)){
						if(performAttack(r,c,nr,nc)) return true;
						return false;
					}
					return false;
				}
				return false;
			} 
			//do the attack
			if(performAttack(r,c,nr,nc)) return true;
			return false;
		}
	}
	//if it is just a move
	else{
		if(hasAvailableAttack(cp)) return false;
		else{
			//check if it's a valid move
			if(soldier[nr][nc] == NULL && soldier[r][c]->isValidMove(r,c,nr,nc)){
				//do the move
				if(soldier[r][c]->isQueen()){
					if(isStraight(r,c,nr,nc)){
						if(emptyStraightLane(r,c,nr,nc)){
							if(performMove(r,c,nr,nc)) return true;
							return false;
						}
						return false;
					}
					if(isDiagonal(r,c,nr,nc)){
						if(emptyDiagonalLane(r,c,nr,nc)){
							if(performMove(r,c,nr,nc)) return true;
							return false;
						}
						return false;
					}
				}else if(soldier[r][c]->isRook()){
					if(isStraight(r,c,nr,nc)){
						if(emptyStraightLane(r, c, nr, nc)){
							if(performMove(r,c,nr,nc)) return true;
							return false;
						}
					}
					return false;
				}else if(soldier[r][c]->isBishop()){
					if(isDiagonal(r,c,nr,nc)){
						if(emptyDiagonalLane(r,c,nr,nc)){
							if(performMove(r,c,nr,nc)) return true;
							return false;
						}
						return false;
					}
					return false;
				}
				if(performMove(r,c,nr,nc)) return true;
				return false;
			}
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
						if(hasAttackIsKing(i,j,player)){
							cout << soldier[i][j]->getAsciiName() << " has an attack" << endl;
							return true;
						}
					}else if(soldier[i][j]->isKnight()){
						if(hasAttackIsKnight(i,j,player)){
							cout << soldier[i][j]->getAsciiName() << " has an attack"<< endl;
							return true;
						}
					}else if(soldier[i][j]->isPawn()){
						if(hasAttackIsPawn(i,j,player)){
							cout << soldier[i][j]->getAsciiName() << " has an attack"<< endl;
							return true;
						}
					}else if(soldier[i][j]->isRook()){
						if(hasAttackStraight(i,j,player)){
							cout << soldier[i][j]->getAsciiName() << " has an attack"<< endl;
							return true;
						}
					}else if(soldier[i][j]->isBishop()){
						if(hasAttackDiagonal(i,j,player)){
							cout << soldier[i][j]->getAsciiName() << " has an attack"<< endl;
							return true;
						}
					}else if(soldier[i][j]->isQueen()){
						if(hasAttackStraight(i,j,player)){
							cout << soldier[i][j]->getAsciiName() << " has an attack"<< endl;
							return true;
						}
						if(hasAttackDiagonal(i,j,player)){
							cout << soldier[i][j]->getAsciiName() << " has an attack"<< endl;
							return true;
						}
					}
				}
			}
		}
	}
	//hasAttackStraight?
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

bool Board::hasAttackIsPawn(int r,int c,string player){
	if(player == "w"){
		if(r<7){
			if(c<7 && isAttack(r+1,c+1,player)) return true;
			if(c>0 && isAttack(r+1,c-1,player)) return true;
		}
	}else{
		if(r>0){
			if(c<7 && isAttack(r-1,c+1,player)) return true;
			if(c>0 && isAttack(r-1,c-1,player)) return true;
		}
	}
	return false;
}

bool Board::hasAttackStraight(int r,int c, string player){
	int temp;
	//check right
	if(r<7){
		temp = r+1;
		while(temp != 8 && soldier[temp][c] == NULL) temp++;
		if(isAttack(temp,c,player)) return true;
	}
	//check left
	if(r>0){
		temp = r-1;
		while(temp >=0 && soldier[temp][c] == NULL) temp--;
		if(isAttack(temp,c,player)) return true;
	}
	if(c<7){
		temp = c+1;
		while(temp != 8 && soldier[r][temp] == NULL) temp++;
		if(isAttack(r,temp,player)) return true;
	}
	if(c>0){
		temp = c-1;
		while(temp >= 0 && soldier[r][temp] == NULL) temp--;
		if(isAttack(r,temp,player)) return true;
	}
	return false;
}

bool Board::hasAttackDiagonal(int r,int c,string player){
	int t1, t2;

	//top
	if(r<7){
		//topright
		if(c<7){
			t1 = r+1; t2 = c+1;
			while(t1 != 8 && t2 != 8 && soldier[t1][t2] == NULL){
				t1++; t2++;
			}
			if(t1 != 8 && t2 != 8){
				if(isAttack(t1,t2,player)) return true;
			}
		}
		//topleft
		if(c>0){
			t1 = r+1; t2 = c-1;
			while(t1 != 8 && t2 >= 0 && soldier[t1][t2] == NULL){
				t1++; t2--;
			}
			if(t1 != 8 && t2 >= 0){
				if(isAttack(t1,t2,player)) return true;
			}
		}
	}
	//bottom
	if(r>0){
		//bottomright
		if(c<7){
			t1 = r-1; t2 = c+1;
			while(t1 >= 0 && t2 != 8 && soldier[t1][t2] == NULL){
				t1--; t2++;
			}
			if(t1 >= 0 && t2 != 8){
				if(isAttack(t1,t2,player)) return true;
			}
		}
		//bottomleft
		if(c>0){
			t1 = r-1; t2 = c-1;
			while(t1 >=0 && t2 >= 0 && soldier[t1][t2] == NULL){
				t1--; t2--;
			}
			if(t1 >=0 && t2 >= 0){
				if(isAttack(t1,t2,player)) return true;
			}
		}
	}

	return false;
}

bool Board::emptyStraightLane(int r, int c, int nr, int nc){
	int t;
	if(r == nr){
		if(c>nc){
			t = c-1;
			while(soldier[t][c] == NULL){
				if(t == nc+1) return true;
				t--;
			}
			return false;
		}
		if(nc>c){
			t = c+1;
			while(soldier[t][c] == NULL){
				if(t == nc-1) return true;
				t++;
			}
			return false;
		}
	}
	if(c == nc){
		if(r>nr){
			t = r-1;
			while(soldier[t][c] == NULL){
				cout << "t " << t << endl;
				cout << "r " << nr << endl;
				if(t == nr+1) return true;
				t--;
			}
			return false;
		}
		if(nr>r){
			t = r+1;
			while(soldier[t][c] == NULL){
				if(t == nr-1) return true;
				t++;
			}
			return false;
		}
	}
	return false;
}
bool Board::emptyDiagonalLane(int r, int c, int nr, int nc){
	int t1, t2;

	//top
	if(r<nr){
		//topright
		if(c<nc){
			t1 = r+1; t2 = c+1;
			while(soldier[t1][t2] == NULL){
				if(t1 == nr-1) return true;
				t1++; t2++;
			}
			return false;
		}
		//topleft
		if(c>nc){
			t1 = r+1; t2 = c-1;
			while(soldier[t1][t2] == NULL){
				if(t1 == nr-1) return true;
				t1++; t2--;
			}
			return false;
		}
	}
	//bottom
	if(r>nr){
		//bottomright
		if(c<nc){
			t1 = r-1; t2 = c+1;
			while(soldier[t1][t2] == NULL){
				if(t1==nr+1) return true;
				t1--; t2++;
			}
			return false;
		}
		//bottomleft
		if(c>nc){
			t1 = r-1; t2 = c-1;
			while(soldier[t1][t2] == NULL){
				if(t1==nr+1) return true;
				t1--; t2--;
			}
			return false;
		}
	}	
	return false;
}


bool Board::isStraight(int r, int c, int nr, int nc){
	if(c == nc && r!= nr) return true;
	if(c != nc && r == nr) return true;
	return false;
}
bool Board::isDiagonal(int r, int c, int nr, int nc){
	if(abs(nr-r)==abs(nc-c) && nr-r != 0) return true;
	return false;
}


//ascii
void Board::display(){

	for (int i=7;i>=0;i--){
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
			square[i][j] = BlackSquare + BlackSquare;
			square[i][j+1] = WhiteSquare + WhiteSquare;
		}
	}
	for(int i=1;i<8;i+=2){
		for(int j=0;j<8;j+=2){
			square[i][j] = WhiteSquare + WhiteSquare;
			square[i][j+1] = BlackSquare + BlackSquare;
		}
	}
	for(int i=0;i<8;i++){
		soldier[1][i] = new Pawn("w");
		soldier[6][i] = new Pawn("b");
	}
	soldier[0][0] = new Rook("w");
	soldier[0][7] = new Rook("w");
	soldier[0][1] = new Knight("w");
	soldier[0][6] = new Knight("w");
	soldier[0][2] = new Bishop("w");
	soldier[0][5] = new Bishop("w");
	soldier[0][3] = new Queen("w");
	soldier[0][4] = new King("w");

	soldier[7][0] = new Rook("b");
	soldier[7][7] = new Rook("b");
	soldier[7][1] = new Knight("b");
	soldier[7][6] = new Knight("b");
	soldier[7][2] = new Bishop("b");
	soldier[7][5] = new Bishop("b");
	soldier[7][3] = new Queen("b");
	soldier[7][4] = new King("b");
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
