#include "Engine.h"
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <SDL3_image/SDL_image.h>

bool Engine::InitializeLibraries()
{
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		std::cout << "SDL Failed to initialize. " << SDL_GetError() << "\n";;
		return false;
	}

	if (!TTF_Init()) {
		std::cout << "SDL_TTF Failed to initialize. " << SDL_GetError() << "\n";;
		return false;
	}

	if (!MIX_Init()) {
		std::cerr << "SDL_Mixer Failed to Initialize. " << SDL_GetError() << "\n";
		return false;
	}

	return false;
}

bool Engine::Start()
{
	if (!InitializeLibraries()) {
		return false;
	}
}
