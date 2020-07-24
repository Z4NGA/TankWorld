#pragma once
#include <GL/freeglut.h>
#include <GL/SOIL.h>
#include <iostream>
#include <math.h>
#include "GameObject.h"
#define Height 600
#define Width 800
class GameEngine;
#define M_PI acos(-1.)
class Controller
{
public:
	float CamXpos , camYpos , camZpos ; //defines where the cam stands
	float centerx , centery , centerz ; //defines where the cam looks
	GameEngine* engineincontrol; 
	GameObject* controlled_object; 

	Controller(GameEngine* p);
	void noclick_motion(int x, int y);
	void arrowfunc(int key, int x, int y);
	void keyboardfunc(unsigned char key, int x, int y);
	void resetlook();
	void setmenulook(); 
	void setcampos(float x, float y, float z);
};

