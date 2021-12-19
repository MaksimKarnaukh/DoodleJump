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

        doodle = Factory->createPlayer(0.5, 0.4, 0.077, 0.18);

        // begin platformen gehardcode zodat de speler gemakkelijk vanaf het begin al kan spelen.

        std::shared_ptr<logic::Platform> p = Factory->createStaticPlatform(0.4, 0.3, 0.174004, 0.0411);
        platforms.push_back(p);

        std::shared_ptr<logic::Platform> p1 = Factory->createStaticPlatform(0.2, 0.5, 0.174004, 0.0411);
        platforms.push_back(p1);

        std::shared_ptr<logic::Platform> p2 = Factory->createStaticPlatform(0.6, 0.5, 0.174004, 0.0411);
        platforms.push_back(p2);

        std::shared_ptr<logic::Platform> p3 = Factory->createStaticPlatform(0.4, 0.7, 0.174004, 0.0411);
        platforms.push_back(p3);

        std::shared_ptr<logic::Platform> p4 = Factory->createStaticPlatform(0.1, 0.9, 0.174004, 0.0411);
        platforms.push_back(p4);

        std::shared_ptr<logic::Platform> p5 = Factory->createStaticPlatform(0.7, 0.9, 0.174004, 0.0411);
        platforms.push_back(p5);

        //

        for (auto c = 0; c < (1.5/0.05)+35.0; c++) { // +35.0 want als we op lage fps zitten, zou dit anders voor visuele problemen zorgen.
            std::vector<std::shared_ptr<logic::BGTile>> row;
            for (auto r = 0; r < rightBound/0.05; r++) {
                std::shared_ptr<logic::BGTile> bgTile = Factory->createBGTile((float)(r*0.05), float((c+1)*0.03), 0.05, 0.05);
                row.push_back(bgTile);
            }
            bgTiles.push_back(row);
        }
    }

    void World::createEntities() {

        // calculate chance of placing a platform or not.

        float p = 0.90; // beginwaarde = 0.90 (90% kans op platform generation)
        float factor = 1; // represents the depending factor on the score (y-coordinate of our player)
        bool isCreate = logic::Random::Instance().bernoulliDistribution(p*factor);

        // y position of our platform

        float platformYPos = 1+logic::Camera::Instance().getShiftValue();
        if (formerPlatformPosY+0.05 < platformYPos) {

            if (isCreate) {
                formerPlatformPosY = platformYPos;

                // decide which platform to place

                int pl = logic::Random::Instance().uniformIntDistribution(0, 3);
                //pl = 0;

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

                platformXPos = logic::Random::Instance().uniformRealDistribution(leftBound+0.01f, rightBound-platform->getWidth()-0.01f);

                platform->setPositionX(platformXPos);
                platforms.push_back(platform);
            }

        }

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

            //if (static_cast<int>(std::round(((doodle->getPositionY()+0.45)*100)))%5==0) {
                createEntities();
            //}
        }

//        if (doodle->getPositionY() <= logic::Camera::Instance().getShiftValue() && doodle->getPositionY() >= logic::Camera::Instance().getShiftValue()+0.5) {
//            //logic::Camera::Instance().setShiftValue(std::min(doodle->getPositionY()-0.6f, 1.0f));
//            logic::Camera::Instance().setShiftValue(doodle->getPositionY()-0.6f);
//
//        }

        std::cout << "Number of platforms: " << platforms.size() << std::endl;

        // deleten van platforms die uit scherm zijn.
        for (int pl = 0; pl < platforms.size(); pl++) {
            if (platforms[pl]->getPositionY() < logic::Camera::Instance().getShiftValue()) {

                for (auto i = 0; i < platforms[pl]->getObservers().size(); i++) {
                    platforms[pl]->removeObserver(platforms[pl]->getObservers()[i]); // remove all observers
                }

                platforms.erase(platforms.begin()+pl);
            }
        }

        // recycling of platforms that are out of screen.

        if (bgTiles.front()[0]->getPositionY() < logic::Camera::Instance().getShiftValue()) {
            float highestYTile = bgTiles.back()[0]->getPositionY();
            std::vector<std::shared_ptr<logic::BGTile>> r;
            for (auto t = 0; t < bgTiles.front().size(); t++) {
                std::shared_ptr<logic::BGTile> tile = bgTiles.front()[t];
                tile->setPositionY(highestYTile+0.03f);
                r.push_back(tile);
            }
            bgTiles.pop_front();
            bgTiles.push_back(r);
        }


//        for (auto i = 0; i < doodle->getObservers().size(); i++) {
//            if (doodle->getObservers()[i]->isScore()) {
//                score = std::dynamic_pointer_cast<logic::Score>(doodle->getObservers()[i]);
//            }
//        }
//        std::cout << "score : " << std::to_string(score->getScore()) << std::endl;
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

    World::~World() {
        //doodle.reset();

        for (int pl = 0; pl < platforms.size(); pl++) {

            for (auto i = 0; i < platforms[pl]->getObservers().size(); i++) {
                platforms[pl]->removeObserver(platforms[pl]->getObservers()[i]); // remove all observers
            }

            platforms.erase(platforms.begin()+pl);
        }
    }


}

