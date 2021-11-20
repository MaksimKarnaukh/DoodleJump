//
// Created by centu on 17/11/2021.
//

#include "Stopwatch.h"

namespace logic {

    Stopwatch* Stopwatch::sInstance = nullptr;

    Stopwatch* Stopwatch::Instance() {
        if (sInstance == nullptr) {
            sInstance = new Stopwatch();
        }
        return sInstance;
    }

    void Stopwatch::release() {
        delete sInstance;
        sInstance = nullptr;
    }

    Stopwatch::Stopwatch() {
        Reset();
        mTimeScale = 1.0f;
        mDeltaTime = std::chrono::duration<float>(0.0f);
    }

    Stopwatch::~Stopwatch() {

    }

    void Stopwatch::Reset() {
        mStartTime = std::chrono::system_clock::now();
    }

    float Stopwatch::getDeltaTime() {
        return mDeltaTime.count();
    }

    void Stopwatch::setTimeScale(float t) {
        mTimeScale = t;
    }

    float Stopwatch::getTimeScale() const {
        return mTimeScale;
    }

    void Stopwatch::tick() {
        mDeltaTime = std::chrono::system_clock::now()-mStartTime;
    }
}


