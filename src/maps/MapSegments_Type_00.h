#pragma once

#include "Pokitto.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


/* -----------------------------------------------------------------------------

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

const uint8_t MAP_Segment_Type00_00[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38,38,38,38,38,38,38,38,  // 0
    38,38,38,38,38,38,38,38,38,  // 1
    38,38,38,38,38,38,38,38,38,  // 2
    38,38,38,29,24,24,24,24,24,  // 3
    38,38,38,21, 0, 0, 0, 0, 0,  // 4
    38,38,38,21, 0,37,22,22,22,  // 5
    38,38,38,21, 0,23,38,38,38,  // 6
    38,38,38,21, 0,23,38,38,38,  // 7
    38,38,38,21, 0,23,38,38,38,  // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    0,

    // Enemy Options ---------------------
    0,

    // Entrance / Exit Options -----------
    2,
    6,4,
    4,7,    
};

const uint8_t MAP_Segment_Type00_01[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38,38,38,38,38,38,38,38,  // 0
    38,38,38,24,24,24,38,38,38,  // 1
    38,38,25, 0, 0, 0,26,38,38,  // 2
    38,21, 0, 0, 0, 0, 0,34,24,  // 3
    38,21, 0, 0, 0, 0, 0, 0, 0,  // 4
    38,21, 0, 0, 0, 0, 0,37,22,  // 5
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

    0,MapTiles::Barrel,4,3,
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
    0,

    // Entrance / Exit Options -----------
    2,
    3,2,
    5,6,
};

const uint8_t MAP_Segment_Type00_02[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    29,24,24,24,24,24,24,24,30,  // 0
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 1
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 2
    21, 0, 0, 0, 0, 0, 0, 0,34,  // 3
    21, 0, 0, 0, 0, 0, 0, 0, 0,  // 4
    21, 0, 0, 0, 0, 0, 0, 0,37,  // 5
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 6
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 7
    31,22,22,36, 0,37,22,22,32,  // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    2,

    // Tilemap Options -------------------
    // Opt, Tile, x, y

    0,MapTiles::Barrel,3,1,
    0,MapTiles::Barrel,4,1,
    0,MapTiles::Barrel,4,2,
    0,MapTiles::Barrel,5,2,
    0,MapTiles::NewSpearDoorLHS,8,4,
    0,MapTiles::SwitchOff,1,1,
    1,MapTiles::Barrel,7,6,
    1,MapTiles::Barrel,5,7,
    1,MapTiles::Barrel,6,7,
    END_OF_OPTIONS,

    // Environment Options ---------------
    // Opt, Source x, y, Dest x, y 

    0,1,1,8,4,
    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    1,
    0,Object::Bat, 1, 2, 20,
    0,Object::Spider, 2, 2, 40,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    2,
    4,4,
    1,7,

};

const uint8_t MAP_Segment_Type00_03[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    29,24,24,24,24,24,24,24,30,  // 8
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 7
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 6
    21, 0, 0,47,44,36, 0, 0,34,  // 5
    21, 0, 0, 0, 0,43, 0, 0, 0,  // 4
    21, 0, 0, 0, 0,23,22,22,22,  // 3
    31,22,22,36, 0,23,38,38,38,  // 2
    38,38,38,21, 0,23,38,38,38,  // 1
    38,38,38,21,  ,23,38,38,38,  // 0

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    2,

    // Tilemap Options -------------------
    // Opt, Tile, x, y

    0,MapTiles::Barrel,7,1,
    0,MapTiles::Barrel,6,1,
    1,MapTiles::Barrel,5,1,
    END_OF_OPTIONS,

    // Environment Options ---------------
    // Opt, Source x, y, Dest x, y 

    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    2,
    0,Object::Bat,3,1,40,
    0,Object::Spider,4,4,40,
    0,Object::Coin,1,5,0,
    1,Object::Bat,3,1,40,
    1,Object::Spider,4,4,40,
    1,Object::Coin,1,5,0,
    1,Object::Coin,1,4,0,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    1,
    1,1,

};