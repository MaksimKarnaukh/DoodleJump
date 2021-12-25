//
// Created by centu on 17/11/2021.
//

#include "BGTile_GR.h"

namespace representation {

    BGTile_GR::BGTile_GR(const std::shared_ptr<logic::EntityModel> &entityModel) {

        mEntityModel = entityModel;
        setSpriteTexture("assets/bg_tile.png");

        sprite.setScale(1*mEntityModel->getWidth()*(float)logic::utility::Camera::Instance().getWindowWidth()/(float)getTexture().getSize().x, 1*mEntityModel->getHeight()*(float)logic::utility::Camera::Instance().getWindowWidth()/(float)getTexture().getSize().x);
    }
}
