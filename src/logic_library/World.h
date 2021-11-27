//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_WORLD_H
#define DOODLEJUMP_WORLD_H

#include "Player.h"
#include "Platform.h"
#include <memory>

namespace logic {

    class World {

        std::shared_ptr<logic::Player> doodle;

    public:

        World();

        void moveDoodleLeft();

        void moveDoodleRight();

        void doodleJump();

        void receiveInput(std::string &key);

    };

}



#endif //DOODLEJUMP_WORLD_H
