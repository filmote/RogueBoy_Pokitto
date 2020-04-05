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

const uint8_t MAP_Segment_Type01_00[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38,38,38,38,38,38,38,38,  // 0
    38,38,38,38,38,38,38,38,38,  // 1
    38,38,38,38,38,38,38,38,38,  // 2
    24,24,24,24,24,30,38,38,38,  // 3
     0, 0, 0, 0, 0,23,38,38,38,  // 4
    22,22,22,36, 0,23,38,38,38,  // 5
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
    2,4,
    4,7,    
};

const uint8_t MAP_Segment_Type01_01[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38,38,38,38,38,38,38,38,  // 0
    38,38,38,24,24,24,38,38,38,  // 1
    38,38,25, 0, 0, 0,26,38,38,  // 2
    24,35, 0, 0, 0, 0, 0,23,38,  // 3
     0, 0, 0, 0, 0, 0, 0,23,38,  // 4
    22,36, 0, 0, 0, 0, 0,23,38,  // 5
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

const uint8_t MAP_Segment_Type01_02[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    29,24,24,24,24,24,24,24,30,  // 0
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 1
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 2
    35, 0, 0, 0, 0, 0, 0, 0,23,  // 3
     0, 0, 0, 0, 0, 0, 0, 0,23,  // 4
    36, 0, 0, 0, 0, 0, 0, 0,23,  // 5
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
    0,MapTiles::Barrel,7,2,
    0,MapTiles::Barrel,5,2,
    1,MapTiles::Barrel,7,6,
    1,MapTiles::Barrel,5,7,
    1,MapTiles::Barrel,6,7,
    END_OF_OPTIONS,

    // Environment Options ---------------
    // Opt, Source x, y, Dest x, y 

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


const uint8_t MAP_Segment_Type01_03[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38,29,24,24,24,24,24,30,  // 0
    38,38,21, 0, 0, 0, 0, 0,23,  // 1
    38,38,21, 0, 0, 0, 0, 0,23,  // 2
    24,24,35, 0, 0,45, 0, 0,23,  // 3
     0, 0, 0, 0, 0,43, 0, 0,23,  // 4
    22,22,22,22,44,35, 0, 0,23,  // 5
    38,38,38,21, 0, 0, 0, 0,23,  // 6
    38,38,38,21, 0, 0, 0, 0,23,  // 7
    38,38,38,21, 0,37,22,22,32,  // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    2,

    // Tilemap Options -------------------
    // Opt, Tile, x, y

    0,MapTiles::Barrel,7,7,
    0,MapTiles::Barrel,6,7,
    1,MapTiles::Barrel,5,7,
    END_OF_OPTIONS,

    // Environment Options ---------------
    // Opt, Source x, y, Dest x, y 

    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    2,
    0,Object::Bat,3,1,40,
    0,Object::Spider,4,4,40,
    0,Object::Coin,1,4,0,
    1,Object::Bat,4,6,40,
    1,Object::Spider,3,1,40,
    1,Object::Coin,6,1,0,
    1,Object::Coin,7,1,0,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    1,
    7,7,

};