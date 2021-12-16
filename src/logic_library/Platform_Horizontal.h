//
// Created by centu on 18/11/2021.
//

#ifndef DOODLEJUMP_PLATFORM_HORIZONTAL_H
#define DOODLEJUMP_PLATFORM_HORIZONTAL_H

#include "Platform.h"

namespace logic {

    class Platform_Horizontal: public Platform {

        float unit = 0.5f; // unit of distance

    public:
        Platform_Horizontal();

        Platform_Horizontal(float posX, float posY);

        void move() override;

    };

}



#endif //DOODLEJUMP_PLATFORM_HORIZONTAL_H
