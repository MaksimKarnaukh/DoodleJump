

#include "Jetpack.h"

namespace logic {

    Jetpack::Jetpack() = default;

    Jetpack::Jetpack(const float posX, const float posY) {
        this->setPositionX(posX);
        this->setPositionY(posY);

        this->setBonusForce(5.0f);
        this->setScoreIncrease(4);
    }

}

