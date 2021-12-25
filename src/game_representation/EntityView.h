//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_ENTITYVIEW_H
#define DOODLEJUMP_ENTITYVIEW_H

#include "../logic_library/Observer.h"
#include "SFML/Graphics.hpp"
#include "Window.h"
#include "../logic_library/Camera.h"
#include "../logic_library/EntityModel.h"
#include "../LoadFileException.h"

namespace representation {

    class EntityView: public logic::Observer {

    protected:

        std::shared_ptr<logic::EntityModel> mEntityModel;

        sf::Sprite sprite;
        sf::Texture texture;

    public:

        /**
        * @function : EntityView
        * Constructor for a EntityView.
        */
        EntityView();

        /**
        * @function : EntityView
        * Constructor for a EntityView.
        * @param entityModel (std::shared_ptr<logic::EntityModel>) : entityModel
        */
        EntityView(const std::shared_ptr<logic::EntityModel>& entityModel);

        /**
        * @function : setSpriteTexture
        * Setter: puts the texture on the sprite.
        * @param filename (std::string) : name of the texture file
        */
        void setSpriteTexture(const std::string& filename);

        /**
        * @function : getSprite
        * Getter: returns the sprite data member.
        * @return (sf::Sprite) : this->sprite
        */
        sf::Sprite& getSprite() {
            return sprite;
        }

        /**
        * @function : getTexture
        * Getter: returns the texture data member.
        * @return (sf::Texture) : this->texture
        */
        sf::Texture& getTexture() {
            return texture;
        }

        /**
        * @function : update
        * Updates the sprite's position correctly according to the logic coordinates.
        */
        void update() override;

    };

}



#endif //DOODLEJUMP_ENTITYVIEW_H
