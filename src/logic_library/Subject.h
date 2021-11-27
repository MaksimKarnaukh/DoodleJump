//
// Created by centu on 17/11/2021.
//
// https://www.youtube.com/watch?v=_BpmfnqjgzQ&list=PLrhzvIcii6GNjpARdnO4ueTUAVR9eMBpc&index=2&ab_channel=ChristopherOkhravi

#ifndef DOODLEJUMP_SUBJECT_H
#define DOODLEJUMP_SUBJECT_H

#include <vector>
#include <string>
#include <memory>
//#include "Observer.h"

namespace logic {

    class Observer;

    class Subject {

        std::vector<std::shared_ptr<Observer>> observers;

    public:

        Subject();

        void registerObserver(const std::shared_ptr<Observer> observer);

        void removeObserver(const std::shared_ptr<Observer> observer);

        void notifyObservers();



        virtual float getPositionX() const = 0;

        virtual float getPositionY() const = 0;
    };
}



#endif //DOODLEJUMP_SUBJECT_H
