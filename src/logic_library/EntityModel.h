//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_ENTITYMODEL_H
#define DOODLEJUMP_ENTITYMODEL_H

#include "Subject.h"

namespace logic {

    class EntityModel: public logic::Subject {

        double e_width; // size
        double e_height;

        double x_pos; // position
        double y_pos;

        double e_speed; // velocity

    public:

        void setWidth(double width) {
            e_width = width;
        }

        void setHeight(double height) {
            e_height = height;
        }

        void setPositionX(double posX) {
            x_pos = posX;
        }

        void setPositionY(double posY) {
            y_pos = posY;
        }

        double getWidth() const {
            return e_width;
        }

        double getHeight() const {
            return e_height;
        }

        double getPositionX() const {
            return x_pos;
        }

        double getPositionY() const {
            return y_pos;
        }

    public:

        EntityModel();

        void update();

    };
}



#endif //DOODLEJUMP_ENTITYMODEL_H
