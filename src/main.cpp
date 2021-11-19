#include <iostream>
#include "game_representation/Game.h"

int main() {

    // Program entry point.
    Game game; // Creating our game object.
    while(!game.GetWindow()->IsDone()){
        // Game loop.
        game.HandleInput();
        game.Update();
        game.Render();
    }

    return 0;
}
