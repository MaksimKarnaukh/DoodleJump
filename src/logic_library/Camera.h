//
// Created by centu on 17/11/2021.
//

#ifndef DOODLEJUMP_CAMERA_H
#define DOODLEJUMP_CAMERA_H

#include "utility"
#include "cmath"

namespace logic {

    class Camera {

        static Camera& sInstance;

        int windowWidth = 640;
        int windowHeight = 960;

        float shiftValue = 0.0f;

    public:

        void setWindowWidth(int width) {
            windowWidth = width;
        }

        void setWindowHeight(int height) {
            windowHeight = height;
        }

        void setShiftValue(float shift) {
            shiftValue = shift;
        }

        int getWindowWidth() const {
            return windowWidth;
        }

        int getWindowHeight() const {
            return windowHeight;
        }

        float getShiftValue() const {
            return shiftValue;
        }

    public:

        Camera();

        std::pair<int,int> projectCoordinates(float x, float y) const;

        Camera(const Camera &) = delete;
        Camera(const Camera &&) = delete;

        Camera& operator=(const Camera &) = delete;
        Camera& operator=(const Camera &&) = delete;

        static Camera& Instance();

    };

}



#endif //DOODLEJUMP_CAMERA_H
