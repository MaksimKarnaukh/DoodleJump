//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_OBSERVER_H
#define DOODLEJUMP_OBSERVER_H

#include "Subject.h"

class Subject;

namespace logic {

    class Observer {

        Subject mSubject;

    public:

        Observer(const Subject &subject);

        void update();

    };

}



#endif //DOODLEJUMP_OBSERVER_H
