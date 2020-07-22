#include "base_scene.h"
base_scene::base_scene(std::string n) : name(n) {

}
void base_scene::draw() {
	glLoadIdentity();
	glPopMatrix();
	glPushMatrix();
	drawground();
	drawsky();
	drawwalls();
}

void base_scene::drawwalls() {

	glBindTexture(GL_TEXTURE_2D, wall);
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
void base_scene::drawground() {
	//loading ground texture ; 
	glBindTexture(GL_TEXTURE_2D, ground);
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
void base_scene::drawsky() {
	//loading sky texture ; 
	glBindTexture(GL_TEXTURE_2D, sky);

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