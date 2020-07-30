#pragma once
#include <vector>
#include <string>
class GameObject
{
public:
	float xLen, yLen, zLen; 
	float xoffset, yoffset, zoffset;
	float xrotationangle=0 ,yrotationangle=0, zrotationangle=0;
	bool inrange;
	bool usable; //indicates if an object is usable 
	std::string type,generaltype="undefined"; 
	GameObject();
	GameObject(float x,float y,float z); 
	void setposition(float x, float y, float z);
	void rotateobject(float xangle,float yangle,float zangle);
	void addoffsettoposition(float x, float y, float z);
	std::vector<float> getborder();
	virtual void spawn() = 0;
};

