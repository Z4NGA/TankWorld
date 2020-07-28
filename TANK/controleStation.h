#pragma once
#include "GameObject.h"
#include <GL/freeglut.h>
#include "cube.h"
extern GLuint gate_frontback, gate_leftright, gate_top, gate_bot,gatewall, gatebar_texture;
class controleStation : public GameObject
{
public :
	controleStation(); 
	controleStation(float x, float y, float z);
	void spawn();
	void drawbox(); 
	void drawminigate();
	void drawlargegate();
	//to be  implemented 
	//bool isopening , isclosing ;
	//void opengate(float offset);
	//void closegate(float offset);
	// float offset
};

