#include "Tent.h"
Tent::Tent() {
	type = "tent";
	xoffset = 0; yoffset = 0; zoffset = 0;
	usable = false;
	inrange = false;
}
Tent::Tent(float x, float y, float z)  {
	type = "tent";
	xLen = x; 
	yLen = y; 
	zLen = z;
	xoffset = 0; yoffset = 0; zoffset = 0;
	usable = false;
	inrange = false;
}

void Tent::spawn() {
	glLoadIdentity();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0. + xoffset, yLen * 0.3 + yoffset, 0. + zoffset);
	drawbot();
	//translation
	glTranslatef(0., yLen * 0.5, 0.);//0.2+0.3
	drawtop();
	//translation
	glTranslatef(0., -yLen * 0.3, 0.);//0.2+0.3
	drawropes();
}
void Tent::drawbot() {
	float tempx=xLen, tempy=0.6*yLen, tempz=zLen; 
	float texmax = 1.;
	//front consisting from 3 parts
	glBindTexture(GL_TEXTURE_2D, green);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
		glColor4f(0.098, 0.603, 0.388, 1.);
		glTexCoord2d(0., 0); glVertex3f(-tempx / 2., -tempy / 2., tempz / 2.);
		glTexCoord2d(0., texmax); glVertex3f(-tempx / 2., tempy / 2., tempz / 2.);
		glTexCoord2d(texmax,0. ); glVertex3f(-tempx / 8., tempy / 2., tempz / 2.);
		glTexCoord2d(texmax, texmax); glVertex3f(-tempx / 8., -tempy / 2., tempz / 2.);
	glEnd();
	glBegin(GL_POLYGON);
		glTexCoord2d(0., 0.); glVertex3f(tempx / 2., tempy / 2., tempz / 2.);
		glTexCoord2d(0., texmax); glVertex3f(tempx / 2., -tempy / 2., tempz / 2.);
		glTexCoord2d(texmax, texmax); glVertex3f(tempx / 8., -tempy / 2., tempz / 2.);
		glTexCoord2d(texmax, 0.); glVertex3f(tempx / 8., tempy / 2., tempz / 2.);
	glEnd();
	glBegin(GL_POLYGON);
		glTexCoord2d(0., 0.); glVertex3f(-tempx / 8., (tempy / 2.) * 0.75, tempz / 2.);
		glTexCoord2d(0., texmax); glVertex3f(-tempx / 8., tempy / 2., tempz / 2.);
		glTexCoord2d(texmax, texmax); glVertex3f(tempx / 8., tempy / 2., tempz / 2.);
		glTexCoord2d(texmax, 0.); glVertex3f(tempx / 8., (tempy / 2.) * 0.75, tempz / 2.);
	glEnd();
		//back consisting from 3 parts
	tempz = -tempz; //invert z 
	glBegin(GL_POLYGON);
	glColor4f(0.098, 0.603, 0.388, 1.);
		glTexCoord2d(0., texmax); 	glVertex3f(-tempx / 2., -tempy / 2., tempz / 2.);
		glTexCoord2d(texmax, texmax); 	glVertex3f(-tempx / 2., tempy / 2., tempz / 2.);
		glTexCoord2d(texmax, 0.); 	glVertex3f(-tempx / 8., tempy / 2., tempz / 2.);
		glTexCoord2d(0., 0.); 	glVertex3f(-tempx / 8., -tempy / 2., tempz / 2.);
	glEnd();
	glBegin(GL_POLYGON);
		glTexCoord2d(0., 0.); 	glVertex3f(tempx / 2., tempy / 2., tempz / 2.);
		glTexCoord2d(0., texmax); 	glVertex3f(tempx / 2., -tempy / 2., tempz / 2.);
		glTexCoord2d(texmax, texmax); 	glVertex3f(tempx / 8., -tempy / 2., tempz / 2.);
		glTexCoord2d(texmax, 0.); 	glVertex3f(tempx / 8., tempy / 2., tempz / 2.);
	glEnd();
	glBegin(GL_POLYGON);
		glTexCoord2d(0., 0.); 	glVertex3f(-tempx / 8., (tempy / 2.) * 0.75, tempz / 2.);
		glTexCoord2d(0., texmax); 	glVertex3f(-tempx / 8., tempy / 2., tempz / 2.);
		glTexCoord2d(texmax, texmax); 	glVertex3f(tempx / 8., tempy / 2., tempz / 2.);
		glTexCoord2d(texmax, 0.); 	glVertex3f(tempx / 8., (tempy / 2.) * 0.75, tempz / 2.);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	tempz = -tempz;//reset
		//left consisting from 4 parts
	glBindTexture(GL_TEXTURE_2D, blue);
	glEnable(GL_TEXTURE_2D); 
	glBegin(GL_POLYGON);//1
	glColor4f(0.098, 0.603, 0.388, 1.);
		glTexCoord2d(0., 0.); glVertex3f(-tempx / 2., tempy*0.4, -tempz / 2.);
		glTexCoord2d(0., texmax); glVertex3f(-tempx / 2., tempy / 2., -tempz / 2.);
		glTexCoord2d(texmax, texmax); 	glVertex3f(-tempx / 2., tempy / 2., tempz / 2.);
		glTexCoord2d(texmax, 0.); 	glVertex3f(-tempx / 2., tempy*0.4, tempz / 2.);
	glEnd();
	glBegin(GL_POLYGON);//2
		glTexCoord2d(0., 0.); 	glVertex3f(-tempx / 2., tempy * 0.1, -tempz / 2.);
		glTexCoord2d(0., texmax); 	glVertex3f(-tempx / 2., tempy * 0.4, -tempz / 2.);
		glTexCoord2d(texmax, texmax); 	glVertex3f(-tempx / 2., tempy * 0.4, -tempz*0.1);
		glTexCoord2d(texmax, 0.); 	glVertex3f(-tempx / 2., tempy * 0.1, -tempz*0.1);
	glEnd();
	glBegin(GL_POLYGON);//3
		glTexCoord2d(0., 0.); 	glVertex3f(-tempx / 2., tempy * 0.1, tempz*0.1);
		glTexCoord2d(0., texmax); 	glVertex3f(-tempx / 2., tempy * 0.4, tempz*0.1);
		glTexCoord2d(texmax, texmax); 	glVertex3f(-tempx / 2., tempy * 0.4, tempz / 2.);
		glTexCoord2d(texmax, 0.); 	glVertex3f(-tempx / 2., tempy * 0.1, tempz / 2.);
	glEnd();
	glBegin(GL_POLYGON);//4
		glTexCoord2d(0., 0.); 	glVertex3f(-tempx / 2., tempy*0.1, -tempz / 2.);
		glTexCoord2d(0., texmax); 	glVertex3f(-tempx / 2., -tempy / 2., -tempz / 2.);
		glTexCoord2d(texmax, texmax); 	glVertex3f(-tempx / 2., -tempy / 2., tempz / 2.);
		glTexCoord2d(texmax, 0.); 	glVertex3f(-tempx / 2., tempy*0.1, tempz / 2.);
	glEnd();
		//left consisting from 4 parts
	tempx = -tempx; //invert
	glBegin(GL_POLYGON);//1
	glColor4f(0.098, 0.603, 0.388, 1.);
		glTexCoord2d(0., 0.); glVertex3f(-tempx / 2., tempy*0.4, -tempz / 2.);
		glTexCoord2d(0., texmax); 	glVertex3f(-tempx / 2., tempy / 2., -tempz / 2.);
		glTexCoord2d(texmax, texmax); 	glVertex3f(-tempx / 2., tempy / 2., tempz / 2.);
		glTexCoord2d(texmax, 0.); glVertex3f(-tempx / 2., tempy*0.4, tempz / 2.);
	glEnd();
	glBegin(GL_POLYGON);//2
		glTexCoord2d(0., 0.); 	glVertex3f(-tempx / 2., tempy * 0.1, -tempz / 2.);
		glTexCoord2d(0., texmax); 	glVertex3f(-tempx / 2., tempy * 0.4, -tempz / 2.);
		glTexCoord2d(texmax, texmax); 	glVertex3f(-tempx / 2., tempy * 0.4, -tempz*0.1);
		glTexCoord2d(0., texmax); 	glVertex3f(-tempx / 2., tempy * 0.1, -tempz*0.1);
	glEnd();
	glBegin(GL_POLYGON);//3
		glTexCoord2d(0., 0.); 	glVertex3f(-tempx / 2., tempy * 0.1, tempz*0.1);
		glTexCoord2d(0., texmax); 	glVertex3f(-tempx / 2., tempy * 0.4, tempz*0.1);
		glTexCoord2d(texmax, texmax); 	glVertex3f(-tempx / 2., tempy * 0.4, tempz / 2.);
		glTexCoord2d(texmax, 0.); 	glVertex3f(-tempx / 2., tempy * 0.1, tempz / 2.);
	glEnd();
	glBegin(GL_POLYGON);//4
		glTexCoord2d(0., 0.); 	glVertex3f(-tempx / 2., tempy*0.1, -tempz / 2.);
		glTexCoord2d(0., texmax); 	glVertex3f(-tempx / 2., -tempy / 2., -tempz / 2.);
		glTexCoord2d(texmax, texmax); 	glVertex3f(-tempx / 2., -tempy / 2., tempz / 2.);
		glTexCoord2d(texmax, 0.); 	glVertex3f(-tempx / 2., tempy*0.1, tempz / 2.);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	tempx = -tempx;//reset

}
void Tent::drawtop() {
	float tempx = xLen, tempy = 0.4 * yLen, tempz = zLen;
	float texmax =1.;
		//side 1  consisting from 3 vert
	glBindTexture(GL_TEXTURE_2D,blue);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
		glColor4f(0.1, 0.7, 0.4, 1.);
		glTexCoord3d(0., 0., texmax); glVertex3f(-tempx / 2., -tempy / 2., tempz / 2.);
		glTexCoord3d(texmax/2., texmax, texmax/2.); glVertex3f(0., tempy / 2., 0.);
		glTexCoord3d(texmax, 0., texmax); glVertex3f(tempx / 2., -tempy / 2., tempz / 2.);
	glEnd();
		//side 2  consisting from 3 vert
	tempz = -tempz;//invert
	glBegin(GL_POLYGON);
		glTexCoord3d(0., 0., texmax); glVertex3f(-tempx / 2., -tempy / 2., tempz / 2.);
		glTexCoord3d(texmax/2., texmax, texmax/2.); glVertex3f(0, tempy / 2., 0.);
		glTexCoord3d(texmax, 0., texmax); glVertex3f(tempx / 2., -tempy / 2., tempz / 2.);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	tempz = -tempz;//reset
		//side 3  consisting from 3 vert
	glBindTexture(GL_TEXTURE_2D, green);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	glTexCoord3d(0., 0., texmax); glVertex3f(-tempx / 2., -tempy / 2., -tempz / 2.);
	glTexCoord3d(texmax / 2., texmax, texmax / 2.); glVertex3f(0., tempy / 2., 0.);
	glTexCoord3d(texmax, 0., texmax); glVertex3f(-tempx / 2., -tempy / 2., tempz / 2.);
	glEnd();
		//side 4  consisting from 3 vert
	tempx = -tempx;//invert
	glBegin(GL_POLYGON);
		glTexCoord3d(0., 0., texmax); glVertex3f(-tempx / 2., -tempy / 2., -tempz / 2.);
		glTexCoord3d(texmax / 2., texmax, texmax / 2.); glVertex3f(0., tempy / 2., 0.);
		glTexCoord3d(texmax, 0., texmax); glVertex3f(-tempx / 2., -tempy / 2., tempz / 2.);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	tempx = -tempx;//reset
}
void Tent::drawropes() {
	float tempx = xLen, tempy = yLen, tempz = zLen;
	glEnable(GL_LINE_SMOOTH);
	//front & back consisting from 3 ropes
	glLineWidth(3.);
	glColor4f(0., 0., 0., 1.);//black
	glBegin(GL_LINE_STRIP);
	 glVertex3f(0.,tempy/2.,0.);
	 glVertex3f(-tempx*0.5,tempy*0.1,tempz*0.5);
	 glVertex3f(-tempx*0.7, -tempy / 2., tempz*0.7);
	glEnd();
	glBegin(GL_LINE_STRIP);
	 glVertex3f(0.,tempy/2.,0.);
	 glVertex3f(0., tempy * 0.1, tempz * 0.5);
	 glVertex3f(0., -tempy / 2., tempz*0.7);
	glEnd();
	glBegin(GL_LINE_STRIP);
	 glVertex3f(0.,tempy/2.,0.);
	 glVertex3f(tempx * 0.5, tempy * 0.1, tempz * 0.5);
	 glVertex3f(tempx*0.7, -tempy / 2., tempz*0.7);
	glEnd();
	tempz = -tempz; //invert
	glBegin(GL_LINE_STRIP);
	 glVertex3f(0.,tempy/2.,0.);
	 glVertex3f(-tempx*0.5,tempy*0.1,tempz*0.5);
	 glVertex3f(-tempx*0.7, -tempy / 2., tempz*0.7);
	glEnd();
	glBegin(GL_LINE_STRIP);
	 glVertex3f(0.,tempy/2.,0.);
	 glVertex3f(0., tempy * 0.1, tempz * 0.5);
	 glVertex3f(0., -tempy / 2., tempz*0.7);
	glEnd();
	glBegin(GL_LINE_STRIP);
	 glVertex3f(0.,tempy/2.,0.);
	 glVertex3f(tempx * 0.5, tempy * 0.1, tempz * 0.5);
	 glVertex3f(tempx*0.7, -tempy / 2., tempz*0.7);
	glEnd();
	tempz = -tempz; //reset
	//left & right have 1 rope each
	glBegin(GL_LINE_STRIP);
	glVertex3f(0., tempy / 2., 0.);
	glVertex3f(-tempx * 0.5, tempy * 0.1, 0.);
	glVertex3f(-tempx * 0.7, -tempy / 2., 0.);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(0., tempy / 2., 0.);
	glVertex3f(tempx * 0.5, tempy * 0.1, 0.);
	glVertex3f(tempx*0.7, -tempy / 2., 0.);
	glEnd();
	glDisable(GL_LINE_SMOOTH);
}