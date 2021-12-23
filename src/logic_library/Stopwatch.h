//
// Created by centu on 17/11/2021.
//
// https://www.youtube.com/watch?v=Vyt-dM8gTRQ&ab_channel=AtherOmar
// https://discuss.cocos2d-x.org/t/correct-way-to-implement-singleton/28226/22?page=2

#ifndef DOODLEJUMP_STOPWATCH_H
#define DOODLEJUMP_STOPWATCH_H

#include <chrono>

namespace logic {
    class Stopwatch {

        //static Stopwatch& sInstance;

        std::chrono::system_clock::time_point mStartTime;
        std::chrono::duration<float> mDeltaTime;

    public:

        Stopwatch(const Stopwatch &) = delete;
        Stopwatch(const Stopwatch &&) = delete;

        Stopwatch& operator=(const Stopwatch &) = delete;
        Stopwatch& operator=(const Stopwatch &&) = delete;

        static Stopwatch& Instance();

        void Reset(); // resets timer

        float getDeltaTime();

        void tick();

    private:

        Stopwatch();
        ~Stopwatch();

    };
}



#endif //DOODLEJUMP_STOPWATCH_H
