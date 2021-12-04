//
// Created by centu on 21/11/2021.
//

#include "Platform_Static_GR.h"

namespace representation {

    Platform_Static_GR::Platform_Static_GR(const std::shared_ptr<logic::Subject>& subject) {

        mSubject = subject;
        setSpriteTexture("assets/Platforms/static_panel.png");

    }
}