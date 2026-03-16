#include "TextAsset.h"
#include <fstream>
#include <iostream>

TextAsset::TextAsset(std::string file)
{
	ReadFromFile(file);
}

TextAsset::TextAsset(std::filesystem::path& path)
{
	ReadFromFile(path.string());
}

bool TextAsset::ReadFromFile(std::string path)
{
	std::string::size_type ext(path.find_last_of('.'));
	name = path.substr(path.find_last_of("\\", ext));
	extension = path.substr(ext, path.size());

	std::ifstream file(path);
	if (!file.is_open()) {
		std::cerr << "Error opening file '" + path + "'!\n";
		return false;
	}

	text = std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

	file.close();
	return true;
}
