// Author: Maksim Karnaukh

#include "Spring_GR.h"

namespace representation {

Spring_GR::Spring_GR(const std::shared_ptr<logic::EntityModel>& entityModel)
{

        mEntityModel = entityModel;
        setSpriteTexture("../assets/Bonus/spring.png");

        if (!mEntityModel.expired()) {
                std::shared_ptr<logic::EntityModel> p = mEntityModel.lock();
                setSpriteScale(p);
        }
}
} // namespace representation
