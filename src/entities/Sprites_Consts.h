#pragma once

#include "Pokitto.h"
#include "Sprite.h"
#include "Player.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


const uint8_t spriteWidths[18] =  { 
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
    16, /* Spike */
    12, /* NewEnemy */
};

const uint8_t spriteHeights[18] = { 
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
    16, /* Spike */
    12, /* NewEnemy */
};

        
const int8_t spriteOffsets[18] = { 
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
    -4, /* Spike */
    -2, /* NewEnemy */
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
const char object_Desc_17[] = "Spike";

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
};