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

        this->setPositionX(this->getPositionX()-unit*logic::Stopwatch::Instance().getDeltaTime());

        notifyObservers();

    }

    void Player::moveRight() {

        this->setPositionX(this->getPositionX()+unit*logic::Stopwatch::Instance().getDeltaTime());

        notifyObservers();

    }

    void Player::jump() {

        this->setSpeed(jumpVelocity);
    }

    void Player::applyGravity() {

        this->setSpeed(this->getSpeed()+gravity*logic::Stopwatch::Instance().getDeltaTime()*32); // na elke tick de zwaartekracht meerekenen (aftrekken)
    }

    void Player::moveVertically() {

        this->setPositionY(this->getPositionY()+e_speed*logic::Stopwatch::Instance().getDeltaTime());

        notifyObservers();

    }

}

