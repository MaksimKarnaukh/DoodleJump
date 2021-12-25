//
// Created by centu on 21/11/2021.
//

#include "Platform_Static_GR.h"

namespace representation {

    Platform_Static_GR::Platform_Static_GR(const std::shared_ptr<logic::EntityModel> &entityModel) {

        mEntityModel = entityModel;
        setSpriteTexture("assets/Platforms/static_panel.png");

        sprite.setScale(1*((float)logic::utility::Camera::Instance().getWindowWidth()*mEntityModel->getWidth())/(float)getTexture().getSize().x, 1*((float)logic::utility::Camera::Instance().getWindowHeight()*mEntityModel->getHeight())/(float)getTexture().getSize().y);

    }
}