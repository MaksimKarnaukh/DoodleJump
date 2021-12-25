//
// Created by centu on 18/11/2021.
//

#ifndef DOODLEJUMP_PLATFORM_HORIZONTAL_H
#define DOODLEJUMP_PLATFORM_HORIZONTAL_H

#include "Platform.h"

namespace logic {

    class Platform_Horizontal: public Platform {

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
        * Constructor for a Platform_Horizontal.
        * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
        * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
        */
        Platform_Horizontal(float posX, float posY);

        /**
        * @function : move
        * Function that is responsible for moving the platform correctly.
        */
        void move() override;

    };

}



#endif //DOODLEJUMP_PLATFORM_HORIZONTAL_H
