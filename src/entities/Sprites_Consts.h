#pragma once

#include "Pokitto.h"
#include "Sprite.h"
#include "Player.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


const uint8_t spriteWidths[21] =  { 
    8,  /* Coin */
    8,  /* SackOfCash */
    8,  /* Bread */
    8,  /* Key */
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
    12,  /* RedSpell */
    8,  /* MauveSpell */
    12, /* NewEnemy */
    16, /* SpikeLHS */
    16, /* SpikeRHS */
    16, /* SpikeTOP */
    16, /* SpikeBOT */
};

const uint8_t spriteHeights[21] = { 
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
    17, /* SpikeLHS */
    17, /* SpikeRHS */
    17, /* SpikeTOP */
    17, /* SpikeBOT */
};

        
const int8_t spriteOffsets[21] = { 
    0,  /* Coin */
    0,  /* SackOfCash */
    0,  /* Bread */
    0,  /* Key */
    0,  /* Chicken */
    0,  /* Floater */  
    0,  /* Skull */
    0,  /* Spider */
    0,  /* Bat */
    -2, /* Tools */
    0,  /* Tonic */
    -4, /* BigSpider */
    -2, /* IceSpell */
    -2,  /* GreenSpell */
    -2,  /* RedSpell */
    0,  /* MauveSpell */
    -2, /* NewEnemy */
    -4, /* SpikeLHS */
    -4, /* SpikeRHS */
    -4, /* SpikeTOP */
    -4, /* SpikeBOT */
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
const char object_Desc_19[] = "Spike TOP";
const char object_Desc_20[] = "Spike BOT";

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
};

                                // 0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4   
const uint8_t spike_frameIdx[] =  {0, 2, 4, 6, 8, 8, 8, 8, 8, 8, 7, 7, 6, 6, 5, 5, 4, 4, 3, 3, 3, 2, 1, 1, 0 };
