#pragma once

#include "Pokitto.h"
#include "Sprite.h"
#include "Player.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


const uint8_t spriteWidths[22] =  { 
    8,  /* Coin */
    8,  /* SackOfCash */
    8,  /* Bread */
    10, /* Key */
    8,  /* Chicken */
    8,  /* Floater */
    10, /* Skull */
    8,  /* Spider */
    8,  /* Bat */
    12, /* Tools */
    8,  /* Tonic */
    16, /* BigSpider */
    12, /* IceSpell */
    12, /* GreenSpell */
    12, /* RedSpell */
    8,  /* MauveSpell */
    12, /* NewEnemy */
    16, /* SpikeLHS */
    16, /* SpikeRHS */
    16, /* FireTOP */
    16, /* FireBOT */
    12, /* Snake */
};

const uint8_t spriteHeights[22] = { 
    8,  /* Coin */
    8,  /* SackOfCash */
    8,  /* Bread */
    8,  /* Key */
    8,  /* Chicken */
    8,  /* Floater */  
    9,  /* Skull */
    8,  /* Spider */
    8,  /* Bat */
    12, /* Tools */
    8,  /* Tonic */
    16, /* BigSpider */
    12, /* IceSpell */
    12,  /* GreenSpell */
    12,  /* RedSpell */
    8,  /* MauveSpell */
    12, /* NewEnemy */
    16, /* SpikeLHS note its actually 17 */
    16, /* SpikeRHS */
    16, /* FireTOP */
    16, /* FireBOT */
    12, /* Snake */
};

        
const int8_t spriteOffsets[44] = { 
    -3, -3,  /* Coin */
    -3, -3,  /* SackOfCash */
    -3, -3,  /* Bread */
    -6, -3,  /* Key */
    -3, -3,  /* Chicken */
    -3, -3,  /* Floater */  
    -3, -3,  /* Skull */
    -4, -4,  /* Spider */
    -4, -4,  /* Bat */
    -5, -5,  /* Tools */
    -4, -4,  /* Tonic */
    -8, -8,  /* BigSpider */
    -5, -4,  /* IceSpell */
    -5, -4,  /* GreenSpell */
    -5, -4,  /* RedSpell */
    -4, -4,  /* MauveSpell */
    -6, -6,  /* NewEnemy */
    -8, -8,  /* SpikeLHS */
    -8, -8,  /* SpikeRHS */
    -8, -8,  /* FireTOP */
    -8, -8,  /* FireBOT */
    -4, -6,  /* Snake */
};

const char object_Desc_00[] = "Coin";
const char object_Desc_01[] = "Sack of Coins";
const char object_Desc_02[] = "Bread";
const char object_Desc_03[] = "Key";
const char object_Desc_04[] = "Chicken";
const char object_Desc_05[] = "Floater";
const char object_Desc_06[] = "Skull";
const char object_Desc_07[] = "Spider";
const char object_Desc_08[] = "Bat";
const char object_Desc_09[] = "Tools";
const char object_Desc_10[] = "Tonic";
const char object_Desc_11[] = "Big Spider";
const char object_Desc_12[] = "Ice Spell";
const char object_Desc_13[] = "Green";
const char object_Desc_14[] = "Red";
const char object_Desc_15[] = "Mauve";
const char object_Desc_16[] = "New Enemy";
const char object_Desc_17[] = "Spike LHS";
const char object_Desc_18[] = "Spike RHS";
const char object_Desc_19[] = "Flame TOP";
const char object_Desc_20[] = "Flame BOT";
const char object_Desc_21[] = "Snake";

const char * const object_Descs[] = { 
    object_Desc_00,
    object_Desc_01,
    object_Desc_02,
    object_Desc_03,
    object_Desc_04,
    object_Desc_05,
    object_Desc_06,
    object_Desc_07,
    object_Desc_08,
    object_Desc_09,
    object_Desc_10,
    object_Desc_11,
    object_Desc_12,
    object_Desc_13,
    object_Desc_14,
    object_Desc_15,
    object_Desc_16,
    object_Desc_17,
    object_Desc_18,
    object_Desc_19,
    object_Desc_20,
    object_Desc_21,
};

                                // 0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4   
const uint8_t spike_frameIdx[] =  {0, 2, 4, 6, 8, 8, 8, 8, 8, 8, 7, 7, 6, 6, 5, 5, 4, 4, 3, 3, 3, 2, 1, 1, 0 };
const uint8_t fire_frameIdx[] =   {0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2 };
