#include "../headers/soldier.h"

Soldier::Soldier(string player, string name){
	color = player;
	asciiName = color + name;
}

string Soldier::getColor(){
	return color;
}

bool Soldier::isValidAttack(int r, int c, int nr, int nc){
	return true;
}

bool Soldier::isValidMove(int r, int c, int nr, int nc){
	return true;
}

string Soldier::getAsciiName(){
	return asciiName;
}

bool Soldier::isKing(){return false;}
bool Soldier::isQueen(){return false;}
bool Soldier::isPawn(){return false;}
bool Soldier::isBishop(){return true;}
bool Soldier::isRook(){return false;}
bool Soldier::isKnight(){return false;}


//PAWN
Pawn::Pawn(string player): Soldier(player, "p"){}

bool Pawn::isKing(){return false;}
bool Pawn::isQueen(){return false;}
bool Pawn::isPawn(){return true;}
bool Pawn::isBishop(){return false;}
bool Pawn::isRook(){return false;}
bool Pawn::isKnight(){return false;}

bool Pawn::isValidAttack(int r, int c, int nr, int nc){
	if(color == "w"){
		if((nr<8 && nr == r+1) && ((nc<8 && nc == c+1) | (nc>=0 && nc == c-1))) return true;
	}else{
		if((nr>=0 && nr == r-1) && ((nc<8 && nc == c+1) | (nc>=0 && nc == c-1))) return true;
	}
	return false;
}

bool Pawn::isValidMove(int r, int c, int nr, int nc){
	if(color == "w"){
		if(nr < 8 && nr == r+1) return true;
		if(r == 1 && nr == r+2) return true;
		return false;
	}else{
		if(nr >= 0 && nr == r-1) return true;
		if(r ==6 && nr == r-2) return true;
		return false;
	}
	return false;
}

//Rook
Rook::Rook(string player): Soldier(player, "r"){}

bool Rook::isKing(){return false;}
bool Rook::isQueen(){return false;}
bool Rook::isPawn(){return false;}
bool Rook::isBishop(){return false;}
bool Rook::isRook(){return true;}
bool Rook::isKnight(){return false;}

bool Rook::isValidAttack(int r, int c, int nr, int nc){
	if(r==nr && c==nc) return false;
	if(r<0 | r>7 | c <0 | c > 7 | nr<0 | nr>7 | nc<0 | nc>7) return false;
	if(c == nc){
		if(nr<8 && nr>=0) return true;
	}
	if(r == nr){
		if(nc<8 && nc>=0) return true;
	}
	return false;
}

bool Rook::isValidMove(int r, int c, int nr, int nc){
	if(isValidAttack(r,c,nr,nc)) return true;
	return false;
}


//Knight
Knight::Knight(string player): Soldier(player, "n"){}

bool Knight::isKing(){return false;}
bool Knight::isQueen(){return false;}
bool Knight::isPawn(){return false;}
bool Knight::isBishop(){return false;}
bool Knight::isRook(){return false;}
bool Knight::isKnight(){return true;}

bool Knight::isValidAttack(int r, int c, int nr, int nc){
	if(nr>0 && nc>1 && nr == r-1 && nc == c-2) return true;
	if(nr>1 && nc>0 && nr == r-2 && nc == c-1) return true;
	if(nr>0 && nc<6 && nr == r-1 && nc == c+2) return true;
	if(nr>1 && nc<7 && nr == r-2 && nc == c+1) return true;
	if(nr<6 && nc>0 && nr == r+2 && nc == c-1) return true;
	if(nr<7 && nc>1 && nr == r+1 && nc == c-2) return true;
	if(nr<6 && nc>0 && nr == r+2 && nc == c-1) return true;
	if(nr<7 && nc<6 && nr == r+1 && nc == c+2) return true;
	if(nr<6 && nc<7 && nr == r+2 && nc == c+1) return true;
	return false;
}

bool Knight::isValidMove(int r, int c, int nr, int nc){
	if(isValidAttack(r,c,nr,nc)) return true;
	return false;
}

//Bishop
Bishop::Bishop(string player): Soldier(player, "b"){}

bool Bishop::isKing(){return false;}
bool Bishop::isQueen(){return false;}
bool Bishop::isPawn(){return false;}
bool Bishop::isBishop(){return true;}
bool Bishop::isRook(){return false;}
bool Bishop::isKnight(){return false;}

bool Bishop::isValidAttack(int r, int c, int nr, int nc){
	if(r<0 | r>7 | c <0 | c > 7 | nr<0 | nr>7 | nc<0 | nc>7) return false;
	if(abs(nc-c) == abs(nr-r) && nc != c && nr != r) return true;
	return false;
}

bool Bishop::isValidMove(int r, int c, int nr, int nc){
	if(isValidAttack(r,c,nr,nc)) return true;
	return false;
}


//Queen
Queen::Queen(string player): Soldier(player, "q"){}

bool Queen::isKing(){return false;}
bool Queen::isQueen(){return true;}
bool Queen::isPawn(){return false;}
bool Queen::isBishop(){return false;}
bool Queen::isRook(){return false;}
bool Queen::isKnight(){return false;}

bool Queen::isValidAttack(int r, int c, int nr, int nc){
	if(r<0 | r>7 | c <0 | c > 7 | nr<0 | nr>7 | nc<0 | nc>7) return false;
	if(r==nr && c==nc) return false;
	//straight
	if(abs(nc-c) == abs(nr-r) && nc != c && nr != r) return true;

	//diagonal
	if(c == nc){
		if(nr<8 && nr>=0) return true;
	}
	if(r == nr){
		if(nc<8 && nc>=0) return true;
	}
	return false;
}

bool Queen::isValidMove(int r, int c, int nr, int nc){
	if(isValidAttack(r,c,nr,nc)) return true;
	return false;
}

//King
King::King(string player): Soldier(player, "k"){}

bool King::isKing(){return true;}
bool King::isQueen(){return false;}
bool King::isPawn(){return false;}
bool King::isBishop(){return false;}
bool King::isRook(){return false;}
bool King::isKnight(){return false;}

bool King::isValidAttack(int r, int c, int nr, int nc){
	if(r==nr && c==nc) return false;

	if(c-nc == 1){
		if(c>0){
			if(r == nr) return true;
			if(r>0){
				if(r-nr == 1) return true;
			}
			if(r<7){
				if(nr-r == 1) return true;
			}
		}
		return false;
	}

	if(nc-c == 1){
		if(c<7){
			if(r==nr) return true;
			if(r>0){
				if(r-nr == 1) return true;
			}
			if(r<7){
				if(nr-r == 1) return true;
			}
		}
		return false;
	}

	if(nc == c){
		if(r>0){
			if(r-nr == 1) return true;
		}
		if(r<7){
			if(nr-r == 1) return true;
		}
		return false;
	}
	return false;

}

bool King::isValidMove(int r, int c, int nr, int nc){
	if(isValidAttack(r,c,nr,nc)) return true;
	return false;
}





