//
// Created by centu on 17/11/2021.
//

#include "World.h"

namespace logic {

    World::World() {

    }

    void World::receiveInput(std::string &key) {

        if (key == "Left") {
            doodle->moveLeft();
        }
        else if (key == "Right") {
            doodle->moveRight();
        }
    }

    void World::isCollision() {

        // check for collision
        if (doodle->getSpeed() <= 0) { // als we aan het vallen zijn

        }
        doodle->jump();
    }

    void World::createEntities(const std::shared_ptr<logic::AbstractFactory>& Factory) {

        doodle = Factory->createPlayer(50, 50, 0.5, 0.5);

    }

    void World::update() {
        doodle->moveVertically();
    }

}

