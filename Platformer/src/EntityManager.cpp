#include "EntityManager.h"
#include "Entities/GameObject.h"

std::vector<GameObject*> EntityManager::Entities;
std::queue<GameObject*> EntityManager::ConstructionQueue;
std::stack<GameObject*> EntityManager::DestroyQueue;
int EntityManager::CurrentID = 0;

void EntityManager::InitializeObject(Object* object)
{
	object->ID = ++CurrentID;

	// TODO: Store unused/freed ID's and free ID's on Object destruction, then Fetch an ID based on what's available
}

void EntityManager::Add(GameObject* entity)
{
	ConstructionQueue.push(entity);
}

void EntityManager::AddToRemove(GameObject* entity) {
	DestroyQueue.push(entity);
}
void EntityManager::Remove(GameObject* entity)
{
	std::erase(Entities, entity);
}

void EntityManager::PreUpdate()
{
	while (!DestroyQueue.empty()) {
		GameObject* entity = DestroyQueue.top();
		Remove(entity);
		DestroyQueue.pop();
		delete entity;
	}

	while (!ConstructionQueue.empty()) {
		GameObject* entity = ConstructionQueue.front();
		Entities.push_back(entity);
		ConstructionQueue.pop();
	}
}

void EntityManager::Shutdown() {
	for (GameObject* entity : Entities) {
		delete entity;
	}
}
