#pragma once
#include "GameObject.h"
#include <string>
#include <vector>
#include <GL/freeglut.h>
extern GLuint metal,alum, blackalum , orangealum;
class Aircraft : public GameObject
{
public :
	float backwingrotationangle, topwingrotationangle;
	std::string color; 
	Aircraft();
	Aircraft(float x, float y, float z , std::string type , std::string c="metal");
	void spawn();
	void drawcore(); 
	void drawback();
	void drawwings(); 
	void drawbackwings();
	void drawrockets();
	void drawwheels();//helicopter
	void drawblade(float x, float y, float z);
	void rotatebackwing(float angle);
	void rotatetopwing(float angle);
	void drawrotator(float tempx, float tempy, float tempz);
};

