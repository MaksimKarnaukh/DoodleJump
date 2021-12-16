//
// Created by centu on 17/11/2021.
//

#include "ConcreteFactory.h"

namespace representation {

    std::shared_ptr<logic::Player>
    ConcreteFactory::createPlayer(float posX, float posY, float width, float height) {

        std::shared_ptr<logic::Player> playerModel(new logic::Player(posX, posY));
        std::shared_ptr<representation::Player_GR> playerView(new representation::Player_GR(playerModel));

        playerModel->setWidth(width); // hardcoded for logic
        playerModel->setHeight(height);

        playerModel->registerObserver(playerView);

        return playerModel;
    }

    std::shared_ptr<logic::Platform>
    ConcreteFactory::createPlatform(float posX, float posY, float width, float height) {


    }

    std::shared_ptr<logic::Platform>
    ConcreteFactory::createStaticPlatform(float posX, float posY, float width, float height) {

        std::shared_ptr<logic::Platform> platformModel(new logic::Platform_Static(posX, posY));
        std::shared_ptr<representation::Platform_Static_GR> platformView(new representation::Platform_Static_GR(platformModel));

        platformModel->setWidth(width);
        platformModel->setHeight(height);

        platformModel->registerObserver(platformView);

        return platformModel;
    }

    std::shared_ptr<logic::Platform>
    ConcreteFactory::createTemporaryPlatform(float posX, float posY, float width, float height) {

        std::shared_ptr<logic::Platform> platformModel(new logic::Platform_Temporary(posX, posY));
        std::shared_ptr<representation::Platform_Temporary_GR> platformView(new representation::Platform_Temporary_GR(platformModel));

        platformModel->setWidth(width);
        platformModel->setHeight(height);

        platformModel->registerObserver(platformView);

        return platformModel;
    }

    std::shared_ptr<logic::Platform>
    ConcreteFactory::createHorizontalPlatform(float posX, float posY, float width, float height) {

        std::shared_ptr<logic::Platform> platformModel(new logic::Platform_Horizontal(posX, posY));
        std::shared_ptr<representation::Platform_Horizontal_GR> platformView(new representation::Platform_Horizontal_GR(platformModel));

        platformModel->setWidth(width);
        platformModel->setHeight(height);

        platformModel->registerObserver(platformView);

        return platformModel;
    }

    std::shared_ptr<logic::Platform>
    ConcreteFactory::createVerticalPlatform(float posX, float posY, float width, float height) {

        std::shared_ptr<logic::Platform> platformModel(new logic::Platform_Vertical(posX, posY));
        std::shared_ptr<representation::Platform_Vertical_GR> platformView(new representation::Platform_Vertical_GR(platformModel));

        platformModel->setWidth(width);
        platformModel->setHeight(height);

        platformModel->registerObserver(platformView);

        return platformModel;
    }

    std::shared_ptr<logic::Bonus> ConcreteFactory::createBonus(float posX, float posY, float width, float height) {
        return std::shared_ptr<logic::Bonus>();
    }

    ConcreteFactory::ConcreteFactory() = default;
}