#pragma once
#include "Entities/Object.h"
#include <filesystem>
#include <string>

class TextAsset : public Object {
public:
	using Object::Object;
	TextAsset(std::string file);
	TextAsset(std::filesystem::path& file);

	std::string text;
	std::string extension;

	bool ReadFromFile(std::string path);
};