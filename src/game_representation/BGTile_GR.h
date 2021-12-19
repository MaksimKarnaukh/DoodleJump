//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_BGTILE_GR_H
#define DOODLEJUMP_BGTILE_GR_H

#include "EntityView.h"

namespace representation {

    class BGTile_GR: public EntityView {

    public:

        BGTile_GR(const std::shared_ptr<logic::EntityModel> &entityModel);
    };
}



#endif //DOODLEJUMP_BGTILE_GR_H
