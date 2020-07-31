#include "Controller.h"
#include "GameEngine.h"
#include "menuScene.h"
Controller::Controller(GameEngine*  p) {
	engineincontrol = p;
	CamXpos = 0., camYpos = 1., camZpos = 0.; //defines where the cam stands
	centerx = 0.7, centery = 0.9, centerz = -1.;  //defines where the cam looks
	controlled_object = nullptr; 
}
void Controller::resetcenterpos() {
	centerx = 0.7; centery = -0.1; centerz = -1.;  //defines where the cam looks
}
void Controller::setcenterpos(float x , float y, float z) {
	centerx = x; centery = y; centerz = z;  //defines where the cam looks
}
//bound function maybe passed into the callack function
void Controller::keyboardfunc(unsigned char key, int x, int y) {
	
	if (engineincontrol->current_scene->type._Equal("game_scene")) {
			// if the scene  is 3d game scene  ,cam will move
		if (engineincontrol->isusing) { //when the player is using an object
			float xpos = (float)x;
			float ypos = (float)y;
			switch (key) {
				case 27:
					engineincontrol->onpause();
					break;
				case 'z':
					//camZpos -= 0.035; //moving to the front means -z
					//move toward the line of sight vector , means in direction of the person's sight
					engineincontrol->controlled_object->addoffsettoposition(0.065 * (centerx), 0., 0.065 * (centerz));
					camZpos += 0.065 * (centerz);//camera position must be included when calculating the direction vector
					CamXpos += 0.065 * (centerx);//so the player walks in a straight line towards middle of screen(crosshair)
					break;
				case 's':
					//camZpos += 0.035; // moving backward means +z
					//move toward the line of sight vector , means in direction of the person's sight
					engineincontrol->controlled_object->addoffsettoposition(-0.045 * (centerx), 0., -0.045 * (centerz));
					camZpos -= 0.045 * (centerz);
					CamXpos -= 0.045 * (centerx);
					break;
				case 'q':
					//CamXpos -= 0.035;
					break;
				case 'd':
					//CamXpos += 0.035;
					break;
				case 'v'://debug
					//if (xdebug.size() > 0) xdebug.pop_back();
					break;
				case ' ':
					if (engineincontrol->controlled_object->generaltype._Equal("aircraft") || engineincontrol->controlled_object->generaltype._Equal("box"))
						{
						engineincontrol->controlled_object->addoffsettoposition(0., 0.065, 0.);
						camYpos += 0.065;
						}
					break;
				case 'x'://change of scene
					engineincontrol->changescene(BEACH_SCENE);
					break;
				case 'e':
					engineincontrol->controlled_object->turnedon = false; 
					engineincontrol->releasecontrolledobject();
					break;
			}
		}
		else{ //when the player is on foot
			float xpos = (float)x;
			float ypos = (float)y;
			switch (key) {
				case 27:
					engineincontrol->onpause();
					break;
				case 'z':
					//camZpos -= 0.035; //moving to the front means -z
					//move toward the line of sight vector , means in direction of the person's sight
					camZpos += 0.035 * (centerz);//camera position must be included when calculating the direction vector
					CamXpos += 0.035 * (centerx);//so the player walks in a straight line towards middle of screen(crosshair)
					break;
				case 's':
					//camZpos += 0.035; // moving backward means +z
					//move toward the line of sight vector , means in direction of the person's sight
					camZpos -= 0.035 * (centerz);
					CamXpos -= 0.035 * (centerx);
					break;
				case 'q':
					//CamXpos -= 0.035;
					break;
				case 'd':
					//CamXpos += 0.035;
					break;
				case 'v'://debug
					//if (xdebug.size() > 0) xdebug.pop_back();
					break;
				case ' ':
					camYpos += 0.035;
					break;
				case 'x'://change of scene
					engineincontrol->changescene(BEACH_SCENE);
					break;
				case 'e':
					if (engineincontrol->hasobjectinrange)
					{
						engineincontrol->setcontrolledobject(engineincontrol->objectinrange);
						engineincontrol->controlled_object->turnedon = true;
					}
					break;
			}
			std::cout << key << " was pressed at " << xpos << " , " << ypos << std::endl;
		}
		//glutPostRedisplay();
	}
	else {// if the scene  is a menu scene 
		
		if (engineincontrol->current_scene->name._Equal("pause")) { //pause menu handler
			switch (key) {
			case 27:
				engineincontrol->backtogame();
				break;
			case 13://32 is the space bar
				std::cout << "u pressed enter\n";
				selectbasedoncursor();
				break;
			case 'c':
				engineincontrol->backtogame();
				break;
			case 'o':
				engineincontrol->displayoptions();
				break;
			case 'q'://debug
				exit(0);
				break;
			}
		}
		else if (engineincontrol->current_scene->name._Equal("controls")) { //pause menu handler
			switch (key) {
			case 27:
				engineincontrol->displaystartmenu();
				break;
			case 'b':
				engineincontrol->displaystartmenu();
				break;
			}
		}
		else if (engineincontrol->current_scene->name._Equal("main")) { //main menu handler
			switch (key) {
				case 'p':
					engineincontrol->startgame();
					break;
				case 'c':
					engineincontrol->displaycontrols();
					break;
				case 'a':
					engineincontrol->displaycredits();
					break;
				case 'o':
					engineincontrol->displayoptions();
					break;
				case 'q'://quit
					exit(0);
					break;
				case 13:
					std::cout << "u pressed enter\n";
					selectbasedoncursor();
					break;
			}
		}
		else { //death screen handler
			switch (key) {
				case 'r':
					//retry
					break;
				case 'q':
					exit(0);
					break;
			}
		}
	}
}
void Controller::arrowfunc(int key, int x, int y) {// handles the special keys such as arrows
	
	if (engineincontrol->current_scene->type._Equal("game_scene")) {
		// if the scene  is 3d game scene  ,cam and object will be able to move
		if (engineincontrol->isusing) { //when the player is using an object
			switch (key) {
			case GLUT_KEY_UP:
				std::cout << " ARROW_UP\n";
				if(engineincontrol->controlled_object->type._Equal("tank"))
					engineincontrol->controlled_object->tiltcannon(2.) ;
				break;
			case GLUT_KEY_DOWN:
				std::cout << " ARROW_DOWN\n";
				if (engineincontrol->controlled_object->generaltype._Equal("aircraft") || engineincontrol->controlled_object->generaltype._Equal("box"))
					{
					engineincontrol->controlled_object->addoffsettoposition(0., -0.065, 0.);
					camYpos -= 0.065;
					}
				if (engineincontrol->controlled_object->type._Equal("tank"))
					engineincontrol->controlled_object->tiltcannon(-2.);
				break;
			case GLUT_KEY_LEFT:
				std::cout << " ARROW_LEFT\n";
				if (engineincontrol->controlled_object->type._Equal("tank"))
					engineincontrol->controlled_object->turntop(2.);
				break;
			case GLUT_KEY_RIGHT:
				std::cout << " ARROW_RIGHT\n";
				if (engineincontrol->controlled_object->type._Equal("tank"))
					engineincontrol->controlled_object->turntop(-2.);
				break;
			case GLUT_KEY_CTRL_L:
				std::cout << "CTRL Left \n";
				//can be upgraded to go left right forward back according to the direction vector
				break;
			}
		}
		else {
			switch (key) {
			case GLUT_KEY_UP:
				std::cout << " ARROW_UP\n";
				/*t->tiltcannon(1);
				b->movez(0.015);
				b->iscolliding = iscolliding(b->getborder(), b2->getborder());
				*/break;
			case GLUT_KEY_DOWN:
				std::cout << " ARROW_DOWN\n";
				camYpos -= 0.035;
				/*t->tiltcannon(-1);
				b->movez(-0.015);
				b->iscolliding = iscolliding(b->getborder(), b2->getborder());
				*/break;
			case GLUT_KEY_LEFT:
				std::cout << " ARROW_LEFT\n";
				/*t->turntop(2);
				b->movex(-0.015);
				b->iscolliding = iscolliding(b->getborder(), b2->getborder());
				*/break;
			case GLUT_KEY_RIGHT:
				std::cout << " ARROW_RIGHT\n";
				/*t->turntop(-2);
				b->movex(0.015);
				b->iscolliding = iscolliding(b->getborder(), b2->getborder());
				*/break;
			case GLUT_KEY_CTRL_L:
				std::cout << "CTRL Left \n";

				//can be upgraded to go left right forward back according to the direction vector
				break;
			}
		}
	}
	else {
		// if the scene  is menu scene  ,arrows will be able to navigate between buttons
		switch (key) {
		case GLUT_KEY_UP:
			std::cout << " ARROW_UP\n";
			engineincontrol->current_scene->decrementcursorposition();
			break;
		case GLUT_KEY_DOWN:
			std::cout << " ARROW_DOWN\n";
			engineincontrol->current_scene->incrementcursorposition();
			break;
		case GLUT_KEY_LEFT:
			std::cout << " ARROW_LEFT\n";
			break;
		case GLUT_KEY_RIGHT:
			std::cout << " ARROW_RIGHT\n";
			break;
		}
	}
}
void Controller::noclick_motion(int x, int y) {
	std::cout << "\033[31mMouseXpos = " << x << ", MouseYpos = " << y << " .\033[0m\n";
	if (engineincontrol->current_scene->type._Equal("game_scene")) {
		if (engineincontrol->isusing) {
			//mouse will be used to move camera line of sight 360� around while game_scene
			//cam movement will result in turning the object

			float angle = ((float(x) - float(Width / 2.)) / (float)(Width / 2.)) * 180. + 90;
			centerx = 2. * cos(angle * M_PI / 180.);
			centerz = 2. * sin(angle * M_PI / 180.);
			//centerx = float(x - 300.) / (float)xdebug.at(xdebug.size()-1);
			centery = -float(y - (Height / 2.)) / 50.;
			float zaxisangle = ((float(x) - float(Width / 2.)) / (float)(Width / 2.)) * 180. + 90;
			if(engineincontrol->controlled_object->type._Equal("tank")) engineincontrol->controlled_object->rotateobject(0., - angle, 0.);
			else engineincontrol->controlled_object->rotateobject(0., 180-angle, 0.);
			std::cout << "\033[34mCenterx = " << centerx << " .\033[0m\n";
			std::cout << "\033[34mCenterz = " << centerz << " .\033[0m\n";
		}
		else {
			//mouse will be used to move camera line of sight 360� around while game_scene
					//gonna set higher sensitivity for now due to the small screen size

			float angle = ((float(x) - float(Width / 2.)) / (float)(Width / 2.)) * 180. + 90;
			centerx = 2. * cos(angle * M_PI / 180.);
			centerz = 2. * sin(angle * M_PI / 180.);
			//centerx = float(x - 300.) / (float)xdebug.at(xdebug.size()-1);
			centery = -float(y - (Height / 2.)) / 50.;
			std::cout << "\033[34mCenterx = " << centerx << " .\033[0m\n";
			std::cout << "\033[34mCenterz = " << centerz << " .\033[0m\n";
		}
	}
	else {
		//mouse will be used to make hover effect over the buttons while menu_scene
		if(engineincontrol->current_scene->name._Equal("main")){
			if (y < (float)Height / 5.) engineincontrol->current_scene->changecursorposition(1);
			else if (y < (2. * (float)Height / 5.)) engineincontrol->current_scene->changecursorposition(2);
			else if (y < (3. * (float)Height / 5.)) engineincontrol->current_scene->changecursorposition(3);
			else if (y < (4. * (float)Height / 5.)) engineincontrol->current_scene->changecursorposition(4);
			else engineincontrol->current_scene->changecursorposition(5);
		}
		else if (engineincontrol->current_scene->name._Equal("pause")) { //not quite yet
			if (y < (float)Height / 3.) engineincontrol->current_scene->changecursorposition(1);
			else if (y < (2. * (float)Height / 3.)) engineincontrol->current_scene->changecursorposition(2);
			else  engineincontrol->current_scene->changecursorposition(3);
		}
		else if (engineincontrol->current_scene->name._Equal("controls")) { //not quite yet
			if (y > (2*(float)Height / 3.)) engineincontrol->current_scene->changecursorposition(1);
		}
	}
}

void Controller::onclick_listner(int button, int state, int x, int y) {
	std::cout << "\033[31mMouseXpos = " << x << ", MouseYpos = " << y << " .\033[0m\n";
	if (engineincontrol->current_scene->type._Equal("menu_scene")) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) selectbasedoncursor();
	}
}
void Controller::resetlook() { 
	//resets the look to suit  a game_scene
	glPopMatrix();//pop the latest matrix on stack to modify if exist
	glLoadIdentity();//reset the currently loaded matrix if it exists
	if(engineincontrol->isusing) gluLookAt(CamXpos, camYpos, camZpos, centerx + CamXpos, centery+camYpos, centerz + camZpos , 0., 1., 0.);
	else gluLookAt(CamXpos, camYpos, camZpos, centerx + CamXpos, centery, centerz + camZpos , 0., 1., 0.);//set the lookAt
	//look behind on the z axis so the left side is -x , right is +x , front -z , back is +z
	glPushMatrix();
	displaydetectionrange();

}
void Controller::setmenulook() {
	// sets the look to suit a menu_scene
	glPopMatrix();//pop the latest matrix on stack to modify if exist
	glLoadIdentity();//reset the currently loaded matrix if it exists
	gluLookAt(0., 0., 0., 0., 0., -1., 0., 1., 0.);//set the lookAt
	//look behind on the z axis so the left side is -x , right is +x , front -z , back is +z
	glPushMatrix();
}
void Controller::setcampos(float x, float y, float z) { 
	// sets the camera position to spesific x ,y ,z coords
	CamXpos = x;
	camYpos = y;
	camZpos = z;
}
void Controller::selectbasedoncursor() {
	if (engineincontrol->current_scene->name._Equal("main")) {
		switch (engineincontrol->current_scene->cursorposition)
		{
		case 1:
			engineincontrol->startgame();
			break;
		case 2:
			engineincontrol->displaycontrols();
			break;
		case 3:
			engineincontrol->displaycredits();
			break;
		case 4:
			engineincontrol->displayoptions();
			break;
		case 5:
			exit(0);
			break;
		}
	}
	else if (engineincontrol->current_scene->name._Equal("pause")) {
		switch (engineincontrol->current_scene->cursorposition)
		{
		case 1:
			engineincontrol->backtogame();
			break;
		case 2:
			engineincontrol->displayoptions();
			break;
		case 3:
			exit(0);
			break;
		}
	}
	else if (engineincontrol->current_scene->name._Equal("controls")) {
		if(engineincontrol->current_scene->cursorposition==1)
			engineincontrol->displaystartmenu();
	}
}
void Controller::displaydetectionrange() {
	float radiuswidth = 0.1;
	glBegin(GL_LINE_LOOP);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	for (float i = 0; i < 2*M_PI; i+=0.005)
	{
		float x = detectionrange * cos(i);
		float z = detectionrange * sin(i);
		glVertex3f(x+CamXpos, 0.1, z+camZpos);
		x = (detectionrange - radiuswidth) * cos(i);
		z = (detectionrange - radiuswidth) * sin(i);
		glVertex3f(x+CamXpos, 0.1, z+camZpos);
	}
	glEnd();
}
bool Controller::isindetectionrange(GameObject*  obj) {
	/*float expectedcenterdistance = detectionrange + (obj->xLen*sqrt(2)/2.); // will be calculated as the radius + diagonal
	float currentcenterdistance  = sqrt(pow((obj->xoffset - CamXpos), 2) + pow((obj->yoffset - camYpos), 2) y offset will be ignored for now+ pow((obj->zoffset - camZpos), 2) );
	bool result = (currentcenterdistance < expectedcenterdistance); 
	if (currentcenterdistance < expectedcenterdistance) std::cout << "object " << obj->type << " is in range of the player !! \nxoffsetdif = "<<
		obj->xoffset-CamXpos<< ", yoffsetdif = "<<obj->yoffset - camYpos <<", zoffsetdif = "<<obj->zoffset-camZpos<< "\n";
	obj->inrange = result; 
	return result;*/
	//will surround the current object with a box 1.f wider and if the player collides with that box he's in range
	float objoffset=1.5;
	if (obj->type._Equal("controlestation")) objoffset = 3.;
	float objxmax = obj->xoffset + obj->xLen / 2. + objoffset, objxmin = obj->xoffset - obj->xLen / 2. - objoffset;
	float objymax = obj->yoffset + obj->yLen / 2. + objoffset, objymin = obj->yoffset - obj->yLen / 2. - objoffset;
	float objzmax = obj->zoffset + obj->zLen / 2. + objoffset, objzmin = obj->zoffset - obj->zLen / 2. - objoffset;

	if (CamXpos<objxmax && CamXpos>objxmin && camYpos<objymax && camYpos>objymin && camZpos<objzmax && camZpos>objzmin) {
		std::cout << "object " << obj->type << " is in range of the player !! \nxoffsetdif = " <<
			obj->xoffset - CamXpos << ", yoffsetdif = " << obj->yoffset - camYpos << ", zoffsetdif = " << obj->zoffset - camZpos << "\n";
		obj->inrange = true;
		return true;
	}
	else {
		obj->inrange = false;
		return false;
	}
}