#pragma once
#include <GL/SOIL.h>
#include <GL/freeglut.h>
#include "tank.h"
#include "box.h"
#include <string>
extern GLuint sky1, ground1, boxtx, redboxtx, wall1;
class base_scene
{
public :
	std::string name; 
	base_scene(std::string n="scene");
	void display(); 
	void drawsky(); 
	void drawground();
	void drawwalls();
};


