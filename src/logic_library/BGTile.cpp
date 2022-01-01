// Author: Maksim Karnaukh

#include "BGTile.h"

namespace logic {

    BGTile::BGTile() = default;

    BGTile::BGTile(const float posX, const float posY) : EntityModel(posX, posY) {}

    BGTile::BGTile(const float posX, const float posY, const float width, const float height) : EntityModel(posX, posY, width, height) {}

}

