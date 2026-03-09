#pragma once
#include "Scene.h"
#include <map>
#include <SDL3/SDL_render.h>
#include <string>
#include <vector>

class Game;

static class SceneManagement {
private:
	static std::vector<Scene*> ActiveScenes;
	static std::map<std::string, Scene*> Scenes;

public:
	static void Update(Game& game, float deltaTime);
	static void Draw(SDL_Renderer* renderer);


	static Scene* GetActiveScene(std::string name);
	static bool MoveToScene(GameObject* gameObject, Scene* scene);

	static void SetActive(std::string name, bool state);
	static void SetActive(Scene* scene, bool state);

	static void Remove(Scene* scene);

	static bool Add(Scene* scene) {
		if (Scenes[scene->name]) { return false; }

		Scenes[scene->name] = scene;
		return true;
	}
};