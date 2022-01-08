// Sources:
// Source for textures: https://github.com/shlapkoff/DoodleJump/tree/master/Doodle%20Jump/images
// https://www.learncpp.com/cpp-tutorial/sharing-global-constants-across-multiple-files-using-inline-variables/

#include "game_representation/Game.h"
#include <iostream>

int main()
{

        // Program entry point.
        representation::Game game; // Creating our game object.

        game.runGameLoop();

        return 0;
}
