

#include "EntityModel.h"

logic::EntityModel::EntityModel() = default;

logic::EntityModel::EntityModel(const float posX, const float posY) {

    this->setPositionX(posX);
    this->setPositionY(posY);

}

logic::EntityModel::EntityModel(const float posX, const float posY, const float width, const float height) {

    this->setPositionX(posX);
    this->setPositionY(posY);

    this->setWidth(width);
    this->setHeight(height);
}
