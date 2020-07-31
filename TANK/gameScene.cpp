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
	glTexCoord2f(0., 0.); glVertex3f(-40, 0., -40);
	glTexCoord2f(0., 1.); glVertex3f(-40, 3.5, -40);
	glTexCoord2f(4., 1.); glVertex3f(-40, 3.5, 40);
	glTexCoord2f(4., 0.); glVertex3f(-40, 0., 40);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//right 
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0., 0.); glVertex3f(40, 0., -40);
	glTexCoord2f(0., 1.); glVertex3f(40, 3.5, -40);
	glTexCoord2f(4., 1.); glVertex3f(40, 3.5, 40);
	glTexCoord2f(4., 0.); glVertex3f(40, 0., 40);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//front 
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0., 0.); glVertex3f(-40, 0., -40);
	glTexCoord2f(0., 1.); glVertex3f(-40, 3.5, -40);
	glTexCoord2f(4., 1.); glVertex3f(40, 3.5, -40);
	glTexCoord2f(4., 0.); glVertex3f(40, 0., -40);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//mid wall with gate
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2f(0., 0.); glVertex3f(-40., 0., 10);
		glTexCoord2f(0., 1.); glVertex3f(-40., 3.5, 10);
		glTexCoord2f(2., 1.); glVertex3f(18, 3.5, 10);
		glTexCoord2f(2., 0.); glVertex3f(18, 0., 10);
	glEnd();

	glBegin(GL_POLYGON);
		glTexCoord2f(0., 0.); glVertex3f(22, 0., 10);
		glTexCoord2f(0., 1.); glVertex3f(22, 3.5, 10);
		glTexCoord2f(2., 1.); glVertex3f(40, 3.5, 10);
		glTexCoord2f(2., 0.); glVertex3f(40, 0., 10);
	glEnd();

	//back wall
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0., 0.); glVertex3f(-40, 0., 40);
	glTexCoord2f(0., 1.); glVertex3f(-40, 3.5, 40);
	glTexCoord2f(4., 1.); glVertex3f(40, 3.5, 40);
	glTexCoord2f(4., 0.); glVertex3f(40, 0., 40);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
void gameScene::drawground() {
	//loading ground texture ; 
	if (name._Equal("base")) glBindTexture(GL_TEXTURE_2D, ground6);
	else if (name._Equal("beach")) glBindTexture(GL_TEXTURE_2D, ground2);
	else glBindTexture(GL_TEXTURE_2D, ground3);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0., 0.); glVertex3f(-40., 0., -40);//10
	glTexCoord2f(0., 4.); glVertex3f(-40, 0., 40);
	glTexCoord2f(4., 4.); glVertex3f(40, 0., 40);
	glTexCoord2f(4., 0.); glVertex3f(40, 0., -40);
	glEnd();
	glDisable(GL_TEXTURE_2D);

}
void gameScene::drawsky() {
	//loading sky texture ; 
	if (name._Equal("base")) glBindTexture(GL_TEXTURE_2D, skynight);
	else if (name._Equal("beach")) glBindTexture(GL_TEXTURE_2D, sky2);
	else glBindTexture(GL_TEXTURE_2D, sky3);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0., 0.); glVertex3f(-95, 16., -95);//15
	glTexCoord2f(0., 2.); glVertex3f(-95, 16., 95);
	glTexCoord2f(2., 2.); glVertex3f(95, 16., 95);
	glTexCoord2f(2., 0.); glVertex3f(95, 16., -95);
	glEnd();
	glDisable(GL_TEXTURE_2D);

}
void gameScene::displayinrangeui() {
	glBindTexture(GL_TEXTURE_2D, useobject);
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
			glTexCoord2d(0., 0.); glVertex3f(-0.5, 0.7 - (float)(1.4 / 11), -1.);
			glTexCoord2d(0., 1.); glVertex3f(-0.5, 0.7, -1.);
			glTexCoord2d(1., 1.); glVertex3f(0.5, 0.7, -1.);
			glTexCoord2d(1., 0.); glVertex3f(0.5, 0.7 - (float)(1.4 / 11), -1.);
		glEnd();
	glDisable(GL_TEXTURE_2D);
}