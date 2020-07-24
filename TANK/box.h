#pragma once
#include "GL/freeglut.h"
#include "GameObject.h"
#include <vector>
extern GLuint boxtx, redboxtx;
class box  :public GameObject {
public:
	/*float xLen, yLen, zLen;
	float xoffset, yoffset, zoffset;*/
	bool iscolliding; 
	box(float x, float y ,float z);
	void spawn();// pure virtual ft should be overloaded for each member
	void drawbox();
	void movex(float offset);//only horizantally for now
	void movey(float offset);//only horizantally for now
	void movez(float offset);//only horizantally for now
	void setposition(float x , float y, float z);
	std::vector<float> getborder();
};

