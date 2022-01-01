// Author: Maksim Karnaukh

#ifndef DOODLEJUMP_SCORE_H
#define DOODLEJUMP_SCORE_H

#include "Observer.h"
#include "cmath"
#include "EntityModel.h"

namespace logic {

    class Score: public logic::Observer {

        float score;

        std::shared_ptr<logic::EntityModel> mEntityModel; // points to an entityModel, in this case mostlikely the player.

    public:

        /**
        * @function : Score
        * Constructor for a Score.
        */
        Score();

        /**
        * @function : Score
        * Destructor for a Score.
        */
        ~Score() override = default;

        /**
        * @function : Score
        * Constructor for a Score.
        * @param entityModel (std::shared_ptr<logic::EntityModel>) : entityModel that we point to.
        */
        Score(const std::shared_ptr<logic::EntityModel>& entityModel);

        /**
        * @function : update
        * Updates the state of score.
        */
        void update() override;

    public:

        /**
        * @function : setScore
        * Setter function for the score data member.
        * @param _score (float) : value that we want to give to score.
        */
        void setScore(float _score) {
            score = _score;
        }

        /**
        * @function : getScore
        * Getter function for the score data member.
        * @return (float) : this->score
        */
        float getScore() const {
            return score;
        }

    };

}



#endif //DOODLEJUMP_SCORE_H
