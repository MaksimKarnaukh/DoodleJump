

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

        /**
        * @function : Platform_Horizontal_GR
        * Destructor for a Platform_Horizontal_GR.
        */
        ~Platform_Horizontal_GR() override = default;

    };

}



#endif //DOODLEJUMP_PLATFORM_HORIZONTAL_GR_H
