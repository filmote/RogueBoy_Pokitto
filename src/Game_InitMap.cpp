#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


const uint8_t offsets[] = { 0, 12, 8, 9, 10, 11, 3, 4, 5, 6 };

void Game::loadMap(uint8_t level) {

    const uint8_t * levelToLoad = this->maps[level];
    uint16_t cursor = 0;

    map.setWidth(levelToLoad[cursor++]);
    map.setHeight(levelToLoad[cursor++]);

    //uint8_t UsedMap = map.getWidth() * map.getHeight(); 

    uint16_t px = (levelToLoad[cursor++] * TILE_SIZE) + 8;
    uint16_t py = (levelToLoad[cursor++] * TILE_SIZE) + 8;

    init(px, py, true);

    map.setTimer(levelToLoad[cursor++]);


    // Read map data ..

    for (uint16_t idx = 0; idx < map.getWidth() * map.getHeight(); idx++) {

        uint8_t tile = levelToLoad[cursor];
        this->map.setBlock(idx, static_cast<MapTiles>(tile));
        cursor++;

    }

    // Load objects ..

    objects.setObjectNum(levelToLoad[cursor++]);

    for (int i = 0; i < MAXOBJECT; i++) {

        if (i < objects.getObjectNum()) {

            uint8_t type = levelToLoad[cursor++];
            uint16_t px = (levelToLoad[cursor++] * TILE_SIZE) + 8;
            uint16_t py = (levelToLoad[cursor++] * TILE_SIZE) + 8;
            uint8_t h = levelToLoad[cursor++];
            uint8_t offset = 0;
            bool active = true;

            auto & object = objects.getSprite(i);
            object.setSprite(px, py, h, static_cast<Object>(type), offsets[type], active);

        }

    }


    // Load environment elements ..

    this->environments.setEnvironmentNum(levelToLoad[cursor++]);
    
    for (int i = 0; i < MAXENVIROMENT; i++) {
    
        if (i < this->environments.getEnvironmentNum()) {

            uint8_t x1 = levelToLoad[cursor++];
            uint8_t y1 = levelToLoad[cursor++];
            uint8_t x2 = levelToLoad[cursor++];
            uint8_t y2 = levelToLoad[cursor++];
            bool active = true;

            auto & environment = this->environments.getEnvironment(i);
            MapTiles tile = this->map.getBlock(x2, y2);
            environment.setEnv(x1, y1, x2, y2, active, tile);

        }

    }



    printf("-----------------------------\n");
    printf("Map: %i", level);
    printf(", W: %i", map.getWidth());
    printf(", H: %i",map.getHeight());
    printf("\n-----------------------------\n");

    uint8_t i = 0;
    for (int y=0; y<map.getHeight(); y++) {
        for (int x=0; x<map.getWidth(); x++) {
    printf("%i ", this->map.getBlock(x, y));
            i++;
        }
    printf("\n");
    }

    printf("Obj: %i", this->objects.getObjectNum());
    printf(", Env: %i\n", this->environments.getEnvironmentNum());

    for (int i=0; i<MAXOBJECT; i++) {

        if (objects.getSprite(i).getActive()) {
    printf("obj[%i] x: %i, y: %i, type: %i, health %1 \n", i, objects.getSprite(i).getX(), objects.getSprite(i).getY(), objects.getSprite(i).getType(), objects.getSprite(i).getHealth());
        }

    }

    printf("\n");
    for (int i=0; i<MAXENVIROMENT; i++) {

        if (this->environments.getEnvironment(i).getActive()) {
    printf("env[%i] x1: %i, y1: %i, x2 %i, y2 %i\n", i, this->environments.getEnvironment(i).getX(), this->environments.getEnvironment(i).getY(), this->environments.getEnvironment(i).finishX(), this->environments.getEnvironment(i).finishY());
        }

    }

}


void Game::nextLevelLoad() {

    if (map.getLevel() < MAXLEVEL) {

        if (this->randomLevel) {

            uint8_t randomLevel = 0; //SJH
            uint8_t environmentCount = 0;
            uint8_t objectCount = 0;

            const uint8_t * levelToLoad = this->mapsRandom[randomLevel];

            uint16_t cursor = 0;
            uint8_t xTiles = levelToLoad[cursor++];
            uint8_t yTiles = levelToLoad[cursor++];
printf("Szie %i %i\n",xTiles, yTiles);
            
            map.setWidth(xTiles * RANDOM_TILE_SIZE);
            map.setHeight(yTiles * RANDOM_TILE_SIZE);
            map.setTimer(levelToLoad[cursor++]);

            for (uint8_t yTilesIdx = 0; yTilesIdx < yTiles; yTilesIdx++) {

                for (uint8_t xTilesIdx = 0; xTilesIdx < xTiles; xTilesIdx++) {

                    uint8_t tileIdx = levelToLoad[cursor++];
                    uint8_t cursorTile = 0;
                    const uint8_t * tileToLoad = this->mapsSegments[tileIdx];
printf("Get tileIdx %i %i %i\n", xTilesIdx, yTilesIdx, tileIdx);

                    for (uint8_t y = 0; y < RANDOM_TILE_SIZE; y++) {
                        for (uint8_t x = 0; x < RANDOM_TILE_SIZE; x++) {

                            uint8_t tile = tileToLoad[cursorTile++];
                            this->map.setBlock((xTilesIdx * RANDOM_TILE_SIZE) + x, (yTilesIdx * RANDOM_TILE_SIZE) + y, static_cast<MapTiles>(tile));

                        }

                    }



                    // Load map options ..

                    uint8_t options = tileToLoad[cursorTile++];
                    uint8_t randOption = random(0, options);

                    if (options > 0) {
printf("rand %i\n", randOption);
                        while (true) {

                            uint8_t option = tileToLoad[cursorTile++];

                            if (option == 255) break;

                            uint8_t tile = tileToLoad[cursorTile++];
                            uint8_t x = tileToLoad[cursorTile++];
                            uint8_t y = tileToLoad[cursorTile++];

                            if (option == randOption) {

                                this->map.setBlock((xTilesIdx * RANDOM_TILE_SIZE) + x, (yTilesIdx * RANDOM_TILE_SIZE) + y, static_cast<MapTiles>(tile));

                            }

                        }

                        // Load environment 
                        while (true) {

                            uint8_t option = tileToLoad[cursorTile++];

                            if (option == 255) break;

                            uint8_t x1 = tileToLoad[cursorTile++];
                            uint8_t y1 = tileToLoad[cursorTile++];
                            uint8_t x2 = tileToLoad[cursorTile++];
                            uint8_t y2 = tileToLoad[cursorTile++];
    printf("Env > %i,%i,%i,%i\n",x1,y1,x2,y2 );

                            if (option == randOption) {

                                auto & environment = this->environments.getEnvironment(environmentCount);
                                MapTiles tile = this->map.getBlock(x2, y2);
                                environment.setEnv((xTilesIdx * RANDOM_TILE_SIZE) + x1, (yTilesIdx * RANDOM_TILE_SIZE) + y1, (xTilesIdx * RANDOM_TILE_SIZE) + x2, (yTilesIdx * RANDOM_TILE_SIZE) + y2, true, tile);
                                environmentCount++;

                            }

                        }

                    }


                    // Load objects ..

                    options = tileToLoad[cursorTile++];
                    randOption = random(0, options);

                    if (options > 0) {
printf("objects rand %i of %i options\n", randOption, options);
                        while (true) {

                            uint8_t option = tileToLoad[cursorTile++];

                            if (option == 255) break;

                            uint8_t type = tileToLoad[cursorTile++];
                            uint16_t x = (tileToLoad[cursorTile++] * TILE_SIZE) + 8;
                            uint16_t y = (tileToLoad[cursorTile++] * TILE_SIZE) + 8;
                            uint8_t h = tileToLoad[cursorTile++];

                            if (option == randOption) {
printf("add object %i at %i, %i > %i, %i\n", type, x, y, (xTilesIdx * RANDOM_TILE_SIZE * TILE_SIZE) + x, (yTilesIdx * RANDOM_TILE_SIZE * TILE_SIZE) + y);
                                auto & object = objects.getSprite(objectCount);
                                object.setSprite((xTilesIdx * RANDOM_TILE_SIZE * TILE_SIZE) + x, (yTilesIdx * RANDOM_TILE_SIZE * TILE_SIZE) + y, h, static_cast<Object>(type), offsets[type], true);
                                objectCount++;

                            }

                        }

                    }


                }

            }


           
    uint16_t px = (4 * TILE_SIZE) + 8;
    uint16_t py = (6 * TILE_SIZE) + 8;


            init(px, py, false);


            this->environments.setEnvironmentNum(environmentCount);
            this->objects.setObjectNum(objectCount);





    printf("-----------------------------\n");
//    printf("Map: %i", level);
    printf(", W: %i", map.getWidth());
    printf(", H: %i",map.getHeight());
    printf("\n-----------------------------\n");

    uint8_t i = 0;
    for (int y=0; y<map.getHeight(); y++) {
        for (int x=0; x<map.getWidth(); x++) {
    printf("%i ", this->map.getBlock(x, y));
            i++;
        }
    printf("\n");
    }

    printf("Obj: %i", this->objects.getObjectNum());
    printf(", Env: %i\n", this->environments.getEnvironmentNum());

    for (int i=0; i<MAXOBJECT; i++) {

        if (objects.getSprite(i).getActive()) {
            printf("obj[%i] x: %i, y: %i, type: %i, health %1 \n", i, objects.getSprite(i).getX(), objects.getSprite(i).getY(), objects.getSprite(i).getType(), objects.getSprite(i).getHealth());
        }

    }

    printf("\n");
    for (int i=0; i<MAXENVIROMENT; i++) {

        if (this->environments.getEnvironment(i).getActive()) {
    printf("env[%i] x1: %i, y1: %i, x2 %i, y2 %i\n", i, this->environments.getEnvironment(i).getX(), this->environments.getEnvironment(i).getY(), this->environments.getEnvironment(i).finishX(), this->environments.getEnvironment(i).finishY());
        }

    }







        }
        else {
        
            this->loadMap(map.getLevel());
            this->map.setLevel(map.getLevel() + 1); 

        }
        
        gameState = GameState::Game;

    } 
    else {
        gameState = GameState::WinState;
    }

}