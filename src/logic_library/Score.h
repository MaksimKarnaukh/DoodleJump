//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_SCORE_H
#define DOODLEJUMP_SCORE_H

#include "Observer.h"
#include "cmath"
#include "EntityModel.h"

namespace logic {

    class Score: public logic::Observer {

        int score;

        std::shared_ptr<logic::EntityModel> mEntityModel;

    public:

        Score();

        Score(const std::shared_ptr<logic::EntityModel>& entityModel);

        void update() override;

        bool isScore() {
            return true;
        }

    public:

        void setScore(int _score) {
            score = _score;
        }

        int getScore() const {
            return score;
        }

    };

}



#endif //DOODLEJUMP_SCORE_H
