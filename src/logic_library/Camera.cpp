//
// Created by centu on 17/11/2021.
//

#include "Camera.h"

namespace logic {

    Camera::Camera() = default;

    std::pair<int, int> Camera::projectCoordinates(float x, float y) const {

        int pixelX = (int)std::round(x)*windowWidth;
        int pixelY = (int)std::round(y)*windowHeight;

        return std::make_pair(pixelX, pixelY);
    }

    Camera &Camera::Instance() {
        static Camera instance;
        return instance;
    }

}