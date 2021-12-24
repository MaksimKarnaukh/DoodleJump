//
// Created by centu on 17/11/2021.
//

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

        void setWidth(float width) {
            e_width = width;
        }

        void setHeight(float height) {
            e_height = height;
        }

        void setPositionX(float posX) {
            x_pos = posX;
        }

        void setPositionY(float posY) {
            y_pos = posY;
        }

        void setPreviousPositionX(float posX) {
            x_posPrevious = posX;
        }

        void setPreviousPositionY(float posY) {
            y_posPrevious = posY;
        }

        void setSpeed(float speed) {
            e_speed = speed;
        }

        void setUnitOfDistance(float unitOfDistance) {
            unit = unitOfDistance;
        }

        float getWidth() const {
            return e_width;
        }

        float getHeight() const {
            return e_height;
        }

        float getPositionX() const {
            return x_pos;
        }

        float getPositionY() const {
            return y_pos;
        }

        float getPreviousPositionX() const {
            return x_posPrevious;
        }

        float getPreviousPositionY() const {
            return y_posPrevious;
        }

        float getSpeed() const {
            return e_speed;
        }

        float getUnit() const {
            return unit;
        }

    public:

        EntityModel();
        //~EntityModel();

        void update();

    };
}



#endif //DOODLEJUMP_ENTITYMODEL_H
