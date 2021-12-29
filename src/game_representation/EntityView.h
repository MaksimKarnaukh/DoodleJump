

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

        std::weak_ptr<logic::EntityModel> mEntityModel;

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
        * Destructor for a EntityView.
        */
        ~EntityView() override = default;

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
        * @function : setSpriteScale
        * Sets the sprite scale.
        * @param p (std::shared_ptr<logic::EntityModel>) : entity model.
        */
        void setSpriteScale(const std::shared_ptr<logic::EntityModel>& p) {
            sprite.setScale(1*((float)logic::utility::Camera::Instance().getWindowWidth()*p->getWidth())/(float)getTexture().getSize().x, 1*((float)logic::utility::Camera::Instance().getWindowHeight()*p->getHeight())/(float)getTexture().getSize().y);
        }

        /**
        * @function : update
        * Updates the sprite's position correctly according to the logic coordinates.
        */
        void update() override;

    };

}



#endif //DOODLEJUMP_ENTITYVIEW_H
