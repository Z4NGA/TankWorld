#pragma once
#include "GameObject.h"
#include <vector>
#include <GL/freeglut.h>
extern GLuint green, blue;
//to be upgraded to display diffrent models of tents
class Tent : public GameObject
{
public:
	Tent();
	Tent(float x, float y, float z);
	//std::vector<float> getborder();
	void spawn();
	void drawbot(); 
	void drawtop();
	void drawropes();
};

