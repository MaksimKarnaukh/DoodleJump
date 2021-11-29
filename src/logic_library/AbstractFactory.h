//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_ABSTRACTFACTORY_H
#define DOODLEJUMP_ABSTRACTFACTORY_H

#include "Player.h"
#include "Observer.h"

namespace logic {

    class AbstractFactory {

    public:

        AbstractFactory();

        virtual std::shared_ptr<logic::Player> createPlayer(float posX, float posY, float width, float height) = 0;

    };

}



#endif //DOODLEJUMP_ABSTRACTFACTORY_H
