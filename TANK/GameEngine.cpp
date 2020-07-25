#include "GameEngine.h"
GameEngine::GameEngine() {
	controller = new Controller(this); 
	status = "dead";
	controlled_object = nullptr; 
}
void GameEngine::setcontrolledobject(GameObject* obj) {
	controlled_object = obj;
	controller->controlled_object = obj; 
	current_scene->setControllledObject(obj);// will be modified to activate on key press
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
		if (current_scene->type._Equal("game_scene")) controller->resetlook();
		else controller->setmenulook();
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
	else setCurrentScene(game_scenes.at(BASE_SCENE));
}
void GameEngine::onpause() {
	if (menu_scenes.size() < 2) std::cerr << "ERROR !! Pause scene is missing !!\n";
	else setCurrentScene(menu_scenes.at(PAUSE));
}
void GameEngine::backtogame() {
	setCurrentScene(game_scenes.at(BASE_SCENE));
}
void GameEngine::endgame() {
	if (menu_scenes.size() < 3) std::cerr << "ERROR !! End scene is missing !!\n";
	else setCurrentScene(menu_scenes.at(END));
}
void GameEngine::displaycontrols() {

}
void GameEngine::displaycredits() {

}
void GameEngine::displayoptions() {

}