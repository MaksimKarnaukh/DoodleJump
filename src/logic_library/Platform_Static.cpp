

#include "Platform_Static.h"

namespace logic {

    Platform_Static::Platform_Static() = default;

    Platform_Static::Platform_Static(const float posX, const float posY) {

        this->setPositionX(posX);
        this->setPositionY(posY);

    }

    float Platform_Static::isTouched() {
        timesTouched++;
        return 1;
    }
}