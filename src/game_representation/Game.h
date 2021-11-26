//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_GAME_H
#define DOODLEJUMP_GAME_H

#include "Window.h"
#include "../logic_library/Stopwatch.h"

namespace representation {

    class Game {

    public:
        Game();
        ~Game();
        void HandleInput();
        void Update();
        void Render();
        Window* GetWindow();

    private:
        void MoveDoodle();
        Window m_window;

        sf::Texture m_doodleTexture;
        sf::Sprite m_doodle;
        sf::Vector2f m_increment;

    public:

        float getElapsed();
//    void restartClock();

    private:


    };
}



#endif //DOODLEJUMP_GAME_H
