//
// Created by centu on 21/11/2021.
//

#ifndef DOODLEJUMP_PLATFORM_HORIZONTAL_GR_H
#define DOODLEJUMP_PLATFORM_HORIZONTAL_GR_H

#include "Platform_GR.h"

namespace representation {

    class Platform_Horizontal_GR: public Platform_GR {

    public:

        /**
        * @function : Platform_Horizontal_GR
        * Constructor for a Platform_Horizontal_GR.
        * @param entityModel (std::shared_ptr<logic::EntityModel>) : entityModel
        */
        Platform_Horizontal_GR(const std::shared_ptr<logic::EntityModel> &entityModel);

    };

}



#endif //DOODLEJUMP_PLATFORM_HORIZONTAL_GR_H
