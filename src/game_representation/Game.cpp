//
// Created by centu on 17/11/2021.
//

#include "Game.h"

Game::Game(): m_window("window", sf::Vector2u(1000,800)){
    // Setting up class members.
    m_doodleTexture.loadFromFile("assets/DoodleJumper/doodle-right.png");
    m_doodle.setTexture(m_doodleTexture);
    m_increment = sf::Vector2i(1,1);
}

Game::~Game(){}

void Game::Update(){
    m_window.Update(); // Update window events.
    MoveDoodle();
}
void Game::MoveDoodle(){
    sf::Vector2u l_windSize = m_window.GetWindowSize();
    sf::Vector2u l_textSize = m_doodleTexture.getSize();
    if((m_doodle.getPosition().x >
        l_windSize.x - l_textSize.x&&m_increment.x> 0) ||
       (m_doodle.getPosition().x < 0 &&m_increment.x< 0)){
        m_increment.x = -m_increment.x;
    }
    if((m_doodle.getPosition().y >
        l_windSize.y - l_textSize.y&&m_increment.y> 0) ||
       (m_doodle.getPosition().y < 0 &&m_increment.y< 0)){
        m_increment.y = -m_increment.y;
    }
    m_doodle.setPosition(
            m_doodle.getPosition().x + m_increment.x,
            m_doodle.getPosition().y + m_increment.y);
}

void Game::Render(){
    m_window.BeginDraw(); // Clear.
    m_window.Draw(m_doodle);
    m_window.EndDraw(); // Display.
}

void Game::HandleInput() {
    MoveDoodle();
}

Window *Game::GetWindow() {
    return &m_window;
}
