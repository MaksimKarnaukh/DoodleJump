//
// Created by centu on 17/11/2021.
//

#include "Stopwatch.h"

namespace logic {

//    Stopwatch* Stopwatch::sInstance = nullptr;

    Stopwatch& Stopwatch::Instance() {
//        if (sInstance == nullptr) {
//            sInstance = new Stopwatch();
//        }
//        return sInstance;
        static Stopwatch instance;
        return instance;
    }

//    void Stopwatch::release() {
//        delete sInstance;
//        sInstance = nullptr;
//    }

    Stopwatch::Stopwatch() {
        Reset();
        mDeltaTime = std::chrono::duration<float>(0.0f);
    }

    Stopwatch::~Stopwatch() = default;

    void Stopwatch::Reset() {
        mStartTime = std::chrono::system_clock::now();
    }

    float Stopwatch::getDeltaTime() {
        return mDeltaTime.count();
    }

    void Stopwatch::tick() {
        mDeltaTime = std::chrono::system_clock::now()-mStartTime;
    }
}


