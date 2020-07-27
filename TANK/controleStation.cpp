#include "controleStation.h"
controleStation::controleStation() {
	type = "controlestation";
	xoffset = 0; yoffset = 0; zoffset = 0;
	usable = false;
	inrange = false;
}
controleStation::controleStation(float x, float y, float z) {
	type = "controlestation";
	xLen = x;
	yLen = y;
	zLen = z;
	xoffset = 0; yoffset = 0; zoffset = 0;
	usable = false;
	inrange = false;
}
void controleStation::spawn() {
	glLoadIdentity();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0. + xoffset, yLen * 0.5 + yoffset, 0. + zoffset);
	drawlargegate();
	//translation
	glTranslatef(-0.7*xLen, -0.35*yLen, -0.3 * zLen);//0.15
	drawminigate();
	//translation
	glTranslatef(-0.3 * xLen, 0.25*yLen, -0.4*zLen);//0.5-0.35+0.25 = 0.4
	drawbox();
}
void controleStation::drawbox() {
	float tempx = xLen/3., tempy = 0.8 * yLen, tempz = zLen;
	float shade = 0.3;
	//front consisting from 3 parts
	glBegin(GL_POLYGON);
		glColor4f(shade, shade, shade, 1.);
		glVertex3f(-tempx / 2., -tempy / 2., tempz / 2.);
		glVertex3f(-tempx / 2., tempy / 2., tempz / 2.);
		glVertex3f(tempy/2., tempy / 2., tempz / 2.);
		glVertex3f(tempy/2., -tempy / 2., tempz / 2.);
	glEnd();
	//back consisting from 3 parts
	glBegin(GL_POLYGON);
		glColor4f(shade, shade, shade, 1.);
		glVertex3f(-tempx / 2., -tempy / 2., -tempz / 2.);
		glVertex3f(-tempx / 2., tempy / 2., -tempz / 2.);
		glVertex3f(tempy/2., tempy / 2., -tempz / 2.);
		glVertex3f(tempy/2., -tempy / 2.,-tempz / 2.);
	glEnd();
	//left consisting from 3 parts
	glBegin(GL_POLYGON);
		glColor4f(shade, shade, shade, 1.);
		glVertex3f(-tempx / 2., -tempy / 2., -tempz / 2.);
		glVertex3f(-tempx / 2., tempy / 2., -tempz / 2.);
		glVertex3f(-tempy/2., tempy / 2., tempz / 2.);
		glVertex3f(-tempy/2., -tempy / 2., tempz / 2.);
	glEnd();
	//right consisting from 3 parts
	glBegin(GL_POLYGON);
		glColor4f(shade, shade, shade, 1.);
		glVertex3f(tempx / 2., -tempy / 2., -tempz / 2.);
		glVertex3f(tempx / 2., tempy / 2., -tempz / 2.);
		glVertex3f(tempy/2., tempy / 2., tempz / 2.);
		glVertex3f(tempy/2., -tempy / 2., tempz / 2.);
	glEnd();
	//top consisting from 3 parts
	glBegin(GL_POLYGON);
		glColor4f(shade, shade, shade, 1.);
		glVertex3f(-tempx / 2., tempy / 2., -tempz / 2.);
		glVertex3f(-tempx / 2., tempy / 2., tempz / 2.);
		glVertex3f(tempy/2., tempy / 2., tempz / 2.);
		glVertex3f(tempy/2., tempy / 2., -tempz / 2.);
	glEnd();
	//bot consisting from 3 parts
	glBegin(GL_POLYGON);
		glColor4f(shade, shade, shade, 1.);
		glVertex3f(-tempx / 2., -tempy / 2., -tempz / 2.);
		glVertex3f(-tempx / 2., -tempy / 2., tempz / 2.);
		glVertex3f(tempy/2., -tempy / 2., tempz / 2.);
		glVertex3f(tempy/2., -tempy / 2., -tempz / 2.);
	glEnd();
}
void controleStation::drawminigate() {
	float tempx = xLen/20., tempy = 0.3 * yLen, tempz = zLen*0.3;
	float shade = 0.5;
	//front consisting from 3 parts
	glBegin(GL_POLYGON);
		glColor4f(shade, shade, shade, 1.);
		glVertex3f(-tempx / 2., -tempy / 2., tempz / 2.);
		glVertex3f(-tempx / 2., tempy / 2., tempz / 2.);
		glVertex3f(tempy/2., tempy / 2., tempz / 2.);
		glVertex3f(tempy/2., -tempy / 2., tempz / 2.);
	glEnd();
	//back consisting from 3 parts
	glBegin(GL_POLYGON);
		glColor4f(shade, shade, shade, 1.);
		glVertex3f(-tempx / 2., -tempy / 2., -tempz / 2.);
		glVertex3f(-tempx / 2., tempy / 2., -tempz / 2.);
		glVertex3f(tempy/2., tempy / 2., -tempz / 2.);
		glVertex3f(tempy/2., -tempy / 2.,-tempz / 2.);
	glEnd();
	//left consisting from 3 parts
	glBegin(GL_POLYGON);
		glColor4f(shade, shade, shade, 1.);
		glVertex3f(-tempx / 2., -tempy / 2., -tempz / 2.);
		glVertex3f(-tempx / 2., tempy / 2., -tempz / 2.);
		glVertex3f(-tempy/2., tempy / 2., tempz / 2.);
		glVertex3f(-tempy/2., -tempy / 2., tempz / 2.);
	glEnd();
	//right consisting from 3 parts
	glBegin(GL_POLYGON);
		glColor4f(shade, shade, shade, 1.);
		glVertex3f(tempx / 2., -tempy / 2., -tempz / 2.);
		glVertex3f(tempx / 2., tempy / 2., -tempz / 2.);
		glVertex3f(tempy/2., tempy / 2., tempz / 2.);
		glVertex3f(tempy/2., -tempy / 2., tempz / 2.);
	glEnd();
	//top consisting from 3 parts
	glBegin(GL_POLYGON);
		glColor4f(shade, shade, shade, 1.);
		glVertex3f(-tempx / 2., tempy / 2., -tempz / 2.);
		glVertex3f(-tempx / 2., tempy / 2., tempz / 2.);
		glVertex3f(tempy/2., tempy / 2., tempz / 2.);
		glVertex3f(tempy/2., tempy / 2., -tempz / 2.);
	glEnd();
	//bot consisting from 3 parts
	glBegin(GL_POLYGON);
		glColor4f(shade, shade, shade, 1.);
		glVertex3f(-tempx / 2., -tempy / 2., -tempz / 2.);
		glVertex3f(-tempx / 2., -tempy / 2., tempz / 2.);
		glVertex3f(tempy/2., -tempy / 2., tempz / 2.);
		glVertex3f(tempy/2., -tempy / 2., -tempz / 2.);
	glEnd();
}
void controleStation::drawlargegate() {
	float tempx = xLen, tempy =yLen, tempz = zLen*0.2;
	float shade = 0.7;
	//front consisting from 3 parts
	glBegin(GL_POLYGON);
		glColor4f(shade, shade, shade, 1.);
		glVertex3f(-tempx / 2., -tempy / 2., tempz / 2.);
		glVertex3f(-tempx / 2., tempy / 2., tempz / 2.);
		glVertex3f(tempy/2., tempy / 2., tempz / 2.);
		glVertex3f(tempy/2., -tempy / 2., tempz / 2.);
	glEnd();
	//back consisting from 3 parts
	glBegin(GL_POLYGON);
		glColor4f(shade, shade, shade, 1.);
		glVertex3f(-tempx / 2., -tempy / 2., -tempz / 2.);
		glVertex3f(-tempx / 2., tempy / 2., -tempz / 2.);
		glVertex3f(tempy/2., tempy / 2., -tempz / 2.);
		glVertex3f(tempy/2., -tempy / 2.,-tempz / 2.);
	glEnd();
	//left consisting from 3 parts
	glBegin(GL_POLYGON);
		glColor4f(shade, shade, shade, 1.);
		glVertex3f(-tempx / 2., -tempy / 2., -tempz / 2.);
		glVertex3f(-tempx / 2., tempy / 2., -tempz / 2.);
		glVertex3f(-tempy/2., tempy / 2., tempz / 2.);
		glVertex3f(-tempy/2., -tempy / 2., tempz / 2.);
	glEnd();
	//right consisting from 3 parts
	glBegin(GL_POLYGON);
		glColor4f(shade, shade, shade, 1.);
		glVertex3f(tempx / 2., -tempy / 2., -tempz / 2.);
		glVertex3f(tempx / 2., tempy / 2., -tempz / 2.);
		glVertex3f(tempy/2., tempy / 2., tempz / 2.);
		glVertex3f(tempy/2., -tempy / 2., tempz / 2.);
	glEnd();
	//top consisting from 3 parts
	glBegin(GL_POLYGON);
		glColor4f(shade, shade, shade, 1.);
		glVertex3f(-tempx / 2., tempy / 2., -tempz / 2.);
		glVertex3f(-tempx / 2., tempy / 2., tempz / 2.);
		glVertex3f(tempy/2., tempy / 2., tempz / 2.);
		glVertex3f(tempy/2., tempy / 2., -tempz / 2.);
	glEnd();
	//bot consisting from 3 parts
	glBegin(GL_POLYGON);
		glColor4f(shade, shade, shade, 1.);
		glVertex3f(-tempx / 2., -tempy / 2., -tempz / 2.);
		glVertex3f(-tempx / 2., -tempy / 2., tempz / 2.);
		glVertex3f(tempy/2., -tempy / 2., tempz / 2.);
		glVertex3f(tempy/2., -tempy / 2., -tempz / 2.);
	glEnd();
}