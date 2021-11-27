//
// Created by centu on 17/11/2021.
//

#include "Player.h"

namespace logic {

    Player::Player() {

        this->setPositionX(0.5);
        this->setPositionY(0.5);

    }

    void Player::moveLeft() {

        this->setPositionX(this->getPositionX()-unit*logic::Stopwatch::Instance()->getDeltaTime());

        if((this->getPositionX() < 0)){ // links buiten window
            this->setPositionX(1 - e_width); // we zetten onze doodle aan de rechterkant
        }

    }

    void Player::moveRight() {

        this->setPositionX(this->getPositionX()+unit*logic::Stopwatch::Instance()->getDeltaTime());

        if((this->getPositionX() > 1 - e_width)){ // rechts buiten window
            this->setPositionX(0); // we zetten onze doodle aan de linkerkant
        }

    }

    void Player::jump() {

        e_speed = 10; // we zullen zeggen dat de zwaartekracht -20 units/s is. (In de doodle jump game online wordt een sprong gedurende ongeveer 0.5s naar boven uitgevoerd.)

        this->setPositionY(this->getPositionY()+e_speed*logic::Stopwatch::Instance()->getDeltaTime());

    }

}

