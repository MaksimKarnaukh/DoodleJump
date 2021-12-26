

#include "Score.h"

logic::Score::Score() {
    score = 0;
};

logic::Score::Score(const std::shared_ptr<logic::EntityModel>& entityModel) {

    mEntityModel = entityModel;
    score = 0;
}

void logic::Score::update() {

    float plus = (mEntityModel->getPositionY() - mEntityModel->getPreviousPositionY());

    if (getScore() < getScore()+plus) {
        setScore(getScore()+plus);
    }

}


