#include "game.h"

Game::~Game()
{
    // SDL_FreeSurface(m_
}

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

    // Initialize PNG loading
    static int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        std::cout << "IMG_Init failed for PNG image with error: " << IMG_GetError() << std::endl;
        return 0;
    }

    // Get screen surface
    m_screen_surface = SDL_GetWindowSurface(m_window);

    m_PGNSurface = Game::load_surface("./media/map1_ground.png");
    if (m_PGNSurface == NULL) {
        std::cout << "failed to load png image" << std::endl;
        return 0;
    }

    m_tank = Game::load_surface("./media/tank.png");
    if (m_tank == NULL) {
        std::cout << "Failed to load tank image " << std::endl;
        return 0;
    }
    // SDL_FillRect(m_screen_surface, NULL, SDL_MapRGB(m_screen_surface->format, 0xff, 0xff, 0xff));

    return 1;
}

void Game::render()
{
    SDL_UpdateWindowSurface(m_window);
}

void Game::run()
{
    bool quit = false;

    SDL_Event event;

    while (!quit) {
        while (SDL_PollEvent(&event) != 0)
            if (event.type == SDL_QUIT)
                quit = true;
        SDL_BlitSurface(m_PGNSurface, NULL, m_screen_surface, NULL);
        m_tank_rect.x = 100;
        m_tank_rect.y = 200;
        SDL_BlitSurface(m_tank, NULL, m_screen_surface, &m_tank_rect);
        Game::render();
    }
}

SDL_Surface* Game::load_surface(std::string path)
{
    SDL_Surface* Optimized_image = NULL;

    // Load image at specific path
    SDL_Surface* Loaded_image = IMG_Load(path.c_str());

    if (Loaded_image == NULL) {
        std::cout << "Unable to load image: " << path << " With error: " << IMG_GetError() << std::endl;
        return NULL;
    }

    Optimized_image = SDL_ConvertSurface(Loaded_image, m_screen_surface->format, 0);

    if (Optimized_image == NULL) {
        std::cout << "Unable to load image: " << path << " With error: " << SDL_GetError() << std::endl;
        return NULL;
    }

    SDL_FreeSurface(Loaded_image);

    return Optimized_image;
}

SDL_Texture* load_texture(std::string path)
{

    SDL_Texture* texture = NULL;

    // TODO: Check for SDL_Logmessage stuff
    return texture;
}
