//
// Created by centu on 17/11/2021.
//

#include "ConcreteFactory.h"

namespace representation {

    std::shared_ptr<logic::Player>
    ConcreteFactory::createPlayer(float posX, float posY, float width, float height) {

        std::shared_ptr<logic::Player> playerModel(new logic::Player(posX, posY, width, height));
        std::shared_ptr<representation::Player_GR> playerView(new representation::Player_GR(playerModel));

        playerModel->setWidth((float)playerView->getTexture().getSize().x*((float)1/(float)4.78896)/(float)representation::Window::Instance()->GetWindowSize().x); // *0.25
        playerModel->setHeight((float)playerView->getTexture().getSize().y*((float)1/(float)3.637695)/(float)representation::Window::Instance()->GetWindowSize().y);

        playerModel->registerObserver(playerView);

        return playerModel;
    }

    std::shared_ptr<logic::Platform>
    ConcreteFactory::createPlatform(float posX, float posY, float width, float height) {

        std::shared_ptr<logic::Platform> platformModel(new logic::Platform_Static(posX, posY, width, height));
        std::shared_ptr<representation::Platform_Static_GR> platformView(new representation::Platform_Static_GR(platformModel));

        platformModel->setWidth((float)platformView->getTexture().getSize().x*((float)1/(float)0.5747)/(float)representation::Window::Instance()->GetWindowSize().x);
        platformModel->setHeight((float)platformView->getTexture().getSize().y*((float)1/(float)0.32426)/(float)representation::Window::Instance()->GetWindowSize().y);

        platformModel->registerObserver(platformView);

        return platformModel;
    }

    ConcreteFactory::ConcreteFactory() = default;
}