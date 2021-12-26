

#include "Platform_Temporary.h"

namespace logic {

    Platform_Temporary::Platform_Temporary() = default;

    Platform_Temporary::Platform_Temporary(const float posX, const float posY) {

        this->setPositionX(posX);
        this->setPositionY(posY);
    }

    float Platform_Temporary::isTouched() {

        return 0;
    }
}