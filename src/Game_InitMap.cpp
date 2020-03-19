#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


// uint8_t Game::getSurround8(uint8_t x, uint8_t y, uint8_t b) {

//     uint8_t a = 0;

//     if (between(0, 0, MAP_WIDTH, MAP_HEIGHT, x+1, y)    &&  getBlock(MAP_HEIGHT, MAP_WIDTH, x+1, y)   == b)  { a++; }
//     if (between(0, 0, MAP_WIDTH, MAP_HEIGHT, x-1, y)    &&  getBlock(MAP_HEIGHT, MAP_WIDTH, x-1, y)   == b)  { a++; }
//     if (between(0, 0, MAP_WIDTH, MAP_HEIGHT, x,   y+1)  &&  getBlock(MAP_HEIGHT, MAP_WIDTH, x,   y+1) == b)  { a++; }
//     if (between(0, 0, MAP_WIDTH, MAP_HEIGHT, x,   y-1)  &&  getBlock(MAP_HEIGHT, MAP_WIDTH, x,   y-1) == b)  { a++; }
//     if (between(0, 0, MAP_WIDTH, MAP_HEIGHT, x+1, y+1)  &&  getBlock(MAP_HEIGHT, MAP_WIDTH, x+1, y+1) == b)  { a++; }
//     if (between(0, 0, MAP_WIDTH, MAP_HEIGHT, x+1, y-1)  &&  getBlock(MAP_HEIGHT, MAP_WIDTH, x+1, y-1) == b)  { a++; }
//     if (between(0, 0, MAP_WIDTH, MAP_HEIGHT, x-1, y+1)  &&  getBlock(MAP_HEIGHT, MAP_WIDTH, x-1, y+1) == b)  { a++; }
//     if (between(0, 0, MAP_WIDTH, MAP_HEIGHT, x-1, y-1)  &&  getBlock(MAP_HEIGHT, MAP_WIDTH, x-1, y-1) == b)  { a++; }

//     return a;

// }


// Point Game::setRandomBlock(uint8_t rep, uint8_t block) {
  
//     bool done = false;
//     Point out;

//     do {    

//         for(uint8_t i = 0; i < MAP_WIDTH; i++) {

//             for(uint8_t j = 0; j < MAP_HEIGHT; j++) {

//                 if ((getBlock(MAP_HEIGHT, MAP_WIDTH, i,j) == rep)&&(random(0,100)==0)) {

//                     setBlock(MAP_HEIGHT, MAP_WIDTH, i, j, block);
//                     out.x = i;
//                     out.y = j;
//                     done = true;
//                     return out;

//                 }

//             }

//         }

//     }
//     while (done == false);

//     return out;

// }

// Point Game::setRandomItem(uint8_t blk) {

//     bool Done = false;
//     Point out;

//     do {    

//         for(uint8_t i = 0; i < MAP_WIDTH; i++) {

//             for(uint8_t j = 0; j < MAP_HEIGHT; j++) {

//                 if ((getBlock(MAP_HEIGHT, MAP_WIDTH, i,j) == 8)&&(random(0,100)==0)) {

//                     dropItem(i,j,false, this->objects);
//                     out.x = i;
//                     out.y = j;
//                     Done = true;
//                     return out;

//                 }

//             }
//         }

//     } 
//     while(Done == false);

//     return out;

// }

// void Game::init(uint16_t x, uint16_t y) {

//     //sound.tone(NOTE_C7H,150, NOTE_REST,100, NOTE_C6,150);
//     player.setX(x);
//     player.setY(y);
//     player.setDirection(Direction::Up);
//     player.setCoins(0);
//     player.setKeys(0);
//     player.setKills(0);
//     player.setHealth(100);

//     for (uint8_t i = 0; i < 6; i++) {

//         bullets.getBullet(i).kill();

//     }

//     for (uint8_t i = 0; i < MAXOBJECT; i++) {

//         auto & object = this->objects.getSprite(i);
//         object.setActive(false);

//     }

//     Timer = 255;
//     printf("timer=255\n");

// }


// void Game::generateCave() {

//     uint8_t temp[MAP_SIZE];
//     MAP_HEIGHT = 15;
//     MAP_WIDTH = 15;

//     for(uint8_t i = 0; i < MAP_SIZE; i++) {
//         temp[i] = 8; Map[i] = 8;
//     }

//     fillRandom();

//     for (uint8_t count = 0; count < 6; count++) {

//         for (uint8_t j = 0; j < MAP_WIDTH; j++) {

//             for (uint8_t i = 0; i < MAP_HEIGHT; i++) {

//                 if (((getBlock(MAP_HEIGHT, MAP_WIDTH, i,j) == 0)&&(getSurround8(i,j,0) >= 3))||((getBlock(MAP_HEIGHT, MAP_WIDTH, i,j) == 1)&&(getSurround8(i,j,0) >= 5))) {

//                     temp[getOffset(MAP_HEIGHT, MAP_WIDTH, i,j)] = 0;

//                 }
//                 else {

//                     temp[getOffset(MAP_HEIGHT, MAP_WIDTH, i,j)] = 1;

//                 }

//             }

//             for(uint16_t i = 0; i < MAP_SIZE; i++) { 
            
//                 Map[i] = temp[i]; 
            
//             }

//         }

//     }

//     for (uint8_t i = 0; i < MAP_WIDTH; i++) {

//         for(uint8_t j = 0; j < MAP_HEIGHT; j++) {

//             if (getBlock(MAP_HEIGHT, MAP_WIDTH, i, j) == 0) {
//                 setBlock(MAP_HEIGHT, MAP_WIDTH, i, j, 8);
//             } 
//             else {
//                 setBlock(MAP_HEIGHT, MAP_WIDTH, i, j, BARREL);
//             }

//         }

//     }

//     setRandomBlock(8, DOWN_STAIRS);
//     Point pl = setRandomBlock(8, UP_STAIRS);
//     init((pl.x*16)+8,(pl.y*16)+8);

//     for(uint8_t count = 0; count < 6; count++) {
//         setRandomItem(8);
//     }

//     Timer = 150;
//     printf("timer=150\n");

// }

// const uint8_t offsets[] = { 0, 12, 8, 9, 10, 11, 3, 4, 5, 6 };

// void Game::LoadMAP(uint8_t L) {

//     const uint8_t * CLevel = Maps[L];

//     MAP_WIDTH = CLevel[0] >> 4;
//     MAP_HEIGHT = CLevel[0] & 0x0F;
//     uint8_t UsedMap = MAP_WIDTH*MAP_HEIGHT; 
//     uint16_t px = (((CLevel[1]) >> 4)*16)+8;
//     uint16_t py = (((CLevel[1]) & 0x0F)*16)+8;
//     //uint8_t index = OFFSET+UsedMap;
//     uint8_t index = OFFSET;

//     init(px, py);


//     // Read map data ..
//     {

//       uint8_t cursor = 0;

//       while (true) {

//         uint8_t data = CLevel[index];
//         uint8_t tile = data >> 3;
//         uint8_t run = data & 0x07;

//         index++;

//         if (run > 0) {

//           for (uint8_t x = 0; x < run; x++) {

//             Map[cursor] = tile;
//             cursor++;

//           }

//         }
//         else {
        
//           break;
        
//         }

//       }

//     }
    

//     // Load objects ..

//     objects.setObjectNum(CLevel[index++]);

//     for (int i = 0; i < MAXOBJECT; i++) {

//         uint8_t id = 0;
//         uint8_t h = 0;
//         uint8_t offset = 0;
//         uint16_t px = 0;
//         uint16_t py = 0;
//         bool active = false;

//         if (i < objects.getObjectNum()) {
//           id = CLevel[index++];
//           px = (((CLevel[index]) >> 4) * TILE_SIZE) + 8;
//           py = (((CLevel[index++]) & 0x0f) * TILE_SIZE) + 8;
//           h = CLevel[index++];
//           active = true;
//         }

//         auto & object = objects.getSprite(i);
//         object.setSprite(px, py, h, id, offsets[id], active);

//     }


//     // Load environment elements ..

//     this->environments.setEnvironmentNum(CLevel[index++]);
    
//     for (int i = 0; i < MAXENVIROMENT; i++) {
    
//         uint8_t x1 = 0;
//         uint8_t y1 = 0;
//         uint8_t x2 = 0;
//         uint8_t y2 = 0;
//         bool active = false;
    
//         if (i < this->environments.getEnvironmentNum()) {
//           x1 = CLevel[index] >> 4;
//           y1 = CLevel[index++] & 0x0f;
//           x2 = CLevel[index] >> 4;
//           y2 = CLevel[index++] & 0x0f;
//           active = true;
//         }

//         auto & environment = this->environments.getEnvironment(i);
//         environment.setEnv(x1, y1, x2, y2, active);

//     }



//   printf("-----------------------------\n");
//   printf("Map: %i", L);
//   printf(", W: %i", MAP_WIDTH);
//   printf(", H: %i",MAP_HEIGHT);
//   printf("\n-----------------------------\n");

//   uint8_t i = 0;
//   for (int x=0; x<MAP_WIDTH; x++) {
//     for (int y=0; y<MAP_HEIGHT; y++) {
//       printf("%i ", Map[i]);
//       i++;
//     }
//     printf("\n");
//   }

//   printf("Obj: %i", this->objects.getObjectNum());
//   printf(", Env: %i\n", this->environments.getEnvironmentNum());

//   for (int i=0; i<MAXOBJECT; i++) {

//     if (objects.getSprite(i).getActive()) {
//       printf("obj[%i] x: %i, y: %i, type: %i, health %1 \n", i, objects.getSprite(i).getX(), objects.getSprite(i).getY(), objects.getSprite(i).getType(), objects.getSprite(i).getHealth());
//     }

//   }

//   printf("\n");
//   for (int i=0; i<MAXENVIROMENT; i++) {

//     if (this->environments.getEnvironment(i).getActive()) {
//       printf("env[%i] x1: %i, y1: %i, x2 %i, y2 %i\n", i, this->environments.getEnvironment(i).getX(), this->environments.getEnvironment(i).getY(), this->environments.getEnvironment(i).finishX(), this->environments.getEnvironment(i).finishY());

//     }

//   }



// }

// void Game::nextLevelLoad() {

//     if (gameType) {

//         if (Level < MAXLEVEL) {
//             LoadMAP(Level);
//             Level++; 
//             gameState = GameState::Game;
//             gameType = !gameType;
//         } 
//         else {
//             gameState = GameState::WinState;
//         }

//     } 
//     else {

//         gameState = GameState::Game;
//         gameType = !gameType;
//         generateCave();
        
//     }

// }