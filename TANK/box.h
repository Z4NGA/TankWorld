#pragma once
#include "GL/freeglut.h"
#include <vector>
extern GLuint boxtx, redboxtx;
class box
{
public:
	float xLen, yLen, zLen;
	float xoffset, yoffset, zoffset;
	bool iscolliding; 
	box(float x, float y ,float z);
	void spawn();
	void drawbox();//just to clean the code
	void movex(float offset);//only horizantally for now
	void movey(float offset);//only horizantally for now
	void movez(float offset);//only horizantally for now
	void setposition(float x , float y, float z);
	std::vector<float> getborder();
};

