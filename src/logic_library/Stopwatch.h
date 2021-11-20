//
// Created by centu on 17/11/2021.
//
// https://www.youtube.com/watch?v=Vyt-dM8gTRQ&ab_channel=AtherOmar

#ifndef DOODLEJUMP_STOPWATCH_H
#define DOODLEJUMP_STOPWATCH_H

#include <chrono>

namespace logic {
    class Stopwatch {

        static Stopwatch* sInstance;

        std::chrono::system_clock::time_point mStartTime;
        std::chrono::duration<float> mDeltaTime;
        float mTimeScale;

    public:

        static Stopwatch* Instance();
        static void release();

        void Reset();

        float getDeltaTime();

        void setTimeScale(float t = 1.0f);

        float getTimeScale();

        void tick();

    private:

        Stopwatch();
        ~Stopwatch();

    };
}



#endif //DOODLEJUMP_STOPWATCH_H
