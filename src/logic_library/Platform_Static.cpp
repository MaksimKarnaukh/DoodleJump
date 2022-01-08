// Author: Maksim Karnaukh

#include "Platform_Static.h"

namespace logic {

Platform_Static::Platform_Static() = default;

Platform_Static::Platform_Static(const float posX, const float posY) : Platform(posX, posY) {}

Platform_Static::Platform_Static(const float posX, const float posY, const float width, const float height)
    : Platform(posX, posY, width, height)
{
}

float Platform_Static::isTouched()
{
        timesTouched++;
        return 1;
}

} // namespace logic