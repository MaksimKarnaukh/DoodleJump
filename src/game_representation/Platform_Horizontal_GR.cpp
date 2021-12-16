//
// Created by centu on 21/11/2021.
//

#include "Platform_Horizontal_GR.h"

namespace representation {

    Platform_Horizontal_GR::Platform_Horizontal_GR(const std::shared_ptr<logic::EntityModel> &entityModel) {

        mEntityModel = entityModel;
        setSpriteTexture("assets/Platforms/move_panel.png");

        sprite.setScale(1*(640*0.174004)/64, 1*(960*0.0411)/16);
    }
}