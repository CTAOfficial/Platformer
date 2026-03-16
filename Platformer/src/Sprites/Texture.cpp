#include "Texture.h"
#include <SDL3_image/SDL_image.h>
#include <iostream>

Texture::Texture(SDL_Texture* sdl_texture, SDL_ScaleMode mode)
{
    texture = sdl_texture;

    width = texture->w;
    height = texture->h;

    SetScaleMode(mode);
}

Texture::~Texture()
{
    SDL_DestroyTexture(texture);
}

bool Texture::LoadTexture(SDL_Renderer* renderer, std::string path, Texture& outTexture)
{
    Texture* texture = LoadTexture(renderer, path);
    if (!texture) { return false; }

    outTexture = *texture;
    return true;
}

void Texture::SetScaleMode(SDL_ScaleMode mode)
{
    scaleMode = mode;

    // Texture Scaling (Jagged Edges etc)
    SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
}

Texture* Texture::FromSurface(SDL_Renderer* renderer, SDL_Surface* surface)
{
    if (!renderer) {
        std::cout << "Provided renderer is nullptr.";
        return nullptr;
    }
    if (!surface) {
        std::cout << "Provided surface is nullptr.";
        return nullptr;
    }

    SDL_Texture* sdl_texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_DestroySurface(surface);
    if (sdl_texture == nullptr)
    {
        std::cout << "Unable to load texture from surface." << SDL_GetError() << "\n";
        return nullptr;
    }

    return new Texture{ sdl_texture };
}

Texture* Texture::LoadTexture(SDL_Renderer* renderer, std::string path)
{
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (surface == nullptr)
    {
        std::cout << "Unable to load image '" << path << "'! SDL_image Error: " << SDL_GetError() << "\n";
        return nullptr;
    }

    return FromSurface(renderer, surface);;
}