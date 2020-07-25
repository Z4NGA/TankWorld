#include "Controller.h"
#include "GameEngine.h"
#include "menuScene.h"
Controller::Controller(GameEngine*  p) {
	engineincontrol = p;
	CamXpos = 0., camYpos = 1., camZpos = 0.; //defines where the cam stands
	centerx = 0.7, centery = 0.9, centerz = 0.;  //defines where the cam looks
	controlled_object = nullptr; 
}
//bound function maybe passed into the callack function
void Controller::keyboardfunc(unsigned char key, int x, int y) {
	
	if (engineincontrol->current_scene->type._Equal("game_scene")) {
		// if the scene  is 3d game scene  ,cam will move
		float xpos = (float)x;
		float ypos = (float)y;
		switch (key) {
			case 27 :
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
			case 'e'://change of scene
				engineincontrol->changescene(rand());
				break;
		}
		std::cout << key << " was pressed at " << xpos << " , " << ypos << std::endl;
		//glutPostRedisplay();
	}
	else {
		// if the scene  is a menu scene 
		if (engineincontrol->current_scene->name._Equal("pause")) { //pause menu handler
			switch (key) {
				case 27:
					engineincontrol->backtogame();
					break;
				case 13 ://32 is the space bar
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
		switch (key) {
		case GLUT_KEY_UP:
			std::cout << " ARROW_UP\n";
			/*t->tiltcannon(1);
			b->movez(0.015);
			b->iscolliding = iscolliding(b->getborder(), b2->getborder());
			*/break;
		case GLUT_KEY_DOWN:
			std::cout << " ARROW_DOWN\n";
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
			camYpos -= 0.035;
			//can be upgraded to go left right forward back according to the direction vector
			break;
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
		//mouse will be used to move camera line of sight 360° around while game_scene
			//gonna set higher sensitivity for now due to the small screen size

		float angle = ((float(x) - float(Width/2.)) / (float)(Width / 2.)) * 180. + 90;
		centerx = 2. * cos(angle * M_PI / 180.);
		centerz = 2. * sin(angle * M_PI / 180.);
		//centerx = float(x - 300.) / (float)xdebug.at(xdebug.size()-1);
		centery = -float(y - (Height / 2.)) / 50.;
		std::cout << "\033[34mCenterx = " << centerx << " .\033[0m\n";
		std::cout << "\033[34mCenterz = " << centerz << " .\033[0m\n";
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
	gluLookAt(CamXpos, camYpos, camZpos, centerx + CamXpos, centery, centerz + camZpos - 1., 0., 1., 0.);//set the lookAt
	//look behind on the z axis so the left side is -x , right is +x , front -z , back is +z
	glPushMatrix();
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
}