#ifndef SCORES_H
#define SCORES_H

#include <string>
#include <gtk/gtk.h>

class scoreObject {

private:
   int p1Score;
   int p2Score;
   std::string p1Name;
   std::string p2Name;
public:
   scoreObject();
   ~scoreObject() {};

   GtkWidget* ScoreBar;

   int GetP1Score();
   int GetP2Score();
   std::string GetP1Name();
   std::string GetP2Name();

   void SetP1Score(int Passed);
   void SetP2Score(int Passed);
   void SetP1Name(std::string Passed);
   void SetP2Name(std::string Passed);

};



#endif