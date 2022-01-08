// Author: Maksim Karnaukh

#include "Platform_Temporary.h"

namespace logic {

Platform_Temporary::Platform_Temporary() = default;

Platform_Temporary::Platform_Temporary(const float posX, const float posY) : Platform(posX, posY) {}

Platform_Temporary::Platform_Temporary(const float posX, const float posY, const float width, const float height)
    : Platform(posX, posY, width, height)
{
}

float Platform_Temporary::isTouched() { return 0; }

} // namespace logic