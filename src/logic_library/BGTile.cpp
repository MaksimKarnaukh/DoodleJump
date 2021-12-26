

#include "BGTile.h"

namespace logic {

    BGTile::BGTile() = default;

    BGTile::BGTile(const float posX, const float posY) {

        this->setPositionX(posX);
        this->setPositionY(posY);
    }
}

