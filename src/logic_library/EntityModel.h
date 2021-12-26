

#ifndef DOODLEJUMP_ENTITYMODEL_H
#define DOODLEJUMP_ENTITYMODEL_H

#include "Subject.h"
#include "Stopwatch.h"

namespace logic {

    class EntityModel: public logic::Subject {

    protected:

        float e_width; // width of the entity
        float e_height; // height of the entity

        float x_pos; // x position of the entity
        float y_pos; // y position of the entity

        float e_speed = 0; // velocity (used for going up and down, not right and left)
        float unit = 0.6f; // unit of distance (used for going right and left, not up and down)

        float x_posPrevious; // x position of entity in previous frame
        float y_posPrevious; // y position of entity in previous frame

    public: // getters en setters

        /**
        * @function : setWidth
        * Setter function for the e_width data member.
        * @param width (float) : value that we want to give to e_width.
        */
        void setWidth(float width) {
            e_width = width;
        }

        /**
        * @function : setHeight
        * Setter function for the e_height data member.
        * @param height (float) : value that we want to give to e_height.
        */
        void setHeight(float height) {
            e_height = height;
        }

        /**
        * @function : setPositionX
        * Setter function for the x_pos data member.
        * @param posX (float) : value that we want to give to x_pos.
        */
        void setPositionX(float posX) {
            x_pos = posX;
        }

        /**
        * @function : setPositionY
        * Setter function for the y_pos data member.
        * @param posY (float) : value that we want to give to y_pos.
        */
        void setPositionY(float posY) {
            y_pos = posY;
        }

        /**
        * @function : setPreviousPositionX
        * Setter function for the x_posPrevious data member.
        * @param posX (float) : value that we want to give to x_posPrevious.
        */
        void setPreviousPositionX(float posX) {
            x_posPrevious = posX;
        }

        /**
        * @function : setPreviousPositionY
        * Setter function for the y_posPrevious data member.
        * @param posY (float) : value that we want to give to y_posPrevious.
        */
        void setPreviousPositionY(float posY) {
            y_posPrevious = posY;
        }

        /**
        * @function : setSpeed
        * Setter function for the e_speed data member.
        * @param speed (float) : value that we want to give to e_speed.
        */
        void setSpeed(float speed) {
            e_speed = speed;
        }

        /**
        * @function : setUnitOfDistance
        * Setter function for the unit data member.
        * @param unitOfDistance (float) : value that we want to give to unit.
        */
        void setUnitOfDistance(float unitOfDistance) {
            unit = unitOfDistance;
        }

        /**
        * @function : getWidth
        * Getter function for the e_width data member.
        * @return (float) : this->e_width
        */
        float getWidth() const {
            return e_width;
        }

        /**
        * @function : getHeight
        * Getter function for the e_height data member.
        * @return (float) : this->e_height
        */
        float getHeight() const {
            return e_height;
        }

        /**
        * @function : getPositionX
        * Getter function for the x_pos data member.
        * @return (float) : this->x_pos
        */
        float getPositionX() const {
            return x_pos;
        }

        /**
        * @function : getPositionY
        * Getter function for the y_pos data member.
        * @return (float) : this->y_pos
        */
        float getPositionY() const {
            return y_pos;
        }

        /**
        * @function : getPreviousPositionX
        * Getter function for the x_posPrevious data member.
        * @return (float) : this->x_posPrevious
        */
        float getPreviousPositionX() const {
            return x_posPrevious;
        }

        /**
        * @function : getPreviousPositionY
        * Getter function for the y_posPrevious data member.
        * @return (float) : this->y_posPrevious
        */
        float getPreviousPositionY() const {
            return y_posPrevious;
        }

        /**
        * @function : getSpeed
        * Getter function for the e_speed data member.
        * @return (float) : this->e_speed
        */
        float getSpeed() const {
            return e_speed;
        }

        /**
        * @function : getUnit
        * Getter function for the unit data member.
        * @return (float) : this->unit
        */
        float getUnit() const {
            return unit;
        }

    public:

        /**
        * @function : EntityModel
        * Constructor for a EntityModel.
        */
        EntityModel();

        //~EntityModel();

    };
}



#endif //DOODLEJUMP_ENTITYMODEL_H
