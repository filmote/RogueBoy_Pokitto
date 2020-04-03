#pragma once

#include "Pokitto.h"

// #include "MapSegments_Type_00.h"
// #include "MapSegments_Type_01.h"
// #include "MapSegments_Type_02.h"
// #include "MapSegments_Type_03.h"
// #include "MapSegments_Type_04.h"
// #include "MapSegments_Type_05.h"
// #include "MapSegments_Type_06.h"
// #include "MapSegments_Type_07.h"
// #include "MapSegments_Type_08.h"
// #include "MapSegments_Type_09.h"
// #include "MapSegments_Type_10.h"
// #include "MapSegments_Type_11.h"
// #include "MapSegments_Type_12.h"
// #include "MapSegments_Type_13.h"
// #include "MapSegments_Type_14.h"
// #include "MapSegments_Type_15.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

#define BLANK_SEG   128
#define ANY_SEG     64
#define THIS_SEG    32
#define SEG_00      0
#define SEG_01      1
#define SEG_02      2
#define SEG_03      3
#define SEG_04      4
#define SEG_05      5
#define SEG_06      6
#define SEG_07      7
#define SEG_08      8
#define SEG_09      9
#define SEG_10      10
#define SEG_11      11
#define SEG_12      12
#define SEG_13      13
#define SEG_14      14
#define SEG_15      15

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


Bit 7       Blank segment.
Bit 6       Any Segment from the nominated Type.
Bit 5       Specify a specific segment (over two bytes, sgement type, index)
Bit 4 .. 0  Segment specification (range 0 - 31).

*/

// -----------------------------------------------------------------------------

const uint8_t Map_Random_1[] = {
    /* Map Size */   2, 1,
    /* Timer */      200,
    /* Player Start Segment / End of Level Segment */ 2,
    /* px, py, EolX, EolY */
    0,0,1,0,
    1,0,0,0,
    /* Map Data */
    THIS_SEG | 0, 3,
    THIS_SEG | 0, 3,
};


const uint8_t Map_Random_2[] = {
    /* Map Size */   2, 2,
    /* Timer */      200,
    /* Player Start Segment / End of Level Segment */ 2,
    /* px, py, EolX, EolY */
    0,0,1,0,
    0,1,0,0,
    /* Map Data */
    // ANY_SEG | 0, THIS_SEG | SEG_08, 0,
    // ANY_SEG | 2, ANY_SEG | 3, 
    ANY_SEG | 0, ANY_SEG | 1,
    ANY_SEG | 2, ANY_SEG | 3, 
};