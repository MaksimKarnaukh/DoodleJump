//
// Created by centu on 17/11/2021.
//
// https://www.youtube.com/watch?v=_BpmfnqjgzQ&list=PLrhzvIcii6GNjpARdnO4ueTUAVR9eMBpc&index=2&ab_channel=ChristopherOkhravi

#ifndef DOODLEJUMP_SUBJECT_H
#define DOODLEJUMP_SUBJECT_H

#include <vector>
#include <string>
//#include "Observer.h"

namespace logic {

    class Observer;

    class Subject {

        std::vector<Observer*> observers;

    public:

        Subject();

        void registerObserver(Observer* observer);

        void removeObserver(Observer* observer);

        void notifyObservers();
    };
}



#endif //DOODLEJUMP_SUBJECT_H
