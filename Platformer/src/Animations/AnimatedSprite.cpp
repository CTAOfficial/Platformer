#include "AnimatedSprite.h"
#include "Sprites/Sprite.h"
#include "Animations/Animation.h"

AnimatedSprite::AnimatedSprite(Sprite* sprites[], int size)
{
	animation = new Animation{ sprites, size };
}

AnimatedSprite::AnimatedSprite(const std::vector<Sprite*>& sprites)
{
	animation = new Animation{ sprites };
}
