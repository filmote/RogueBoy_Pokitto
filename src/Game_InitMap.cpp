#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


const int8_t offsets[] = { 
    /* Coin */          0, 
    /* Sack of Cash */  0, 
    /* Bread */         0, 
    /* Key */           0, 
    /* Chickens */      0, 
    /* Floater */       0, 
    /* Skull */         0, 
    /* Spider */        0,
    /* Bat */           0, 
    /* Spanner */       -3, 
    /* Potion */        0, 
    /* BgSpider */      -4,
    /* IceSpell */      -2, 
};

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
            bool active = true;

            auto & object = objects.getSprite(i);
            object.setSprite(px, py, h, static_cast<Object>(type), offsets[type], active);


            // Capture the exit location so we can show the 'cheat' arrow ..

            if (type == MapTiles::DownStairs) {
                this->eolXTile = px;
                this->eolYTile = py;
            }

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
    printf("env[%i] x1: %i, y1: %i, x2 %i, y2 %i\n", i, this->environments.getEnvironment(i).getX(), this->environments.getEnvironment(i).getY(), this->environments.getEnvironment(i).getFinishX(), this->environments.getEnvironment(i).getFinishY());
        }

    }

}


void Game::nextLevelLoad() {

    uint16_t playerX = 0;
    uint16_t playerY = 0;
    uint16_t levelEndX = 0;
    uint16_t levelEndY = 0;


    // Clear any old maps away ..

    this->map.clearMap();

    #ifdef DEBUG
        this->clearCells();
    #endif

    if (map.getLevel() < MAXLEVEL) {

        if (this->randomLevel) {

            uint8_t randomLevel = random(mapRandomLow, mapRandomLow + 4);

            #ifdef DEBUG
                this->level = randomLevel;
            #endif
            uint8_t environmentCount = 0;
            uint8_t objectCount = 0;

            const uint8_t * levelToLoad = this->mapsRandom[randomLevel];//Map_Random_Test;//SJH this->mapsRandom[randomLevel];

            uint16_t cursor = 0;
            uint8_t xSegments = levelToLoad[cursor++];
            uint8_t ySegments = levelToLoad[cursor++];
            printf("Size %i %i\n",xSegments, ySegments);
            
            map.setWidth(xSegments * RANDOM_TILE_SIZE);
            map.setHeight(ySegments * RANDOM_TILE_SIZE);
            map.setTimer(levelToLoad[cursor++]);


            // Work out which segements the player will start and finish in ..

            uint8_t optionsStartEnd = levelToLoad[cursor++];
            uint8_t randomStartEnd = random(0, optionsStartEnd);

            for (uint8_t i = 0; i < optionsStartEnd; i++) {

                if (i == randomStartEnd) {

                    playerX = levelToLoad[cursor++];
                    playerY = levelToLoad[cursor++];
                    levelEndX = levelToLoad[cursor++];
                    levelEndY = levelToLoad[cursor++];

                    #ifdef DEBUG
                        this->playerXStart = playerX;
                        this->playerYStart = playerY;
                        this->eolX = levelEndX;
                        this->eolY = levelEndY;
                    #endif
                    
                }
                else {
                    cursor = cursor + 4;
                }

            }

printf("Player %i %i, EOL %i %i\n",playerX, playerY, levelEndX, levelEndY);


            // Load segments ..

            for (uint8_t ySegment = 0; ySegment < ySegments; ySegment++) {

                for (uint8_t xSegment = 0; xSegment < xSegments; xSegment++) {

                    uint8_t segmentDetails = levelToLoad[cursor++];
                    uint8_t cursorTile = 0;
                    const uint8_t * segmentToLoad = nullptr; // = this->mapsSegments[tileIdx];

                    printf("segmentDetails >  %i, & 128 > %i, & 64 > %i, &32 > %i\n", segmentDetails, segmentDetails & 128, segmentDetails & 64, segmentDetails & 32);

                    // Determine which segement to load ..

                    if ((segmentDetails & BLANK_SEG) > 0) {

                        #ifdef DEBUG
                            this->cells[ySegment][xSegment].isBlank = true;
                        #endif

                    }

                    if ((segmentDetails & ANY_SEG) > 0) {

                        uint8_t segmentType = segmentDetails & 0x1F;
                        uint8_t randomSegment = random(0, mapSegments_Counts[segmentType]);

                        #ifdef DEBUG
                            this->cells[ySegment][xSegment].segment = segmentType;
                            this->cells[ySegment][xSegment].variation = randomSegment;
                            this->cells[ySegment][xSegment].isBlank = false;
                        #endif

                        segmentToLoad = this->getSegment(segmentType, randomSegment);

                    }

                    if ((segmentDetails & THIS_SEG) > 0) {

                        uint8_t segmentType = segmentDetails & 0x1F;
                        uint8_t segmentId = levelToLoad[cursor++];

                        #ifdef DEBUG
                            this->cells[ySegment][xSegment].segment = segmentType;
                            this->cells[ySegment][xSegment].variation = segmentId;
                            this->cells[ySegment][xSegment].isBlank = false;
                        #endif

                        segmentToLoad = this->getSegment(segmentType, segmentId);

                    }




                    // printf("Get tileIdx %i %i %i\n", xSegment, ySegment, tileIdx);
                    //printf("-----------------------------------------------------------------------------\n");

                    if (segmentToLoad != nullptr) {
                            
                        for (uint8_t y = 0; y < RANDOM_TILE_SIZE; y++) {

                            for (uint8_t x = 0; x < RANDOM_TILE_SIZE; x++) {

                                uint8_t tile = segmentToLoad[cursorTile++];
                                this->map.setBlock((xSegment * RANDOM_TILE_SIZE) + x, (ySegment * RANDOM_TILE_SIZE) + y, static_cast<MapTiles>(tile));
                                // printf("%i, ", tile);

                            }
                                
                            // printf("\n");

                        }



                        // Load map options ..

                        uint8_t options = segmentToLoad[cursorTile++];
                        uint8_t randOption = random(0, options);

                        if (options > 0) {
                            //printf("maptiles rand %i of %i options\n", randOption, options);
                            while (true) {

                                uint8_t option = segmentToLoad[cursorTile++];

                                if (option == 255) break;

                                uint8_t tile = segmentToLoad[cursorTile++];
                                uint8_t x = segmentToLoad[cursorTile++];
                                uint8_t y = segmentToLoad[cursorTile++];

                                if (option == randOption) {

                                    this->map.setBlock((xSegment * RANDOM_TILE_SIZE) + x, (ySegment * RANDOM_TILE_SIZE) + y, static_cast<MapTiles>(tile));

                                }

                            }


                            // Load environment  ..

                            while (true) {

                                uint8_t option = segmentToLoad[cursorTile++];

                                if (option == 255) break;

                                int8_t x1 = segmentToLoad[cursorTile++];
                                int8_t y1 = segmentToLoad[cursorTile++];
                                int8_t x2 = segmentToLoad[cursorTile++];
                                int8_t y2 = segmentToLoad[cursorTile++];

                                if (option == randOption) {

                                    auto & environment = this->environments.getEnvironment(environmentCount);
                                    MapTiles tile = this->map.getBlock(x2, y2);
                                    environment.setEnv((xSegment * RANDOM_TILE_SIZE) + x1, (ySegment * RANDOM_TILE_SIZE) + y1, (xSegment * RANDOM_TILE_SIZE) + x2, (ySegment * RANDOM_TILE_SIZE) + y2, true, tile);
                                    environmentCount++;

                                }

                            }

                        }


                        // Load objects ..

                        options = segmentToLoad[cursorTile++];
                        randOption = random(0, options);

                        if (options > 0) {
                            // printf("objects rand %i of %i options\n", randOption, options);
                            while (true) {

                                uint8_t option = segmentToLoad[cursorTile++];

                                if (option == 255) break;

                                uint8_t type = segmentToLoad[cursorTile++];
                                uint16_t x = (segmentToLoad[cursorTile++] * TILE_SIZE) + 8;
                                uint16_t y = (segmentToLoad[cursorTile++] * TILE_SIZE) + 8;
                                uint8_t h = segmentToLoad[cursorTile++];

                                if (option == randOption) {
                                    auto & object = objects.getSprite(objectCount);
                                    object.setSprite((xSegment * RANDOM_TILE_SIZE * TILE_SIZE) + x, (ySegment * RANDOM_TILE_SIZE * TILE_SIZE) + y, h, static_cast<Object>(type), offsets[type], true);
                                    objectCount++;

                                }

                            }

                        }


                        // If this is the entry level, then read in the player starting position ..

                        if (playerX == xSegment && playerY == ySegment) {

                            uint8_t playerOptions = segmentToLoad[cursorTile++];
                            uint8_t playerRandom = random(0, playerOptions);

                            for (uint8_t i = 0; i < playerOptions; i++) {

                                playerX = segmentToLoad[cursorTile++];
                                playerY = segmentToLoad[cursorTile++];

                                if (i == playerRandom) break;

                            }

                            uint16_t px = (xSegment * RANDOM_TILE_SIZE * TILE_SIZE) + (playerX * TILE_SIZE) + 8;
                            uint16_t py = (ySegment * RANDOM_TILE_SIZE * TILE_SIZE) + (playerY * TILE_SIZE) + 8;

                            this->map.setBlock((xSegment * RANDOM_TILE_SIZE) + playerX, (ySegment * RANDOM_TILE_SIZE) + playerY, static_cast<MapTiles>(MapTiles::UpStairs));


                            init(px, py, false);
                            playerX = 0;
                            playerY = 0;

                        }


                        // If this is the exit level, then read in the valid exit positions ..

                        if (levelEndX == xSegment && levelEndY == ySegment) {

                            uint8_t eolOptions = segmentToLoad[cursorTile++];
                            uint8_t eolRandom = random(0, eolOptions);

                            for (uint8_t i = 0; i < eolOptions; i++) {

                                levelEndX = segmentToLoad[cursorTile++];
                                levelEndY = segmentToLoad[cursorTile++];

                                if (i == eolRandom) break;

                            }

                            this->map.setBlock((xSegment * RANDOM_TILE_SIZE) + levelEndX, (ySegment * RANDOM_TILE_SIZE) + levelEndY, static_cast<MapTiles>(MapTiles::DownStairs));
                            this->eolXTile = (xSegment * RANDOM_TILE_SIZE) + levelEndX;
                            this->eolYTile = (ySegment * RANDOM_TILE_SIZE) + levelEndY;
                            levelEndX = 0;
                            levelEndY = 0;

                        }

                    }

                }

            }

            this->environments.setEnvironmentNum(environmentCount);
            this->objects.setObjectNum(objectCount);

            #ifdef DEBUG

                printf("-----------------------------\n");
                printf("W: %i", map.getWidth());
                printf("H: %i",map.getHeight());
                printf("\n-----------------------------\n");


                for (int y=0; y<map.getHeight()/9; y++) {
                    for (int x=0; x<map.getWidth()/9; x++) {
                        if (this->cells[y][x].isBlank) {
                            printf("Blank, ");
                        }
                        else {
                            printf("S%i R%i, ", this->cells[y][x].segment, this->cells[y][x].variation);
                        }
                    }
                    printf("\n");
                }


                uint8_t i = 0;
                for (int y=0; y<map.getHeight(); y++) {
                    if (y % 9 == 0) printf("----------------------------------------------------------------------------------------------------------------------------\n");
                    for (int x=0; x<map.getWidth(); x++) {
                        if (x % 9 == 0) printf(" | ");
                        if (this->map.getBlock(x, y) < 10) printf("0");
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
                    printf("env[%i] x1: %i, y1: %i, x2 %i, y2 %i\n", i, this->environments.getEnvironment(i).getX(), this->environments.getEnvironment(i).getY(), this->environments.getEnvironment(i).getFinishX(), this->environments.getEnvironment(i).getFinishY());
                    }

                }

            #endif


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


const uint8_t * Game::getSegment(uint8_t segmentType, uint8_t segmentIndex) {

    switch (segmentType) {

        case SEG_00:    return mapSegments_Type00[segmentIndex];
        case SEG_01:    return mapSegments_Type01[segmentIndex];
        case SEG_02:    return mapSegments_Type02[segmentIndex];
        case SEG_03:    return mapSegments_Type03[segmentIndex];
        case SEG_04:    return mapSegments_Type04[segmentIndex];
        case SEG_05:    return mapSegments_Type05[segmentIndex];
        case SEG_06:    return mapSegments_Type06[segmentIndex];
        case SEG_07:    return mapSegments_Type07[segmentIndex];
        case SEG_08:    return mapSegments_Type08[segmentIndex];
        case SEG_09:    return mapSegments_Type09[segmentIndex];
        case SEG_10:    return mapSegments_Type10[segmentIndex];
        case SEG_11:    return mapSegments_Type11[segmentIndex];
        case SEG_12:    return mapSegments_Type12[segmentIndex];
        case SEG_13:    return mapSegments_Type13[segmentIndex];
        case SEG_14:    return mapSegments_Type14[segmentIndex];
        case SEG_15:    return mapSegments_Type15[segmentIndex];
        default:        return nullptr;

    }

}

#ifdef DEBUG
void Game::clearCells() {

    for (uint8_t y = 0; y < MAP_SIZE_Y; y++) {

        for (uint8_t x = 0; x < MAP_SIZE_X; x++) {

            this->cells[y][x].segment = 0;
            this->cells[y][x].variation = 0;
            this->cells[y][x].isBlank = false;
            
        }

    }

}
#endif