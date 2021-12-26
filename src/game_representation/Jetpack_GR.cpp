

#include "Jetpack_GR.h"

namespace representation {

    Jetpack_GR::Jetpack_GR(const std::shared_ptr<logic::EntityModel> &entityModel) {

        mEntityModel = entityModel;
        setSpriteTexture("assets/Bonus/jetpack_on_panel.png");
        sprite.setScale(1*((float)logic::utility::Camera::Instance().getWindowWidth()*mEntityModel->getWidth())/(float)getTexture().getSize().x, 1*((float)logic::utility::Camera::Instance().getWindowHeight()*mEntityModel->getHeight())/(float)getTexture().getSize().y);

    }
}

