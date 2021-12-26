

#include "Player_GR.h"

namespace representation {

    Player_GR::Player_GR(const std::shared_ptr<logic::EntityModel> &entityModel) {

        mEntityModel = entityModel;
        setSpriteTexture("assets/DoodleJumper/doodle-pow.png");

        sprite.setScale(1*((float)logic::utility::Camera::Instance().getWindowWidth()*mEntityModel->getWidth())/(float)getTexture().getSize().x, 1*((float)logic::utility::Camera::Instance().getWindowHeight()*mEntityModel->getHeight())/(float)getTexture().getSize().y);

    }
}