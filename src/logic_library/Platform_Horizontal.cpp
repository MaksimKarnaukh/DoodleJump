//
// Created by centu on 18/11/2021.
//

#include "Platform_Horizontal.h"

namespace logic {

    Platform_Horizontal::Platform_Horizontal() = default;

    Platform_Horizontal::Platform_Horizontal(float posX, float posY) {

        this->setPositionX(posX);
        this->setPositionY(posY);
    }

    void Platform_Horizontal::move() {

        this->setPositionX(this->getPositionX()+unit*logic::Stopwatch::Instance().getDeltaTime());
        if (this->getPositionX() <= 0 || this->getPositionX()+this->getWidth() >= 1) {
            unit = -unit;
        }

        notifyObservers();
    }
}