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

        sf::Font font1;
        sf::Text scoreText;
        sf::Text menuText;

        int gameState; // 0:menu ; 1:game

        float frameRate = 60.0f; // standard value

    public:
        Game();
        ~Game();
        void HandleInput();
        void Update();
        void Render();
        Window& GetWindow();

        void runGameLoop();
        void playMenu();
        void playGame();

        void loadFonts();
        void createTexts();

    public:

        void setFrameRate(float fps) {
            frameRate = fps;
        }

        float getFrameRate() const {
            return frameRate;
        }

    private:

        //Window m_window;

        std::shared_ptr<logic::World> world;

        std::shared_ptr<logic::AbstractFactory> factory;

    public:

    };
}



#endif //DOODLEJUMP_GAME_H
