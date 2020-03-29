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

        // void drawHealth();
        // void drawHolding();
        // void drawTime();
        // void drawLevel();
        void renderHud();
        void renderEnviroment();
        void renderPlayer();

        void updateMainMenu();
        void loadMap(uint8_t level);
        void nextLevelLoad();

        void showInventory();
        void renderInventoryItem(InventoryItem inventotyItem);

        void init(uint16_t x, uint16_t y);
        bool intersect(uint16_t min0, uint16_t max0, uint16_t min1, uint16_t max1);
        bool collision(uint16_t x, uint16_t y, uint16_t x1, uint16_t y1);
        void updateObjects();
        void renderObjects();
        void death();
        void win();
        void endOfLevel();
        void updateGame();
        void playerMovement();
        bool interactWithBlock(int x, int y, MapTiles block);
        void updateEnvironmentBlock(MapInformation map, uint8_t x, uint8_t y, Environments &Envi);

        void dropItem(uint16_t x, uint16_t y, bool EnDrop, Sprites &Objects);
        void spriteAI(MapInformation map, Player &player, Sprite &sprite);
        void barrelBreak(MapInformation map, uint8_t x,uint8_t y, Sprites &objects);
        Direction getNearestCardinalDirection(Direction direction, Axis axis);

    private:

        Player player;
        Bullets bullets;
        Sprites objects;
        Environments environments;

        GameState gameState = GameState::MainMenu;

        uint8_t diff = 1;
        int points = 0;
        InventoryMenu inventoryMenu;
        
        MapInformation map;

//        const uint8_t * maps[18] = { MAP_1, MAP_2, MAP_3, MAP_4, MAP_5, MAP_6, MAP_7, MAP_8, MAP_9, MAP_10, MAP_11, MAP_12, MAP_13, MAP_14, MAP_15, MAP_16, MAP_17, MAP_18 };
        const uint8_t * maps[19] = { MAP_Test, MAP_1, MAP_2, MAP_3, MAP_4, MAP_5, MAP_6, MAP_7, MAP_8, MAP_9, MAP_10, MAP_11, MAP_12, MAP_13, MAP_14, MAP_15, MAP_16, MAP_17, MAP_18,  };
    
};


