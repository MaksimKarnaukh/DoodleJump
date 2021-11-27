//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_GAME_H
#define DOODLEJUMP_GAME_H

#include "Window.h"
#include "../logic_library/Stopwatch.h"
#include "../logic_library/World.h"

namespace representation {

    class Game {

    public:
        Game();
        ~Game();
        void HandleInput();
        void Update();
        void Render();
        Window* GetWindow();

    private:

        Window m_window;
        //representation::Window* m_window = representation::Window::Instance();

        logic::World world;

    public:

        float getElapsed();
//    void restartClock();

    };
}



#endif //DOODLEJUMP_GAME_H
