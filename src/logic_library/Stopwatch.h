// Author: Maksim Karnaukh
// Implemented as a singleton class.
// Sources:
// https://www.youtube.com/watch?v=Vyt-dM8gTRQ&ab_channel=AtherOmar
// https://discuss.cocos2d-x.org/t/correct-way-to-implement-singleton/28226/22?page=2

#ifndef DOODLEJUMP_STOPWATCH_H
#define DOODLEJUMP_STOPWATCH_H

#include <chrono>

namespace logic {
namespace utility {

class Stopwatch
{

        std::chrono::system_clock::time_point mStartTime;
        std::chrono::duration<float> mDeltaTime; // used as the elapsed time.

        /**
         * @function : Stopwatch
         * Constructor for a Stopwatch.
         */
        Stopwatch();

        /**
         * @function : Stopwatch
         * Destructor for a Stopwatch.
         */
        ~Stopwatch();

public:
        Stopwatch(const Stopwatch&) = delete;
        Stopwatch(const Stopwatch&&) = delete;

        Stopwatch& operator=(const Stopwatch&) = delete;
        Stopwatch& operator=(const Stopwatch&&) = delete;

public:
        static Stopwatch& Instance();

        /**
         * @function : Reset
         * Resets the mStartTime data member, setting it equal to std::chrono::system_clock::now().
         */
        void Reset();

        /**
         * @function : getDeltaTime
         * Returns the mDeltaTime data member.
         * @return (float) : mDeltaTime, which is the elapsed time, set by the last tick() called.
         */
        float getDeltaTime();

        /**
         * @function : tick
         * Sets the mDeltaTime equal to (std::chrono::system_clock::now()-mStartTime).
         */
        void tick();
};

} // namespace utility
} // namespace logic

#endif // DOODLEJUMP_STOPWATCH_H
