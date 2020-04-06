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


const uint8_t MAP_Segment_Type12_00[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38,38,21, 0,23,38,38,38,  // 0
    38,38,38,21, 0,23,38,38,38,  // 1
    38,38,38,21, 0,23,38,38,38,  // 2
    38,38,38,21, 0,23,38,38,38,  // 3
    38,38,38,21, 0,23,38,38,38,  // 4
    38,38,38,21, 0,23,38,38,38,  // 5
    38,38,38,31,22,32,38,38,38,  // 6
    38,38,38,38,38,38,38,38,38,  // 7
    38,38,38,38,38,38,38,38,38,  // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    2,

    // Tilemap Options -------------------
    // Opt, Tile, x, y

    1,MapTiles::NewCornerTR,3,5,
    1,MapTiles::NewCornerFillUR,2,5,
    1,MapTiles::NewStraightRHS,2,4,
    1,MapTiles::NewCornerFillLR,2,3,
    1,MapTiles::NewCornerLR,3,3,
    1,MapTiles::SwitchOn,3,4,
    1,MapTiles::NewSpearDoorTOP,4,3,

    1,MapTiles::NewCornerLL,5,0,
    1,MapTiles::NewCornerFillLL,6,0,
    1,MapTiles::NewStraightLHS,6,1,
    1,MapTiles::NewCornerFillUL,6,2,
    1,MapTiles::NewCornerTL,5,2,
    1,MapTiles::SwitchOn,5,1,
    END_OF_OPTIONS,

    // Environment Options ---------------
    // Opt, Source x, y, Dest x, y 

    1,3,4,4,3,
    1,5,1,4,3,
    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    0,

    // Entrance / Exit Options -----------
    1,
    4,5,

};

const uint8_t MAP_Segment_Type12_01[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38,38,21, 0,23,38,38,38,  // 0
    38,38,38,35, 0,34,38,38,38,  // 1
    38,38,25, 0, 0, 0,26,38,38,  // 2
    38,21, 0, 0, 0, 0, 0,23,38,  // 3
    38,21, 0, 0, 0, 0, 0,23,38,  // 4
    38,21, 0, 0, 0, 0, 0,23,38,  // 5
    38,38,27, 0, 0, 0,28,38,38,  // 6
    38,38,38,22,22,22,38,38,38,  // 7
    38,38,38,38,38,38,38,38,38,  // 8

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


const uint8_t MAP_Segment_Type12_02[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38,38,21, 0,34,24,24,30,  // 0
    38,38,38,21, 0, 0, 0, 0,23,  // 1
    29,24,24,24,44,44,48, 0,23,  // 2
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 3
    21, 0,47,44,44,44,44,44,52,  // 4
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 5
    31,22,22,22,44,44,48, 0,23,  // 6
    38,38,38,21, 0, 0, 0, 0,23,  // 7
    38,38,38,31,22,22,22,22,32,  // 8
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
    4,7,

};

const uint8_t MAP_Segment_Type12_03[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    29,24,24,35, 0,23,38,38,38,  // 0
    21, 0, 0, 0, 0,23,38,38,38,  // 1
    21, 0,37,44,44,24,30,38,38,  // 2
    21, 0,46, 0, 0, 0,23,38,38,  // 3
    21, 0, 0, 0, 0, 0,23,38,38,  // 4
    31,22,36, 0, 0, 0,23,38,38,  // 5
    38,38,21, 0, 0, 0,23,38,38,  // 6
    38,38,31,22,22,22,32,38,38,  // 7
    38,38,38,38,38,38,38,38,38,  // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    2,

    // Tilemap Options -------------------
    // Opt, Tile, x, y

    0,MapTiles::Barrel,3,6,
    0,MapTiles::Barrel,5,6,
    1,MapTiles::Barrel,3,3,
    1,MapTiles::Barrel,5,3,
    END_OF_OPTIONS,

    // Environment Options ---------------
    // Opt, Source x, y, Dest x, y 

    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    1,
    0,Object::Bat,2,4,20,
    0,Object::Spider,1,1,40,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    1,
    4,4,

};