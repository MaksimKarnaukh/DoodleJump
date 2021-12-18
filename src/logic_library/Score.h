//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_SCORE_H
#define DOODLEJUMP_SCORE_H

#include "Observer.h"

namespace logic {

    class Score: public logic::Observer {

        int score;

    public:

        Score();

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
