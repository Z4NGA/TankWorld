#include "Controller.h"
Controller::Controller() {
	CamXpos = 0., camYpos = 1., camZpos = 0.; //defines where the cam stands
	centerx = 0.7, centery = 0.9, centerz = 0.;  //defines where the cam looks
}
//bound function
void Controller::keyboardfunc(unsigned char key, int x, int y) {
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
	}
	std::cout << key << " was pressed at " << xpos << " , " << ypos << std::endl;
	glutPostRedisplay();
}
void Controller::arrowfunc(int key, int x, int y) {// handles the special keys such as arrows
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
void Controller::noclick_motion(int x, int y) {
	//gonna set higher sensitivity for now due to the small screen size
	std::cout << "\033[31mMouseXpos = " << x << ", MouseYpos = " << y << " .\033[0m\n";
	float angle = ((float(x) - 300.) / (float)300.) * 180. + 90;
	centerx = 2. * cos(angle * M_PI / 180.);
	centerz = 2. * sin(angle * M_PI / 180.);
	//centerx = float(x - 300.) / (float)xdebug.at(xdebug.size()-1);
	centery = -float(y - 300.) / 50.;
	std::cout << "\033[34mCenterx = " << centerx << " .\033[0m\n";
	std::cout << "\033[34mCentery = " << centery << " .\033[0m\n";
}
void Controller::resetlook() {
	glPopMatrix();//pop the latest matrix on stack to modify if exist
	glLoadIdentity();//reset the currently loaded matrix if it exists
	gluLookAt(CamXpos, camYpos, camZpos, centerx + CamXpos, centery, centerz + camZpos - 1., 0., 1., 0.);//set the lookAt
	//look behind on the z axis so the left side is -x , right is +x , front -z , back is +z
	glPushMatrix();
}
void Controller::setcampos(float x, float y, float z) { // sets the camera position
	CamXpos = x;
	camYpos = y;
	camZpos = z;
}