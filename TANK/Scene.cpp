#include "Scene.h"
Scene::Scene() : name("default"),type("default") {
	controlled_object = nullptr;
}
void Scene::addObject(GameObject* obj) {
	scene_objects.push_back(obj);
}
void Scene::setControllledObject(GameObject* obj) {
	controlled_object = obj;
}
