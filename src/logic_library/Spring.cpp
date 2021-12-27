

#include "Spring.h"

namespace logic {

    Spring::Spring() = default;

    Spring::Spring(const float posX, const float posY) : Bonus(posX, posY) {

        this->setBonusForce(2.5f);
        this->setScoreIncrease(2);
    }

    Spring::Spring(const float posX, const float posY, const float width, const float height) : Bonus(posX, posY, width, height) {

        this->setBonusForce(2.5f);
        this->setScoreIncrease(2);
    }

}

