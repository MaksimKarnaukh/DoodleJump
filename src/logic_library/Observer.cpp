// Author: Maksim Karnaukh

#include "Observer.h"

namespace logic {

    Observer::Observer() = default;

    Observer::Observer(const std::shared_ptr<logic::Subject>& subject) {
        mSubject = subject;
    }

}

