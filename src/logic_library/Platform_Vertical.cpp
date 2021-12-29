


#include "Platform_Vertical.h"

logic::Platform_Vertical::Platform_Vertical() = default;

logic::Platform_Vertical::Platform_Vertical(const float posX, const float posY) : Platform(posX, posY) {

    this->startingX = posX;
    this->startingY = posY;
}

logic::Platform_Vertical::Platform_Vertical(const float posX, const float posY, const float width, const float height) : Platform(posX, posY, width, height) {

    this->startingX = posX;
    this->startingY = posY;
}

void logic::Platform_Vertical::move() {

    this->setPositionY(this->getPositionY()+unit*logic::utility::Stopwatch::Instance().getDeltaTime());

    if (this->getPositionY() <= this->startingY-0.2) { // we do the checking this way, because putting both if statements together and setting unit=-unit can cause problems at the relative borders.
        unit = moveUp;
    }
    if (this->getPositionY() >= this->startingY+0.2) {
        unit = moveDown;
    }

    notifyObservers();

}

float logic::Platform_Vertical::isTouched() {
    timesTouched++;
    return 0.7;
}

