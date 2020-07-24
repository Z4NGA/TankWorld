#include <iostream> 
#include "cube.h"
#include "tank.h"
#include <GL/glut.h>   // laedt alles für OpenGL
#include <GL/freeglut.h>         //lädt alles für OpenGL
#include <GL/SOIL.h>
#include <conio.h>
#include <vector>
#include "box.h"
#include "base_scene.h"
#include "GameEngine.h"
#include "Controller.h"
#include "Scene.h"
#include "gameScene.h"
#include "menuScene.h"
#include <math.h>
#define M_PI acos(-1.)
int value = 0;
//setting default size values
bool move = false;//used in making fist
float timerelativeAngle = 0;//used in making fist
tank* t;
box* b;
box* b2;
box* b3;
//base_scene* base; 
GameEngine* ge;
Scene* mainmenu; 
Scene* base;
Scene* beach; 
Scene* forest;
std::vector<GLuint> textures; 
std::vector<float> xdebug {50,150,300};
std::vector<float> zdebug ;
GLuint tex_2d,boxtx, redboxtx;
GLuint sky1, ground1, wall1;//set of textures scene1 
GLuint sky2, ground2, wall2;//set of textures scene2 
GLuint sky3, ground3, wall3;//set of textures scene3 
GLuint menubg, play, controls, credits, options, quit;//menu textures
int h, w;
float CamXpos=0., camYpos=1., camZpos=0.; //defines where the cam stands
float centerx=0.7, centery= 0.9, centerz=0.;  //defines where the cam looks
void loadtext() {
	GLuint green = SOIL_load_OGL_texture("camogreen100.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	GLuint blue = SOIL_load_OGL_texture("camoblue100.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_TEXTURE_REPEATS);
	GLuint grey = SOIL_load_OGL_texture("camogrey100.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_TEXTURE_REPEATS);
	GLuint yellow = SOIL_load_OGL_texture("camoyellow100.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_TEXTURE_REPEATS);
	boxtx = SOIL_load_OGL_texture("box.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_TEXTURE_REPEATS);
	redboxtx = SOIL_load_OGL_texture("redbox.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_TEXTURE_REPEATS);
	///
	///  LOADING game scenes TEXTURES
	///
	wall1 = SOIL_load_OGL_texture("wall.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	ground1 = SOIL_load_OGL_texture("groundbetter.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	sky1 = SOIL_load_OGL_texture("sky800.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	wall2 = SOIL_load_OGL_texture("wall2.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	ground2 = SOIL_load_OGL_texture("ground2.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	sky2 = SOIL_load_OGL_texture("sky2.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	wall3 = SOIL_load_OGL_texture("wall3.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	ground3 = SOIL_load_OGL_texture("ground3.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	sky3 = SOIL_load_OGL_texture("sky3.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	///
	///  LOADING MENU TEXTURES
	///
	menubg = SOIL_load_OGL_texture("menubg.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	play = SOIL_load_OGL_texture("play.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	controls = SOIL_load_OGL_texture("controls.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	credits = SOIL_load_OGL_texture("credits.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	options = SOIL_load_OGL_texture("options.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	quit = SOIL_load_OGL_texture("quit.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);

	textures.push_back(green); textures.push_back(blue); textures.push_back(grey);  textures.push_back(yellow);
}


void Init()
{	
	loadtext();
	//tex_2d = SOIL_load_OGL_texture("TREE1.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
		//SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	//textures.push_back(tex_2d);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0., 0., 0., 1.);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	/*glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	*/
}

void drawGrid() {
	glLoadIdentity();
	glPopMatrix();
	glPushMatrix();
	//gluLookAt(-1., 1., 2., 0., 0., 0., 0., 1., 0.);//set the lookAt 
	glLineWidth(1.);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	for (float x = -1.2; x < 1.2; x += 0.2)
	{
		glBegin(GL_LINE_STRIP);
		glVertex3f(x, 0., 1.2);
		glVertex3f(x, 0., -1.2);
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex3f(-1.2, 0., x);
		glVertex3f(1.2, 0., x);
		glEnd();
	}
}
void drawcrosshair() {
	//pass 
}
void RenderScene() //Zeichenfunktion
{
	/// <summary>
	/// RESET LOOK FUNCTION
	/// </summary>
	glPopMatrix();//pop the latest matrix on stack to modify if exist
	glLoadIdentity();//reset the currently loaded matrix if it exists
	gluLookAt(ge->controller->CamXpos, ge->controller->camYpos, ge->controller->camZpos, ge->controller->centerx+ ge->controller->CamXpos, ge->controller->centery, ge->controller->centerz+ ge->controller->camZpos-1., 0., 1., 0.);//set the lookAt
	//look behind on the z axis so the left side is -x , right is +x , front -z , back is +z
	glPushMatrix();
	// Hier befindet sich der Code der in jedem Frame ausgefuehrt werden muss
	glLoadIdentity();   // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//drawGrid();
	/*position p(1, 2, 3);
	p.add(1., 1., 1.);
	position::print(p);
	position p2(1, 1, 1);
	position::print(p - p2);
	*/
	ge->drawCurrentScene();
	//drawcrosshair();z
	//glPopMatrix();
	//cube(0.2,0.2,0.2,boxtx);
	//t->spawn((value % 2));
	/*tright->spawn((value % 2) + 1);
	resetLook();
	tbehind->spawn((value % 2) + 1);
	resetLook();*/
	//t->spawn((value % 2) + 1);
	//b->spawn();
	//b2->spawn();
	//b3->spawn();
	glLoadIdentity();
	glutSwapBuffers();
}
void Reshape(int width, int height)
{
	// Matrix fuer Transformation : Frustum?>viewport
	glMatrixMode(GL_PROJECTION);
	// Aktuelle Transformation s?Matrix zuruecksetzen
	glLoadIdentity();
	// Viewport definieren
	glViewport(0, 0, width, height);
	// Frustum definieren (siehe unten)
	gluPerspective(70., (float)width / (float)height, 0.01, 1000.);
	//glOrtho(-1., 1., -1., 1., 0.001, 1000.0);
	//glTranslatef(camZpos, camYpos, camZpos);
	//gluPerspective(45., 1., 0.1, 10.0);
	// Matrix fuer Modellierung / Viewing
	glMatrixMode(GL_MODELVIEW);


	// Hier finden die Reaktionen auf eine Veränderung der Größe des 
	// Graphikfensters statt
}
void keyboardfunc(unsigned char key, int x, int y) {
	ge->controller->keyboardfunc(key, x, y);
	
	/*float xpos = (float)x;
	float ypos = (float)y;
	switch (key) {
	case 'z':t->movetank(0.015);//move forward
		b->iscolliding = iscolliding(b->getborder(), b2->getborder());
		//camZpos -= 0.035; //moving to the front means -z
		//move toward the line of sight vector , means in direction of the person's sight
		camZpos += 0.035 * centerz;
		CamXpos += 0.035 * centerx; 
		break;
	case 's':t->movetank(-0.015);//move backward
		b->iscolliding = iscolliding(b->getborder(), b2->getborder());
		//camZpos += 0.035; // moving backward means +z
		//move toward the line of sight vector , means in direction of the person's sight
		camZpos -= 0.035 * centerz;
		CamXpos -= 0.035 * centerx;
		break;
	case 'q':t->turntank(1);//turn 1 degree left
		//CamXpos -= 0.035;
		break;
	case 'd':t->turntank(-1);//turn 1 degree right
		//CamXpos += 0.035;
		break;
	case 'v':
		if (xdebug.size() > 0) xdebug.pop_back();
		break;
	case ' ':
		camYpos += 0.035;
		break;
	}
	std::cout << key << " was pressed at " << xpos << " , " << ypos << std::endl; 
	*/glutPostRedisplay();
}
void arrowfunc(int key,int x,int y) {// handles the special keys such as arrows
	ge->controller->arrowfunc(key, x, y);
									 /*
	 switch (key) {
	case GLUT_KEY_UP:
		std::cout << " ARROW_UP\n";
		t->tiltcannon(1);
		b->movez(0.015);
		b->iscolliding = iscolliding(b->getborder(), b2->getborder());
		break;
	case GLUT_KEY_DOWN:
		std::cout << " ARROW_DOWN\n";
		t->tiltcannon(-1);
		b->movez(-0.015);
		b->iscolliding = iscolliding(b->getborder(), b2->getborder());
		break;
	case GLUT_KEY_LEFT:
		std::cout << " ARROW_LEFT\n";
		t->turntop(2);
		b->movex(-0.015);
		b->iscolliding = iscolliding(b->getborder(), b2->getborder());
		break;
	case GLUT_KEY_RIGHT:
		std::cout << " ARROW_RIGHT\n";
		t->turntop(-2);
		b->movex(0.015);
		b->iscolliding = iscolliding(b->getborder(), b2->getborder());
		break;
	case GLUT_KEY_CTRL_L: 
		std::cout << "CTRL Left \n";
		camYpos -= 0.035;
		//can be upgraded to go left right forward back according to the direction vector
		break;
	}
	*/

}
void noclick_motion(int x, int y) {
	ge->controller->noclick_motion(x, y);
	/*//gonna set higher sensitivity for now due to the small screen size
	std::cout<< "\033[31mMouseXpos = " << x << ", MouseYpos = "<<y<<" .\033[0m\n";
	float angle = ((float(x)-300.) / (float)300.) * 180.+90;
	centerx = 2. * cos(angle * M_PI / 180.);
	centerz = 2. * sin(angle * M_PI / 180.);
	//centerx = float(x - 300.) / (float)xdebug.at(xdebug.size()-1);
	centery = -float(y - 300.) / 50.;
	std::cout << "\033[34mCenterx = " << centerx << " .\033[0m\n";
	std::cout << "\033[34mCentery = " << centery << " .\033[0m\n";*/
}
void Animate(int v)
{
	t->output_specs();
	// Hier werden Berechnungen durchgeführt, die zu einer Animation der Szene  
	// erforderlich sind. Dieser Prozess läuft im Hintergrund und wird alle 
	// 1000 msec aufgerufen. Der Parameter "value" wird einfach nur um eins 
	// inkrementiert und dem Callback wieder uebergeben. 
	//std::cout << "Current incremented value set to =" << value << std::endl;
	// RenderScene aufrufen
	glutPostRedisplay();
	// Timer wieder registrieren - Animate wird so nach 10 msec mit value+=1 aufgerufen.
	int wait_msec = 10;
	glutTimerFunc(wait_msec, Animate, ++value);

}

int main(int argc, char** argv)
{
	ge = new GameEngine();
	base = new gameScene("base","game_scene");
	beach = new gameScene("beach", "game_scene");
	forest = new gameScene("forest","game_scene");
	mainmenu = new menuScene("main", "menu_scene");
	ge->addgamescene(base);
	ge->addgamescene(beach);
	ge->addgamescene(forest);
	ge->setCurrentScene(base);
	b = new box(0.5, 0.5, 0.5);
	b2 = new box(0.5, 0.5, 0.5);
	b2->setposition(1., 0., 0.);
	b3 = new box(0.5, 0.5, 0.5);
	b3->setposition(1., 0., 2.);
	t = new tank(1.4, 0.8, 1.3);
	t->setposition(1., 0., 2.);
	ge->addObjecttocurrentscene(b);
	ge->addObjecttocurrentscene(b2);
	ge->addObjecttocurrentscene(b3);
	/*tright = new tank(1.4, 0.8, 1.3);
	tright->setposition(3., 0., 3.);
	tbehind = new tank(1.4, 0.8, 1.3);
	tbehind->setposition(1., 0., 6.);*/
	glutInit(&argc, argv);                // GLUT initialisieren
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(Width, Height);         // Fenster-Konfiguration
	glutCreateWindow("TANK");   // Fenster-Erzeugung
	glutDisplayFunc(RenderScene);         // Zeichenfunktion bekannt machen
	glutSpecialFunc(arrowfunc);
	glutKeyboardFunc(keyboardfunc);
	glutPassiveMotionFunc(noclick_motion);
	// TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0  
	glutTimerFunc(10, Animate, value);
	glutReshapeFunc(Reshape);
	Init();
	t->settextures(&textures);
	/*tright->settextures(&textures);
	tbehind->settextures(&textures);*/
	glutMainLoop();
	return 0;
}
