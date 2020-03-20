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
    mapEnding, 
    Dead, 
    WinState
};