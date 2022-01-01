// Author: Maksim Karnaukh

#ifndef DOODLEJUMP_BONUS_GR_H
#define DOODLEJUMP_BONUS_GR_H

#include "EntityView.h"

namespace representation {

    class Bonus_GR: public EntityView {

    public:

        /**
        * @function : Bonus_GR
        * Constructor for a Bonus_GR.
        */
        Bonus_GR();

        /**
        * @function : Bonus_GR
        * Destructor for a Bonus_GR.
        */
        ~Bonus_GR() override = default;

    };

}



#endif //DOODLEJUMP_BONUS_GR_H
