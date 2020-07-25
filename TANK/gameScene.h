#pragma once
#include<vector>
#include <string>
#include <GL/freeglut.h>
#include "GameObject.h"
#include "Scene.h"
extern GLuint ground1, sky1, wall1;
extern GLuint ground2, sky2, wall2;
extern GLuint ground3, sky3, wall3;
extern GLuint useobject;
class gameScene :public Scene
{
public: 
	float x, y, z; //configs the world size , wil be useful in future extensions
	gameScene();
	gameScene(std::string n = "level", std::string t = "game_scene");
	void display();
	void drawsky();
	void drawground();
	void drawwalls();
	void displayinrangeui();
};

