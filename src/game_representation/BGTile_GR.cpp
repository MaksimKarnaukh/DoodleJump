// Author: Maksim Karnaukh

#include "BGTile_GR.h"

namespace representation {

BGTile_GR::BGTile_GR(const std::shared_ptr<logic::EntityModel>& entityModel)
{

        mEntityModel = entityModel;
        setSpriteTexture("../assets/bg_tile.png");

        if (!mEntityModel.expired()) {
                std::shared_ptr<logic::EntityModel> p = mEntityModel.lock();
                setSpriteScale(p);
        }
}
} // namespace representation
