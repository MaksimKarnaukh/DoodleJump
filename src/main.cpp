#include <iostream>
#include "game_representation/Game.h"
#include "logic_library/Stopwatch.h"

int main() {

    // Program entry point.
    Game game; // Creating our game object.

    logic::Stopwatch* stopwatch = logic::Stopwatch::Instance();
    float frameRate = 60.0f;

    while(!game.GetWindow()->IsDone()){

        stopwatch->tick();

        if (stopwatch->getDeltaTime() >= 1 / frameRate) {

            stopwatch->Reset();
            std::cout << 1 / stopwatch->getDeltaTime() << std::endl;
            // Game loop.
            game.HandleInput();
            game.Update();
            game.Render();
        }
    }

    return 0;
}
