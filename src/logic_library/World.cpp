

#include "World.h"
#include <memory>

namespace logic {

    World::World() = default;

    World::World(std::shared_ptr<logic::AbstractFactory> &factory) : Factory(factory) {

        logic::utility::Random::Instance();
        logic::utility::Camera::Instance();

        createStartEntities();

        score = std::make_shared<logic::Score>(doodle);
        doodle->registerObserver(score);

        setupPercentages();

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

        float x0 = doodle->getPreviousPositionX() + doodle->getWidth() / 2;
        float y0 = doodle->getPreviousPositionY() - doodle->getHeight();
        float x1 = doodle->getPositionX() + doodle->getWidth() / 2;
        float y1 = doodle->getPositionY() - doodle->getHeight();

        std::vector<std::pair<float, float>> middleLine = getLineBetweenPoints(x0, y0, x1, y1);

        if ((doodle->getPositionY() <= lowerBound) ||
            (doodle->getPositionY() <= lowerBound + logic::utility::Camera::Instance().getShiftValue())) {
            //gameOver = true;
            doodle->jump();
        }

        for (auto b = 0; b < bonuses.size(); b++) {

            if (checkForUndetectedCollision(bonuses[b], middleLine, doodle)) {
                doodle->touchedBonus(bonuses[b]->getBonusForce());
                score->setScore(score->getScore() + bonuses[b]->getScoreIncrease());
                for (auto i = 0; i < bonuses[b]->getObservers().size(); i++) {
                    bonuses[b]->removeObserver(bonuses[b]->getObservers()[i]); // remove all observers
                }
                bonuses.erase(bonuses.begin() + b);
                break;
            }

        }

        // check if we hit a platform.
        for (auto pl = 0; pl < platforms.size(); pl++) {

            if (checkForUndetectedCollision(platforms[pl], middleLine, doodle)) {
                doodle->jump();
                float dec = platforms[pl]->isTouched();
                if ((int) (dec * 10)) {
                    if (platforms[pl]->getTimesTouched() > 1) {
                        score->setScore(score->getScore() - dec);
                    }
                } else {
                    for (auto i = 0; i < platforms[pl]->getObservers().size(); i++) {
                        platforms[pl]->removeObserver(platforms[pl]->getObservers()[i]);
                    }
                    platforms.erase(platforms.begin() + pl); // observers deleted in function
                }
                break;
            }
        }

    }

    void World::createStartEntities() {

        doodle = Factory->createPlayer(0.5, 0.5, 0.077, 0.18);

        // beginning platformen hardcoded so that the player can easily start playing.

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

        createStartingBGTiles();

    }

    void World::createEntities() {

        bool wasBonusGeneratedTemp = false; // to indicate whether we created a bonus this time

        // calculate chance of placing a platform or not.
        float p = 0.90; // begin value = 0.90 (90% chance for platform generation)
        float factor = std::max( 0.25f,  (1.0f-(std::floor(doodle->getPositionY()/3))/100) ); // represents the depending factor on the score (y-coordinate of our player)
        bool isCreate = logic::utility::Random::Instance().bernoulliDistribution(p*factor);

        // y position of our platform
        float platformYPos = 1+logic::utility::Camera::Instance().getShiftValue();
        if (platformYPos > formerPlatformPosY+0.35) { // min distance between platforms guaranteed
            isCreate = true;
        }

        if (formerPlatformPosY+0.05 < platformYPos) {

            if (isCreate) {
                formerPlatformPosY = platformYPos;

                // decide which platform to place
                int pl = choosePlatformType();

                std::shared_ptr<logic::Platform> platform;
                std::shared_ptr<logic::Bonus> bonus;

                float platformXPos = 0; // going to be overwritten

                // calculate chance of placing a bonus or not.
                float chanceForBonus = 0.10;
                float factorBonus = std::min(0.08f, (std::floor(doodle->getPositionY()/500))/100); // per 500 height, the chance for a bonus gets decreased by 0.01 with at the end a minimum value of 0.02.
                bool isCreateBonus;

                switch (pl) {
                    case 0:
                        platform = Factory->createStaticPlatform(platformXPos, platformYPos, 0.174004, 0.0411);

                        isCreateBonus = logic::utility::Random::Instance().bernoulliDistribution(chanceForBonus-factorBonus);
                        if (isCreateBonus) {

                            // decide which bonus to place
                            chooseBonusType(bonus);
                            wasBonusGeneratedTemp = true;
                        }
                        break;
                    case 1:
                        platform = Factory->createTemporaryPlatform(platformXPos, platformYPos, 0.174004, 0.0411);
                        break;
                    case 2:
                        platform = Factory->createVerticalPlatform(platformXPos, platformYPos, 0.174004, 0.0411);
                        break;
                    case 3:
                        platform = Factory->createHorizontalPlatform(platformXPos, platformYPos, 0.174004, 0.0411);
                        break;
                    default:
                        std::cerr << "No platform was created" << std::endl; // default statement used for error output
                }

                // calculate where to place the platform (x position only)
                platformXPos = calculatePlatformXPos(platform);

                platform->setPositionX(platformXPos);
                platforms.push_back(platform);

                formerPlatformPosX = platformXPos;

                if (wasBonusGeneratedTemp) {
                    float bonusXPos = logic::utility::Random::Instance().uniformRealDistribution(platformXPos+0.01f, platformXPos+platform->getWidth()-bonus->getWidth()-0.01f);
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

        if (doodle->getSpeed() <= 0) { // when we are falling down
            checkForCollision();
        }
        checkForCollisionBetweenPlatforms();

        doodle->setPreviousPositionX(doodle->getPositionX());
        doodle->setPreviousPositionY(doodle->getPositionY());

        if (doodle->getPositionY() >= shiftBorder && doodle->getPositionY() >= logic::utility::Camera::Instance().getShiftValue()+shiftBorder) {
            logic::utility::Camera::Instance().setShiftValue(doodle->getPositionY()-shiftBorder);

            createEntities();

            for (auto a = 0; a < platforms.size(); a++) {
                platforms[a]->notifyObservers();
            }
            for (auto a = 0; a < bonuses.size(); a++) {
                bonuses[a]->notifyObservers();
            }
            doodle->notifyObservers();

        }

        // deleting of platforms that are out of view.
        deleteOutOfViewPlatforms();

        // deleting of bonusses that are out of view.
        deleteOutOfViewBonusses();

        // recycling of BG tiles that are out of view.
        recycleOutOfViewBGTiles();

    }

    bool World::checkForUndetectedCollision(const std::shared_ptr<logic::EntityModel>& pl, std::vector<std::pair<float,float>> &middleLine, const std::shared_ptr<logic::EntityModel>& pl2) const {

        for (int i = 0; i < middleLine.size(); i++) {
            // check for the x-coordinates
            if (middleLine[i].first+pl2->getWidth()/2 >= pl->getPositionX() &&
                middleLine[i].first-pl2->getWidth()/2 <= pl->getPositionX()+pl->getWidth()) {

                // check for the y-coordinates
                if (middleLine[i].second <= pl->getPositionY() &&
                    middleLine[i].second >= pl->getPositionY()-pl->getHeight()) {

                    return true;
                }
            }
        }
        return false;
    }

    std::vector<std::pair<float,float>> World::getLineBetweenPoints(float x0, float y0, float x1, float y1)  {

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

        logic::utility::Camera::Instance().setShiftValue(0.0f);
    }

    void World::setupPercentages() {

        std::map<int, float> map100 = {
                {0, 1}, // 0: Static
                {1, 0}, // 1: Temporary
                {2, 0}, // 2: Vertical
                {3, 0} // 3: Horizontal
        };
        percentages[100] = map100;

        std::map<int, float> map200 = {
                {0, 0.8}, // 80%
                {1, 0},
                {2, 0},
                {3, 1} // 20%
        };
        percentages[200] = map200;

        std::map<int, float> map400 = {
                {0, 0.6}, // 60%
                {1, 0},
                {2, 0.8}, // 20%
                {3, 1} // 20%
        };
        percentages[400] = map400;

        std::map<int, float> map800 = {
                {0, 0.4}, // 40%
                {1, 0.7}, // 30%
                {2, 0.85}, // 15%
                {3, 1} // 15%
        };
        percentages[800] = map800;

        std::map<int, float> map2000 = {
                {0, 0.2}, // 20%
                {1, 0.6}, // 40%
                {2, 0.8}, // 20%
                {3, 1} // 20%
        };
        percentages[2000] = map2000;

        std::map<int, float> map4000 = {
                {0, 0.1}, // 10%
                {1, 0.7}, // 60%
                {2, 0.85}, // 15%
                {3, 1} // 15%
        };
        percentages[4000] = map4000;

        std::map<int, float> map8000 = {
                {0, 0.05}, // 5%
                {1, 0.7}, // 65%
                {2, 0.85}, // 15%
                {3, 1} // 15%
        };
        percentages[8000] = map8000;

        std::map<int, float> map16000 = {
                {0, 0.05}, // 5%
                {1, 0.6}, // 55%
                {2, 0.8}, // 20%
                {3, 1} // 20%
        };
        percentages[8000] = map16000;

    }

    void World::createStartingBGTiles() {

        float bgTileSideLength = 0.05f;
        for (auto c = 0; c < (1.5/bgTileSideLength)+30.0; c++) { // +35.0, otherwise at low fps, we get visual problems.
            std::vector<std::shared_ptr<logic::BGTile>> row;
            for (auto r = 0; r < (rightBound/bgTileSideLength); r++) {
                std::shared_ptr<logic::BGTile> bgTile = Factory->createBGTile((float)(r*bgTileSideLength), float((c+1)*0.03), bgTileSideLength, bgTileSideLength);
                row.push_back(bgTile);
            }
            bgTiles.push_back(row);
        }
    }

    void World::deleteOutOfViewPlatforms() {

        for (int pl = 0; pl < platforms.size(); pl++) {
            if (platforms[pl]->getPositionY() < logic::utility::Camera::Instance().getShiftValue()) {

                for (auto i = 0; i < platforms[pl]->getObservers().size(); i++) {
                    platforms[pl]->removeObserver(platforms[pl]->getObservers()[i]); // remove all observers
                }

                platforms.erase(platforms.begin()+pl);
            }
        }

    }

    void World::deleteOutOfViewBonusses() {

        for (int b = 0; b < bonuses.size(); b++) {
            if (bonuses[b]->getPositionY() < logic::utility::Camera::Instance().getShiftValue()) {

                for (auto i = 0; i < bonuses[b]->getObservers().size(); i++) {
                    bonuses[b]->removeObserver(bonuses[b]->getObservers()[i]); // remove all observers
                }

                bonuses.erase(bonuses.begin()+b);
            }
        }

    }

    void World::recycleOutOfViewBGTiles() {

        for (auto i = 0; i < 20; i++) { // We check the bottom 20 platforms in case we get a drop in fps.
            if (bgTiles.front()[0]->getPositionY() < logic::utility::Camera::Instance().getShiftValue()) {
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
            else {
                break;
            }
        }
        for (auto a = 0; a < bgTiles.size(); a++) {

            for (auto b = 0; b < bgTiles[a].size(); b++) {
                bgTiles[a][b]->notifyObservers();
            }
        }

    }

    int World::choosePlatformType() const {

        std::map<int, float> chanceMap;
        for (auto it = percentages.begin(); it != percentages.end(); it++) {
            if (doodle->getPositionY()*10 < (float) it->first) {
                chanceMap = it->second;
                break;

            }
        }
        if (doodle->getPositionY()*10 >= 8000) {
            chanceMap = {
                    {0, 0},
                    {1, 0.5}, // 50%
                    {2, 0.6}, // 10%
                    {3, 1} // 40%
            };
        }

        float pl1 = logic::utility::Random::Instance().uniformRealDistribution(0, 1);

        for (auto it = chanceMap.begin(); it != chanceMap.end(); it++) {
            if (pl1 < it->second) {
                return it->first;
            }
        }
        return 0; // just to have a return value

    }

    void World::chooseBonusType(std::shared_ptr<logic::Bonus>& bonus) const {

        int bonusKind = logic::utility::Random::Instance().uniformIntDistribution(0, 9);

        if (bonusKind < 8) {
            bonus = Factory->createSpring(0, 0, 0.058, 0.0411);
        }
        else {
            bonus = Factory->createJetpack(0, 0, 0.0696, 0.06576);
        }
    }

    float World::calculatePlatformXPos(const std::shared_ptr<logic::Platform>& platform) const {

        float platformXPos;
        if (wasBonusGenerated) {
            float platformXPos1 = logic::utility::Random::Instance().uniformRealDistribution(leftBound+0.02f, formerPlatformPosX-platform->getWidth()-0.08f); //// +0.02 watch out
            float platformXPos2 = logic::utility::Random::Instance().uniformRealDistribution(formerPlatformPosX+platform->getWidth()+0.08f, rightBound-platform->getWidth()-0.02f);

            if (platformXPos1 < leftBound) {
                platformXPos = platformXPos2;
            }
            else if (platformXPos2 > rightBound-platform->getWidth()-0.02f) {
                platformXPos = platformXPos1;
            }
            else {
                int posDecider = logic::utility::Random::Instance().uniformIntDistribution(0, 9);
                if (posDecider < 5) {
                    platformXPos = platformXPos1;
                }
                else {
                    platformXPos = platformXPos2;
                }
            }
        }
        else {
            platformXPos = logic::utility::Random::Instance().uniformRealDistribution(leftBound+0.02f, rightBound-platform->getWidth()-0.02f);
        }
        return platformXPos;
    }

    void World::checkForCollisionBetweenPlatforms() {

        // collision between platforms
        for (auto pl0 = 0; pl0 < platforms.size(); pl0++) {
            for (auto pl1 = 0; pl1 < platforms.size(); pl1++) {
                if (pl0 != pl1) {
                    if (platforms[pl0]->getPositionX()+platforms[pl0]->getWidth() >= platforms[pl1]->getPositionX() &&
                        platforms[pl0]->getPositionX() <= platforms[pl1]->getPositionX()+platforms[pl1]->getWidth()) {

                        // checken op de y-coordinaten
                        if (platforms[pl0]->getPositionY() >= platforms[pl1]->getPositionY()-platforms[pl1]->getHeight() &&
                            platforms[pl0]->getPositionY()-platforms[pl0]->getHeight() <= platforms[pl1]->getPositionY()) {

                            platforms[pl0]->changeDirection();
                            platforms[pl1]->changeDirection();

                        }
                    }
                }
            }
        }
    }

}

