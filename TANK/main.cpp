#include <iostream> 
#include "cube.h"
#include "tank.h"
#include <GL/glut.h>   // laedt alles für OpenGL
#include <GL/freeglut.h>         //lädt alles für OpenGL
#include <GL/SOIL.h>
#include <conio.h>
#include <vector>
#include "box.h"
int value = 0;
//setting default size values
bool move = false;//used in making fist
float timerelativeAngle = 0;//used in making fist
tank* t;
box* b;
box* b2;
box* b3;
std::vector<GLuint> textures; 
GLuint tex_2d,sky , ground, boxtx , redboxtx,wall;
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
	wall = SOIL_load_OGL_texture("wall.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	ground = SOIL_load_OGL_texture("groundbetter.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	sky = SOIL_load_OGL_texture("sky800.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);

	textures.push_back(green); textures.push_back(blue); textures.push_back(grey);  textures.push_back(yellow);
}
bool iscolliding(std::vector<float> border1, std::vector<float> border2) {
	//border vec will be defined as left,right,top,bot,front,back
	float l1 = border1[0], r1 = border1[1], t1 = border1[2], b1 = border1[3], f1 = border1[4], bk1 = border1[5];
	float l2 = border2[0], r2 = border2[1], t2 = border2[2], b2 = border2[3], f2 = border2[4], bk2 = border2[5];
	//easier to check when 2 objects dont collide 
	return !(r1<l2 || l1>r2 || bk1<f2 || f1>bk2 || b1>t2 || t1<b2);
}
void setcampos(float x, float y, float z) {
	CamXpos = x;
	camYpos = y;
	camZpos = z;
}
void inline resetLook() {
	glPopMatrix();//pop the latest matrix on stack to modify if exist
	glLoadIdentity();//reset the currently loaded matrix if it exists
	gluLookAt(0., 1., 2., centerx, centery, centerz, 0., 1., 0.);//set the lookAt
	glPushMatrix();
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

void drawwalls() {
	
	glBindTexture(GL_TEXTURE_2D, wall);
	//left 
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0., 0.); glVertex3f(-10., 0., -10);
	glTexCoord2f(0., 1.); glVertex3f(-10., 3.5, -10);
	glTexCoord2f(1., 1.); glVertex3f(-10., 3.5, 10);
	glTexCoord2f(1., 0.); glVertex3f(-10., 0., 10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//right 
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0., 0.); glVertex3f(10., 0., -10);
	glTexCoord2f(0., 1.); glVertex3f(10., 3.5, -10);
	glTexCoord2f(1., 1.); glVertex3f(10., 3.5, 10);
	glTexCoord2f(1., 0.); glVertex3f(10., 0., 10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//front 
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0., 0.); glVertex3f(-10., 0., -10);
	glTexCoord2f(0., 1.); glVertex3f(-10., 3.5, -10);
	glTexCoord2f(1., 1.); glVertex3f(10., 3.5, -10);
	glTexCoord2f(1., 0.); glVertex3f(10., 0., -10);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//back 
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0., 0.); glVertex3f(-10., 0., 10);
	glTexCoord2f(0., 1.); glVertex3f(-10., 3.5, 10);
	glTexCoord2f(1., 1.); glVertex3f(10., 3.5, 10);
	glTexCoord2f(1., 0.); glVertex3f(10., 0., 10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
void drawground() {
	//loading ground texture ; 
	glBindTexture(GL_TEXTURE_2D, ground);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
			glTexCoord2f(0.,0.); glVertex3f(-10., 0., -10);
			glTexCoord2f(0.,4.); glVertex3f(-10., 0., 10);
			glTexCoord2f(4.,4.); glVertex3f(10., 0., 10);
			glTexCoord2f(4.,0.); glVertex3f(10., 0., -10);
		glEnd();
	glDisable(GL_TEXTURE_2D);

}
void drawsky() {
	//loading sky texture ; 
	glBindTexture(GL_TEXTURE_2D, sky);
	
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0., 0.); glVertex3f(-15., 4., -15);
	glTexCoord2f(0., 1.); glVertex3f(-15., 4., 15);
	glTexCoord2f(1., 1.); glVertex3f(15., 4., 15);
	glTexCoord2f(1., 0.); glVertex3f(15., 4., -15);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	
}
void createworld() {
	glLoadIdentity();
	glPopMatrix();
	glPushMatrix();
	drawground();
	drawsky();
	drawwalls();
}
void RenderScene() //Zeichenfunktion
{
	//setcampos(t->tank_x_offset, t->tank_y_offset + 1., t->tank_z_offset);
	//gluLookAt(0., 1., 2., centerx, centery, centerz, 0., 1., 0.);//set the lookAt
	glPopMatrix();//pop the latest matrix on stack to modify if exist
	glLoadIdentity();//reset the currently loaded matrix if it exists
	gluLookAt(CamXpos,camYpos,camZpos,centerx+CamXpos, centery, centerz+camZpos-1., 0., 1., 0.);//set the lookAt
	//look behind on the z axis so the left side is -x , right is +x , front -z , back is +z
	glPushMatrix();
	// Hier befindet sich der Code der in jedem Frame ausgefuehrt werden muss
	glLoadIdentity();   // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//drawGrid();
	/*position p(1, 2, 3);
	p.add(1., 1., 1.);
	position::print(p);
	position p2(1, 1, 1);
	position::print(p - p2);
	*/
	createworld();
	/*tright->spawn((value % 2) + 1);
	resetLook();
	tbehind->spawn((value % 2) + 1);
	resetLook();*/
	//t->spawn((value % 2) + 1);
	b->spawn();
	b2->spawn();
	b3->spawn();
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
	float xpos = (float)x;
	float ypos = (float)y;
	switch (key) {
	case 'z':t->movetank(0.015);//move forward
		b->iscolliding = iscolliding(b->getborder(), b2->getborder());
		camZpos -= 0.035; //moving to the front means -z
		break;
	case 's':t->movetank(-0.015);//move backward
		b->iscolliding = iscolliding(b->getborder(), b2->getborder());
		camZpos += 0.035; // moving backward means +z
		break;
	case 'q':t->turntank(1);//turn 1 degree left
		CamXpos -= 0.035;
		break;
	case 'd':t->turntank(-1);//turn 1 degree right
		CamXpos += 0.035;
		break;
	case ' ':
		camYpos += 0.035;
		break;
	}
	std::cout << key << " was pressed at " << xpos << " , " << ypos << std::endl; 
	glutPostRedisplay();
}
void arrowfunc(int key,int x,int y) {// handles the special keys such as arrows
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
}
void noclick_motion(int x, int y) {
	//gonna set higher sensitivity for now due to the small screen size
	std::cout<< "\033[31mMouseXpos = " << x << ", MouseYpos = "<<y<<" .\033[0m\n";
	centerx = float(x - 300.) / 50.;
	centery = -float(y - 300.) / 50.;
	std::cout << "\033[34mCenterx = " << centerx << " .\033[0m\n";
	std::cout << "\033[34mCentery = " << centery << " .\033[0m\n";
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
	b = new box(0.5, 0.5, 0.5);
	b2 = new box(0.5, 0.5, 0.5);
	b2->setposition(1., 0., 0.);
	b3 = new box(0.5, 0.5, 0.5);
	b3->setposition(1., 0., 2.);
	t = new tank(1.4, 0.8, 1.3);
	t->setposition(1., 0., 2.);
	/*tright = new tank(1.4, 0.8, 1.3);
	tright->setposition(3., 0., 3.);
	tbehind = new tank(1.4, 0.8, 1.3);
	tbehind->setposition(1., 0., 6.);*/
	glutInit(&argc, argv);                // GLUT initialisieren
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);         // Fenster-Konfiguration
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
