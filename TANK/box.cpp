#include "box.h"
box::box(float x, float y, float z) : GameObject()  {
	xLen = x;
	yLen = y; 
	zLen = z; 
	xoffset = 0; yoffset = 0; zoffset = 0;
	iscolliding = false; 
	type = "box";
	inrange = false;
}
void box::spawn() {
	glLoadIdentity(); 
	glPopMatrix();  
	glPushMatrix();
	glTranslatef(0.+xoffset, yLen * 0.5+yoffset, 0.+zoffset);
	drawbox();
}
void box::setposition(float x, float y, float z) {
	xoffset = x; yoffset = y;   zoffset = z;
}
void box::movex(float offset) {
	xoffset += offset;
}
void box::movey(float offset) {
	yoffset += offset;
}
void box::movez(float offset) {
	zoffset += offset;
}
std::vector<float> box::getborder() {
	//left,right,top ,bot , front,back
	std::vector<float> temp; 
	temp.push_back(-xLen/2.+xoffset);
	temp.push_back(xLen/2.+xoffset);
	temp.push_back(yLen+yoffset);
	temp.push_back(0.+yoffset);
	temp.push_back(-zLen/2.+zoffset);
	temp.push_back(zLen/2.+zoffset);
	return temp; 
}
void box::drawbox() {
	float texmax = 1.;
	if(inrange) glBindTexture(GL_TEXTURE_2D, redboxtx);
	else 	glBindTexture(GL_TEXTURE_2D, boxtx);

	glColor4f(1., 1., 1., 1.);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);   //Vorderseite
	glTexCoord2f(0., 0.);
	glVertex3f(-xLen / 2.0f, -yLen / 2.0f, +zLen / 2.0f);
	glTexCoord2f(texmax, 0.);
	glVertex3f(+xLen / 2.0f, -yLen / 2.0f, +zLen / 2.0f);
	glTexCoord2f(texmax, texmax);
	glVertex3f(+xLen / 2.0f, +yLen / 2.0f, +zLen / 2.0f);
	glTexCoord2f(0., texmax);
	glVertex3f(-xLen / 2.0f, +yLen / 2.0f, +zLen / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Rechte Seite
	glTexCoord2f(0., texmax);
	glVertex3f(+xLen / 2.0f, -yLen / 2.0f, +zLen / 2.0f);
	glTexCoord2f(0., 0.);
	glVertex3f(+xLen / 2.0f, -yLen / 2.0f, -zLen / 2.0f);
	glTexCoord2f(texmax, 0.);
	glVertex3f(+xLen / 2.0f, +yLen / 2.0f, -zLen / 2.0f);
	glTexCoord2f(texmax, texmax);
	glVertex3f(+xLen / 2.0f, +yLen / 2.0f, +zLen / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Rueckseite
	glTexCoord2f(texmax, 0.);
	glVertex3f(+xLen / 2.0f, +yLen / 2.0f, -zLen / 2.0f);
	glTexCoord2f(texmax, texmax);
	glVertex3f(+xLen / 2.0f, -yLen / 2.0f, -zLen / 2.0f);
	glTexCoord2f(0., texmax);
	glVertex3f(-xLen / 2.0f, -yLen / 2.0f, -zLen / 2.0f);
	glTexCoord2f(0., 0.);
	glVertex3f(-xLen / 2.0f, +yLen / 2.0f, -zLen / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Linke Seite
	glTexCoord2f(0., texmax);
	glVertex3f(-xLen / 2.0f, +yLen / 2.0f, -zLen / 2.0f);
	glTexCoord2f(texmax, texmax);
	glVertex3f(-xLen / 2.0f, -yLen / 2.0f, -zLen / 2.0f);
	glTexCoord2f(texmax, 0.);
	glVertex3f(-xLen / 2.0f, -yLen / 2.0f, +zLen / 2.0f);
	glTexCoord2f(0., 0.);
	glVertex3f(-xLen / 2.0f, +yLen / 2.0f, +zLen / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Deckflaeche
	glTexCoord2f(0., texmax);
	glVertex3f(-xLen / 2.0f, +yLen / 2.0f, +zLen / 2.0f);
	glTexCoord2f(texmax, texmax);
	glVertex3f(+xLen / 2.0f, +yLen / 2.0f, +zLen / 2.0f);
	glTexCoord2f(texmax, 0.);
	glVertex3f(+xLen / 2.0f, +yLen / 2.0f, -zLen / 2.0f);
	glTexCoord2f(0., 0.);
	glVertex3f(-xLen / 2.0f, +yLen / 2.0f, -zLen / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Bodenflaeche
	glTexCoord2f(0., texmax);
	glVertex3f(-xLen / 2.0f, -yLen / 2.0f, -zLen / 2.0f);
	glTexCoord2f(texmax, texmax);
	glVertex3f(+xLen / 2.0f, -yLen / 2.0f, -zLen / 2.0f);
	glTexCoord2f(texmax, 0.);
	glVertex3f(+xLen / 2.0f, -yLen / 2.0f, +zLen / 2.0f);
	glTexCoord2f(0., 0.);
	glVertex3f(-xLen / 2.0f, -yLen / 2.0f, +zLen / 2.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}