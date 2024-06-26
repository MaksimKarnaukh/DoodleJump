// Author: Maksim Karnaukh

#include "Player.h"

namespace logic {

Player::Player() = default;

Player::Player(float posX, float posY) : EntityModel(posX, posY) {}

Player::Player(float posX, float posY, float width, float height) : EntityModel(posX, posY, width, height) {}

void Player::moveLeft()
{

        this->setPositionX(this->getPositionX() - unit * logic::utility::Stopwatch::Instance().getDeltaTime());

        notifyObservers();
}

void Player::moveRight()
{

        this->setPositionX(this->getPositionX() + unit * logic::utility::Stopwatch::Instance().getDeltaTime());

        notifyObservers();
}

void Player::jump() { this->setSpeed(jumpVelocity); }

void Player::applyGravity()
{

        this->setSpeed(this->getSpeed() + gravity * logic::utility::Stopwatch::Instance().getDeltaTime());
}

void Player::moveVertically()
{

        this->setPositionY(this->getPositionY() + e_speed * logic::utility::Stopwatch::Instance().getDeltaTime());

        notifyObservers();
}

} // namespace logic
