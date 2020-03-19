#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


void Game::fillRandom() {

    uint8_t r = 0;

    for(uint16_t i = 0; i<MAP_SIZE; i++) {
        r = rand() % 2;
        Map[i] = r;
    }

}

uint8_t Game::getSurround8(uint8_t x, uint8_t y, uint8_t b) {

    uint8_t a = 0;

    if (between(0, 0, MAP_WIDTH, MAP_HEIGHT, x+1, y)    &&  getBlock(MAP_HEIGHT, MAP_WIDTH, x+1, y)   == b)  { a++; }
    if (between(0, 0, MAP_WIDTH, MAP_HEIGHT, x-1, y)    &&  getBlock(MAP_HEIGHT, MAP_WIDTH, x-1, y)   == b)  { a++; }
    if (between(0, 0, MAP_WIDTH, MAP_HEIGHT, x,   y+1)  &&  getBlock(MAP_HEIGHT, MAP_WIDTH, x,   y+1) == b)  { a++; }
    if (between(0, 0, MAP_WIDTH, MAP_HEIGHT, x,   y-1)  &&  getBlock(MAP_HEIGHT, MAP_WIDTH, x,   y-1) == b)  { a++; }
    if (between(0, 0, MAP_WIDTH, MAP_HEIGHT, x+1, y+1)  &&  getBlock(MAP_HEIGHT, MAP_WIDTH, x+1, y+1) == b)  { a++; }
    if (between(0, 0, MAP_WIDTH, MAP_HEIGHT, x+1, y-1)  &&  getBlock(MAP_HEIGHT, MAP_WIDTH, x+1, y-1) == b)  { a++; }
    if (between(0, 0, MAP_WIDTH, MAP_HEIGHT, x-1, y+1)  &&  getBlock(MAP_HEIGHT, MAP_WIDTH, x-1, y+1) == b)  { a++; }
    if (between(0, 0, MAP_WIDTH, MAP_HEIGHT, x-1, y-1)  &&  getBlock(MAP_HEIGHT, MAP_WIDTH, x-1, y-1) == b)  { a++; }

    return a;

}


Point Game::setRandomBlock(uint8_t rep,uint8_t blk) {
  bool Done = false;
  Point out;
  do{    
  for(uint8_t i = 0; i < MAP_WIDTH; i++)
      for(uint8_t j = 0; j < MAP_HEIGHT; j++) {
        if ((getBlock(MAP_HEIGHT, MAP_WIDTH, i,j) == rep)&&(random(0,100)==0)) {
          setBlock(MAP_HEIGHT, MAP_WIDTH, i,j,blk);
          out.x = i;
          out.y = j;
          Done = true;
          return out;
        }
      }
  }while(Done == false);
  return out;
}

Point Game::setRandomItem(uint8_t blk) {
  bool Done = false;
  Point out;
  do{    
  for(uint8_t i = 0; i < MAP_WIDTH; i++)
      for(uint8_t j = 0; j < MAP_HEIGHT; j++) {
        if ((getBlock(MAP_HEIGHT, MAP_WIDTH, i,j) == 8)&&(random(0,100)==0)) {
          dropItem(i,j,false, this->objects);
          out.x = i;
          out.y = j;
          Done = true;
          return out;
        }
      }
  } while(Done == false);
  return out;
}

void Game::init(uint16_t x, uint16_t y) {
  //sound.tone(NOTE_C7H,150, NOTE_REST,100, NOTE_C6,150);
  player.setX(x);
  player.setY(y);
  player.setDirection(Direction::Up);
  player.setCoins(0);
  player.setKeys(0);
  player.setKills(0);
  player.setHealth(100);
  
  for (uint8_t i = 0; i < 6; i++) {
    bullets.getBullet(i).kill();
  }
  for (uint8_t i = 0; i < MAXOBJECT; i++) {
      
        auto & object = this->objects.getSprite(i);
        object.setActive(false);
        
  }
  Timer = 255;
  printf("timer=255\n");
}


void Game::generateCave() {
  uint8_t Temp[MAP_SIZE];
  MAP_HEIGHT = 15;
  MAP_WIDTH = 15;
  for(uint8_t i = 0; i < MAP_SIZE; i++) {Temp[i] = 8; Map[i] = 8;}
  fillRandom();
  for(uint8_t count = 0; count < 6; count++) {
    for(uint8_t j = 0; j < MAP_WIDTH; j++)
      for(uint8_t i = 0; i < MAP_HEIGHT; i++) {
        if(((getBlock(MAP_HEIGHT, MAP_WIDTH, i,j) == 0)&&(getSurround8(i,j,0) >= 3))||((getBlock(MAP_HEIGHT, MAP_WIDTH, i,j) == 1)&&(getSurround8(i,j,0) >= 5)))
          Temp[getOffset(MAP_HEIGHT, MAP_WIDTH, i,j)] = 0;
        else
          Temp[getOffset(MAP_HEIGHT, MAP_WIDTH, i,j)] = 1;
    }
    for(uint16_t i = 0; i<MAP_SIZE; i++) { Map[i] = Temp[i]; }
  }
  for(uint8_t i = 0; i < MAP_WIDTH; i++)
      for(uint8_t j = 0; j < MAP_HEIGHT; j++) {
        if (getBlock(MAP_HEIGHT, MAP_WIDTH, i,j) == 0) {
          setBlock(MAP_HEIGHT, MAP_WIDTH, i,j,8);
        } else {
          setBlock(MAP_HEIGHT, MAP_WIDTH, i,j,BARREL);
        }
      }
  setRandomBlock(8,DOWN_STAIRS);
  Point pl = setRandomBlock(8,UP_STAIRS);
  init((pl.x*16)+8,(pl.y*16)+8);
  for(uint8_t count = 0; count < 6; count++) {
    setRandomItem(8);
  }
  Timer = 150;
  printf("timer=150\n");
}


bool Game::Intersect(uint16_t Min0, uint16_t Max0, uint16_t Min1, uint16_t Max1) {
   return ((Max0 > Min1) && (Min0 < Max1));
}

bool Game::Collision(uint16_t x, uint16_t y, uint16_t x1, uint16_t y1) {
  return (Intersect(x,x+8,x1,x1+8)&&Intersect(y,y+8,y1,y1+8));
}







const uint8_t offsets[] = { 0, 12, 8, 9, 10, 11, 3, 4, 5, 6 };

void Game::LoadMAP(uint8_t L) {

    const uint8_t * CLevel = Maps[L];

    MAP_WIDTH = CLevel[0] >> 4;
    MAP_HEIGHT = CLevel[0] & 0x0F;
    uint8_t UsedMap = MAP_WIDTH*MAP_HEIGHT; 
    uint16_t px = (((CLevel[1]) >> 4)*16)+8;
    uint16_t py = (((CLevel[1]) & 0x0F)*16)+8;
    //uint8_t index = OFFSET+UsedMap;
    uint8_t index = OFFSET;

    init(px, py);


    // Read map data ..
    {

      uint8_t cursor = 0;

      while (true) {

        uint8_t data = CLevel[index];
        uint8_t tile = data >> 3;
        uint8_t run = data & 0x07;

        index++;

        if (run > 0) {

          for (uint8_t x = 0; x < run; x++) {

            Map[cursor] = tile;
            cursor++;

          }

        }
        else {
        
          break;
        
        }

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
  printf(", W: %i", MAP_WIDTH);
  printf(", H: %i",MAP_HEIGHT);
  printf("\n-----------------------------\n");

  uint8_t i = 0;
  for (int x=0; x<MAP_WIDTH; x++) {
    for (int y=0; y<MAP_HEIGHT; y++) {
      printf("%i ", Map[i]);
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

    if (gameType) {

        if (Level < MAXLEVEL) {
            LoadMAP(Level);
            Level++; 
            gameState = GameState::Game;
            gameType = !gameType;
        } 
        else {
            gameState = GameState::WinState;
        }

    } 
    else {

        gameState = GameState::Game;
        gameType = !gameType;
        generateCave();

    }

}

void Game::UpdateObjects() {

  for (uint8_t i = 0; i < this->objects.getObjectNum(); i++) {

    auto &objectI = this->objects.getSprite(i);
    
    if (objectI.getActive()) { 

      bool Ud = true;

      for (uint8_t j = 0; j < this->objects.getObjectNum(); j++) {

        auto &objectJ = this->objects.getSprite(j);

        if (j < i && objectJ.getActive() && Collision(objectI.getX(), objectI.getY(), objectJ.getX(), objectJ.getY()) && (objectJ.getType() >= 6)) {

            Ud = false;
            
        }

      }

      if (Ud) { SpriteAI(MAP_HEIGHT, MAP_WIDTH, player, objectI); }
      
      if (Collision(objectI.getX(), objectI.getY(), player.getX(), player.getY())) {

          {
            uint16_t note = 0;
            uint16_t duration = 0;
            uint8_t type = objectI.getType();

            switch (type) {
              
              case 1: 
                player.setCoins(player.getCoins() + 1); 
                objectI.setActive(false); 
                break;

              case 2: 
                player.setCoins(player.getCoins() + 5); 
                objectI.setActive(false); 
                break;

              case 3: 
                player.setHealth(player.getHealth() + 5); 
                objectI.setActive(false); 
                break;

              case 4: 
                player.setKeys(player.getKeys() + 1); 
                objectI.setActive(false); 
                break;

              case 5: 
                player.setHealth(player.getHealth() + 10); 
                objectI.setActive(false); 
                break;

              case 6 ... 9:

                if (PC::frameCount % 5 == 0) { 

                  switch (type) {

                    case 6:   
                      player.setHealth(player.getHealth() - (10 * Diff)); 
                      break;

                    case 7: 
                      player.setHealth(player.getHealth() - (5 * Diff)); 
                      break;
              
                    case 8: 
                      player.setHealth(player.getHealth() - (2 * Diff)); 
                      break;

                    case 9: 
                      player.setHealth(player.getHealth() - Diff); 
                      break;

                  }

                }
                break;
              }

            }

         }

      }
      
  }


  // Update bullets ..

  bullets.update();


  // Have the bullets hit anything ?

  for (uint8_t j = 0; j < 6; j++) {

    auto &bullet = bullets.getBullet(j);

    if (bullet.getActive()) {

      uint16_t rx = bullet.getX();
      uint16_t ry = bullet.getY();
    
      if (!isWalkable(MAP_HEIGHT, MAP_WIDTH, rx,ry)) {

        switch (bullet.getDirection()) {

            case Direction::Up:     
                ry-=5; 
                break;

            case Direction::Down: 
                ry+=5; 
                break;

            case Direction::Right: 
                rx+=5; 
                break;

            case Direction::Left: 
                rx-=5; 
                break;
                
        };

        if (getBlock(MAP_HEIGHT, MAP_WIDTH, getTileX(rx), getTileY(ry)) == 4) {
            BarrelBreak(MAP_HEIGHT, MAP_WIDTH, getTileX(rx), getTileY(ry), this->objects);
        } 

        bullet.setActive(false);

      }
      else {

        for (uint8_t i = 0; i < this->objects.getObjectNum(); i++) {
            
          auto &object = this->objects.getSprite(i);
          
          if (object.getActive() && object.getType() >= 6 && Collision(object.getX()-4, object.getY()-4, bullet.getX()-4, bullet.getY()-4)) {

              object.damage();
              bullet.setActive(false);

              if (!object.getActive()) {
                  player.setKills(player.getKills() + 1);
                  dropItem(object.getX(), object.getY(), true, this->objects);
              }

          }

        }

      }

    }

  }

}

void Game::RenderObjects() {

    objects.render(player);
    bullets.render(player);

}

//const uint16_t DeathNotes[] = {NOTE_A3,500,NOTE_REST,100,NOTE_A3,500,NOTE_REST,100,NOTE_A3,250,NOTE_REST,100,NOTE_A3,250,NOTE_REST,50,NOTE_C3,500,NOTE_REST,100,NOTE_B3,250,NOTE_REST,100,NOTE_B3,250,NOTE_REST,100,NOTE_A3,500,NOTE_REST,100,NOTE_B3,250, TONES_END};


void Game::MapEnding() {
    int padd = player.getCoins() * 5;    
    int kadd = player.getKeys() * 10;
    int killp = player.getKills() * 15;
    PD::setCursor(0,0);
    PD::print("Level:");
    PD::print(Level, 10);
    PD::print("\nKills:");
    PD::print(player.getKills(), 10);
    PD::print("\nCoins:");
    PD::print(player.getCoins(), 10);
    PD::print("\nKeys:");
    PD::print(player.getKeys(), 10);
    PD::print("\nTimeBonus:");
    PD::print(Timer/10);
    PD::print("\nLevel Points:");
    PD::print(kadd+padd+killp+(Timer/10), 10);
    
    PD::print("\nTotal Points:");
    PD::print(this->points+kadd+padd+killp+(Timer/10), 10);
    
    if ((PC::frameCount % 240 == 0) || (PC::buttons.pressed(BTN_A))) {
        gameState = GameState::LoadMap;
        this->points += padd + kadd + killp + (Timer/10);
    }
}


void Game::UpdateGame() {
    PlayerMovement();
    UpdateObjects();
    RenderEnviroment();
    RenderPlayer();
    RenderObjects();
    DrawHud();
    
    if (Pokitto::Core::frameCount % 15 == 0) { Timer--;  }
    if (Timer == 0) { player.setHealth(0); }
    
    if (player.getHealth() <= 0) {
    //sound.tones(DeathNotes); 
        gameState = GameState::Dead;

    }

}


void Game::PlayerMovement() {

    uint16_t x = player.getX();
    uint16_t y = player.getY();
    Direction direction = player.getDirection();
    bool moving = player.getMoving();

    moving = false;

    if ((PC::buttons.pressed(BTN_UP) || PC::buttons.repeat(BTN_UP, 1))) {
        if (isWalkable(MAP_HEIGHT, MAP_WIDTH, x,y-2)) {
            y-=2;
            moving = true;
        }
        direction = Direction::Up;
    }

    if ((PC::buttons.pressed(BTN_DOWN) || PC::buttons.repeat(BTN_DOWN, 1))) {
        if (isWalkable(MAP_HEIGHT, MAP_WIDTH, x,y+2)) {
            y+=2;
            moving = true;
        }
        direction = Direction::Down;
    }

    if ((PC::buttons.pressed(BTN_RIGHT) || PC::buttons.repeat(BTN_RIGHT, 1))) {
        if (isWalkable(MAP_HEIGHT, MAP_WIDTH, x+2,y)) {
            x+=2;
            moving = true;
        }
        direction = Direction::Right;
    }
    
    if ((PC::buttons.pressed(BTN_LEFT) || PC::buttons.repeat(BTN_LEFT, 1))) {
        if (isWalkable(MAP_HEIGHT, MAP_WIDTH, x-2,y)) {
            x-=2;
            moving = true;
        }
        direction = Direction::Left;
    }   

    player.setX(x);
    player.setY(y);
    player.setDirection(direction);
    player.setMoving(moving);

    if (moving) {    
        
        int relx = getTileX(x);
        int rely = getTileY(y);
        uint8_t ofx = getTileXOffset(x);
        uint8_t ofy = getTileYOffset(y);
        uint8_t block = getBlock(MAP_HEIGHT, MAP_WIDTH, relx,rely);

        if (between(3, 3, 11, 11, ofx, ofy) && block == PRESS_PLATE) {
            setBlock(MAP_HEIGHT, MAP_WIDTH, relx,rely,RUBBLE);
            updateEnvironmentBlock(MAP_HEIGHT, MAP_WIDTH, relx, rely, this->environments);
            //sound.tone(NOTE_D2,150,NOTE_E2,50);
        }

    }


    // Shoot a bullet ?

    if (PC::buttons.pressed(BTN_B)) {

        for (uint8_t i = 0; i < 6; i++) {

            if (bullets.getBullet(i).getActive() == false) {
                bullets.getBullet(i).setBullet(x, y, direction);
                //sound.tone(NOTE_F2H,50);
                break;
            }

        }
  
    }

    if (PC::buttons.pressed(BTN_A)) {

        int relx = getTileX(x);
        int rely = getTileY(y);
        uint8_t block = getBlock(MAP_HEIGHT, MAP_WIDTH, relx,rely);

        if (block == DOWN_STAIRS) {
            //sound.tone(NOTE_C3,100,NOTE_E3,100,NOTE_G3,100);
            gameState = GameState::MapEnding;
        } 
        else {

            switch(direction) {
                case Direction::Up: rely--; break;
                case Direction::Down: rely++; break;
                case Direction::Right: relx++; break;
                case Direction::Left: relx--; break;
            }

            block = getBlock(MAP_HEIGHT, MAP_WIDTH, relx,rely);

            switch (block) {

                case SWITCH_ON: 
                    setBlock(MAP_HEIGHT, MAP_WIDTH, relx, rely, SWITCH_OFF); 
                    updateEnvironmentBlock(MAP_HEIGHT, MAP_WIDTH, relx, rely, this->environments); 
                    //sound.tone(NOTE_D3,50,NOTE_E5,50); 
                    break;

                case SWITCH_OFF: 
                    setBlock(MAP_HEIGHT, MAP_WIDTH, relx,rely,SWITCH_ON); 
                    updateEnvironmentBlock(MAP_HEIGHT, MAP_WIDTH, relx, rely, this->environments); 
                    //sound.tone(NOTE_D5,50,NOTE_E3,50); 
                    break;

                case CLOSED_CHEST: 
                    setBlock(MAP_HEIGHT, MAP_WIDTH, relx,rely,OPEN_CHEST); 
                    player.setKeys(player.getKeys() + 1); 
                                    //sound.tone(NOTE_D3,50,NOTE_E5,50); 
                    break;

                case LOCKED_DOOR: 
                    if (player.getKeys() > 0) {
                        setBlock(MAP_HEIGHT, MAP_WIDTH, relx,rely,OPEN_DOOR); 
                        player.setKeys(player.getKeys() - 1);  
                        //sound.tone(NOTE_D3,50,NOTE_E5,50);
                    } 
                    else {
                        //sound.tone(NOTE_D2,150,NOTE_E2,50);
                    }  
                    break;

                case LOCKED_STAIRS: 
                    if (player.getKeys() > 0) {
                        setBlock(MAP_HEIGHT, MAP_WIDTH, relx, rely, DOWN_STAIRS); 
                        player.setKeys(player.getKeys() - 1);
                        //sound.tone(NOTE_D3,50,NOTE_E5,50);
                    } 
                    else {
                        //sound.tone(NOTE_D2,150,NOTE_E2,50);
                    } 
                    break;

            }

        }

    }

}

void Game::updateEnvironmentBlock(uint8_t MAP_HEIGHT, uint8_t MAP_WIDTH, uint8_t x, uint8_t y, Environments &environments) {

    for (int i = 0; i < this->environments.getEnvironmentNum(); i++) {

        auto environment = this->environments.getEnvironment(i);

        if (environment.checkStart(x,y) && environment.getActive()) {

            uint8_t x1 = environment.finishX();
            uint8_t y1 = environment.finishY();

            switch(getBlock(MAP_HEIGHT, MAP_WIDTH, x1, y1)) {

                case SPEAR_DOOR: 
                    setBlock(MAP_HEIGHT, MAP_WIDTH, x1, y1, OPEN_DOOR); 
                    break;
                
                case OPEN_DOOR: 
                    setBlock(MAP_HEIGHT, MAP_WIDTH, x1, y1, SPEAR_DOOR); 
                    break;

                case LOCKED_STAIRS: 
                    setBlock(MAP_HEIGHT, MAP_WIDTH, x1, y1, DOWN_STAIRS); 
                    break;

                case DOWN_STAIRS: 
                    setBlock(MAP_HEIGHT, MAP_WIDTH, x1, y1, LOCKED_STAIRS); 
                    break;

                case EXPLOSIVE_BARREL: 
                    setBlock(MAP_HEIGHT, MAP_WIDTH, x1, y1, RUBBLE); 
                    break;

            }

        }

    }

}


void Game::swap(uint8_t & a, uint8_t & b) {
    uint8_t t = a;
    a = b;
    b = t;
}

    bool Game::between(uint8_t x, uint8_t y, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
        if (x > x1)
            swap(x, x1);
            
        if (y > y1)
            swap(y, y1);
            
        return ((x <= x2) && (x2 <= x1) && (y <= y2) && (y2 <= y1));
    }

    int8_t Game::getTileX(uint16_t x) {
        return (x / TILE_WIDTH);
    }

    uint8_t Game::getTileY(uint16_t y) {
       return (y / TILE_HEIGHT);
    }

    uint8_t Game::getTileXOffset(uint16_t x) {
        return (x % TILE_WIDTH);
    }

    uint8_t Game::getTileYOffset(uint16_t y) {
        return (y % TILE_HEIGHT);
    }

    uint16_t Game::getDistance(int x,int y,int x1,int y1) {uint16_t ret = (abs(getTileX(x)-getTileX(x1))+abs(getTileY(y)-getTileY(y1))); return ret;}

    uint8_t Game::getBlock(uint8_t MAP_HEIGHT, uint8_t MAP_WIDTH, uint16_t x, uint16_t y) {
        if ((x >= MAP_WIDTH) || (y >= MAP_HEIGHT)) {
            return BLANK_WALL;
        } 
        else {
            uint8_t Block = Map[(x + (y * MAP_WIDTH))];
            return Block;
        }
    }

    void Game::setBlock(uint8_t MAP_HEIGHT, uint8_t MAP_WIDTH, uint8_t x, uint8_t y, uint8_t bl) {
        if ((x >= MAP_WIDTH) || (y >= MAP_HEIGHT)) {
            return;
        }
        Map[(x + (y * (MAP_WIDTH)))] = bl;
    }

    uint8_t Game::getOffset(uint8_t MAP_HEIGHT, uint8_t MAP_WIDTH, uint8_t x, uint8_t y) {
        if ((x >= MAP_WIDTH) || (y >= MAP_HEIGHT)) {
            return 0;
        }
        return (x + (y * (MAP_WIDTH)));
    }


    bool Game::isWalkable(uint8_t MAP_HEIGHT, uint8_t MAP_WIDTH, uint16_t x, uint16_t y) {
        uint8_t p[4];
        bool Walk = true; 
        p[0] = (getBlock(MAP_HEIGHT, MAP_WIDTH, getTileX(x-4), getTileY(y-4)));
        p[1] = (getBlock(MAP_HEIGHT, MAP_WIDTH, getTileX(x+3), getTileY(y-4)));
        p[2] = (getBlock(MAP_HEIGHT, MAP_WIDTH, getTileX(x-4), getTileY(y+3)));
        p[3] = (getBlock(MAP_HEIGHT, MAP_WIDTH, getTileX(x+3), getTileY(y+3)));
        for (uint8_t i=0; i<4;i++) {
            if (!((p[i] == OPEN_DOOR)||(p[i] == UP_STAIRS)||(p[i] == DOWN_STAIRS)||(p[i] == EMPTY)||(p[i] == OPEN_CHEST)||(p[i] == RUBBLE)||(p[i] == PRESS_PLATE))) {
                Walk = false;
                break;
            }
        }
        return Walk;
    }

    void Game::dropItem(uint16_t x, uint16_t y, bool EnDrop, Sprites &objects) {
        
        bool newSlot = true;
        uint8_t found = 0;
        
        for (uint8_t i = 0; i < objects.getObjectNum(); i++) {

            auto &obj = this->objects.getSprite(i);
            
            if (!(obj.getActive())) {
                newSlot = false;
                found = i;
                break;
            }

        }

        if (this->objects.getObjectNum() == MAXOBJECT && newSlot) return;

        if (newSlot) {

            if (this->objects.getObjectNum() < MAXOBJECT) {

                uint8_t oNum = this->objects.getObjectNum();
                oNum++;
                this->objects.setObjectNum(oNum);
                
            }
            
            uint8_t id = random(1,5);
            uint8_t offset = 0;
            auto object = this->objects.getSprite(this->objects.getObjectNum());
            
            if ((id != 4) && (id != 2)) {
                
                switch (id) {
                    
                    case 1: offset = 12;  break; //Coin
                    case 3: offset = 9;   break; //Jelly Filled Doughnut
                    case 5: offset = 11;  break; //Ham
                    
                }
                if (!EnDrop) {
                    object.setSprite((x * TILE_SIZE) + 8, (y * TILE_SIZE) + 8, 1, id, offset, true);
                }
                else{
                    object.setSprite(x, y, 1, id, offset, true);
                }
                
            }
            
        } 
        else {
    
            uint8_t id = random(1,5);
            uint8_t offset = 0;
            auto object = this->objects.getSprite(found);
    
            if ((id != 4) && (id != 2)) {
    
                switch (id) {
                    
                    case 1: offset = 12;  break; //Coin
                    case 3: offset = 9;   break; //Jelly Filled Doughnut
                    case 5: offset = 11;  break; //Ham
                    
                }
    
                if (!EnDrop) {
                    object.setSprite((x * TILE_SIZE) + 8, (y * TILE_SIZE) + 8, 1, id, offset, true);
                }
                else{
                    object.setSprite(x, y, 1, id, offset, true);
                }
                
            }
            
        }
        
    }
    
    
    void Game::SpriteAI(uint8_t MAP_HEIGHT, uint8_t MAP_WIDTH, Player &player, Sprite &sprite) {

        uint16_t x = sprite.getX();
        uint16_t y = sprite.getY();
            
        switch(sprite.getType()) {

            case 1: 
                if (Pokitto::Core::frameCount % 5 == 0) { 
                    sprite.setFrame(sprite.getFrame() + 1); 
                    sprite.setFrame(sprite.getFrame() % 6);
                } 
                break;

            case 6:            
            case 7:     
            case 8:   
                if (getDistance(x, y, player.getX(), player.getY()) <= 5) {
                    if (x < player.getX() && isWalkable(MAP_HEIGHT, MAP_WIDTH, x+1,y)) { x++; }
                    if (x > player.getX() && isWalkable(MAP_HEIGHT, MAP_WIDTH, x-1,y)) { x--; }
                    if (y < player.getY() && isWalkable(MAP_HEIGHT, MAP_WIDTH, x,y+1)) { y++; }
                    if (y > player.getY() && isWalkable(MAP_HEIGHT, MAP_WIDTH, x,y-1)) { y--; }
                }
                break;

            case 9: 
                if (getDistance(x, y, player.getX(), player.getY()) < 5) {
                    if (x < player.getX() && isWalkable(MAP_HEIGHT, MAP_WIDTH, x+1,y)) { x++; }
                    if (x > player.getX() && isWalkable(MAP_HEIGHT, MAP_WIDTH, x-1,y)) { x--; }
                    if (y < player.getY() && isWalkable(MAP_HEIGHT, MAP_WIDTH, x,y+1)) { y++; }
                    if (y > player.getY() && isWalkable(MAP_HEIGHT, MAP_WIDTH, x,y-1)) { y--; }
                }
                if (Pokitto::Core::frameCount % 5 == 0) { 
                    sprite.setFrame(sprite.getFrame() + 1); 
                    sprite.setFrame(sprite.getFrame() % 2);
                } 

                //if (Pokitto::Core::frameCount % 5 == 0) { ++Frame; Frame %= 2; } 
                break;

        }

        sprite.setX(x);
        sprite.setY(y);
    
    }

    void Game::BarrelBreak(uint8_t MAP_HEIGHT, uint8_t MAP_WIDTH, uint8_t x, uint8_t y, Sprites &objects) {
        setBlock(MAP_HEIGHT, MAP_WIDTH, x,y,18);
        dropItem(x,y, false, this->objects);
        //sound.tone(NOTE_C3,50, NOTE_C2,50, NOTE_E3,150);
    }

