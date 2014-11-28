#ifndef IMAGEFILES_H
#define IMAGEFILES_H

#include "../headers/PlayerUnit.h"
#include "../headers/filenames.h"

class ImageFiles
{

private:
	PlayerUnit* BK;
	PlayerUnit* BQ;
	PlayerUnit* BN[NumKngt];
	PlayerUnit* BB[NumBish];
	PlayerUnit* BR[NumRook];
	PlayerUnit* BP[NumPawn];

	PlayerUnit* WK;
	PlayerUnit* WQ;
	PlayerUnit* WN[NumKngt];
	PlayerUnit* WB[NumBish];
	PlayerUnit* WR[NumRook];
	PlayerUnit* WP[NumPawn];

	bool LoadFiles();
	bool NullCheck(PlayerUnit* ToCheck);

public:
	ImageFiles();
	~ImageFiles();
	bool GetUnitImg(std::string ToGet);

};

#endif