//scan attack

//is it an attack?
//if it is, is the piece the opponent?
//can the piece do this move or attack?


//Check if a piece has any available attacks
bool hasAttack(int r, int c){
   if(isPawn(int r, int c)){
      return(canPawnAttack(int r, int c));
   }
   else if(isRook(int r, int c)){
      return(canRookAttack(int r, int c));
   }
   else if(isKing(int r, int c)){
      return(canKingAttack(int r, int c));
   }
   else if(canAttackDiagonal(int r, int c)){
      return(hasDiagonalAttack(int r, int c));
   }
   else if(canAttackStraight(int r, int c)){
      return(hasHorizontalAttack(int r, int c));
   }
   return false;
}

//can pawn attack anywhere
bool canPawnAttack(int r, int c){
   if(getPlayer(r,c) == 'W'){
      if(areOpponents(r,c,r+1,c-1)) return true;
      if(areOpponents(r,c,r+1,c+1)) return true;
   }else{
      if(areOpponents(r,c,r-1,c-1)) return true;
      if(areOpponents(r,c,r-1,c+1)) return true;
   }
   return false
}

//can king attack anywhere
bool canKingAttack(int r, int c){
      if(areOpponents(r,c,r+1,c-1)) return true;
      if(areOpponents(r,c,r+1,c)) return true;
      if(areOpponents(r,c,r+1,c+1)) return true;
      if(areOpponents(r,c,r,c-1)) return true;
      if(areOpponents(r,c,r,c)) return true;
      if(areOpponents(r,c,r-1,c-1)) return true;
      if(areOpponents(r,c,r-1,c)) return true;
      if(areOpponents(r,c,r-1,c+1)) return true;
}

//
