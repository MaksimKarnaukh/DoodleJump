//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_WORLD_H
#define DOODLEJUMP_WORLD_H

#include "string"
#include "cmath"
#include "iostream"
#include "Player.h"
#include "Platform.h"
#include "BGTile.h"
#include "Bonus.h"
#include "AbstractFactory.h"
#include "Camera.h"
#include <memory>
#include "Random.h"
#include "Score.h"
#include <deque>
#include <map>

namespace logic {

    class World {

    public:

        std::shared_ptr<logic::Score> score;
        std::shared_ptr<logic::Player> doodle;
        std::deque<std::vector<std::shared_ptr<logic::BGTile>>> bgTiles;
        std::vector<std::shared_ptr<logic::Platform>> platforms;
        std::vector<std::shared_ptr<logic::Bonus>> bonuses;

        std::shared_ptr<logic::AbstractFactory> Factory;

        float leftBound = logic::utility::Camera::Instance().getLeftBound();
        float rightBound = logic::utility::Camera::Instance().getRightBound();
        float lowerBound = logic::utility::Camera::Instance().getLowerBound();
        float shiftBorder = logic::utility::Camera::Instance().getShiftBorder();

        float formerPlatformPosY;
        float formerPlatformPosX;
        bool wasBonusGenerated = false;

        bool gameOver = false;

        std::map<int, std::map<int, float>> percentages;

    public:

        World();
        World(std::shared_ptr<logic::AbstractFactory>& factory);
        ~World();

        void receiveInput(std::string &key);

        void checkForCollision();

        //bool checkForUndetectedCollision(const std::shared_ptr<logic::Platform>& pl, std::vector<std::pair<float,float>> &middleLine);

        template<class entity>
        bool checkForUndetectedCollision(const entity& pl, std::vector<std::pair<float,float>> &middleLine);

        void createStartEntities();

        void createEntities();

        void update();

        static std::vector<std::pair<float,float>> getLineBetweenPoints(float x0, float y0, float x1, float y1);

        void setupPercentages();



    };

}



#endif //DOODLEJUMP_WORLD_H
