#pragma once
#include "GameObject.h"
#include <iostream>
#include <string>
#include <vector>
#include <GL/freeglut.h>
#include <GL/SOIL.h>
#include <math.h>
#define M_PI acos(-1.)
extern GLuint black,grid_glass;
extern GLuint blackalum;
class rocket_truck : public GameObject
{
public : 
	float launcher_turn_angle, launcher_tilt_angle; 
	bool is_launcher_open; 
	rocket_truck();
	rocket_truck(float x, float y, float z);
	void spawn();
	void open_launcher();
	void close_launcher();
	void turn_launcher(float turnangle);
	void tilt_launcher(float tilt_angle);
	void draw_truck(); //draws the core of the truck
	void draw_wheels(); 
	void draw_doublewheel(); //draws a single doublewheel
	void draw_wheels_protections();
	void draw_connection(); //draws the connection between the launcher and truck
	void draw_launcher(); //draws the launchers
	void draw_rockets(); 

};

