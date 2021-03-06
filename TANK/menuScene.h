#pragma once
#include "Scene.h"
#include <GL/freeglut.h>
#include <vector>
#include <string>
#include <iostream>

extern GLuint menubg, play, controls, credits, options, quit,cursor,deathbg,cont,pausebg,retry,controlsbg,back,video,keybindings,audio;
extern GLuint videofg, res800, res1200, res1600, quality_low, quality_medium, quality_high, vsync_on, vsync_off,smallcursor;//video menu textures
extern GLuint level1, level2, level1_selected, level2_selected; //level selector
extern GLuint keybinding_bg,letter_cursor,new_key; //keybinding menu
extern std::vector<GLuint> letters; //all chars vectors
class menuScene :  public Scene
{
public : 

	menuScene();
	menuScene(std::string n = "menu", std::string t = "menu_scene");
	void display();
	void drawbackground();
	void drawbuttons();
	void drawcursor();
	void incrementcursorposition();
	void decrementcursorposition();
	void changecursorposition(int position);
	void changeres(int x);
	void changequal(int x);
	void changevsync();
};

