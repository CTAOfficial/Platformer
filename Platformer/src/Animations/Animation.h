#pragma once
#include "../Entities/Object.h"
#include <map>
#include <vector>

class Sprite;
class SpriteSheet;

// QUERY: Make generic class?
class Animation : public Object {
private:
	bool isPlaying = false;
	int last = 0; // the last frame;

	Sprite* frame = nullptr;
	std::map<int, Sprite*> frames;

public:
	Animation(SpriteSheet* sheet);
	Animation(Sprite* frames[], int size);
	Animation(const std::vector<Sprite*>& frames);

	int index = 0;
	int skip = 1;

	void Start();
	void Stop();

	void Animate();

	bool IsPlaying() const {
		return isPlaying;
	}
	Sprite* GetFrame() const {
		return frame;
	}
};