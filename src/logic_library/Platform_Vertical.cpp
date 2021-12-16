//
// Created by centu on 18/11/2021.
//

#include "Platform_Vertical.h"

logic::Platform_Vertical::Platform_Vertical() = default;

logic::Platform_Vertical::Platform_Vertical(float posX, float posY) {

    this->setPositionX(posX);
    this->setPositionY(posY);

    this->startingX = posX;
    this->startingY = posY;
}

void logic::Platform_Vertical::move() {

    this->setPositionY(this->getPositionY()+unit*logic::Stopwatch::Instance().getDeltaTime());
    if (this->getPositionY() <= this->startingY-0.2 || this->getPositionY() >= this->startingY+0.2) {
        unit = -unit;
    }

    notifyObservers();

}
