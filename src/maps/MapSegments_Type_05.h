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


const uint8_t MAP_Segment_Type05_00[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38,38,38,38,38,38,38,38,  // 0
    38,38,38,38,38,38,38,38,38,  // 1
    38,38,38,38,38,38,38,38,38,  // 2
    24,24,24,24,24,24,24,24,24,  // 3
     0, 0, 0, 0, 0, 0, 0, 0, 0,  // 4
    22,22,22,22,22,22,22,22,22,  // 5
    38,38,38,38,38,38,38,38,38,  // 6
    38,38,38,38,38,38,38,38,38,  // 7
    38,38,38,38,38,38,38,38,38,  // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    2,
    1,MapTiles::NewCornerLR,1,3,
    1,MapTiles::NewCornerFillLR,1,2,
    1,MapTiles::NewStraightBOT,2,2,
    1,MapTiles::NewCornerFillLL,3,2,
    1,MapTiles::NewCornerLL,3,3,
    1,MapTiles::NewCornerTR,5,5,
    1,MapTiles::NewCornerFillUR,5,6,
    1,MapTiles::NewStraightTOP,6,6,
    1,MapTiles::NewCornerFillUL,7,6,
    1,MapTiles::NewCornerTL,7,5,
    1,MapTiles::SwitchOn,2,3,
    1,MapTiles::SwitchOn,6,5,
    1,MapTiles::NewSpearDoorLHS,4,4,
    END_OF_OPTIONS,

    1,2,3,4,4,
    1,6,5,4,4,
    END_OF_OPTIONS,

    // Enemy Options ---------------------
    2,
    0,Object::Coin,0,4,0,
    1,Object::Coin,8,4,0,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    2,
    1,4,
    7,4,
};


const uint8_t MAP_Segment_Type05_01[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38,38,38,38,38,38,38,38,  // 0
    38, 0,24,24,24,24,24, 0,38,  // 1
    38,21, 0, 0, 0, 0, 0,23,38,  // 2
    24,35, 0, 0, 0, 0, 0,34,24,  // 3
     0, 0, 0, 0, 0, 0, 0, 0, 0,  // 4
    22,36, 0, 0, 0, 0, 0,37,22,  // 5
    38,21, 0, 0, 0, 0, 0,23,38,  // 6
    38, 0,22,22,22,22,22, 0,38,  // 7
    38,38,38,38,38,38,38,38,38,  // 8

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
    1,Object::Chicken,6,6,0,
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

const uint8_t MAP_Segment_Type05_02[] = {
  // 0  1  2  3  4  5  6  7  8
     0,24,24,24,24,24,24,24, 0, // 0
    21, 0, 0, 0, 0, 0, 0, 0,23, // 1
    21, 0, 0, 0, 0, 0,45, 0,23, // 2
    24,44,36, 0, 0, 0,43, 0,34, // 3
     0, 0,43, 0, 0, 0,43, 0, 0, // 4
    36, 0,43, 0, 0, 0,34,44,22, // 5
    21, 0,46, 0, 0, 0, 0, 0,23, // 6
    21, 0, 0, 0, 0, 0, 0, 0,23, // 7
     0,22,22,22,22,22,22,22, 0, // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    2,

    // Tilemap Options -------------------
    // Opt, Tile, x, y
    0,MapTiles::SwitchOn,1,1,
    0,MapTiles::SwitchOn,7,7,
    0,MapTiles::NewStraightLHS,2,4,
    0,MapTiles::NewEndTRB,3,4,
    0,MapTiles::NewSpearDoorTOP,4,4,
    0,MapTiles::NewEndTBL,5,4,
    0,MapTiles::NewStraightRHS,6,4,

    1,MapTiles::NewFill,0,0,
    1,MapTiles::NewFill,0,1,
    1,MapTiles::NewFill,0,2,
    1,MapTiles::NewFill,1,0,
    1,MapTiles::NewFill,1,1,
    1,MapTiles::NewFill,1,2,
    1,MapTiles::NewCornerFillLR,2,0,
    1,MapTiles::NewStraightRHS,2,1,
    1,MapTiles::NewStraightRHS,2,2,
    1,MapTiles::NewStraightRHS,2,3,
    1,MapTiles::NewStraightBOT,1,3,
    1,MapTiles::NewFill,7,6,
    1,MapTiles::NewFill,7,7,
    1,MapTiles::NewFill,7,8,
    1,MapTiles::NewFill,8,6,
    1,MapTiles::NewFill,8,7,
    1,MapTiles::NewFill,8,8,
    1,MapTiles::NewCornerFillUL,6,8,
    1,MapTiles::NewStraightLHS,6,5,
    1,MapTiles::NewStraightLHS,6,6,
    1,MapTiles::NewStraightLHS,6,7,
    1,MapTiles::NewStraightTOP,7,5,
    END_OF_OPTIONS,

    // Environment Options ---------------
    // Opt, Source x, y, Dest x, y 

    0,1,1,4,4,
    0,7,7,4,4,
    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    2,
    0,Object::Bat,3,2,40,
    0,Object::Bat,5,6,40,
    0,Object::Coin,3,1,0,
    1,Object::Spider,3,2,40,
    1,Object::Bat,5,6,40,
    1,Object::Coin,3,1,0,
    1,Object::Coin,5,7,0,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    2,
    4,1,
    4,7,

};


const uint8_t MAP_Segment_Type05_03[] = {
//   0  1  2  3  4  5  6  7  8
    38,38, 0,24,24, 0, 0,24, 0, // 0
    38,38,21,11, 0,23,35,11,23, // 1
     0,24,24,36, 0,46, 0, 0,23, // 2
    35, 0, 0,43, 0,58, 0, 0,34, // 3
     0, 0, 0,46, 0,45, 0, 0, 0, // 4
    36, 0, 0,57, 0,43, 0, 0,37, // 5
    21, 0, 0,45, 0,34,22,22, 0, // 6
    21,11,37,21, 0,11,23,38,38, // 7
     0,22, 0, 0,22,22, 0,38,38, // 8
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
    0,3,1,3,5,
    0,7,1,5,3,
    0,5,7,5,3,
    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    0,

    // Entrance / Exit Options -----------
    2,
    6,5,
    2,3,

};
