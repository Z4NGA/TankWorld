#include "GameObject.h"
GameObject::GameObject() {

}
GameObject::GameObject(float x, float y, float z) : xLen(x), yLen(y), zLen(z) {
	xoffset = 0; yoffset = 0; zoffset = 0; 
	type = "undefined";

}
std::vector<float> GameObject::getborder() {
	//left,right,top ,bot , front,back
	std::vector<float> temp;
	temp.push_back(-xLen / 2. + xoffset);
	temp.push_back(xLen / 2. + xoffset);
	temp.push_back(yLen + yoffset);
	temp.push_back(0. + yoffset);
	temp.push_back(-zLen / 2. + zoffset);
	temp.push_back(zLen / 2. + zoffset);
	return temp;
}
void GameObject::setposition(float x, float y, float z) {
	xoffset = x; yoffset = y;   zoffset = z;
}