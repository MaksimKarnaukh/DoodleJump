//
// Created by centu on 18/11/2021.
//

#include "Platform_Temporary.h"

namespace logic {

    Platform_Temporary::Platform_Temporary() = default;

    Platform_Temporary::Platform_Temporary(float posX, float posY) {

        this->setPositionX(posX);
        this->setPositionY(posY);
    }

    bool Platform_Temporary::isTouched() {

        for (auto i = 0; i < observers.size(); i++) {
            removeObserver(observers[i]);
        }
        return true;
    }
}