#include "Sprite.h"
#include <SDL3_image/SDL_image.h>
#include <iostream>

Sprite* Sprite::MissingSprite;


Sprite::Sprite() {
    if (texture) {
        center = { rect.w * 0.5f, rect.h * 0.5f };
        rect = SDL_FRect{ position.X, position.Y, (float)texture->width * scale.X, (float)texture->height * scale.Y };
    }
    else {
        rect = SDL_FRect{ position.X, position.Y, 0, 0 };
    }
}

Sprite::Sprite(Texture* texture) : Sprite()
{
    SetTexture(texture);
}

Sprite::Sprite(SDL_Texture* sdl_texture) : Sprite()
{
    if (sdl_texture) {
        SetTexture(new Texture{ sdl_texture });
    }
}

Sprite::Sprite(SDL_Renderer* renderer, std::string path) : Sprite()
{
    texture = Texture::LoadTexture(renderer, path);
}

Sprite::~Sprite()
{
    delete texture;
}

void Sprite::Draw(SDL_Renderer* renderer)
{
    centerPos = position + center;

    if (texture) {
        rect = SDL_FRect { centerPos.X, centerPos.Y, (float)texture->width * scale.X, (float)texture->height * scale.Y };
        SDL_RenderTextureRotated(renderer, texture->SDLTexture(), NULL, const_cast<SDL_FRect*>(&rect), rotation, NULL, flipMode);
    }
    else {
        rect = SDL_FRect { centerPos.X, centerPos.Y, 0, 0 };
    }
}

bool Sprite::SetTexture(Texture* texture)
{
    if (!texture) { return false; }

    this->texture = texture;


    return true;
}
