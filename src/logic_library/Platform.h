

#ifndef DOODLEJUMP_PLATFORM_H
#define DOODLEJUMP_PLATFORM_H

#include "EntityModel.h"

namespace logic {

    class Platform: public logic::EntityModel {

    protected:

        float startingX; // starting x-position of our platform (top-left corner of entity)
        float startingY; // starting y-position of our platform (top-left corner of entity)

        int timesTouched = 0;

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
        * @return (float) : score decrease.
        */
        virtual float isTouched() = 0;

        int getTimesTouched() const {
            return timesTouched;
        }

    };

}

#endif //DOODLEJUMP_PLATFORM_H
