#include "GameEngine.h"
GameEngine::GameEngine() {
	controller = new Controller(this); 
	status = "dead";
	controlled_object = nullptr; 
	isusing = false;
	hasobjectinrange = false;
}
void GameEngine::setcontrolledobject(GameObject* obj) {
	controlled_object = obj;
	controller->controlled_object = obj; 
	isusing = true;
	if (obj->generaltype._Equal("aircraft"))
		//inside view will be implemented later on
		//controller->setcampos(obj->xoffset , obj->yoffset+1.87, obj->zoffset); //need to find optimal point for the camera to watch the object controlled 
		//outside view for now 
		controller->setcampos(obj->xoffset, obj->yoffset + 3.7, obj->zoffset); //need to find optimal point for the camera to watch the object controlled 2.22
		
	else controller->setcampos(obj->xoffset,obj->yoffset+obj->yLen+0.5,obj->zoffset); //need to find optimal point for the camera to watch the object controlled 
	current_scene->setControllledObject(obj);// will be modified to activate on key press // i think useless
}
void GameEngine::releasecontrolledobject() {
	if (!isusing) std::cout << "player isnt currently using any objects!\n";
	else {
		controller->setcampos(controlled_object->xoffset , 1., controlled_object->zoffset+controlled_object->zLen+0.5);
		//need to find optimal point for the camera to watch the player get off from the object in control
		isusing = false; 
		controlled_object = nullptr;
	}
	
}

/*
@brief checks whether 2 3d objects collides or not
@param border1 border limit of the object 1
@param border2 border limit of the object 2
@return bool indicates if objects are colliding(true)
*/
bool GameEngine::iscolliding(std::vector<float> border1 , std::vector<float> border2) {
	//checks 3d collision
	//border vec will be defined as left,right,top,bot,front,back
	float l1 = border1[0], r1 = border1[1], t1 = border1[2], b1 = border1[3], f1 = border1[4], bk1 = border1[5];
	float l2 = border2[0], r2 = border2[1], t2 = border2[2], b2 = border2[3], f2 = border2[4], bk2 = border2[5];
	//easier to check when 2 objects dont collide 
	return !(r1<l2 || l1>r2 || bk1<f2 || f1>bk2 || b1 > t2 || t1 < b2);
}
/*
@brief checks whether the current object is colliding with other objects i the scene
@param currentobject currentobject (controlled object)
@param o reresents one opf many objects in the current scene
@return bool indicates if objects are colliding(true) 
*/
bool GameEngine::collisiondetection() {
	bool collides = false; 
	for (GameObject* o : scene_objects) {
		collides = collides || iscolliding(controlled_object->getborder(), o->getborder());
 }
	return collides; 
}
void GameEngine::drawCurrentScene() {
	if (current_scene != nullptr)
	{
		if (current_scene->type._Equal("game_scene")) {
			glEnable(GL_LIGHTING);
			glEnable(GL_COLOR_MATERIAL);
			controller->resetlook();
			if (!isusing) { //when not using anyobject the game engine will check if any object is in range
				for (GameObject* o : current_scene->scene_objects) {
					if (o->usable) {
						if (controller->isindetectionrange(o)) {
							hasobjectinrange = true;
							objectinrange = o;
							controller->setmenulook();
							current_scene->displayinrangeui();
							controller->resetlook();
							break;
						}
					}
					else if (o->type._Equal("controlestation")) {
						if (controller->isindetectionrange(o)) o->opengate();
						else o->closegate();
					}
					hasobjectinrange = false; 
				}
			}
			else {
				for (GameObject* o : current_scene->scene_objects) {
					if (o->type._Equal("controlestation")) {
						if (controller->isindetectionrange(o)) o->opengate();
						else o->closegate();
					}
				}
			}
		}
		else { glDisable(GL_LIGHTING); glDisable(GL_COLOR_MATERIAL); controller->setmenulook(); }
		current_scene->display();
	}
	else std::cerr << "CURRENT SCENE UNDEFINED ???\n";
}

void GameEngine::setCurrentScene(Scene* s) {
	if (s->type._Equal("game_scene")) status = "ingame";
	else status = s->name;
	current_scene=s;
	
}
void GameEngine::addgamescene(Scene* s) {
	game_scenes.push_back(s);
}
void GameEngine::addmenuscene(Scene* s) {
	menu_scenes.push_back(s);
}
void GameEngine::addObjecttocurrentscene(GameObject* obj) {
	current_scene->addObject(obj);
}
void GameEngine::changescene(int i) {
	if (!game_scenes.empty()) {
		i = i % game_scenes.size();
		setCurrentScene(game_scenes.at(i));
	}
	else std::cerr << "ERROR SCENES EMPTY !!!\n";
}
void GameEngine::startgame() {
	if (game_scenes.empty()) std::cerr << "ERROR !! No game scenes are created !!\n";
	else {
		setCurrentScene(game_scenes.at(BASE_SCENE)); 
		gamestarted = true;
	}
}
void GameEngine::displaystartmenu() {
	if (menu_scenes.size() < MAIN_MENU+1) std::cerr << "ERROR !! Main menu scene is missing !!\n";
	else setCurrentScene(menu_scenes.at(MAIN_MENU));
}
void GameEngine::selectlevel() {
	if (menu_scenes.size() < LEVEL_SELECTOR + 1) std::cerr << "ERROR !! No Level to select !!\\n";
	else setCurrentScene(menu_scenes.at(LEVEL_SELECTOR));
}
void GameEngine::startlevel(int level_index) {
	//starts a specific level according to the index
	if (game_scenes.empty()) std::cerr << "ERROR !! No game scenes are created !!\n";
	else if(level_index<game_scenes.size()){
		setCurrentScene(game_scenes.at(level_index));
		gamestarted = true;
	}
	else {
		std::cerr << "ERROR !! Game_scene Nr. "<<level_index<<" Can Not Be Found !!\n";
	}
}
void GameEngine::onpause() {
	if (menu_scenes.size() < PAUSE+1) std::cerr << "ERROR !! Pause scene is missing !!\n";
	else setCurrentScene(menu_scenes.at(PAUSE));
}
void GameEngine::backtogame() {
	setCurrentScene(game_scenes.at(BASE_SCENE));
}
void GameEngine::displaycontrols() {
	if (menu_scenes.size() < CONTROLS+1) std::cerr << "ERROR !! controls scene is missing !!\n";
	else setCurrentScene(menu_scenes.at(CONTROLS));
}

void GameEngine::displayvideo() {
	if (menu_scenes.size() < VIDEO+1) std::cerr << "ERROR !! video scene is missing !!\n";
	else setCurrentScene(menu_scenes.at(VIDEO));
}

void GameEngine::displaykeybindings() {
	if (menu_scenes.size() < KEYBINDING+1) std::cerr << "ERROR !! keybindings scene is missing !!\n";
	else setCurrentScene(menu_scenes.at(KEYBINDING));
}

void GameEngine::displayaudio() {
	if (menu_scenes.size() < AUDIO+1) std::cerr << "ERROR !! audio scene is missing !!\n";
	else setCurrentScene(menu_scenes.at(AUDIO));
}
void GameEngine::endgame() {
	if (menu_scenes.size() < END+1) std::cerr << "ERROR !! End scene is missing !!\n";
	else setCurrentScene(menu_scenes.at(END));
}

void GameEngine::displaycredits() {

}
void GameEngine::displayoptions() {
	if (menu_scenes.size() < OPTIONS + 1) std::cerr << "ERROR !! options scene is missing !!\n";
	else setCurrentScene(menu_scenes.at(OPTIONS));
}