//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_WORLD_H
#define DOODLEJUMP_WORLD_H

#include "Player.h"
#include "Platform.h"
#include "BGTile.h"
#include "Bonus.h"
#include "AbstractFactory.h"

#include <memory>

namespace logic {

    class World {

    public:

        std::shared_ptr<logic::Player> doodle;
        std::shared_ptr<logic::BGTile> bgTile;
        std::vector<std::shared_ptr<logic::Platform>> platforms;

    public:

        World();

        void receiveInput(std::string &key);

        void isCollision();

        void createEntities(const std::shared_ptr<logic::AbstractFactory>& Factory);

        void update();

    };

}



#endif //DOODLEJUMP_WORLD_H
