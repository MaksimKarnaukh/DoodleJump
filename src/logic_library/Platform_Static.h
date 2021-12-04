//
// Created by centu on 18/11/2021.
//

#ifndef DOODLEJUMP_PLATFORM_STATIC_H
#define DOODLEJUMP_PLATFORM_STATIC_H

#include "Platform.h"

namespace logic {

    class Platform_Static: public Platform {

    public:

        Platform_Static();

        Platform_Static(float posX, float posY, float width, float height);
    };

}



#endif //DOODLEJUMP_PLATFORM_STATIC_H
