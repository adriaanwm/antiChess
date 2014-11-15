#include <string>

#include "scores.h"

scoreObject::scoreObject() 
{
   p1Score = 0;
   p2Score = 0;
}

int scoreObject::GetP1Score()
{
   return p1Score;
}

int scoreObject::GetP2Score()
{
   return p2Score;
}

std::string scoreObject::GetP1Name()
{
   return p1Name;
}

std::string scoreObject::GetP2Name()
{
   return p2Name;
}

void scoreObject::SetP1Score(int Passed)
{
   p1Score = Passed;
}

void scoreObject::SetP2Score(int Passed)
{
   p2Score = Passed;
}

void scoreObject::SetP1Name(std::string Passed)
{
   p1Name = Passed + ": ";
}

void scoreObject::SetP2Name(std::string Passed)
{
   p2Name = Passed + ": ";
}