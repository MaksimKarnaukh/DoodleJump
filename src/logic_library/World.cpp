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

    void World::checkForCollision() { // jump if collision from top detected

        // check for collision

        float x0 = doodle->getPreviousPositionX();
        float y0 = doodle->getPreviousPositionY();

        float x1 = doodle->getPositionX();
        float y1 = doodle->getPositionY();

        std::vector<std::pair<float,float>> middleLine = getLineBetweenPoints(x0, y0, x1, y1);

        std::cout << " " << x0 << " " << y0 << " " << x1 << " " << y1 << std::endl;

        if((doodle->getPositionY()+doodle->getHeight() >= 1)){ //
            doodle->jump(); //
        }

        // checken of we een platform raken.
        for (int pl = 0; pl < platforms.size(); pl++) {

            // checken of het midden van de doodle tussen de uiteinden van het platform zit
            if (doodle->getPositionX()+doodle->getWidth()/2 >= platforms[pl]->getPositionX() &&
            doodle->getPositionX()+doodle->getWidth()/2 <= platforms[pl]->getPositionX()+platforms[pl]->getWidth()) {

                // checken op de y-coordinaten
                if (doodle->getPositionY()+doodle->getHeight() >= platforms[pl]->getPositionY()-platforms[pl]->getHeight()/2 &&
                        doodle->getPositionY()+doodle->getHeight() <= platforms[pl]->getPositionY()+platforms[pl]->getHeight()/2) {

                    doodle->jump();
                }
            }

            if (checkForUndetectedCollision(platforms[pl], middleLine)) { // backup check
                doodle->jump();
                std::cout << "jump" << std::endl;
                break;
            }

        }

    }

    void World::createEntities(const std::shared_ptr<logic::AbstractFactory>& Factory) {

        doodle = Factory->createPlayer(0.5, 0.5, 0.077, 0.128);

        std::shared_ptr<logic::Platform> p = Factory->createPlatform(0.5, 0.8, 0.174, 0.05);
        platforms.push_back(p);

        std::shared_ptr<logic::Platform> p1 = Factory->createPlatform(0.2, 0.5, 0.174, 0.05);
        platforms.push_back(p1);

        std::shared_ptr<logic::Platform> p2 = Factory->createPlatform(0.6, 0.3, 0.174, 0.05);
        platforms.push_back(p2);

    }

    void World::update() {

        doodle->applyGravity();
        doodle->moveVertically();

        if (doodle->getSpeed() >= 0) { // als we aan het vallen zijn
            checkForCollision();
        }
        doodle->setPreviousPositionX(doodle->getPositionX());
        doodle->setPreviousPositionY(doodle->getPositionY());

    }

    bool World::checkForUndetectedCollision(const std::shared_ptr<logic::Platform>& pl, std::vector<std::pair<float,float>> &middleLine) {

        for (int i = 0; i < middleLine.size(); i++) {

            //std::cout << "middleLine:  " << middleLine[i].first << "  " << middleLine[i].second << " ]" << std::endl;

            if (middleLine[i].first >= pl->getPositionX() &&
                    middleLine[i].first <= pl->getPositionX()+pl->getWidth()) {

                // checken op de y-coordinaten
                if (middleLine[i].second >= pl->getPositionY() &&
                        middleLine[i].second <= pl->getPositionY()+pl->getHeight()) {

                    return true;

                }
            }
        }
        return false;
    }

    std::vector<std::pair<float,float>> World::getLineBetweenPoints(float x0, float y0, float x1, float y1) {

        std::vector<std::pair<float,float>> line;
        float precisionOfIterator = 0.001f;

        if (x0 == x1) {
            //special case for x0 == x1
            for (float i = std::min(y0, y1); i <= std::max(y0, y1); i+=precisionOfIterator) {
                line.emplace_back(x0, i);
            }
        }
        else if (y0 == y1) {
            //special case for y0 == y1
            for (float i = std::min(x0, x1); i <= std::max(x0, x1); i+=precisionOfIterator) {
                line.emplace_back(i, y0);
            }
        }
        else {
            if (x0 > x1) {
                //flip points if x1<x0: we want x0 to have the lowest value
                std::swap(x0, x1);
                std::swap(y0, y1);
            }

            float m = ( y1 - y0) / ( x1 - x0);
            if (-1.0 <= m && m <= 1.0) {
                for (float i = 0; i <= (x1 - x0); i+=precisionOfIterator) {
                    line.emplace_back(x0 + i,  (y0 + m * i));
                }
            }
            else if (m > 1.0) {
                for (float i = 0; i <= (y1 - y0); i+=precisionOfIterator) {
                    line.emplace_back( (x0 + (i / m)), y0 + i);
                }
            }
            else if (m < -1.0) {
                for (float i = 0; i <= (y0 - y1); i+=precisionOfIterator) {
                    line.emplace_back( (x0 - (i / m)), y0 - i);
                }
            }
        }
        return line;
    }
}

