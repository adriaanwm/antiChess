#include <gtk/gtk.h>
#include <string>
#include <iostream>
#include <cstdlib>

#include "../headers/ImageFiles.h"
#include "../headers/PlayerUnit.h"
#include "../headers/GUIConst.h"
#include "../headers/filenames.h"


using namespace std;


//--Constructor--//
ImageFiles::ImageFiles() 
{
	BK = new PlayerUnit(BLK_KING.c_str());
	NullCheck(BK);

	BQ = new PlayerUnit(BLK_QUEN.c_str());
	NullCheck(BQ);

	for (int i = 0; i < NumPawn; i++) {
		BP[i] = new PlayerUnit(BLK_PAWN);
		NullCheck(BP[i]);
	}
	for (int i = 0; i < NumKngt; i++) {
		BN[i] = new PlayerUnit(BLK_KNGT);
		NullCheck(BN[i]);
	}
	for (int i = 0; i < NumBish; i++) {
		BB[i] = new PlayerUnit(BLK_BISH);
		NullCheck(BB[i]);
	}
	for (int i = 0; i < NumRook; i++) {
		BR[i] = new PlayerUnit(BLK_ROOK);
		NullCheck(BR[i]);
	}

	WK = new PlayerUnit(WHT_KING.c_str());
		NullCheck(WK);

	WQ = new PlayerUnit(WHT_QUEN.c_str());
		NullCheck(WQ);

	for (int i = 0; i < NumPawn; i++) {
		WP[i] = new PlayerUnit(WHT_PAWN);
		NullCheck(WP[i]);
	}
	for (int i = 0; i < NumKngt; i++) {
		WN[i] = new PlayerUnit(WHT_KNGT);
		NullCheck(WN[i]);
	}
	for (int i = 0; i < NumBish; i++) {
		WB[i] = new PlayerUnit(WHT_BISH);
		NullCheck(WB[i]);
	}
	for (int i = 0; i < NumRook; i++) {
		WR[i] = new PlayerUnit(WHT_ROOK);
		NullCheck(WR[i]);
	}
}


//--Destructor--//
ImageFiles::~ImageFiles() 
{
	NullCheck(BK); delete BK; 
	NullCheck(BQ); delete BQ;
	for (int i = 0; i < NumPawn; i++) {NullCheck(BP[i]); delete BP[i];}
	for (int i = 0; i < NumKngt; i++) {NullCheck(BN[i]); delete BN[i];}
	for (int i = 0; i < NumBish; i++) {NullCheck(BB[i]); delete BB[i];}
	for (int i = 0; i < NumRook; i++) {NullCheck(BR[i]); delete BR[i];}

	NullCheck(WK); delete WK; 
	NullCheck(WQ); delete WQ;
	for (int i = 0; i < NumPawn; i++) {NullCheck(WP[i]); delete WP[i];}
	for (int i = 0; i < NumKngt; i++) {NullCheck(WN[i]); delete WN[i];}
	for (int i = 0; i < NumBish; i++) {NullCheck(WB[i]); delete WB[i];}
	for (int i = 0; i < NumRook; i++) {NullCheck(WR[i]); delete WR[i];}

	cout << "Deleting ImageFiles" << endl; 
}

bool ImageFiles::GetUnitImg(std::string ToGet)
{
	//switch (ToGet)
	return true;
}

bool ImageFiles::NullCheck(PlayerUnit* ToCheck) 
{
	if (ToCheck == NULL) {
		cerr << "Memory Error" << endl;
		exit(1);
	}
}