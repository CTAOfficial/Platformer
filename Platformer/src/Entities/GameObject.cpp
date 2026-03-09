#include "GameObject.h"
#include "Sprites/Sprite.h"
#include "EntityManager.h"
#include "Scenes/Scene.h"
#include "Scenes/SceneManagement.h"


GameObject::GameObject() : Object()
{
	EntityManager::Add(this);
	SceneManagement::MoveToScene(this, Scene::Current);
}

void GameObject::Draw(SDL_Renderer* renderer)
{
	if (sprite != nullptr) {
		sprite->position = position;
		sprite->Draw(renderer);
	}
}

void GameObject::Destroy(GameObject& entity) {
	EntityManager::AddToRemove(&entity);
}