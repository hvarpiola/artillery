#pragma once
#include <SDL2/SDL.h>
#include <iostream>

class Game {
public:
    Game(int screen_x, int screen_y)
    {
        m_screen_x = screen_x;
        m_screen_y = screen_y;
    }
    ~Game() = default;

    int init();

    void run();
    void render();

private:
    SDL_Window* m_window;
    SDL_Surface* m_screen_surface;
    int m_screen_x = 0;
    int m_screen_y = 0;
};
