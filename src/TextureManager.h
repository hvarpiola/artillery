#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>

class TextureManager {
public:
    // singleton
    static TextureManager* the()
    {
        if (s_instance == nullptr)
            s_instance = new TextureManager();
        return s_instance;
    }

    bool load(std::string file_name, std::string id, SDL_Renderer* renderer);
    void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void draw_frame(std::string id, int x, int y, int width, int height, int current_row, int current_frame, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void draw_rotated(std::string id, int x, int y, int width, int height, double angle, SDL_Point* center, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
    TextureManager() { } // required for singleton
    std::map<std::string, SDL_Texture*> m_texture_map = {};

    static TextureManager* s_instance;
};
