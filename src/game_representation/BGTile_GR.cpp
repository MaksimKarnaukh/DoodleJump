//
// Created by centu on 17/11/2021.
//

#include "BGTile_GR.h"

namespace representation {

    BGTile_GR::BGTile_GR(const std::shared_ptr<logic::EntityModel> &entityModel) {

        mEntityModel = entityModel;
        setSpriteTexture("assets/bg_tile.png");

        sprite.setScale(1*0.05*640/18, 1*0.05*640/18);
    }
}
