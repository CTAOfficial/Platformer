#pragma once
#include <vector>
#include <queue>
#include <stack>
#include <SDL3/SDL_render.h>

class Game;
class Object;
class GameObject;

class EntityManager {
private:
	static std::vector<GameObject*> Entities;
	static std::queue<GameObject*> ConstructionQueue;
	static std::stack<GameObject*> DestroyQueue;
	static void Remove(GameObject* entity);

	static int CurrentID;

public:
	// TODO: Separate object and gameobject handling
	static void InitializeObject(Object* object);
	static void Add(GameObject* entity);
	static void AddToRemove(GameObject* entity);
	static void PreUpdate();
	static void Shutdown();

	static std::vector<GameObject*> GetEntities() {
		return Entities;
	}
};