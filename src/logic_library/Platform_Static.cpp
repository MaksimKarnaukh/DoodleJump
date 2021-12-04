//
// Created by centu on 18/11/2021.
//

#include "Platform_Static.h"

namespace logic {

    Platform_Static::Platform_Static() = default;

    Platform_Static::Platform_Static(float posX, float posY, float width, float height) {

        this->setPositionX(posX);
        this->setPositionY(posY);

        this->setWidth(width);
        this->setHeight(height);
    }
}