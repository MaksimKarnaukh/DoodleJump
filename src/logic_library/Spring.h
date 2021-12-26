

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
        * Constructor for a Spring.
        * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
        * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
        */
        Spring(float posX, float posY);

    };

}



#endif //DOODLEJUMP_SPRING_H
