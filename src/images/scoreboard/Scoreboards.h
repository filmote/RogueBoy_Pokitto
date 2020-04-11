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
    #include "IceSpell_Scoreboard_F0.h"
    #include "IceSpell_Scoreboard_F1.h"
    #include "IceSpell_Scoreboard_F2.h"
    #include "IceSpell_Scoreboard_F3.h"
    #include "IceSpell_Scoreboard_F4.h"
    #include "IceSpell_Scoreboard_F5.h"
    #include "IceSpell_Scoreboard_F6.h"
    #include "IceSpell_Scoreboard_F7.h"
    #include "IceSpell_Scoreboard_F8.h"
    #include "IceSpell_Scoreboard_F9.h"
    #include "IceSpell_Scoreboard_F10.h"
    #include "IceSpell_Scoreboard_F11.h"
    #include "GreenSpell_Scoreboard.h"
    #include "YellowSpell_Scoreboard.h"
    #include "MauveSpell_Scoreboard.h"

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

    const uint8_t * const IceSpell_Scoreboard[] = { 
        IceSpell_Scoreboard_F11,
        IceSpell_Scoreboard_F10,
        IceSpell_Scoreboard_F9,
        IceSpell_Scoreboard_F8,
        IceSpell_Scoreboard_F7,
        IceSpell_Scoreboard_F6,
        IceSpell_Scoreboard_F5,
        IceSpell_Scoreboard_F4,
        IceSpell_Scoreboard_F3,
        IceSpell_Scoreboard_F2,
        IceSpell_Scoreboard_F1,
        IceSpell_Scoreboard_F0,
    };    

};
