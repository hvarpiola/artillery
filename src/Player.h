#pragma once

#include "GameObject.h"
#include <SDL2/SDL.h>
#include <string>

class Player : public GameObject {
public:
    Player(std::string name, int location_x, int location_y, SDL_Renderer* renderer);

    ~Player() override { }
    void load(int x, int y, int width, int height, std::string id)
    {
        GameObject::load(x, y, width, height, id);
    }
    // void draw(SDL_Renderer* renderer)
    //{
    // GameObject::draw(renderer);
    //}

    // void update() override
    //{
    // std::cout << "@Player::update()" << std::endl;
    //}
    void clear();

private:
    std::string m_player_name = {};
    int m_score = 0;
    int m_turrent_angel = 0;
    int m_location_x = 0;
    int m_location_y = 0;
    SDL_Texture* m_tank_texture = nullptr;
    SDL_Texture* m_turret_texture = nullptr;
};
