//
// Created by centu on 19/12/2021.
//

#ifndef DOODLEJUMP_SPRING_GR_H
#define DOODLEJUMP_SPRING_GR_H

#include "Bonus_GR.h"

namespace representation {

    class Spring_GR: public representation::Bonus_GR {

    public:

        /**
        * @function : Spring_GR
        * Constructor for a Spring_GR.
        * @param entityModel (std::shared_ptr<logic::EntityModel>) : entityModel
        */
        Spring_GR(const std::shared_ptr<logic::EntityModel> &entityModel);
    };

}



#endif //DOODLEJUMP_SPRING_GR_H
