#ifndef PLAYERUNIT_H
#define PLAYERUNIT_H

class PlayerUnit
{
private:
	//--If an Image is in use it can not be called--//
	bool InUse;
	GtkWidget* Image;

public:
	PlayerUnit(std::string File2Load);
	~PlayerUnit();
	GtkWidget* GetImage(int &Error);

};

#endif