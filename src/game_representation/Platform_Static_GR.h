// Author: Maksim Karnaukh

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

        /**
        * @function : Platform_Static_GR
        * Destructor for a Platform_Static_GR.
        */
        ~Platform_Static_GR() override = default;

    };

}



#endif //DOODLEJUMP_PLATFORM_STATIC_GR_H
