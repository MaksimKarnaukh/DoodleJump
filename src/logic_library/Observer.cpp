//
// Created by centu on 17/11/2021.
//

#include "Observer.h"

//#include "Subject.h"

namespace logic {

    Observer::Observer() = default;

    Observer::Observer(const std::shared_ptr<logic::Subject>& subject) {
        mSubject = subject;
    }

}

