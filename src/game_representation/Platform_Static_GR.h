//
// Created by centu on 21/11/2021.
//

#ifndef DOODLEJUMP_PLATFORM_STATIC_GR_H
#define DOODLEJUMP_PLATFORM_STATIC_GR_H

#include "Platform_GR.h"

namespace representation {

    class Platform_Static_GR: public Platform_GR {

    public:

        /**
        * @function : Platform_Static_GR
        * Constructor for a Platform_Static_GR.
        * @param entityModel (std::shared_ptr<logic::EntityModel>) : entityModel
        */
        Platform_Static_GR(const std::shared_ptr<logic::EntityModel> &entityModel);

    };

}



#endif //DOODLEJUMP_PLATFORM_STATIC_GR_H
