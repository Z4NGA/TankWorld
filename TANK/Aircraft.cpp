#include "Aircraft.h"
Aircraft::Aircraft() {
	type = "aircraft";
	usable = true; 
	inrange = false; 
	xoffset = 0; yoffset = 0; zoffset = 0;
}
Aircraft::Aircraft(float x, float y, float z, std::string t) {
	xLen = x;  yLen = y; zLen = z;
	type = t;
	usable = true;
	inrange = false;
	xoffset = 0; yoffset = 0; zoffset = 0;
}
void Aircraft::spawn() {
	glLoadIdentity();
	glPopMatrix();
	glPushMatrix();
	drawcore();
	drawwings();
	drawbackwings();
	drawrockets();
	drawwheels();
}
void Aircraft::drawcore() {
	if (type._Equal("helicopter")) {

	}
	else if (type._Equal("cargo")) {

	}
	else if (type._Equal("fighter")) {

	}
	if (type._Equal("ghost")) {

	}
}
void Aircraft::drawwings() {
	if (type._Equal("helicopter")) {

	}
	else if (type._Equal("cargo")) {

	}
	else if (type._Equal("fighter")) {

	}
	if (type._Equal("ghost")) {

	}
}
void Aircraft::drawbackwings() {
	if (type._Equal("helicopter")) {

	}
	else if (type._Equal("cargo")) {

	}
	else if (type._Equal("fighter")) {

	}
	if (type._Equal("ghost")) {

	}
}
void Aircraft::drawrockets() {
	if (type._Equal("helicopter")) {

	}
	else if (type._Equal("cargo")) {

	}
	else if (type._Equal("fighter")) {

	}
	if (type._Equal("ghost")) {

	}
}
void Aircraft::drawwheels() {
	//helicopter
	if (type._Equal("helicopter")) {

	}
	else if (type._Equal("cargo")) {

	}
	else if (type._Equal("fighter")) {

	}
	if (type._Equal("ghost")) {

	}
}