

#ifndef DOODLEJUMP_PLATFORM_GR_H
#define DOODLEJUMP_PLATFORM_GR_H

#include "EntityView.h"

namespace representation {

    class Platform_GR: public EntityView {

    public:

        /**
        * @function : Platform_GR
        * Constructor for a Platform_GR.
        */
        Platform_GR();

        /**
        * @function : Platform_GR
        * Destructor for a Platform_GR.
        */
        ~Platform_GR() override = default;

    };

}




#endif //DOODLEJUMP_PLATFORM_GR_H
