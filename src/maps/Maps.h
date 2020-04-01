#pragma once

#include "Pokitto.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


// -----------------------------------------------------------------------------

const uint8_t MAP_Test[] = {
    /* Map Size */   20, 20,
    /* Player Pos */ 2, 15,
    /* Timer */     200,

    29,24,24,24,24, 24,24,24,24,24, 24,24,24,24,24, 24,24,24,24,30,
    21,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,23,
    21,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,23,
    21,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,23,
    21,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,23,

    21,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,23,
    21,0,0,37,22, 22,22,36,0,0, 0,0,0,0,0, 0,0,0,0,23,
    21,0,0,23,0, 0,0,21,0,0, 0,0,0,0,0, 0,0,0,0,23,
    21,0,0,23,0, 24,24,35,0,0, 0,0,0,0,0, 0,0,0,0,23,
    21,0,0,34,25, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,23,

    21,0,0,0,0, 28,22,27,0,0, 0,0,0,0,0, 0,0,0,0,23,
    21,0,0,0,0, 23,0,21,0,0, 0,0,0,0,0, 0,0,0,0,23,
    31,22,22,27,0, 26,24,25,0,0, 0,0,0,0,0, 0,0,0,0,23,
    0,29,24,30,27, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,23,
    0,25,0,26,30, 27,0,28,22,22, 27,0,0,0,0, 0,0,0,0,23,

    21,0,9,0,65, 21,0,23,0,0, 21,0,19,37,44, 44,44,44,44,52,
    21,0,0,28,32, 21,0,23,0,29, 25,0,11,43,0, 0,0,0,0,23,
    21,0,0,34,24, 35,0,34,24,25, 0,0,0,34,44, 48,0,0,0,23,
    // 21,27,0,28,32, 21,0,23,0,29, 25,0,0,0,0, 0,0,0,0,23,
    // 21,0,22,39,24, 35,0,34,24,25, 0,0,0,0,0, 0,0,0,0,23,

    31,27,0,0,0, 0,0,0,0,0, 0,0,0,57,0, 39,0,3,28,32,
    0,31,22,22,22, 22,22,22,22,22, 22,22,22,22,22, 22,22,22,32,0,

    /* Object Count */ 7,
    Object::Key, 5, 18, 0,
    Object::Coin, 6, 18, 0,
    Object::Donut, 7, 18, 0,
    Object::Ham, 8, 18, 0,
    Object::SackOCash, 9, 18, 0,
    Object::Spanner, 10, 18, 0,
    Object::Potion, 11, 18, 0,
    /* Environment Count */ 2,
    12,15,13,18,
    12,16,13,18,

};


// -----------------------------------------------------------------------------

const uint8_t MAP_1[] = {
    /* Map Size */   6, 6,
    /* Player Pos */ 1, 1,
    /* Timer */     255,
    29,24,24,24,24,30,
    21,9,0,0,0,23,
    21,0,0,0,0,23,
    21,0,0,0,0,23,
    21,0,0,0,3,23,
    31,22,22,22,22,32,
    /* Object Count */ 4,
    Object::Coin, 2, 2, 0,
    Object::Coin, 2, 3, 0,
    Object::Coin, 3, 3, 0,
    Object::Coin, 3, 2, 0,
    /* Environment Count */ 0,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_2[] = {
    /* Map Size */   9,7,
    /* Player Pos */ 1,1,
    /* Timner */     255,
    29,24,24,24,68,24,24,24,30,
    21, 9, 0, 0, 0, 0, 0, 0,23,
    21, 0, 0, 0, 4, 4, 0, 0,23,
    66, 0, 0, 0, 8, 4, 0, 4,65,
    21, 4, 0, 0, 0, 0, 0, 4,23,
    21, 4, 4, 0, 0, 0, 0,17,23,
    31,22,22,22,22,22,22,22,32,
    /* Object Count */ 0,
    /* Environment Count */ 0,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_3[] = {
    /* Map Size */   11,8,
    /* Player Pos */ 4,1,
    /* Timer */     255,
    29,24,24,24,24,24,24,24,30,38,30,
    21, 4, 0 ,0, 9, 0, 0, 0,34,24,30,
    21, 0, 0 ,0, 0, 0, 0, 0,39, 0,23,
    21,11, 0, 0, 0, 0, 0,37,36, 0,23,
    31,22,36,59,45,59,37,32,21, 0,23,
    38,38,21, 0,43, 0,23,38,21, 0,23,
    38,38,21, 8,43,03,23,38,21,11,23,
    38,38,31,22,49,22,32,38,31,22,32,
    /* Object Count */ 2,
    Object::Spider,9,3,1,
    Object::Bat,3,5,20,
    /* Environment Count */ 2,
    1,3,3,4,
    9,6,5,4,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_4[] = {
    /* Map Size */   11,9,
    /* Player Pos */ 5,1,
    /* Timer */     255,
    29,24,24,24,24,24,24,24,24,24,30,
    21, 4, 4, 0, 0, 9, 4, 0, 4, 4,23,
    21, 4, 0, 0, 0,11, 0, 0, 0, 4,23,
    21, 0, 0, 4, 0, 0, 0, 4, 0, 0,23,
    31,36, 4,45,59,45,59,45,59,37,32,
    38,21, 0,43, 0,43, 0,43, 0,23,38,
    38,21, 0,43, 0,43, 0,43, 0,23,38,
    38,21,17,43,11,43, 8,43,11,23,38,
    38,31,22,49,22,49,22,49,22,32,38,
    /* Object Count */ 1,
    Object::Spider,4,6,1,
    /* Environment Count */ 4,
    5,2,4,4,
    8,7,6,4,
    4,7,8,4,
    8,7,2,4,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_5[] = {
    /* Map Size */   12,12,
    /* Player Pos */ 1,1,
    /* Timer */     255,
    29,24,24,24,24,24,24,24,24,24,24,30,
    21, 9, 0, 0, 0, 0, 61, 0, 0, 0, 0,23,
    21, 0, 0, 0, 4,37,44,44,48, 0,37,32,
    50,44,44,44,44,35, 0,39, 0, 0,34,30,
    21, 0, 0, 0, 0,40, 0,45, 0, 0, 8,23,
    31,22,44,44,44,36, 0,34,22,22,22,32,
    38,21, 0, 0, 8,43, 0, 0,23,38,38,38,
    38,21, 0,47,44,35, 0, 0,23,38,38,38,
    38,21, 0, 0, 0, 0, 0, 0,23,29,24,30,
    38,31,22,22,22,36, 0,47,24,35,17,23,
    38,38,38,38,38,21, 0, 0, 0, 0, 0,23,
    38,38,38,38,38,31,22,22,22,22,22,32,
    /* Object Count */ 14,
    Object::Floater,6,7,30,
    Object::Bat,7,7,20,
    Object::Bat,7,8,20,
    Object::Bat,6,8,20,
    Object::Bat,5,8,20,
    Object::Bat,4,8,20,
    Object::Spider,8,3,20,
    Object::Spider,9,4,20,
    Object::Bat,8,4,20,
    Object::Donut,9,3,20,
    Object::SackOCash,2,4,20,
    Object::SackOCash,3,4,20,
    Object::SackOCash,4,4,20,
    Object::Key,1,4,20,
    /* Environment Count */ 0,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_6[] = {
    /* Map Size */   11,12,
    /* Player Pos */ 3,1,
    /* Timer */     255,
    1,1,1,1,1,1,1,1,1,1,1,
    1,12,1,9,1,13,1,1,13,1,1,
    1,4,0,0,0,11,1,0,4,1,1,
    1,1,1,59,1,1,1,4,0,1,1,
    1,0,0,0,0,0,0,0,0,1,1,
    1,12,1,16,1,1,1,0,4,1,1,
    1,0,0,0,0,0,1,4,4,1,1,
    1,0,0,17,0,0,1,4,11,1,1,
    1,1,1,1,1,1,1,16,16,1,1,
    1,1,1,1,1,1,1,0,0,1,1,
    1,1,1,1,1,1,1,0,8,1,1,
    1,1,1,1,1,1,1,1,1,1,1,
    /* Object Count */ 6,
    Object::Skull,7,10,10,
    Object::Spider,8,9,10,
    Object::Skull,7,9,10,
    Object::Spider,7,10,30,
    Object::Skull,7,9,30,
    Object::Spider,8,9,30,
    /* Environment Count */ 4,
    5,2,3,3,
    8,7,8,8,
    8,7,7,8,
    8,7,3,5,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_7[] = {
    /* Map Size */   12,12,
    /* Player Pos */ 1,1,
    /* Timer */     255,
    1,1,1,1,1,1,1,1,1,1,1,1,
    1,9,0,0,1,0,0,0,0,0,1,1,
    1,0,0,1,1,0,0,1,0,0,1,1,
    1,1,4,1,0,0, 1,1,0,1,1,1,
    1,0,0,0,0,0,1,0,0,1,1,1,
    1,0,0,1,1,1,1,0,0,0,0,1,
    1,1,1,1,0,0,0,0,1,0,0,1,
    1,1,1,0,0,0,0,1,1,1,0,1,
    1,1,0,0,0,0,1,1,0,0,0,1,
    1,1,0,0,1,1,1,0,0,0,1,1,
    1,1,17,0,1,1,0,0,0,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,
    /* Object Count */ 10,
    Object::Key,6,10,30,
    Object::Spider,2,5,30,
    Object::Spider,1,5,30,
    Object::Spider,1,4,30,
    Object::Bat,8,1,30,
    Object::Bat,9,2,30,
    Object::Skull,8,9,30,
    Object::Floater,3,9,30,
    Object::Floater,2,8,30,
    Object::Floater,9,8,30,
    /* Environment Count */ 0,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_8[] = {
    /* Map Size */   12,12,
    /* Player Pos */ 1,1,
    /* Timer */     255,
    1,1,1,1,1,1,1,1,1,1,1,1,
    1,9,1,1,0,0,39,0,0,0,0,1,
    1,0,1,0,0,1,1,1,1,1,0,1,
    1,0,0,0,1,1,1,1,1,1,0,1,
    1,1,0,1,0,1,1,0,0,0,0,1,
    1,1,0,1,0,1,1,0,0,0,0,1,
    1,0,0,0,0,1,1,0,0,0,0,1,
    1,4,1,0,1,1,1,1,1,1,1,1,
    1,0,1,0,0,0,1,1,1,1,1,1,
    1,0,1,1,1,2,1,1,1,1,1,1,
    1,0,1,1,1,3,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,
    /* Object Count */ 9,
    Object::Key,1,10,1,
    Object::Floater,4,4,30,
    Object::Skull,4,4,30,
    Object::Key,4,4,1,
    Object::Floater,10,4,100,
    Object::SackOCash,7,5,1,
    Object::SackOCash,8,5,1,
    Object::SackOCash,9,5,1,
    Object::SackOCash,10,5,1,
    /* Environment Count */ 0,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_9[] = {
    /* Map Size */   11,11,
    /* Player Pos */ 6,9,
    /* Timer */     255,
    1,1,1,1,1,1,1,1,1,1,1,
    1,10,0,0,1,0,0,0,0,0,1,
    1,0,0,0,1,0,1,1,1,0,1,
    1,1,0,13,1,6,1,1,1,0,1,
    1,0,0,0,59,0,0,0,1,0,1,
    1,1,1,1,1,0,0,11,1,0,1,
    1,0,0,0,6,0,0,0,1,0,1,
    1,59,13,1,1,1,1,12,1,0,1,
    1,0,0,0,0,1,0,0,0,0,1,
    1,0,0,0,17,1,9,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1,1,
    /* Object Count */ 5,
    Object::Key,2,2,30,
    Object::Bat,2,2,30,
    Object::Skull,6,5,30,
    Object::Spider,9,4,30,
    Object::Spider,6,1,30,
    /* Environment Count */ 5,
    7,5,5,3,
    7,5,4,4,
    7,5,4,6,
    1,1,4,6,
    1,1,1,7,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_10[] = {
    /* Map Size */   9,9,
    /* Player Pos */ 1,1,
    /* Timer */     255,
    1,1,1,1,1,1,1,1,1,
    1,9,0,0,0,1,0,0,1,
    1,0,0,0,0,4,0,0,1,
    1,0,0,0,0,1,0,0,1,
    1,0,0,0,17,1,0,0,1,
    1,1,4,1,1,1,1,1,1,
    1,0,0,0,0,1,1,1,1,
    1,0,0,0,0,1,1,1,1,
    1,1,1,1,1,1,1,1,1,
    /* Object Count */ 15,
    Object::Coin,2,2,10,
    Object::Coin,2,3,10,
    Object::Coin,3,3,10,
    Object::Coin,3,2,10,
    Object::Key,4,7,10,
    Object::Spider,4,7,50,
    Object::Spider,3,7,50,
    Object::Spider,2,7,50,
    Object::Spider,1,7,50,
    Object::Skull,7,4,50,
    Object::Skull,7,3,50,
    Object::Skull,7,2,50,
    Object::Skull,7,1,50,
    Object::Coin,7,1,50,
    Object::Coin,7,2,50,
    /* Environment Count */ 0,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_11[] = {
    /* Map Size */   12,8,
    /* Player Pos */ 2,2,
    /* Timer */     255,
    1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,1,1,1,8,1,3,1,1,
    1,0,9,0,2,0,0,4,1,0,1,1,
    1,0,0,0,1,0,0,1,1,0,0,1,
    1,1,4,1,1,1,2,1,1,1,0,1,
    1,0,0,0,1,0,0,0,0,0,0,1,
    1,0,0,0,1,1,0,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,
    /* Object Count */ 11,
    Object::Donut,2,6,20,
    Object::Spider,3,5,20,
    Object::Spider,1,5,20,
    Object::Bat,6,2,20,
    Object::Key,1,6,20,
    Object::Bat,5,3,20,
    Object::Bat,6,6,20,
    Object::Spider,5,5,20,
    Object::Skull,8,5,20,
    Object::Floater,9,3,20,
    Object::Skull,10,5,20,
    /* Environment Count */ 0,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_12[] = {
    /* Map Size */   4,12,
    /* Player Pos */ 1,1,
    /* Timer */     255,
    1,1,1,1,
    1,0,11,1,
    1,0,11,1,
    1,0,11,1,
    1,0,11,1,
    1,0,1,1,
    1,59,1,1,
    1,59,1,1,
    1,59,0,1,
    1,59,1,1,
    1,17,1,1,
    1,1,1,1,
    /* Object Count */ 3,
    Object::Key,2,8,40,
    Object::Bat,2,8,40,
    Object::Bat,2,8,40,
    /* Environment Count */ 4,
    2,4,1,8,
    2,2,1,7,
    2,2,1,6,
    2,4,1,9,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_13[] = {
    /* Map Size */   11,12,
    /* Player Pos */ 4,2,
    /* Timer */     255,
    1,1,1,1,1,1,1,1,1,1,1,
    1,4,4,4,4,1,1,12,1,1,1,
    1,4,7,4,0,0,0,0,1,3,1,
    1,4,4,0,0,7,0,0,57,0,1,
    1,1,12,1,1,1,0,1,1,12,1,
    1,1,0,0,0,1,0,4,0,0,1,
    1,1,0,1,2,1,1,1,1,0,1,
    1,1,0,1,0,4,0,0,0,0,1,
    1,1,0,12,1,1,0,1,1,12,1,
    1,1,0,0,11,1,0,0,4,8,1,
    1,1,12,1,1,1,1,12,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,
    /* Object Count */ 7,
    Object::Skull,8,5,20,
    Object::Skull,8,5,20,
    Object::Spider,7,9,20,
    Object::Spider,7,9,20,
    Object::Spider,7,9,20,
    Object::Bat,2,9,20,
    Object::Floater,2,9,20,
    /* Environment Count */ 1,
    4,9,8,3,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_14[] = {
    /* Map Size */   11,11,
    /* Player Pos */ 5,5,
    /* Timer */     255,
    1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,0,0,0,0,0,1,
    1,0,7,0,7,0,7,0,7,0,1,
    1,0,0,0,0,0,0,0,0,0,1,
    1,0,7,0,7,0,7,0,7,0,1,
    1,0,0,0,0,0,0,0,0,0,1,
    1,0,7,0,7,0,7,0,7,0,1,
    1,0,0,0,0,0,0,0,0,0,1,
    1,0,7,0,7,17,7,0,7,0,1,
    1,0,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1,1,
    /* Object Count */ 15,
    Object::Bat,8,3,100,
    Object::Bat,7,2,100,
    Object::Bat,5,2,100,
    Object::Bat,3,2,100,
    Object::Bat,2,3,100,
    Object::Bat,2,5,100,
    Object::Bat,2,7,100,
    Object::Bat,3,8,100,
    Object::SackOCash,1,9,100,
    Object::Bat,7,8,100,
    Object::Bat,8,7,100,
    Object::Bat,8,5,100,
    Object::Key,1,1,100,
    Object::SackOCash,9,1,100,
    Object::Coin,9,9,100,
    /* Environment Count */ 0,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_15[] = {
    /* Map Size */   12,11,
    /* Player Pos */ 6,5,
    /* Timer */     255,
    1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,0,0,1,1,1,1,1,
    1,0,0,0,1,0,0,1,0,0,0,1,
    1,16,16,16,1,0,0,1,16,16,16,1,
    1,0,0,0,1,1,1,1,0,0,0,1,
    1,17,0,14,6,0,0,6,14,0,17,1,
    1,0,0,0,1,1,1,1,0,0,0,1,
    1,16,16,16,1,0,0,1,16,16,16,1,
    1,0,0,0,1,0,0,1,0,0,0,1,
    1,1,1,1,1,0,0,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,
    /* Object Count */ 14,
    Object::Floater,9,8,50,
    Object::Floater,10,8,50,
    Object::Floater,8,8,50,
    Object::Spider,8,2,50,
    Object::Spider,9,2,50,
    Object::Spider,10,2,50,
    Object::Bat,3,2,50,
    Object::Bat,2,2,50,
    Object::Bat,1,2,50,
    Object::Skull,1,8,50,
    Object::Skull,2,8,50,
    Object::Skull,3,8,50,
    Object::Key,2,2,50,
    Object::Key,9,8,50,
    /* Environment Count */ 14,
    3,5,4,5,
    8,5,7,5,
    8,5,8,7,
    8,5,9,7,
    8,5,10,7,
    8,5,8,3,
    8,5,9,3,
    8,5,10,3,
    3,5,3,7,
    3,5,3,3,
    3,5,2,3,
    3,5,1,3,
    3,5,2,7,
    3,5,1,7,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_16[] = {
    /* Map Size */   11,11,
    /* Player Pos */ 5,8,
    /* Timer */     255,
    1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,59,1,1,1,1,8,0,1,
    1,8,1,0,0,14,0,0,1,0,1,
    1,1,0,2,0,0,0,2,0,59,1,
    1,1,0,0,1,0,1,0,0,1,1,
    1,1,14,0,0,1,0,0,14,1,1,
    1,1,0,0,1,8,1,0,0,1,1,
    1,59,0,1,0,0,0,2,0,1,1,
    1,0,1,0,0,9,0,0,1,0,1,
    1,3,0,1,1,1,1,1,0,0,1,
    1,1,1,1,1,1,1,1,1,1,1,
    /* Object Count */ 10,
    Object::Spider,7,5,50,
    Object::Spider,8,4,50,
    Object::Bat,9,1,50,
    Object::Bat,9,1,50,
    Object::Floater,6,2,50,
    Object::Skull,1,1,50,
    Object::Skull,1,1,50,
    Object::Skull,2,4,50,
    Object::Skull,3,5,50,
    Object::Floater,2,6,50,
    /* Environment Count */ 6,
    8,5,7,7,
    8,5,9,3,
    5,2,7,3,
    5,2,3,1,
    2,5,3,3,
    2,5,1,7,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_17[] = {
    /* Map Size */   12,11,
    /* Player Pos */ 2,2,
    /* Timer */     255,
    1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,12,0,0,0,0,0,0,1,
    1,0,9,0,1,0,0,1,0,0,0,1,
    1,12,1,0,1,0,1,1,0,1,12,1,
    1,0,0,0,1,0,0,1,0,0,0,1,
    1,14,0,0,16,0,0,12,0,0,0,1,
    1,1,1,13,1,1,2,1,1,1,0,1,
    1,0,0,0,1,0,0,0,1,0,0,1,
    1,0,0,0,58,0,17,0,12,0,0,1,
    1,0,0,0,1,0,0,0,1,11,0,1,
    1,1,1,1,1,1,1,1,1,1,1,1,
    /* Object Count */ 14,
    Object::Key,10,8,50,
    Object::Key,2,8,50,
    Object::Spider,5,7,50,
    Object::Spider,7,9,50,
    Object::Skull,8,4,50,
    Object::Skull,6,2,50,
    Object::Bat,1,4,50,
    Object::Bat,2,5,50,
    Object::Bat,10,8,50,
    Object::Bat,9,7,50,
    Object::Floater,9,7,50,
    Object::Floater,1,7,30,
    Object::Floater,3,9,30,
    Object::Floater,1,9,30,
    /* Environment Count */ 3,
    1,5,4,5,
    10,1,4,8,
    9,9,4,8,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_18[] = {
    /* Map Size */   11,10,
    /* Player Pos */ 5,1,
    /* Timer */     255,
    1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,9,0,0,0,0,1,
    1,0,14,0,14,0,14,0,14,0,1,
    1,0,0,0,0,0,0,0,0,0,1,
    1,0,14,0,14,0,14,0,14,0,1,
    1,0,0,0,0,0,0,0,0,0,1,
    1,0,14,0,14,0,14,0,14,0,1,
    1,0,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,17,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,
    /* Object Count */ 0,
    /* Environment Count */ 3,
    8,2,5,8,
    2,4,5,8,
    8,6,5,8,
};
