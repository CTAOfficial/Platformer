#include <iostream>
#include "src/Windowing/Window.h"
#include "src/Game.h"
#include "DynamicArray.h"
#include <string>
#include <Utilities/Engine.h>


int main() {

	if (Engine::Start()) {
		return -1;
	}

	/*DynamicArray<int> array(2);
	array.push_back(5);
	array.push_back(7);
	array.push_back(7);
	array.push_back(58);
	array.push_back(12);
	for (int i = 0; i < array.Size(); i++) {
		std::cout << array.GetValue(i) << "\n";
	}*/

	std::string name = "Platformer";
	Game* game = new Game(name, Vector2{ 1080, 720 });

	game->Run();

	delete game;
	game = nullptr;

	Engine::Shutdown();
	return 0;
}

