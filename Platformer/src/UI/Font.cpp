#include "Font.h"

Font::Font(TTF_Font* font)
{
	this->font = font;
}

Font::Font(TTF_Font* font, RGBA rgba) : Font(font)
{
	color = { rgba.R, rgba.G, rgba.B, rgba.A };
}

Font::Font(TTF_Font* font, SDL_Color color) : Font(font)
{
	this->color = color;
}

Font::~Font()
{
	TTF_CloseFont(font);
}

void Font::SetSize(float size)
{
	TTF_SetFontSize(font, size);
}
