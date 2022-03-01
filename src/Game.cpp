#include "Game.h"

Game::~Game()
{
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    delete m_player;
    SDL_Quit();
}

int Game::init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "sdl init failed with error %s\n", SDL_GetError());
        return 0;
    }

    // Initialize logging
    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_WARN);

    // create window
    m_window = SDL_CreateWindow("Artilery game", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, m_screen_x, m_screen_y, 0);

    if (m_window == NULL) {
        std::cout << "SDL_Create window failed with error: " << SDL_GetError() << std::endl;
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "SDL_Create window failed with error: %s\n", SDL_GetError());
        return 0;
    }

    // Initialize renderer
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_SOFTWARE);

    if (m_renderer == NULL) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Renderer init failed %s", SDL_GetError());
        return 0;
    }

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);

    // Initialize PNG loading
    static int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "IMG_Init failed for PNG image with error: %s\n", SDL_GetError());
        return 0;
    }
    // Get screen surface
    // m_screen_surface = SDL_GetWindowSurface(m_window);
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Inits completed");
    return 1;

    TextureManager::the()->load("./media/tank.png", "tank", m_renderer);

    m_player = new Player("Jorma");

    m_player->load(100, 100, 100, 100, "tank");
}

void Game::render()
{
    SDL_RenderClear(m_renderer);
    m_player->draw(m_renderer);
    SDL_RenderPresent(m_renderer);
}

void Game::update()
{
    m_player->update();
}

void Game::handle_events()
{
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            m_running = false;
            break;

        default:
            break;
        }
    }
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
