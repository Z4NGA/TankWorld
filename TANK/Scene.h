#pragma once
#include "GameObject.h"
#include <string>
class Scene
{
public:
	std::string name,type;
	int cursorposition=1 ,nrofbuttons=0;
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
};

