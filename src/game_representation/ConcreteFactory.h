//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_CONCRETEFACTORY_H
#define DOODLEJUMP_CONCRETEFACTORY_H

#include "../logic_library/AbstractFactory.h"
#include "../game_representation/Player_GR.h"
#include "../game_representation/Platform_Static_GR.h"
#include "../game_representation/Platform_Horizontal_GR.h"
#include "../game_representation/Platform_Temporary_GR.h"
#include "../game_representation/Platform_Vertical_GR.h"
#include "BGTile_GR.h"

#include "Window.h"

namespace representation {

    class ConcreteFactory: public logic::AbstractFactory {

    public:
        ConcreteFactory();

        std::shared_ptr<logic::Player> createPlayer(float posX, float posY, float width, float height) override;

        std::shared_ptr<logic::Platform> createPlatform(float posX, float posY, float width, float height) override;
        std::shared_ptr<logic::Platform> createStaticPlatform(float posX, float posY, float width, float height) override;
        std::shared_ptr<logic::Platform> createTemporaryPlatform(float posX, float posY, float width, float height) override;
        std::shared_ptr<logic::Platform> createHorizontalPlatform(float posX, float posY, float width, float height) override;
        std::shared_ptr<logic::Platform> createVerticalPlatform(float posX, float posY, float width, float height) override;

        std::shared_ptr<logic::Bonus> createBonus(float posX, float posY, float width, float height) override;

        std::shared_ptr<logic::BGTile> createBGTile(float posX, float posY, float width, float height) override;


    };

}



#endif //DOODLEJUMP_CONCRETEFACTORY_H
