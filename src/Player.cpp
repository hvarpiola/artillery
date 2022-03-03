#include "Player.h"

Player::Player(std::string name, int location_x, int location_y, SDL_Renderer* renderer)
{
    m_player_name = name;
    m_location_x = location_x;
    m_location_y = location_y;
    m_tank_texture = load_texture("tank1.png", renderer);
    m_turret_texture = load_texture("turret.png", renderer);
}
