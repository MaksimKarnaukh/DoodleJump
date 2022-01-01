// Author: Maksim Karnaukh

#include "Game.h"
#include <memory>

namespace representation {

    Game::Game() {

        representation::Window& m_window = representation::Window::Instance();
        m_window.Setup("Doodle Jump", sf::Vector2u(640,960));

        logic::utility::Stopwatch::Instance();

        gameState = 0;

        fontFile = "../assets/Fonts/Bodo_Amat.ttf";

    }

    Game::~Game(){}

    void Game::Update() {
        representation::Window::Instance().Update(); // Update window events.
        world->update();

    }

    void Game::Render(){
        representation::Window::Instance().BeginDraw(); // Clear.

        drawBGTiles();
        drawPlatforms();
        drawBonusses();
        drawScore();
        drawPlayer();

        representation::Window::Instance().EndDraw(); // Display.
    }

    void Game::HandleInput() {

        std::string key{};
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Q) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { // left

            key = "Left";
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
                 sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { // right

            key = "Right";
        }
        world->receiveInput(key);

    }

    Window &Game::GetWindow() {
        return representation::Window::Instance();
    }

    void Game::runGameLoop() {

        loadFonts();
        createTexts();

        while(!GetWindow().IsDone()) {

            representation::Window::Instance().Update(); // Update window events.
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

        cFactory = std::move(std::make_shared<representation::ConcreteFactory>());
        factory = cFactory;

        world = std::move(std::make_unique<logic::World>(factory));

        logic::utility::Stopwatch::Instance().Reset();

        while ( !(world->gameOver || GetWindow().IsDone()) ) {

            logic::utility::Stopwatch::Instance().tick();

            if (logic::utility::Stopwatch::Instance().getDeltaTime() < (1.0f/getFrameRate())) {
                std::chrono::milliseconds ms = std::chrono::milliseconds((int)(((1.0f/getFrameRate()) - logic::utility::Stopwatch::Instance().getDeltaTime())*1000));
                std::this_thread::sleep_for(ms);
            }

            logic::utility::Stopwatch::Instance().tick(); // de verstreken milliseconden erbij.
            //std::cout << 1 / logic::utility::Stopwatch::Instance().getDeltaTime() << std::endl;
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

        createSingleText(scoreText, font1, 60, sf::Color::Red, sf::Color::Yellow, 4, std::make_pair(0,0), "");
        createSingleText(menuText, font1, 20, sf::Color::Red, sf::Color::Yellow, 3, std::make_pair(150.0f, (float)representation::Window::Instance().GetWindowSize().y/3), "Press Enter to start the game.");
        createSingleText(menuText0, font1, 80, sf::Color::Green, sf::Color::Yellow, 1, std::make_pair(70.0f, (float)representation::Window::Instance().GetWindowSize().y/8), "Doodle Jump");
        createSingleText(currentHighScore, font1, 40, sf::Color::Blue, sf::Color::Green, 2, std::make_pair(60.0f, (float)representation::Window::Instance().GetWindowSize().y/1.5f), "");
        createSingleText(allTimeHighScore, font1, 40, sf::Color::Blue, sf::Color::Red, 2, std::make_pair(60.0f, (float)representation::Window::Instance().GetWindowSize().y/1.3f), "");

    }

    void Game::createSingleText(sf::Text& _text, const sf::Font& _font, int charSize, sf::Color fillColor, sf::Color outlineColor, float outlineThickness, std::pair<float,float> pos, const std::string& str) {

        _text.setFont(_font);
        _text.setCharacterSize(charSize);
        _text.setFillColor(fillColor);
        _text.setOutlineColor(outlineColor);
        _text.setOutlineThickness(outlineThickness);
        _text.setPosition(pos.first, pos.second);
        if (! str.empty()) {
            _text.setString(str);
        }
    }

    void Game::createSingleText(sf::Text &_text, const sf::Font &_font, int charSize, std::pair<float, float> pos,
                                const std::string &str) {

        _text.setFont(_font);
        _text.setCharacterSize(charSize);
        _text.setPosition(pos.first, pos.second);
        if (! str.empty()) {
            _text.setString(str);
        }
    }

    void Game::calculateHighScore() {
        _currentScore = static_cast<int>(std::round(world->score->getScore()*10));
        if (_currentScore > _allTimeHighScore) {
            _allTimeHighScore = _currentScore;
        }
    }

    void Game::drawBGTiles() {
        for (int i = cFactory->bgTilesViews.size()-1; i >= 0; i--) {
            representation::Window::Instance().Draw(cFactory->bgTilesViews[i]->getSprite());
        }
    }

    void Game::drawPlatforms() {
        for (int i = cFactory->platformViews.size()-1; i >= 0; i--) {

            if (cFactory->platformViews[i].use_count() == 1) {
                cFactory->platformViews.erase(cFactory->platformViews.begin()+i);
            }
            else {
                representation::Window::Instance().Draw(cFactory->platformViews[i]->getSprite());
            }
        }
    }

    void Game::drawBonusses() {
        for (int i = cFactory->bonusViews.size()-1; i >= 0; i--) {

            if (cFactory->bonusViews[i].use_count() == 1) {
                cFactory->bonusViews.erase(cFactory->bonusViews.begin()+i);
            }
            else {
                representation::Window::Instance().Draw(cFactory->bonusViews[i]->getSprite());
            }
        }
    }

    void Game::drawScore() {
        scoreText.setString(std::to_string(static_cast<int>(std::round(world->score->getScore()*10))));
        representation::Window::Instance().Draw(scoreText);
    }

    void Game::drawPlayer() {
        representation::Window::Instance().Draw(cFactory->playerViews[0]->getSprite());
    }

}


