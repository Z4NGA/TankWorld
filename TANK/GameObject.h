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
	//gates and controle stations only
	bool turnedon = false;
	float opengateangle, opengateoffset; //describes gate angle and offset when open
	float closedgateangle, closedgateoffset;  // describes gate angle and offset whn closed
	float currentgateoffset, currentgateangle; //describes current gate offset and angle 
	bool isopen=false, isclosed=true; //stores if gate isopen or close ;
	bool islauncher_open = false;
	std::string type,generaltype="undefined"; 

	GameObject();
	GameObject(float x,float y,float z); 
	void setposition(float x, float y, float z);
	void rotateobject(float xangle,float yangle,float zangle);
	void addoffsettoposition(float x, float y, float z);
	//rocket truck functions
	virtual void open_launcher(){}
	virtual void close_launcher(){}
	virtual void turn_launcher(float turnangle){}
	virtual void tilt_launcher(float tilt_angle){}
	//gate class functions
	virtual void opengate(){}
	virtual void closegate(){}
	//tank functions
	virtual void tiltcannon(float angle){}
	virtual void turntop(float angle){}
	std::vector<float> getborder();
	virtual void spawn() = 0;
};

