// Author: Maksim Karnaukh

#include "Camera.h"

namespace logic {
namespace utility {

Camera::Camera() = default;

std::pair<int, int> Camera::projectCoordinates(const float x, const float y) const
{

        int pixelX = static_cast<int>(std::round(x * (float)windowWidth));
        int pixelY = windowHeight - static_cast<int>(std::round((y - shiftValue) * (float)windowHeight));

        return std::make_pair(pixelX, pixelY);
}

Camera& Camera::Instance()
{
        static Camera instance;
        return instance;
}
} // namespace utility
} // namespace logic