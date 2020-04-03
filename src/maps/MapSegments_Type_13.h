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

const uint8_t MAP_Segment_Type13_00[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38,38,38,38,38,38,38,38,  // 0
    38,38,38,38,38,38,38,38,38,  // 1
    38,38,38,38,38,38,38,38,38,  // 2
    24,24,24,24,24,24,38,38,38,  // 3
     0, 0, 0, 0, 0, 0,23,38,38,  // 4
    22,22,22,22,22,22,38,38,38,  // 5
    38,38,38,38,38,38,38,38,38,  // 6
    38,38,38,38,38,38,38,38,38,  // 7
    38,38,38,38,38,38,38,38,38,  // 8


    // -----------------------------------
    // TileMap and Environment Options
    // -----------------------------------
   
    // Number of Options
    2,

    // Tilemap Options -------------------
    // Opt, Tile, x, y

    1,MapTiles::NewCornerLR,0,3,
    1,MapTiles::NewCornerFillLR,0,2,
    1,MapTiles::NewStraightBOT,1,2,
    1,MapTiles::NewCornerFillLL,2,2,
    1,MapTiles::NewCornerLL,2,3,
    1,MapTiles::SwitchOn,1,3,
    1,MapTiles::NewSpearDoorLHS,3,4,

    1,MapTiles::NewCornerTR,3,5,
    1,MapTiles::NewCornerFillUR,3,6,
    1,MapTiles::NewStraightTOP,4,6,
    1,MapTiles::NewCornerFillUL,5,6,
    1,MapTiles::NewCornerTL,5,5,
    1,MapTiles::SwitchOn,4,5,
    END_OF_OPTIONS,

    // Environment Options ---------------
    // Opt, Source x, y, Dest x, y 

    1,4,5,3,4,
    1,1,3,3,4,
    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    0,

    // Entrance / Exit Options -----------
    1,
    5,4,

};

const uint8_t MAP_Segment_Type13_01[] = {
  // 0, 1, 2, 3, 4, 5, 6, 7, 8
    38,38,38,38,38,38,38,38,38,  // 0
    38,38,38,24,24,24,38,38,38,  // 1
    38,38,25, 0, 0, 0,26,38,38,  // 2
    38,35, 0, 0, 0, 0, 0,23,38,  // 3
     0, 0, 0, 0, 0, 0, 0,23,38,  // 4
    38,36, 0, 0, 0, 0, 0,23,38,  // 5
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
