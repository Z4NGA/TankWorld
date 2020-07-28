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
	glTranslatef(-0.5*xLen, -0.35*yLen, -0.3 * zLen);//0.15
	drawminigate();
	//translation
	glTranslatef(-0.2 * xLen, 0.25*yLen, -0.4*zLen);//0.5-0.35+0.25 = 0.4
	drawbox();
}
void controleStation::drawbox() {
	float tempx = xLen/3., tempy = 0.8 * yLen, tempz = zLen;
	cube(tempx, tempy, tempz,gatewall);
}
void controleStation::drawminigate() {
	float tempx = xLen/20., tempy = 0.3 * yLen, tempz = zLen*0.3;
	float shade = 0.5;
	//front consisting from 2 parts
	cube(tempx, tempy, tempz, gate_frontback);
	glTranslatef(tempx / 2. + xLen / 2., tempy / 4., 0.);
	cube(xLen, tempy/4., tempz/8., gatebar_texture);
	glTranslatef(-tempx / 2. - xLen / 2., -tempy / 4., 0.);
}
void controleStation::drawlargegate() {
	float tempx = xLen*0.9, tempy =yLen, tempz = zLen*0.1;
	float shade = 0.7;

	//shrinken tempx
	//draw the grid
	glLineWidth(3.),
	glEnable(GL_LINE_SMOOTH);float j = tempy/2.;
	glColor4f(0.,0.,0.,1.);
	for (float  i = -tempx/2.; i <tempx/2.; i+=tempx/30.)
	{
		j -= tempy / 30.;
		glBegin(GL_LINES);
			glVertex3f(-tempx / 2., j, tempz / 2.);
			glVertex3f(i, tempy / 2., tempz / 2.);
		glEnd();
		glBegin(GL_LINES);
			glVertex3f(tempx / 2., -j, tempz / 2.);
			glVertex3f(-i, -tempy / 2., tempz / 2.);
		glEnd();
		glBegin(GL_LINES);
			glVertex3f(tempx / 2., j, tempz / 2.);
			glVertex3f(-i, tempy / 2., tempz / 2.);
		glEnd();
		glBegin(GL_LINES);
			glVertex3f(-tempx / 2., -j, tempz / 2.);
			glVertex3f(i, -tempy / 2., tempz / 2.);
		glEnd();
		// -tempz
		tempz = -tempz;//invert
		glBegin(GL_LINES);
			glVertex3f(-tempx / 2., j, tempz / 2.);
			glVertex3f(i, tempy / 2., tempz / 2.);
		glEnd();
		glBegin(GL_LINES);
			glVertex3f(tempx / 2., -j, tempz / 2.);
			glVertex3f(-i, -tempy / 2., tempz / 2.);
		glEnd();
		glBegin(GL_LINES);
			glVertex3f(tempx / 2., j, tempz / 2.);
			glVertex3f(-i, tempy / 2., tempz / 2.);
		glEnd();
		glBegin(GL_LINES);
			glVertex3f(-tempx / 2., -j, tempz / 2.);
			glVertex3f(i, -tempy / 2., tempz / 2.);
		glEnd();
		tempz = -tempz;//reset
	}
	glDisable(GL_LINE_SMOOTH);
	//draw gate left and right poles 
	tempx = xLen;
	glTranslatef(-tempx * 0.47, tempy/2., 0.);
	glRotatef(90,1., 0., 0.);
	gluCylinder(gluNewQuadric(), tempx / 40., tempx / 40., tempy, 10, 10);
	glRotatef(-90, 1., 0., 0.);
	glTranslatef(tempx * 0.94, 0., 0.);
	glRotatef(90, 1., 0., 0.);
	gluCylinder(gluNewQuadric(), tempx / 40., tempx / 40., tempy, 10, 10);
	glRotatef(-90, 1., 0., 0.);
	glTranslatef(-tempx * 0.47, -tempy / 2., 0.); //resetting position
	////front consisting from 3 parts
	//glBegin(GL_POLYGON);
	//	glColor4f(shade, shade, shade, 1.);
	//	glVertex3f(-tempx / 2., -tempy / 2., tempz / 2.);
	//	glVertex3f(-tempx / 2., tempy / 2., tempz / 2.);
	//	glVertex3f(tempy/2., tempy / 2., tempz / 2.);
	//	glVertex3f(tempy/2., -tempy / 2., tempz / 2.);
	//glEnd();
	////back consisting from 3 parts
	//glBegin(GL_POLYGON);
	//	glColor4f(shade, shade, shade, 1.);
	//	glVertex3f(-tempx / 2., -tempy / 2., -tempz / 2.);
	//	glVertex3f(-tempx / 2., tempy / 2., -tempz / 2.);
	//	glVertex3f(tempy/2., tempy / 2., -tempz / 2.);
	//	glVertex3f(tempy/2., -tempy / 2.,-tempz / 2.);
	//glEnd();
	////left consisting from 3 parts
	//glBegin(GL_POLYGON);
	//	glColor4f(shade, shade, shade, 1.);
	//	glVertex3f(-tempx / 2., -tempy / 2., -tempz / 2.);
	//	glVertex3f(-tempx / 2., tempy / 2., -tempz / 2.);
	//	glVertex3f(-tempy/2., tempy / 2., tempz / 2.);
	//	glVertex3f(-tempy/2., -tempy / 2., tempz / 2.);
	//glEnd();
	////right consisting from 3 parts
	//glBegin(GL_POLYGON);
	//	glColor4f(shade, shade, shade, 1.);
	//	glVertex3f(tempx / 2., -tempy / 2., -tempz / 2.);
	//	glVertex3f(tempx / 2., tempy / 2., -tempz / 2.);
	//	glVertex3f(tempy/2., tempy / 2., tempz / 2.);
	//	glVertex3f(tempy/2., -tempy / 2., tempz / 2.);
	//glEnd();
	////top consisting from 3 parts
	//glBegin(GL_POLYGON);
	//	glColor4f(shade, shade, shade, 1.);
	//	glVertex3f(-tempx / 2., tempy / 2., -tempz / 2.);
	//	glVertex3f(-tempx / 2., tempy / 2., tempz / 2.);
	//	glVertex3f(tempy/2., tempy / 2., tempz / 2.);
	//	glVertex3f(tempy/2., tempy / 2., -tempz / 2.);
	//glEnd();
	////bot consisting from 3 parts
	//glBegin(GL_POLYGON);
	//	glColor4f(shade, shade, shade, 1.);
	//	glVertex3f(-tempx / 2., -tempy / 2., -tempz / 2.);
	//	glVertex3f(-tempx / 2., -tempy / 2., tempz / 2.);
	//	glVertex3f(tempy/2., -tempy / 2., tempz / 2.);
	//	glVertex3f(tempy/2., -tempy / 2., -tempz / 2.);
	//glEnd();
}