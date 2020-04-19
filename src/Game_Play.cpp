#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

void Game::updateObjects() {

//printf("%i\n", this->enemyBulletDelay);
    // Handle various counters ..

    this->player.decWeaponCount();
    if (this->shake > 0)                this->shake--;
    if (this->shockwave > 0)            this->shockwave--;
    if (this->levelStartDelay > 0)      this->levelStartDelay--;
    if (this->enemyBulletDelay > 0)     this->enemyBulletDelay--;


    // Update other objects ..

    for (uint8_t i = 0; i < this->objects.getObjectNum(); i++) {

        auto &objectI = this->objects.getSprite(i);
        bool objectI_IsEnemy = objectI.isEnemy();

        if (objectI.getActive()) { 


            // Reduce the health bar visual indicator counter ..
// printf("a\n");
            objectI.update();


            // Dow we need to update the object?

            bool update = true;

            for (uint8_t j = 0; j < this->objects.getObjectNum(); j++) {

                auto &objectJ = this->objects.getSprite(j);

                if (objectJ.getActive()) {


                    // If the enemy has collided with another enemy then do not update the position ..

                    if (i < j && objectI_IsEnemy && objectJ.isEnemy() && this->collision(objectI, objectJ)) {

                        update = false;

                    }


                    // If an enemy has collided with an object then pick it up ..

                    if (i != j && objectI_IsEnemy && !objectJ.isEnemy() && this->collision(objectI, objectJ)) {

                        if (objectI.getCarrying() == Object::None) {

                            objectJ.setActive(false);
                            objectI.setCarrying(objectJ.getType());
                            
                        }

                    }

                }

            }
// printf("b\n");


            if (!objectI_IsEnemy || (objectI_IsEnemy && update && this->levelStartDelay == 0)) { this->spriteAI(map, player, objectI); }


            // Has a collision between the object and player occured ?

            if (!objectI.getPreventImmediatePickup() && this->collision(player, objectI)) {

                uint16_t note = 0;
                uint16_t duration = 0;
                uint8_t type = objectI.getType();

                switch (type) {

                    case Object::Coin: 
                        player.incCoins(1); 
                        objectI.setActive(false); 
                        break;

                    case Object::SackOCash: 
                        player.incCoins(5); 
                        objectI.setActive(false); 
                        break;

                    case Object::Key:
                    case Object::Bread:
                    case Object::Chicken:
                    case Object::Tools:
                    case Object::Tonic:
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
                    case Object::RedSpell:
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
                    case Object::NewEnemy:
                    case Object::SpikeLHS:
                    case Object::SpikeRHS:
                    case Object::FireTOP:
                    case Object::FireBOT:
                    case Object::Snake:

                        if (this->shake < 3) {
                            this->shake = this->shake + 2;
                        }

                        if (PC::frameCount % 4 == 0) { 

                            switch (type) {

                                case Object::Floater:   
                                    //SJH 
                                    player.decHealth(10 * diff); 
                                    break;

                                case Object::Skull: 
                                    //SJH 
                                    player.decHealth(5 * diff); 
                                    break;

                                case Object::Spider:
                                    //SJH 
                                    player.decHealth(2 * diff); 
                                    break;

                                case Object::BigSpider:
                                    //SJH 
                                    player.decHealth(6 * diff); 
                                    break;

                                case Object::Bat: 
                                    //SJH 
                                    player.decHealth(diff); 
                                    break;

                                case Object::NewEnemy: 
                                    //SJH 
                                    player.decHealth(3 * diff); 
                                    break;

                                case Object::Snake: 
                                    //SJH 
                                    player.decHealth(3 * diff); 
                                    break;

                                case Object::SpikeLHS: 
                                case Object::SpikeRHS: 
                                case Object::FireTOP: 
                                case Object::FireBOT: 
                                    //SJH 
                                    player.decHealth(2 * diff); 
                                    break;

                            }

                        }

                        break;

                }

            }

        }

    }
// printf("c\n");


    // Have the bullets hit anything ?

    for (uint8_t bulletIdx = 0; bulletIdx < PLAYER_BULLET_MAX + ENEMY_BULLET_MAX; bulletIdx++) {

        auto &bullet = bullets.getBullet(bulletIdx);
        
        if (bullet.getActive()) {

            uint8_t width = bullet.getWidth();
            uint8_t height = bullet.getHeight();
// printf("c1\n");
            Direction xDirection = this->getNearestCardinalDirection(bullet.getDirection(), Axis::XAxis);
            Direction yDirection = this->getNearestCardinalDirection(bullet.getDirection(), Axis::YAxis);

            uint16_t rx = bullet.getX();
            uint16_t ry = bullet.getY();

            bullet.update();


            // If the bullet has hit a wall or other fixed object ..
// printf("c2\n");
            if (xDirection != Direction::None && this->map.isWalkable(bullet.getX(), ry, xDirection, width, height) == WalkType::Stop) {

                if (bullet.getWeapon() == Object::SpiderWeb) {
                    bullet.setX(rx);
                    bullet.setDirection(Direction::None);
                }
                else {
                    bullet.setActive(false);
                }

            }
// printf("c3\n");
            if (yDirection != Direction::None && bullet.getActive() && this->map.isWalkable(rx, bullet.getY(), yDirection, width, height) == WalkType::Stop) {

                if (bullet.getWeapon() == Object::SpiderWeb) {
                    bullet.setY(ry);
                    bullet.setDirection(Direction::None);
                }
                else {
                    bullet.setActive(false);
                }

            }

// printf("c4\n");
            const int8_t bullet_XMovement[8] = { 0, 5, 5, 5, 0, -5, -5, -5 };
            const int8_t bullet_YMovement[8] = { -5, -5, 0, 5, 5, 5, 0, -5 };


            // Did we just break a barrel ?

            if (!bullet.getActive()) {
// printf("c5a\n");
                uint8_t direction = static_cast<uint8_t>(bullet.getDirection());
                rx = rx + bullet_XMovement[direction];
                ry = ry + bullet_YMovement[direction];

                if (this->map.getBlock(this->map.getTileX(rx), this->map.getTileY(ry)) == MapTiles::Barrel) {
                    barrelBreak(map, this->map.getTileX(rx), this->map.getTileY(ry), this->objects);
                } 

            }
            else {
// printf("c5b\n");

                switch (bulletIdx) {
                    

                    // Did we bullet an enemy?  Test only id it is a player bullet ..

                    case 0 ... PLAYER_BULLET_MAX - 1:
// printf("c5b1\n");
                        for (uint8_t i = 0; i < this->objects.getObjectNum(); i++) {

                            auto &object = this->objects.getSprite(i);


                            // Did we hit an enemy?
                            
                            if (object.getActive() && object.isEnemy() && this->collision(object, bullet)) {

                                object.damage(bullet.getWeapon());
                                bullet.setActive(false);

                                if (!object.getActive()) {

                                    player.setKills(this->player.getKills() + 1);

                                    if (object.getCarrying() != Object::None) {
                                        dropItem(object.getCarrying(), object.getX(), object.getY(), true, &object, this->objects);
                                    }

                                }

                            }

                        }

                        break;


                    // Did the bullet hit the player?  Test only if it is an enemy bullet ..

                    case PLAYER_BULLET_MAX ... PLAYER_BULLET_MAX + ENEMY_BULLET_MAX:
    //  printf("c5c\n");                
                        if (this->collision(this->player, bullet)) {
    //  printf("c5c1\n"); 
                            //sound shot, ouch!

                            if (this->shake < 3) {
                                this->shake = this->shake + 2;
                            }
    //  printf("c5c2\n"); 

                            this->player.setHealth(this->player.getHealth() - DAMAGE_BULLET);
    //  printf("c5c3\n"); 
                            bullet.setActive(false);
    //  printf("c5c4\n"); 

                        }
// printf("c5d\n");
                        break;

                }
// printf("c5e\n");

            }

        }

    }

    // printf("d\n");


}

void Game::updateGame() {
    
    // const uint8_t offX[4] = { 0, 1, 0, -1 };
    // const uint8_t offY[4] = { 1, 0, -1, 0 };
    // const uint8_t offX[4] = { 1, -1,};
    // const uint8_t offY[4] = { -1, 1 };
    const uint8_t offX[4] = { 1, 0,};
    const uint8_t offY[4] = { 0, 1 };

// printf("1\n");

    this->playerMovement();
// printf("2\n");
    this->updateObjects();
// printf("3\n");

    if (this->shake > 0) {
        this->renderEnviroment(offX[(this->shake - 1) % 2], offY[(this->shake - 1) % 2]);
        this->renderPlayer(offX[(this->shake - 1) % 2], offY[(this->shake - 1) % 2]);
    }
    else {
        this->renderEnviroment(0, 0);
        this->renderPlayer(0, 0);
    }
// printf("4\n");

    this->renderObjects();
// printf("5\n");
    this->renderHud();
    
    if (Pokitto::Core::frameCount % TIMER_STEP == 0) { this->map.decTimer();  }
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
            
            Rect objectRect = object.getRect();

            if (collide(playerRect, objectRect)) return true;

        }

    }

    return false;

}

bool Game::isBlockedByPlayer(Player player, Sprite enemy, uint16_t enemyX, uint16_t enemyY) {
   
    Rect enemyRect = { enemyX - (enemy.getWidth() / 2), enemyY - (enemy.getHeight() / 2), enemy.getWidth(), enemy.getHeight() };
    return collide(player.getRect(), enemyRect);

}

void Game::playerMovement() {

    uint16_t x = player.getX();
    uint16_t y = player.getY();
    Direction direction = player.getDirection();
    bool moving = player.getMoving();

    moving = false;

    if ((PC::buttons.pressed(BTN_UP) || PC::buttons.repeat(BTN_UP, 1))) {

        WalkType walk = this->map.isWalkable(x, y - 2, Direction::Up, this->player.getWidth(), this->player.getHeight());

        if ((walk == WalkType::Normal || (walk == WalkType::Slow && PC::frameCount % WALK_SLOW_FRAME_COUNT == 0)) && !isBlockedByEnemy(this->player, x, y - 2)) {
            
            y-=2;
            moving = true;

            if (walk == WalkType::Slow) {
                player.decHealth(HEALTH_DEC_SPIDERS_WEB); 
            }

        }

        direction = Direction::Up;

    }

    if ((PC::buttons.pressed(BTN_DOWN) || PC::buttons.repeat(BTN_DOWN, 1))) {

        WalkType walk = this->map.isWalkable(x, y + 2, Direction::Down, this->player.getWidth(), this->player.getHeight());

        if ((walk == WalkType::Normal || (walk == WalkType::Slow && PC::frameCount % WALK_SLOW_FRAME_COUNT == 0)) && !isBlockedByEnemy(this->player, x, y + 2)) {

            y+=2;
            moving = true;


            if (walk == WalkType::Slow) {
                player.decHealth(HEALTH_DEC_SPIDERS_WEB); 
            }

        }

        direction = Direction::Down;

    }

    if ((PC::buttons.pressed(BTN_RIGHT) || PC::buttons.repeat(BTN_RIGHT, 1))) {

        WalkType walk = this->map.isWalkable(x + 2, y, Direction::Right, this->player.getWidth(), this->player.getHeight());

        if ((walk == WalkType::Normal || (walk == WalkType::Slow && PC::frameCount % WALK_SLOW_FRAME_COUNT == 0)) && !isBlockedByEnemy(this->player, x + 2, y)) {

            x+=2;
            moving = true;

            if (walk == WalkType::Slow) {
                player.decHealth(HEALTH_DEC_SPIDERS_WEB); 
            }

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

        WalkType walk = this->map.isWalkable(x - 2, y, Direction::Left, this->player.getWidth(), this->player.getHeight());

        if ((walk == WalkType::Normal || (walk == WalkType::Slow && PC::frameCount % WALK_SLOW_FRAME_COUNT == 0)) && !isBlockedByEnemy(this->player, x - 2, y)) {

            x-=2;
            moving = true;

            if (walk == WalkType::Slow) {
                player.decHealth(HEALTH_DEC_SPIDERS_WEB); 
            }

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

        const int32_t xOffsets[8] = { 0, 2, 2, 2, 0, -2, -2, -2 };
        const int32_t yOffsets[8] = { -6, -6, 0, 6, 6, 6, 0, -2 };

        //sound.tone(NOTE_F2H,50);


        switch (this->player.getWeapon()) {

            case Object::FireBall:
                {
                    uint8_t inactiveBulletIdx = this->bullets.getInactivePlayerBullet();

                    if (inactiveBulletIdx != NO_INACTIVE_BULLET_FOUND) {

                        Bullet &bullet = this->bullets.getPlayerBullet(inactiveBulletIdx);
                        bullet.setBullet(x + xOffsets[static_cast<uint8_t>(direction)], y + yOffsets[static_cast<uint8_t>(direction)], direction, this->player.getWeapon());

                    }
                }
                break;

            case Object::GreenSpell:
            case Object::RedSpell:
                {
                    uint8_t inactiveBulletIdx = this->bullets.getInactivePlayerBullet();

                    if (inactiveBulletIdx != NO_INACTIVE_BULLET_FOUND) {

                        Bullet &bullet = this->bullets.getPlayerBullet(inactiveBulletIdx);
                        bullet.setBullet(x + xOffsets[static_cast<uint8_t>(direction)], y + yOffsets[static_cast<uint8_t>(direction)], direction, this->player.getWeapon());

                        uint8_t slot = this->player.getInventorySlot(this->player.getWeapon());
                        InventoryItem &inventoryItem = this->player.getInventoryItem(slot);

                        inventoryItem.quantity--;

                        if (inventoryItem.quantity == 0) {
                            this->player.setWeapon(Object::FireBall);
                        }

                    }

                }
                break;

            case Object::MauveSpell:
                {
                    int16_t xMin = this->player.getX() - 55;
                    int16_t xMax = this->player.getX() + 55;
                    int16_t yMin = this->player.getY() - 36;
                    int16_t yMax = this->player.getY() + 36;

                    for (uint8_t i = 0; i < this->objects.getObjectNum(); i++) {

                        auto &object = this->objects.getSprite(i);

                        if (object.getActive() && object.isEnemy() && object.getX() >= xMin && object.getX() <= xMax && object.getY() >= yMin & object.getY() <= yMax) {

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

            case MapTiles::Shop00 ... MapTiles::Shop05:
                this->gameState = GameState::Shop;
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
                this->map.setBlock(x, y, MapTiles::OpenChest); 
                // sound open chest


                // Find a matching Object in the sprites collecion that is disabled, otherwise add one ..

                uint8_t spriteIdx = this->objects.getFirstInactiveSpriteIndex(Object::Key);

                if (spriteIdx == NO_SPRITE_FOUND) {

                    this->objects.setObjectNum(this->objects.getObjectNum() + 1);
                    spriteIdx = this->objects.getObjectNum() - 1;

                }   

                Sprite &sprite = this->objects.getSprite(spriteIdx);

                sprite.setType(Object::Key);
                sprite.setActive(true);
                sprite.setX((x * TILE_SIZE) + 8);
                sprite.setY((y * TILE_SIZE) + 8);
                sprite.setPreventImmediatePickup(true);

            }
            return true;

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

        case MapTiles::DoorLHS ... MapTiles::DoorBOT:

            if (this->player.getInventoryCount(Object::Key) > 0) {
//                this->map.setBlock(x, y, static_cast<MapTiles>((static_cast<uint8_t>(block) + (static_cast<uint8_t>(MapTiles::DoorLHSOpen) - static_cast<uint8_t>(MapTiles::DoorLHS))))); 
                this->map.setBlock(x, y, static_cast<MapTiles>(block + MapTiles::DoorLHSOpen - MapTiles::DoorLHS)); 
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

            if (this->player.getInventoryCount(Object::Tools) > 0) {
                this->map.setBlock(x, y, MapTiles::SwitchOff); 
                this->player.decInventoryItem(Object::Tools);
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

            MapTiles mapTile = this->map.getBlock(x1, y1);

            switch(mapTile) {

                case MapTiles::SpearDoor: 
                    this->map.setBlock(x1, y1, MapTiles::OpenDoor); 
                    break;

                case MapTiles::SpearDoorLHS ... MapTiles::SpearDoorBOT: 
                    this->map.setBlock(x1, y1, static_cast<MapTiles>(mapTile + (MapTiles::SpearDoorLHSOpen - MapTiles::SpearDoorLHS))); 
                    break;

                case MapTiles::SpearDoorLHSOpen ... SpearDoorBOTOpen: 
                    this->map.setBlock(x1, y1, static_cast<MapTiles>(mapTile - (MapTiles::SpearDoorLHSOpen - MapTiles::SpearDoorLHS))); 
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

                case MapTiles::DoorLHSOpen: 
                    this->map.setBlock(x1, y1, MapTiles::DoorLHS); 
                    break;

            }

        }

    }

}

void Game::dropItem(Object droppedObject, uint16_t x, uint16_t y, bool enemyDrop, Sprite *enemy, Sprites &objects) {

    bool slotFound = false;
    uint8_t slotIndex = 0;
    

    // Find the first empty slot ..

    for (uint8_t i = 0; i < objects.getObjectNum(); i++) {

        auto &obj = this->objects.getSprite(i);
        
        if (!(obj.getActive())) {
            slotFound = true;
            slotIndex = i;
            break;
        }

    }

    if (this->objects.getObjectNum() == MAXOBJECT && !slotFound) return;


    // If no disabled slot was found, then select the next available one in the collection ..

    if (this->objects.getObjectNum() < MAXOBJECT) {

        uint8_t slotIndex = this->objects.getObjectNum();
        this->objects.setObjectNum(slotIndex + 1);
        
    }
    

    // Retrieve the sprite object and populate ..

    auto &object = this->objects.getSprite(slotIndex);

    if (enemyDrop) {

        object.setSprite(x, y, 1, static_cast<Object>(droppedObject), true, true);
        
    }
    else{

        object.setSprite(x, y, 1, static_cast<Object>(droppedObject), true, false);

    }
    
}


void Game::spriteAI(MapInformation &map, Player &player, Sprite &sprite) {

    Point location;
    location.x = sprite.getX();
    location.y = sprite.getY();
        
    switch(sprite.getType()) {

        case Object::Key: 

            spriteAI_UpdateFrame(sprite, 8, 10);
            break;

        case Object::Coin: 

            spriteAI_UpdateFrame(sprite, 4, 6);
            break;

        case Object::Floater:            
        case Object::Skull:     

            spriteAI_CheckForMove(map, player, sprite, location, 7);
            break;

        case Object::Snake:
        case Object::BigSpider:   
        case Object::Bat: 

            spriteAI_UpdateFrame(sprite ,4, 2);
            spriteAI_CheckForMove(map, player, sprite, location, 7);
            break;

        case Object::Spider:   
            {
                spriteAI_UpdateFrame(sprite, 4, 2);
                Direction direction = spriteAI_CheckForMove(map, player, sprite, location, 7);

                if (direction != Direction::None) {


                    // Should the enemy shoot a bullet?

                    if (this->enemyBulletDelay == 0 && random(0, 4) == 0 && direction != Direction::None) {

                        const int32_t xOffsets[8] = { 0, 4, 4, 4, 0, -4, -4, -4 };
                        const int32_t yOffsets[8] = { -4, -4, 0, 4, 4, 4, 0, -4 };

                        uint8_t inactiveBulletIdx = this->bullets.getInactiveEnemyBullet();

                        if (inactiveBulletIdx != NO_INACTIVE_BULLET_FOUND) {
    // printf("fire web x: %i, y: %i, d: %i\n", sprite.getX(), sprite.getY(), static_cast<uint8_t>(direction));
                            Bullet &bullet = this->bullets.getEnemyBullet(inactiveBulletIdx);
                            bullet.setBullet(sprite.getX() + xOffsets[static_cast<uint8_t>(direction)], sprite.getY() + yOffsets[static_cast<uint8_t>(direction)], direction, Object::SpiderWeb);
                            this->enemyBulletDelay = random(ENEMY_BULLET_DELAY_MIN, ENEMY_BULLET_DELAY_MAX);

                        }

                    }

                }

            }
            
            break;

        case Object::NewEnemy:   
            {
                Direction direction = spriteAI_CheckForMove(map, player, sprite, location, 7);

                if (direction != Direction::None) {


                    // Should the enemy shoot a bullet?

                    if (this->enemyBulletDelay == 0 && random(0, 4) == 0 && direction != Direction::None) {

                        const int32_t xOffsets[8] = { 0, 6, 6, 6, 0, -6, -6, -6 };
                        const int32_t yOffsets[8] = { -6, -6, 0, 6, 6, 6, 0, -6 };

                        uint8_t inactiveBulletIdx = this->bullets.getInactiveEnemyBullet();

                        if (inactiveBulletIdx != NO_INACTIVE_BULLET_FOUND) {

                            Bullet &bullet = this->bullets.getEnemyBullet(inactiveBulletIdx);
                            bullet.setBullet(sprite.getX() + xOffsets[static_cast<uint8_t>(direction)], sprite.getY() + yOffsets[static_cast<uint8_t>(direction)], direction, Object::FireBall);
                            this->enemyBulletDelay = random(ENEMY_BULLET_DELAY_MIN, ENEMY_BULLET_DELAY_MAX);

                        }

                    }
                    
                }

            }

            break;

        case Object::SpikeLHS: 
        case Object::SpikeRHS: 

            sprite.decCountdown();

            if (sprite.getCountdown() <= 24) {

                sprite.setFrame(sprite.getFrame() + 1); 

                if (sprite.getCountdown() == 0) {

                    sprite.setCountdown(random(70, 120));
                    sprite.setFrame(0);

                }

            }

            break;

        case Object::FireTOP: 
        case Object::FireBOT: 

            sprite.decCountdown();

            if (sprite.getCountdown() <= 16) {

                sprite.setFrame(sprite.getFrame() + 1); 

                if (sprite.getCountdown() == 0) {

                    sprite.setCountdown(random(40, 75));
                    sprite.setFrame(0);

                }

            }

            break;

    }

    sprite.setPosition(location.x, location.y);

}

void Game::spriteAI_UpdateFrame(Sprite &sprite, uint8_t frameMultiple, uint8_t frameMax) {

    if (Pokitto::Core::frameCount % frameMultiple == 0) { 
        sprite.setFrame(sprite.getFrame() + 1); 
        sprite.setFrame(sprite.getFrame() % frameMax);
    } 

}


Direction Game::spriteAI_CheckForMove(MapInformation &map, Player &player, Sprite &sprite, Point &location, uint8_t dist) {

    Direction direction = Direction::None;

    if (this->map.getDistance(location.x, location.y, player.getX(), player.getY()) <= dist) {

        switch (this->player.getWeapon()) {

            case Object::IceSpell:
                if (this->player.getWeaponCount() % 2 == 0) {
                    direction = this->spriteAI_UpdateEnemy(location, map, player, sprite);
                }
                break;

            default:
                direction = this->spriteAI_UpdateEnemy(location, map, player, sprite);
                break;

        }

    }

    return direction;

}

Direction Game::spriteAI_UpdateEnemy(Point &point, MapInformation &map, Player &player, Sprite &enemy) {

    Direction direction = Direction::None;

    if (map.getDistance(point.x, point.y, player.getX(), player.getY()) <= 5) {
    
        if (point.x < player.getX() && map.isWalkable(point.x + 1, point.y, Direction::Right, enemy.getWidth(), enemy.getHeight()) && !isBlockedByPlayer(player, enemy, point.x + 1, point.y) != WalkType::Stop) { 
            direction = Direction::Right;
            point.x++; 
        }

        if (point.x > player.getX() && map.isWalkable(point.x - 1, point.y, Direction::Left, enemy.getWidth(), enemy.getHeight()) && !isBlockedByPlayer(player, enemy, point.x - 1, point.y) != WalkType::Stop) { 
            point.x--; 
            direction = Direction::Left;
        }

        if (point.y < player.getY() && map.isWalkable(point.x, point.y + 1, Direction::Down, enemy.getWidth(), enemy.getHeight()) && !isBlockedByPlayer(player, enemy, point.x, point.y + 1) != WalkType::Stop) { 

            point.y++; 

            switch (direction) {

                case Direction::None:
                    direction = Direction::Down;
                    break;

                case Direction::Right:
                    direction = Direction::DownRight;
                    break;

                case Direction::Left:
                    direction = Direction::DownLeft;
                    break;

            }

        }

        if (point.y > player.getY() && map.isWalkable(point.x, point.y - 1, Direction::Up, enemy.getWidth(), enemy.getHeight()) && !isBlockedByPlayer(player, enemy, point.x, point.y - 1) != WalkType::Stop) { 

            point.y--; 

            switch (direction) {

                case Direction::None:
                    direction = Direction::Up;
                    break;

                case Direction::Right:
                    direction = Direction::UpRight;
                    break;

                case Direction::Left:
                    direction = Direction::UpLeft;
                    break;

            }
            
        }

    }

    return direction;

}
