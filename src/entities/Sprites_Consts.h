#pragma once

#include "Pokitto.h"
#include "Sprite.h"
#include "Player.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


const uint8_t spriteWidths[16] =  { 
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
    13, /* IceSpell */
    8,  /* GreenSpell */
    8,  /* YellowSpell */
    8,  /* MauveSpell */
};

const uint8_t spriteHeights[16] = { 
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
    11, /* IceSpell */
    8,  /* GreenSpell */
    8,  /* YellowSpell */
    8,  /* MauveSpell */
};

        
const int8_t spriteOffsets[16] = { 
    0,  /* Coin */
    0,  /* SackOfCash */
    0,  /* Bread */
    0,  /* Key */
    0,  /* Chicken */
    0,  /* Floater */  
    0,  /* Skull */
    0,  /* Spider */
    0,  /* Bat */
    -3, /* Tools */
    0,  /* Tonic */
    -4, /* BigSpider */
    -2, /* IceSpell */
    0,  /* GreenSpell */
    0,  /* YellowSpell */
    0,  /* MauveSpell */
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
const char object_Desc_14[] = "Yellow";
const char object_Desc_15[] = "Mauve";

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
};