// Author: Maksim Karnaukh

#include "Bonus.h"

namespace logic {

    Bonus::Bonus() = default;

    Bonus::Bonus(const float posX, const float posY) : EntityModel(posX, posY) {}

    Bonus::Bonus(const float posX, const float posY, const float width, const float height) : EntityModel(posX, posY, width, height) {}

    void Bonus::touchedBonus(std::shared_ptr<logic::Player>& player) {

        player->setSpeed(player->getJumpVelocity()*bonusForce); // Spring: doodle jumps with dy = 2.75 (5x larger than the normal jumpheight = 0.55)
                                                                      // Jetpack: doodle jumps with dy = 10.6
    }
}

