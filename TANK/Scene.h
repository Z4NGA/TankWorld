#pragma once
#include "GameObject.h"
#include <string>
class Scene
{
public:
	std::string name,type;
	int NR_LEVELS = 2; //for level_selector only
	int cursorposition=1 ,nrofbuttons=0;
	int current_res, current_qual; //menu scene
	bool vsync; //menu scene
	bool changing_key; //keybinding
	//keybindings tracking for keybinding menu 
	//std::string forward = "z", backward = "s", left = "left", right = "right", cannon_up = "up", down = "down", change_scene = "x", use_object = "e",fly ="space";
	std::vector <std::string> keys{ "z", "s","up","down","left","right","x","e","space"}; //keybinding scene
	GameObject* controlled_object;
	std::vector<GameObject*> scene_objects;
	Scene();
	virtual void display() = 0;
	void addObject(GameObject* obj);
	void setControllledObject(GameObject* obj);
	virtual void incrementcursorposition(){}
	virtual void decrementcursorposition() {}
	virtual void changecursorposition(int position) {}
	virtual void displayinrangeui(){}
	virtual void changeres(int x){}
	virtual void changequal(int x){}
	virtual void changevsync(){}
};

