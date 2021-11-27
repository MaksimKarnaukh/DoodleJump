//
// Created by centu on 17/11/2021.
//

#include "Subject.h"

#include "Observer.h"

namespace logic {
    logic::Subject::Subject() = default;

    void Subject::registerObserver(const std::shared_ptr<Observer> observer) {

        observers.push_back(observer);
    }

    void Subject::removeObserver(const std::shared_ptr<Observer> observer) {

        auto it = observers.begin(); // std::vector<Observer*>::iterator it
        while (it != observers.end()) {
            if (*it == observer) {
                observers.erase(it);
                break;
            }
            else {
                ++it;
            }
        }
    }

    void Subject::notifyObservers() {

        for (auto obs = 0; obs < observers.size(); obs++) {
            observers[obs]->update();
        }
    }

}



