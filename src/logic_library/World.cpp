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
            if((doodle->getPositionX() < 0)){ // links buiten window
                doodle->setPositionX(1*640 - doodle->getWidth()); // we zetten onze doodle aan de rechterkant
            }
        }
        else if (key == "Right") {
            doodle->moveRight();
            if((doodle->getPositionX() > 1*640 - doodle->getWidth())){ // rechts buiten window
                doodle->setPositionX(0); // we zetten onze doodle aan de linkerkant
            }
        }
    }

    void World::isCollision() {

        // check for collision
        if (doodle->getSpeed() >= 0) { // als we aan het vallen zijn
            if((doodle->getPositionY() >= 850)){ // rechts buiten window
                doodle->jump(); // we zetten onze doodle aan de linkerkant
            }
        }
    }

    void World::createEntities(const std::shared_ptr<logic::AbstractFactory>& Factory) {

        doodle = Factory->createPlayer(100, 100, 10, 10);

    }

    void World::update() {
        doodle->applyGravity();
        doodle->moveVertically();
        isCollision();
    }

}

