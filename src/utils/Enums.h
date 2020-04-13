#pragma once

enum Object {
    Coin = 0,
    SackOCash = 1,
    Bread = 2,
    Key = 3,
    Chicken = 4, 
    Floater = 5,
    Skull = 6,
    Spider = 7, 
    Bat = 8,
    Tools = 9,
    Potion = 10,
    BigSpider = 11, 
    IceSpell = 12,
    GreenSpell = 13,
    YellowSpell = 14,
    MauveSpell = 15,
    FireBall = 255
};

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
    SplashScreen,
    MainMenu, 
    Settings, 
    Game, 
    LoadMap,
    GameOver, 
    EndOfLevel, 
    Dead, 
    WinState,
    Inventory,
    MapDetails
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
    StraightRHS = 21,
    StraightTOP = 22,
    StraightLHS = 23,
    StraightBOT = 24,
    TriangleTL = 25,
    TriangleTR = 26,
    TriangleLL = 27,
    TriangleLR = 28,
    CornerFillLR = 29,
    CornerFillLL = 30,
    CornerFillTR = 31,
    CornerFillTL = 32,
    FullSquare = 33,
    CornerLL = 34,
    CornerLR = 35,
    CornerTR = 36,
    CornerTL = 37,
    Fill = 38,
    DoorLHS = 39,
    DoorRHS = 40,
    DoorTOP = 41,
    DoorBOT = 42,
    StraightLR = 43,
    StraightTB = 44,
    EndTRL = 45,
    EndRBL = 46,
    EndTBL = 47,
    EndTRB = 48,
    FillTLTR = 49,
    FillTRBR = 50,
    FillBLBR = 51,
    FillTLBL = 52,
    DoorLHSOpen = 53,
    DoorRHSOpen = 54,
    DoorTOPOpen = 55,
    DoorBOTOpen = 56,
    SpearDoorLHS = 57,
    SpearDoorRHS = 58,
    SpearDoorTOP = 59,
    SpearDoorBOT = 60,
    SpearDoorLHSOpen = 61,
    SpearDoorRHSOpen = 62,
    SpearDoorTOPOpen = 63,
    SpearDoorBOTOpen = 64,
    StraightTorchLHS_F0 = 65,
    StraightTorchRHS_F0 = 66,
    StraightTorchTOP_F0 = 67,
    StraightTorchBOT_F0 = 68,
    StraightTorchLHS_F1 = 69,
    StraightTorchRHS_F1 = 70,
    StraightTorchTOP_F1 = 71,
    StraightTorchBOT_F1 = 72,
    WormHole_F0 = 73,
    WormHole_F1 = 74,
    WormHole_F2 = 75,
    WormHole_F3 = 76,
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
const char object_Desc_10[] = "Potion";
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