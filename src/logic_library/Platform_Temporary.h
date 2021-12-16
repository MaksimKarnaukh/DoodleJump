//
// Created by centu on 18/11/2021.
//

#ifndef DOODLEJUMP_PLATFORM_TEMPORARY_H
#define DOODLEJUMP_PLATFORM_TEMPORARY_H

#include "Platform.h"

namespace logic {

    class Platform_Temporary: public Platform {

    public:

        Platform_Temporary();

        Platform_Temporary(float posX, float posY);

        bool isTouched() override;

    };

}



#endif //DOODLEJUMP_PLATFORM_TEMPORARY_H
