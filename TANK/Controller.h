#pragma once
#include <GL/freeglut.h>
#include <GL/SOIL.h>
#include <iostream>
#include <math.h>
#define M_PI acos(-1.)
class Controller
{
public:
	float CamXpos , camYpos , camZpos ; //defines where the cam stands
	float centerx , centery , centerz ; //defines where the cam looks
	Controller();
	void noclick_motion(int x, int y);
	void arrowfunc(int key, int x, int y);
	void keyboardfunc(unsigned char key, int x, int y);
	void resetlook();
	void setcampos(float x, float y, float z);
};

