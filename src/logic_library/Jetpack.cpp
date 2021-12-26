

#include "Jetpack.h"

namespace logic {

    Jetpack::Jetpack() = default;

    Jetpack::Jetpack(float posX, float posY) {
        this->setPositionX(posX);
        this->setPositionY(posY);

        this->setBonusForce(5.0f);
    }

}

