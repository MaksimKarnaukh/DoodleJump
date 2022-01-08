// Author: Maksim Karnaukh

#ifndef DOODLEJUMP_PLATFORM_HORIZONTAL_H
#define DOODLEJUMP_PLATFORM_HORIZONTAL_H

#include "Platform.h"

namespace logic {

class Platform_Horizontal : public Platform
{

        float unit = 0.5f; // unit of distance
        float moveRight = unit;
        float moveLeft = -std::abs(unit);

public:
        /**
         * @function : Platform_Horizontal
         * Constructor for a Platform_Horizontal.
         */
        Platform_Horizontal();

        /**
         * @function : Platform_Horizontal
         * Destructor for a Platform_Horizontal.
         */
        ~Platform_Horizontal() override = default;

        /**
         * @function : Platform_Horizontal
         * Constructor for a Platform_Horizontal.
         * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
         * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
         */
        Platform_Horizontal(float posX, float posY);

        /**
         * @function : Platform_Horizontal
         * Constructor for a Platform_Horizontal.
         * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
         * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
         * @param width (float) : width of our entity.
         * @param height (float) : height of our entity.
         */
        Platform_Horizontal(float posX, float posY, float width, float height);

        /**
         * @function : move
         * Function that is responsible for moving the platform correctly.
         */
        void move() override;

        /**
         * @function : changeDirection
         * Changes the direction our platform is moving to.
         */
        void changeDirection() override;

        /**
         * @function : isTouched
         * Function that is used for the score decrease and temporary platform deletion.
         * @return (float) : score decrease.
         */
        float isTouched() override;
};

} // namespace logic

#endif // DOODLEJUMP_PLATFORM_HORIZONTAL_H
