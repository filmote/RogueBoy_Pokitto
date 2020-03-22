#pragma once

#include "Pokitto.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

/*
   MAP DEFINITIONS
   0 - Closed_chest
   1 - Blank_Wall
   2 - Locked_Door
   3 - Stairs_Down
   4 - Barrel
   5 - Open_chest
   6 - Open_Door
   7 - Full_Block_Wall
   8 - Blank Space
   9 - Stairs_UP
   10 - MapTiles::SwitchOn
   11 - MapTiles::SwitchOff
   12 - Wall_Torch
   13 - Window_Wall
   14 - Sign_wall
   15 - Spear_Door
   16 - Explosive_barrel
   17 - Locked_Stairs_Down
   18 - MapTiles::Rubble

*/


// -----------------------------------------------------------------------------

// const uint8_t MAP_1[] = {
//     /* Map Size */   4, 4,
//     /* Player Pos */ 0, 0,
//     9,8,8,8,
//     8,8,8,8,
//     8,8,8,8,
//     8,8,8,3,
//     /* Object Count */ 4,
//     Object::Coin, 1, 1, 0,
//     Object::Coin, 1, 2, 0,
//     Object::Coin, 2, 2, 0,
//     Object::Coin, 2, 1, 0,
//     /* Environment Count */ 0,
// };

const uint8_t MAP_Test[] = {
    /* Map Size */   12, 9,
    /* Player Pos */ 0, 0,
    /* Timner */     200,
    9,8,8,8, 8,19,8,8, 8,8,8,8, 
    8,8,8,8, 8,8,8,8, 8,8,8,8, 
    8,8,8,8, 8,8,8,8, 8,8,8,8, 

    8,8,8,8, 8,8,8,8, 8,8,8,8, 
    8,8,8,8, 8,8,8,8, 8,8,8,8, 
    8,8,8,8, 8,8,8,8, 8,8,8,8, 

    8,8,8,8, 8,8,8,8, 8,8,8,8, 
    8,8,8,8, 8,8,8,8, 8,8,8,8, 
    8,8,8,8, 8,8,8,8, 8,8,8,3,

    /* Object Count */ 14,
    Object::Coin, 1, 1, 0,
    Object::Coin, 1, 2, 0,
    Object::Coin, 2, 2, 0,
    Object::Donut, 3, 3, 20,
    Object::Key, 4, 3, 20,
    Object::Potion, 5, 3, 20,

    Object::Donut, 10, 3, 20,
    Object::Ham, 11, 3, 20,
    Object::Spanner, 5, 5, 20,

    Object::Ham, 11, 4, 20,
    Object::Ham, 11, 5, 20,
    Object::Ham, 11, 6, 20,
    Object::Ham, 11, 7, 20,
    Object::Donut, 9, 8, 20,

    /* Environment Count */ 1,

};

// -----------------------------------------------------------------------------

const uint8_t MAP_1[] = {
    /* Map Size */   4, 4,
    /* Player Pos */ 0, 0,
    /* Timner */     255,
    9,8,8,8,
    8,8,8,8,
    8,8,8,8,
    8,8,8,3,
    /* Object Count */ 4,
    Object::Coin, 1, 1, 0,
    Object::Coin, 1, 2, 0,
    Object::Coin, 2, 2, 0,
    Object::Coin, 2, 1, 0,
    /* Environment Count */ 0,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_2[] = {
    /* Map Size */   7,5,
    /* Player Pos */ 0,0,
    /* Timner */     255,
    9,8,8,8,8,8,8,
    8,8,8,4,4,8,8,
    8,8,8,0,4,8,4,
    4,8,8,8,8,8,4,
    4,4,8,8,8,8,17,
    /* Object Count */ 0,
    /* Environment Count */ 0,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_3[] = {
    /* Map Size */   9,6,
    /* Player Pos */ 3,0,
    /* Timner */     255,
    4,8,8,9,8,8,8,1,1,
    8,8,8,8,8,8,8,2,8,
    11,8,8,8,8,8,8,1,8,
    1,1,15,1,15,1,1,1,11,
    1,1,8,1,8,1,1,1,1,
    1,1,0,1,3,1,1,1,1,
    /* Object Count */ 2,
    Object::Spider,8,2,1,
    Object::Bat,2,4,20,
    /* Environment Count */ 2,
    0,2,2,3,
    8,3,4,3,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_4[] = {
    /* Map Size */   9,7,
    /* Player Pos */ 4,0,
    /* Timner */     255,
    4,4,8,8,9,4,8,4,4,
    4,8,8,8,11,8,8,8,4,
    8,8,4,8,8,8,4,8,8,
    1,16,1,15,1,15,1,15,1,
    1,8,1,8,1,8,1,8,1,
    1,8,1,8,1,8,1,8,1,
    1,17,1,11,1,0,1,11,1,
    /* Object Count */ 1,
    Object::Spider,3,5,1,
    /* Environment Count */ 4,
    4,1,3,3,
    7,6,5,3,
    3,6,7,3,
    7,6,1,3,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_5[] = {
    /* Map Size */   10,10,
    /* Player Pos */ 0,0,
    /* Timner */     255,
    9,8,8,8,8,6,8,8,8,1,
    8,8,8,4,1,1,1,1,6,1,
    1,1,1,1,1,8,2,8,8,1,
    8,8,8,8,2,8,1,8,8,0,
    1,1,1,1,1,8,1,1,1,1,
    1,8,8,0,1,8,8,1,1,1,
    1,8,1,1,8,8,8,1,1,1,
    1,8,8,8,8,8,8,1,1,1,
    1,1,1,1,1,8,1,1,1,17,
    1,1,1,1,1,8,8,8,8,8,
    /* Object Count */ 14,
    Object::Floater,5,6,20,
    Object::Bat,6,6,20,
    Object::Bat,6,7,20,
    Object::Bat,5,7,20,
    Object::Bat,4,7,20,
    Object::Bat,4,6,20,
    Object::Spider,7,2,20,
    Object::Spider,8,3,20,
    Object::Bat,7,3,20,
    Object::Donut,8,2,20,
    Object::SackOCash,1,3,20,
    Object::SackOCash,2,3,20,
    Object::SackOCash,3,3,20,
    Object::Key,0,3,20,
    /* Environment Count */ 0,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_6[] = {
    /* Map Size */   9,10,
    /* Player Pos */ 2,0,
    /* Timner */     255,
    12,1,9,1,13,1,1,13,1,
    4,8,8,8,11,1,8,4,1,
    1,1,15,1,1,1,4,8,1,
    8,8,8,8,8,8,8,8,1,
    12,1,16,1,1,1,8,4,1,
    8,8,8,8,8,1,4,4,1,
    8,8,17,8,8,1,4,11,1,
    1,1,1,1,1,1,16,16,1,
    1,1,1,1,1,1,8,8,1,
    1,1,1,1,1,1,8,0,1,
    /* Object Count */ 6,
    Object::Skull,6,9,10,
    Object::Spider,7,8,10,
    Object::Skull,6,8,10,
    Object::Spider,6,9,30,
    Object::Skull,6,8,30,
    Object::Spider,7,8,30,
    /* Environment Count */ 4,
    4,1,2,2,
    7,6,7,7,
    7,6,6,7,
    7,6,2,4,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_7[] = {
    /* Map Size */   10,10,
    /* Player Pos */ 0,0,
    /* Timner */     255,
    9,8,8,1,8,8,8,8,8,1,
    8,8,1,1,8,8,1,8,8,1,
    1,4,1,8,8, 1,1,8,1,1,
    8,8,8,8,8,1,8,8,1,1,
    8,8,1,1,1,1,8,8,8,8,
    1,1,1,8,8,8,8,1,8,8,
    1,1,8,8,8,8,1,1,1,8,
    1,8,8,8,8,1,1,8,8,8,
    1,8,8,1,1,1,8,8,8,1,
    1,17,8,1,1,8,8,8,1,1,
    /* Object Count */ 10,
    Object::Key,5,9,30,
    Object::Spider,1,4,30,
    Object::Spider,0,4,30,
    Object::Spider,0,3,30,
    Object::Bat,7,0,30,
    Object::Bat,8,1,30,
    Object::Skull,7,8,30,
    Object::Floater,2,8,30,
    Object::Floater,1,7,30,
    Object::Floater,8,7,30,
    /* Environment Count */ 0,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_8[] = {
    /* Map Size */   10,10,
    /* Player Pos */ 0,0,
    /* Timner */     255,
    9,1,1,8,8,2,8,8,8,8,
    8,1,8,8,1,1,1,1,1,8,
    8,8,8,1,1,1,1,1,1,8,
    1,8,1,8,1,1,8,8,8,8,
    1,8,1,8,1,1,8,8,8,8,
    8,8,8,8,1,1,8,8,8,8,
    4,1,8,1,1,1,1,1,1,1,
    8,1,8,8,8,1,1,1,1,1,
    8,1,1,1,2,1,1,1,1,1,
    8,1,1,1,3,1,1,1,1,1,
    /* Object Count */ 9,
    Object::Key,0,9,1,
    Object::Floater,3,3,30,
    Object::Skull,3,3,30,
    Object::Key,3,3,1,
    Object::Floater,9,3,100,
    Object::SackOCash,6,4,1,
    Object::SackOCash,7,4,1,
    Object::SackOCash,8,4,1,
    Object::SackOCash,9,4,1,
    /* Environment Count */ 0,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_9[] = {
    /* Map Size */   9,9,
    /* Player Pos */ 5,8,
    /* Timner */     255,
    10,8,8,1,8,8,8,8,8,
    8,8,8,1,8,1,1,1,8,
    1,8,13,1,6,1,1,1,8,
    8,8,8,15,8,8,8,1,8,
    1,1,1,1,8,8,11,1,8,
    8,8,8,6,8,8,8,1,8,
    15,13,1,1,1,1,12,1,8,
    8,8,8,8,1,8,8,8,8,
    8,8,8,17,1,9,8,8,8,
    /* Object Count */ 5,
    Object::Key,1,1,30,
    Object::Bat,1,1,30,
    Object::Skull,5,4,30,
    Object::Spider,8,3,30,
    Object::Spider,5,0,30,
    /* Environment Count */ 5,
    6,4,4,2,
    6,4,3,3,
    6,4,3,5,
    0,0,3,5,
    0,0,0,6,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_10[] = {
    /* Map Size */   7,7,
    /* Player Pos */ 0,0,
    /* Timner */     255,
    9,8,8,8,1,8,8,
    8,8,8,8,4,8,8,
    8,8,8,8,1,8,8,
    8,8,8,17,1,8,8,
    1,4,1,1,1,1,1,
    8,8,8,8,1,1,1,
    8,8,8,8,1,1,1,
    /* Object Count */ 15,
    Object::Coin, 1,1,10,
    Object::Coin, 1,2,10,
    Object::Coin, 2,2,10,
    Object::Coin, 2,1,10,
    Object::Key,3,6,10,
    Object::Spider,3,6,50,
    Object::Spider,2,6,50,
    Object::Spider,1,6,50,
    Object::Spider,0,6,50,
    Object::Skull,6,3,50,
    Object::Skull,6,2,50,
    Object::Skull,6,1,50,
    Object::Skull,6,0,50,
    Object::Coin, 6,0,50,
    Object::Coin, 6,1,50,
    /* Environment Count */ 0,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_11[] = {
    /* Map Size */   10,6,
    /* Player Pos */ 1,1,
    /* Timner */     255,
    8,8,8,1,1,1,0,1,3,1,
    8,9,8,2,8,8,4,1,8,1,
    8,8,8,1,8,8,1,1,8,8,
    1,4,1,1,1,2,1,1,1,8,
    8,8,8,1,8,8,8,8,8,8,
    8,8,8,1,1,8,1,1,1,1,
    /* Object Count */ 11,
    Object::Donut,1,5,20,
    Object::Spider,2,4,20,
    Object::Spider,0,4,20,
    Object::Bat,5,1,20,
    Object::Key,0,5,20,
    Object::Bat,4,2,20,
    Object::Bat,5,5,20,
    Object::Spider,4,4,20,
    Object::Skull,7,4,20,
    Object::Floater,8,2,20,
    Object::Skull,9,4,20,
    /* Environment Count */ 0,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_12[] = {
    /* Map Size */   2,10,
    /* Player Pos */ 0,0,
    /* Timner */     255,
    8,11,
    8,11,
    8,11,
    8,11,
    8,1,
    15,1,
    15,1,
    15,8,
    15,1,
    17,1,
    /* Object Count */ 3,
    Object::Key,1,7,40,
    Object::Bat,1,7,40,
    Object::Bat,1,7,40,
    /* Environment Count */ 4,
    1,3,0,7,
    1,1,0,6,
    1,1,0,5,
    1,3,0,8,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_13[] = {
    /* Map Size */   9,10,
    /* Player Pos */ 3,1,
    /* Timner */     255,
    4,4,4,4,1,1,12,1,1,
    4,7,4,8,8,8,8,1,3,
    4,4,8,8,7,8,8,15,8,
    1,12,1,1,1,8,1,1,12,
    1,8,8,8,1,8,4,8,8,
    1,8,1,2,1,1,1,1,8,
    1,8,1,8,4,8,8,8,8,
    1,8,12,1,1,8,1,1,12,
    1,8,8,11,1,8,8,4,0,
    1,12,1,1,1,1,12,1,1,
    /* Object Count */ 7,
    Object::Skull,7,4,20,
    Object::Skull,7,4,20,
    Object::Spider,6,8,20,
    Object::Spider,6,8,20,
    Object::Spider,6,8,20,
    Object::Bat,1,8,20,
    Object::Floater,1,8,20,
    /* Environment Count */ 1,
    3,8,7,2,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_14[] = {
    /* Map Size */   9,9,
    /* Player Pos */ 4,4,
    /* Timner */     255,
    8,8,8,8,8,8,8,8,8,
    8,7,8,7,8,7,8,7,8,
    8,8,8,8,8,8,8,8,8,
    8,7,8,7,8,7,8,7,8,
    8,8,8,8,8,8,8,8,8,
    8,7,8,7,8,7,8,7,8,
    8,8,8,8,8,8,8,8,8,
    8,7,8,7,17,7,8,7,8,
    8,8,8,8,8,8,8,8,8,
    /* Object Count */ 15,
    Object::Bat, 7,2,100,
    Object::Bat,6,1,100,
    Object::Bat,4,1,100,
    Object::Bat,2,1,100,
    Object::Bat,1,2,100,
    Object::Bat,1,4,100,
    Object::Bat,1,6,100,
    Object::Bat,2,7,100,
    Object::SackOCash,0,8,100,
    Object::Bat,6,7,100,
    Object::Bat,7,6,100,
    Object::Bat,7,4,100,
    Object::Key,0,0,100,
    Object::SackOCash,8,0,100,
    Object::Coin, 8,8,100,
    /* Environment Count */ 0,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_15[] = {
    /* Map Size */   10,9,
    /* Player Pos */ 5,4,
    /* Timner */     255,
    1,1,1,1,8,8,1,1,1,1,
    8,8,8,1,8,8,1,8,8,8,
    16,16,16,1,8,8,1,16,16,16,
    8,8,8,1,1,1,1,8,8,8,
    17,8,14,6,8,8,6,14,8,17,
    8,8,8,1,1,1,1,8,8,8,
    16,16,16,1,8,8,1,16,16,16,
    8,8,8,1,8,8,1,8,8,8,
    1,1,1,1,8,8,1,1,1,1,
    /* Object Count */ 14,
    Object::Floater,8,7,50,
    Object::Floater,9,7,50,
    Object::Floater,7,7,50,
    Object::Spider,7,1,50,
    Object::Spider,8,1,50,
    Object::Spider,9,1,50,
    Object::Bat,2,1,50,
    Object::Bat,1,1,50,
    Object::Bat,0,1,50,
    Object::Skull,0,7,50,
    Object::Skull,1,7,50,
    Object::Skull,2,7,50,
    Object::Key,1,1,50,
    Object::Key,8,7,50,
    /* Environment Count */ 14,
    2,4,3,4,
    7,4,6,4,
    7,4,7,6,
    7,4,8,6,
    7,4,9,6,
    7,4,7,2,
    7,4,8,2,
    7,4,9,2,
    2,4,2,6,
    2,4,2,2,
    2,4,1,2,
    2,4,0,2,
    2,4,1,6,
    2,4,0,6,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_16[] = {
    /* Map Size */   9,9,
    /* Player Pos */ 4,7,
    /* Timner */     255,
    8,8,15,1,1,1,1,0,8,
    0,1,8,8,14,8,8,1,8,
    1,8,2,8,8,8,2,8,15,
    1,8,8,1,8,1,8,8,1,
    1,14,8,8,1,8,8,14,1,
    1,8,8,1,0,1,8,8,1,
    15,8,1,8,8,8,2,8,1,
    8,1,8,8,9,8,8,1,8,
    3,8,1,1,1,1,1,8,8,
    /* Object Count */ 10,
    Object::Spider,6,4,50,
    Object::Spider,7,3,50,
    Object::Bat,8,0,50,
    Object::Bat,8,0,50,
    Object::Floater,5,1,50,
    Object::Skull,0,0,50,
    Object::Skull,0,0,50,
    Object::Skull,1,3,50,
    Object::Skull,2,4,50,
    Object::Floater,1,5,50,
    /* Environment Count */ 6,
    7,4,6,6,
    7,4,8,2,
    4,1,6,2,
    4,1,2,0,
    1,4,2,2,
    1,4,0,6,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_17[] = {
    /* Map Size */   10,9,
    /* Player Pos */ 1,1,
    /* Timner */     255,
    8,8,8,12,8,8,8,8,8,8,
    8,9,8,1,8,8,1,8,8,8,
    12,1,8,1,8,1,1,8,1,12,
    8,8,8,1,8,8,1,8,8,8,
    14,8,8,16,8,8,12,8,8,8,
    1,1,13,1,1,2,1,1,1,8,
    8,8,8,1,8,8,8,1,8,8,
    8,8,8,15,8,17,8,12,8,8,
    8,8,8,1,8,8,8,1,1,1,
    /* Object Count */ 14,
    Object::Key,9,6,50,
    Object::Spider,4,6,50,
    Object::Spider,6,8,50,
    Object::Skull,7,3,50,
    Object::Skull,5,1,50,
    Object::Bat,0,3,50,
    Object::Bat,1,4,50,
    Object::Bat,9,7,50,
    Object::Bat,8,6,50,
    Object::Floater,8,6,50,
    Object::Key,1,7,50,
    Object::Floater,0,6,30,
    Object::Floater,2,8,30,
    Object::Floater,0,8,30,
    /* Environment Count */ 2,
    0,4,3,4,
    9,0,3,7,
};

// -----------------------------------------------------------------------------

const uint8_t MAP_18[] = {
    /* Map Size */   9,8,
    /* Player Pos */ 4,0,
    /* Timner */     255,
    8,8,8,8,9,8,8,8,8,
    8,14,8,14,8,14,8,14,8,
    8,8,8,8,8,8,8,8,8,
    8,14,8,14,8,14,8,14,8,
    8,8,8,8,8,8,8,8,8,
    8,14,8,14,8,14,8,14,8,
    8,8,8,8,8,8,8,8,8,
    1,1,1,1,17,1,1,1,1,
    /* Object Count */ 0,
    /* Environment Count */ 3,
    7,1,4,7,
    1,3,4,7,
    7,5,4,7,
};
