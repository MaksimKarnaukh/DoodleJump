// Author: Maksim Karnaukh

#include "Platform_Vertical_GR.h"

namespace representation {

    Platform_Vertical_GR::Platform_Vertical_GR(const std::shared_ptr<logic::EntityModel> &entityModel) {

        mEntityModel = entityModel;
        setSpriteTexture("../assets/Platforms/moveVertical_panel.png");

        if (! mEntityModel.expired()) {
            std::shared_ptr<logic::EntityModel> p = mEntityModel.lock();
            setSpriteScale(p);
        }

    }
}