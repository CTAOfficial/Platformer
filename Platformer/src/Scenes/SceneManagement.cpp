#include "SceneManagement.h"
#include "Game.h"
#include "Entities/GameObject.h"

std::vector<Scene*> SceneManagement::ActiveScenes;
std::map<std::string, Scene*> SceneManagement::Scenes;


void SceneManagement::Update(Game& game, float deltaTime)
{
	if (!Scene::Current && ActiveScenes.size() > 0) { Scene::Current = ActiveScenes[0]; }

	for (auto& scene : ActiveScenes) {
		scene->Update(game, deltaTime);
	}
}

void SceneManagement::Draw(SDL_Renderer* renderer)
{
	for (auto& scene : ActiveScenes) {
		scene->Draw(renderer);
	}
}

Scene* SceneManagement::GetActiveScene(std::string name) {
	for (auto& scene : ActiveScenes) {
		if (scene->name == name) { return scene; }
	}
	return nullptr;
}
bool SceneManagement::MoveToScene(GameObject* gameObject, Scene* scene)
{
	if (!gameObject) 
	{ 
		//..TODO: Log
		return false; 
	}
	if (!scene)
	{
		//..TODO: Log
		return false;
	}

	if (gameObject->scene) {
		gameObject->scene->RemoveFromScene(gameObject);
	}
	scene->AddObject(gameObject);
}
void SceneManagement::SetActive(std::string name, bool state) {
	SetActive(Scenes[name], state);
}
void SceneManagement::SetActive(Scene* scene, bool state) {
	if (GetActiveScene(scene->name) && state) { return; }
	if (!GetActiveScene(scene->name) && state) 
	{ 
		ActiveScenes.push_back(scene); 
		if (!Scene::Current) { Scene::Current = scene; }
		return; 
	}

	std::erase(ActiveScenes, scene);	
}

void SceneManagement::Remove(Scene* scene) {
	Scenes[scene->name] = nullptr;
	std::erase(ActiveScenes, scene);
}