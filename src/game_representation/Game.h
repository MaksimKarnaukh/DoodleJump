//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_GAME_H
#define DOODLEJUMP_GAME_H

#include "Window.h"
#include "../logic_library/Stopwatch.h"
#include "../logic_library/World.h"
#include "ConcreteFactory.h"
#include <thread>

namespace representation {

    class Game {

        sf::Font font;
        sf::Text text;


    public:
        Game();
        ~Game();
        void HandleInput();
        void Update();
        void Render();
        Window& GetWindow();

        void runGameLoop();

    private:

        //Window m_window;

        std::shared_ptr<logic::World> world;

        std::shared_ptr<logic::AbstractFactory> factory;

    public:

//        float getElapsed();
//    void restartClock();

    };
}



#endif //DOODLEJUMP_GAME_H
