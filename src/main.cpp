#include <iostream>
#include "game_representation/Game.h"
//#include "logic_library/Stopwatch.h"
#include <thread>

int main() {

    // Program entry point.
    Game game; // Creating our game object.

    logic::Stopwatch* stopwatch = logic::Stopwatch::Instance();

    float frameRate = 60.0f;

    while(!game.GetWindow()->IsDone()){

        stopwatch->tick();

        if (stopwatch->getDeltaTime() < (1 / frameRate)) {
            std::chrono::milliseconds ms = std::chrono::milliseconds((int)(((1/frameRate) - stopwatch->getDeltaTime())*1000));
            std::this_thread::sleep_for(ms);
            std::cout << ms.count() << endl; ////
        }

        stopwatch->tick(); // de verstreken milliseconden erbij.

        std::cout /* << stopwatch->getDeltaTime() << "  " */ << 1 / stopwatch->getDeltaTime() << std::endl; ////

        stopwatch->Reset(); // mStartTime = now (tijd verstreken is terug 0)

        // Game loop.
        game.HandleInput();
        game.Update();
        game.Render();
        //sf::sleep(sf::seconds(0.1));

    }

    return 0;
}
