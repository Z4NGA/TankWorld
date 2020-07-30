#include "Aircraft.h"
Aircraft::Aircraft() {
	generaltype = "aircraft";
	usable = true; 
	inrange = false; 
	backwingrotationangle = 0; topwingrotationangle = 0.;
	xoffset = 0; yoffset = 0; zoffset = 0;
}
Aircraft::Aircraft(float x, float y, float z, std::string t) {
	generaltype = "aircraft";
	xLen = x;  yLen = y; zLen = z;
	backwingrotationangle = 0; topwingrotationangle = 0.;
	type = t;
	usable = true;
	inrange = false;
	xoffset = 0; yoffset = 0; zoffset = 0;
}
void Aircraft::rotatebackwing(float angle) {
	backwingrotationangle = angle;
}
void Aircraft::rotatetopwing(float angle) {
	topwingrotationangle = angle;
}
void Aircraft::spawn() {
	glLoadIdentity();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.+xoffset, yLen / 2.+yoffset, 0.+zoffset);
	//aplying object roations 
	glRotatef(xrotationangle, 1., 0., 0.);
	glRotatef(yrotationangle, 0., 1., 0.);
	glRotatef(zrotationangle, 0., 0., 1.);
	drawcore();
	drawback();
	drawwings();
	drawbackwings();
	drawrockets();
	drawwheels();
}
void Aircraft::drawcore() {
	float tempx = xLen, tempy = yLen*0.5, tempz = zLen * 0.5;
	if (type._Equal("helicopter")) {
		tempx = xLen*0.7, tempy = yLen , tempz = zLen * 0.5;
		glBindTexture(GL_TEXTURE_2D, metal);;
		glEnable(GL_TEXTURE_2D);
		///
		/// FRONT
		///
		glColor4f(0.5, 0.5, 0.5, 1.);
		//nose
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(-tempx / 2., -0.1 * tempy, tempz);
			glTexCoord2d(0.,1.);  glVertex3f(-tempx / 2., 0.1 * tempy, tempz);
			glTexCoord2d(1.,1.);  glVertex3f(-tempx / 4., 0.25 * tempy, tempz);
			glTexCoord2d(1.,0.);  glVertex3f(-tempx / 4., -0.4 * tempy, tempz);
		glEnd();
		//body
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(-tempx / 4., -0.4 * tempy, tempz);
			glTexCoord2d(0.,1.);  glVertex3f(-tempx / 4., 0.25 * tempy, tempz);
			glTexCoord2d(1.,1.);  glVertex3f(tempx / 4., 0.25 * tempy, tempz);
			glTexCoord2d(1.,0.);  glVertex3f(tempx / 4., -0.4 * tempy, tempz);
		glEnd();
		//back body
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(tempx / 4., 0.25 * tempy, tempz);
			glTexCoord2d(0.,1.);  glVertex3f(tempx / 4., -0.4 * tempy, tempz);
			glTexCoord2d(1.,1.);  glVertex3f(tempx *0.35, -0.35 * tempy, tempz);
			glTexCoord2d(1.,0.);  glVertex3f(tempx *0.35, 0.1 * tempy, tempz);
		glEnd();
		
		//triangle window
		glColor4f(0.1, 0.1, 0.1, 0.8);
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(-tempx / 4., 0.25* tempy, tempz);
			glTexCoord2d(0.,1.);  glVertex3f(-tempx / 7., 0.5 * tempy, tempz);
			glTexCoord2d(1.,1.);  glVertex3f(-tempx / 8., 0.5 * tempy, tempz);
			glTexCoord2d(01.,0.);  glVertex3f(-tempx / 8., 0.25 * tempy, tempz);
		glEnd();
		//long window
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(-tempx / 8., 0.25 * tempy, tempz);
			glTexCoord2d(0.,01.);  glVertex3f(-tempx / 8., 0.5 * tempy, tempz);
			glTexCoord2d(01.,01.);  glVertex3f(tempx / 8., 0.5 * tempy, tempz);
			glTexCoord2d(01.,0.);  glVertex3f(tempx / 8., 0.25 * tempy, tempz);
		glEnd();
		//rear window
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(tempx / 8., 0.25 * tempy, tempz);
			glTexCoord2d(0.,01.);  glVertex3f(tempx / 8., 0.5 * tempy, tempz);
			glTexCoord2d(01.,01.);  glVertex3f(tempx / 4., 0.25 * tempy, tempz);
		glEnd();
		///
		/// BACK
		///
		glColor4f(0.5, 0.5, 0.5, 1.);
		tempz = -tempz; 
		//nose
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(-tempx / 2., -0.1 * tempy, tempz);
			glTexCoord2d(0.,01.);  glVertex3f(-tempx / 2., 0.1 * tempy, tempz);
			glTexCoord2d(01.,01.);  glVertex3f(-tempx / 4., 0.25 * tempy, tempz);
			glTexCoord2d(01.,0.);  glVertex3f(-tempx / 4., -0.4 * tempy, tempz);
		glEnd();
		//body
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(-tempx / 4., -0.4 * tempy, tempz);
			glTexCoord2d(0.,01.);  glVertex3f(-tempx / 4., 0.25 * tempy, tempz);
			glTexCoord2d(01.,01.);  glVertex3f(tempx / 4., 0.25 * tempy, tempz);
			glTexCoord2d(01.,0.);  glVertex3f(tempx / 4., -0.4 * tempy, tempz);
		glEnd();
		//back body
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(tempx / 4., 0.25 * tempy, tempz);
			glTexCoord2d(0.,01.);  glVertex3f(tempx / 4., -0.4 * tempy, tempz);
			glTexCoord2d(01.,01.);  glVertex3f(tempx *0.35, -0.35 * tempy, tempz);
			glTexCoord2d(01.,0.);  glVertex3f(tempx *0.35, 0.1 * tempy, tempz);
		glEnd();
		//triangle window
		glColor4f(0.1, 0.1, 0.1, 0.8);
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(-tempx / 4., 0.25* tempy, tempz);
			glTexCoord2d(0.,01.);  glVertex3f(-tempx / 7., 0.5 * tempy, tempz);
			glTexCoord2d(01.,01.);  glVertex3f(-tempx / 8., 0.5 * tempy, tempz);
			glTexCoord2d(01.,0.);  glVertex3f(-tempx / 8., 0.25 * tempy, tempz);
		glEnd();
		
		//long window
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(-tempx / 8., 0.25 * tempy, tempz);
			glTexCoord2d(0.,01.);  glVertex3f(-tempx / 8., 0.5 * tempy, tempz);
			glTexCoord2d(01.,01.);  glVertex3f(tempx / 8., 0.5 * tempy, tempz);
			glTexCoord2d(01.,0.);  glVertex3f(tempx / 8., 0.25 * tempy, tempz);
		glEnd();
		//rear window
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(tempx / 8., 0.25 * tempy, tempz);
			glTexCoord2d(0.,01.);  glVertex3f(tempx / 8., 0.5 * tempy, tempz);
			glTexCoord2d(01.,01.);  glVertex3f(tempx / 4., 0.25 * tempy, tempz);
		glEnd();
		tempz = -tempz;
		///
		/// left
		///
		glColor4f(0.5, 0.5, 0.5, 1.);
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(-tempx / 2., -0.1 * tempy, tempz);
			glTexCoord2d(0.,01.);  glVertex3f(-tempx / 2., 0.1 * tempy, tempz);
			glTexCoord2d(01.,01.);  glVertex3f(-tempx / 2., 0.1 * tempy, -tempz);
			glTexCoord2d(01.,0.);  glVertex3f(-tempx / 2., -0.1 * tempy, -tempz);
		glEnd();
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(-tempx / 2., 0.1 * tempy, tempz);
			glTexCoord2d(0.,01.);  glVertex3f(-tempx / 4., 0.25 * tempy, tempz);
			glTexCoord2d(01.,01.);  glVertex3f(-tempx / 4., 0.25 * tempy,-tempz);
			glTexCoord2d(01.,0.);  glVertex3f(-tempx / 2., 0.1 * tempy, -tempz);
		glEnd();
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(-tempx / 2., -0.1 * tempy, tempz);
			glTexCoord2d(0.,01.);  glVertex3f(-tempx / 4., -0.4 * tempy, tempz);
			glTexCoord2d(01.,01.);  glVertex3f(-tempx / 4., -0.4 * tempy, -tempz);
			glTexCoord2d(01.,0.);  glVertex3f(-tempx / 2., -0.1 * tempy, -tempz);
		glEnd();
		/// <summary>
		///  Right
		/// </summary>
		//top part
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(tempx / 4., 0.25 * tempy, tempz);
			glTexCoord2d(0.,01.);  glVertex3f(tempx *0.35, 0.1 * tempy, tempz);
			glTexCoord2d(01.,01.);  glVertex3f(tempx * 0.35, 0.1 * tempy, -tempz);
			glTexCoord2d(01.,0.);  glVertex3f(tempx / 4., 0.25 * tempy, -tempz);
		glEnd();
		//mid part
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(tempx * 0.35, -0.35 * tempy, tempz);
			glTexCoord2d(0.,01.);  glVertex3f(tempx * 0.35, 0.1 * tempy, tempz);
			glTexCoord2d(01.,01.);  glVertex3f(tempx * 0.35, 0.1 * tempy, -tempz);
			glTexCoord2d(01.,0.);  glVertex3f(tempx * 0.35, -0.35 * tempy, -tempz);
		glEnd();
		//bot part
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(tempx / 4., -0.4 * tempy, tempz);
			glTexCoord2d(0.,01.);  glVertex3f(tempx *0.35, -0.35 * tempy, tempz);
			glTexCoord2d(01.,01.);  glVertex3f(tempx * 0.35, -0.35 * tempy, -tempz);
			glTexCoord2d(01.,0.);  glVertex3f(tempx / 4., -0.4 * tempy, -tempz);
		glEnd();

		glColor4f(0.1, 0.1, 0.1, 0.8);
		/// TOP
		//triangle window
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(-tempx / 4., 0.25* tempy, tempz);
			glTexCoord2d(0.,01.);  glVertex3f(-tempx / 7., 0.5 * tempy, tempz);
			glTexCoord2d(01.,01.);  glVertex3f(-tempx / 7., 0.5 * tempy, -tempz);
			glTexCoord2d(01.,0.);  glVertex3f(-tempx / 4., 0.25 * tempy, -tempz);
		glEnd();
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(-tempx / 7., 0.5 * tempy, tempz);
			glTexCoord2d(0.,01.);  glVertex3f(-tempx / 8., 0.5 * tempy, tempz);
			glTexCoord2d(01.,01.);  glVertex3f(-tempx / 8., 0.5 * tempy, -tempz);
			glTexCoord2d(01.,0.);  glVertex3f(-tempx / 7., 0.5 * tempy, -tempz);
		glEnd();
		//long window
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(-tempx / 8., 0.5 * tempy, tempz);
			glTexCoord2d(0.,01.);  glVertex3f(tempx / 8., 0.5 * tempy, tempz);
			glTexCoord2d(01.,01.);  glVertex3f(tempx / 8., 0.5 * tempy, -tempz);
			glTexCoord2d(01.,0.);  glVertex3f(-tempx / 8., 0.5 * tempy, -tempz);
		glEnd();
		//rear window
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(tempx / 8., 0.5 * tempy, tempz);
			glTexCoord2d(0.,01.);  glVertex3f(tempx / 4., 0.25 * tempy, tempz);
			glTexCoord2d(01.,01.);  glVertex3f(tempx / 4., 0.25 * tempy, -tempz);
			glTexCoord2d(01.,0.);  glVertex3f(tempx / 8., 0.5 * tempy, -tempz);
		glEnd();
		///BOT 
		//body
		glColor4f(0.5, 0.5, 0.5, 1.);
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(-tempx / 4., -0.4 * tempy, tempz);
			glTexCoord2d(0.,01.);  glVertex3f(tempx / 4., -0.4 * tempy, tempz);
			glTexCoord2d(01.,01.);  glVertex3f(tempx / 4., -0.4 * tempy, -tempz);
			glTexCoord2d(01.,0.);  glVertex3f(-tempx / 4., -0.4 * tempy,-tempz);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	else if (type._Equal("cargo")) {
		tempx = xLen * 0.7, tempy = yLen * 0.5, tempz = zLen * 0.25;
		glColor4f(0.2, 0.2, 0.2, 1.);
		glRotatef(90., 0., 1., 0.);
		gluCylinder(gluNewQuadric(), 0., tempy * 0.7, tempx * 0.05, 20, 20);
		glRotatef(-90., 0., 1., 0.);
		glTranslatef(tempx * 0.05, 0., 0.);
		glRotatef(90., 0., 1., 0.);
		glColor4f(0.4, 0.4, 0.4, 1.);
		gluCylinder(gluNewQuadric(), tempy * 0.7, tempy, tempx * 0.2, 20, 10);
		glRotatef(-90., 0., 1., 0.);
		glTranslatef(tempx * 0.2, 0., 0.);
		glRotatef(90., 0., 1., 0.);
		glColor4f(0.6, 0.6, 0.6, 1.);
		gluCylinder(gluNewQuadric(), tempy, tempy, tempx * 0.5, 20, 10);
		glRotatef(-90., 0., 1., 0.);
		glTranslatef(tempx * 0.5, 0., 0.);
		glRotatef(90., 0., 1., 0.);
		glColor4f(0.8, 0.8, 0.8, 1.);
		gluCylinder(gluNewQuadric(), tempy, 0, tempx * 0.1, 20, 10);
		glRotatef(-90., 0., 1., 0.);
	}
	else if (type._Equal("fighter")) {
		tempx = xLen * 0.7, tempy = yLen * 0.5, tempz = zLen * 0.25;
		glColor4f(0.2, 0.2, 0.2, 1.);
		glRotatef(90., 0., 1., 0.);
		gluCylinder(gluNewQuadric(), 0., tempy * 0.7, tempx * 0.05, 20, 20);
		glRotatef(-90., 0., 1., 0.);
		glTranslatef(tempx * 0.05, 0., 0.);
		glRotatef(90., 0., 1., 0.);
		glColor4f(0.4, 0.4, 0.4, 1.);
		gluCylinder(gluNewQuadric(), tempy * 0.7, tempy, tempx * 0.2, 20, 10);
		glRotatef(-90., 0., 1., 0.);
		glTranslatef(tempx * 0.2, 0., 0.);
		glRotatef(90., 0., 1., 0.);
		glColor4f(0.6, 0.6, 0.6, 1.);
		gluCylinder(gluNewQuadric(), tempy, tempy, tempx * 0.5, 20, 10);
		glRotatef(-90., 0., 1., 0.);
		glTranslatef(tempx * 0.5, 0., 0.);
		glRotatef(90., 0., 1., 0.);
		glColor4f(0.8, 0.8, 0.8, 1.);
		gluCylinder(gluNewQuadric(), tempy, 0, tempx * 0.1, 20, 10);
		glRotatef(-90., 0., 1., 0.);
	}
	if (type._Equal("ghost")) {
		tempx = xLen * 0.7, tempy = yLen * 0.5, tempz = zLen * 0.25;
		glColor4f(0.2, 0.2, 0.2, 1.);
		glRotatef(90., 0., 1., 0.);
		gluCylinder(gluNewQuadric(), 0., tempy * 0.7, tempx * 0.05, 20, 20);
		glRotatef(-90., 0., 1., 0.);
		glTranslatef(tempx * 0.05, 0., 0.);
		glRotatef(90., 0., 1., 0.);
		glColor4f(0.4, 0.4, 0.4, 1.);
		gluCylinder(gluNewQuadric(), tempy * 0.7, tempy, tempx * 0.2, 20, 10);
		glRotatef(-90., 0., 1., 0.);
		glTranslatef(tempx * 0.2, 0., 0.);
		glRotatef(90., 0., 1., 0.);
		glColor4f(0.6, 0.6, 0.6, 1.);
		gluCylinder(gluNewQuadric(), tempy, tempy, tempx * 0.5, 20, 10);
		glRotatef(-90., 0., 1., 0.);
		glTranslatef(tempx * 0.5, 0., 0.);
		glRotatef(90., 0., 1., 0.);
		glColor4f(0.8, 0.8, 0.8, 1.);
		gluCylinder(gluNewQuadric(), tempy, 0, tempx * 0.1, 20, 10);
		glRotatef(-90., 0., 1., 0.);
	}
}
void Aircraft::drawback() {
	if (type._Equal("helicopter")) {
		float tempx = xLen * 0.7, tempy = yLen, tempz = zLen * 0.2;
		/// 
		/// FRONT
		/// 
		glColor4f(0.4, 0.4, 0.4, 1.);
		//1
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(tempx *0.35, -0.35 * tempy, tempz);
			glTexCoord2d(0.,01.);  glVertex3f(tempx *0.35, 0.1 * tempy, tempz);
			glTexCoord2d(01.,01.);  glVertex3f(tempx ,0.1 * tempy, tempz);
			glTexCoord2d(01.,0.);  glVertex3f(tempx , -0.1 * tempy, tempz);
		glEnd();
		//2
		glColor4f(0.3, 0.3, 0.3, 1.);
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(tempx , -0.1 * tempy, tempz);
			glTexCoord2d(0.,0.5);  glVertex3f(tempx , 0.1 * tempy, tempz);
			glTexCoord2d(0.5,1);  glVertex3f(tempx *1.1,0.35* tempy, tempz);
			glTexCoord2d(1.,1.);  glVertex3f(tempx * 1.2, 0.35 * tempy, tempz);
			glTexCoord2d(0.25,0.);  glVertex3f(tempx * 1.05, -0.1 * tempy, tempz);
		glEnd();
		/// 
		/// back
		/// 
		glColor4f(0.4, 0.4, 0.4, 1.);
		tempz = -tempz; 
		//1
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(tempx *0.35, -0.35 * tempy, tempz);
			glTexCoord2d(0.,1);  glVertex3f(tempx *0.35, 0.1 * tempy, tempz);
			glTexCoord2d(1,1);  glVertex3f(tempx ,0.1 * tempy, tempz);
			glTexCoord2d(1,0.);  glVertex3f(tempx , -0.1 * tempy, tempz);
		glEnd();
		//2
		glColor4f(0.3, 0.3, 0.3, 1.);
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(tempx , -0.1 * tempy, tempz);
			glTexCoord2d(0.,1);  glVertex3f(tempx , 0.1 * tempy, tempz);
			glTexCoord2d(1,1);  glVertex3f(tempx *1.1,0.35* tempy, tempz);
			glTexCoord2d(1,0.);  glVertex3f(tempx * 1.2, 0.35 * tempy, tempz);
			glTexCoord2d(0.,0.);  glVertex3f(tempx * 1.05, -0.1 * tempy, tempz);
		glEnd();
		tempz = -tempz;
		/// 
		/// left
		/// 
		glColor4f(0.4, 0.4, 0.4, 1.);
		//1
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(tempx *0.35, -0.35 * tempy, tempz);
			glTexCoord2d(0.,1);  glVertex3f(tempx *0.35, 0.1 * tempy, tempz);
			glTexCoord2d(1,1);  glVertex3f(tempx * 0.35, 0.1 * tempy, -tempz);
			glTexCoord2d(1,0.);  glVertex3f(tempx * 0.35, -0.35 * tempy, -tempz);
		glEnd();
		//2
		glColor4f(0.3, 0.3, 0.3, 1.);
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(tempx , -0.1 * tempy, tempz);
			glTexCoord2d(0.,1);  glVertex3f(tempx , 0.1 * tempy, tempz);
			glTexCoord2d(1,1);  glVertex3f(tempx, 0.1 * tempy, -tempz);
			glTexCoord2d(1,0.);  glVertex3f(tempx, -0.1 * tempy, -tempz);
		glEnd();
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(tempx , 0.1 * tempy, tempz);
			glTexCoord2d(0.,1);  glVertex3f(tempx *1.1,0.35* tempy, tempz);
			glTexCoord2d(1,1);  glVertex3f(tempx * 1.1, 0.35 * tempy, -tempz);
			glTexCoord2d(1,0.);  glVertex3f(tempx, 0.1 * tempy, -tempz);
		glEnd();
		/// 
		/// right
		/// 
		glColor4f(0.4, 0.4, 0.4, 1.);
		//1
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(tempx ,0.1 * tempy, tempz);
			glTexCoord2d(0.,1);  glVertex3f(tempx , -0.1 * tempy, tempz);
			glTexCoord2d(1,1);  glVertex3f(tempx, -0.1 * tempy, -tempz);
			glTexCoord2d(1,0.);  glVertex3f(tempx, 0.1 * tempy, -tempz);
		glEnd();
		//2
		glColor4f(0.3, 0.3, 0.3, 1.);
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(tempx * 1.2, 0.35 * tempy, tempz);
			glTexCoord2d(0.,1);  glVertex3f(tempx * 1.05, -0.1 * tempy, tempz);
			glTexCoord2d(1,1);  glVertex3f(tempx * 1.05, -0.1 * tempy, -tempz);
			glTexCoord2d(1,0.);  glVertex3f(tempx * 1.2, 0.35 * tempy, -tempz);
		glEnd();
		/// 
		/// top
		/// 
		glColor4f(0.4, 0.4, 0.4, 1.);
		//1
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(tempx *0.35, 0.1 * tempy, tempz);
			glTexCoord2d(0.,1);  glVertex3f(tempx ,0.1 * tempy, tempz);
			glTexCoord2d(1,1);  glVertex3f(tempx, 0.1 * tempy, -tempz);
			glTexCoord2d(1,0.);  glVertex3f(tempx * 0.35, 0.1 * tempy, -tempz);
		glEnd();
		//2
		glColor4f(0.3, 0.3, 0.3, 1.);
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(tempx *1.1,0.35* tempy, tempz);
			glTexCoord2d(0.,1);  glVertex3f(tempx * 1.2, 0.35 * tempy, tempz);
			glTexCoord2d(1,1);  glVertex3f(tempx * 1.2, 0.35 * tempy, -tempz);
			glTexCoord2d(1,0.);  glVertex3f(tempx * 1.1, 0.35 * tempy, -tempz);
		glEnd();
		/// 
		/// bot
		/// 
		glColor4f(0.4, 0.4, 0.4, 1.);
		//1
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(tempx *0.35, -0.35 * tempy, tempz);
			glTexCoord2d(0.,1);  glVertex3f(tempx , -0.1 * tempy, tempz);
			glTexCoord2d(1,1);  glVertex3f(tempx, -0.1 * tempy, -tempz);
			glTexCoord2d(1,0.);  glVertex3f(tempx * 0.35, -0.35 * tempy, -tempz);
		glEnd();
		//2
		glColor4f(0.3, 0.3, 0.3, 1.);
		glBegin(GL_POLYGON);
			glTexCoord2d(0.,0.);  glVertex3f(tempx , 0.1 * tempy, tempz);
			glTexCoord2d(0.,1);  glVertex3f(tempx * 1.05, -0.1 * tempy, tempz);
			glTexCoord2d(1,1);  glVertex3f(tempx * 1.05, -0.1 * tempy, -tempz);
			glTexCoord2d(1,0.);  glVertex3f(tempx, 0.1 * tempy, -tempz);
		glEnd();
		glDisable(GL_TEXTURE_2D);
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
		float tempx = xLen * 0.1, tempy = xLen * 0.1, tempz = zLen * 0.05;
		glTranslatef(0., 0.5 * yLen+0.1*zLen,0.);
		/// 
		/// Rotator - FRONT
		/// 
		glRotatef(-90., 1., 0., 0.);
		glColor4f(0.4, 0.4, 0.4, 1.);
		drawrotator(tempx, tempy, tempz);
		glTranslatef(0., 0.,tempz * 2.5);
		//rotator 2 is the start of spin
		glRotatef(topwingrotationangle, 0., 0., 1.);
		drawrotator(tempx/4., tempy/4., tempz*4.);
		glTranslatef(0.,0., tempz * 2.5);
		drawrotator(tempx/2., tempy/2., tempz);


		/// <summary>
		/// BLADES
		/// </summary>
		drawblade(0.25 * tempx, 5. * tempy, 0.12 * tempz);
		glRotatef(120, 0., 0., 1.);
		drawblade(0.25 * tempx, 5. * tempy, 0.12 * tempz);
		glRotatef(120, 0., 0., 1.);
		drawblade(0.25 * tempx, 5. * tempy, 0.12 * tempz);
		//reset position
		glRotatef(-240., 0., 0., 1.);
		glRotatef(-topwingrotationangle, 0., 0., 1.);
		glTranslatef(0.,0., -tempz * 5.);
		glRotatef(90, 1., 0., 0.);
		glTranslatef(0., -0.5 * yLen - 0.1 * zLen,0.);
	}
	else if (type._Equal("cargo")) {

	}
	else if (type._Equal("fighter")) {

	}
	if (type._Equal("ghost")) {

	}
}
void Aircraft::drawrotator(float tempx, float tempy, float tempz) {
	glBindTexture(GL_TEXTURE_2D, metal);

	glColor4f(0.4, 0.4, 0.4, 1.);
	//1
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);   glVertex3f(-tempx * 0.5, 0.16 * tempy, tempz);
	glTexCoord2d(0, 1);   glVertex3f(-tempx * 0.16, 0.5 * tempy, tempz);
	glTexCoord2d(1, 1);   glVertex3f(0.16 * tempx, 0.5 * tempy, tempz);
	glTexCoord2d(1, 0);   glVertex3f(0.5 * tempx, 0.16 * tempy, tempz);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);   glVertex3f(tempx * 0.5, -0.16 * tempy, tempz);
	glTexCoord2d(0, 1);   glVertex3f(tempx * 0.16, -0.5 * tempy, tempz);
	glTexCoord2d(1, 1);   glVertex3f(-tempx * 0.16, -0.5 * tempy, tempz);
	glTexCoord2d(1, 0);   glVertex3f(-tempx * 0.5, -0.16 * tempy, tempz);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);   glVertex3f(tempx * 0.5, -0.16 * tempy, tempz);
	glTexCoord2d(0, 1);   glVertex3f(tempx * 0.5, 0.16 * tempy, tempz);
	glTexCoord2d(1, 1);   glVertex3f(-tempx * 0.5, 0.16 * tempy, tempz);
	glTexCoord2d(1, 0);   glVertex3f(-tempx * 0.5, -0.16 * tempy, tempz);
	glEnd();
	/// 
	/// Rotator - back
	/// 
	//1
	tempz = -tempz;
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);   glVertex3f(-tempx * 0.5, 0.16 * tempy, tempz);
	glTexCoord2d(0, 1);   glVertex3f(-tempx * 0.16, 0.5 * tempy, tempz);
	glTexCoord2d(1, 1);   glVertex3f(0.16 * tempx, 0.5 * tempy, tempz);
	glTexCoord2d(1, 0);   glVertex3f(0.5 * tempx, 0.16 * tempy, tempz);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);   glVertex3f(tempx * 0.5, -0.16 * tempy, tempz);
	glTexCoord2d(0, 1);   glVertex3f(tempx * 0.5, 0.16 * tempy, tempz);
	glTexCoord2d(1, 1);   glVertex3f(-tempx * 0.5, 0.16 * tempy, tempz);
	glTexCoord2d(1, 0);   glVertex3f(-tempx * 0.5, -0.16 * tempy, tempz);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);   glVertex3f(tempx * 0.5, -0.16 * tempy, tempz);
	glTexCoord2d(0, 1);   glVertex3f(tempx * 0.16, -0.5 * tempy, tempz);
	glTexCoord2d(1, 1);   glVertex3f(-tempx * 0.16, -0.5 * tempy, tempz);
	glTexCoord2d(1, 0);   glVertex3f(-tempx * 0.5, -0.16 * tempy, tempz);
	glEnd();
	tempz = -tempz;
	/// 
	/// Rotator - left
	/// 
	//1
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);    glVertex3f(-tempx * 0.5, 0.16 * tempy, tempz);
	glTexCoord2d(0, 1);    glVertex3f(-tempx * 0.5, -0.16 * tempy, tempz);
	glTexCoord2d(1, 1);    glVertex3f(-tempx * 0.5, -0.16 * tempy, -tempz);
	glTexCoord2d(1, 0);    glVertex3f(-tempx * 0.5, 0.16 * tempy, -tempz);
	glEnd();
	/// 
	/// Rotator - right
	/// 
	//1
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);   glVertex3f(tempx * 0.5, 0.16 * tempy, tempz);
	glTexCoord2d(0, 1);   glVertex3f(tempx * 0.5, -0.16 * tempy, tempz);
	glTexCoord2d(1, 1);   glVertex3f(tempx * 0.5, -0.16 * tempy, -tempz);
	glTexCoord2d(1, 0);   glVertex3f(tempx * 0.5, 0.16 * tempy, -tempz);
	glEnd();
	/// 
	/// Rotator - top
	/// 
	//1
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);   glVertex3f(-tempx * 0.5, 0.16 * tempy, tempz);
	glTexCoord2d(0, 1);   glVertex3f(-tempx * 0.16, 0.5 * tempy, tempz);
	glTexCoord2d(1, 1);   glVertex3f(-tempx * 0.16, 0.5 * tempy, -tempz);
	glTexCoord2d(1, 0);   glVertex3f(-tempx * 0.5, 0.16 * tempy, -tempz);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);   glVertex3f(0.16 * tempx, 0.5 * tempy, tempz);
	glTexCoord2d(0, 1);   glVertex3f(-tempx * 0.16, 0.5 * tempy, tempz);
	glTexCoord2d(1, 1);   glVertex3f(-tempx * 0.16, 0.5 * tempy, -tempz);
	glTexCoord2d(1, 0);   glVertex3f(0.16 * tempx, 0.5 * tempy, -tempz);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);   glVertex3f(0.5 * tempx, 0.16 * tempy, tempz);
	glTexCoord2d(0, 1);   glVertex3f(0.16 * tempx, 0.5 * tempy, tempz);
	glTexCoord2d(1, 1);   glVertex3f(0.16 * tempx, 0.5 * tempy, -tempz);
	glTexCoord2d(1, 0);   glVertex3f(0.5 * tempx, 0.16 * tempy, -tempz);
	glEnd();
	/// 
	/// Rotator - bot
	/// 
	//1
	tempy = -tempy;
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);   glVertex3f(-tempx * 0.5, 0.16 * tempy, tempz);
	glTexCoord2d(0, 1);   glVertex3f(-tempx * 0.16, 0.5 * tempy, tempz);
	glTexCoord2d(1, 1);   glVertex3f(-tempx * 0.16, 0.5 * tempy, -tempz);
	glTexCoord2d(1, 0);   glVertex3f(-tempx * 0.5, 0.16 * tempy, -tempz);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);   glVertex3f(0.16 * tempx, 0.5 * tempy, tempz);
	glTexCoord2d(0, 1);   glVertex3f(-tempx * 0.16, 0.5 * tempy, tempz);
	glTexCoord2d(1, 1);   glVertex3f(-tempx * 0.16, 0.5 * tempy, -tempz);
	glTexCoord2d(1, 0);   glVertex3f(0.16 * tempx, 0.5 * tempy, -tempz);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);   glVertex3f(0.5 * tempx, 0.16 * tempy, tempz);
	glTexCoord2d(0, 1);   glVertex3f(0.16 * tempx, 0.5 * tempy, tempz);
	glTexCoord2d(1, 1);   glVertex3f(0.16 * tempx, 0.5 * tempy, -tempz);
	glTexCoord2d(1, 0);   glVertex3f(0.5 * tempx, 0.16 * tempy, -tempz);
	glEnd();
	tempy = -tempy;
	glDisable(GL_TEXTURE_2D);
}
void Aircraft::drawbackwings() {
	if (type._Equal("helicopter")) {
		float tempx = xLen * 0.07, tempy = xLen * 0.07, tempz = zLen * 0.1;
		glTranslatef(1.15 * 0.7 * xLen, 0.35 * yLen, -zLen * 0.3);
		/// 
		/// Rotator - FRONT
		/// 
		glRotatef(backwingrotationangle, 0., 0., 1.);
		glColor4f(0.4, 0.4, 0.4, 1.);
		drawrotator(tempx, tempy, tempz);
		/// <summary>
		/// BLADES
		/// </summary>
		drawblade( 0.5*tempx, 5. * tempy, 0.25 * tempz);
		glRotatef(120, 0., 0., 1.);
		drawblade( 0.5*tempx, 5. * tempy, 0.25 * tempz);
		glRotatef(120, 0., 0., 1.);
		drawblade( 0.5*tempx, 5. * tempy, 0.25 * tempz);
		glRotatef(-240., 0., 0., 1.);
		glRotatef(-backwingrotationangle, 0., 0., 1.);
		glTranslatef(-1.15 * 0.7 * xLen, -0.35 * yLen, zLen * 0.3);
		
	}
	else if (type._Equal("cargo")) {

	}
	else if (type._Equal("fighter")) {

	}
	if (type._Equal("ghost")) {

	}
}
void Aircraft::drawblade(float x , float y,float z) {
	glColor4f(1., 1., 1., 1.);
	glBindTexture(GL_TEXTURE_2D, alum);
	glEnable(GL_TEXTURE_2D);
	//front
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);   glVertex3f(-x * 0.5, -0.5 * y, 0);
	glTexCoord2d(0, 1);   glVertex3f(-x * 0.5, 0.5 * y, 0);
	glTexCoord2d(1, 1);   glVertex3f(0., 0.5 * y, z * 0.5);
	glTexCoord2d(1, 0);   glVertex3f(0., -0.5 * y, z * 0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);   glVertex3f(0., -0.5 * y, z * 0.5);
	glTexCoord2d(0, 1);   glVertex3f(0., 0.5 * y, z * 0.5);
	glTexCoord2d(1, 1);   glVertex3f(x * 0.5, 0.5 * y, 0);
	glTexCoord2d(1, 0);   glVertex3f(x * 0.5, -0.5 * y, 0);
	glEnd();
	//back
	z = -z;
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);   glVertex3f(-x * 0.5, -0.5 * y, 0);
	glTexCoord2d(0, 1);   glVertex3f(-x * 0.5, 0.5 * y, 0);
	glTexCoord2d(1, 1);   glVertex3f(0., 0.5 * y, z * 0.5);
	glTexCoord2d(1, 0);   glVertex3f(0., -0.5 * y, z * 0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);   glVertex3f(0., -0.5 * y, z * 0.5);
	glTexCoord2d(0, 1);   glVertex3f(0., 0.5 * y, z * 0.5);
	glTexCoord2d(1, 1);   glVertex3f(x * 0.5, 0.5 * y, 0);
	glTexCoord2d(1, 0);   glVertex3f(x * 0.5, -0.5 * y, 0);
	glEnd();
	//top
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);   glVertex3f(-x * 0.5, 0.5 * y, 0);
	glTexCoord2d(0, 1);   glVertex3f(0., 0.5 * y, z * 0.5);
	glTexCoord2d(1, 1);   glVertex3f(x * 0.5, 0.5 * y, 0);
	glTexCoord2d(1, 0);   glVertex3f(0., 0.5 * y, -z * 0.5);
	glEnd();
	//bot
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);   glVertex3f(-x * 0.5, -0.5 * y, 0);
	glTexCoord2d(0, 1);   glVertex3f(0., -0.5 * y, z * 0.5);
	glTexCoord2d(1, 1);   glVertex3f(x * 0.5, -0.5 * y, 0);
	glTexCoord2d(1, 0);   glVertex3f(0., -0.5 * y, -z * 0.5);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
void Aircraft::drawrockets() {
	if (type._Equal("helicopter")) {

	}
	else if (type._Equal("cargo")) {
		float tempx = xLen * 0.7, tempy = yLen * 0.5, tempz = zLen * 0.25;
		glColor4f(0.2, 0.2, 0.2, 1.);
		glRotatef(90., 0., 1., 0.);
		gluCylinder(gluNewQuadric(), 0., tempy * 0.5, tempx * 0.02, 20, 20);
		glRotatef(-90., 0., 1., 0.);
		glTranslatef(tempx * 0.02, 0., 0.);
		glRotatef(90., 0., 1., 0.);
		glColor4f(0.4, 0.4, 0.4, 1.);
		gluCylinder(gluNewQuadric(), tempy * 0.5, tempy, tempx * 0.2, 20, 10);
		glRotatef(-90., 0., 1., 0.);
		glTranslatef(tempx * 0.2, 0., 0.);
		glRotatef(90., 0., 1., 0.);
		glColor4f(0.6, 0.6, 0.6, 1.);
		gluCylinder(gluNewQuadric(), tempy, tempy, tempx * 0.5, 20, 10);
		glRotatef(-90., 0., 1., 0.);
		glTranslatef(tempx * 0.5, 0., 0.);
		glRotatef(90., 0., 1., 0.);
		glColor4f(0.8, 0.8, 0.8, 1.);
		gluCylinder(gluNewQuadric(), tempy, 0, tempx * 0.1, 20, 10);
		glRotatef(-90., 0., 1., 0.);
	}
	else if (type._Equal("fighter")) {
		float tempx = xLen * 0.7, tempy = yLen * 0.5, tempz = zLen * 0.25;
		glColor4f(0.2, 0.2, 0.2, 1.);
		glRotatef(90., 0., 1., 0.);
		gluCylinder(gluNewQuadric(), 0., tempy * 0.5, tempx * 0.02, 20, 20);
		glRotatef(-90., 0., 1., 0.);
		glTranslatef(tempx * 0.02, 0., 0.);
		glRotatef(90., 0., 1., 0.);
		glColor4f(0.4, 0.4, 0.4, 1.);
		gluCylinder(gluNewQuadric(), tempy * 0.5, tempy, tempx * 0.2, 20, 10);
		glRotatef(-90., 0., 1., 0.);
		glTranslatef(tempx * 0.2, 0., 0.);
		glRotatef(90., 0., 1., 0.);
		glColor4f(0.6, 0.6, 0.6, 1.);
		gluCylinder(gluNewQuadric(), tempy, tempy, tempx * 0.5, 20, 10);
		glRotatef(-90., 0., 1., 0.);
		glTranslatef(tempx * 0.5, 0., 0.);
		glRotatef(90., 0., 1., 0.);
		glColor4f(0.8, 0.8, 0.8, 1.);
		gluCylinder(gluNewQuadric(), tempy, 0, tempx * 0.1, 20, 10);
		glRotatef(-90., 0., 1., 0.);
	}
	if (type._Equal("ghost")) {
		float tempx = xLen * 0.7, tempy = yLen * 0.5, tempz = zLen * 0.25;
		glColor4f(0.2, 0.2, 0.2, 1.);
		glRotatef(90., 0., 1., 0.);
		gluCylinder(gluNewQuadric(), 0., tempy * 0.5, tempx * 0.02, 20, 20);
		glRotatef(-90., 0., 1., 0.);
		glTranslatef(tempx * 0.02, 0., 0.);
		glRotatef(90., 0., 1., 0.);
		glColor4f(0.4, 0.4, 0.4, 1.);
		gluCylinder(gluNewQuadric(), tempy * 0.5, tempy, tempx * 0.2, 20, 10);
		glRotatef(-90., 0., 1., 0.);
		glTranslatef(tempx * 0.2, 0., 0.);
		glRotatef(90., 0., 1., 0.);
		glColor4f(0.6, 0.6, 0.6, 1.);
		gluCylinder(gluNewQuadric(), tempy, tempy, tempx * 0.5, 20, 10);
		glRotatef(-90., 0., 1., 0.);
		glTranslatef(tempx * 0.5, 0., 0.);
		glRotatef(90., 0., 1., 0.);
		glColor4f(0.8, 0.8, 0.8, 1.);
		gluCylinder(gluNewQuadric(), tempy, 0, tempx * 0.1, 20, 10);
		glRotatef(-90., 0., 1., 0.);
	}
}
void Aircraft::drawwheels() {
	//helicopter
	if (type._Equal("helicopter")) {
		float tempx = xLen * 0.07, tempy = xLen * 0.07, tempz = zLen * 0.1;
		glTranslatef(-xLen/8., -0.425 * yLen, -zLen * 0.35);
		/// 
		/// Rotator - FRONT
		/// 
		glRotatef(90., 1., 0., 0.);
		glColor4f(0.15, 0.15, 0.15, 1.);
		drawrotator(tempx/2., tempx/2., 0.05 * yLen);//just needing the shape
		glTranslatef(xLen / 4., 0., 0.);
		drawrotator(tempx/2., tempx/2., 0.05 * yLen);//just needing the shape
		glTranslatef(-xLen / 8., 0., 0.035*yLen);
		drawrotator(xLen*0.6, tempx*0.7, 0.02 * yLen);//just needing the shape big stand
		//reset
		glRotatef(-90., 1., 0., 0.);
		glTranslatef(0., 0.46 * yLen, zLen * 0.35);


		glTranslatef(-xLen / 8., -0.425 * yLen, zLen * 0.35);
		glRotatef(90., 1., 0., 0.);
		glColor4f(0.15, 0.15, 0.15, 1.);
		drawrotator(tempx / 2., tempx / 2., 0.05 * yLen);//just needing the shape
		glTranslatef(xLen / 4., 0., 0.);
		drawrotator(tempx / 2., tempx / 2., 0.05 * yLen);//just needing the shape
		glTranslatef(-xLen / 8., 0., 0.035 * yLen);
		drawrotator(xLen * 0.6, tempx * 0.7, 0.02 * yLen);//just needing the shape big stand
		//reset
		glRotatef(-90., 1., 0., 0.);
		glTranslatef(0., 0.46 * yLen, -zLen * 0.35);

		
	}
	else if (type._Equal("cargo")) {

	}
	else if (type._Equal("fighter")) {

	}
	if (type._Equal("ghost")) {

	}
}