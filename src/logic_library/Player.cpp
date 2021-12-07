//
// Created by centu on 17/11/2021.
//

#include "Player.h"

namespace logic {

    Player::Player() = default;

    Player::Player(float posX, float posY, float width, float height) {
        this->setPositionX(posX);
        this->setPositionY(posY);

        this->setWidth(width);
        this->setHeight(height);
    }

    void Player::moveLeft() {

        this->setPositionX(this->getPositionX()-unit*logic::Stopwatch::Instance()->getDeltaTime());

        notifyObservers();
    }

    void Player::moveRight() {

        this->setPositionX(this->getPositionX()+unit*logic::Stopwatch::Instance()->getDeltaTime());

        notifyObservers();
    }

    void Player::jump() {

        this->setSpeed(jumpVelocity);
    }

    void Player::applyGravity() {

        // - wordt +, want (0,0) is links bovenaan, en naar beneden gaan betekent vergroten.
        this->setSpeed(this->getSpeed()+gravity); // na elke tick de zwaartekracht meerekenen (aftrekken)
    }

    void Player::moveVertically() {

        this->setPositionY(this->getPositionY()+e_speed*logic::Stopwatch::Instance()->getDeltaTime());

        notifyObservers();

        setPreviousPositionX(getPositionX());
        setPreviousPositionY(getPositionY());
    }

}

