//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_PLATFORM_H
#define DOODLEJUMP_PLATFORM_H

#include "EntityModel.h"

namespace logic {

    class Platform: public logic::EntityModel {

    protected:

        float startingX; // starting x-position of our platform (top-left corner of entity)
        float startingY; // starting y-position of our platform (top-left corner of entity)

    public:

        /**
        * @function : Platform
        * Constructor for a Platform.
        */
        Platform();

        /**
        * @function : move
        * Function that is responsible for moving the platform correctly.
        */
        virtual void move() {};

        /**
        * @function : isTouched
        * Function that is used for the score decrease and temporary platform deletion.
        * @return (bool) : true if this object is of type Platform_Temporary, false otherwise.
        */
        virtual bool isTouched();

    };

}

#endif //DOODLEJUMP_PLATFORM_H
