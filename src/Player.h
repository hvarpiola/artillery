#pragma once

#include "GameObject.h"
#include <SDL2/SDL.h>
#include <string>

class Player : public GameObject {
public:
    Player(std::string name)
    {
        m_player_name = name;
    }

    ~Player() override { }
    void load(int x, int y, int width, int height, std::string id)
    {
        GameObject::load(x, y, width, height, id);
    }
    // void draw(SDL_Renderer* renderer)
    //{
    // GameObject::draw(renderer);
    //}

    // void update();
    void clear();

private:
    std::string m_player_name = {};
    int m_score = 0;
};
