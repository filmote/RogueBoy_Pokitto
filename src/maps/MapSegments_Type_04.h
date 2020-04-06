#pragma once

#include "Pokitto.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


/* -------------------------------------------------------------------------------------

Type 0       1         2         3         4         5         6         7         8   
.......   .......   .......   .......   .......   .......   .......   .......   .......
.     .   .     .   .  |  .   .  |  .   .  |  .   .     .   .  |  .   .  |  .   .     .
.  +--.   .--+  .   .  +--.   .--+  .   .  |  .   .-----.   .--+--.   .  +--.   .--+--.
.  |  .   .  |  .   .     .   .     .   .  |  .   .     .   .     .   .  |  .   .  |  .
.......   .......   .......   .......   .......   .......   .......   .......   .......

Type 9       10        11        12        13        14        15
.......   .......   .......   .......   .......   .......   .......    
.  |  .   .  |  .   .     .   .  |  .   .     .   .     .   .     .   
.--+  .   .--+--.   .  o  .   .  o  .   .--o  .   .  o--.   .  ?  .   
.  |  .   .  |  .   .  |  .   .     .   .     .   .     .   .     .   
.......   .......   .......   .......   .......   .......   ....... 

*/


const uint8_t MAP_Segment_Type04_00[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38,38,21, 0,23,38,38,38,  // 0
    38,38,38,21, 0,23,38,38,38,  // 1
    38,38,38,21, 0,23,38,38,38,  // 2
    38,38,38,21, 0,23,38,38,38,  // 3
    38,38,38,21, 0,23,38,38,38,  // 4
    38,38,38,21, 0,23,38,38,38,  // 5
    38,38,38,21, 0,23,38,38,38,  // 6
    38,38,38,21, 0,23,38,38,38,  // 7
    38,38,38,21, 0,23,38,38,38,  // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    2,
    1,MapTiles::NewCornerLL,5,1,
    1,MapTiles::NewCornerFillLL,6,1,
    1,MapTiles::NewStraightLHS,6,2,
    1,MapTiles::NewCornerFillUL,6,3,
    1,MapTiles::NewCornerTL,5,3,
    1,MapTiles::NewCornerLR,3,5,
    1,MapTiles::NewCornerFillLR,2,5,
    1,MapTiles::NewStraightRHS,2,6,
    1,MapTiles::NewCornerFillUR,2,7,
    1,MapTiles::NewCornerTR,3,7,
    1,MapTiles::SwitchOn,5,2,
    1,MapTiles::SwitchOn,3,6,
    1,MapTiles::NewSpearDoorBOT,4,4,
    END_OF_OPTIONS,

    1,5,2,4,4,
    1,3,6,4,4,
    END_OF_OPTIONS,

    // Enemy Options ---------------------
    2,
    0,Object::Coin,4,0,0,
    0,Object::Coin,4,8,0,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    2,
    4,1,
    4,7,
};


const uint8_t MAP_Segment_Type04_01[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38,38,21, 0,23,38,38,38,  // 0
    38,29,24,35, 0,34,24,30,38,  // 1
    38,21, 0, 0, 0, 0, 0,23,38,  // 2
    38,21, 0, 0, 0, 0, 0,23,38,  // 3
    38,21, 0, 0, 0, 0, 0,23,38,  // 4
    38,21, 0, 0, 0, 0, 0,23,38,  // 5
    38,21, 0, 0, 0, 0, 0,23,38,  // 6
    38,31,22,36, 0,37,22,32,38,  // 7
    38,38,38,21, 0,23,38,38,38,  // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    0,

    // Enemy Options ---------------------
    3,
    0,Object::Coin,2,2,0,
    0,Object::Coin,3,2,0,
    0,Object::Coin,2,3,0,
    0,Object::Spider,6,5,40,
    0,Object::Spider,5,6,40,
    1,Object::Ham,6,6,0,
    1,Object::Spider,2,2,60,
    1,Object::Bat,3,2,40,
    1,Object::Bat,2,3,40,
    2,Object::SackOCash,5,2,0,
    2,Object::Spider,2,6,60,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    1,
    4,4,
};

const uint8_t MAP_Segment_Type04_02[] = {
//   0  1  2  3  4  5  6  7  8
    29,24,24,21, 0,34,24,24,30, // 0
    21, 0, 0,43, 0, 0, 0, 0,23, // 1
    21, 0, 0,34,44,44,48, 0,23, // 2
    21, 0, 0, 0, 0, 0, 0, 0,23, // 3
    21, 0, 0, 0, 0, 0, 0, 0,23, // 4
    21, 0, 0, 0, 0, 0, 0, 0,23, // 5
    21, 0,47,44,44,36, 0, 0,23, // 6
    21, 0, 0, 0, 0,43, 0, 0,23, // 7
    31,22,22,36, 0,23,22,22,32, // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    2,

    // Tilemap Options -------------------
    // Opt, Tile, x, y
    0,MapTiles::SwitchOn,1,1,
    0,MapTiles::SwitchOn,7,7,
    0,MapTiles::NewStraightTOP,4,2,
    0,MapTiles::NewEndRBL,4,3,
    0,MapTiles::NewSpearDoorLHS,4,4,
    0,MapTiles::NewEndTRL,4,5,
    0,MapTiles::NewStraightTOP,4,6,
    END_OF_OPTIONS,

    // Environment Options ---------------
    // Opt, Source x, y, Dest x, y 

    0,1,1,4,4,
    0,7,7,4,4,
    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    0,

    // Entrance / Exit Options -----------
    4,
    2,1,
    1,4,
    7,4,
    6,7,

};


const uint8_t MAP_Segment_Type04_03[] = {
//   0  1  2  3  4  5  6  7  8
    38,38,29,35, 0,34,24,24,30, // 0
    38,38,21, 0, 0, 0, 0,11,23, // 1
    29,24,21, 0, 0, 0, 0,37,32, // 2
    21,11,34,44,48,59,47,24,30, // 3
    21, 0, 0, 0, 0, 0, 0, 0,23, // 4
    31,22,48,60,47,44,36,11,23, // 5
    29,35, 0, 0, 0, 0,23,22,32, // 6
    21,11, 0, 0, 0, 0,23,38,38, // 7
    31,22,22,36, 0,37,32,38,38, // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    1,

    // Tilemap Options -------------------
    // Opt, Tile, x, y
    END_OF_OPTIONS,

    // Environment Options ---------------
    // Opt, Source x, y, Dest x, y 

    0,1,7,3,5,
    0,7,5,5,3,
    0,1,3,3,5,
    0,7,1,5,3,
    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    0,

    // Entrance / Exit Options -----------
    2,
    5,6,
    3,2,

};
