#pragma once
#include <vector>
#include <string>
class GameObject
{
public:
	float xLen, yLen, zLen; 
	float xoffset, yoffset, zoffset;
	std::string type; 
	GameObject();
	GameObject(float x,float y,float z); 
	void setposition(float x, float y, float z);
	std::vector<float> getborder();
	virtual void spawn() = 0;
};

