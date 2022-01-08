// Author: Maksim Karnaukh

#include "ConcreteFactory.h"

namespace representation {

std::shared_ptr<logic::Player> ConcreteFactory::createPlayer(float posX, float posY, float width, float height)
{

        std::shared_ptr<logic::Player> playerModel = std::make_shared<logic::Player>(posX, posY, width, height);
        std::shared_ptr<representation::Player_GR> playerView =
            std::make_shared<representation::Player_GR>(playerModel);

        playerModel->registerObserver(playerView);

        std::shared_ptr<logic::Score> score = std::make_shared<logic::Score>(playerModel);
        playerModel->registerObserver(score);

        playerViews.push_back(std::move(playerView));

        return playerModel;
}

std::shared_ptr<logic::Platform> ConcreteFactory::createStaticPlatform(float posX, float posY, float width,
                                                                       float height)
{

        std::shared_ptr<logic::Platform> platformModel =
            std::make_shared<logic::Platform_Static>(posX, posY, width, height);
        std::shared_ptr<representation::Platform_Static_GR> platformView =
            std::make_shared<representation::Platform_Static_GR>(platformModel);

        platformModel->registerObserver(platformView);

        platformViews.push_back(std::move(platformView));

        return platformModel;
}

std::shared_ptr<logic::Platform> ConcreteFactory::createTemporaryPlatform(float posX, float posY, float width,
                                                                          float height)
{

        std::shared_ptr<logic::Platform> platformModel =
            std::make_shared<logic::Platform_Temporary>(posX, posY, width, height);
        std::shared_ptr<representation::Platform_Temporary_GR> platformView =
            std::make_shared<representation::Platform_Temporary_GR>(platformModel);

        platformModel->registerObserver(platformView);

        platformViews.push_back(std::move(platformView));

        return platformModel;
}

std::shared_ptr<logic::Platform> ConcreteFactory::createHorizontalPlatform(float posX, float posY, float width,
                                                                           float height)
{

        std::shared_ptr<logic::Platform> platformModel =
            std::make_shared<logic::Platform_Horizontal>(posX, posY, width, height);
        std::shared_ptr<representation::Platform_Horizontal_GR> platformView =
            std::make_shared<representation::Platform_Horizontal_GR>(platformModel);

        platformModel->registerObserver(platformView);

        platformViews.push_back(std::move(platformView));

        return platformModel;
}

std::shared_ptr<logic::Platform> ConcreteFactory::createVerticalPlatform(float posX, float posY, float width,
                                                                         float height)
{

        std::shared_ptr<logic::Platform> platformModel =
            std::make_shared<logic::Platform_Vertical>(posX, posY, width, height);
        std::shared_ptr<representation::Platform_Vertical_GR> platformView =
            std::make_shared<representation::Platform_Vertical_GR>(platformModel);

        platformModel->registerObserver(platformView);

        platformViews.push_back(std::move(platformView));

        return platformModel;
}

std::shared_ptr<logic::Bonus> ConcreteFactory::createSpring(float posX, float posY, float width, float height)
{
        std::shared_ptr<logic::Bonus> bonusModel = std::make_shared<logic::Spring>(posX, posY, width, height);
        std::shared_ptr<representation::Spring_GR> bonusView = std::make_shared<representation::Spring_GR>(bonusModel);

        bonusModel->registerObserver(bonusView);

        bonusViews.push_back(std::move(bonusView));

        return bonusModel;
}

std::shared_ptr<logic::Bonus> ConcreteFactory::createJetpack(float posX, float posY, float width, float height)
{
        std::shared_ptr<logic::Bonus> bonusModel = std::make_shared<logic::Jetpack>(posX, posY, width, height);
        std::shared_ptr<representation::Jetpack_GR> bonusView =
            std::make_shared<representation::Jetpack_GR>(bonusModel);

        bonusModel->registerObserver(bonusView);

        bonusViews.push_back(std::move(bonusView));

        return bonusModel;
}

std::shared_ptr<logic::BGTile> ConcreteFactory::createBGTile(float posX, float posY, float width, float height)
{
        std::shared_ptr<logic::BGTile> bgModel = std::make_shared<logic::BGTile>(posX, posY, width, height);
        std::shared_ptr<representation::BGTile_GR> bgView = std::make_shared<representation::BGTile_GR>(bgModel);

        bgModel->registerObserver(bgView);

        bgTilesViews.push_back(std::move(bgView));

        return bgModel;
}

ConcreteFactory::ConcreteFactory() = default;
} // namespace representation