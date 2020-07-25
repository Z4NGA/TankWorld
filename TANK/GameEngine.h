#pragma once
#include "Controller.h"
#include <string>
#include "GameObject.h"
#include "Scene.h"
#include <vector>
#define MAIN_MENU 0
#define PAUSE 1
#define END 2 
#define BASE_SCENE 0
#define BEACH_SCENE 1 
#define FOREST_SCENE 2 
class GameEngine
{
	
public:
	Scene* current_scene; 
	std::vector<Scene*> game_scenes; 
	std::vector<Scene*> menu_scenes;
	GameObject* controlled_object;
	std::vector<GameObject*> scene_objects; 
	std::string status; 
	Controller* controller; 
	GameEngine();
	void setcontrolledobject(GameObject* obj); 
	bool collisiondetection();//checks collision detection of current object with the world
	bool iscolliding(std::vector<float> border1, std::vector<float> border2);
	void setCurrentScene(Scene* s);
	void addgamescene(Scene* s);
	void addmenuscene(Scene* s);
	void drawCurrentScene();
	void addObjecttocurrentscene(GameObject* obj);
	void changescene(int i); 
	void startgame();
	void onpause(); 
	void endgame();
	void displaycontrols();
	void displaycredits();
	void displayoptions();
	void backtogame();

};

