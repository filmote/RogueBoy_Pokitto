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


// Maze of levers ..
const uint8_t MAP_Segment_Type15_00[] = {
//   0  1  2  3  4  5  6  7  8
    29,24,24,35,60,34,24,24,30, // 0
    21,10, 0,58, 0,57, 0,10,23, // 1
    50,44,44,36, 0,37,44,44,52, // 2
    21,10, 0,43, 0,43, 0,10,23, // 3
    50,33,60,46,60,46,60,47,52, // 4
    21,10, 0,58, 0,57, 0,10,23, // 5
    50,48,60,47,44,48,60,47,52, // 6
    21,10, 0, 0, 0, 0, 0,10,23, // 7
    31,22,22,36, 0,37,22,22,32, // 8

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

    0,1,7,2,6,
    0,1,7,5,1,
    0,7,7,6,6,
    0,7,7,3,1,
    0,1,5,6,4,
    0,1,5,5,5,
    0,1,5,6,6,
    0,7,5,2,4,
    0,7,5,2,6,
    0,7,5,3,5,
    0,1,3,4,4,
    0,1,3,3,5,
    0,1,3,5,5,
    0,7,3,4,4,
    0,7,3,3,5,
    0,7,3,5,5,
    0,1,1,4,0,
    0,7,1,3,1,
    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    0,

    // Entrance / Exit Options -----------
    1,
    4,7

};