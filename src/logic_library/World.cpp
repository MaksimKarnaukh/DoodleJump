//
// Created by centu on 17/11/2021.
//

#include "World.h"

#include <memory>

namespace logic {

    World::World() = default;

    World::World(std::shared_ptr<logic::AbstractFactory> &factory) : Factory(factory) {

        logic::Random& random = logic::Random::Instance();
        logic::Camera& camera = logic::Camera::Instance();

        createStartEntities();

        score = std::make_shared<logic::Score>(doodle);
        doodle->registerObserver(score);

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

        if ((doodle->getPositionY() <= lowerBound) || (doodle->getPositionY() <= lowerBound+logic::Camera::Instance().getShiftValue())) {
            gameOver = true;
        }

        for (auto b = 0; b < bonuses.size(); b++) {

            if (checkForUndetectedCollision(bonuses[b], middleLine)) { // backup check
                doodle->touchedBonus(bonuses[b]->getBonusForce());
                for (auto i = 0; i < bonuses[b]->getObservers().size(); i++) {
                    bonuses[b]->removeObserver(bonuses[b]->getObservers()[i]); // remove all observers
                }

                bonuses.erase(bonuses.begin()+b);
                break;
            }

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

//        std::shared_ptr<logic::Bonus> b1 = Factory->createSpring(0.1, 0+0.0412, 0.174004/3, 0.0411);
//        bonuses.push_back(b1);
//
//        std::shared_ptr<logic::Bonus> b2 = Factory->createJetpack(0.9, 0+0.06576, 0.0696, 0.06576);
//        bonuses.push_back(b2);

        //

        for (auto c = 0; c < (1.5/0.05)+30.0; c++) { // +35.0 want als we op lage fps zitten, zou dit anders voor visuele problemen zorgen.
            std::vector<std::shared_ptr<logic::BGTile>> row;
            for (auto r = 0; r < (rightBound/0.05); r++) {
                std::shared_ptr<logic::BGTile> bgTile = Factory->createBGTile((float)(r*0.05), float((c+1)*0.03), 0.05, 0.05);
                row.push_back(bgTile);
            }
            bgTiles.push_back(row);
        }
    }

    void World::createEntities() {

        bool wasBonusGeneratedTemp = false; // to indicate whether we created a bonus this time

        // calculate chance of placing a platform or not.

        float p = 0.90; // beginwaarde = 0.90 (90% kans op platform generation)
        float factor = std::max( 0.25f,  (1.0f-(std::floor(doodle->getPositionY()/3))/100) ); // represents the depending factor on the score (y-coordinate of our player)
        bool isCreate = logic::Random::Instance().bernoulliDistribution(p*factor);
//        std::cout << "factor : " << factor << " chance : " << p*factor << std::endl;

        // y position of our platform
        float platformYPos = 1+logic::Camera::Instance().getShiftValue();

        if (formerPlatformPosY+0.05 < platformYPos) {

            if (isCreate) {
                formerPlatformPosY = platformYPos;

                // decide which platform to place

                int pl = logic::Random::Instance().uniformIntDistribution(0, 3);
                pl = 0;

                std::shared_ptr<logic::Platform> platform;
                std::shared_ptr<logic::Bonus> bonus;

                float platformXPos = 0; // going to be overwritten

                float chanceForBonus = 0.10;
                float factorBonus = std::min(0.08f, (std::floor(doodle->getPositionY()/500))/100); // per 500 hoogte wordt kans op bonus verminderd met 0.01 met op het einde minimum een waarde van 0.02.
                bool isCreateBonus;

                switch (pl) {
                    case 0:
                        platform = Factory->createStaticPlatform(platformXPos, platformYPos, 0.174004, 0.0411);

                        isCreateBonus = logic::Random::Instance().bernoulliDistribution(chanceForBonus-factorBonus);
                        if (isCreateBonus) {

                            // decide which bonus to place
                            int bonusKind = logic::Random::Instance().uniformIntDistribution(0, 9);

                            if (bonusKind < 8) {
                                bonus = Factory->createSpring(0, 0, 0.058, 0.0411);
                            }
                            else {
                                bonus = Factory->createJetpack(0, 0, 0.0696, 0.06576);
                            }
                            wasBonusGeneratedTemp = true;
                        }

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

                if (wasBonusGenerated) {
                    float platformXPos1 = logic::Random::Instance().uniformRealDistribution(leftBound+0.02f, formerPlatformPosX-platform->getWidth()-0.08f);
                    float platformXPos2 = logic::Random::Instance().uniformRealDistribution(formerPlatformPosX+platform->getWidth()+0.08f, rightBound-platform->getWidth()-0.02f);

                    if (platformXPos1 < leftBound) {
                        platformXPos = platformXPos2;
                    }
                    else if (platformXPos2 > rightBound-platform->getWidth()-0.02f) {
                        platformXPos = platformXPos1;
                    }
                    else {
                        int posDecider = logic::Random::Instance().uniformIntDistribution(0, 9);
                        if (posDecider < 5) {
                            platformXPos = platformXPos1;
                        }
                        else {
                            platformXPos = platformXPos2;
                        }
                    }
                }
                else {
                    platformXPos = logic::Random::Instance().uniformRealDistribution(leftBound+0.02f, rightBound-platform->getWidth()-0.02f);
                }

                platform->setPositionX(platformXPos);
                platforms.push_back(platform);

                formerPlatformPosX = platformXPos;

                if (wasBonusGeneratedTemp) {
                    float bonusXPos = logic::Random::Instance().uniformRealDistribution(platformXPos+0.01f, platformXPos+platform->getWidth()-bonus->getWidth()-0.01f);
                    bonus->setPositionX(bonusXPos);
                    bonus->setPositionY(platformYPos+bonus->getHeight());
                    bonuses.push_back(bonus);
                    wasBonusGenerated = true;
                }
                else {
                    wasBonusGenerated = false;
                }
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
        // deleten van bonussen die uit scherm zijn
        for (int b = 0; b < bonuses.size(); b++) {
            if (bonuses[b]->getPositionY() < logic::Camera::Instance().getShiftValue()) {

                for (auto i = 0; i < bonuses[b]->getObservers().size(); i++) {
                    bonuses[b]->removeObserver(bonuses[b]->getObservers()[i]); // remove all observers
                }

                bonuses.erase(bonuses.begin()+b);
            }
        }
        // recycling of platforms that are out of screen.

        for (auto i = 0; i < 20; i++) { // We check the bottom 20 platforms in case we get a drop in fps. The background tile generation, with this loop, can produce without visual errors or 'glitches' at a minimum of 8 fps.
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
        }

        //std::cout << "score : " << std::to_string(score->getScore()) << std::endl;
    }


    template <class entity>
    bool World::checkForUndetectedCollision(const entity& pl, std::vector<std::pair<float,float>> &middleLine) {

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

        for (auto o = 0; o < doodle->getObservers().size(); o++) {
            doodle->removeObserver(doodle->getObservers()[o]);
        }

        for (int pl = 0; pl < platforms.size(); pl++) {

            for (auto i = 0; i < platforms[pl]->getObservers().size(); i++) {
                platforms[pl]->removeObserver(platforms[pl]->getObservers()[i]); // remove all observers
            }

            platforms.erase(platforms.begin()+pl);
        }
        for (int bg = 0; bg < bgTiles.size(); bg++) {

            for (auto i = 0; i < bgTiles[bg].size(); i++) {

                for (auto j = 0; j < bgTiles[bg][i]->getObservers().size(); j++) {
                    bgTiles[bg][i]->removeObserver((bgTiles[bg][i]->getObservers()[j])); // remove all observers

                }
            }

            bgTiles.erase(bgTiles.begin()+bg);
        }
        for (int b = 0; b < bonuses.size(); b++) {

            for (auto i = 0; i < bonuses[b]->getObservers().size(); i++) {
                bonuses[b]->removeObserver(bonuses[b]->getObservers()[i]); // remove all observers
            }

            bonuses.erase(bonuses.begin()+b);
        }
        logic::Camera::Instance().setShiftValue(0.0f);
    }

}

