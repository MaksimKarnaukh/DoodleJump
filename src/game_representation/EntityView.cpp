// Author: Maksim Karnaukh

#include "EntityView.h"

namespace representation {

    EntityView::EntityView() = default;

    EntityView::EntityView(const std::shared_ptr<logic::EntityModel>& entityModel) {
        mEntityModel = entityModel;
    }

    void EntityView::setSpriteTexture(const std::string &filename) {

        try {
            if (!texture.loadFromFile(filename)) {
                throw LoadFileException("Error loading from file");
            }
        }
        catch (LoadFileException& e) {
            std::cout << e.what() << ": " << filename << std::endl;
        }

        sprite.setTexture(texture);

    }

    void EntityView::update() {

        if (! mEntityModel.expired()) {
            std::shared_ptr<logic::EntityModel> p = mEntityModel.lock();
            std::pair<int, int> pixels = logic::utility::Camera::Instance().projectCoordinates(p->getPositionX(),p->getPositionY()); // projection
            sprite.setPosition((float)pixels.first, (float)pixels.second);

        }
    }
}