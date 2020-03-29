#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

void Game::updateObjects() {

    for (uint8_t i = 0; i < this->objects.getObjectNum(); i++) {

        auto &objectI = this->objects.getSprite(i);

        if (objectI.getActive()) { 

            bool Ud = true;

            for (uint8_t j = 0; j < this->objects.getObjectNum(); j++) {

                auto &objectJ = this->objects.getSprite(j);

                if (j < i && objectJ.getActive() && this->collision(objectI.getX(), objectI.getY(), objectJ.getX(), objectJ.getY()) && (objectJ.getType() >= 6)) {

                    Ud = false;

                }

            }

            if (Ud) { this->spriteAI(map, player, objectI); }

            if (!objectI.getPreventImmediatePickup() && this->collision(objectI.getX(), objectI.getY(), player.getX(), player.getY())) {

                uint16_t note = 0;
                uint16_t duration = 0;
                uint8_t type = objectI.getType();

                switch (type) {

                    case Object::Coin: 
                        player.setCoins(player.getCoins() + 1); 
                        objectI.setActive(false); 
                        break;

                    case Object::SackOCash: 
                        player.setCoins(player.getCoins() + 5); 
                        objectI.setActive(false); 
                        break;

                    case Object::Key: 
                    case Object::Donut: 
                    case Object::Ham: 
                    case Object::Spanner: 
                    case Object::Potion:             
                        {
                            uint8_t slot = this->player.addInventoryItem(static_cast<Object>(type));

                            if (slot != NO_SLOT_FOUND) {
                                objectI.setActive(false);
                                // sound picked up item
                            }
                            else {
                                // sound could not pick up
                            }

                        }
                        break;

                    case Object::Floater:
                    case Object::Skull:
                    case Object::Spider:
                    case Object::Bat:

                        if (PC::frameCount % 5 == 0) { 

                            switch (type) {

                                case Object::Floater:   
                                    //player.setHealth(player.getHealth() - (10 * diff)); 
                                    break;

                                case Object::Skull: 
                                    //player.setHealth(player.getHealth() - (5 * diff)); 
                                    break;

                                case Object::Spider:
                                    //player.setHealth(player.getHealth() - (2 * diff)); 
                                    break;

                                case Object::Bat: 
                                    //SJH player.setHealth(player.getHealth() - diff); 
                                    break;

                            }

                        }

                        break;

                }

            }

        }

    }


    // Update bullets ..

    // bullets.update();


    // Have the bullets hit anything ?

    for (uint8_t j = 0; j < 6; j++) {

        auto &bullet = bullets.getBullet(j);

        if (bullet.getActive()) {

            Direction xDirection = this->getNearestCardinalDirection(bullet.getDirection(), Axis::XAxis);
            Direction yDirection = this->getNearestCardinalDirection(bullet.getDirection(), Axis::YAxis);

// printf("Bullet: %i, xDir: %i, yDir: %i, ", static_cast<uint8_t>(bullet.getDirection()), static_cast<uint8_t>(xDirection), static_cast<uint8_t>(yDirection));

            uint16_t rx = bullet.getX();
            uint16_t ry = bullet.getY();

// printf("x: %i, y: %i, >> ", rx, ry);

            bullet.update();

// printf("x: %i, y: %i, \n", bullet.getX(), bullet.getY());

            if (xDirection != Direction::None && !this->map.isWalkable(bullet.getX(), ry, xDirection, 4, 4)) {
                bullet.setActive(false);
            }

            if (yDirection != Direction::None && bullet.getActive() && !this->map.isWalkable(rx, bullet.getY(), yDirection, 4, 4)) {
                bullet.setActive(false);
            }


            if (!bullet.getActive()) {

                switch (bullet.getDirection()) {

                    case Direction::Up:     
                        ry-=5; 
                        break;

                    case Direction::UpRight:     
                        rx+=5; 
                        ry-=5; 
                        break;

                    case Direction::Right: 
                        rx+=5; 
                        break;

                    case Direction::DownRight: 
                        rx+=5; 
                        ry+=5; 
                        break;

                    case Direction::Down: 
                        ry+=5; 
                        break;

                    case Direction::DownLeft: 
                        ry+=5; 
                        rx-=5; 
                        break;

                    case Direction::Left: 
                        rx-=5; 
                        break;

                    case Direction::UpLeft: 
                        rx-=5; 
                        ry-=5; 
                        break;

                };

                if (this->map.getBlock(this->map.getTileX(rx), this->map.getTileY(ry)) == 4) {
                    barrelBreak(map, this->map.getTileX(rx), this->map.getTileY(ry), this->objects);
                } 

                bullet.setActive(false);

            }
            else {

                for (uint8_t i = 0; i < this->objects.getObjectNum(); i++) {

                    auto &object = this->objects.getSprite(i);

                    if (object.getActive() && object.isEnemy() && this->collision(object.getX()-4, object.getY()-4, bullet.getX()-4, bullet.getY()-4)) {

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

void Game::updateGame() {
    
    this->playerMovement();
    this->updateObjects();
    this->renderEnviroment();
    this->renderPlayer();
    this->renderObjects();
    this->renderHud();
    
    if (Pokitto::Core::frameCount % 15 == 0) { this->map.decTimer();  }
    if (this->map.getTimer() == 0) { player.setHealth(0); }
    
    if (player.getHealth() <= 0) {
        //sound.tones(DeathNotes); 
        gameState = GameState::Dead;

    }

}


void Game::playerMovement() {

    uint16_t x = player.getX();
    uint16_t y = player.getY();
    Direction direction = player.getDirection();
    bool moving = player.getMoving();

    moving = false;

    if ((PC::buttons.pressed(BTN_UP) || PC::buttons.repeat(BTN_UP, 1))) {

        if (this->map.isWalkable(x, y - 2, Direction::Up, 8, 12)) {
            y-=2;
            moving = true;
        }

        direction = Direction::Up;

    }

    if ((PC::buttons.pressed(BTN_DOWN) || PC::buttons.repeat(BTN_DOWN, 1))) {

        if (this->map.isWalkable(x, y + 2, Direction::Down, 8, 12)) {
            y+=2;
            moving = true;
        }

        direction = Direction::Down;

    }

    if ((PC::buttons.pressed(BTN_RIGHT) || PC::buttons.repeat(BTN_RIGHT, 1))) {

        if (this->map.isWalkable(x + 2, y, Direction::Right, 8, 12)) {
            x+=2;
            moving = true;
        }

        switch (direction) {

            case Direction::Up:
                direction = Direction::UpRight;
                break;

            case Direction::Down:
                direction = Direction::DownRight;
                break;

            default:
                direction = Direction::Right;
                break;
                
        }

    }
    
    if ((PC::buttons.pressed(BTN_LEFT) || PC::buttons.repeat(BTN_LEFT, 1))) {
printf("Left\n");
        if (this->map.isWalkable(x - 2, y, Direction::Left, 8, 12)) {
            x-=2;
            moving = true;
        }

        switch (direction) {

            case Direction::Up:
                direction = Direction::UpLeft;
                break;

            case Direction::Down:
                direction = Direction::DownLeft;
                break;

            default:
                direction = Direction::Left;
                break;
                
        }

    }   

    player.setX(x);
    player.setY(y);
    player.setDirection(direction);
    player.setMoving(moving);

    if (moving) {    
        
        int relx = this->map.getTileX(x);
        int rely = this->map.getTileY(y);
        uint8_t ofx = this->map.getTileXOffset(x);
        uint8_t ofy = this->map.getTileYOffset(y);
        uint8_t block = this->map.getBlock(relx, rely);

        if (this->map. between(3, 3, 11, 11, ofx, ofy) && block == MapTiles::PressPlate) {
            this->map.setBlock(relx,rely,MapTiles::Rubble);
            updateEnvironmentBlock(map, relx, rely, this->environments);
            //sound.tone(NOTE_D2,150,NOTE_E2,50);
        }


        // If the player has moved, then any object he may have previously dropped will be available for pickup once the player has moved off the tile ..

        this->objects.clearPreventImmediatePickup(player);

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


    // Display Inventory?

    if (PC::buttons.pressed(BTN_C)) {

        this->gameState = GameState::Inventory;
        this->inventoryMenu.mainCursor = 0;
  
    }
    

    // Operate lever, open door, fix things ..

    if (PC::buttons.pressed(BTN_A)) {

        int relx = this->map.getTileX(x);
        int rely = this->map.getTileY(y);
        MapTiles block = static_cast<MapTiles>(this->map.getBlock(relx, rely));

        if (block == MapTiles::DownStairs) {
            //sound.tone(NOTE_C3,100,NOTE_E3,100,NOTE_G3,100);
            gameState = GameState::EndOfLevel;
        } 
        else {

            switch(direction) {

                case Direction::Up:         rely--;         break;
                case Direction::UpRight:    relx++; rely--; break;
                case Direction::Right:      relx++;         break;
                case Direction::DownRight:  relx++; rely++; break;
                case Direction::Down:       rely++;         break;
                case Direction::DownLeft:   relx--; rely++; break;
                case Direction::Left:       relx--;         break;
                case Direction::UpLeft:     relx--; rely--; break;

            }

            block = static_cast<MapTiles>(this->map.getBlock(relx, rely));
            this->interactWithBlock(relx, rely, block);

        }

    }

}

// ----------------------------------------------------------------------
//   Handle player's interaction with a 'special' block.
//
//   Returns true if an element was changed.
//
bool Game::interactWithBlock(int x, int y, MapTiles block) {

    switch (block) {

        case MapTiles::SwitchOn: 
            this->map.setBlock(x, y, MapTiles::SwitchOff); 
            printf("%i,%i\n",x,y);
            updateEnvironmentBlock(map, x, y, this->environments); 
            // sound move switch 
            return true;

        case MapTiles::SwitchOff: 
            this->map.setBlock(x, y, MapTiles::SwitchOn); 
            updateEnvironmentBlock(map, x, y, this->environments); 
            // sound move switch 
            return true;

        case MapTiles::ClosedChest: 
            {
                uint8_t slot = this->player.addInventoryItem(Object::Key);

                if (slot != NO_SLOT_FOUND) {

                    this->map.setBlock(x, y, MapTiles::OpenChest); 
                    // sound open chest
                    return true;

                }
                
            }
            return false;

        case MapTiles::LockedDoor: 
            if (this->player.getInventoryCount(Object::Key) > 0) {
                this->map.setBlock(x, y, MapTiles::OpenDoor); 
                this->player.decInventoryItem(Object::Key);
                // sound unlock door
                return true;
            } 
            else {
                // sound missing keys
                return false;
            }  
        case MapTiles::NewDoorTOP: 
            if (this->player.getInventoryCount(Object::Key) > 0) {
                this->map.setBlock(x, y, MapTiles::NewDoorTOPOpen); 
                this->player.decInventoryItem(Object::Key);
                // sound unlock door
                return true;
            } 
            else {
                // sound missing keys
                return false;
            }  
        case MapTiles::NewDoorBOT: 
            if (this->player.getInventoryCount(Object::Key) > 0) {
                this->map.setBlock(x, y, MapTiles::NewDoorBOTOpen); 
                this->player.decInventoryItem(Object::Key);
                // sound unlock door
                return true;
            } 
            else {
                // sound missing keys
                return false;
            }

        case MapTiles::NewDoorLHS: 
            if (this->player.getInventoryCount(Object::Key) > 0) {
                this->map.setBlock(x, y, MapTiles::NewDoorLHSOpen); 
                this->player.decInventoryItem(Object::Key);
                // sound unlock door
                return true;
            } 
            else {
                // sound missing keys
                return false;
            }  

        case MapTiles::NewDoorRHS: 
            if (this->player.getInventoryCount(Object::Key) > 0) {
                this->map.setBlock(x, y, MapTiles::NewDoorRHSOpen); 
                this->player.decInventoryItem(Object::Key);
                // sound unlock door
                return true;
            } 
            else {
                // sound missing keys
                return false;
            }  

        case MapTiles::LockedStairs: 
            if (this->player.getInventoryCount(Object::Key) > 0) {
                this->map.setBlock(x, y, MapTiles::DownStairs); 
                this->player.decInventoryItem(Object::Key);
                // sound unlock door
            } 
            else {
                // sound missing keys
            } 
            return true;

        case MapTiles::SwitchBroken: 
            if (this->player.getInventoryCount(Object::Spanner) > 0) {
                this->map.setBlock(x, y, MapTiles::SwitchOff); 
                this->player.decInventoryItem(Object::Spanner);
                // sound fix
                return true;
            } 
            else {
                // sound missing keys / spanner
                return false;
            } 

    }

    return false;

}


void Game::updateEnvironmentBlock(MapInformation map, uint8_t x, uint8_t y, Environments &environments) {

    for (int i = 0; i < this->environments.getEnvironmentNum(); i++) {

        auto environment = this->environments.getEnvironment(i);

        if (environment.checkStart(x,y) && environment.getActive()) {

            uint8_t x1 = environment.finishX();
            uint8_t y1 = environment.finishY();
printf("block %i\n",this->map.getBlock(x1, y1));
            switch(this->map.getBlock(x1, y1)) {

                case MapTiles::SpearDoor: 
                    this->map.setBlock(x1, y1, MapTiles::OpenDoor); 
                    break;
                
                case MapTiles::OpenDoor: 
//                    this->map.setBlock(x1, y1, MapTiles::SpearDoor); 
                    this->map.setBlock(x1, y1, environment.getTile()); 
                    break;

                case MapTiles::LockedStairs: 
                    this->map.setBlock(x1, y1, MapTiles::DownStairs); 
                    break;

                case MapTiles::DownStairs: 
                    this->map.setBlock(x1, y1, MapTiles::LockedStairs); 
                    break;

                case MapTiles::ExplosiveBarrel: 
                    this->map.setBlock(x1, y1, MapTiles::Rubble); 
                    break;

                case MapTiles::NewDoorLHSOpen: 
                    this->map.setBlock(x1, y1, MapTiles::NewDoorLHS); 
                    break;

            }

        }

    }

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

                object.setSprite((x * TILE_SIZE) + 8, (y * TILE_SIZE) + 8, 1, static_cast<Object>(id), offset, true);

            }
            else{

                object.setSprite(x, y, 1, static_cast<Object>(id), offset, true);

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
                object.setSprite((x * TILE_SIZE) + 8, (y * TILE_SIZE) + 8, 1, static_cast<Object>(id), offset, true);
            }
            else{
                object.setSprite(x, y, 1, static_cast<Object>(id), offset, true);
            }
            
        }
        
    }
    
}


void Game::spriteAI(MapInformation map, Player &player, Sprite &sprite) {

    uint16_t x = sprite.getX();
    uint16_t y = sprite.getY();
        
    switch(sprite.getType()) {

        case Object::Coin: 

            if (Pokitto::Core::frameCount % 5 == 0) { 
                sprite.setFrame(sprite.getFrame() + 1); 
                sprite.setFrame(sprite.getFrame() % 6);
            } 

            break;

        case Object::Floater:            
        case Object::Skull:     
        case Object::Spider:   

            if (this->map.getDistance(x, y, player.getX(), player.getY()) <= 5) {
                if (x < player.getX() && this->map.isWalkable(x + 1, y, Direction::Right, 12, 12))   { x++; }
                if (x > player.getX() && this->map.isWalkable(x - 1, y, Direction::Left, 12, 12))    { x--; }
                if (y < player.getY() && this->map.isWalkable(x, y + 1, Direction::Down, 12, 12))    { y++; }
                if (y > player.getY() && this->map.isWalkable(x, y - 1, Direction::Up, 12, 12))      { y--; }
            }

            break;

        case Object::Bat: 

            if (this->map.getDistance(x, y, player.getX(), player.getY()) < 5) {
                if (x < player.getX() && this->map.isWalkable(x + 1, y, Direction::Right, 12, 12))   { x++; }
                if (x > player.getX() && this->map.isWalkable(x - 1, y, Direction::Left, 12, 12))    { x--; }
                if (y < player.getY() && this->map.isWalkable(x, y + 1, Direction::Down, 12, 12))    { y++; }
                if (y > player.getY() && this->map.isWalkable(x, y - 1, Direction::Up, 12, 12))      { y--; }
            }

            if (Pokitto::Core::frameCount % 5 == 0) { 
                sprite.setFrame(sprite.getFrame() + 1); 
                sprite.setFrame(sprite.getFrame() % 2);
            } 

            break;

    }

    sprite.setPosition(x, y);

}

Direction Game::getNearestCardinalDirection(Direction direction, Axis axis) {

    switch (axis) {

        case Axis::XAxis:

            switch (direction) {

                case Direction::UpLeft:
                case Direction::Left:
                case Direction::DownLeft:

                    return Direction::Left;

                case Direction::Up:
                case Direction::Down:

                    return Direction::None;

                case Direction::UpRight:
                case Direction::Right:
                case Direction::DownRight:

                    return Direction::Right;
                
            }

            break;

        case Axis::YAxis:

            switch (direction) {

                case Direction::UpLeft:
                case Direction::Up:
                case Direction::UpRight:

                    return Direction::Up;

                case Direction::Left:
                case Direction::Right:

                    return Direction::None;

                case Direction::DownLeft:
                case Direction::Down:
                case Direction::DownRight:

                    return Direction::Down;
                
            }

            break;


    }
}