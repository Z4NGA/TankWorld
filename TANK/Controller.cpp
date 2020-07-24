#include "Controller.h"
#include "GameEngine.h"
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
		case 'z':
			//camZpos -= 0.035; //moving to the front means -z
			//move toward the line of sight vector , means in direction of the person's sight
			camZpos += 0.035 * centerz;
			CamXpos += 0.035 * centerx;
			break;
		case 's':
			//camZpos += 0.035; // moving backward means +z
			//move toward the line of sight vector , means in direction of the person's sight
			camZpos -= 0.035 * centerz;
			CamXpos -= 0.035 * centerx;
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
		// if the scene  is a menu scene the keyboard will be ignonerd for now
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
	}
}
void Controller::noclick_motion(int x, int y) {
	if (engineincontrol->current_scene->type._Equal("game_scene")) {
		//mouse will be used to move camera line of sight 360° around while game_scene
			//gonna set higher sensitivity for now due to the small screen size
		std::cout << "\033[31mMouseXpos = " << x << ", MouseYpos = " << y << " .\033[0m\n";
		float angle = ((float(x) - float(Width/2.)) / (float)(Width / 2.)) * 180. + 90;
		centerx = 2. * cos(angle * M_PI / 180.);
		centerz = 2. * sin(angle * M_PI / 180.);
		//centerx = float(x - 300.) / (float)xdebug.at(xdebug.size()-1);
		centery = -float(y - (Height / 2.)) / 50.;
		std::cout << "\033[34mCenterx = " << centerx << " .\033[0m\n";
		std::cout << "\033[34mCentery = " << centery << " .\033[0m\n";
	}
	else {
		//mouse will be used to make hover effect over the buttons while menu_scene

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
	gluLookAt(CamXpos, camYpos, camZpos, centerx + CamXpos, centery, centerz + camZpos - 1., 0., 1., 0.);//set the lookAt
	//look behind on the z axis so the left side is -x , right is +x , front -z , back is +z
	glPushMatrix();
}
void Controller::setcampos(float x, float y, float z) { 
	// sets the camera position to spesific x ,y ,z coords
	CamXpos = x;
	camYpos = y;
	camZpos = z;
}