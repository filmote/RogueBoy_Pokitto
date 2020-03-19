#pragma once

#include "Pokitto.h"
#include "utils/Enums.h"
#include "images/Images.h"
#include "entities/Environment.h"
#include "entities/Environments.h"
#include "entities/Bullet.h"
#include "entities/Bullets.h"
#include "entities/Player.h"
#include "entities/Sprite.h"
#include "entities/Sprites.h"
#include "maps/Maps.h"
#include "Player.h"



struct Point {

    int16_t x;
    int16_t y;

};

class Game {
    
    public:

        void setup(/*GameCookie *cookie*/);
        void loop();


        void DrawHealth();
        void DrawHolding();
        void DrawTime();
        void DrawHud();
        void fillRandom();
        uint8_t getSurround8(uint8_t x,uint8_t y,uint8_t b);
        Point setRandomBlock(uint8_t rep,uint8_t blk);
        Point setRandomItem(uint8_t blk);
        void init(uint16_t x, uint16_t y);
        void generateCave();
        bool Intersect(uint16_t Min0, uint16_t Max0, uint16_t Min1, uint16_t Max1);
        bool Collision(uint16_t x, uint16_t y, uint16_t x1, uint16_t y1);
        void RenderEnviroment();
        void RenderPlayer();
        void UpdateMainMenu();
        void TitleText();
        void LoadMAP(uint8_t L);
        void nextLevelLoad();
        void UpdateObjects();
        void RenderObjects();
        void Death();
        void win();
        void MapEnding();
        void UpdateGame();
        void PlayerMovement();
        void UpdateBullets(Bullet &bullet);
        void updateEnvironmentBlock(uint8_t MAP_HEIGHT, uint8_t MAP_WIDTH, uint8_t x, uint8_t y, Environments &Envi);

        void swap(uint8_t & a, uint8_t & b);
        bool between(uint8_t x, uint8_t y, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
        int8_t getTileX(uint16_t x);
        uint8_t getTileY(uint16_t y);
        uint8_t getTileXOffset(uint16_t x);
        uint8_t getTileYOffset(uint16_t y);
        uint16_t getDistance(int x,int y,int x1,int y1);
        uint8_t getBlock(uint8_t MAP_HEIGHT, uint8_t MAP_WIDTH, uint16_t x, uint16_t y);
        void setBlock(uint8_t MAP_HEIGHT, uint8_t MAP_WIDTH, uint8_t x, uint8_t y, uint8_t bl);
        uint8_t getOffset(uint8_t MAP_HEIGHT, uint8_t MAP_WIDTH, uint8_t x, uint8_t y);
        bool isWalkable(uint8_t MAP_HEIGHT, uint8_t MAP_WIDTH, uint16_t x, uint16_t y);
        void dropItem(uint16_t x, uint16_t y, bool EnDrop, Sprites &Objects);
        void SpriteAI(uint8_t MAP_HEIGHT, uint8_t MAP_WIDTH, Player &player, Sprite &sprite);
        void BarrelBreak(uint8_t MAP_HEIGHT, uint8_t MAP_WIDTH, uint8_t x,uint8_t y, Sprites &objects);

    private:

//        GameCookie *cookie;
        uint8_t showarrow;
        Player player;
        Bullets bullets;
        Sprites objects;
        Environments environments;

        GameState gameState = GameState::MainMenu;

        uint8_t Level;
        uint8_t Diff = 1;
        uint8_t Timer = 255;
        bool gameType = true;
        int points = 0;

        uint8_t MAP_HEIGHT = 15;
        uint8_t MAP_WIDTH = 15;
        const uint8_t * Maps[18] = { MAP_1, MAP_2, MAP_3, MAP_4, MAP_5, MAP_6, MAP_7, MAP_8, MAP_9, MAP_10, MAP_11, MAP_12, MAP_13, MAP_14, MAP_15, MAP_16, MAP_17, MAP_18 };
        uint8_t Map[MAP_SIZE];

};


