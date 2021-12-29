

#include "Platform_Static_GR.h"

namespace representation {

    Platform_Static_GR::Platform_Static_GR(const std::shared_ptr<logic::EntityModel> &entityModel) {

        mEntityModel = entityModel;
        setSpriteTexture("../assets/Platforms/static_panel.png");

        if (! mEntityModel.expired()) {
            std::shared_ptr<logic::EntityModel> p = mEntityModel.lock();
            setSpriteScale(p);
        }

    }
}