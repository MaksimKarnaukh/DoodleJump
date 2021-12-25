//
// Created by centu on 21/11/2021.
//

#include "Platform_Temporary_GR.h"

namespace representation {

    Platform_Temporary_GR::Platform_Temporary_GR(const std::shared_ptr<logic::EntityModel> &entityModel) {

        mEntityModel = entityModel;
        setSpriteTexture("assets/Platforms/temp_panel.png");

        sprite.setScale(1*((float)logic::utility::Camera::Instance().getWindowWidth()*mEntityModel->getWidth())/(float)getTexture().getSize().x, 1*((float)logic::utility::Camera::Instance().getWindowHeight()*mEntityModel->getHeight())/(float)getTexture().getSize().y);
    }
}