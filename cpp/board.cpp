#include "../headers/board.h"
#include <complex>

Board::Board(){

	WhiteSquare = 'w';
	BlackSquare = 'b';
	numPlayerOneDead = 0;
	numPlayerTwoDead = 0;

	for(int i=0;i<8;i+=2){
		for(int j=0;j<8;j+=2){
			squares[i][j] = WhiteSquare;
			squares[i][j+1] = BlackSquare;
		}
	}
	for(int i=1;i<8;i+=2){
		for(int j=0;j<8;j+=2){
			squares[i][j] = BlackSquare;
			squares[i][j+1] = WhiteSquare;
		}
	}

	setupBoard();

}

void Board::printBoard(){
	cout << "  0 1 2 3 4 5 6 7"<<endl;

	for (int i=0;i<8;i++){
		cout << i << " ";
		for(int j=0;j<8;j++){
			if (soldiers[i][j]) cout << soldiers[i][j]->getSquareName() << " ";
			else if ((j-i+1)%2 == 1 || (i-j+1)%2 == 1) cout << "w ";
			else cout << "b ";
		}
		cout << endl;
	}
	return;
}

Pawn *Board::getSoldier(int r, int c){
	return soldiers[r][c];
}

void Board::updateSquares(){
	for(int i=0;i<8;i+=2){
		for(int j=0;j<8;j+=2){
			squares[i][j] = WhiteSquare;
			squares[i][j+1] = BlackSquare;
		}
	}
	for(int i=1;i<8;i+=2){
		for(int j=0;j<8;j+=2){
			squares[i][j] = BlackSquare;
			squares[i][j+1] = WhiteSquare;
		}
	}

	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(soldiers[i][j]!=NULL){
				squares[i][j] = soldiers[i][j]->getSquareName();
			}
		}
	}
}


void Board::updateSoldiers(int r, int c, int nr, int nc){
	soldiers[nr][nc] = soldiers[r][c];
	soldiers[r][c] = NULL;
}

void Board::setupBoard(){
	for(int i=0;i<8;i++){
		soldiers[1][i] = new Pawn('1', 1);
		soldiers[6][i] = new Pawn('2', 2);
	}

}

bool Board::move(int r, int c, int nr, int nc){
	Pawn *temp = soldiers[r][c];
	//can this piece move like that?

	if(temp->isValidMoveDirection(r,c,nr,nc)){
		updateSoldiers(r,c,nr,nc);
		return true;
	}
	return false;
}

bool Board::occupied(int r, int c){
	if(soldiers[r][c]!= NULL){
		return true;
	} return false;
}

bool Board::attack(int r, int c, int nr, int nc){
	Pawn *temp = soldiers[r][c];

	if(temp->isValidAttackDirection(r,c,nr,nc)){
		soldierCleanup(nr,nc);
		updateSoldiers(r,c,nr,nc);
		return true;
	}
	return false;
}

bool Board::soldierCleanup(int r, int c){
	int i = 0;
	if(soldiers[r][c]->isPlayerOne()){
		playerOne[numPlayerOneDead] = soldiers[r][c];
		soldiers[r][c] = NULL;
		numPlayerOneDead ++;
		return true;
	}
	if(soldiers[r][c]->isPlayerTwo()){
		playerTwo[numPlayerTwoDead] = soldiers[r][c];
		soldiers[r][c] = NULL;
		numPlayerTwoDead ++;
		return true;
	}
	return false;
}

bool Board::handleMoveRequest(int r, int c, int nr, int nc){
	bool diagonal= false;
	bool horizontal = false;
	bool vertical = false;
	bool lShaped=false;

	if(isAttack(nr,nc)){
		if(!canAttack(r,c,nr,nc)){
			cout << "*** invalid move ***" << endl;
			return false;
		}
		else{
			attack(r,c,nr,nc);
			return true;
		}
	}
	else{
		if(canMove(r, c, nr, nc)){
			move(r,c,nr,nc);
			return true;
		}else{
			return false;
		}
	}

	return true;//handle move!
}

//check if move is diagonal, horizontal, vertical, or L/7
bool Board::isDiagonal(int r, int c, int nr, int nc){
	if(r==nr || c ==nc) return false;
	else if(abs(nr-r) == abs(nc-c)) return true;
	return false;
}

bool Board::isVertical(int r, int c, int nr, int nc){
	if(r!=nr && c==nc) return true;
	return false;
}

bool Board::isHorizontal(int r, int c, int nr, int nc){
	if(r==nr && c!=nc) return true;
	return false;
}

bool Board::isL(int r, int c, int nr, int nc){
	if((abs(nr-r)==1 && abs(nc-c)==2)||(abs(nc-c)==1 && abs(nr-r)==2)) return true;
	return false;
}



//check if diagonal PATH TO nr, nc is vacant. nr, nc can be occupied
bool Board::emptyDiagonal(int r, int c, int nr, int nc){
	for(int i=1;i<abs(nr-r);i++){

		//moving towards bottom right
		if(nr>r && nc>c){
			if(soldiers[r+i][c+i]!=NULL)return false;
		}

		//moving towards bottom left
		else if(nr>r && nc<c){
			if(soldiers[r+i][c-i]!=NULL)return false;
		}

		//moving towards top left
		else if(nr<r && nc<c){
			if(soldiers[r-i][c-i]!=NULL)return false;
		}

		//moving towards top left
		else if(nr<r && nc>c){
			if(soldiers[r-i][c+i]!=NULL)return false;
		}
	}
	return true;
}

bool Board::emptyVertical(int r, int c, int nr){
	for(int i=1;i<abs(nr-r);i++){
		//moving down
		if(nr>r){
			if(soldiers[r+i][c]!=NULL){
				return false;
			}
		}
		//moving up
		else if(nr<r){
			if(soldiers[r-i][c]!=NULL)return false;
		}
	}
	return true;
}

bool Board::emptyHorizontal(int r, int c, int nc){
	for(int i=1;i<abs(nc-c);i++){
		//moving right
		if(nc>c){
			if(soldiers[r][c+i]!=NULL)return false;
		}
		//moving up
		else if(nc<c){
			if(soldiers[r][c-i]!=NULL)return false;
		}
	}
	return true;
}

bool Board::canAttack(int r, int c, int nr, int nc){
	//if same player on both squares return false
	if(soldiers[r][c]->getPlayer()==soldiers[nr][nc]->getPlayer()) return false;
	
	if(!(soldiers[r][c]->isValidAttackDirection(r,c,nr,nc))) return false;
	//check for type of attack with the piece and if the path is empty
	if(isDiagonal(r,c,nr,nc)){
		if(!emptyDiagonal(r,c,nr,nc)) return false;
		return true;
	}

	if(isHorizontal(r,c,nr,nc)){
		if(!emptyHorizontal(r,c,nc)) return false;
		return true;
	}

	if(isVertical(r,c,nr,nc)){
		if(!emptyVertical(r,c,nr)) return false;
		return true;
	}

	if(isL(r,c,nr,nc)){
		return true;
	}

	return false;

}

bool Board::isAttack(int nr, int nc){
	if(soldiers[nr][nc]==NULL)return false;
	return true;
}


bool Board::canMove(int r, int c, int nr, int nc){

	if(!(soldiers[r][c]->isValidMoveDirection(r,c,nr,nc))) return false;
	if(isDiagonal(r,c,nr,nc)){
		if(!emptyDiagonal(r,c,nr,nc)) return false;
		return true;
	}

	if(isHorizontal(r,c,nr,nc)){
		if(!emptyHorizontal(r,c,nc)) return false;
		return true;
	}

	if(isVertical(r,c,nr,nc)){
		if(!emptyVertical(r,c,nr)){
			cout << "not empty" << endl;
			return false;
		} 
		return true;
	}

	if(isL(r,c,nr,nc)){
		return true;
	}

	return false;
}


bool Board::scanAttack(int r, int c){
	// int a[2];
	// if(soldiers[r][c]->canAttackDiagonal()){
	// 	if(scanTopRightDiagonal(r,c,a)){
	// 		if(isOpponent(a[0],a[1],r,c)) return true;
	// 	}
	// 	if(scanTopLeftDiagonal(r,c,a)){
	// 		if(isOpponent(a[0],a[1],r,c)) return true;
	// 	}
	// 	if(scanBottomLeftDiagonal(r,c,a)){
	// 		if(isOpponent(a[0],a[1],r,c)) return true;
	// 	}
	// 	if(scanTopRightDiagonal(r,c,a)){
	// 		if(isOpponent(r,c,a[0],a[1])) return true;
	// 	}
	// }
	// if(soldiers[r][c]->canAttackStraight()){

	// }
	return true;
}

bool Board::scanTopRightDiagonal(int r, int c, int a[]){
	int i=0;
	while(r-i>=0 && c+i<8){
		if(soldiers[r-i][c+i]!=NULL){
			a[0]=r-i;
			a[1]=c+i;
			return true;
		}
		i++;
	}
	return false;
}

bool Board::scanTopLeftDiagonal(int r, int c, int a[]){
	int i=0;
	while(r-i>=0 && c-i>=0){
		if(soldiers[r-i][c-i]!=NULL){
			a[0]=r-i;
			a[1]=c-i;
			return true;
		}
		i++;
	}
	return false;
}

bool Board::scanBottomLeftDiagonal(int r, int c, int a[]){
	int i=0;
	while(r+i<8 && c-i>=0){
		if(soldiers[r+i][c-i]!=NULL){
			a[0]=r+i;
			a[1]=c-i;
			return true;
		}
		i++;
	}
	return false;
}

bool Board::scanBottomRightDiagonal(int r, int c, int a[]){
	int i=0;
	while(r+i<8 && c+i<8){
		if(soldiers[r+i][c+i]!=NULL){
			a[0]=r+i;
			a[1]=c+i;
			return true;
		}
		i++;
	}
	return false;
}

bool Board::isOpponent(int r, int c, int nr, int nc){
	if(occupied(r,c) && occupied(nr,nc)){
		if(soldiers[r][c]->getPlayer()==soldiers[nr][nc]->getPlayer())
			return false;
		return true;
	}
	return false;
}



