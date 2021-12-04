//
// Created by centu on 21/11/2021.
//

#ifndef DOODLEJUMP_PLATFORM_STATIC_GR_H
#define DOODLEJUMP_PLATFORM_STATIC_GR_H

#include "Platform_GR.h"

namespace representation {

    class Platform_Static_GR: public Platform_GR {

    public:

        Platform_Static_GR(const std::shared_ptr<logic::Subject>& subject);

    };

}



#endif //DOODLEJUMP_PLATFORM_STATIC_GR_H
