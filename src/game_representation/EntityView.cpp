//
// Created by centu on 17/11/2021.
//

#include "EntityView.h"

namespace representation {

    EntityView::EntityView() = default;

    EntityView::EntityView(std::shared_ptr<logic::Subject> subject) {
        mSubject = subject;
    }

    void EntityView::setSpriteTexture(const std::string &filename) {

        texture.loadFromFile(filename);
        sprite.setTexture(texture);

        //sprite.setScale(0.25,0.25);

    }

    void EntityView::update() {

        std::pair<int, int> pixels = logic::Camera::Instance().projectCoordinates(mSubject->getPositionX(),mSubject->getPositionY());


        sprite.setPosition(pixels.first, pixels.second);

        //std::cout << sprite.getPosition().x << " " << sprite.getPosition().y << std::endl;
        representation::Window::Instance().Draw(sprite);

    }
}