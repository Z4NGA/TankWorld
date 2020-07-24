#pragma once
#include "Scene.h"
#include <GL/freeglut.h>
#include <vector>
#include <string>
extern GLuint menubg, play, controls, credits, options, quit;
class menuScene :  public Scene
{
public : 
	menuScene();
	menuScene(std::string n = "menu", std::string t = "menu_scene");
	void display();
	void drawbackground();
	void drawbuttons();
};

