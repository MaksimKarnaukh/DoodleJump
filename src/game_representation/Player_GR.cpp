//
// Created by centu on 17/11/2021.
//

#include "Player_GR.h"

namespace representation {

    Player_GR::Player_GR(const std::shared_ptr<logic::Subject>& subject) {

        mSubject = subject;
        setSpriteTexture("assets/DoodleJumper/doodle-pow.png");

        sprite.setScale(1*0.077*640/236, 1*0.18*960/447);

    }
}