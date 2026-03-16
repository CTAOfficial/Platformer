#pragma once
#include "Entities/Object.h"
#include "TextAsset.h"
#include <iostream>
#include <filesystem>
#include <map>
#include <string>
#include <SDL3/SDL_render.h>
#include <type_traits>

// https://brightspace.uos.ac.uk/d2l/le/lessons/84561/topics/1405619 - 38:33
//..TODO: Delete assets on shutdown (after entities destroyed)
class Assets {
private:
	static std::map<std::string, Object*> assets;

	static bool AddAsset(Object* asset, std::string path);
	static void CheckDirectory(std::string path, bool recursive = false);
	static Object* ConvertToAsset(std::filesystem::path filePath, SDL_Renderer* renderer = Renderer);
	static TextAsset* CheckTextAsset(std::filesystem::path& file);
	static bool ValidateFile(std::filesystem::path& file);

public:
	static std::string AssetPath;
	static SDL_Renderer* Renderer;
	static float DefaultFontSize;

	static void Load(std::string path, bool recursive = false);
	static void Load(std::filesystem::directory_entry, bool recursive = false);
	static void LoadAll(std::string path = AssetPath);

	template <typename T>
	static T Get(std::string path) {

		// This only appears to trigger when T does inherit, regardless of the exclamation
		/*if (!std::is_base_of<Object, T>::value) {
			std::cerr << "Type does not derive from Object. Path: " << path << "\n";
			return nullptr;
		}*/

		if (!assets[path]) {
			std::cerr << "Tried to get Object of index '" << path << "' which doesnt exist.\n";
			return nullptr;
		}

		T item = dynamic_cast<T>(assets[path]);
		if (item) {
			return item;
		}

		std::cerr << "Type does not derive from Object. Path: " << path << "\n";
		return nullptr;
	}

	//static bool Add(std::string path);
	//template<class Object>
	//static Object* Get(std::string path);
};