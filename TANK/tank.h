#pragma once
#include "cube.h"
#include <iostream>
class tank
{
public:
	float xLen, yLen, zLen;
	float i_xlen, i_ylen, i_zlen;
	float dirx,diry,dirz; //vector that repesents the direction of the tank
	float tank_x_offset, tank_y_offset, tank_z_offset; //represnts how much the tank has to travel based on previous offset and dir
	//just indicates the current position of the tank
	float tankoffset, tankangle, topangle, cannonangle;
	std::vector<GLuint>* textures; 
	tank();
	tank(float x, float y, float z);
	~tank();
	void settextures(std::vector<GLuint>* t);
	void drawcore();
	void drawtop();
	void drawcannonpart();
	void drawbot();
	void drawwheelpart(int pos);
	void drawwheelcover(float tempx,float tempy, float tempz);
	void drawchain(float xoffset,int pos);
	void drawrims();
	void spawn(int pos);
	void movetank(float offset);
	void turntank(float angle);
	void tiltcannon(float angle);
	void turntop(float angle);
	void output_specs();
	void setposition(float x, float y, float z); 
	void reshape();
};
class position {
public:
	float x, y, z;
	position(float px,  float py, float pz):x(px),y(py),z(pz){}
	position operator +(position p) {
		x += p.x;
		y += p.y;
		z += p.z;
		return *this;
	}
	position add(float px, float py,float pz) {
		x += px;
		y += py;
		z += pz;
		return *this;
	}
	position operator -(position p) {
		x -= p.x;
		y -= p.y;
		z -= p.z;
		return *this;
	}
	static void print(position p) {
		std::cout << "x : " <<p.x<< ", y : " << p.y << ", z : "<< p.z << std::endl;
	}
};
