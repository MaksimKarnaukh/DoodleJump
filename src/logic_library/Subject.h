// Source: https://www.youtube.com/watch?v=_BpmfnqjgzQ&list=PLrhzvIcii6GNjpARdnO4ueTUAVR9eMBpc&index=2&ab_channel=ChristopherOkhravi

#ifndef DOODLEJUMP_SUBJECT_H
#define DOODLEJUMP_SUBJECT_H

#include <vector>
#include <string>
#include <memory>

namespace logic {

    class Observer;

    class Subject {

    protected:

        std::vector<std::shared_ptr<Observer>> observers;

    public:

        /**
        * @function : Subject
        * Constructor for a Subject.
        */
        Subject();

        virtual ~Subject() = default;;

        /**
        * @function : registerObserver
        * Adds an observer to the list of observers.
        * @param observer (std::shared_ptr<Observer>) : observer that we want to add.
        */
        void registerObserver(std::shared_ptr<Observer> observer);

        /**
        * @function : removeObserver
        * Removes the observer from the list of observers.
        * @param observer (std::shared_ptr<Observer>) : observer that we want to remove.
        */
        void removeObserver(const std::shared_ptr<Observer>& observer);

        /**
        * @function : notifyObservers
        * Updates each observer in the list of observers.
        */
        void notifyObservers();

        /**
        * @function : getObservers
        * Returns the list of observers.
        * @return (std::vector<std::shared_ptr<Observer>>) : list of observers.
        */
        std::vector<std::shared_ptr<Observer>> getObservers();

    };
}

#endif //DOODLEJUMP_SUBJECT_H
