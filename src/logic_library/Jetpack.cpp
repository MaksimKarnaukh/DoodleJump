// Author: Maksim Karnaukh

#include "Jetpack.h"

namespace logic {

    Jetpack::Jetpack() = default;

    Jetpack::Jetpack(const float posX, const float posY) : Bonus(posX, posY) {

        this->setBonusForce(5.0f);
        this->setScoreIncrease(4);
    }

    Jetpack::Jetpack(const float posX, const float posY, const float width, const float height) : Bonus(posX, posY, width, height) {

        this->setBonusForce(5.0f);
        this->setScoreIncrease(4);
    }

}

