//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_PLATFORM_H
#define DOODLEJUMP_PLATFORM_H

#include "EntityModel.h"

namespace logic {

    class Platform: public logic::EntityModel {

    public:

        Platform();

        virtual void move() {};

        virtual bool isTouched();

    };

}

#endif //DOODLEJUMP_PLATFORM_H
