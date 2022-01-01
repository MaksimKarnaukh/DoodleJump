// Author: Maksim Karnaukh

#ifndef DOODLEJUMP_BGTILE_GR_H
#define DOODLEJUMP_BGTILE_GR_H

#include "EntityView.h"

namespace representation {

    class BGTile_GR: public EntityView {

    public:

        /**
        * @function : BGTile_GR
        * Constructor for a BGTile_GR.
        * @param entityModel (std::shared_ptr<logic::EntityModel>) : entityModel
        */
        BGTile_GR(const std::shared_ptr<logic::EntityModel> &entityModel);

        /**
        * @function : BGTile_GR
        * Destructor for a BGTile_GR.
        */
        ~BGTile_GR() override = default;

    };
}



#endif //DOODLEJUMP_BGTILE_GR_H
