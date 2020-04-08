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


const uint8_t MAP_Segment_Type10_00[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38,38,21, 0,23,38,38,38,  // 0
    38,38,38,21, 0,23,38,38,38,  // 1
    38,38,38,21, 0,23,38,38,38,  // 2
    24,24,24,35, 0,34,24,24,24,  // 3
     0, 0, 0, 0, 0, 0, 0, 0, 0,  // 4
    22,22,22,36, 0,37,22,22,22,  // 5
    38,38,38,21, 0,23,38,38,38,  // 6
    38,38,38,21, 0,23,38,38,38,  // 7
    38,38,38,21, 0,23,38,38,38,  // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    0,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    4,
    0,Object::Bat,1,4,20,
    0,Object::Skull,4,7,40,
    1,Object::Spider,7,4,20,
    2,Object::Coin,2,4,0,
    2,Object::Coin,6,4,0,
    2,Object::Coin,4,2,0,
    2,Object::Coin,4,6,0,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    1,
    4,4,

};


const uint8_t MAP_Segment_Type10_01[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
     0,24,24,35, 0,34,24,24, 0,  // 0
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 1
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 2
    35, 0, 0, 0, 0, 0, 0, 0,34,  // 3
     0, 0, 0, 0, 0, 0, 0, 0, 0,  // 4
    36, 0, 0, 0, 0, 0, 0, 0,37,  // 5
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 6
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 7
     0,22,22,36, 0,37,22,22, 0,  // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    3,

    // Tilemap Options -------------------
    // Opt, Tile, x, y

    0,MapTiles::Barrel,2,2,
    0,MapTiles::Barrel,3,3,
    0,MapTiles::Barrel,5,5,
    1,MapTiles::Barrel,2,2,
    1,MapTiles::Barrel,3,3,
    1,MapTiles::Barrel,5,5,
    2,MapTiles::FullSquare,2,2,
    2,MapTiles::FullSquare,6,2,
    2,MapTiles::FullSquare,2,6,
    2,MapTiles::FullSquare,6,6,
    END_OF_OPTIONS,

    // Environment Options ---------------
    // Opt, Source x, y, Dest x, y 

    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    2,
    0,Object::Bat,1,5,20,
    0,Object::Bat,7,2,40,
    0,Object::Coin,3,1,40,
    0,Object::Coin,5,7,40,
    1,Object::Spider, 1, 5, 20,
    1,Object::Spider, 7, 2, 40,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    3,
    4,4,
    1,7,
    7,7,

};

const uint8_t MAP_Segment_Type10_02[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38,38,21, 0,23,38,38,38,  // 0
    38,38,38,25, 0,26,38,38,38,  // 1
    38,38,25, 0, 0, 0,26,38,38,  // 2
    24,25, 0, 0, 0, 0, 0,26,24,  // 3
     0, 0, 0, 0, 0, 0, 0, 0, 0,  // 4
    22,27, 0, 0, 0, 0, 0,28,22,  // 5
    38,38,27, 0, 0, 0,28,38,38,  // 6
    38,38,38,27, 0,28,38,38,38,  // 7
    38,38,38,21, 0,23,38,38,38,  // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    3,

    // Tilemap Options -------------------
    // Opt, Tile, x, y

    0,MapTiles::Barrel,3,3,
    0,MapTiles::Barrel,5,5,
    1,MapTiles::Barrel,3,3,
    1,MapTiles::Barrel,5,5,
    2,MapTiles::NewEndTRL,4,3,
    2,MapTiles::NewEndTBL,3,4,
    2,MapTiles::NewEndRBL,4,5,
    2,MapTiles::NewEndTRB,5,4,
    END_OF_OPTIONS,

    // Environment Options ---------------
    // Opt, Source x, y, Dest x, y 

    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    2,
    0,Object::Bat,5,2,20,
    0,Object::Bat,3,2,40,
    0,Object::Coin,3,6,40,
    0,Object::Coin,5,6,40,
    1,Object::Spider,3,6,40,
    1,Object::Spider,5,6, 40,
    0,Object::Coin,5,2,40,
    0,Object::Coin,3,2,40,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    4,
    2,3,
    5,3,
    2,5,
    5,5,


};


const uint8_t MAP_Segment_Type10_03[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38, 0,35, 0,34,24,24, 0,  // 0
    38,38,21, 0, 0, 0, 0, 0,23,  // 1
    38,38,21, 0,47,44,36, 0,23,  // 2
    24,24,21, 0, 0, 0,43, 0,34,  // 3
     0, 0,43, 0, 0, 0,43, 0, 0,  // 4
    36, 0,43, 0, 0, 0,23,22,22,  // 5
    21, 0,34,44,48, 0,23,38,38,  // 6
    21, 0, 0, 0, 0, 0,23,38,38,  // 7
     0,22,22,36, 0,37, 0,38,38,  // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    2,

    // Tilemap Options -------------------
    // Opt, Tile, x, y

    0,MapTiles::Barrel,3,5,
    0,MapTiles::Barrel,5,3,
    END_OF_OPTIONS,

    // Environment Options ---------------
    // Opt, Source x, y, Dest x, y 

    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    2,
    0,Object::Bat,1,7,20,
    0,Object::Coin,7,1,40,
    1,Object::Spider,1,7,20,
    1,Object::Coin,7,1,40,
    2,Object::Bat, 1, 5, 20,
    2,Object::Spider, 7, 2, 40,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    1,
    4,4,

};


const uint8_t MAP_Segment_Type10_04[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
     0,24,24,35, 0,34,24,24, 0,  // 0
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 1
    21, 0,37,44,44,44,36, 0,23,  // 2
    35, 0,43, 0, 0, 0,43, 0,34,  // 3
     0, 0,43, 0, 0, 0,43, 0, 0,  // 4
    36, 0,43, 0, 0, 0,43, 0,37,  // 5
    21, 0,34,48, 0,47,35, 0,23,  // 6
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 7
     0,22,22,36, 0,37,22,22, 0,  // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    3,

    // Tilemap Options -------------------
    // Opt, Tile, x, y

    0,MapTiles::Barrel,3,3,
    1,MapTiles::Barrel,3,5,
    END_OF_OPTIONS,

    // Environment Options ---------------
    // Opt, Source x, y, Dest x, y 

    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    2,
    0,Object::Bat,4,3,20,
    0,Object::Coin,1,1,0,
    0,Object::Coin,7,1,40,
    0,Object::Coin,1,7,0,
    0,Object::Coin,7,7,40,
    1,Object::Spider,4,3,60,
    0,Object::Coin,1,7,0,
    0,Object::Coin,7,7,40,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    1,
    4,4,

};


const uint8_t MAP_Segment_Type10_05[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38, 0,35, 0,34, 0,38,38,  // 0
    38,38,21,11, 0,11,23,38,38,  // 1
     0,24, 0,36, 0,37, 0,24, 0,  // 2
    35,11,34,35,59,34,35,11,34,  // 3
     0, 0, 0,57, 0,58, 0, 0, 0,  // 4
    36,11,37,36,60,37,36,11,37,  // 5
     0,22, 0,35, 0,34, 0,22, 0,  // 6
    38,38,21,11, 0,11,23,38,38,  // 7
    38,38, 0,36, 0,37, 0,38,38,  // 8

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

    0,1,3,3,4,
    0,1,3,4,3,
    0,1,3,5,4,
    0,1,5,4,3,
    0,1,5,5,4,
    0,1,5,4,5,

    0,5,1,4,3,
    0,5,1,5,4,
    0,5,1,4,6,
    0,3,1,5,4,
    0,3,1,4,5,
    0,3,1,3,4,

    0,7,5,5,4,
    0,7,5,4,5,
    0,7,5,3,4,
    0,7,3,4,5,
    0,7,3,3,4,
    0,7,3,4,3,

    0,3,7,4,5,
    0,3,7,3,4,
    0,3,7,4,3,
    0,5,7,3,4,
    0,5,7,4,3,
    0,5,7,5,4,
    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    1,
    0,Object::SackOCash,4,4,0,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    4,
    4,0,
    4,8,
    0,4,
    8,4,

};