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
};
