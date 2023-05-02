#include "raylib.h"
#include "Game.h"
#include "Board.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    Game game{screenWidth, screenHeight,60, "Tetris game"};

    while (!game.GameShouldClose()) {
        game.Tick();
    }
    return 0;
}