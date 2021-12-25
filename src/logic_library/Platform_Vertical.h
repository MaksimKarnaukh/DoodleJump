//
// Created by centu on 18/11/2021.
//

#ifndef DOODLEJUMP_PLATFORM_VERTICAL_H
#define DOODLEJUMP_PLATFORM_VERTICAL_H

#include "Platform.h"

namespace logic {

    class Platform_Vertical: public Platform {

        float unit = 0.1f; // unit of distance
        float moveUp = unit;
        float moveDown = -std::abs(unit);

    public:

        /**
        * @function : Platform_Vertical
        * Constructor for a Platform_Vertical.
        */
        Platform_Vertical();

        /**
        * @function : Platform_Vertical
        * Constructor for a Platform_Vertical.
        * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
        * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
        */
        Platform_Vertical(float posX, float posY);

        /**
        * @function : move
        * Function that is responsible for moving the platform correctly.
        */
        void move() override;
    };

}



#endif //DOODLEJUMP_PLATFORM_VERTICAL_H
