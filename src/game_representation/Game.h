//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_GAME_H
#define DOODLEJUMP_GAME_H

#include "Window.h"

class Game {

public:
    Game();
    ~Game();
    void HandleInput();
    void Update();
    void Render();
    Window* GetWindow();

private:
    void MoveMushroom();
    Window m_window;
};


#endif //DOODLEJUMP_GAME_H
