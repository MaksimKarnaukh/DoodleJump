//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_ENTITYVIEW_H
#define DOODLEJUMP_ENTITYVIEW_H

#include "../logic_library/Observer.h"
#include "SFML/Graphics.hpp"
#include "Window.h"

namespace representation {

    class EntityView: public logic::Observer {

    protected:

        sf::Sprite sprite;
        sf::Texture texture;

    public:

        EntityView();

        EntityView(std::shared_ptr<logic::Subject> subject);

        void setSpriteTexture(const std::string& filename);

        sf::Sprite getSprite() {
            return sprite;
        }

        sf::Texture getTexture() {
            return texture;
        }

        void update() override;

    };

}



#endif //DOODLEJUMP_ENTITYVIEW_H
