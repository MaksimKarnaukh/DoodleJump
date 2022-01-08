// Author: Maksim Karnaukh

#include "Platform_Horizontal_GR.h"

namespace representation {

Platform_Horizontal_GR::Platform_Horizontal_GR(const std::shared_ptr<logic::EntityModel>& entityModel)
{

        mEntityModel = entityModel;
        setSpriteTexture("../assets/Platforms/move_panel.png");

        if (!mEntityModel.expired()) {
                std::shared_ptr<logic::EntityModel> p = mEntityModel.lock();
                setSpriteScale(p);
        }
}
} // namespace representation