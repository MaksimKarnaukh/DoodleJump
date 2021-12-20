//
// Created by centu on 19/12/2021.
//

#include "Jetpack_GR.h"

namespace representation {

    Jetpack_GR::Jetpack_GR(const std::shared_ptr<logic::EntityModel> &entityModel) {

        mEntityModel = entityModel;
        setSpriteTexture("assets/Bonus/jetpack_on_panel.png");

        sprite.setScale(1*(640*0.0696)/26, 1*(960*0.06576)/38);

    }
}

