// Author: Maksim Karnaukh

#include "Platform_Temporary_GR.h"

namespace representation {

    Platform_Temporary_GR::Platform_Temporary_GR(const std::shared_ptr<logic::EntityModel> &entityModel) {

        mEntityModel = entityModel;
        setSpriteTexture("../assets/Platforms/temp_panel.png");

        if (! mEntityModel.expired()) {
            std::shared_ptr<logic::EntityModel> p = mEntityModel.lock();
            setSpriteScale(p);
        }

    }
}