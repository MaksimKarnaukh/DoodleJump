//
// Created by centu on 17/11/2021.
//

#include "Player_GR.h"

namespace representation {

    Player_GR::Player_GR(const std::shared_ptr<logic::Subject>& subject) {

        mSubject = subject;
        setSpriteTexture("assets/DoodleJumper/doodle-right.png");
        sprite.setScale(0.25, 0.25);

    }
}