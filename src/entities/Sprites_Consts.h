#pragma once

#include "Pokitto.h"
#include "Sprite.h"
#include "Player.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


const uint8_t spriteWidths[24] =  { 
    10, /* Coin */
    10, /* SackOfCash */
    10, /* Bread */
    10, /* Key */
    10, /* Chicken */
    8,  /* Floater */
    12, /* Eye */
    8,  /* Spider */
    8,  /* Bat */
    12, /* Tools */
    10,  /* Tonic */
    16, /* BigSpider */
    14, /* IceSpell */
    14, /* GreenSpell */
    14, /* RedSpell */
    14, /* MauveSpell */
     8, /* Skeleton */
    16, /* SpikeLHS */
    16, /* SpikeRHS */
    16, /* FireTOP */
    16, /* FireBOT */
    12, /* Snake */
    16, /* Chest */
    10, /* Necromancer */
};

const uint8_t spriteHeights[24] = { 
    10, /* Coin */
    10, /* SackOfCash */
    10, /* Bread */
    10, /* Key */
    8,  /* Chicken */
    8,  /* Floater */  
    12,  /* Eye */
    8,  /* Spider */
    8,  /* Bat */
    12, /* Tools */
    10,  /* Tonic */
    16, /* BigSpider */
    14, /* IceSpell */
    14,  /* GreenSpell */
    14,  /* RedSpell */
    14, /* MauveSpell */
    12, /* Skeleton */
    16, /* SpikeLHS note its actually 17 */
    16, /* SpikeRHS */
    16, /* FireTOP */
    16, /* FireBOT */
    12, /* Snake */
    16, /* Chest */
    12, /* Necromancer */
};

        
const int8_t spriteOffsets[48] = { 
    -5, -5,  /* Coin */
    -5, -5,  /* SackOfCash */
    -5, -5,  /* Bread */
    -5, -4,  /* Key */
    -5, -5,  /* Chicken */
    -3, -3,  /* Floater */  
    -6, -6,  /* Eye */
    -4, -4,  /* Spider */
    -4, -4,  /* Bat */
    -5, -5,  /* Tools */
    -5, -5,  /* Tonic */
    -8, -8,  /* BigSpider */
    -7, -6,  /* IceSpell */
    -7, -6,  /* GreenSpell */
    -7, -6,  /* RedSpell */
    -7, -6,  /* MauveSpell */
    -6, -6,  /* Skeleton */
    -8, -8,  /* SpikeLHS */
    -8, -8,  /* SpikeRHS */
    -8, -8,  /* FireTOP */
    -8, -8,  /* FireBOT */
    -4, -6,  /* Snake */
    -8, -8,  /* Chest */
    -6, -6,  /* Necromancer */
};

const char object_Desc_00[] = "Coin";
const char object_Desc_01[] = "Sack of Coins";
const char object_Desc_02[] = "Bread";
const char object_Desc_03[] = "Key";
const char object_Desc_04[] = "Chicken";
const char object_Desc_05[] = "Floater";
const char object_Desc_06[] = "Eye";
const char object_Desc_07[] = "Spider";
const char object_Desc_08[] = "Bat";
const char object_Desc_09[] = "Tools";
const char object_Desc_10[] = "Tonic";
const char object_Desc_11[] = "Big Spider";
const char object_Desc_12[] = "Ice Spell";
const char object_Desc_13[] = "Green";
const char object_Desc_14[] = "Red";
const char object_Desc_15[] = "Mauve";
const char object_Desc_16[] = "Skeleton";
const char object_Desc_17[] = "Spike LHS";
const char object_Desc_18[] = "Spike RHS";
const char object_Desc_19[] = "Flame TOP";
const char object_Desc_20[] = "Flame BOT";
const char object_Desc_21[] = "Snake";
const char object_Desc_22[] = "Chest";
const char object_Desc_23[] = "Necromancer";

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
    object_Desc_22,
    object_Desc_23,
};

                                // 0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4   
const uint8_t spike_frameIdx[] =  {0, 2, 4, 6, 8, 8, 8, 8, 8, 8, 7, 7, 6, 6, 5, 5, 4, 4, 3, 3, 3, 2, 1, 1, 0 };
const uint8_t fire_frameIdx[] =   {0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2 };
