#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

void Game::updateObjects() {

    this->player.decWeaponCount();
    if (this->shake > 0) this->shake--;
    if (this->shockwave > 0) this->shockwave--;


    // Update other objects ..

    for (uint8_t i = 0; i < this->objects.getObjectNum(); i++) {

        auto &objectI = this->objects.getSprite(i);

        if (objectI.getActive()) { 


            // Reduce the health bar visual indicator counter ..

            objectI.decHealthBarCounter();


            // Dow we need to update the object?

            bool update = true;

            for (uint8_t j = 0; j < this->objects.getObjectNum(); j++) {

                auto &objectJ = this->objects.getSprite(j);

                if (j < i && objectJ.getActive() && this->collision(objectI, objectJ) && (objectJ.getType() >= 6)) {

                    update = false;

                }

            }


            if (update) { this->spriteAI(map, player, objectI); }


            // Has a collision between two objects occurred ?

            if (!objectI.getPreventImmediatePickup() && this->collision(player, objectI, true)) {

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
                    case Object::Bread:
                    case Object::Chicken:
                    case Object::Spanner:
                    case Object::Potion:
                    case Object::IceSpell:
                    case Object::MauveSpell:
                        {
                            uint8_t slot = this->player.addInventoryItem(static_cast<Object>(type), 1);

                            if (slot != NO_SLOT_FOUND) {
                                objectI.setActive(false);
                                // sound picked up item
                            }
                            else {
                                // sound could not pick up
                            }

                        }
                        break;

                    case Object::GreenSpell:
                    case Object::YellowSpell:
                        {
                            uint8_t slot = this->player.addInventoryItem(static_cast<Object>(type), objectI.getQuantity());

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
                    case Object::BigSpider:
                    case Object::Bat:

                        if (this->shake < 3) {
                            this->shake = this->shake + 2;
                        }

                        if (PC::frameCount % 5 == 0) { 

                            switch (type) {

                                case Object::Floater:   
                                    //SJH 
                                    player.setHealth(player.getHealth() - (10 * diff)); 
                                    break;

                                case Object::Skull: 
                                    //SJH 
                                    player.setHealth(player.getHealth() - (5 * diff)); 
                                    break;

                                case Object::Spider:
                                    //SJH 
                                    player.setHealth(player.getHealth() - (2 * diff)); 
                                    break;

                                case Object::BigSpider:
                                    //SJH 
                                    player.setHealth(player.getHealth() - (6 * diff)); 
                                    break;

                                case Object::Bat: 
                                    //SJH 
                                    player.setHealth(player.getHealth() - diff); 
                                    break;

                            }

                        }

                        break;

                }

            }

        }

    }


    // Have the bullets hit anything ?

    for (uint8_t j = 0; j < 6; j++) {

        auto &bullet = bullets.getBullet(j);

        if (bullet.getActive()) {

            Direction xDirection = this->getNearestCardinalDirection(bullet.getDirection(), Axis::XAxis);
            Direction yDirection = this->getNearestCardinalDirection(bullet.getDirection(), Axis::YAxis);

            uint16_t rx = bullet.getX();
            uint16_t ry = bullet.getY();

            bullet.update();

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

                    if (object.getActive() && object.isEnemy() && this->collision(object, bullet)) {

                        object.damage(bullet.getWeapon());
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
    
    // const uint8_t offX[4] = { 0, 1, 0, -1 };
    // const uint8_t offY[4] = { 1, 0, -1, 0 };
    // const uint8_t offX[4] = { 1, -1,};
    // const uint8_t offY[4] = { -1, 1 };
    const uint8_t offX[4] = { 1, 0,};
    const uint8_t offY[4] = { 0, 1 };

    this->playerMovement();
    this->updateObjects();

    if (this->shake > 0) {
        this->renderEnviroment(offX[(this->shake - 1) % 2], offY[(this->shake - 1) % 2]);
        this->renderPlayer(offX[(this->shake - 1) % 2], offY[(this->shake - 1) % 2]);
    }
    else {
        this->renderEnviroment(0, 0);
        this->renderPlayer(0, 0);
    }

    this->renderObjects();
    this->renderHud();
    
    if (Pokitto::Core::frameCount % 15 == 0) { this->map.decTimer();  }
    if (this->map.getTimer() == 0) { player.setHealth(0); }

    if (player.getHealth() <= 0) {
        //sound.tones(DeathNotes); 
        gameState = GameState::Dead;

    }

}

bool Game::isBlockedByEnemy(Player player, uint16_t playerX, uint16_t playerY) {

    Rect playerRect = { playerX - (player.getWidth() / 2), playerY - (player.getHeight() / 2), player.getWidth(), player.getHeight() };

    for (uint8_t i = 0; i < this->objects.getObjectNum(); i++) {

        auto &object = this->objects.getSprite(i);

        if (object.getActive() && object.isEnemy()) {
            
            Rect objectRect = { object.getX() - (object.getWidth() / 2),  object.getY() - (object.getHeight() / 2), object.getWidth(), object.getHeight() };

            if (collide(playerRect, objectRect)) return true;

        }

    }

    return false;

}

bool Game::isBlockedByPlayer(Player player, Sprite enemy, uint16_t enemyX, uint16_t enemyY) {
   
    Rect playerRect = { this->player.getX() - (player.getWidth() / 2), this->player.getY() - (player.getHeight() / 2), player.getWidth(), player.getHeight() };
    Rect enemyRect = { enemyX - (enemy.getWidth() / 2), enemyY - (enemy.getHeight() / 2), enemy.getWidth(), enemy.getHeight() };

    return collide(playerRect, enemyRect);

}

void Game::playerMovement() {

    uint16_t x = player.getX();
    uint16_t y = player.getY();
    Direction direction = player.getDirection();
    bool moving = player.getMoving();

    moving = false;

    if ((PC::buttons.pressed(BTN_UP) || PC::buttons.repeat(BTN_UP, 1))) {

        if (this->map.isWalkable(x, y - 2, Direction::Up, this->player.getWidth(), this->player.getHeight()) && !isBlockedByEnemy(this->player, x, y - 2)) {
            y-=2;
            moving = true;
        }

        direction = Direction::Up;

    }

    if ((PC::buttons.pressed(BTN_DOWN) || PC::buttons.repeat(BTN_DOWN, 1))) {

        if (this->map.isWalkable(x, y + 2, Direction::Down, this->player.getWidth(), this->player.getHeight()) && !isBlockedByEnemy(this->player, x, y + 2)) {
            y+=2;
            moving = true;
        }

        direction = Direction::Down;

    }

    if ((PC::buttons.pressed(BTN_RIGHT) || PC::buttons.repeat(BTN_RIGHT, 1))) {

        if (this->map.isWalkable(x + 2, y, Direction::Right, this->player.getWidth(), this->player.getHeight()) && !isBlockedByEnemy(this->player, x + 2, y)) {
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

        if (this->map.isWalkable(x - 2, y, Direction::Left, this->player.getWidth(), this->player.getHeight()) && !isBlockedByEnemy(this->player, x - 2, y)) {
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

                const int32_t xOffsets[8] = { 0, 2, 2, 2, 0, -2, -2, -2 };
                const int32_t yOffsets[8] = { -6, -6, 0, 6, 6, 6, 0, -2 };

                //sound.tone(NOTE_F2H,50);


                switch (this->player.getWeapon()) {

                    case Object::FireBall:
                        bullets.getBullet(i).setBullet(x + xOffsets[static_cast<uint8_t>(direction)], y + yOffsets[static_cast<uint8_t>(direction)], direction, this->player.getWeapon());
                        break;

                    case Object::GreenSpell:
                    case Object::YellowSpell:
                        {
                            bullets.getBullet(i).setBullet(x + xOffsets[static_cast<uint8_t>(direction)], y + yOffsets[static_cast<uint8_t>(direction)], direction, this->player.getWeapon());

                            uint8_t slot = this->player.getInventorySlot(this->player.getWeapon());
                            InventoryItem &inventoryItem = this->player.getInventoryItem(slot);

                            inventoryItem.quantity--;

                            if (inventoryItem.quantity == 0) {
                                this->player.setWeapon(Object::FireBall);
                            }

                        }
                        break;

                    case Object::MauveSpell:
                        {
                            printf("Shot Mauve\n");
                            int16_t xMin = this->player.getX() - 55;
                            int16_t xMax = this->player.getX() + 55;
                            int16_t yMin = this->player.getY() - 36;
                            int16_t yMax = this->player.getY() + 36;

                            for (uint8_t i = 0; i < this->objects.getObjectNum(); i++) {

                                auto &object = this->objects.getSprite(i);
if (object.getActive() && object.isEnemy()) {

printf("x %i - %i, y %i - %i > %i,%i\n", xMin, xMax, yMin, yMax, object.getX(), object.getY());

}

                                if (object.getActive() && object.isEnemy() && object.getX() >= xMin && object.getX() <= xMax && object.getY() >= yMin & object.getY() <= yMax) {
printf("Kill\n");
                                    object.damage(Object::MauveSpell);

                                }

                            }
                            
                            uint8_t slot = this->player.getInventorySlot(this->player.getWeapon());
                            InventoryItem &inventoryItem = this->player.getInventoryItem(slot);

                            //SJH inventoryItem.quantity--;
                            this->shockwave = 9;

                            if (inventoryItem.quantity == 0) {
                                this->player.setWeapon(Object::FireBall);
                            }

                        }
                        break;


                }

                break;

            }

        }
  
    }


    // Display Inventory?

    if (PC::buttons.pressed(BTN_C)) {

        this->gameState = GameState::Inventory;
        this->inventoryMenu.mainCursor = 0;
  
    }


    // Display Map Details ..

    #ifdef DEBUG

        if (PC::buttons.pressed(BTN_A) && PC::buttons.pressed(BTN_C)) {

            this->gameState = GameState::MapDetails;
    
        }

    #endif
    

    // Operate lever, open door, fix things ..

    if (PC::buttons.pressed(BTN_A)) {

        int relx = this->map.getTileX(x);
        int rely = this->map.getTileY(y);
        MapTiles block = static_cast<MapTiles>(this->map.getBlock(relx, rely));

        switch (block) {

            case MapTiles::DownStairs:
                //sound.tone(NOTE_C3,100,NOTE_E3,100,NOTE_G3,100);
                gameState = GameState::EndOfLevel;
                break;

            case MapTiles::WormHole_F0:
                this->interactWithBlock(relx, rely, block);
                break;

            default:

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
                break;


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
                uint8_t slot = this->player.addInventoryItem(Object::Key, 1);

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

        case MapTiles::WormHole_F0:
            {
                for (uint8_t i = 0; i < this->environments.getEnvironmentNum(); i++) {

                    auto environment = this->environments.getEnvironment(i);

                    if (environment.getX() == x && environment.getY() == y) {

                        player.setX(environment.getFinishX() * TILE_SIZE + 8);
                        player.setY(environment.getFinishY() * TILE_SIZE + 8);
                        break;

                    }

                }

            }
            return false;

    }

    return false;

}


void Game::updateEnvironmentBlock(MapInformation map, uint8_t x, uint8_t y, Environments &environments) {

    for (int i = 0; i < this->environments.getEnvironmentNum(); i++) {

        auto environment = this->environments.getEnvironment(i);

        if (environment.checkStart(x,y) && environment.getActive()) {

            uint8_t x1 = environment.getFinishX();
            uint8_t y1 = environment.getFinishY();

            switch(this->map.getBlock(x1, y1)) {

                case MapTiles::SpearDoor: 
                    this->map.setBlock(x1, y1, MapTiles::OpenDoor); 
                    break;

                case MapTiles::NewSpearDoorLHS: 
                    this->map.setBlock(x1, y1, MapTiles::NewSpearDoorLHSOpen); 
                    break;

                case MapTiles::NewSpearDoorRHS: 
                    this->map.setBlock(x1, y1, MapTiles::NewSpearDoorRHSOpen); 
                    break;

                case MapTiles::NewSpearDoorTOP: 
                    this->map.setBlock(x1, y1, MapTiles::NewSpearDoorTOPOpen); 
                    break;

                case MapTiles::NewSpearDoorBOT: 
                    this->map.setBlock(x1, y1, MapTiles::NewSpearDoorBOTOpen); 
                    break;

                case MapTiles::NewSpearDoorLHSOpen: 
                    this->map.setBlock(x1, y1, MapTiles::NewSpearDoorLHS); 
                    break;

                case MapTiles::NewSpearDoorRHSOpen: 
                    this->map.setBlock(x1, y1, MapTiles::NewSpearDoorRHS); 
                    break;

                case MapTiles::NewSpearDoorTOPOpen: 
                    this->map.setBlock(x1, y1, MapTiles::NewSpearDoorTOP); 
                    break;

                case MapTiles::NewSpearDoorBOTOpen: 
                    this->map.setBlock(x1, y1, MapTiles::NewSpearDoorBOT); 
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

            if (!EnDrop) {

                object.setSprite((x * TILE_SIZE) + 8, (y * TILE_SIZE) + 8, 1, static_cast<Object>(id), true);

            }
            else{

                object.setSprite(x, y, 1, static_cast<Object>(id), true);

            }
            
        }
        
    } 
    else {

        uint8_t id = random(1,5);
        auto object = this->objects.getSprite(found);

        if ((id != 4) && (id != 2)) {

            if (!EnDrop) {
                object.setSprite((x * TILE_SIZE) + 8, (y * TILE_SIZE) + 8, 1, static_cast<Object>(id), true);
            }
            else{
                object.setSprite(x, y, 1, static_cast<Object>(id), true);
            }
            
        }
        
    }
    
}


void Game::spriteAI(MapInformation &map, Player &player, Sprite &sprite) {

    Point location;
    location.x = sprite.getX();
    location.y = sprite.getY();
        
    switch(sprite.getType()) {

        case Object::Coin: 

            if (Pokitto::Core::frameCount % 5 == 0) { 
                sprite.setFrame(sprite.getFrame() + 1); 
                sprite.setFrame(sprite.getFrame() % 6);
            } 

            break;

        case Object::Floater:            
        case Object::Skull:     

            switch (this->player.getWeapon()) {

                case Object::IceSpell:
                    if (this->player.getWeaponCount() % 2 == 0) {
                        this->spriteAI_UpdateEnemy(location, map, player, sprite);
                    }
                    break;

                default:
                    this->spriteAI_UpdateEnemy(location, map, player, sprite);
                    break;

            }

            break;

        case Object::Spider:   

            if (Pokitto::Core::frameCount % 5 == 0) { 
                sprite.setFrame(sprite.getFrame() + 1); 
                sprite.setFrame(sprite.getFrame() % 2);
            } 

            if (this->map.getDistance(location.x, location.y, player.getX(), player.getY()) <= 7) {

                switch (this->player.getWeapon()) {

                    case Object::IceSpell:
                        if (this->player.getWeaponCount() % 2 == 0) {
                            this->spriteAI_UpdateEnemy(location, map, player, sprite);
                        }
                        break;

                    default:
                        this->spriteAI_UpdateEnemy(location, map, player, sprite);
                        break;

                }
                
            }

            break;

        case Object::BigSpider:   

            if (Pokitto::Core::frameCount % 5 == 0) { 
                sprite.setFrame(sprite.getFrame() + 1); 
                sprite.setFrame(sprite.getFrame() % 2);
            } 

            if (this->map.getDistance(location.x, location.y, player.getX(), player.getY()) <= 7) {
                
                switch (this->player.getWeapon()) {

                    case Object::IceSpell:
                        if (this->player.getWeaponCount() % 2 == 0) {
                            this->spriteAI_UpdateEnemy(location, map, player, sprite);
                        }
                        break;

                    default:
                        this->spriteAI_UpdateEnemy(location, map, player, sprite);
                        break;

                }

            }

            break;

        case Object::Bat: 

            if (this->map.getDistance(location.x, location.y, player.getX(), player.getY()) < 7) {

                switch (this->player.getWeapon()) {

                    case Object::FireBall:
                        this->spriteAI_UpdateEnemy(location, map, player, sprite);
                        break;

                    case Object::IceSpell:
                        if (this->player.getWeaponCount() % 2 == 0) {
                            this->spriteAI_UpdateEnemy(location, map, player, sprite);
                        }
                        break;

                }

            }

            if (Pokitto::Core::frameCount % 5 == 0) { 
                sprite.setFrame(sprite.getFrame() + 1); 
                sprite.setFrame(sprite.getFrame() % 2);
            } 

            break;

        case Object::IceSpell: 

            if (Pokitto::Core::frameCount % 16 == 0) { 
                sprite.setFrame(sprite.getFrame() + 1); 
                sprite.setFrame(sprite.getFrame() % 2);
            } 

            break;

    }

    sprite.setPosition(location.x, location.y);

}

void Game::spriteAI_UpdateEnemy(Point &point, MapInformation &map, Player &player, Sprite &enemy) {

    if (map.getDistance(point.x, point.y, player.getX(), player.getY()) <= 5) {
        if (point.x < player.getX() && map.isWalkable(point.x + 1, point.y, Direction::Right, enemy.getWidth(), enemy.getHeight()) && !isBlockedByPlayer(player, enemy, point.x + 1, point.y))   { point.x++; }
        if (point.x > player.getX() && map.isWalkable(point.x - 1, point.y, Direction::Left, enemy.getWidth(), enemy.getHeight()) && !isBlockedByPlayer(player, enemy, point.x - 1, point.y))    { point.x--; }
        if (point.y < player.getY() && map.isWalkable(point.x, point.y + 1, Direction::Down, enemy.getWidth(), enemy.getHeight()) && !isBlockedByPlayer(player, enemy, point.x, point.y + 1))    { point.y++; }
        if (point.y > player.getY() && map.isWalkable(point.x, point.y - 1, Direction::Up, enemy.getWidth(), enemy.getHeight()) && !isBlockedByPlayer(player, enemy, point.x, point.y - 1))      { point.y--; }
    }

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