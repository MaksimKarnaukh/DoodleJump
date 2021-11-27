//
// Created by centu on 17/11/2021.
//

#include "Game.h"

namespace representation {

    Game::Game(): m_window("window", sf::Vector2u(640,960)){


    }

    Game::~Game(){}

    void Game::Update(){
        m_window.Update(); // Update window events.
    }

    void Game::Render(){
        m_window.BeginDraw(); // Clear.
        //m_window.Draw();
        m_window.EndDraw(); // Display.
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
        world.receiveInput(key);

    }

    Window *Game::GetWindow() {
        return &m_window;
    }

    float Game::getElapsed() {
        return logic::Stopwatch::Instance()->getDeltaTime();
    }

//void Game::restartClock() {
//    logic::Stopwatch::Instance()->Reset();
//}

}


