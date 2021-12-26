

#ifndef DOODLEJUMP_BGTILE_H
#define DOODLEJUMP_BGTILE_H

#include "EntityModel.h"

namespace logic {

    class BGTile: public logic::EntityModel {

    public:

        /**
        * @function : BGTile
        * Constructor for a background tile.
        */
        BGTile();

        /**
        * @function : BGTile
        * Constructor for a background tile.
        * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
        * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
        */
        BGTile(float posX, float posY);

    };

}



#endif //DOODLEJUMP_BGTILE_H
