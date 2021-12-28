

#ifndef DOODLEJUMP_JETPACK_GR_H
#define DOODLEJUMP_JETPACK_GR_H

#include "Bonus_GR.h"

namespace representation {

    class Jetpack_GR: public representation::Bonus_GR {

    public:

        /**
        * @function : Jetpack_GR
        * Constructor for a Jetpack_GR.
        * @param entityModel (std::shared_ptr<logic::EntityModel>) : entityModel
        */
        Jetpack_GR(const std::shared_ptr<logic::EntityModel> &entityModel);

        /**
        * @function : Jetpack_GR
        * Destructor for a Jetpack_GR.
        */
        ~Jetpack_GR() override = default;

    };

}



#endif //DOODLEJUMP_JETPACK_GR_H
