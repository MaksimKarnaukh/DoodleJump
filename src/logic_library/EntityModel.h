//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_ENTITYMODEL_H
#define DOODLEJUMP_ENTITYMODEL_H

#include "Subject.h"

namespace logic {

    class EntityModel: public logic::Subject {

    protected:

        float e_width; // size
        float e_height;

        float x_pos; // position
        float y_pos;

        float e_speed; // velocity
        float unit=200.0f; // unit of distance


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

        float getPositionX() const override {
            return x_pos;
        }

        float getPositionY() const override {
            return y_pos;
        }

        float getSpeed() const {
            return e_speed;
        }

        float getUnit() const {
            return unit;
        }

    public:

        EntityModel();

        void update();

    };
}



#endif //DOODLEJUMP_ENTITYMODEL_H
