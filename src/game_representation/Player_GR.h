

#ifndef DOODLEJUMP_PLAYER_GR_H
#define DOODLEJUMP_PLAYER_GR_H

#include "EntityView.h"

namespace representation {

    class Player_GR: public EntityView {

    public:

        /**
        * @function : Player_GR
        * Constructor for a Player_GR.
        * @param entityModel (std::shared_ptr<logic::EntityModel>) : entityModel
        */
        Player_GR(const std::shared_ptr<logic::EntityModel> &entityModel);

        /**
        * @function : Player_GR
        * Destructor for a Player_GR.
        */
        ~Player_GR() override = default;

    };

}



#endif //DOODLEJUMP_PLAYER_GR_H
