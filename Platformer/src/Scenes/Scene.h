#pragma once
#include <SDL3/SDL_render.h>
#include <string>
#include <vector>

class Game;
class GameObject;

class Scene {
private:
	std::vector<GameObject*> GameObjects;

public:
	static Scene* Current;

	Scene(std::string name);

	std::string name;

	void Update(Game& game, float deltaTime);
	void Draw(SDL_Renderer* renderer);
	void SetActive(bool state);
	bool AddObject(GameObject* gameObject);
	bool RemoveFromScene(GameObject* gameObject);
};