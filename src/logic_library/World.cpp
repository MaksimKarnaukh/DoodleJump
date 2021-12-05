//
// Created by centu on 17/11/2021.
//

#include "World.h"

namespace logic {

    World::World() = default;

    void World::receiveInput(std::string &key) {

        if (key == "Left") {
            doodle->moveLeft();
            if((doodle->getPositionX()+doodle->getWidth()/2 < 0)){ // links buiten window
                doodle->setPositionX(1 - doodle->getWidth()/2); // we zetten onze doodle aan de rechterkant
            }
        }
        else if (key == "Right") {
            doodle->moveRight();
            if((doodle->getPositionX() > 1 - doodle->getWidth()/2)){ // rechts buiten window
                doodle->setPositionX(0 - doodle->getWidth()/2); // we zetten onze doodle aan de linkerkant
            }
        }
    }

    void World::checkForCollision() {

        // check for collision
        if (doodle->getSpeed() >= 0) { // als we aan het vallen zijn

            if((doodle->getPositionY()+doodle->getHeight() >= 1)){ //
                doodle->jump(); //
            }

            // checken of we een platform raken.
            for (int pl = 0; pl < platforms.size(); pl++) {

                // checken of het midden van de doodle tussen de uiteinden van het platform zit
                if (doodle->getPositionX()+doodle->getWidth()/2 >= platforms[pl]->getPositionX() &&
                doodle->getPositionX()+doodle->getWidth()/2 <= platforms[pl]->getPositionX()+platforms[pl]->getWidth()) {

                    // checken op de y-coordinaten
                    if (doodle->getPositionY()+doodle->getHeight() >= platforms[pl]->getPositionY()-platforms[pl]->getHeight()/3 &&
                            doodle->getPositionY()+doodle->getHeight() <= platforms[pl]->getPositionY()+platforms[pl]->getHeight()/3) {

                        doodle->jump();
                        std::cout << "jump" << std::endl;
                    }
                }
            }
        }
    }

    void World::createEntities(const std::shared_ptr<logic::AbstractFactory>& Factory) {

        doodle = Factory->createPlayer(0.5, 0.5, 0.1, 0.1);

        std::shared_ptr<logic::Platform> p = Factory->createPlatform(0.5, 0.9, 0.1, 0.5);
        platforms.push_back(p);

    }

    void World::update() {

        doodle->applyGravity();
        doodle->moveVertically();
        checkForCollision();

    }
}

