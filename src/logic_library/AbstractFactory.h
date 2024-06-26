// Author: Maksim Karnaukh

#ifndef DOODLEJUMP_ABSTRACTFACTORY_H
#define DOODLEJUMP_ABSTRACTFACTORY_H

#include "BGTile.h"
#include "Jetpack.h"
#include "Observer.h"
#include "Platform_Horizontal.h"
#include "Platform_Static.h"
#include "Platform_Temporary.h"
#include "Platform_Vertical.h"
#include "Player.h"
#include "Score.h"
#include "Spring.h"

namespace logic {

class AbstractFactory
{

public:
        /**
         * @function : AbstractFactory
         * Constructor for a AbstractFactory.
         */
        AbstractFactory();

        /**
         * @function : AbstractFactory
         * Destructor for an AbstractFactory.
         */
        virtual ~AbstractFactory() = default;

        /**
         * @function : createPlayer
         * This function is responsible for creating the doodle.
         * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
         * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
         * @param width (float) : width of our entity (in logic units).
         * @param height (float) : height of our entity (in logic units).
         */
        virtual std::shared_ptr<logic::Player> createPlayer(float posX, float posY, float width, float height) = 0;

        /**
         * @function : createStaticPlatform
         * This function is responsible for creating the static platform.
         * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
         * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
         * @param width (float) : width of our entity (in logic units).
         * @param height (float) : height of our entity (in logic units).
         */
        virtual std::shared_ptr<logic::Platform> createStaticPlatform(float posX, float posY, float width,
                                                                      float height) = 0;

        /**
         * @function : createTemporaryPlatform
         * This function is responsible for creating the temporary platform.
         * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
         * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
         * @param width (float) : width of our entity (in logic units).
         * @param height (float) : height of our entity (in logic units).
         */
        virtual std::shared_ptr<logic::Platform> createTemporaryPlatform(float posX, float posY, float width,
                                                                         float height) = 0;

        /**
         * @function : createHorizontalPlatform
         * This function is responsible for creating the horizontal platform.
         * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
         * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
         * @param width (float) : width of our entity (in logic units).
         * @param height (float) : height of our entity (in logic units).
         */
        virtual std::shared_ptr<logic::Platform> createHorizontalPlatform(float posX, float posY, float width,
                                                                          float height) = 0;

        /**
         * @function : createVerticalPlatform
         * This function is responsible for creating the vertical platform.
         * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
         * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
         * @param width (float) : width of our entity (in logic units).
         * @param height (float) : height of our entity (in logic units).
         */
        virtual std::shared_ptr<logic::Platform> createVerticalPlatform(float posX, float posY, float width,
                                                                        float height) = 0;

        /**
         * @function : createSpring
         * This function is responsible for creating the spring bonus.
         * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
         * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
         * @param width (float) : width of our entity (in logic units).
         * @param height (float) : height of our entity (in logic units).
         */
        virtual std::shared_ptr<logic::Bonus> createSpring(float posX, float posY, float width, float height) = 0;

        /**
         * @function : createJetpack
         * This function is responsible for creating the jetpack bonus.
         * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
         * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
         * @param width (float) : width of our entity (in logic units).
         * @param height (float) : height of our entity (in logic units).
         */
        virtual std::shared_ptr<logic::Bonus> createJetpack(float posX, float posY, float width, float height) = 0;

        /**
         * @function : createBGTile
         * This function is responsible for creating the background tile (little square).
         * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
         * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
         * @param width (float) : width of our entity (in logic units).
         * @param height (float) : height of our entity (in logic units).
         */
        virtual std::shared_ptr<logic::BGTile> createBGTile(float posX, float posY, float width, float height) = 0;
};

} // namespace logic

#endif // DOODLEJUMP_ABSTRACTFACTORY_H
