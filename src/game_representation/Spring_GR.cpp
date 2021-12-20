//
// Created by centu on 19/12/2021.
//

#include "Spring_GR.h"

namespace representation {

    Spring_GR::Spring_GR(const std::shared_ptr<logic::EntityModel> &entityModel) {

        mEntityModel = entityModel;
        setSpriteTexture("assets/Bonus/spring.png");

        sprite.setScale(1*(640*0.174004/3)/17, 1*(960*0.0411)/14);

    }
}

