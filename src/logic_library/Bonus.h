

#ifndef DOODLEJUMP_BONUS_H
#define DOODLEJUMP_BONUS_H

#include "EntityModel.h"

namespace logic {

    class Bonus: public logic::EntityModel {

    protected:
        float bonusForce; // multiplier for the player speed
        float scoreIncrease;

    public:

        /**
        * @function : Bonus
        * Constructor for a bonus.
        */
        Bonus();

        /**
        * @function : Bonus
        * Destructor for a bonus.
        */
        ~Bonus() override = default;

        /**
        * @function : Bonus
        * Constructor for a bonus.
        * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
        * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
        */
        Bonus(float posX, float posY);

        /**
        * @function : Bonus
        * Constructor for a bonus.
        * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
        * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
        * @param width (float) : width of our entity.
        * @param height (float) : height of our entity.
        */
        Bonus(float posX, float posY, float width, float height);

        /**
        * @function : setBonusForce
        * Setter function for the bonusForce data member.
        * @param force (float) : value that we want to give to bonusForce.
        */
        virtual void setBonusForce(const float force) {
            bonusForce = force;
        }

        /**
        * @function : setScoreIncrease
        * Setter function for the scoreIncrease data member.
        * @param inc (float) : value that we want to give to scoreIncrease.
        */
        virtual void setScoreIncrease(const float inc) {
            scoreIncrease = inc;
        }

        /**
         * @function : getBonusForce
         * Getter function for the bonusForce data member.
         * @return (float) : this->bonusForce
         */
        virtual float getBonusForce() const {
            return bonusForce;
        };

        /**
         * @function : getScoreIncrease
         * Getter function for the scoreIncrease data member.
         * @return (float) : this->scoreIncrease
         */
        virtual float getScoreIncrease() const {
            return scoreIncrease;
        }

    };

}

#endif //DOODLEJUMP_BONUS_H
