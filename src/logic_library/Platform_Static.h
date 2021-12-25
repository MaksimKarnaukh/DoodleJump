//
// Created by centu on 18/11/2021.
//

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
        * Constructor for a Platform_Static.
        * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
        * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
        */
        Platform_Static(float posX, float posY);

    };

}



#endif //DOODLEJUMP_PLATFORM_STATIC_H
