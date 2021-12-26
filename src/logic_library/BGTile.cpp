

#include "BGTile.h"

namespace logic {

    BGTile::BGTile() = default;

    BGTile::BGTile(float posX, float posY) {

        this->setPositionX(posX);
        this->setPositionY(posY);
    }
}

