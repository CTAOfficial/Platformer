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
    name = texture->name;
    SetTexture(texture);
}

Sprite::Sprite(SDL_Texture* sdl_texture) : Sprite()
{
    if (sdl_texture) {
        SetTexture(new Texture{ sdl_texture });
        name = texture->name;
    }
}

Sprite::Sprite(SDL_Renderer* renderer, std::string path) : Sprite()
{
    texture = Texture::LoadTexture(renderer, path);
    name = texture->name;
}

Sprite::~Sprite()
{
    delete texture;
    delete rect;
}

void Sprite::Draw(SDL_Renderer* renderer)
{
    centerPos = position + center;

    /*
     Vector2 pos;
        if (DrawFromTL) {
            center = { rect->w * 0.5f, rect->h * 0.5f };
            centerPos = position + center;
            pos = centerPos;
        }
        else {
            pos = position;
        }

        rect->x = pos.X;
        rect->y = pos.Y; 
        rect->w = (float)texture->width * scale.X;
        rect->h = (float)texture->height * scale.Y;
        SDL_RenderTextureRotated(renderer, texture->SDLTexture(), NULL, const_cast<SDL_FRect*>(rect), rotation, NULL, flipMode);
    }    
    */
    if (texture) {
        rect->x = centerPos.X;
        rect->y = centerPos.Y; 
        rect->w = (float)texture->width * scale.X;
        rect->h = (float)texture->height * scale.Y;
        SDL_RenderTextureRotated(renderer, texture->SDLTexture(), NULL, const_cast<SDL_FRect*>(rect), rotation, NULL, flipMode);
    }
    else {
        rect->x = position.X;
        rect->y = position.Y;
        rect->w = 0;
        rect->h = 0;
    }
}

bool Sprite::SetTexture(Texture* texture)
{
    if (!texture) { return false; }

    this->texture = texture;

    center = { rect->w * 0.5f, rect->h * 0.5f };
    rect = new SDL_FRect{ position.X, position.Y, (float)texture->width * scale.X, (float)texture->height * scale.Y };
    return true;
}
