#pragma once
#include <GL/SOIL.h>
#include <GL/freeglut.h>
#include "tank.h"
#include "box.h"
#include <string>
extern GLuint sky, ground, boxtx, redboxtx, wall;
class base_scene
{
public :
	std::string name; 
	base_scene(std::string n="scene");
	void draw(); 
	void drawsky(); 
	void drawground();
	void drawwalls();
};


