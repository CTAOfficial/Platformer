#pragma once
#include "Entities/GameObject.h"
#include <vector>

class Animation;
class Sprite;

class AnimatedSprite : public GameObject {
private:
	Animation* animation = nullptr;

public:
	AnimatedSprite(Animation* anim) : animation{ anim } {}
	AnimatedSprite(Sprite* sprites[], int size);
	AnimatedSprite(const std::vector<Sprite*>& sprites);
};