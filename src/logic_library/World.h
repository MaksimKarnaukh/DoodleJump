// Author: Maksim Karnaukh

#ifndef DOODLEJUMP_WORLD_H
#define DOODLEJUMP_WORLD_H

#include "string"
#include "cmath"
#include "iostream"
#include "Player.h"
#include "Platform.h"
#include "BGTile.h"
#include "Bonus.h"
#include "AbstractFactory.h"
#include "Camera.h"
#include <memory>
#include "Random.h"
#include "Score.h"
#include <deque>
#include <map>

namespace logic {

    class World {

    public:

        std::shared_ptr<logic::Score> score; // score is an observer of the doodle (player)
        std::shared_ptr<logic::Player> doodle; // player entity
        std::deque<std::vector<std::shared_ptr<logic::BGTile>>> bgTiles; // matrix of background tiles (little squares).
        std::vector<std::shared_ptr<logic::Platform>> platforms; // list that contains all platforms in our current "view" window
        std::vector<std::shared_ptr<logic::Bonus>> bonuses; // list that contains all bonusses in our current "view" window

        std::shared_ptr<logic::AbstractFactory> Factory;

        float leftBound = logic::utility::Camera::Instance().getLeftBound();
        float rightBound = logic::utility::Camera::Instance().getRightBound();
        float lowerBound = logic::utility::Camera::Instance().getLowerBound();
        float shiftBorder = logic::utility::Camera::Instance().getShiftBorder();

        float formerPlatformPosY = 0; // y-position of the platform we generated the previous time.
        float formerPlatformPosX = 0; // x-position of the platform we generated the previous time.
        bool wasBonusGenerated = false; // bool for knowing whether we generated a bonus last time (when we generated the platform).

        bool gameOver = false; // true when we fall in the void below.

        std::map<int, std::map<int, float>> percentages; // map for our random platform generation

        // entity data :
        float playerWidth = 0.077;
        float playerHeight = 0.18;
        float platformWidth = 0.174004;
        float platformHeight = 0.0411;
        float springWidth = 0.058;
        float springHeight = 0.0411;
        float jetpackWidth = 0.0696;
        float jetpackHeight = 0.06576;

    public:

        /**
        * @function : World
        * Constructor for a World.
        */
        World();

        /**
        * @function : World
        * Constructor for a World.
        * @param factory (std::shared_ptr<logic::AbstractFactory>) : abstract factory (actually concrete factory).
        */
        World(std::shared_ptr<logic::AbstractFactory>& factory);

        /**
        * @function : ~World
        * Destructor for a World. Resets everything in the world.
        */
        ~World();

        /**
        * @function : receiveInput
        * Function that handles the received input from the game class and moves the player accordingly.
        * @param key (std::string) : key that was pressed by the user.
        */
        void receiveInput(std::string &key);

        /**
        * @function : checkForCollision
        * Function that checks for collision between the player and other entities.
        */
        void checkForCollision();

        /**
        * @function : checkForCollisionBetweenPlatforms
        * Function that checks for collision between platforms.
        */
        void checkForCollisionBetweenPlatforms();

        /**
        * @function : checkForUndetectedCollision
        * Function that checks for intersection between entities (e1 and e2).
        * @param e1 (std::shared_ptr<logic::EntityModel>) : first entity.
        * @param e2 (std::shared_ptr<logic::EntityModel>) : second entity.
        * @param middleLine (std::vector<std::pair<float,float>>) :
        */
        bool checkForUndetectedCollision(const std::shared_ptr<logic::EntityModel>& e1, std::vector<std::pair<float,float>> &middleLine, const std::shared_ptr<logic::EntityModel>& e2) const;

        /**
        * @function : createStartEntities
        * Handles the creation of the entities at the start of the game (player, background tiles and some prebuilt platforms
        */
        void createStartEntities();

        /**
        * @function : createEntities
        * Handles the spontaneous creation of entities throughout the game (i.e. platform and bonus generation).
        */
        void createEntities();

        /**
        * @function : update
        * Updates everything in the world (movement of player, collision checking, creating entities,...).
        */
        void update();

        /**
        * @function : getLineBetweenPoints
        * Returns a line between the first and second point in the form of a list of pairs of floats.
        * @param x0 (float) : x-coordinate of the first point.
        * @param y0 (float) : y-coordinate of the first point.
        * @param x1 (float) : x-coordinate of the second point.
        * @param y1 (float) : y-coordinate of the second point.
        * @return (std::vector<std::pair<float,float>>) : list of points which represents the line
        * Source : algorithm from project Computer Graphics.
        */
        static std::vector<std::pair<float,float>> getLineBetweenPoints(float x0, float y0, float x1, float y1);

        /**
        * @function : setupPercentages
        * Sets up the percentages map, that we use for our random platform generation.
        */
        void setupPercentages();

        /**
        * @function : createStartingBGTiles
        * Creates the background tiles in the beginning.
        */
        void createStartingBGTiles();

        /**
        * @function : deleteOutOfViewPlatforms
        * Deletes all platforms that are out of view.
        */
        void deleteOutOfViewPlatforms();

        /**
        * @function : deleteOutOfViewBonusses
        * Deletes all bonusees that are out of view.
        */
        void deleteOutOfViewBonusses();

        /**
        * @function : recycleOutOfViewBGTiles
        * Recycles all background tiles that are out of view at the bottom (it stacks them on top).
        */
        void recycleOutOfViewBGTiles();

        /**
        * @function : choosePlatformType
        * Chooses the platform type by chance.
        * @return (int) : integer representing the type of platform to be generated.
        */
        int choosePlatformType() const;

        /**
        * @function : chooseBonusType
        * Chooses the bonus type by chance.
        * @param bonus (std::shared_ptr<logic::Bonus>) : reference to the bonus that we instantiated previously.
        */
        void chooseBonusType(std::shared_ptr<logic::Bonus>& bonus) const;

        /**
        * @function : calculatePlatformXPos
        * Calculates the x-position for our platform.
        * @param platform (std::shared_ptr<logic::Platform>) : reference to the platform that we instantiated previously.
        * @return (float) : x-position.
        */
        float calculatePlatformXPos(const std::shared_ptr<logic::Platform>& platform) const;

    };

}



#endif //DOODLEJUMP_WORLD_H
