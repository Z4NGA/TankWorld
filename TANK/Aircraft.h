#pragma once
#include "GameObject.h"
#include <string>
#include <vector>
#include <GL/freeglut.h>
extern GLuint metal,alum; 
class Aircraft : public GameObject
{
public :
	float backwingrotationangle, topwingrotationangle;
	Aircraft();
	Aircraft(float x, float y, float z , std::string type);
	void spawn();
	void drawcore(); 
	void drawback();
	void drawwings(); 
	void drawbackwings();
	void drawrockets();
	void drawwheels();//helicopter
	void drawblade(float x, float y, float z);
	void rotatebackwing(float angle);
};

