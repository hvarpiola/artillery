#include "game.h"
#include <iostream>

int main(int argc, char* argv[])
{
    Game* game = new Game(1024, 768);

    game->init();

    game->run();
}
