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

const uint8_t MAP_Segment_Type11_00[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38,38,38,38,38,38,38,38,  // 0
    38,38,38,38,38,38,38,38,38,  // 1
    38,38,38, 0,24, 0,38,38,38,  // 2
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

    // Tilemap Options -------------------
    // Opt, Tile, x, y

    1,MapTiles::NewCornerTR,3,8,
    1,MapTiles::NewCornerFillUR,2,8,
    1,MapTiles::NewStraightRHS,2,7,
    1,MapTiles::NewCornerFillLR,2,6,
    1,MapTiles::NewCornerLR,3,6,
    1,MapTiles::SwitchOn,3,7,
    1,MapTiles::NewSpearDoorBOT,4,6,

    1,MapTiles::NewCornerLL,5,4,
    1,MapTiles::NewCornerFillLL,6,4,
    1,MapTiles::NewStraightLHS,6,5,
    1,MapTiles::NewCornerFillUL,6,6,
    1,MapTiles::NewCornerTL,5,6,
    1,MapTiles::SwitchOn,5,5,
    END_OF_OPTIONS,

    // Environment Options ---------------
    // Opt, Source x, y, Dest x, y 

    1,3,7,4,6,
    1,5,5,4,6,
    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    0,

    // Entrance / Exit Options -----------
    1,
    4,3,

};

const uint8_t MAP_Segment_Type11_01[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38,38,38,38,38,38,38,38,  // 0
    38,38,38,24,24,24,38,38,38,  // 1
    38,38,25, 0, 0, 0,26,38,38,  // 2
    38,21, 0, 0, 0, 0, 0,23,38,  // 3
    38,21, 0, 0, 0, 0, 0,23,38,  // 4
    38,21, 0, 0, 0, 0, 0,23,38,  // 5
    38,38,27, 0, 0, 0,28,38,38,  // 6
    38,38,38,36, 0,37,38,38,38,  // 7
    38,38,38,21, 0,23,38,38,38,  // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    2,

    // Tilemap Options -------------------
    // Opt, Tile, x, y

    0,MapTiles::Barrel,4,2,
    0,MapTiles::Barrel,3,5,
    1,MapTiles::Barrel,5,3,
    1,MapTiles::Barrel,5,4,
    1,MapTiles::Barrel,5,5,
    1,MapTiles::Barrel,4,4,
    END_OF_OPTIONS,

    // Environment Options ---------------
    // Opt, Source x, y, Dest x, y 

    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    2,
    0,Object::Bat, 3, 2, 20,
    1,Object::Spider, 3, 2, 40,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    1,
    4,4,

};

const uint8_t MAP_Segment_Type11_02[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38,38, 0,24,24,24,24, 0,  // 0
    38,38,38,21, 0, 0, 0, 0,23,  // 1
     0,24,24,24,44,44,48, 0,23,  // 2
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 3
    21, 0,47,44,44,44,44,44, 0,  // 4
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 5
     0,22,22,22,44,44,48, 0,23,  // 6
    38,38,38,21, 0, 0, 0, 0,23,  // 7
    38,38,38,21, 0,37,22,22, 0,  // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    0,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    2,
    0,Object::Bat,1,3,20,
    0,Object::Bat,1,5,20,
    1,Object::Spider,1,4,40,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    1,
    4,1,

};


const uint8_t MAP_Segment_Type11_03[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38,38,38,38,38,38,38,38,  // 0
    38,38, 0,24,24,24, 0,38,38,  // 1
    38,38,21, 0, 0, 0,23,38,38,  // 2
     0,24,35, 0, 0, 0,23,38,38,  // 3
    21, 0, 0, 0, 0, 0,23,38,38,  // 4
    21, 0,45, 0, 0, 0,23,38,38,  // 5
    21, 0,34,44,44,22, 0,38,38,  // 6
    21, 0, 0, 0, 0,23,38,38,38,  // 7
     0,22,22,36, 0,23,38,38,38,  // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    2,

    // Tilemap Options -------------------
    // Opt, Tile, x, y

    0,MapTiles::Barrel,3,2,
    0,MapTiles::Barrel,5,2,
    1,MapTiles::Barrel,3,5,
    1,MapTiles::Barrel,5,5,
    END_OF_OPTIONS,

    // Environment Options ---------------
    // Opt, Source x, y, Dest x, y 

    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    1,
    0,Object::Bat,2,4,20,
    0,Object::Spider,1,7,40,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    1,
    4,4,

};