#include "menuScene.h"
menuScene::menuScene() {
	cursorposition = 4;
}

menuScene::menuScene(std::string n, std::string t ){
	name = n; type = t;
	if (name._Equal("main")) nrofbuttons = 5;
	else if (name._Equal("pause")) nrofbuttons = 3;
	else nrofbuttons = 1;
	cursorposition = nrofbuttons;
}
void menuScene::display() {
	glLoadIdentity(); 
	glPopMatrix(); 
	glPushMatrix();
	drawbackground(); 
	drawbuttons();
	drawcursor();
}
void menuScene::drawbackground() {
	if (name._Equal("main")) {
		glBindTexture(GL_TEXTURE_2D, menubg);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
			glTexCoord2d(0., 0.); glVertex3f(-0.95, -0.7, -1.01);
			glTexCoord2d(0., 1.); glVertex3f(-0.95, 0.7, -1.01);
			glTexCoord2d(1., 1.); glVertex3f(0.95, 0.7, -1.01);
			glTexCoord2d(1., 0.); glVertex3f(0.95, -0.7, -1.01);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	else if (name._Equal("pause")) {
		glBindTexture(GL_TEXTURE_2D, pausebg);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2d(0., 0.); glVertex3f(-0.95, -0.7, -1.01);
		glTexCoord2d(0., 1.); glVertex3f(-0.95, 0.7, -1.01);
		glTexCoord2d(1., 1.); glVertex3f(0.95, 0.7, -1.01);
		glTexCoord2d(1., 0.); glVertex3f(0.95, -0.7, -1.01);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	else {
		glBindTexture(GL_TEXTURE_2D, deathbg);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2d(0., 0.); glVertex3f(-0.95, -0.7, -1.01);
		glTexCoord2d(0., 1.); glVertex3f(-0.95, 0.7, -1.01);
		glTexCoord2d(1., 1.); glVertex3f(0.95, 0.7, -1.01);
		glTexCoord2d(1., 0.); glVertex3f(0.95, -0.7, -1.01);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
}
void menuScene::drawbuttons() {
	if (name._Equal("main")) {
		//quit button		
		glBindTexture(GL_TEXTURE_2D, quit);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2d(0., 0.); glVertex3f(-0.95, -0.7, -1);
		glTexCoord2d(0., 1.); glVertex3f(-0.95, -0.7 + (float)(1.4 / 5), -1);
		glTexCoord2d(1., 1.); glVertex3f(0.95, -0.7 + (float)(1.4 / 5), -1);
		glTexCoord2d(1., 0.); glVertex3f(0.95, -0.7, -1);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		//options button		
		glBindTexture(GL_TEXTURE_2D, options);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2d(0., 0.); glVertex3f(-0.95, -0.7 + (float)(1.4 / 5), -1.);
		glTexCoord2d(0., 1.); glVertex3f(-0.95, -0.7 +2.* (float)(1.4 / 5), -1.);
		glTexCoord2d(1., 1.); glVertex3f(0.95, -0.7 + 2.*(float)(1.4 / 5),-1.);
		glTexCoord2d(1., 0.); glVertex3f(0.95, -0.7 + (float)(1.4 / 5), -1.);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		//credits button		
		glBindTexture(GL_TEXTURE_2D, credits);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2d(0., 0.); glVertex3f(-0.95, -0.7 + 2. * (float)(1.4 / 5), -1.);
		glTexCoord2d(0., 1.); glVertex3f(-0.95, -0.7 +3.* (float)(1.4 / 5), -1.);
		glTexCoord2d(1., 1.); glVertex3f(0.95, -0.7 + 3.*(float)(1.4 / 5), -1.);
		glTexCoord2d(1., 0.); glVertex3f(0.95, -0.7 + 2. * (float)(1.4 / 5), -1.);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		//controls button		
		glBindTexture(GL_TEXTURE_2D, controls);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2d(0., 0.); glVertex3f(-0.95, -0.7 + 3. * (float)(1.4 / 5), -1.);
		glTexCoord2d(0., 1.); glVertex3f(-0.95, -0.7 + 4.*(float)(1.4 / 5), -1.);
		glTexCoord2d(1., 1.); glVertex3f(0.95, -0.7 + 4.*(float)(1.4 / 5), -1.);
		glTexCoord2d(1., 0.); glVertex3f(0.95, -0.7 + 3. * (float)(1.4 / 5), -1.);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		//play button		
		glBindTexture(GL_TEXTURE_2D, play);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2d(0., 0.); glVertex3f(-0.95, -0.7 + 4. * (float)(1.4 / 5), -1.);
		glTexCoord2d(0., 1.); glVertex3f(-0.95, 0.7, -1.);
		glTexCoord2d(1., 1.); glVertex3f(0.95, 0.7, -1.);
		glTexCoord2d(1., 0.); glVertex3f(0.95, -0.7 + 4. * (float)(1.4 / 5), -1.);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	else if (name._Equal("pause")) {
		//quit button		
		glBindTexture(GL_TEXTURE_2D, quit);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2d(0., 0.); glVertex3f(-0.95, -0.7, -1);
		glTexCoord2d(0., 1.); glVertex3f(-0.95, -0.7 + (float)(1.4 / 3), -1);
		glTexCoord2d(1., 1.); glVertex3f(0.95, -0.7 + (float)(1.4 / 3), -1);
		glTexCoord2d(1., 0.); glVertex3f(0.95, -0.7, -1);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		//options button		
		glBindTexture(GL_TEXTURE_2D, options);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2d(0., 0.); glVertex3f(-0.95, -0.7 + (float)(1.4 / 3), -1.);
		glTexCoord2d(0., 1.); glVertex3f(-0.95, -0.7 + 2. * (float)(1.4 / 3), -1.);
		glTexCoord2d(1., 1.); glVertex3f(0.95, -0.7 + 2. * (float)(1.4 / 3), -1.);
		glTexCoord2d(1., 0.); glVertex3f(0.95, -0.7 + (float)(1.4 / 3), -1.);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		//continue button		
		glBindTexture(GL_TEXTURE_2D, cont);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2d(0., 0.); glVertex3f(-0.95, -0.7 + 2.*(float)(1.4 / 3), -1.);
		glTexCoord2d(0., 1.); glVertex3f(-0.95, 0.7 , -1.);
		glTexCoord2d(1., 1.); glVertex3f(0.95, 0.7 , -1.);
		glTexCoord2d(1., 0.); glVertex3f(0.95, -0.7 +2.* (float)(1.4 / 3), -1.);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	else {
		//retry button		
		glBindTexture(GL_TEXTURE_2D, retry);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2d(0., 0.); glVertex3f(-0.95/8., -0.7 + 2. * (float)(1.4 / 5), -1.);
		glTexCoord2d(0., 1.); glVertex3f(-0.95/8., -0.7+ 3. * (float)(1.4 / 5), -1.);
		glTexCoord2d(1., 1.); glVertex3f(0.95/8., -0.7+ 3. * (float)(1.4 / 5), -1.);
		glTexCoord2d(1., 0.); glVertex3f(0.95/8., -0.7 + 2. * (float)(1.4 / 5), -1.);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
}
void menuScene::drawcursor() {
	if (name._Equal("main")|| name._Equal("pause")) {
		if (cursorposition < 1) cursorposition = 1;
		if (cursorposition >nrofbuttons) cursorposition = nrofbuttons;
		glBindTexture(GL_TEXTURE_2D, cursor);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2d(0., 0.); glVertex3f(-0.95, 0.7 -(cursorposition -1)* (float)(1.4 / nrofbuttons), -0.99);
		glTexCoord2d(0., 1.); glVertex3f(-0.95, 0.7 - cursorposition * (float)(1.4 / nrofbuttons), -0.99);
		glTexCoord2d(1., 1.); glVertex3f(0.95, 0.7 - cursorposition * (float)(1.4 / nrofbuttons), -0.99);
		glTexCoord2d(1., 0.); glVertex3f(0.95, 0.7- (cursorposition - 1) * (float)(1.4 / nrofbuttons), -0.99);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	//no cursor for death screen yet 
	
}
void menuScene::incrementcursorposition() {//decending
	cursorposition++;
	if (cursorposition > nrofbuttons) cursorposition = cursorposition % nrofbuttons;

}
void menuScene::decrementcursorposition() {//ascending
	cursorposition--;
	if (cursorposition <= 0) cursorposition = cursorposition + nrofbuttons;
}

void menuScene::changecursorposition(int position) {
	if (position > nrofbuttons) cursorposition = position % nrofbuttons;
	else if (position <= 0) cursorposition = (position + nrofbuttons);
	else cursorposition = position;
}
