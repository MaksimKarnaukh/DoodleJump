// Author: Maksim Karnaukh

#ifndef DOODLEJUMP_PLATFORM_H
#define DOODLEJUMP_PLATFORM_H

#include "EntityModel.h"

namespace logic {

class Platform : public logic::EntityModel
{

protected:
        float startingX; // starting x-position of our platform (top-left corner of entity)
        float startingY; // starting y-position of our platform (top-left corner of entity)

        int timesTouched = 0;

public:
        /**
         * @function : Platform
         * Constructor for a Platform.
         */
        Platform();

        /**
         * @function : Platform
         * Destructor for a Platform.
         */
        ~Platform() override = default;

        /**
         * @function : Platform
         * Constructor for a Platform.
         * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
         * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
         */
        Platform(float posX, float posY);

        /**
         * @function : Platform
         * Constructor for a Platform.
         * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
         * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
         * @param width (float) : width of our entity.
         * @param height (float) : height of our entity.
         */
        Platform(float posX, float posY, float width, float height);

        /**
         * @function : move
         * Function that is responsible for moving the platform correctly.
         */
        virtual void move(){};

        /**
         * @function : changeDirection
         * Changes the direction our platform is moving to.
         */
        virtual void changeDirection(){};

        /**
         * @function : isTouched
         * Function that is used for the score decrease and temporary platform deletion.
         * @return (float) : score decrease.
         */
        virtual float isTouched() = 0;

        int getTimesTouched() const { return timesTouched; }
};

} // namespace logic

#endif // DOODLEJUMP_PLATFORM_H
