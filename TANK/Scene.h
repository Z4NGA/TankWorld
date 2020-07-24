#pragma once
#include "GameObject.h"
#include <string>
class Scene
{
public:
	std::string name,type;
	GameObject* controlled_object;
	std::vector<GameObject*> scene_objects;
	Scene();
	virtual void display() = 0;
	void addObject(GameObject* obj);
	void setControllledObject(GameObject* obj);
};

