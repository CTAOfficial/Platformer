#include "Animation.h"
#include "Sprites/Sprite.h"
#include "Sprites/SpriteSheet.h"
#include <cassert>
#include <format>
#include <iostream>


Animation::Animation(SpriteSheet* sheet)
{
	assert(!sheet, "Animation sheet cannot be nullptr!");

	// TODO: Process sprites
}

Animation::Animation(Sprite* frames[], int size)
{
	int current = 0;

	for (int i = 0; i < size; i++) {
		Sprite* sprite = frames[i];
		if (!sprite) 
		{ 
			std::cout << std::format("[Animation] Sprite at index {} is nullptr", i);
			continue; 
		}

		auto pair = std::pair<int, Sprite*>{current++, sprite};
		this->frames.emplace(pair);
	}
}

Animation::Animation(const std::vector<Sprite*>& frames)
{
	int current = 0;
	for (auto& sprite : frames) {
		auto pair = std::pair<int, Sprite*>{ current++, sprite };
		this->frames.emplace(pair);
	}
}

void Animation::Start()
{
	isPlaying = true;
}

void Animation::Stop()
{
	isPlaying = false;
}

void Animation::Animate()
{
	if (index <= last) {
		index = 0;
	}

	index += skip;	
	Sprite* sprite = frames.at(index);

	if (sprite) { frame = sprite; }
}
