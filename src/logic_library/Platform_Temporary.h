// Author: Maksim Karnaukh

#ifndef DOODLEJUMP_PLATFORM_TEMPORARY_H
#define DOODLEJUMP_PLATFORM_TEMPORARY_H

#include "Platform.h"

namespace logic {

class Platform_Temporary : public Platform
{

public:
        /**
         * @function : Platform_Temporary
         * Constructor for a Platform_Temporary.
         */
        Platform_Temporary();

        /**
         * @function : Platform_Temporary
         * Destructor for a Platform_Temporary.
         */
        ~Platform_Temporary() override = default;

        /**
         * @function : Platform_Temporary
         * Constructor for a Platform_Temporary.
         * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
         * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
         */
        Platform_Temporary(float posX, float posY);

        /**
         * @function : Platform_Temporary
         * Constructor for a Platform_Temporary.
         * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
         * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
         * @param width (float) : width of our entity.
         * @param height (float) : height of our entity.
         */
        Platform_Temporary(float posX, float posY, float width, float height);

        /**
         * @function : isTouched
         * Function that is used for the score decrease and temporary platform deletion.
         * @return (float) : score decrease.
         */
        float isTouched() override;
};

} // namespace logic

#endif // DOODLEJUMP_PLATFORM_TEMPORARY_H
