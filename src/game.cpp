#include "game.h"

int Game::init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "sdl init failed with error: " << SDL_GetError() << std::endl;
        return 0;
    }

    // create window
    m_window = SDL_CreateWindow("Artilery game", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, m_screen_x, m_screen_y, SDL_WINDOW_SHOWN);

    if (m_window == NULL) {
        std::cout << "SDL_Create window failed with error: " << SDL_GetError() << std::endl;
        return 0;
    }

    m_screen_surface = SDL_GetWindowSurface(m_window);

    SDL_FillRect(m_screen_surface, NULL, SDL_MapRGB(m_screen_surface->format, 0xff, 0xff, 0xff));

    return 1;
}

void Game::render()
{
    SDL_UpdateWindowSurface(m_window);
}
