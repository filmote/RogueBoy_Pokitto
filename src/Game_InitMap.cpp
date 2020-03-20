#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


const uint8_t offsets[] = { 0, 12, 8, 9, 10, 11, 3, 4, 5, 6 };

void Game::loadMap(uint8_t L) {

    const uint8_t * CLevel = this->maps[L];

    map.setWidth(CLevel[0] >> 4);
    map.setHeight(CLevel[0] & 0x0F);

    uint8_t UsedMap = map.getWidth()*map.getHeight(); 
    uint16_t px = (((CLevel[1]) >> 4)*16)+8;
    uint16_t py = (((CLevel[1]) & 0x0F)*16)+8;
    uint8_t index = OFFSET;

    init(px, py);


    // Read map data ..

    uint8_t cursor = 0;

    while (true) {

        uint8_t data = CLevel[index];
        uint8_t tile = data >> 3;
        uint8_t run = data & 0x07;

        index++;

        if (run > 0) {

            for (uint8_t x = 0; x < run; x++) {

                this->map.setBlock(cursor, tile);
                cursor++;

            }

        }
        else {

            break;

        }

    }
    

    // Load objects ..

    objects.setObjectNum(CLevel[index++]);

    for (int i = 0; i < MAXOBJECT; i++) {

        uint8_t id = 0;
        uint8_t h = 0;
        uint8_t offset = 0;
        uint16_t px = 0;
        uint16_t py = 0;
        bool active = false;

        if (i < objects.getObjectNum()) {
          id = CLevel[index++];
          px = (((CLevel[index]) >> 4) * TILE_SIZE) + 8;
          py = (((CLevel[index++]) & 0x0f) * TILE_SIZE) + 8;
          h = CLevel[index++];
          active = true;
        }

        auto & object = objects.getSprite(i);
        object.setSprite(px, py, h, id, offsets[id], active);

    }


    // Load environment elements ..

    this->environments.setEnvironmentNum(CLevel[index++]);
    
    for (int i = 0; i < MAXENVIROMENT; i++) {
    
        uint8_t x1 = 0;
        uint8_t y1 = 0;
        uint8_t x2 = 0;
        uint8_t y2 = 0;
        bool active = false;
    
        if (i < this->environments.getEnvironmentNum()) {
          x1 = CLevel[index] >> 4;
          y1 = CLevel[index++] & 0x0f;
          x2 = CLevel[index] >> 4;
          y2 = CLevel[index++] & 0x0f;
          active = true;
        }

        auto & environment = this->environments.getEnvironment(i);
        environment.setEnv(x1, y1, x2, y2, active);

    }



    printf("-----------------------------\n");
    printf("Map: %i", L);
    printf(", W: %i", map.getWidth());
    printf(", H: %i",map.getHeight());
    printf("\n-----------------------------\n");

    uint8_t i = 0;
    for (int x=0; x<map.getWidth(); x++) {
        for (int y=0; y<map.getHeight(); y++) {
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
        this->loadMap(map.getLevel());
        this->map.setLevel(map.getLevel() + 1); 
        gameState = GameState::Game;
    } 
    else {
        gameState = GameState::WinState;
    }

}