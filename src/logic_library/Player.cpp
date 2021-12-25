//
// Created by centu on 17/11/2021.
//

#include "Player.h"

namespace logic {

    Player::Player() = default;

    Player::Player(float posX, float posY) {
        this->setPositionX(posX);
        this->setPositionY(posY);

//        this->setWidth(0.077f);
//        this->setHeight(0.128f);
    }

    void Player::moveLeft() {

        this->setPositionX(this->getPositionX()-unit*logic::utility::Stopwatch::Instance().getDeltaTime());

        notifyObservers();

    }

    void Player::moveRight() {

        this->setPositionX(this->getPositionX()+unit*logic::utility::Stopwatch::Instance().getDeltaTime());

        notifyObservers();

    }

    void Player::jump() {

        this->setSpeed(jumpVelocity);
    }

    void Player::applyGravity() {

        this->setSpeed(this->getSpeed()+gravity*logic::utility::Stopwatch::Instance().getDeltaTime()); // na elke tick de zwaartekracht meerekenen (aftrekken)
    }

    void Player::moveVertically() {

        this->setPositionY(this->getPositionY()+e_speed*logic::utility::Stopwatch::Instance().getDeltaTime());

        notifyObservers();

    }

    void Player::touchedBonus(float bonusForce) {

        this->setSpeed(jumpVelocity*bonusForce); // Spring: doodle jumps with dy = 2.75 (5x larger than the normal jumpheight = 0.55)
                                                       // Jetpack: doodle jumps with dy = 10.6

    }

}

