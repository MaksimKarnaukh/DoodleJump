

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
        * Destructor for a Jetpack.
        */
        ~Jetpack() override = default;

        /**
        * @function : Jetpack
        * Constructor for a Jetpack.
        * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
        * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
        */
        Jetpack(float posX, float posY);

        /**
        * @function : Jetpack
        * Constructor for a Jetpack.
        * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
        * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
        * @param width (float) : width of our entity.
        * @param height (float) : height of our entity.
        */
        Jetpack(float posX, float posY, float width, float height);

    };

}



#endif //DOODLEJUMP_JETPACK_H
