#pragma once

#include "Pokitto.h"
#include "utils/Enums.h"
#include "utils/Structs.h"
#include "images/Images.h"
#include "entities/Entities.h"

#include "maps/MapSegments_Type_00.h"
#include "maps/MapSegments_Type_01.h"
#include "maps/MapSegments_Type_02.h"
#include "maps/MapSegments_Type_03.h"
#include "maps/MapSegments_Type_04.h"
#include "maps/MapSegments_Type_05.h"
#include "maps/MapSegments_Type_06.h"
#include "maps/MapSegments_Type_07.h"
#include "maps/MapSegments_Type_08.h"
#include "maps/MapSegments_Type_09.h"
#include "maps/MapSegments_Type_10.h"
#include "maps/MapSegments_Type_11.h"
#include "maps/MapSegments_Type_12.h"
#include "maps/MapSegments_Type_13.h"
#include "maps/MapSegments_Type_14.h"
#include "maps/MapSegments_Type_15.h"

#include "maps/Maps.h"
#include "maps/MapStructures.h"


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

        void init(uint16_t x, uint16_t y, bool resetObjects);
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
        const uint8_t * getSegment(uint8_t segmentType, uint8_t segmentIndex);


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
        bool randomLevel = true;

//        const uint8_t * maps[18] = { MAP_1, MAP_2, MAP_3, MAP_4, MAP_5, MAP_6, MAP_7, MAP_9, MAP_10, MAP_11, MAP_12, MAP_13, MAP_14, MAP_15, MAP_16, MAP_17, MAP_18 };
        const uint8_t * maps[20] = { MAP_Test, MAP_1, MAP_2, MAP_3, MAP_4, MAP_5, MAP_Test, MAP_6, MAP_7, MAP_8, MAP_9, MAP_10, MAP_11, MAP_12, MAP_13, MAP_14, MAP_15, MAP_16, MAP_17, MAP_18,  };



       const uint8_t * mapsRandom[1] = { Map_Random_1 };
    
        #define MAP_SEGMENT_TYPE_00_COUNT 3
        #define MAP_SEGMENT_TYPE_01_COUNT 3
        #define MAP_SEGMENT_TYPE_02_COUNT 3
        #define MAP_SEGMENT_TYPE_03_COUNT 3
        #define MAP_SEGMENT_TYPE_04_COUNT 1
        #define MAP_SEGMENT_TYPE_05_COUNT 0
        #define MAP_SEGMENT_TYPE_06_COUNT 0
        #define MAP_SEGMENT_TYPE_07_COUNT 0
        #define MAP_SEGMENT_TYPE_08_COUNT 1
        #define MAP_SEGMENT_TYPE_09_COUNT 0
        #define MAP_SEGMENT_TYPE_10_COUNT 0
        #define MAP_SEGMENT_TYPE_11_COUNT 0
        #define MAP_SEGMENT_TYPE_12_COUNT 0
        #define MAP_SEGMENT_TYPE_13_COUNT 0
        #define MAP_SEGMENT_TYPE_14_COUNT 0
        #define MAP_SEGMENT_TYPE_15_COUNT 0

        const uint8_t * mapSegments_Type00[MAP_SEGMENT_TYPE_00_COUNT] = { MAP_Segment_Type00_00, MAP_Segment_Type00_01, MAP_Segment_Type00_02 };
        const uint8_t * mapSegments_Type01[MAP_SEGMENT_TYPE_01_COUNT] = { MAP_Segment_Type01_00, MAP_Segment_Type01_01, MAP_Segment_Type01_02 };
        const uint8_t * mapSegments_Type02[MAP_SEGMENT_TYPE_02_COUNT] = { MAP_Segment_Type02_00, MAP_Segment_Type02_01, MAP_Segment_Type02_02 };
        const uint8_t * mapSegments_Type03[MAP_SEGMENT_TYPE_03_COUNT] = { MAP_Segment_Type03_00, MAP_Segment_Type03_01, MAP_Segment_Type03_02 };
        const uint8_t * mapSegments_Type04[MAP_SEGMENT_TYPE_04_COUNT] = { MAP_Segment_Type04_00 };
        const uint8_t * mapSegments_Type05[MAP_SEGMENT_TYPE_05_COUNT] = { };
        const uint8_t * mapSegments_Type06[MAP_SEGMENT_TYPE_06_COUNT] = { };
        const uint8_t * mapSegments_Type07[MAP_SEGMENT_TYPE_07_COUNT] = { };
        const uint8_t * mapSegments_Type08[MAP_SEGMENT_TYPE_08_COUNT] = { MAP_Segment_Type08_00 };
        const uint8_t * mapSegments_Type09[MAP_SEGMENT_TYPE_09_COUNT] = { };
        const uint8_t * mapSegments_Type10[MAP_SEGMENT_TYPE_10_COUNT] = { };
        const uint8_t * mapSegments_Type11[MAP_SEGMENT_TYPE_11_COUNT] = { };
        const uint8_t * mapSegments_Type12[MAP_SEGMENT_TYPE_12_COUNT] = { };
        const uint8_t * mapSegments_Type13[MAP_SEGMENT_TYPE_13_COUNT] = { };
        const uint8_t * mapSegments_Type14[MAP_SEGMENT_TYPE_14_COUNT] = { };
        const uint8_t * mapSegments_Type15[MAP_SEGMENT_TYPE_15_COUNT] = { };

        const uint8_t mapSegments_Counts[16] = { MAP_SEGMENT_TYPE_00_COUNT, MAP_SEGMENT_TYPE_01_COUNT, MAP_SEGMENT_TYPE_02_COUNT, MAP_SEGMENT_TYPE_03_COUNT, 
                                                 MAP_SEGMENT_TYPE_04_COUNT, MAP_SEGMENT_TYPE_05_COUNT, MAP_SEGMENT_TYPE_06_COUNT, MAP_SEGMENT_TYPE_07_COUNT, 
                                                 MAP_SEGMENT_TYPE_08_COUNT, MAP_SEGMENT_TYPE_09_COUNT, MAP_SEGMENT_TYPE_10_COUNT, MAP_SEGMENT_TYPE_11_COUNT, 
                                                 MAP_SEGMENT_TYPE_12_COUNT, MAP_SEGMENT_TYPE_13_COUNT, MAP_SEGMENT_TYPE_14_COUNT, MAP_SEGMENT_TYPE_15_COUNT };

        const  uint8_t ** mapSegments_Types[16] = { mapSegments_Type00, mapSegments_Type01, mapSegments_Type02, mapSegments_Type03,
                                                    mapSegments_Type04, mapSegments_Type05, mapSegments_Type06, mapSegments_Type07, 
                                                    mapSegments_Type08, mapSegments_Type09, mapSegments_Type10, mapSegments_Type11, 
                                                    mapSegments_Type12, mapSegments_Type13, mapSegments_Type14, mapSegments_Type15 };

};


