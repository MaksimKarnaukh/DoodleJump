

#include "Stopwatch.h"

namespace logic {
    namespace utility {

        Stopwatch& Stopwatch::Instance() {
            static Stopwatch instance;
            return instance;
        }

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
}


