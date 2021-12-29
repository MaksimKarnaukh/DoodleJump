

#ifndef DOODLEJUMP_CONCRETEFACTORY_H
#define DOODLEJUMP_CONCRETEFACTORY_H

#include "../logic_library/AbstractFactory.h"
#include "Player_GR.h"
#include "Platform_Static_GR.h"
#include "Platform_Horizontal_GR.h"
#include "Platform_Temporary_GR.h"
#include "Platform_Vertical_GR.h"
#include "BGTile_GR.h"
#include "Jetpack_GR.h"
#include "Spring_GR.h"
#include "Window.h"

namespace representation {

    class ConcreteFactory: public logic::AbstractFactory {
    public:
        std::vector<std::shared_ptr<representation::Platform_GR>> platformViews;
        std::vector<std::shared_ptr<representation::Player_GR>> playerViews;
        std::vector<std::shared_ptr<representation::Bonus_GR>> bonusViews;
        std::vector<std::shared_ptr<representation::BGTile_GR>> bgTilesViews;


    public:

        /**
        * @function : ConcreteFactory
        * Constructor for a ConcreteFactory.
        */
        ConcreteFactory();

        /**
        * @function : ConcreteFactory
        * Destructor for a ConcreteFactory.
        */
        ~ConcreteFactory() override = default;

        /**
        * @function : createPlayer
        * Creates and returns a player model.
        * @param posX (float) : x-position of the entity.
        * @param posY (float) : y-position of the entity.
        * @param width (float) : width of the entity.
        * @param height (float) : height of the entity.
        * @return (std::shared_ptr<logic::Player>) : player model.
        */
        std::shared_ptr<logic::Player> createPlayer(float posX, float posY, float width, float height) override;


        /**
        * @function : createStaticPlatform
        * Creates and returns a (static) platform model.
        * @param posX (float) : x-position of the entity.
        * @param posY (float) : y-position of the entity.
        * @param width (float) : width of the entity.
        * @param height (float) : height of the entity.
        * @return (std::shared_ptr<logic::Platform) : platform model.
        */
        std::shared_ptr<logic::Platform> createStaticPlatform(float posX, float posY, float width, float height) override;

        /**
        * @function : createTemporaryPlatform
        * Creates and returns a (temporary) platform model.
        * @param posX (float) : x-position of the entity.
        * @param posY (float) : y-position of the entity.
        * @param width (float) : width of the entity.
        * @param height (float) : height of the entity.
        * @return (std::shared_ptr<logic::Platform>) : platform model.
        */
        std::shared_ptr<logic::Platform> createTemporaryPlatform(float posX, float posY, float width, float height) override;

        /**
        * @function : createHorizontalPlatform
        * Creates and returns a (horizontal) platform model.
        * @param posX (float) : x-position of the entity.
        * @param posY (float) : y-position of the entity.
        * @param width (float) : width of the entity.
        * @param height (float) : height of the entity.
        * @return (std::shared_ptr<logic::Platform>) : platform model.
        */
        std::shared_ptr<logic::Platform> createHorizontalPlatform(float posX, float posY, float width, float height) override;

        /**
        * @function : createVerticalPlatform
        * Creates and returns a (vertical) platform model.
        * @param posX (float) : x-position of the entity.
        * @param posY (float) : y-position of the entity.
        * @param width (float) : width of the entity.
        * @param height (float) : height of the entity.
        * @return (std::shared_ptr<logic::Platform>) : platform model.
        */
        std::shared_ptr<logic::Platform> createVerticalPlatform(float posX, float posY, float width, float height) override;


        /**
        * @function : createSpring
        * Creates and returns a spring model.
        * @param posX (float) : x-position of the entity.
        * @param posY (float) : y-position of the entity.
        * @param width (float) : width of the entity.
        * @param height (float) : height of the entity.
        * @return (std::shared_ptr<logic::Bonus>) : bonus model.
        */
        std::shared_ptr<logic::Bonus> createSpring(float posX, float posY, float width, float height) override;

        /**
        * @function : createJetpack
        * Creates and returns a jetpack model.
        * @param posX (float) : x-position of the entity.
        * @param posY (float) : y-position of the entity.
        * @param width (float) : width of the entity.
        * @param height (float) : height of the entity.
        * @return (std::shared_ptr<logic::Bonus>) : bonus model.
        */
        std::shared_ptr<logic::Bonus> createJetpack(float posX, float posY, float width, float height) override;


        /**
        * @function : createBGTile
        * Creates and returns a background tile model.
        * @param posX (float) : x-position of the entity.
        * @param posY (float) : y-position of the entity.
        * @param width (float) : width of the entity.
        * @param height (float) : height of the entity.
        * @return (std::shared_ptr<logic::BGTile>) : background tile model.
        */
        std::shared_ptr<logic::BGTile> createBGTile(float posX, float posY, float width, float height) override;

    };

}

#endif //DOODLEJUMP_CONCRETEFACTORY_H
