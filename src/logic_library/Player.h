//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_PLAYER_H
#define DOODLEJUMP_PLAYER_H

#include "EntityModel.h"
#include "Stopwatch.h"

namespace logic {

    class Player: public logic::EntityModel {

        float gravity = 20.0f;
        float jumpVelocity = -750.0f; // 10

        //int state; // state 1 = player flying up; state 0 = player falling down

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
