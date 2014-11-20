#ifndef GUICONST_H
#define GUICONST_H

//===GamePlay Constants===//
const int XChessSquares = 8;
const int YChessSquares = 8;
const int TotalSquares = (XChessSquares * YChessSquares);

const int NumberOfChessUnits = 32;

//====CONSTANTS FOR WINDOW DIMENSIONS & SETTINGS====///

//--Size Of the Window Objects in pixels--//
//--The width and height of the chessboard table--//
const int TableSizeY = 600;
const int TableSizeX = 600;

//--Width and Height of the top and bottom banner--//
const int TopBannerY = 30; 
const int TopBannerX = 600;
const int BottomBannerY = 30;
const int BottomBannerX = 600;

//--Window heights add together, but object widths only add if they're greater than the width of the table--//
const int Win_SizeX = TableSizeX + (TopBannerX - TableSizeX) + (BottomBannerX - TableSizeX);
const int Win_SizeY = TableSizeY + TopBannerY + BottomBannerY;


//--Is the Window Resizeable? False = No, because The gameboard doesn't scale--//
const bool Resizable = false;


//===Window Title, Names, and Spaces===//

//--Used as spacing between scores and other titles--//
const char Spaces20[] = "                    ";

const char Window_Title[] = "Anti-Chess";
const char p1NameConst[] = "Player 1: ";
const char p2NameConst[] = "Player 2: ";


//===Object Positioning Constants===///

//--Number of Vertical Containers, (ChessBoard, TopBanner, BottomBanner)--//
const int CcountX = 1;
const int CcountY = 3;

//--Main Table Span Properties--//
//-Can not overlap, this will cause a segmentation fault--//
const int TopWidgetXStart = 0;
const int TopWidgetXEnd = 1;
const int TopWidgetYStart = 0;
const int TopWidgetYEnd = 1;

const int BoardXStart = 0;
const int BoardXEnd = 1;
const int BoardYStart = 2;
const int BoardYEnd = 3;

const int BottomWidgetXStart = 0;
const int BottomWidgetXEnd = 1;
const int BottomWidgetYStart = 4;
const int BottomWidgetYEnd = 5;


//===Colors===//
const char MEDIUMGREEN[] = "#0099CC"; //--Like in the Food's industry, green is a blue--//
const char DarkSquare[] = "#263026";
const char LightSquare[] = "#d0d0d0";


#endif