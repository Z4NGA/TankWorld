#include "gameScene.h"
gameScene::gameScene(std::string n, std::string t) {
	name = n; 
	type = t; 
}
void gameScene::display() {
	glLoadIdentity();
	glPopMatrix();
	glPushMatrix();
	drawground();
	drawsky();
	drawwalls();
	for (GameObject* o : scene_objects) o->spawn();
}

void gameScene::drawwalls() {

	if(name._Equal("base")) glBindTexture(GL_TEXTURE_2D, wall1);
	else if (name._Equal("beach")) glBindTexture(GL_TEXTURE_2D, wall2);
	else glBindTexture(GL_TEXTURE_2D, wall3);

	//left 
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0., 0.); glVertex3f(-10., 0., -10);
	glTexCoord2f(0., 1.); glVertex3f(-10., 3.5, -10);
	glTexCoord2f(1., 1.); glVertex3f(-10., 3.5, 10);
	glTexCoord2f(1., 0.); glVertex3f(-10., 0., 10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//right 
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0., 0.); glVertex3f(10., 0., -10);
	glTexCoord2f(0., 1.); glVertex3f(10., 3.5, -10);
	glTexCoord2f(1., 1.); glVertex3f(10., 3.5, 10);
	glTexCoord2f(1., 0.); glVertex3f(10., 0., 10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//front 
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0., 0.); glVertex3f(-10., 0., -10);
	glTexCoord2f(0., 1.); glVertex3f(-10., 3.5, -10);
	glTexCoord2f(1., 1.); glVertex3f(10., 3.5, -10);
	glTexCoord2f(1., 0.); glVertex3f(10., 0., -10);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//back 
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0., 0.); glVertex3f(-10., 0., 10);
	glTexCoord2f(0., 1.); glVertex3f(-10., 3.5, 10);
	glTexCoord2f(1., 1.); glVertex3f(10., 3.5, 10);
	glTexCoord2f(1., 0.); glVertex3f(10., 0., 10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
void gameScene::drawground() {
	//loading ground texture ; 
	if (name._Equal("base")) glBindTexture(GL_TEXTURE_2D, ground1);
	else if (name._Equal("beach")) glBindTexture(GL_TEXTURE_2D, ground2);
	else glBindTexture(GL_TEXTURE_2D, ground3);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0., 0.); glVertex3f(-10., 0., -10);
	glTexCoord2f(0., 4.); glVertex3f(-10., 0., 10);
	glTexCoord2f(4., 4.); glVertex3f(10., 0., 10);
	glTexCoord2f(4., 0.); glVertex3f(10., 0., -10);
	glEnd();
	glDisable(GL_TEXTURE_2D);

}
void gameScene::drawsky() {
	//loading sky texture ; 
	if (name._Equal("base")) glBindTexture(GL_TEXTURE_2D, sky1);
	else if (name._Equal("beach")) glBindTexture(GL_TEXTURE_2D, sky2);
	else glBindTexture(GL_TEXTURE_2D, sky3);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0., 0.); glVertex3f(-15., 4., -15);
	glTexCoord2f(0., 1.); glVertex3f(-15., 4., 15);
	glTexCoord2f(1., 1.); glVertex3f(15., 4., 15);
	glTexCoord2f(1., 0.); glVertex3f(15., 4., -15);
	glEnd();
	glDisable(GL_TEXTURE_2D);

}
