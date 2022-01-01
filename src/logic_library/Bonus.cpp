// Author: Maksim Karnaukh

#include "Bonus.h"

namespace logic {

    Bonus::Bonus() = default;

    Bonus::Bonus(const float posX, const float posY) : EntityModel(posX, posY) {}

    Bonus::Bonus(const float posX, const float posY, const float width, const float height) : EntityModel(posX, posY, width, height) {}
}

