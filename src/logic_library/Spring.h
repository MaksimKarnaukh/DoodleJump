// Author: Maksim Karnaukh

#ifndef DOODLEJUMP_SPRING_H
#define DOODLEJUMP_SPRING_H

#include "Bonus.h"

namespace logic {

    class Spring: public logic::Bonus {

    public:

        /**
        * @function : Spring
        * Constructor for a Spring.
        */
        Spring();

        /**
        * @function : Spring
        * Destructor for a Spring.
        */
        ~Spring() override = default;

        /**
        * @function : Spring
        * Constructor for a Spring.
        * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
        * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
        */
        Spring(float posX, float posY);

        /**
        * @function : Spring
        * Constructor for a Spring.
        * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
        * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
        * @param width (float) : width of our entity.
        * @param height (float) : height of our entity.
        */
        Spring(float posX, float posY, float width, float height);

    };

}



#endif //DOODLEJUMP_SPRING_H
