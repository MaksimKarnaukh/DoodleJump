

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
        * Destructor for a background tile.
        */
        ~BGTile() override = default;

        /**
        * @function : BGTile
        * Constructor for a background tile.
        * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
        * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
        */
        BGTile(float posX, float posY);

        /**
        * @function : BGTile
        * Constructor for a background tile.
        * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
        * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
        * @param width (float) : width of our entity.
        * @param height (float) : height of our entity.
        */
        BGTile(float posX, float posY, float width, float height);

    };

}



#endif //DOODLEJUMP_BGTILE_H
