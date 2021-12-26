

#ifndef DOODLEJUMP_PLATFORM_VERTICAL_GR_H
#define DOODLEJUMP_PLATFORM_VERTICAL_GR_H

#include "Platform_GR.h"

namespace representation {

    class Platform_Vertical_GR: public Platform_GR {

    public:

        /**
        * @function : Platform_Vertical_GR
        * Constructor for a Platform_Vertical_GR.
        * @param entityModel (std::shared_ptr<logic::EntityModel>) : entityModel
        */
        Platform_Vertical_GR(const std::shared_ptr<logic::EntityModel> &entityModel);

    };

}



#endif //DOODLEJUMP_PLATFORM_VERTICAL_GR_H
