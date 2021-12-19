//
// Created by centu on 17/11/2021.
//

#include "Score.h"

logic::Score::Score() {
    score = 0;
};

void logic::Score::update() {

    if (getScore() < static_cast<int>(std::round(mEntityModel->getPositionY()*10))) {
        setScore(static_cast<int>(std::round(mEntityModel->getPositionY()*10)));
    }

}

logic::Score::Score(const std::shared_ptr<logic::EntityModel>& entityModel) {

    mEntityModel = entityModel;
    score = 0;
}
