#pragma once
#include "Controller.h"
#include <string>
#include "GameObject.h"
#include "Scene.h"
#include <vector>
#define MAIN_MENU 0
#define PAUSE 1
#define CONTROLS 2
#define END 3 
#define OPTIONS 4
#define VIDEO 5 //to be implemented
#define KEYBINDING 6 //to be implemented
#define AUDIO 7 //to be implemented
#define LEVEL_SELECTOR 8 //implemented
#define BASE_SCENE 0
#define BEACH_SCENE 1 
#define FOREST_SCENE 2 
class GameEngine
{
	
public:
	Scene* current_scene; 
	bool isusing,hasobjectinrange; 
	bool gamestarted = false;
	std::vector<Scene*> game_scenes; 
	std::vector<Scene*> menu_scenes;
	GameObject* controlled_object;
	GameObject* objectinrange; 
	std::vector<GameObject*> scene_objects; 
	std::string status; 
	Controller* controller; 
	GameEngine();
	void setcontrolledobject(GameObject* obj); 
	void releasecontrolledobject();
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
	void displaystartmenu();
	void selectlevel();
	void startlevel(int level_index);
	void displaycontrols();
	void displaycredits();
	void displayoptions();
	void displayvideo();
	void displaykeybindings();
	void displayaudio();
	void backtogame();

};

