// Author: Maksim Karnaukh

#include "Jetpack_GR.h"

namespace representation {

    Jetpack_GR::Jetpack_GR(const std::shared_ptr<logic::EntityModel> &entityModel) {

        mEntityModel = entityModel;
        setSpriteTexture("../assets/Bonus/jetpack_on_panel.png");
        if (! mEntityModel.expired()) {
            std::shared_ptr<logic::EntityModel> p = mEntityModel.lock();
            setSpriteScale(p);
        }
    }
}

