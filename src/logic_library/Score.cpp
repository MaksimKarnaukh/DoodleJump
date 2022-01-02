// Author: Maksim Karnaukh

#include "Score.h"

logic::Score::Score() {
    score = 0;
};

logic::Score::Score(const std::shared_ptr<logic::EntityModel>& entityModel) {

    mEntityModel = entityModel;
    score = 0;
}

void logic::Score::update() {

    if (!mEntityModel.expired()) {
        std::shared_ptr<logic::EntityModel> p = mEntityModel.lock();
        float plus = (p->getPositionY() - p->getPreviousPositionY());

        if (getScore() < getScore()+plus) {
            setScore(getScore()+plus);
        }
    }


}


