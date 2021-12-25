//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_OBSERVER_H
#define DOODLEJUMP_OBSERVER_H

#include "Subject.h"

class Subject;

namespace logic {

    class Observer {

    protected:

        std::shared_ptr<logic::Subject> mSubject; // subject that belongs to this observer

    public:

        /**
        * @function : Observer
        * Constructor for a Observer.
        */
        Observer();

        /**
        * @function : Observer
        * Constructor for a Observer.
        */
        Observer(const std::shared_ptr<logic::Subject>& subject);

        /**
        * @function : update
        * Updates the state of the observer.
        */
        virtual void update() = 0;

        /**
        * @function : registerSubject
        * Sets the subject for this observer.
        * @param subject (std::shared_ptr<logic::Subject>) : subject that we register.
        */
        void registerSubject(const std::shared_ptr<logic::Subject>& subject) {
            mSubject = subject;
        }

    };

}



#endif //DOODLEJUMP_OBSERVER_H
