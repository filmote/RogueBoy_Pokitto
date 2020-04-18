#pragma once

namespace Images {

    #include "bat/Bat_00.h"
    #include "bat/Bat_01.h"
    #include "spider/Spider_00_F0.h"
    #include "spider/Spider_00_F1.h"
    #include "spider/Spider_01_F0.h"
    #include "spider/Spider_01_F1.h"
    #include "spider/Spider_02_F0.h"
    #include "spider/Spider_02_F1.h"
    #include "spider/Spider_03_F0.h"
    #include "spider/Spider_03_F1.h"
    #include "spider/Spider_04_F0.h"
    #include "spider/Spider_04_F1.h"
    #include "spider/Spider_05_F0.h"
    #include "spider/Spider_05_F1.h"
    #include "spider/Spider_06_F0.h"
    #include "spider/Spider_06_F1.h"
    #include "spider/Spider_07_F0.h"
    #include "spider/Spider_07_F1.h"
    #include "bigspider/Spider_16_00_F0.h"
    #include "bigspider/Spider_16_00_F1.h"
    #include "bigspider/Spider_16_01_F0.h"
    #include "bigspider/Spider_16_01_F1.h"
    #include "bigspider/Spider_16_02_F0.h"
    #include "bigspider/Spider_16_02_F1.h"
    #include "bigspider/Spider_16_03_F0.h"
    #include "bigspider/Spider_16_03_F1.h"
    #include "bigspider/Spider_16_04_F0.h"
    #include "bigspider/Spider_16_04_F1.h"
    #include "bigspider/Spider_16_05_F0.h"
    #include "bigspider/Spider_16_05_F1.h"
    #include "bigspider/Spider_16_06_F0.h"
    #include "bigspider/Spider_16_06_F1.h"
    #include "bigspider/Spider_16_07_F0.h"
    #include "bigspider/Spider_16_07_F1.h"
    #include "newenemy/NewEnemy_00.h"
    #include "newenemy/NewEnemy_01.h"
    #include "newenemy/NewEnemy_02.h"
    #include "newenemy/NewEnemy_03.h"
    #include "newenemy/NewEnemy_04.h"
    #include "newenemy/NewEnemy_05.h"
    #include "newenemy/NewEnemy_06.h"
    #include "newenemy/NewEnemy_07.h"
    #include "spike/Spike_00.h"
    #include "spike/Spike_01.h"
    #include "spike/Spike_02.h"
    #include "spike/Spike_03.h"
    #include "spike/Spike_04.h"
    #include "spike/Spike_05.h"
    #include "spike/Spike_06.h"
    #include "spike/Spike_07.h"
    #include "spike/Spike_08.h"
    #include "HealthBar.h"

    const uint8_t * const Bats[] = { 
        Bat_00,
        Bat_01,
    };

    const uint8_t * const Spiders[] = { 
        Spider_00_F0,
        Spider_00_F1,
        Spider_01_F0,
        Spider_01_F1,
        Spider_02_F0,
        Spider_02_F1,
        Spider_03_F0,
        Spider_03_F1,
        Spider_04_F0,
        Spider_04_F1,
        Spider_05_F0,
        Spider_05_F1,
        Spider_06_F0,
        Spider_06_F1,
        Spider_07_F0,
        Spider_07_F1,
    };

    const uint8_t * const BigSpiders[] = { 
        Spider_16_00_F0,
        Spider_16_00_F1,
        Spider_16_01_F0,
        Spider_16_01_F1,
        Spider_16_02_F0,
        Spider_16_02_F1,
        Spider_16_03_F0,
        Spider_16_03_F1,
        Spider_16_04_F0,
        Spider_16_04_F1,
        Spider_16_05_F0,
        Spider_16_05_F1,
        Spider_16_06_F0,
        Spider_16_06_F1,
        Spider_16_07_F0,
        Spider_16_07_F1,
    };

    const uint8_t * const NewEnemys[] = { 
        NewEnemy_00,
        NewEnemy_01,
        NewEnemy_02,
        NewEnemy_03,
        NewEnemy_04,
        NewEnemy_05,
        NewEnemy_06,
        NewEnemy_07,
    };

    const uint8_t * const Spike[] = { 
        Spike_00,
        Spike_01,
        Spike_02,
        Spike_03,
        Spike_04,
        Spike_05,
        Spike_06,
        Spike_07,
        Spike_08,
    };

};