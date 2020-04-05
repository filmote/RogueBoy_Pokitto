#pragma once

namespace Images {

    #include "Fireball.h"
    #include "Scoreboard.h"
    #include "Direction_00.h"
    #include "Direction_01.h"
    #include "Direction_02.h"
    #include "Direction_03.h"
    #include "Direction_04.h"
    #include "Direction_05.h"
    #include "Direction_06.h"
    #include "Direction_07.h"

    const uint8_t * const Directions[] = { 
        Direction_00,
        Direction_01,
        Direction_02,
        Direction_03,
        Direction_04,
        Direction_05,
        Direction_06,
        Direction_07,
    };
};
