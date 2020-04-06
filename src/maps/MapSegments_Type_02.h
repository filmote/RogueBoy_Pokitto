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

const uint8_t MAP_Segment_Type02_00[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38,38,21, 0,23,38,38,38,  // 0
    38,38,38,21, 0,23,38,38,38,  // 1
    38,38,38,21, 0,23,38,38,38,  // 2
    38,38,38,21, 0,34,24,24,24,  // 3
    38,38,38,21, 0, 0, 0, 0, 0,  // 4
    38,38,38,31,22,22,22,22,22,  // 5
    38,38,38,38,38,38,38,38,38,  // 6
    38,38,38,38,38,38,38,38,38,  // 7
    38,38,38,38,38,38,38,38,38,  // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    0,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    0,

    // Entrance / Exit Options -----------
    1,
    4,4,

};

const uint8_t MAP_Segment_Type02_01[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38,38,21, 0,23,38,38,38,  // 0
    38,38,38,35, 0,34,38,38,38,  // 1
    38,38,25, 0, 0, 0,26,38,38,  // 2
    38,21, 0, 0, 0, 0, 0,34,24,  // 3
    38,21, 0, 0, 0, 0, 0, 0, 0,  // 4
    38,21, 0, 0, 0, 0, 0,37,22,  // 5
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
    2,
    0,Object::Bat, 2, 5, 20,
    0,Object::Spider, 3, 6, 40,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    2,
    3,2,
    5,6,
};

const uint8_t MAP_Segment_Type02_02[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    29,24,24,35, 0,34,24,24,30,  // 0
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 1
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 2
    21, 0, 0, 0, 0, 0, 0, 0,34,  // 3
    21, 0, 0, 0, 0, 0, 0, 0, 0,  // 4
    21, 0, 0, 0, 0, 0, 0, 0,37,  // 5
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 6
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 7
    31,22,22,22,22,22,22,22,32,  // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    2,

    // Tilemap Options -------------------
    // Opt, Tile, x, y

    0,MapTiles::Barrel,3,1,
    0,MapTiles::Barrel,4,1,
    0,MapTiles::Barrel,2,4,
    0,MapTiles::Barrel,5,2,
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

const uint8_t MAP_Segment_Type02_03[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38,38,21, 0,23,38,38,38,  // 0
    38,38,38,21, 0,23,38,38,38,  // 1
    29,24,24,35, 0,23,38,38,38,  // 2
    21, 0, 0, 0, 0,23,24,24,24,  // 3
    21, 0, 0, 0, 0,43, 0, 0, 0,  // 4
    21, 0, 0,47,44,35, 0, 0,37,  // 5
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 6
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 7
    31,22,22,22,22,22,22,22,32,  // 8

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
    0,Object::Bat, 3, 7, 40,
    0,Object::Spider, 4, 4, 40,
    0,Object::Coin,1,3,0,
    1,Object::Bat, 3, 7, 40,
    1,Object::Spider, 4, 4, 40,
    1,Object::Coin,1,3,0,
    1,Object::Coin,1,4,0,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    1,
    1,7,

};


const uint8_t MAP_Segment_Type02_04[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,29,24,35, 0,34,24,24,30,  // 0
    38,21,11, 0, 0, 0, 0, 0,23,  // 1
    29,24,48,59,47,44,36, 0,23,  // 2
    21, 0, 0, 0, 0, 0,43, 0,34,  // 3
    21, 0, 0, 0, 0, 0,46, 0, 0,  // 4
    21, 0, 0, 0, 0, 0,58, 0,37,  // 5
    21, 0, 0, 0, 0, 0,45,11,23,  // 6
    21,11, 0, 0, 0, 0,23,22,32,  // 7
    31,22,22,22,22,22,32,38,38,  // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    3,

    // Tilemap Options -------------------
    // Opt, Tile, x, y

    0,MapTiles::Barrel,3,7,
    0,MapTiles::Barrel,4,7,
    1,MapTiles::Barrel,1,5,
    1,MapTiles::Barrel,1,4,
    1,MapTiles::Barrel,4,5,
    2,MapTiles::FullSquare,2,4,
    2,MapTiles::FullSquare,4,4,
    2,MapTiles::FullSquare,2,6,
    2,MapTiles::FullSquare,4,6,
    END_OF_OPTIONS,

    // Environment Options ---------------
    // Opt, Source x, y, Dest x, y 

    0,7,5,3,2,
    0,2,1,6,5,
    0,1,7,6,5,
    0,1,7,3,2,
    1,7,5,3,2,
    1,2,1,6,5,
    1,1,7,6,5,
    1,1,7,3,2,
    2,7,5,3,2,
    2,2,1,6,5,
    2,1,7,6,5,
    2,1,7,3,2,
    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    2,
    0,Object::Bat,3,6,40,
    0,Object::Spider,2,5,40,
    0,Object::Coin,3,5,0,
    1,Object::Bat,3,6,40,
    1,Object::Bat,2,5,40,
    1,Object::Donut,5,7,0,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    2,
    7,1,
    5,3

};