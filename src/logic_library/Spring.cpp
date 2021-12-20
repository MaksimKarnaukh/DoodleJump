//
// Created by centu on 19/12/2021.
//

#include "Spring.h"

namespace logic {

    Spring::Spring() = default;

    Spring::Spring(float posX, float posY) {

        this->setPositionX(posX);
        this->setPositionY(posY);

        this->setBonusForce(2.5f);
    }

}

