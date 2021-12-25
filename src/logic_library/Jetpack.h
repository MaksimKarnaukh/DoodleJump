//
// Created by centu on 19/12/2021.
//

#ifndef DOODLEJUMP_JETPACK_H
#define DOODLEJUMP_JETPACK_H

#include "Bonus.h"

namespace logic {

    class Jetpack: public logic::Bonus {

    public:

        /**
        * @function : Jetpack
        * Constructor for a Jetpack.
        */
        Jetpack();

        /**
        * @function : Jetpack
        * Constructor for a Jetpack.
        */
        Jetpack(float posX, float posY);

//        float getBonusForce() const override {
//            return bonusForce;
//        }

    };

}



#endif //DOODLEJUMP_JETPACK_H
