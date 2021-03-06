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
	std::vector<std::string> keys{ "z", "s","up","down","left","right","x","e","space" };
	float CamXpos , camYpos , camZpos ; //defines where the cam stands
	float centerx , centery , centerz ; //defines where the cam looks
	float detectionrange = 1.; // will allow the use of different objects
	GameEngine* engineincontrol; 
	GameObject* controlled_object; 
	int isbound(std::string s);//returns movement code according to string / -1 if key is unbound
	void action(int index); //executes a certain action according to the index given
	int height=600, width=800; 
	void Reshape(int width, int height);
	Controller(GameEngine* p);
	void noclick_motion(int x, int y);
	void onclick_listner(int button, int state, int x, int y);
	void arrowfunc(int key, int x, int y);
	void keyboardfunc(unsigned char key, int x, int y);
	void resetlook();
	void setmenulook(); 
	void selectbasedoncursor();
	void setcampos(float x, float y, float z);
	void resetcenterpos();
	void setcenterpos(float x, float y, float z);
	void displaydetectionrange(); 
	bool isindetectionrange(GameObject* obj);
};

