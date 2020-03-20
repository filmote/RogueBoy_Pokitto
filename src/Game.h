#pragma once

#include "Pokitto.h"
#include "utils/Enums.h"
#include "utils/Structs.h"
#include "images/Images.h"
#include "entities/Entities.h"
#include "maps/maps.h"



class Game {
    
    public:

        void setup(/*GameCookie *cookie*/);
        void loop();

    private:

        void drawHealth();
        void drawHolding();
        void drawTime();
        void drawLevel();
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

        uint8_t diff = 1;
        uint8_t timer = 255;
        int points = 0;

        MapInformation map;

        const uint8_t * maps[18] = { MAP_1, MAP_2, MAP_3, MAP_4, MAP_5, MAP_6, MAP_7, MAP_8, MAP_9, MAP_10, MAP_11, MAP_12, MAP_13, MAP_14, MAP_15, MAP_16, MAP_17, MAP_18 };
    
};


