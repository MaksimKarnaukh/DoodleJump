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
#include "../LoadFileException.h"

namespace representation {

    class Game {

        sf::Font font1;
        std::string fontFile; // path to file with font

        sf::Text scoreText; // score text in game
        sf::Text menuText; // "Press Enter to start the game."
        sf::Text menuText0; // "Doodle Jump"
        sf::Text currentHighScore; // see _currentScore
        sf::Text allTimeHighScore; // see _allTimeHighScore

        int _currentScore = 0; // high-score of the previously played game.
        int _allTimeHighScore = 0; // all time high-score for this session.

        int gameState; // 0:menu ; 1:game

        float frameRate = 60.0f; // standard value

        std::unique_ptr<logic::World> world;

        std::shared_ptr<logic::AbstractFactory> factory;

    public:

        /**
        * @function : Game
        * Constructor for a Game (the window is made here).
        */
        Game();

        ~Game();

        /**
        * @function : HandleInput
        * Checks for user input on the keyboard and passes this to the world.
        */
        void HandleInput();

        /**
        * @function : Update
        * Updates the window events.
        */
        void Update();

        /**
        * @function : Render
        * Takes care of drawing all our entities on the window.
        */
        void Render();

        /**
        * @function : GetWindow
        * Returns the window instance.
        * @return (Window) : window instance.
        */
        Window& GetWindow();

        /**
        * @function : runGameLoop
        * Runs the top-level program loop, which alternates between the different states of our game.
        */
        void runGameLoop();

        /**
        * @function : playMenu
        * Responsible for showing the menu screen.
        */
        void playMenu();

        /**
        * @function : playGame
        * Runs the actual Doodle Jump game.
        */
        void playGame();


        /**
        * @function : loadFonts
        * All necessary fonts are loaded in here.
        */
        void loadFonts();

        /**
        * @function : createTexts
        * All necessary text items are created here.
        */
        void createTexts();

        /**
        * @function : calculateHighScore
        * Calculates the previous and all-time high-score.
        */
        void calculateHighScore();

    public:

        /**
        * @function : setFrameRate
        * Setter for the framerate data member.
        * @param fps (float) : frames per second.
        */
        void setFrameRate(float fps) {
            frameRate = fps;
        }

        /**
        * @function : getFrameRate
        * Getter for the framerate data member.
        * @return (float) : framerate data member (frames per second).
        */
        float getFrameRate() const {
            return frameRate;
        }

    };
}



#endif //DOODLEJUMP_GAME_H
