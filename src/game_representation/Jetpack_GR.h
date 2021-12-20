//
// Created by centu on 19/12/2021.
//

#ifndef DOODLEJUMP_JETPACK_GR_H
#define DOODLEJUMP_JETPACK_GR_H

#include "Bonus_GR.h"

namespace representation {

    class Jetpack_GR: public representation::Bonus_GR {

    public:

        Jetpack_GR(const std::shared_ptr<logic::EntityModel> &entityModel);

    };

}



#endif //DOODLEJUMP_JETPACK_GR_H
