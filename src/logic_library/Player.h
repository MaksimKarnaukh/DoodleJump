//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_PLAYER_H
#define DOODLEJUMP_PLAYER_H

#include "EntityModel.h"
#include "Stopwatch.h"

namespace logic {

    class Player: public logic::EntityModel {

        const float gravity = 0.05f; // (In de doodle jump game online wordt een sprong gedurende ongeveer 0.5s naar boven uitgevoerd.)
        float jumpVelocity = -1.2f; // -2.0 en 0.1

    public:

        Player();

        Player(float posX, float posY, float width, float height);

        void moveLeft();

        void moveRight();

        void jump();

        void applyGravity();

        void moveVertically();

    };

}



#endif //DOODLEJUMP_PLAYER_H
