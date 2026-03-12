#include "TextureAtlas.h"
#include <iostream>

Texture* TextureAtlas::FromRect(SDL_Renderer* renderer, SDL_Rect* rect)
{
    SDL_Texture* sdl_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, rect->w, rect->h);
    if (!sdl_texture) {
        std::cout << "Unable to load texture from surface." << SDL_GetError() << "\n";
        return nullptr;
    }

    return new Texture{ sdl_texture };
}
