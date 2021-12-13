//
// Created by centu on 17/11/2021.
//

#include "Camera.h"

namespace logic {

    Camera::Camera() = default;

    std::pair<int, int> Camera::projectCoordinates(float x, float y) const {

        int pixelX = static_cast<int>(std::round(x*windowWidth));
        int pixelY = windowHeight-static_cast<int>(std::round((y-shiftValue)*windowHeight));

        return std::make_pair(pixelX, pixelY);
    }

    Camera &Camera::Instance() {
        static Camera instance;
        return instance;
    }

}