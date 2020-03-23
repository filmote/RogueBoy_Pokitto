#pragma once

enum class Direction : uint8_t {
    Up,
    Down,
    Right,
    Left
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


enum class Rotation : uint8_t {
    Up, 
    UpRight, 
    Right, 
    DownRight,
    Down, 
    DownLeft, 
    Left, 
    UpLeft
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
};

enum MapTiles {
    ClosedChest = 0,
    BlankWall = 1,
    LockedDoor = 2,
    DownStairs = 3,
    Barrel = 4,
    OpenChest = 5,
    OpenDoor = 6,
    FullBlockWall = 7,
    Empty = 8,
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
};