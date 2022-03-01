#include "TextureManager.h"

TextureManager* TextureManager::s_instance = 0;

bool TextureManager::load(std::string file_name, std::string id, SDL_Renderer* renderer)
{
    SDL_Surface* temp_surface = 0;
    temp_surface = IMG_Load(file_name.c_str());

    if (!temp_surface)
        return false;

    SDL_Texture* texture;
    texture = SDL_CreateTextureFromSurface(renderer, temp_surface);

    SDL_FreeSurface(temp_surface);

    if (texture) {
        m_texture_map[id] = texture;
        return true;
    }

    // should not get here, something has to be failing
    return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip)
{
    SDL_Rect src_rect;
    SDL_Rect dest_rect;

    src_rect.x = 0;
    src_rect.y = 0;
    src_rect.w = dest_rect.w = width;
    src_rect.h = dest_rect.h = height;
    dest_rect.x = x;
    dest_rect.y = y;

    SDL_RenderCopyEx(renderer, m_texture_map[id], &src_rect, &dest_rect, 0, 0, flip);
}

void TextureManager::draw_frame(std::string id, int x, int y, int width, int height, int current_row, int current_frame, SDL_Renderer* renderer, SDL_RendererFlip flip)
{
    SDL_Rect src_rect;
    SDL_Rect dest_rect;

    src_rect.x = width * current_frame;
    src_rect.y = height * (current_row - 1);
    src_rect.w = dest_rect.w = width;
    src_rect.h = dest_rect.h = height;
    dest_rect.x = x;
    dest_rect.y = y;

    SDL_RenderCopyEx(renderer, m_texture_map[id], &src_rect, &dest_rect, 0, 0, flip);
}
void TextureManager::draw_rotated(std::string id, int x, int y, int width, int height, double angle, SDL_Point* center, SDL_Renderer* renderer, SDL_RendererFlip flip)
{

    SDL_Rect src_rect;
    SDL_Rect dest_rect;

    src_rect.x = 0;
    src_rect.y = 0;
    src_rect.w = dest_rect.w = width;
    src_rect.h = dest_rect.h = height;
    dest_rect.x = x;
    dest_rect.y = y;

    SDL_RenderCopyEx(renderer, m_texture_map[id], &src_rect, &dest_rect, angle, center, flip);
}
