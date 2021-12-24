//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_BONUS_H
#define DOODLEJUMP_BONUS_H

#include "EntityModel.h"

namespace logic {

    class Bonus: public logic::EntityModel {

    protected:
        float bonusForce; // multiplier for the player speed

    public:

        /**
        * @function : Bonus
        * Constructor for a bonus.
        */
        Bonus();

        /**
        * @function : setBonusForce
        * Setter function for the bonusForce data member.
        * @param force (float) : value that we want to give to bonusForce.
        */
        virtual void setBonusForce(const float force) {
            bonusForce = force;
        }

        /**
         * @function : getBonusForce
         * Getter function for the bonusForce data member.
         * @return (float) : this->bonusForce
         */
        virtual float getBonusForce() const {
            return bonusForce;
        };

    };

}

#endif //DOODLEJUMP_BONUS_H
