//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_BONUS_H
#define DOODLEJUMP_BONUS_H

#include "EntityModel.h"

namespace logic {

    class Bonus: public logic::EntityModel {

    protected:
        float bonusForce;

    public:

        Bonus();

        virtual void setBonusForce(const float force) {
            bonusForce = force;
        }

        virtual float getBonusForce() const {
            return bonusForce;
        };


    };

}

#endif //DOODLEJUMP_BONUS_H
