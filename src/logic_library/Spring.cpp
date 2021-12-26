

#include "Spring.h"

namespace logic {

    Spring::Spring() = default;

    Spring::Spring(float posX, float posY) {

        this->setPositionX(posX);
        this->setPositionY(posY);

        this->setBonusForce(2.5f);
    }

}

