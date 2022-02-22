#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

class Game {
public:
    Game(int screen_x, int screen_y)
    {
        m_screen_x = screen_x;
        m_screen_y = screen_y;
    }
    ~Game();

    int init();

    void run();
    void render();

private:
    SDL_Surface* load_surface(std::string path);
    SDL_Surface* m_PGNSurface = NULL;
    SDL_Surface* m_tank = NULL;
    SDL_Rect m_tank_rect = {};
    SDL_Window* m_window = NULL;
    SDL_Surface* m_screen_surface = NULL;
    int m_screen_x = 0;
    int m_screen_y = 0;
};
