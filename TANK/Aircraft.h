#pragma once
#include "GameObject.h"
#include <string>
#include <vector>
#include <GL/freeglut.h>
class Aircraft : public GameObject
{
public :
	Aircraft();
	Aircraft(float x, float y, float z , std::string type);
	void spawn();
	void drawcore(); 
	void drawwings(); 
	void drawbackwings();
	void drawrockets();
	void drawwheels();//helicopter
};

