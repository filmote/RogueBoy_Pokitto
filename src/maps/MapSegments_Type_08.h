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

const uint8_t MAP_Segment_Type08_00[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    29,24,24,24,24,24,24,24,30,  // 0
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 1
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 2
    35, 0, 0, 0, 0, 0, 0, 0,34,  // 3
     0, 0, 0, 0, 0, 0, 0, 0, 0,  // 4
    36, 0, 0, 0, 0, 0, 0, 0,37,  // 5
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 6
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 7
    31,22,22,36, 0,37,22,22,32,  // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    3,

    // Tilemap Options -------------------
    // Opt, Tile, x, y

    0,MapTiles::Barrel,3,2,
    0,MapTiles::Barrel,4,2,
    0,MapTiles::Barrel,4,3,
    0,MapTiles::Barrel,5,2,
    0,MapTiles::NewSpearDoorLHS,8,4,
    0,MapTiles::SwitchOff,1,1,
    1,MapTiles::Barrel,7,6,
    1,MapTiles::Barrel,5,7,
    1,MapTiles::Barrel,6,7,
    2,MapTiles::NewCornerTL,3,3,
    2,MapTiles::NewStraightTOP,4,3,
    2,MapTiles::NewCornerTR,5,3,
    2,MapTiles::NewStraightLHS,3,4,
    2,MapTiles::NewFill,4,4,
    2,MapTiles::NewStraightRHS,5,4,
    2,MapTiles::NewCornerLL,3,5,
    2,MapTiles::NewStraightBOT,4,5,
    2,MapTiles::NewCornerLR,5,5,
    2,MapTiles::Barrel,3,1,
    2,MapTiles::Barrel,4,1,
    END_OF_OPTIONS,

    // Environment Options ---------------
    // Opt, Source x, y, Dest x, y 

    0,1,1,8,4,
    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    3,
    0,Object::Bat, 1, 2, 40,
    0,Object::Bat, 2, 1, 40,
    0,Object::Bat, 2, 3, 40,
    0,Object::Donut, 7, 7, 40,
    1,Object::Coin, 2, 2, 40, 
    1,Object::Coin, 2, 1, 40, 
    1,Object::Coin, 1, 2, 40, 
    1,Object::Bat, 6, 6, 40,
    1,Object::Bat, 2, 2, 40,
    1,Object::Bat, 7, 2, 40,
    2,Object::Floater, 2, 2, 40,
    2,Object::Skull, 3, 7, 40,
    2,Object::Skull, 5, 6, 40,
    2,Object::Ham, 1, 2, 40,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    2,
    1,8,
    7,7,

};

const uint8_t MAP_Segment_Type08_01[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    29,24,24,24,24,24,24,24,30,  // 0
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 1
    21, 0, 0, 0, 0, 0, 0, 0,23,  // 2
    35, 0, 0,45, 0,45, 0, 0,34,  // 3
     0, 0, 0,43, 0,43, 0, 0, 0,  // 4
    22,22,22,21, 0,23,22,22,22,  // 5
    38,38,38,21, 0,23,38,38,38,  // 6
    38,38,38,21, 0,23,38,38,38,  // 7
    38,38,38,21, 0,23,38,38,38,  // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    3,

    // Tilemap Options -------------------
    // Opt, Tile, x, y

    0,MapTiles::Barrel,2,1,
    0,MapTiles::Barrel,1,2,
    0,MapTiles::Barrel,4,3,
    1,MapTiles::Barrel,7,1,
    1,MapTiles::Barrel,7,2,
    1,MapTiles::Barrel,2,3,
    END_OF_OPTIONS,

    // Environment Options ---------------
    // Opt, Source x, y, Dest x, y 

    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    3,
    0,Object::Bat,2,1,40,
    0,Object::Bat,2,4,40,
    0,Object::Donut,6,4,40,
    1,Object::Bat,6,1,40,
    1,Object::Bat,6,3,40,
    1,Object::Floater,1,3,40,
    2,Object::Bat,4,6,40,
    2,Object::Skull,7,3,40,
    2,Object::Ham,2,1,0,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    1,
    1,1,

};


const uint8_t MAP_Segment_Type08_02[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38,29,24,24,24,24,24,30,  // 0
    38,38,21, 0, 0, 0, 0, 0,23,  // 1
    38,38,21, 0, 0, 0, 0, 0,23,  // 2
    24,24,21, 0, 0, 0,45, 0,34,  // 3
     0, 0,43, 0, 0, 0,43, 0, 0,  // 4
    36, 0,46, 0, 0, 0,23,22,22,  // 5
    21, 0, 0, 0, 0, 0,23,38,38,  // 6
    21, 0, 0, 0, 0, 0,23,38,38,  // 7
    31,22,22,36, 0,37,32,38,38,  // 8

    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    3,

    // Tilemap Options -------------------
    // Opt, Tile, x, y

    0,MapTiles::Barrel,4,1,
    0,MapTiles::Barrel,5,1,
    1,MapTiles::Barrel,4,1,
    1,MapTiles::Barrel,3,7,
    2,MapTiles::Barrel,6,1,
    2,MapTiles::Barrel,2,7,
    END_OF_OPTIONS,

    // Environment Options ---------------
    // Opt, Source x, y, Dest x, y 

    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    3,
    0,Object::Bat,2,6,40,
    0,Object::Bat,3,3,40,
    0,Object::Donut,5,7,40,
    1,Object::Bat,4,4,40,
    1,Object::Bat,4,5,40,
    1,Object::Floater,4,6,40,
    2,Object::Bat,4,6,40,
    2,Object::Skull,4,5,40,
    2,Object::Ham,5,7,0,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    1,
    3,1,

};



