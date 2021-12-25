//
// Created by centu on 17/11/2021.
//

#include "Game.h"

#include <memory>

namespace representation {

    Game::Game() { // : m_window("window", sf::Vector2u(640,960))

        representation::Window& m_window = representation::Window::Instance();
        m_window.Setup("Doodle Jump", sf::Vector2u(640,960));

        logic::utility::Stopwatch::Instance();

        factory = std::make_shared<representation::ConcreteFactory>();

        gameState = 0;

        fontFile = "assets/Fonts/Bodo_Amat.ttf";

    }

    Game::~Game(){}

    void Game::Update(){
        representation::Window::Instance().Update(); // Update window events.
    }

    void Game::Render(){
        representation::Window::Instance().BeginDraw(); // Clear.

        for (auto a = 0; a < world->bgTiles.size(); a++) {

            for (auto b = 0; b < world->bgTiles[a].size(); b++) {
                world->bgTiles[a][b]->notifyObservers();
            }
        }

        for (auto a = 0; a < world->platforms.size(); a++) {
            world->platforms[a]->notifyObservers();
        }
        for (auto a = 0; a < world->bonuses.size(); a++) {
            world->bonuses[a]->notifyObservers();
        }
        scoreText.setString(std::to_string(world->score->getScore()));
        representation::Window::Instance().Draw(scoreText);

        world->doodle->notifyObservers();

        std::cout << "playerX = " << world->doodle->getPositionX() <<  "; ";
        std::cout << "playerY = " << world->doodle->getPositionY() << "; ";
        std::cout << "playerWidth = " << world->doodle->getWidth() << "; ";
        std::cout << "playerHeight = " << world->doodle->getHeight() << std::endl;
//        std::cout << "pl.x =" << world->platforms[0]->getPositionX() << "   ";
//        std::cout << "pl.y =" << world->platforms[0]->getPositionY() << "   ";
//        std::cout << "pl.w =" << world->platforms[0]->getWidth() << "   ";
//        std::cout << "pl.h =" << world->platforms[0]->getHeight() << std::endl;

        representation::Window::Instance().EndDraw(); // Display.
    }

    void Game::HandleInput() {

        std::string key;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Q) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { // links

            key = "Left";
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
                 sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { // rechts

            key = "Right";
        }
        world->receiveInput(key);

        world->update();

    }

    Window &Game::GetWindow() {
        return representation::Window::Instance();
    }

    void Game::runGameLoop() {

        loadFonts();
        createTexts();

        while(!GetWindow().IsDone()) {

            if (gameState == 0) {
                playMenu();
            }
            else {
                playGame();
            }
            // we can add more gameStates if we want

        }
    }

    void Game::playMenu() {

        if (! sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {

            representation::Window::Instance().BeginDraw(); // Clear.

            representation::Window::Instance().Draw(menuText);
            representation::Window::Instance().Draw(menuText0);

            std::string currentScore;
            currentScore += "Score : ";
            currentScore += std::to_string(_currentScore);
            currentHighScore.setString(currentScore);
            std::string AllTimeHighScore;
            AllTimeHighScore += "All-Time High-Score : ";
            AllTimeHighScore += std::to_string(_allTimeHighScore);
            allTimeHighScore.setString(AllTimeHighScore);

            representation::Window::Instance().Draw(allTimeHighScore);
            representation::Window::Instance().Draw(currentHighScore);

            representation::Window::Instance().EndDraw(); // Display.

        }
        else {

            gameState = 1;
        }

    }

    void Game::playGame() {

        world = std::move(std::make_unique<logic::World>(factory));

        logic::utility::Stopwatch::Instance().Reset();

        while ( !(world->gameOver || GetWindow().IsDone()) ) {

            logic::utility::Stopwatch::Instance().tick();

            if (logic::utility::Stopwatch::Instance().getDeltaTime() < (1.0f/getFrameRate())) {
                std::chrono::milliseconds ms = std::chrono::milliseconds((int)(((1.0f/getFrameRate()) - logic::utility::Stopwatch::Instance().getDeltaTime())*1000));
                std::this_thread::sleep_for(ms);
                std::cout << ms.count() << std::endl;
            }

            logic::utility::Stopwatch::Instance().tick(); // de verstreken milliseconden erbij.
            std::cout  << logic::utility::Stopwatch::Instance().getDeltaTime() << "  " << 1 / logic::utility::Stopwatch::Instance().getDeltaTime() << std::endl;
            logic::utility::Stopwatch::Instance().Reset(); // mStartTime = now (tijd verstreken is terug 0)

            // Game loop.
            HandleInput();
            Update();
            Render();
        }
        gameState = 0;
        calculateHighScore();

    }

    void Game::loadFonts() {

        try {
            if (!font1.loadFromFile(fontFile)) {
                throw LoadFileException("Error loading from file");
            }
        }
        catch (LoadFileException& e) {
            std::cout << e.what() << ": " << fontFile << std::endl;
        }

    }

    void Game::createTexts() {

        scoreText.setFont(font1);
        scoreText.setCharacterSize(60); // 60
        scoreText.setFillColor(sf::Color::Red);
        scoreText.setOutlineColor(sf::Color::Yellow);
        scoreText.setOutlineThickness(4); // 4

        menuText.setFont(font1);
        menuText.setCharacterSize(20); // 60
        menuText.setFillColor(sf::Color::Red);
        menuText.setOutlineColor(sf::Color::Yellow);
        menuText.setOutlineThickness(3); // 4
        menuText.setPosition(150.0f, (float)representation::Window::Instance().GetWindowSize().y/3);
        menuText.setString("Press Enter to start the game.");

        menuText0.setFont(font1);
        menuText0.setCharacterSize(80); // 60
        menuText0.setFillColor(sf::Color::Green);
        menuText0.setOutlineColor(sf::Color::Yellow);
        menuText0.setOutlineThickness(1); // 4
        menuText0.setPosition(70.0f, (float)representation::Window::Instance().GetWindowSize().y/8);
        menuText0.setString("Doodle Jump");

        currentHighScore.setFont(font1);
        currentHighScore.setCharacterSize(40); // 60
        currentHighScore.setFillColor(sf::Color::Blue);
        currentHighScore.setOutlineColor(sf::Color::Green);
        currentHighScore.setOutlineThickness(2); // 4
        currentHighScore.setPosition(80.0f, (float)representation::Window::Instance().GetWindowSize().y/1.5f);

        allTimeHighScore.setFont(font1);
        allTimeHighScore.setCharacterSize(40); // 60
        allTimeHighScore.setFillColor(sf::Color::Blue);
        allTimeHighScore.setOutlineColor(sf::Color::Red);
        allTimeHighScore.setOutlineThickness(2); // 4
        allTimeHighScore.setPosition(80.0f, (float)representation::Window::Instance().GetWindowSize().y/1.3f);


    }

    void Game::calculateHighScore() {
        _currentScore = world->score->getScore();
        if (_currentScore > _allTimeHighScore) {
            _allTimeHighScore = _currentScore;
        }
    }
}


