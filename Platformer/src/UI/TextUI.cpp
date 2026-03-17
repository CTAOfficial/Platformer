#include "TextUI.h"
#include <string>
#include <iostream>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3/SDL_error.h>


TextUI::TextUI(std::string fontPath, SDL_Renderer* renderer, Vector2 pos, RGBA rgba) : Basic2D(pos, rgba)
{
	this->renderer = renderer;
	color = { rgba.R, rgba.G, rgba.B, rgba.A };

	font = new Font{ TTF_OpenFont(fontPath.c_str(), 12) };
	if (!font) {
		std::cout << "Failed to retrive font '" + fontPath + "'\n";
		std::cout << SDL_GetError() << "\n";
	}

	SetText("Sample Text");
}
TextUI::~TextUI() 
{
	SDL_DestroyTexture(texture);
	font = nullptr;
}

void TextUI::Draw(SDL_Renderer* renderer) {

	rect.x = position.X + offset.X;
	rect.y = position.Y + offset.Y;
	SDL_SetRenderDrawColor(renderer, colour.R, colour.G, colour.B, colour.A);
	SDL_RenderTexture(renderer, texture, NULL, &rect);
}

void TextUI::SetText(std::string input)
{
	surface = TTF_RenderText_Blended(font->SDLFont(), input.c_str(), 0, font->color);
	if (!surface) {
		std::cout << "Could not create surface.";
		return;
	}

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_DestroySurface(surface);
	text = input;

	SDL_GetTextureSize(texture, &rect.w, &rect.h);
}

void TextUI::SetSize(float size) {
	font->SetSize(size);
}