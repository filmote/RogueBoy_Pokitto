#pragma once

enum class SpriteType : uint8_t {
    Player_1 = 0,
    Player_2,
    Player_3,
    Coin_1 = 12,
    Coin_2,
    Coin_3,
    Coin_4,
    Coin_5,
    Coin_6,
    BulletUp = 18,
    BulletDown,
    BulletRight,
    BulletLeft,
    
};

enum class GameState : uint8_t {
    MainMenu, 
    Settings, 
    Game, 
    LoadMap,
    GameOver, 
    EndOfLevel, 
    Dead, 
    WinState,
    Inventory
};


enum class Direction : uint8_t {
    Up, 
    UpRight, 
    Right, 
    DownRight,
    Down, 
    DownLeft, 
    Left, 
    UpLeft,
    None
};

enum class Axis : uint8_t {
    XAxis,
    YAxis
};

enum Object {
    Coin = 0,
    SackOCash = 1,
    Donut = 2,
    Key = 3,
    Ham = 4, 
    Floater = 5,
    Skull = 6,
    Spider = 7, 
    Bat = 8,
    Spanner = 9,
    Potion = 10,
    BigSpider = 11, 
};

enum MapTiles {
    Empty = 0,
    BlankWall = 1,
    LockedDoor = 2,
    DownStairs = 3,
    Barrel = 4,
    OpenChest = 5,
    OpenDoor = 6,
    FullBlockWall = 7,
    ClosedChest = 8,
    UpStairs = 9,
    SwitchOn = 10,
    SwitchOff = 11,
    TorchWall = 12,
    WindowWall = 13,
    PressPlate = 14,
    SpearDoor = 15,
    ExplosiveBarrel = 16,
    LockedStairs = 17,
    Rubble = 18,
    SwitchBroken = 19,
    Grass = 20,
    NewStraightRHS = 21,
    NewStraightTOP = 22,
    NewStraightLHS = 23,
    NewStraightBOT = 24,
    NewUpperLeftTriangle = 25,
    NewUpperRightTriangle = 26,
    NewLowerLeftTriangle = 27,
    NewLowerRightTriangle = 28,
    NewCornerFillLR = 29,
    NewCornerFillLL = 30,
    NewCornerFillUR = 31,
    NewCornerFillUL = 32,
    FullSquare = 33,
    NewCornerLL = 34,
    NewCornerLR = 35,
    NewCornerTR = 36,
    NewCornerTL = 37,
    NewFill = 38,
    NewDoorLHS = 39,
    NewDoorRHS = 40,
    NewDoorTOP = 41,
    NewDoorBOT = 42,
    NewStraightLR = 43,
    NewStraightTB = 44,
    NewEndTRL = 45,
    NewEndRBL = 46,
    NewEndTBL = 47,
    NewEndTRB = 48,
    NewFillTLTR = 49,
    NewFillTRBR = 50,
    NewFillBLBR = 51,
    NewFillTLBL = 52,
    NewDoorLHSOpen = 53,
    NewDoorRHSOpen = 54,
    NewDoorTOPOpen = 55,
    NewDoorBOTOpen = 56,
    NewSpearDoorLHS = 57,
    NewSpearDoorRHS = 58,
    NewSpearDoorTOP = 59,
    NewSpearDoorBOT = 60,
    NewSpearDoorLHSOpen = 61,
    NewSpearDoorRHSOpen = 62,
    NewSpearDoorTOPOpen = 63,
    NewSpearDoorBOTOpen = 64,
    NewStraightTorchLHS_F0 = 65,
    NewStraightTorchRHS_F0 = 66,
    NewStraightTorchTOP_F0 = 67,
    NewStraightTorchBOT_F0 = 68,
    NewStraightTorchLHS_F1 = 69,
    NewStraightTorchRHS_F1 = 70,
    NewStraightTorchTOP_F1 = 71,
    NewStraightTorchBOT_F1 = 72,
};

const char object_Desc_00[] = "Coin";
const char object_Desc_01[] = "Sack of Coins";
const char object_Desc_02[] = "Donut";
const char object_Desc_03[] = "Key";
const char object_Desc_04[] = "Ham";
const char object_Desc_05[] = "Floater";
const char object_Desc_06[] = "Skull";
const char object_Desc_07[] = "Spider";
const char object_Desc_08[] = "Bat";
const char object_Desc_09[] = "Spanner";
const char object_Desc_10[] = "Potion";
const char object_Desc_11[] = "Big Spider";

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
};