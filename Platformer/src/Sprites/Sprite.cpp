#include "Sprite.h"
#include <SDL3_image/SDL_image.h>
#include <iostream>

Sprite* Sprite::MissingSprite;


Sprite::Sprite() {
    if (texture) {
        center = { rect->w * 0.5f, rect->h * 0.5f };
        rect = new SDL_FRect{ position.X, position.Y, (float)texture->width * scale.X, (float)texture->height * scale.Y };
    }
    else {
        rect = new SDL_FRect{ position.X, position.Y, 0, 0 };
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
    delete rect;
}

void Sprite::Draw(SDL_Renderer* renderer)
{
    centerPos = position + center;

    if (texture) {
        rect->x = centerPos.X;
        rect->y = centerPos.Y; 
        rect->w = (float)texture->width * scale.X;
        rect->h = (float)texture->height * scale.Y;
        SDL_RenderTextureRotated(renderer, texture->SDLTexture(), NULL, const_cast<SDL_FRect*>(rect), rotation, NULL, flipMode);
    }
    else {
        rect->x = centerPos.X;
        rect->y = centerPos.Y;
        rect->w = 0;
        rect->h = 0;
    }
}

bool Sprite::SetTexture(Texture* texture)
{
    if (!texture) { return false; }

    this->texture = texture;


    return true;
}
