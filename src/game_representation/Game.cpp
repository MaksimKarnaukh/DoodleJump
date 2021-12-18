//
// Created by centu on 17/11/2021.
//

#include "Game.h"

#include <memory>

namespace representation {

    Game::Game() { // : m_window("window", sf::Vector2u(640,960))

        representation::Window& m_window = representation::Window::Instance();
        m_window.Setup("Doodle Jump", sf::Vector2u(640,960));

        factory = std::make_shared<representation::ConcreteFactory>();
        world = std::make_shared<logic::World>(factory);

    }

    Game::~Game(){}

    void Game::Update(){
        representation::Window::Instance().Update(); // Update window events.
    }

    void Game::Render(){
        representation::Window::Instance().BeginDraw(); // Clear.

        text.setString(std::to_string(world->score.getScore()));
        representation::Window::Instance().Draw(text);

        world->doodle->notifyObservers();
        for (auto a = 0; a < world->platforms.size(); a++) {
            world->platforms[a]->notifyObservers();
        }

        std::cout << "x =" << world->doodle->getPositionX() <<  "   ";
        std::cout << "y =" << world->doodle->getPositionY() << "   ";
        std::cout << "w =" << world->doodle->getWidth() << "   ";
        std::cout << "h =" << world->doodle->getHeight() << "   " << std::endl;
        std::cout << "pl.x =" << world->platforms[0]->getPositionX() << "   ";
        std::cout << "pl.y =" << world->platforms[0]->getPositionY() << "   ";
        std::cout << "pl.w =" << world->platforms[0]->getWidth() << "   ";
        std::cout << "pl.h =" << world->platforms[0]->getHeight() << std::endl;


        //representation::Window::Instance()->Draw(world->doodle.);

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

        if (!font.loadFromFile("assets/Fonts/Bodo_Amat.ttf")) {

        }
        text.setFont(font);
        text.setCharacterSize(60);
        text.setFillColor(sf::Color::Red);
        text.setOutlineColor(sf::Color::Yellow);
        text.setOutlineThickness(4);

        logic::Stopwatch& stopwatch = logic::Stopwatch::Instance();

        float frameRate = 60.0f;

        while(!GetWindow().IsDone()) {

            stopwatch.tick();

            if (stopwatch.getDeltaTime() < (1 / frameRate)) {
                std::chrono::milliseconds ms = std::chrono::milliseconds((int)(((1/frameRate) - stopwatch.getDeltaTime())*1000));
                std::this_thread::sleep_for(ms);
                // std::cout << ms.count() << std::endl; ////
            }

            stopwatch.tick(); // de verstreken milliseconden erbij.

            std::cout /* << stopwatch->getDeltaTime() << "  " */ << 1 / stopwatch.getDeltaTime() << std::endl; ////

            stopwatch.Reset(); // mStartTime = now (tijd verstreken is terug 0)

            // Game loop.
            HandleInput();
            Update();
            Render();
            //sf::sleep(sf::seconds(0.1));

        }
    }

//    float Game::getElapsed() {
//        return logic::Stopwatch::Instance()->getDeltaTime();
//    }

//void Game::restartClock() {
//    logic::Stopwatch::Instance()->Reset();
//}

}


