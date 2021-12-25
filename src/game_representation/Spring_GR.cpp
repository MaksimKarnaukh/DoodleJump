//
// Created by centu on 19/12/2021.
//

#include "Spring_GR.h"

namespace representation {

    Spring_GR::Spring_GR(const std::shared_ptr<logic::EntityModel> &entityModel) {

        mEntityModel = entityModel;
        setSpriteTexture("assets/Bonus/spring.png");

        sprite.setScale(1*((float)logic::utility::Camera::Instance().getWindowWidth()*mEntityModel->getWidth())/(float)getTexture().getSize().x, 1*((float)logic::utility::Camera::Instance().getWindowHeight()*mEntityModel->getHeight())/(float)getTexture().getSize().y);

    }
}

