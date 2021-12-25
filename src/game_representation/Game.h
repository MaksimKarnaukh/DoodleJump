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
        sf::Text menuText0;
        sf::Text currentHighScore;
        sf::Text allTimeHighScore;

        int _currentScore = 0;
        int _allTimeHighScore = 0;

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

        void calculateHighScore();

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

    };
}



#endif //DOODLEJUMP_GAME_H
