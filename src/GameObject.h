#pragma once

#include "TextureManager.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <string>

// Game objects base class
class GameObject {
public:
    virtual ~GameObject() { }
    void load(int x, int y, int width, int height, std::string id)
    {
        m_x = x;
        m_y = y;
        m_width = width;
        m_height = height;
        m_texture_id = id;
        m_current_frame = 1;
        m_current_row = 1;
    }
    virtual void draw(SDL_Renderer* renderer)
    {
        TextureManager::the()->draw_frame(m_texture_id, m_x, m_y, m_width, m_height, m_current_row, m_current_frame, renderer);
    }
    virtual void update()
    {
        // std::cout << "@ Gameobject::update()" << std::endl;
    }
    virtual void clean() { }

protected:
    std::string m_texture_id {};

    int m_current_frame = 0;
    int m_current_row = 0;

    int m_x = 0;
    int m_y = 0;

    int m_width = 0;
    int m_height = 0;
};
