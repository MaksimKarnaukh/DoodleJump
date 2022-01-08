// Author: Maksim Karnaukh

#ifndef DOODLEJUMP_GAME_H
#define DOODLEJUMP_GAME_H

#include "../LoadFileException.h"
#include "../logic_library/Stopwatch.h"
#include "../logic_library/World.h"
#include "ConcreteFactory.h"
#include "Window.h"
#include <thread>

namespace representation {

class Game
{

        sf::Font font1;
        std::string fontFile; // path to file with font

        sf::Text scoreText;        // score text in game
        sf::Text menuText;         // "Press Enter to start the game."
        sf::Text menuText0;        // "Doodle Jump"
        sf::Text currentHighScore; // see _currentScore
        sf::Text allTimeHighScore; // see _allTimeHighScore

        int _currentScore = 0;     // high-score of the previously played game.
        int _allTimeHighScore = 0; // all time high-score for this session.

        int gameState; // 0:menu ; 1:game

        float frameRate = 60.0f; // standard value

        std::unique_ptr<logic::World> world;

        std::shared_ptr<logic::AbstractFactory> factory;
        std::shared_ptr<representation::ConcreteFactory> cFactory;

public:
        /**
         * @function : Game
         * Constructor for a Game (the window is made here).
         */
        Game();

        /**
         * @function : Game
         * Destructor for a Game.
         */
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
         * @function : createSingleText
         * Assigns the esthetics to a single text item.
         * @param _text (sf::Text) : text item.
         * @param _font (sf::Font) : font that is applied to the text.
         * @param charSize (int) : character size of our text.
         * @param fillColor (sf::Color) : text color.
         * @param outlineColor (sf::Color) : outline color of our text.
         * @param outlineThickness (float) : outline thickness.
         * @param pos (std::pair<float,float>) : position of the text.
         * @param str (std::string) : the string that the text represents.
         */
        static void createSingleText(sf::Text& _text, const sf::Font& _font, int charSize, sf::Color fillColor,
                                     sf::Color outlineColor, float outlineThickness, std::pair<float, float> pos,
                                     const std::string& str);

        /**
         * @function : createSingleText
         * Assigns the esthetics to a single text item.
         * @param _text (sf::Text) : text item.
         * @param _font (sf::Font) : font that is applied to the text.
         * @param charSize (int) : character size of our text.
         * @param pos (std::pair<float,float>) : position of the text.
         * @param str (std::string) : the string that the text represents.
         */
        static void createSingleText(sf::Text& _text, const sf::Font& _font, int charSize, std::pair<float, float> pos,
                                     const std::string& str);

        /**
         * @function : calculateHighScore
         * Calculates the previous and all-time high-score.
         */
        void calculateHighScore();

        /**
         * @function : drawBGTiles
         * Draws the background tiles.
         */
        void drawBGTiles();

        /**
         * @function : drawPlatforms
         * Draws the platforms.
         */
        void drawPlatforms();

        /**
         * @function : drawBonusses
         * Draws the bonusses.
         */
        void drawBonusses();

        /**
         * @function : drawScore
         * Draws the score.
         */
        void drawScore();

        /**
         * @function : drawPlayer
         * Draws the player.
         */
        void drawPlayer();

public:
        /**
         * @function : setFrameRate
         * Setter for the framerate data member.
         * @param fps (float) : frames per second.
         */
        void setFrameRate(float fps) { frameRate = fps; }

        /**
         * @function : getFrameRate
         * Getter for the framerate data member.
         * @return (float) : framerate data member (frames per second).
         */
        float getFrameRate() const { return frameRate; }
};
} // namespace representation

#endif // DOODLEJUMP_GAME_H
