

#ifndef DOODLEJUMP_PLATFORM_STATIC_H
#define DOODLEJUMP_PLATFORM_STATIC_H

#include "Platform.h"

namespace logic {

    class Platform_Static: public Platform {

    public:

        /**
        * @function : Platform_Static
        * Constructor for a Platform_Static.
        */
        Platform_Static();

        /**
        * @function : Platform_Static
        * Destructor for a Platform_Static.
        */
        ~Platform_Static() override = default;

        /**
        * @function : Platform_Static
        * Constructor for a Platform_Static.
        * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
        * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
        */
        Platform_Static(float posX, float posY);

        /**
        * @function : Platform_Static
        * Constructor for a Platform_Static.
        * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
        * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
        * @param width (float) : width of our entity.
        * @param height (float) : height of our entity.
        */
        Platform_Static(float posX, float posY, float width, float height);

        /**
        * @function : isTouched
        * Function that is used for the score decrease and temporary platform deletion.
        * @return (float) : score decrease.
        */
        float isTouched() override;

    };

}



#endif //DOODLEJUMP_PLATFORM_STATIC_H
