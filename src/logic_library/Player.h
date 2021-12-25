//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_PLAYER_H
#define DOODLEJUMP_PLAYER_H

#include "EntityModel.h"
#include "Stopwatch.h"

namespace logic {

    class Player: public logic::EntityModel {

        const float gravity = -2.08f; // factor that tells us how hard we are getting pulled down
        float jumpVelocity = 1.32f; // factor that tells us how high we can jump

    public:

        /**
        * @function : Player
        * Constructor for a Player.
        */
        Player();

        /**
        * @function : Player
        * Constructor for a Player.
        * @param posX (float) : x-coordinate of our entity, between the range [0,1-entity.width].
        * @param posY (float) : y-coordinate of our entity, between the range [0+entity.height, inf[.
        */
        Player(float posX, float posY);

        /**
        * @function : moveLeft
        * Moves the player left.
        */
        void moveLeft();

        /**
        * @function : moveRight
        * Moves the player right.
        */
        void moveRight();

        /**
        * @function : jump
        * Sets the speed of the player to jumpVelocity, so that the player "jumps".
        */
        void jump();

        /**
        * @function : applyGravity
        * Applies gravity to the speed of the player (=> as a result, the speed decreases).
        */
        void applyGravity();

        /**
        * @function : moveVertically
        * Moves the player in the vertical direction (depending on the speed).
        */
        void moveVertically();

        /**
        * @function : touchedBonus
        * Multiplies the jumpVelocity by the parameter bonusForce and sets this as the player speed.
        * @param bonusForce (float) : jumpvelocity multiplier.
        */
        void touchedBonus(float bonusForce);

    };

}



#endif //DOODLEJUMP_PLAYER_H
