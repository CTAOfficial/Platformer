#include "Assets.h"
#include "Sprites/Texture.h"
#include "TextAsset.h"
#include "UI/Font.h"
#include <algorithm>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>


std::string Assets::AssetPath;
SDL_Renderer* Assets::Renderer;
float Assets::DefaultFontSize;
std::map<std::string, Object*> Assets::assets;

bool Assets::AddAsset(Object* asset, std::string path)
{
    if (assets.contains(path)) { return false; }

    assets[path] = asset;
    return false;
}

void Assets::CheckDirectory(std::string path, bool recursive)
{
    if (!Renderer) { return; }

    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        Load(entry, true);
    }    
}

Object* Assets::ConvertToAsset(std::filesystem::path filePath, SDL_Renderer* renderer)
{
    if (!Renderer) { return nullptr; }
    std::filesystem::path  file = filePath.filename();
    std::string path = filePath.string();

    if (!ValidateFile(file)) {
        return nullptr; 
    }

    if (TextAsset* asset = CheckTextAsset(filePath)) {
        return asset;
    }
    else if (SDL_Surface* surface = IMG_Load(path.c_str())) {
        Texture* texture = Texture::FromSurface(renderer, surface);
        return texture;
    }
    else if (TTF_Font* ttf_font = TTF_OpenFont(path.c_str(), DefaultFontSize)) {
        Font* font = new Font{ ttf_font };
        font->name = file.filename().string();
        return font;
    }

    std::cerr << "Cannot Convert path to Asset: " << path << "\n";
    return nullptr;
}

TextAsset* Assets::CheckTextAsset(std::filesystem::path& file)
{
    std::string extension = file.extension().string();

    if (extension == ".txt" ||
        extension == ".xml") {
        return new TextAsset{ file };
    }

    return nullptr;
}

bool Assets::ValidateFile(std::filesystem::path& file)
{
    std::string extension = file.extension().string();

    if (extension == ".lnk" ||
        extension == ".url") {
        return false; 
    }

    return true;
}

void Assets::LoadAll(std::string path)
{
    if (!Renderer) { return; }
    Load(path, true);
}

void Assets::Load(std::string path, bool recursive)
{
    try {
        if (!std::filesystem::exists(path)) {
            std::cerr << "Error: Path does not exist.\n";
            return;
        }
        if (!std::filesystem::is_directory(path)) {
            std::cerr << "Error: Path is not a directory.\n";
            return;
        }

        CheckDirectory(path);
    }
    catch (const std::filesystem::filesystem_error& e) {
        //..TODO: Log
        std::cerr << "Filesystem error: " << e.what() << '\n';
        return;
    }
    catch (const std::exception& e) {
        //..TODO: Log
        std::cerr << "Error: " << e.what() << '\n';
        return;
    }
}

void Assets::Load(std::filesystem::directory_entry entry, bool recursive)
{
    if (!Renderer) { return; }

    std::filesystem::path path = entry.path();
    if (std::filesystem::is_regular_file(entry.status())) {
        std::cout << "\nFile: " << path.filename().string() << '\n';

        if (Object* object = ConvertToAsset(path)) {
            std::string string = path.string();

            if (path.string().starts_with(AssetPath)) {
                size_t pos = path.string().find(AssetPath);

                if (pos != std::string::npos) {
                    string.erase(pos, AssetPath.length());
                }
            }


            std::replace(string.begin(), string.end(), '\\', '/');
            std::cout << "\t" << string;
            AddAsset(object, string);
        }
    }
    else if (std::filesystem::is_directory(entry.status()) && recursive) {
        std::cout << "\n========================================================\n";
        std::cout << "\n\tDirectory: " << entry.path().string() << "\n";
        std::cout << "\n========================================================\n";
        Load(path.string());
    }

    // Optional: Recursive iteration
    /*std::cout << "\nRecursive listing:\n";
    for (const auto& entry : fs::recursive_directory_iterator(path)) {
        std::cout << entry.path().string() << '\n';
    }*/
}
