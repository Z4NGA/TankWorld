#include "menuScene.h"
menuScene::menuScene() {
	cursorposition = 4;
}

menuScene::menuScene(std::string n, std::string t ){
	name = n; type = t;
	current_res = 0; current_qual = 1; vsync = false;
	changing_key = false; 
	if (name._Equal("main")) nrofbuttons = 5;
	else if (name._Equal("pause")) nrofbuttons = 3;
	else if (name._Equal("options")) nrofbuttons = 4;
	else if (name._Equal("video")) nrofbuttons = 7;
	else if (name._Equal("level_selector")) nrofbuttons = NR_LEVELS + 1;
	else if (name._Equal("keybinding")) nrofbuttons = 10; // for now we have 8 bindings + 1 back button   , change can  be done using clicks
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
	if (name._Equal("main")||name._Equal("options")||name._Equal("audio")||name._Equal("level_selector")) {
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
	else if (name._Equal("controls")) {
		glBindTexture(GL_TEXTURE_2D, controlsbg);
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
	else if (name._Equal("video")) {
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
		glBindTexture(GL_TEXTURE_2D, videofg);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2d(0., 0.); glVertex3f(-0.95, -0.7, -1.0);
		glTexCoord2d(0., 1.); glVertex3f(-0.95, 0.7, -1.0);
		glTexCoord2d(1., 1.); glVertex3f(0.95, 0.7, -1.0);
		glTexCoord2d(1., 0.); glVertex3f(0.95, -0.7, -1.0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		switch (current_res) {
		case 0:
			glBindTexture(GL_TEXTURE_2D, res800);
			break;
		case 1:
			glBindTexture(GL_TEXTURE_2D, res1200);
			break;
		case 2:
			glBindTexture(GL_TEXTURE_2D, res1600);
			break;
		}
		//draws the resolution settings
		glEnable(GL_TEXTURE_2D);
			glBegin(GL_POLYGON);
				glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
				glTexCoord2d(0., 0.); glVertex3f(-0.95, -0.7, -0.99);
				glTexCoord2d(0., 1.); glVertex3f(-0.95, 0.7,-0.99);
				glTexCoord2d(1., 1.); glVertex3f(0.95, 0.7, -0.99);
				glTexCoord2d(1., 0.); glVertex3f(0.95, -0.7, -0.99);
			glEnd();
		glDisable(GL_TEXTURE_2D);
		switch (current_qual) {
		case 0:
			glBindTexture(GL_TEXTURE_2D, quality_low);
			break;
		case 1:
			glBindTexture(GL_TEXTURE_2D, quality_medium);
			break;
		case 2:
			glBindTexture(GL_TEXTURE_2D, quality_high);
			break;
		}
		//draws the quality settings
		glEnable(GL_TEXTURE_2D);
			glBegin(GL_POLYGON);
				glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
				glTexCoord2d(0., 0.); glVertex3f(-0.95, -0.7, -0.98);
				glTexCoord2d(0., 1.); glVertex3f(-0.95, 0.7, -0.98);
				glTexCoord2d(1., 1.); glVertex3f(0.95, 0.7, -0.98);
				glTexCoord2d(1., 0.); glVertex3f(0.95, -0.7, -0.98);
			glEnd();
		glDisable(GL_TEXTURE_2D);
		if (vsync) 	glBindTexture(GL_TEXTURE_2D, vsync_on);
		else glBindTexture(GL_TEXTURE_2D, vsync_off);
		//draws the vsync settings
		glEnable(GL_TEXTURE_2D);
			glBegin(GL_POLYGON);
				glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
				glTexCoord2d(0., 0.); glVertex3f(-0.95, -0.7, -0.97);
				glTexCoord2d(0., 1.); glVertex3f(-0.95, 0.7, -0.97);
				glTexCoord2d(1., 1.); glVertex3f(0.95, 0.7, -0.97);
				glTexCoord2d(1., 0.); glVertex3f(0.95, -0.7, -0.97);
			glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	else if (name._Equal("keybinding")) {
	glBindTexture(GL_TEXTURE_2D, keybinding_bg);
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
	else if (name._Equal("options")) {
		//back button		
		glBindTexture(GL_TEXTURE_2D, back);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2d(0., 0.); glVertex3f(-0.95, -0.7, -1);
		glTexCoord2d(0., 1.); glVertex3f(-0.95, -0.7 + (float)(1.4 / 4), -1);
		glTexCoord2d(1., 1.); glVertex3f(0.95, -0.7 + (float)(1.4 / 4), -1);
		glTexCoord2d(1., 0.); glVertex3f(0.95, -0.7, -1);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		//audio button		
		glBindTexture(GL_TEXTURE_2D, audio);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2d(0., 0.); glVertex3f(-0.95, -0.7 + (float)(1.4 / 4), -1.);
		glTexCoord2d(0., 1.); glVertex3f(-0.95, -0.7 + 2. * (float)(1.4 / 4), -1.);
		glTexCoord2d(1., 1.); glVertex3f(0.95, -0.7 + 2. * (float)(1.4 / 4), -1.);
		glTexCoord2d(1., 0.); glVertex3f(0.95, -0.7 + (float)(1.4 / 4), -1.);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		//keybindings button		
		glBindTexture(GL_TEXTURE_2D, keybindings);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2d(0., 0.); glVertex3f(-0.95, -0.7 + 2. * (float)(1.4 / 4), -1.);
		glTexCoord2d(0., 1.); glVertex3f(-0.95, -0.7 + 3. * (float)(1.4 / 4), -1.);
		glTexCoord2d(1., 1.); glVertex3f(0.95, -0.7 + 3. * (float)(1.4 / 4), -1.);
		glTexCoord2d(1., 0.); glVertex3f(0.95, -0.7 + 2. * (float)(1.4 / 4), -1.);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		//video button		
		glBindTexture(GL_TEXTURE_2D, video);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2d(0., 0.); glVertex3f(-0.95, -0.7 + 3. * (float)(1.4 / 4), -1.);
		glTexCoord2d(0., 1.); glVertex3f(-0.95, 0.7, -1.);
		glTexCoord2d(1., 1.); glVertex3f(0.95, 0.7, -1.);
		glTexCoord2d(1., 0.); glVertex3f(0.95, -0.7 + 3. * (float)(1.4 / 4), -1.);
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
	else if (name._Equal("controls")||name._Equal("video")) {
		//back button		
		glBindTexture(GL_TEXTURE_2D, back);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2d(0., 0.); glVertex3f(-0.95, -0.7, -0.96);
		glTexCoord2d(0., 1.); glVertex3f(-0.95, -0.7 + (float)(1.4 / 5), -0.96);
		glTexCoord2d(1., 1.); glVertex3f(0.95, -0.7 + (float)(1.4 / 5), -0.96);
		glTexCoord2d(1., 0.); glVertex3f(0.95, -0.7, -0.96);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	else if (name._Equal("level_selector")) {
	//back button		
		glBindTexture(GL_TEXTURE_2D, back);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2d(0., 0.); glVertex3f(-0.95, -0.7, -0.96);
		glTexCoord2d(0., 1.); glVertex3f(-0.95, -0.7 + (float)(1.4 / 5), -0.96);
		glTexCoord2d(1., 1.); glVertex3f(0.95, -0.7 + (float)(1.4 / 5), -0.96);
		glTexCoord2d(1., 0.); glVertex3f(0.95, -0.7, -0.96);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	//level 1
		if (cursorposition == 1) glBindTexture(GL_TEXTURE_2D, level1_selected);
		else glBindTexture(GL_TEXTURE_2D, level1);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2d(0., 0.); glVertex3f(-0.75, 0.1, -0.96);
		glTexCoord2d(0., 1.); glVertex3f(-0.75, 0.5, -0.96);
		glTexCoord2d(1., 1.); glVertex3f(-0.25, 0.5, -0.96);
		glTexCoord2d(1., 0.); glVertex3f(-0.25, 0.1, -0.96);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	//level 2
		if (cursorposition == 2) glBindTexture(GL_TEXTURE_2D, level2_selected);
		else glBindTexture(GL_TEXTURE_2D, level2);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2d(0., 0.); glVertex3f(0.25, 0.1, -0.96);
		glTexCoord2d(0., 1.); glVertex3f(0.25, 0.5, -0.96);
		glTexCoord2d(1., 1.); glVertex3f(0.75, 0.5, -0.96);
		glTexCoord2d(1., 0.); glVertex3f(0.75, 0.1, -0.96);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	else if (name._Equal("keybinding")) {
	std::string all_letters = "abcdefghijklmnopqrstuvwxyz";
	//a way to draw keybindings 
	float yoffset = 0;
	for (int i = 0; i<keys.size();i++) {
		std::string key = keys.at(i);
		yoffset += 0.1;
		if (key.size() > 1) {
			if (key._Equal("left"))			glBindTexture(GL_TEXTURE_2D, letters.at(26));
			else if (key._Equal("right"))	glBindTexture(GL_TEXTURE_2D, letters.at(27));
			else if (key._Equal("up"))		glBindTexture(GL_TEXTURE_2D, letters.at(28));
			else if (key._Equal("down"))	glBindTexture(GL_TEXTURE_2D, letters.at(29));
			else if (key._Equal("space"))	glBindTexture(GL_TEXTURE_2D, letters.at(30));
		}
		else {
			if (all_letters.find(key) != std::string::npos) 
				glBindTexture(GL_TEXTURE_2D, letters.at(all_letters.find(key)));
			else glBindTexture(GL_TEXTURE_2D, letters.at(30));
		}
		if ((changing_key)&&(i == cursorposition - 1)) {
			glBindTexture(GL_TEXTURE_2D, new_key);
			glEnable(GL_TEXTURE_2D);
				glBegin(GL_POLYGON);
					glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
					glTexCoord2d(0., 0.); glVertex3f(0.1, 0.53 - yoffset, -0.99);
					glTexCoord2d(0., 1.); glVertex3f(0.1, 0.62 - yoffset, -0.99);
					glTexCoord2d(1., 1.); glVertex3f(0.7, 0.62 - yoffset, -0.99);
					glTexCoord2d(1., 0.); glVertex3f(0.7, 0.53 - yoffset, -0.99);
				glEnd();
			glDisable(GL_TEXTURE_2D);
		}
		else {
			glEnable(GL_TEXTURE_2D);
				glBegin(GL_POLYGON);
					glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
					glTexCoord2d(0., 0.); glVertex3f(0.4, 0.53 - yoffset, -0.99);
					glTexCoord2d(0., 1.); glVertex3f(0.4, 0.62 - yoffset, -0.99);
					glTexCoord2d(1., 1.); glVertex3f(0.5, 0.62 - yoffset, -0.99);
					glTexCoord2d(1., 0.); glVertex3f(0.5, 0.53 - yoffset, -0.99);
				glEnd();
			glDisable(GL_TEXTURE_2D);
		}
	 }
	
	//back button		
		glBindTexture(GL_TEXTURE_2D, back);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2d(0., 0.); glVertex3f(-0.95, -0.7, -0.96);
		glTexCoord2d(0., 1.); glVertex3f(-0.95, -0.7 + (float)(1.4 / 5), -0.99);
		glTexCoord2d(1., 1.); glVertex3f(0.95, -0.7 + (float)(1.4 / 5), -0.99);
		glTexCoord2d(1., 0.); glVertex3f(0.95, -0.7, -0.96);
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
	if (name._Equal("main")|| name._Equal("pause")|| name._Equal("options")) {
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
	else if (name._Equal("video")) {
		if (cursorposition < 1) cursorposition = 1;
		if (cursorposition > nrofbuttons) cursorposition = nrofbuttons;
		if (cursorposition < 7) {
			//small cursor for thhe small buttons
			glBindTexture(GL_TEXTURE_2D, smallcursor);
			float cursorx=0., cursory=0., xoffset =(1./8.)*1.9 , yoffset = (1./6.)*1.4; 
			if (cursorposition <= 3) cursorx = (0.21*1.9)-0.95;
			else cursorx = (0.633*1.9)-0.95;
			if (cursorposition % 3 == 1) cursory = 0.7-(0.14*1.4);
			else if (cursorposition % 3 == 2)cursory = 0.7 - (0.385 * 1.4);
			else cursory = 0.7 - (0.63 * 1.4);
			glEnable(GL_TEXTURE_2D);
			glBegin(GL_POLYGON);
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
			glTexCoord2d(0., 0.); glVertex3f(cursorx, cursory - yoffset, -0.95);
			glTexCoord2d(0., 1.); glVertex3f(cursorx, cursory, -0.95);
			glTexCoord2d(1., 1.); glVertex3f(cursorx + xoffset, cursory , -0.95);
			glTexCoord2d(1., 0.); glVertex3f(cursorx + xoffset, cursory- yoffset, -0.95);
			glEnd();
			glDisable(GL_TEXTURE_2D);
		}
		else { //cursor of the back button
			glBindTexture(GL_TEXTURE_2D, cursor);
			glEnable(GL_TEXTURE_2D);
			glBegin(GL_POLYGON);
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
			glTexCoord2d(0., 0.); glVertex3f(-0.95, -0.7, -0.95);
			glTexCoord2d(0., 1.); glVertex3f(-0.95, -0.7 + (float)(1.4 / 5), -0.95);
			glTexCoord2d(1., 1.); glVertex3f(0.95, -0.7 + (float)(1.4 / 5), -0.95);
			glTexCoord2d(1., 0.); glVertex3f(0.95, -0.7, -0.95);
			glEnd();
			glDisable(GL_TEXTURE_2D);
		}
		//implement the level selector
	}
	else if (name._Equal("level_selector")) {
		if (cursorposition < 1) cursorposition = 1;
		if (cursorposition > nrofbuttons) cursorposition = nrofbuttons;
		glBindTexture(GL_TEXTURE_2D, cursor);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2d(0., 0.); glVertex3f(-0.95, -0.7, -0.99);
		glTexCoord2d(0., 1.); glVertex3f(-0.95, -0.7 + (float)(1.4 / 5), -0.99);
		glTexCoord2d(1., 1.); glVertex3f(0.95, -0.7 + (float)(1.4 / 5), -0.99);
		glTexCoord2d(1., 0.); glVertex3f(0.95, -0.7, -0.99);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	else if (name._Equal("controls")) {
		if (cursorposition < 1) cursorposition = 1;
		if (cursorposition > nrofbuttons) cursorposition = nrofbuttons;
		glBindTexture(GL_TEXTURE_2D, cursor);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glTexCoord2d(0., 0.); glVertex3f(-0.95, -0.7, -0.99);
		glTexCoord2d(0., 1.); glVertex3f(-0.95, -0.7 + (float)(1.4 / 5), -0.99);
		glTexCoord2d(1., 1.); glVertex3f(0.95, -0.7 + (float)(1.4 / 5), -0.99);
		glTexCoord2d(1., 0.); glVertex3f(0.95, -0.7, -0.99);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	else if (name._Equal("keybinding")) {
		if (cursorposition > 10)cursorposition = 10;
		if (cursorposition < 1)cursorposition = 1;
		if (cursorposition < 10) {
			glBindTexture(GL_TEXTURE_2D, letter_cursor);
			glEnable(GL_TEXTURE_2D);
			glBegin(GL_POLYGON);
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
			glTexCoord2d(0., 0.); glVertex3f(0., 0.526 - (cursorposition * 0.097), -0.98);
			glTexCoord2d(0., 1.); glVertex3f(0., 0.616 - (cursorposition * 0.097), -0.98);
			glTexCoord2d(1., 1.); glVertex3f(0.8, 0.616 - (cursorposition * 0.097), -0.98);
			glTexCoord2d(1., 0.); glVertex3f(0.8, 0.526 - (cursorposition * 0.097), -0.98);
			glEnd();
			glDisable(GL_TEXTURE_2D);
		}
		else {
			glBindTexture(GL_TEXTURE_2D, cursor);
			glEnable(GL_TEXTURE_2D);
			glBegin(GL_POLYGON);
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
			glTexCoord2d(0., 0.); glVertex3f(-0.95, -0.7, -0.95);
			glTexCoord2d(0., 1.); glVertex3f(-0.95, -0.7 + (float)(1.4 / 5), -0.95);
			glTexCoord2d(1., 1.); glVertex3f(0.95, -0.7 + (float)(1.4 / 5), -0.95);
			glTexCoord2d(1., 0.); glVertex3f(0.95, -0.7, -0.95);
			glEnd();
			glDisable(GL_TEXTURE_2D);
		}
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
	std::cout << "Current Cursor position is : " << cursorposition << " ,passed position value is : " << position << std::endl;
}
void menuScene::changeres(int x) {
	current_res += x; 
	if (current_res < 0)current_res += 3;
	if (current_res >= 3)current_res = current_res % 3;
}
void menuScene::changequal(int x) {
	current_qual += x; 
	if (current_qual < 0)current_qual += 3;
	if (current_qual >= 3) current_qual = current_qual % 3;
}
void menuScene::changevsync() {
	vsync = !vsync;
}