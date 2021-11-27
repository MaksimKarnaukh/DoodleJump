//
// Created by centu on 17/11/2021.
//

#include "World.h"

namespace logic {

    World::World() {

    }

    void World::moveDoodleLeft() {
        doodle->moveLeft();
    }

    void World::moveDoodleRight() {
        doodle->moveRight();
    }

    void World::doodleJump() {
        doodle->jump();
    }

    void World::receiveInput(std::string &key) {

        if (key == "Left") {
            moveDoodleLeft();
        }
        else if (key == "Right") {
            moveDoodleRight();
        }
    }

}

