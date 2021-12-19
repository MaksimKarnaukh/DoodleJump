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

namespace logic {

    class World {

    public:

        std::shared_ptr<logic::Score> score;

        std::shared_ptr<logic::Player> doodle;
        std::deque<std::vector<std::shared_ptr<logic::BGTile>>> bgTiles;
        std::vector<std::shared_ptr<logic::Platform>> platforms;

        std::shared_ptr<logic::AbstractFactory> Factory;

        float leftBound = 0.0f;
        float rightBound = 1.0f;
        float lowerBound = 0.0f;

        float shiftBorder = 0.6f;

        float formerPlatformPosY;

    public:

        World();

        World(std::shared_ptr<logic::AbstractFactory>& factory);

        ~World();

        void receiveInput(std::string &key);

        void checkForCollision();

        bool checkForUndetectedCollision(const std::shared_ptr<logic::Platform>& pl, std::vector<std::pair<float,float>> &middleLine);

        void createStartEntities();

        void createEntities();

        void update();

        static std::vector<std::pair<float,float>> getLineBetweenPoints(float x0, float y0, float x1, float y1);



    };

}



#endif //DOODLEJUMP_WORLD_H
