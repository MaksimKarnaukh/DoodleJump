//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_CONCRETEFACTORY_H
#define DOODLEJUMP_CONCRETEFACTORY_H

#include "../logic_library/AbstractFactory.h"
#include "../game_representation/Player_GR.h"

namespace representation {

    class ConcreteFactory: public logic::AbstractFactory {

        std::shared_ptr<logic::Player> createPlayer(float posX, float posY, float width, float height) override;
    };

}



#endif //DOODLEJUMP_CONCRETEFACTORY_H
