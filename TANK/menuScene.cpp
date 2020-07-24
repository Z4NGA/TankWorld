#include "menuScene.h"
menuScene::menuScene() {
	
}

menuScene::menuScene(std::string n, std::string t ){

}
void menuScene::display() {
	glLoadIdentity(); 
	glPopMatrix(); 
	glPushMatrix();
	drawbackground(); 
	drawbuttons();
}
void menuScene::drawbackground() {

}
void menuScene::drawbuttons() {

}