#include <iostream> 
#include "cube.h"
#include "tank.h"
#include <GL/glut.h>   // laedt alles f�r OpenGL
#include <GL/freeglut.h>         //l�dt alles f�r OpenGL
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
#include "Tent.h"
#include "controleStation.h"
#include "Aircraft.h"
#include <math.h>
#define M_PI acos(-1.)
#define all_textures 0.51

//textures should be front / right / back / left /top /bot

int value = 0;
int loadedtextures = 0;
//setting default size values
bool move = false;//used in making fist
float timerelativeAngle = 0;//used in making fist
tank* t;
box* b;
box* b2;
box* b3;
std::vector<Tent*> tent;
controleStation* cs;
std::vector<Aircraft*> heli;
//base_scene* base; 
GameEngine* ge;
Scene* mainmenu;
Scene* controlsmenu;
Scene* base;
Scene* beach;
Scene* forest;
Scene* pause;
Scene* death;
Scene* optionsmenu;
Scene* videomenu;
Scene* keybindingmenu;
Scene* audiomenu;
std::vector<float> xdebug {50,150,300};
std::vector<float> zdebug ;
GLuint tex_2d,boxtx, redboxtx; //box textures
GLuint green, blue, grey, yellow; //tank textures
GLuint sky1, ground1, wall1,skynight,ground6;//set of textures scene1 
GLuint sky2, ground2, wall2;//set of textures scene2 
GLuint sky3, ground3, wall3;//set of textures scene3 
GLuint menubg, play, controls, credits, options, quit,cursor ,pausebg , cont ,deathbg,retry,smallcursor;//menu textures
GLuint controlsbg, back;//controls texture
GLuint keybindings, audio, video;//optionmenu textures
GLuint videofg, res800,res1200,res1600,quality_low,quality_medium,quality_high,vsync_on,vsync_off;//video menu textures
GLuint useobject; //game ui textures
GLuint gate_frontback,gatewall, gatebar_texture; //controller textures
GLuint metal,alum,blackalum, orangealum;
int h, w;
float CamXpos=0., camYpos=1., camZpos=0.; //defines where the cam stands
float centerx=0.7, centery= 0.9, centerz=0.;  //defines where the cam looks
void loadtext() {
	/// <summary>
	/// loading tank TEXTURES
	/// </summary>
	std::cout << "\033[34m";//helps the user to understand whats going on
	std::cout << "#### LOADING TEXTURES ! Please wait "<<(float)loadedtextures/all_textures<<"%\n";
	green = SOIL_load_OGL_texture("resources/camogen/camogreen100.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	blue = SOIL_load_OGL_texture("resources/camogen/camoblue100.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_TEXTURE_REPEATS);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	grey = SOIL_load_OGL_texture("resources/camogen/camogrey100.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_TEXTURE_REPEATS);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	yellow = SOIL_load_OGL_texture("resources/camogen/camoyellow100.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_TEXTURE_REPEATS);
	/// <summary>
	/// loading boxes TEXTURES
	/// </summary>
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	boxtx = SOIL_load_OGL_texture("resources/box.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_TEXTURE_REPEATS);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	redboxtx = SOIL_load_OGL_texture("resources/redbox.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_TEXTURE_REPEATS);
	///
	///  LOADING game scenes TEXTURES
	///
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	wall1 = SOIL_load_OGL_texture("resources/world/wall.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n"; 
	ground1 = SOIL_load_OGL_texture("resources/world/groundbetter.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n"; 
	sky1 = SOIL_load_OGL_texture("resources/world/sky800.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n"; 
	wall2 = SOIL_load_OGL_texture("resources/world/wall2.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n"; 
	ground2 = SOIL_load_OGL_texture("resources/world/ground2.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n"; 
	sky2 = SOIL_load_OGL_texture("resources/world/sky2.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n"; 
	wall3 = SOIL_load_OGL_texture("resources/world/wall3.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n"; 
	ground3 = SOIL_load_OGL_texture("resources/world/ground3.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n"; 
	sky3 = SOIL_load_OGL_texture("resources/world/sky3.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	ground6 = SOIL_load_OGL_texture("resources/world/ground6.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	skynight = SOIL_load_OGL_texture("resources/world/skynight1.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	//used clamping to clone pixels
	///
	///  LOADING MENU TEXTURES
	///
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n"; 
	menubg = SOIL_load_OGL_texture("resources/menu/menubg.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n"; 
	play = SOIL_load_OGL_texture("resources/menu/play.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n"; 
	controls = SOIL_load_OGL_texture("resources/menu/controls.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n"; 
	credits = SOIL_load_OGL_texture("resources/menu/credits.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n"; 
	options = SOIL_load_OGL_texture("resources/menu/options.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n"; 
	quit = SOIL_load_OGL_texture("resources/menu/quit.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n"; 
	cursor = SOIL_load_OGL_texture("resources/menu/cursor.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	smallcursor = SOIL_load_OGL_texture("resources/menu/smallcursor.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	pausebg = SOIL_load_OGL_texture("resources/menu/pause.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n"; 
	cont = SOIL_load_OGL_texture("resources/menu/continue.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n"; 
	deathbg = SOIL_load_OGL_texture("resources/menu/deathbg.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n"; 
	retry = SOIL_load_OGL_texture("resources/menu/retry.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	/// <summary>
	/// LOADING CONTROLS MENU TEXTURE
	/// </summary>

	controlsbg = SOIL_load_OGL_texture("resources/menu/controlsbg.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	back = SOIL_load_OGL_texture("resources/menu/back.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	/// <summary>
		/// LOADING OPTIONS MENU TEXTURE
		/// </summary>

	video = SOIL_load_OGL_texture("resources/menu/video.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	keybindings = SOIL_load_OGL_texture("resources/menu/keybindings.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	audio = SOIL_load_OGL_texture("resources/menu/audio.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";

	/// <summary>
		/// LOADING VIDEO MENU TEXTURE
		/// </summary>
	videofg = SOIL_load_OGL_texture("resources/menu/videofg.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	res800 = SOIL_load_OGL_texture("resources/menu/800x600.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	res1200 = SOIL_load_OGL_texture("resources/menu/1200x900.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	res1600 = SOIL_load_OGL_texture("resources/menu/1600x1200.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	quality_low = SOIL_load_OGL_texture("resources/menu/low.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	quality_medium = SOIL_load_OGL_texture("resources/menu/medium.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	quality_high = SOIL_load_OGL_texture("resources/menu/high.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	vsync_on = SOIL_load_OGL_texture("resources/menu/on.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	vsync_off = SOIL_load_OGL_texture("resources/menu/off.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";

	/// <summary>
	///  LOADING GAME UI TEXTURES
	/// </summary>
	useobject = SOIL_load_OGL_texture("resources/menu/useobject.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	/// <summary>
	/// LOADING GATE CONTROLLER TEXTURES
	/// </summary>
	gate_frontback = SOIL_load_OGL_texture("resources/gate/gate_texture.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	gatebar_texture = SOIL_load_OGL_texture("resources/gate/gatebar_texture.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	gatewall = SOIL_load_OGL_texture("resources/gate/gatewall.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	
	metal = SOIL_load_OGL_texture("resources/material/greenmetal.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT | SOIL_FLAG_TEXTURE_REPEATS);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	alum = SOIL_load_OGL_texture("resources/material/alum.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT | SOIL_FLAG_TEXTURE_REPEATS);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	blackalum = SOIL_load_OGL_texture("resources/material/blackalum.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT | SOIL_FLAG_TEXTURE_REPEATS);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";
	orangealum = SOIL_load_OGL_texture("resources/material/orangealum.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT | SOIL_FLAG_TEXTURE_REPEATS);
	loadedtextures++; std::cout << "#### LOADING TEXTURES ! Please wait " << (float)loadedtextures / all_textures << "%\n";

	std::cout << "\033[0m";
}


void Init()
{	
	loadtext();
	//tex_2d = SOIL_load_OGL_texture("TREE1.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
		//SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	//textures.push_back(tex_2d);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	GLfloat light_position[] = { 1.0, 15.0, 1.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_COLOR_MATERIAL);
	//glEnable(GL_NORMALIZE);


	glEnable(GL_DEPTH_TEST);
	glClearColor(0., 0., 0., 1.);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

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
	//heli->rotatebackwing(value);
	//heli->rotatetopwing(value * 3);
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


	// Hier finden die Reaktionen auf eine Ver�nderung der Gr��e des 
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
void onclick_listner(int button,int state ,int x ,int y) {
	ge->controller->onclick_listner(button, state, x, y);
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
	// Hier werden Berechnungen durchgef�hrt, die zu einer Animation der Szene  
	// erforderlich sind. Dieser Prozess l�uft im Hintergrund und wird alle 
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
	beach = new gameScene("base", "game_scene");
	forest = new gameScene("forest","game_scene");
	mainmenu = new menuScene("main", "menu_scene");
	controlsmenu = new menuScene("controls", "menu_scene");
	pause = new menuScene("pause", "menu_scene");
	death = new menuScene("death","menu_scene");
	optionsmenu = new menuScene("options", "menu_scene");
	videomenu = new menuScene("video", "menu_scene"); //to be
	keybindingmenu = new menuScene("keybinding", "menu_scene"); //to be
	audiomenu = new menuScene("audio", "menu_scene"); //to be impl
	ge->addgamescene(base);//0
	ge->addgamescene(beach);//1
	ge->addgamescene(forest);
	ge->addmenuscene(mainmenu);//0
	ge->addmenuscene(pause);//1
	ge->addmenuscene(controlsmenu);//2
	ge->addmenuscene(death);//3
	ge->addmenuscene(optionsmenu);//4
	ge->addmenuscene(videomenu);//5
	ge->addmenuscene(keybindingmenu);//6
	ge->addmenuscene(audiomenu);//7
	ge->setCurrentScene(base);
	//creating gameobjects
	b = new box(0.5, 0.5, 0.5);
	b2 = new box(0.5, 0.5, 0.5);
	b2->setposition(1., 0., 0.);
	b3 = new box(0.5, 0.5, 0.5);
	b3->setposition(1., 0., 2.);
	t = new tank(3.4, 1.8, 3.3);
	t->setposition(15, 0., 4);
	heli.push_back(new Aircraft(7., 2., 1.5, "helicopter"));
	heli.push_back(new Aircraft(7., 2., 1.5, "helicopter", "blackalum"));
	heli.push_back(new Aircraft(7., 2., 1.5, "helicopter", "blackalum"));
	heli.push_back(new Aircraft(7., 2., 1.5, "helicopter", "orangealum"));
	heli[0]->setposition(-20., 0., 1.5 );
	heli[1]->setposition(20., 0., 1.5 );
	heli[2]->setposition(-20., 0., -20. );
	heli[3]->setposition(20., 0., -20. );
	for (int i = 0; i < 12; i++)
		{
		if (i % 3 == 0) tent.push_back(new Tent(3.4, 2.2, 7.6));
		else tent.push_back(new Tent(3.4, 2.2, 3.6));	
		}
	tent[2]->setposition(-30., 0., 6.5);
	tent[1]->setposition(-30., 0., -4.5);
	tent[0]->setposition(-35., 0., 1.5);

	tent[5]->setposition(30., 0., 6.5);
	tent[4]->setposition(30., 0., -4.5);
	tent[3]->setposition(35., 0., 1.5);

	tent[8]->setposition(-30., 0., -16.5);
	tent[7]->setposition(-30., 0., -26.5);
	tent[6]->setposition(-35., 0., -21.5);

	tent[11]->setposition(30., 0., -16.5);
	tent[10]->setposition(30., 0., -26.5);
	tent[9]->setposition(35., 0., -21.5);

	

	cs = new controleStation(4.0, 2.0, 1.);
	cs->setposition(20,0.,10);
	
	
	
	//adding gameobjects
	
	ge->addObjecttocurrentscene(b);
	ge->addObjecttocurrentscene(b2);
	ge->addObjecttocurrentscene(b3);
	for (int i = 0; i < 12; i++)
		ge->addObjecttocurrentscene(tent[i]);
	for (int i = 0; i < 4; i++)
		ge->addObjecttocurrentscene(heli[i]);
	
	ge->addObjecttocurrentscene(cs);
	//adding objects to scenes
	ge->setCurrentScene(beach);
	ge->addObjecttocurrentscene(t); //causing scenes to lag due to high quality chain & rims ,LOL :)
	ge->addObjecttocurrentscene(b);
	ge->addObjecttocurrentscene(b2);
	ge->addObjecttocurrentscene(b3);
	ge->addObjecttocurrentscene(cs);
	for (int i = 0; i < 12; i++)
		ge->addObjecttocurrentscene(tent[i]);
	/**/

	ge->setCurrentScene(mainmenu);

	glutInit(&argc, argv);                // GLUT initialisieren
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(ge->controller->width, ge->controller->height);         // Fenster-Konfiguration
	glutCreateWindow("TANK");   // Fenster-Erzeugung
	glutDisplayFunc(RenderScene);         // Zeichenfunktion bekannt machen
	glutSpecialFunc(arrowfunc);
	glutKeyboardFunc(keyboardfunc);
	glutPassiveMotionFunc(noclick_motion);
	glutMouseFunc(onclick_listner);
	// TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0  
	glutTimerFunc(10, Animate, value);
	glutReshapeFunc(Reshape);
	Init();

	glutMainLoop();
	return 0;
}
