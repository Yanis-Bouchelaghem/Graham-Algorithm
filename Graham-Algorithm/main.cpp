#include "Game.h"
#include "Settings.h"

int main()
{
    using namespace settings;
    Game game{screenWidth,
              screenHeight,
              fps,
              windowTitle };

    while (!game.GameShouldClose())
    {
        game.Tick();
    }
	return 0;
}