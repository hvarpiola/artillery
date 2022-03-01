#include "Game.h"
#include <iostream>

int main(int argc, char* argv[])
{
    Game* game = new Game(1024, 768);

    game->init();

    while (game->running()) {
        game->handle_events();
        game->update();
        game->render();
    }
}
