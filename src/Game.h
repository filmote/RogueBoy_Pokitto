#pragma once

#include "Pokitto.h"
#include "utils/Enums.h"
#include "utils/Structs.h"
#include "images/Images.h"
#include "entities/Environment.h"
#include "entities/Environments.h"
#include "entities/Bullet.h"
#include "entities/Bullets.h"
#include "entities/Player.h"
#include "entities/Sprite.h"
#include "entities/Sprites.h"
#include "maps/Maps.h"



class Game {
    
    public:

        void setup(/*GameCookie *cookie*/);
        void loop();

        void drawHealth();
        void drawHolding();
        void drawTime();
        void drawHud();
        void renderEnviroment();
        void renderPlayer();

        void updateMainMenu();

        void loadMap(uint8_t L);
        void nextLevelLoad();

        void init(uint16_t x, uint16_t y);
        bool intersect(uint16_t Min0, uint16_t Max0, uint16_t Min1, uint16_t Max1);
        bool collision(uint16_t x, uint16_t y, uint16_t x1, uint16_t y1);
        void updateObjects();
        void renderObjects();
        void death();
        void win();
        void mapEnding();
        void updateGame();
        void playerMovement();
        void updateEnvironmentBlock(MapInformation map, uint8_t x, uint8_t y, Environments &Envi);

        void swap(uint8_t & a, uint8_t & b);
        bool between(uint8_t x, uint8_t y, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
        int8_t getTileX(uint16_t x);
        uint8_t getTileY(uint16_t y);
        uint8_t getTileXOffset(uint16_t x);
        uint8_t getTileYOffset(uint16_t y);
        uint16_t getDistance(int x,int y,int x1,int y1);
        uint8_t getBlock(MapInformation map, uint16_t x, uint16_t y);
        void setBlock(MapInformation map, uint8_t x, uint8_t y, uint8_t bl);
        uint8_t getOffset(MapInformation map, uint8_t x, uint8_t y);
        bool isWalkable(MapInformation map, uint16_t x, uint16_t y);
        void dropItem(uint16_t x, uint16_t y, bool EnDrop, Sprites &Objects);
        void spriteAI(MapInformation map, Player &player, Sprite &sprite);
        void barrelBreak(MapInformation map, uint8_t x,uint8_t y, Sprites &objects);

    private:

        uint8_t showarrow;
        Player player;
        Bullets bullets;
        Sprites objects;
        Environments environments;

        GameState gameState = GameState::MainMenu;

        uint8_t Diff = 1;
        uint8_t timer = 255;
        bool gameType = true;
        int points = 0;

        MapInformation map = { 15, 15 };
        const uint8_t * Maps[18] = { MAP_1, MAP_2, MAP_3, MAP_4, MAP_5, MAP_6, MAP_7, MAP_8, MAP_9, MAP_10, MAP_11, MAP_12, MAP_13, MAP_14, MAP_15, MAP_16, MAP_17, MAP_18 };
        uint8_t Map[MAP_SIZE];

};


