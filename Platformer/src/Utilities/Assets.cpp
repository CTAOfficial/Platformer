#include "Assets.h"
#include "Sprites/Texture.h"
#include "UI/Font.h"
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

    // Iterate through files (non-recursive)
    //std::cout << "\nFiles in folder:\n";
    for (const auto& entry : fs::directory_iterator(path)) {
        Load(entry, true);
    }

    
}

Object* Assets::ConvertToAsset(std::filesystem::path filePath, SDL_Renderer* renderer)
{
    if (!Renderer) { return nullptr; }
    std::string file = filePath.filename().string();
    std::string path = filePath.string();

    //SDL_Surface* surface = nullptr;
    if (SDL_Surface* surface = IMG_Load(path.c_str())) {
        Texture* texture = Texture::FromSurface(renderer, surface);
        return texture;
    }
    else if (TTF_Font* ttf_font = TTF_OpenFont(path.c_str(), DefaultFontSize)) {
        Font* font = new Font{ ttf_font };
        return font;
    }

    std::cerr << "Cannot Convert path to Asset: " << path << "\n";
    return nullptr;
}

void Assets::LoadAll(std::string path)
{
    if (!Renderer) { return; }
    Load(path, true);
}

void Assets::Load(std::string path, bool recursive)
{
    /*if (recursive) {
        for (const auto& entry : fs::directory_iterator(path)) {
            Load(entry, recursive);
        }
    }
    else {
        Load(fs::directory_entry(path));
    }*/


    try {
        if (!fs::exists(path)) {
            std::cerr << "Error: Path does not exist.\n";
            return;
        }
        if (!fs::is_directory(path)) {
            std::cerr << "Error: Path is not a directory.\n";
            return;
        }

        CheckDirectory(path);

    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << '\n';
        return;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return;
    }
}

void Assets::Load(fs::directory_entry entry, bool recursive)
{
    if (!Renderer) { return; }

    fs::path path = entry.path();
    if (fs::is_regular_file(entry.status())) {
        std::cout << "File: " << path.filename().string() << '\n';

        if (Object* object = ConvertToAsset(path)) {
            std::string string = path.string();
            if (path.string().starts_with(AssetPath)) {
                //string = entry.;
            }

            AddAsset(object, string);
        }
    }
    else if (fs::is_directory(entry.status()) && recursive) {
        std::cout << "Directory: " << entry.path().filename().string() << '\n';
        Load(path.string());
    }

    // Optional: Recursive iteration
    /*std::cout << "\nRecursive listing:\n";
    for (const auto& entry : fs::recursive_directory_iterator(path)) {
        std::cout << entry.path().string() << '\n';
    }*/
}
