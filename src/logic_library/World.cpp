//
// Created by centu on 17/11/2021.
//

#include "World.h"

namespace logic {

    World::World() = default;

    World::World(std::shared_ptr<logic::AbstractFactory> &factory) : Factory(factory) {

        logic::Random& random = logic::Random::Instance();
        logic::Camera& camera = logic::Camera::Instance();

        createStartEntities();

    }

    void World::receiveInput(std::string &key) {

        if (key == "Left") {
            doodle->moveLeft();
            if((doodle->getPositionX()+doodle->getWidth()/2 < leftBound)){ // links buiten window
                doodle->setPositionX(rightBound - doodle->getWidth()/2); // we zetten onze doodle aan de rechterkant
            }
        }
        else if (key == "Right") {
            doodle->moveRight();
            if((doodle->getPositionX() > rightBound - doodle->getWidth()/2)){ // rechts buiten window
                doodle->setPositionX(leftBound - doodle->getWidth()/2); // we zetten onze doodle aan de linkerkant
            }
        }
    }

    void World::checkForCollision() { // jump if collision from top detected

        float x0 = doodle->getPreviousPositionX()+doodle->getWidth()/2;
        float y0 = doodle->getPreviousPositionY()-doodle->getHeight();
        float x1 = doodle->getPositionX()+doodle->getWidth()/2;
        float y1 = doodle->getPositionY()-doodle->getHeight();

        std::vector<std::pair<float,float>> middleLine = getLineBetweenPoints(x0, y0, x1, y1);

        if ((doodle->getPositionY()-doodle->getHeight() <= lowerBound)) {
            doodle->jump();
        }

        // checken of we een platform raken.
        for (auto pl = 0; pl < platforms.size(); pl++) {

            // checken of het midden van de doodle tussen de uiteinden van het platform zit
//            if (doodle->getPositionX()+doodle->getWidth()/2 >= platforms[pl]->getPositionX() &&
//            doodle->getPositionX()+doodle->getWidth()/2 <= platforms[pl]->getPositionX()+platforms[pl]->getWidth()) {
//
//                // checken op de y-coordinaten
//                if (doodle->getPositionY()+doodle->getHeight() >= platforms[pl]->getPositionY()-platforms[pl]->getHeight()/2 &&
//                        doodle->getPositionY()+doodle->getHeight() <= platforms[pl]->getPositionY()+platforms[pl]->getHeight()/2) {
//
//                    doodle->jump();
//                }
//            }

            if (checkForUndetectedCollision(platforms[pl], middleLine)) { // backup check
                doodle->jump();

                if (platforms[pl]->isTouched()) {
                    platforms.erase(platforms.begin()+pl);
                }

                break;
            }
        }
    }

    void World::createStartEntities() {

        doodle = Factory->createPlayer(0.5, 0.5, 0.077, 0.18);

        std::shared_ptr<logic::Platform> p = Factory->createVerticalPlatform(0.5, 0.8, 0.174004, 0.0411);
        platforms.push_back(p);

        std::shared_ptr<logic::Platform> p1 = Factory->createVerticalPlatform(0.2, 0.5, 0.174004, 0.0411);
        platforms.push_back(p1);

        std::shared_ptr<logic::Platform> p2 = Factory->createHorizontalPlatform(0.6, 0.3, 0.174004, 0.0411);
        platforms.push_back(p2);

//        std::shared_ptr<logic::Platform> p3 = Factory->createVerticalPlatform(0.6, 1.2, 0.174004, 0.0411);
//        platforms.push_back(p3);
//
//        std::shared_ptr<logic::Platform> p4 = Factory->createVerticalPlatform(0.6, 1.7, 0.174004, 0.0411);
//        platforms.push_back(p4);
//
//        std::shared_ptr<logic::Platform> p5 = Factory->createTemporaryPlatform(0.4, 1.3, 0.174004, 0.0411);
//        platforms.push_back(p5);
//
//        std::shared_ptr<logic::Platform> p6 = Factory->createTemporaryPlatform(0.4, 1.5, 0.174004, 0.0411);
//        platforms.push_back(p6);
//
//        std::shared_ptr<logic::Platform> p7 = Factory->createTemporaryPlatform(0.4, 1.8, 0.174004, 0.0411);
//        platforms.push_back(p7);

    }

    void World::createEntities() {

        // calculate chance of placing a platform or not.

        float score = doodle->getPositionY();

        float p = 0.70; // beginwaarde = 0.90 (90% kans op platform generation)
        float factor = 1; // represents the depending factor on the score (y-coordinate of our player)
        bool isCreate = logic::Random::Instance().bernoulliDistribution(p*factor);

        // y position of our platform

        float platformYPos = 1+logic::Camera::Instance().getShiftValue();

        // decide which platform to place

        int pl = logic::Random::Instance().uniformIntDistribution(0, 3);
        pl = 0;

        std::shared_ptr<logic::Platform> platform;
        float platformXPos = 0; // going to be overwritten
        switch (pl) {
            case 0:
                platform = Factory->createStaticPlatform(platformXPos, platformYPos, 0.174004, 0.0411);
                break;
            case 1:
                platform = Factory->createVerticalPlatform(platformXPos, platformYPos, 0.174004, 0.0411);
                break;
            case 2:
                platform = Factory->createHorizontalPlatform(platformXPos, platformYPos, 0.174004, 0.0411);
                break;
            case 3:
                platform = Factory->createTemporaryPlatform(platformXPos, platformYPos, 0.174004, 0.0411);
                break;
            default:
                std::cerr << "No platform was created" << std::endl; // default statement used for error output
        }

        // calculate where to place the platform (x position only)

        platformXPos = logic::Random::Instance().uniformRealDistribution(leftBound, rightBound-platform->getWidth());

        platform->setPositionX(platformXPos);
        platforms.push_back(platform);

    }

    void World::update() {

        for (auto pl = 0; pl < platforms.size(); pl++)  {
            platforms[pl]->move();
        }

        doodle->applyGravity();
        doodle->moveVertically();

        if (doodle->getSpeed() <= 0) { // als we aan het vallen zijn
            checkForCollision();
        }

        doodle->setPreviousPositionX(doodle->getPositionX());
        doodle->setPreviousPositionY(doodle->getPositionY());

        if (doodle->getPositionY() >= shiftBorder && doodle->getPositionY() >= logic::Camera::Instance().getShiftValue()+shiftBorder) {
            logic::Camera::Instance().setShiftValue(doodle->getPositionY()-shiftBorder);

            if (static_cast<int>(std::round(((doodle->getPositionY()+0.60)*100)))%5==0) {
                createEntities();
            }
        }
//        if (doodle->getPositionY() <= logic::Camera::Instance().getShiftValue() && doodle->getPositionY() >= logic::Camera::Instance().getShiftValue()+0.5) {
//            //logic::Camera::Instance().setShiftValue(std::min(doodle->getPositionY()-0.6f, 1.0f));
//            logic::Camera::Instance().setShiftValue(doodle->getPositionY()-0.6f);
//
//        }

    }

    bool World::checkForUndetectedCollision(const std::shared_ptr<logic::Platform>& pl, std::vector<std::pair<float,float>> &middleLine) {

        for (int i = 0; i < middleLine.size(); i++) {

            // checken op de x-coordinaten
            if (middleLine[i].first+doodle->getWidth()/2 >= pl->getPositionX() &&
                    middleLine[i].first-doodle->getWidth()/2 <= pl->getPositionX()+pl->getWidth()) {

                // checken op de y-coordinaten
                if (middleLine[i].second <= pl->getPositionY() &&
                        middleLine[i].second >= pl->getPositionY()-pl->getHeight()) {

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

