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
     0,24,24,35,60,34,24,24, 0, // 0
    21,10, 0,58, 0,57, 0,10,23, // 1
     0,44,44,36, 0,37,44,44, 0, // 2
    21,10, 0,43, 0,43, 0,10,23, // 3
     0,33,60,46,60,46,60,47, 0, // 4
    21,10, 0,58, 0,57, 0,10,23, // 5
     0,48,60,47,44,48,60,47, 0, // 6
    21,10, 0, 0, 0, 0, 0,10,23, // 7
     0,22,22,36, 0,37,22,22, 0, // 8

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



// Three segment maze (Horizontal) ..
const uint8_t MAP_Segment_Type15_01[] = {
//   0  1  2  3  4  5  6  7  8
     0,24, 0,24, 0,24,24,24,24,  // 0
    21,10,46,10,46, 0, 0, 0, 0,  // 1
    21, 0, 0, 0,57, 0,37,44,44,  // 2
    35, 0, 0, 0,47,44,35, 0,73,  // 3
     0, 0, 0, 0,57, 0, 0, 0,47,  // 4
    36, 0, 0, 0,47,44,36, 0, 0,  // 5
    21, 0, 0, 0,57, 0,34,44,44,  // 6
    21,10,45,10,45, 0, 0, 0,73,  // 7
     0,22, 0,22, 0,22,22,22,22,  // 8

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

    0,1,1,4,2,
    0,1,1,22,6,
    0,3,1,4,4,
    0,3,1,12,6,
    0,3,1,22,2,
    0,3,1,22,4,
    0,1,7,4,6,
    0,1,7,19,6,
    0,8,3,21,7,
    0,8,7,10,3,
    0,5,2,8,3,
    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    1,
    0,Object::IceSpell,0,4,0,
    END_OF_OPTIONS,
    
    // Entrance / Exit Options -----------
    1,
    2,4

};

const uint8_t MAP_Segment_Type15_02[] = {
//   0  1  2  3  4  5  6  7  8
    24,24,24,24,24, 0,24,24,24,   // 0
     0, 0, 0, 0, 0,43, 0, 0, 0,   // 1
    22,44,36,73, 0,43,73,37,44,   // 2
    43,73,23,44,44,24,44,21, 0,   // 3
    35, 0,43, 0, 0, 0, 0,43,73,   // 4
     0, 0,43, 0, 0, 0, 0,23,44,   // 5
    22,44,35,60,45, 0, 0,46, 0,   // 6
    43,73, 0, 0,43, 0, 0, 0, 0,   // 7
     0,22,22,22, 0,22,22,22,22,   // 8

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

    0,3,2,1,7,
    0,1,7,3,2,
    0,1,3,-1,7,
    0,8,4,6,2,
    0,6,2,8,4,
    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    1,
    0,Object::Ham,8,6,0,
    END_OF_OPTIONS,

    // Entrance / Exit Options -----------
    0,

};


const uint8_t MAP_Segment_Type15_03[] = {
//   0  1  2  3  4  5  6  7  8
    24,24,24,24, 0,24, 0,24, 0,   // 0
     0, 0, 0, 0,46,10,46,10,23,   // 1
    44,44,36, 0,58, 0, 0, 0,23,   // 2
    58, 0,34,44,48, 0, 0, 0,34,   // 3
    45, 0, 0, 0,58, 0, 0, 0, 0,   // 4
    21, 0,37,44,48, 0, 0, 0,37,   // 5
    46,64,43, 0,58, 0, 0, 0,23,   // 6
     0, 0,43,73,45,10,45,10,23,   // 7
    22,22, 0,22, 0,22, 0,22, 0,   // 8

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

    0,5,1,4,6,
    0,5,1,-14,2,
    0,7,1,4,2,
    0,7,1,4,4,
    0,7,1,-6,6,
    0,7,1,-14,4,
    0,5,7,1,6,
    0,5,7,-14,6,
    0,3,7,-10,3,        
    0,7,7,0,3,
    END_OF_OPTIONS,

    // Enemy Options ---------------------
    // Opt , Object, x, y, Health 
    0,

    // Entrance / Exit Options -----------
    1,
    6,4,

};


