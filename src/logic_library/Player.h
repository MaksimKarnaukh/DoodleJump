//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_PLAYER_H
#define DOODLEJUMP_PLAYER_H

#include "EntityModel.h"
#include "Stopwatch.h"

namespace logic {

    class Player: public logic::EntityModel {

        //int state; // state 1 = player flying up; state 0 = player falling down

    public:

        Player();

        void moveLeft();

        void moveRight();

        void jump();

    };

}



#endif //DOODLEJUMP_PLAYER_H
