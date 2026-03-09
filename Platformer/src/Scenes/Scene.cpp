#include "Scene.h"
#include "SceneManagement.h"
#include "Game.h"
#include "../Entities/GameObject.h"

Scene* Scene::Current;


Scene::Scene(std::string name)
{
	this->name = name;
	SceneManagement::Add(this);
}

void Scene::Update(Game& game, float deltaTime)
{
	for (auto& gameObject : GameObjects) {
		if (!gameObject->IsActive || gameObject->IsStatic) { continue; }

		gameObject->Update(game, deltaTime);
	}
}
void Scene::Draw(SDL_Renderer* renderer)
{
	for (auto& gameObject : GameObjects) {
		if (!gameObject->IsActive) { continue; }

		gameObject->Draw(renderer);
	}
}

void Scene::SetActive(bool state)
{
	SceneManagement::SetActive(this, true);
}

bool Scene::AddObject(GameObject* gameObject)
{
	for (auto& found : GameObjects) {
		if (found == gameObject) { return false; }
	}

	GameObjects.push_back(gameObject);
	return true;
}

bool Scene::RemoveFromScene(GameObject* gameObject) {
	if (!gameObject) { return false; }
	
	return std::erase(GameObjects, gameObject);
}
