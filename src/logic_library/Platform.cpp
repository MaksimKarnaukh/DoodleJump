// Author: Maksim Karnaukh

#include "Platform.h"

namespace logic {

Platform::Platform() = default;

Platform::Platform(const float posX, const float posY) : EntityModel(posX, posY) {}

Platform::Platform(const float posX, const float posY, const float width, const float height)
    : EntityModel(posX, posY, width, height)
{
}
} // namespace logic