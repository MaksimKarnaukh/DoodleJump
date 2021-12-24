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

        float startingX;
        float startingY;

    public:
        Platform_Vertical();

        Platform_Vertical(float posX, float posY);

        void move() override;
    };

}



#endif //DOODLEJUMP_PLATFORM_VERTICAL_H
