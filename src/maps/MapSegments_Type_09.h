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


const uint8_t MAP_Segment_Type09_00[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
     0, 0, 0,21, 0,34,24,24,30,  // 0
     0, 0, 0,21, 0, 0, 0, 0,23,  // 1
     0, 0, 0,21, 0, 0, 0, 0,23,  // 2
    24,24,24,24,44,48, 0, 0,23,  // 3
     0, 0, 0, 0, 0, 0, 0, 0,23,  // 4
    22,22,22,22,44,48, 0, 0,23,  // 5
    38,38,38,21, 0, 0, 0, 0,23,  // 6
    38,38,38,21, 0, 0, 0, 0,23,  // 7
    38,38,38,21, 0,37,22,22,32,  // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    3,

    // Tilemap Options -------------------
    // Opt, Tile, x, y

    0,MapTiles::Barrel,6,1,
    0,MapTiles::Barrel,7,2,
    0,MapTiles::Barrel,4,2,
    1,MapTiles::Barrel,5,7,
    1,MapTiles::Barrel,7,4,
    1,MapTiles::Barrel,7,3,
    END_OF_OPTIONS,

    // Environment Options ---------------
    // Opt, Source x, y, Dest x, y 

    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    3,
    0,Object::Bat,6,2,40,
    0,Object::Bat,7,1,40,
    0,Object::Donut,7,7,40,
    1,Object::Bat,7,7,40,
    1,Object::Bat,7,1,40,
    1,Object::Floater,6,2,40,
    2,Object::Bat,7,1,40,
    2,Object::Skull,6,2,40,
    2,Object::Ham,7,7,0,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    1,
    7,1,

};


const uint8_t MAP_Segment_Type09_01[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    29,24,24,35, 0,23,38,38,38,  // 0
    21, 0, 0, 0, 0,23,38,38,38,  // 1
    21, 0, 0,47,44,24,24,24,30,  // 2
    35, 0, 0, 0, 0, 0, 0, 0,23,  // 3
     0, 0, 0, 0, 0, 0, 0, 0,23,  // 4
    36, 0, 0, 0, 0, 0, 0, 0,23,  // 5
    31,22,22,22,44,48, 0, 0,23,  // 6
    38,38,38,21, 0, 0, 0, 0,23,  // 7
    38,38,38,21, 0,37,22,22,32,  // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    3,

    // Tilemap Options -------------------
    // Opt, Tile, x, y

    0,MapTiles::Barrel,2,5,
    0,MapTiles::FullSquare,3,4,
    0,MapTiles::FullSquare,5,4,
    1,MapTiles::Barrel,5,3,
    1,MapTiles::Barrel,6,3,
    2,MapTiles::Barrel,1,2,
    2,MapTiles::Barrel,7,6,
    END_OF_OPTIONS,

    // Environment Options ---------------
    // Opt, Source x, y, Dest x, y 

    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    3,
    0,Object::Bat,4,1,40,
    0,Object::Spider,4,4,40,
    1,Object::Bat,6,4,40,
    1,Object::Bat,4,3,40,
    1,Object::Floater,4,4,40,
    2,Object::Bat,4,1,40,
    2,Object::Skull,4,4,40,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    2,
    1,1,
    7,7,

};


const uint8_t MAP_Segment_Type09_02[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38,38,21, 0,34,30,38,38,	  // 0
    38,38,38,21, 0,11,23,38,38,	  // 1
    29,24,51,35,59,47,24,24,30,	  // 2
    35,11,46, 0, 0, 0, 0,11,23,	  // 3
     0, 0,57, 0, 0, 0, 0,11,23,	  // 4
    22,22,36, 0, 0, 0, 0,11,23,	  // 5
    38,38,50,48,60,37,22,22,32,	  // 6
    38,38,21,11, 0,23,38,38,38,	  // 7
    38,38,31,36, 0,23,38,38,38,	  // 8


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
    0,5,1,4,2,
    0,1,3,2,4,
    0,3,7,4,6,
    0,7,3,4,2,
    0,7,4,2,4,
    0,7,5,4,6,
    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    3,
    0,Object::Bat,6,3,40,
    0,Object::Bat,6,5,40,
    0,Object::Coin,3,3,0,
    0,Object::Coin,3,5,0,
    1,Object::Floater,6,3,40,
    1,Object::Floater,6,5,40,
    1,Object::SackOCash,3,3,0,
    1,Object::Donut,3,5,0,
    2,Object::Skull,6,3,40,
    2,Object::Skull,6,5,40,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    1,
    4,4,

};




