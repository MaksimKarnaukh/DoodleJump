

#include "Player_GR.h"

namespace representation {

    Player_GR::Player_GR(const std::shared_ptr<logic::EntityModel> &entityModel) {

        mEntityModel = entityModel;
        setSpriteTexture("../assets/DoodleJumper/doodle-pow.png");

        if (! mEntityModel.expired()) {
            std::shared_ptr<logic::EntityModel> p = mEntityModel.lock();
            setSpriteScale(p);
        }

    }
}