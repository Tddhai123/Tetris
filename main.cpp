#include <bits/stdc++.h>
#include <windows.h>

#include "game.h"

using namespace std;

int main(int argc, char* args[] ) {
    Game *game = Game::getInstance();
    if (game->initialize()) {
        while (!game->isGameExiting()) {
            game->run();
        }
        game->exit();
    }
	return 0;
}
