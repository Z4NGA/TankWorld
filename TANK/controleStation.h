#pragma once
#include "GameObject.h"
#include <GL/freeglut.h>
class controleStation : public GameObject
{
public :
	controleStation(); 
	controleStation(float x, float y, float z);
	void spawn();
	void drawbox(); 
	void drawminigate();
	void drawlargegate();
};

