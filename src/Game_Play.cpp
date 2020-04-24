#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

void Game::updateObjects(bool ignorePlayerDamage) {


    // Handle various counters ..

    this->player.decWeaponCount();
    if (this->shake > 0)                this->shake--;
    if (this->shockwave > 0)            this->shockwave--;
    if (this->levelStartDelay > 0)      this->levelStartDelay--;
    if (this->enemyBulletDelay > 0)     this->enemyBulletDelay--;
    if (this->launchSkeletonDelay > 0)  this->launchSkeletonDelay--;


    // Update other objects ..

    for (uint8_t i = 0; i < this->objects.getObjectNum(); i++) {

        auto &objectI = this->objects.getSprite(i);
        bool objectI_IsEnemy = objectI.isEnemy();

        if (objectI.getActive()) { 


            // Reduce the health bar visual indicator counter ..

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

                    if (i != j && objectI_IsEnemy && objectJ.isCarryable() && this->collision(objectI, objectJ)) {

                        if (objectI.getCarrying() == Object::None) {

                            objectJ.setActive(false);
                            objectI.setCarrying(objectJ.getType());
                            
                        }

                    }

                }

            }


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
                    case Object::Eye:
                    case Object::Spider:
                    case Object::BigSpider:
                    case Object::Bat:
                    case Object::Skeleton:
                    case Object::SpikeLHS:
                    case Object::SpikeRHS:
                    case Object::FireTOP:
                    case Object::FireBOT:
                    case Object::Snake:
                    case Object::Necromancer:

                        if (!ignorePlayerDamage) {
                                
                            if (this->shake < 3) {
                                this->shake = this->shake + 2;
                            }

                            if (PC::frameCount % 4 == 0) { 

                                switch (type) {

                                    case Object::Floater:   
                                        player.decHealth(HEALTH_DEC_FLOATER); 
                                        break;

                                    case Object::Eye: 
                                        player.decHealth(HEALTH_DEC_EYES); 
                                        break;

                                    case Object::Spider:
                                        player.decHealth(HEALTH_DEC_SPIDER); 
                                        break;

                                    case Object::BigSpider:
                                        player.decHealth(HEALTH_DEC_BIGSPIDER); 
                                        break;

                                    case Object::Bat: 
                                        player.decHealth(HEALTH_DEC_BAT); 
                                        break;

                                    case Object::Skeleton: 
                                        player.decHealth(HEALTH_DEC_SKELETON); 
                                        break;

                                    case Object::Snake: 
                                        player.decHealth(HEALTH_DEC_SNAKE); 
                                        break;

                                    case Object::SpikeLHS: 
                                    case Object::SpikeRHS: 
                                    case Object::FireTOP: 
                                    case Object::FireBOT: 
                                        player.decHealth(HEALTH_DEC_SPIKE_FIRE); 
                                        break;

                                    case Object::Chest:   
                                        player.decHealth(HEALTH_DEC_CHEST); 
                                        break;

                                    case Object::Necromancer:   
                                        player.decHealth(HEALTH_DEC_NECROMANCER); 
                                        break;


                                }

                            }

                        }

                        break;

                }

            }

        }

    }


    // Have the bullets hit anything ?

    for (uint8_t bulletIdx = 0; bulletIdx < PLAYER_BULLET_MAX + ENEMY_BULLET_MAX; bulletIdx++) {

        auto &bullet = bullets.getBullet(bulletIdx);
        
        if (bullet.getActive()) {

            uint8_t width = bullet.getWidth();
            uint8_t height = bullet.getHeight();

            Direction xDirection = this->getNearestCardinalDirection(bullet.getDirection(), Axis::XAxis);
            Direction yDirection = this->getNearestCardinalDirection(bullet.getDirection(), Axis::YAxis);

            uint16_t rx = bullet.getX();
            uint16_t ry = bullet.getY();

            bullet.update();


            // If the bullet has hit a wall or other fixed object ..

            if (xDirection != Direction::None && this->map.isWalkable(bullet.getX(), ry, xDirection, width, height) == WalkType::Stop) {

                if (bullet.getWeapon() == Object::SpiderWeb) {
                    bullet.setX(rx);
                    bullet.setDirection(Direction::None);
                }
                else {
                    bullet.setActive(false);
                }

            }

            if (yDirection != Direction::None && bullet.getActive() && this->map.isWalkable(rx, bullet.getY(), yDirection, width, height) == WalkType::Stop) {

                if (bullet.getWeapon() == Object::SpiderWeb) {
                    bullet.setY(ry);
                    bullet.setDirection(Direction::None);
                }
                else {
                    bullet.setActive(false);
                }

            }

            const int8_t bullet_XMovement[8] = { 0, 5, 5, 5, 0, -5, -5, -5 };
            const int8_t bullet_YMovement[8] = { -5, -5, 0, 5, 5, 5, 0, -5 };


            // Did we just break a barrel ?

            if (!bullet.getActive()) {

                uint8_t direction = static_cast<uint8_t>(bullet.getDirection());
                rx = rx + bullet_XMovement[direction];
                ry = ry + bullet_YMovement[direction];

                if (this->map.getBlock(this->map.getTileX(rx), this->map.getTileY(ry)) == MapTiles::Barrel) {

                    barrelBreak(map, this->map.getTileX(rx), this->map.getTileY(ry), this->objects);

                    const uint8_t randomLimit[12] = { BARREL_RANDOM_NOTHING, BARREL_RANDOM_COIN, BARREL_RANDOM_SACK, BARREL_RANDOM_BREAD, BARREL_RANDOM_CHICKEN, }; 
                    const uint8_t randomItems[11] = { Object::None,                Object::Coin,  Object::SackOCash,       Object::Bread,       Object::Chicken, };

                    uint8_t randObject = random(0, BARREL_RANDOM_CHICKEN);
                    uint8_t object = 0;

                    for (uint8_t x = 0; x < 12; x++) {

                        if  (randObject <= randomLimit[x]) {

                            object = randomItems[x];
                            break;

                        }

                    }


                    // Find a matching Object in the sprites collecion that is disabled, otherwise add one ..

                    if (object != Object::None) {

                        uint8_t spriteIdx = this->objects.getFirstInactiveSpriteIndex(static_cast<Object>(object));

                        if (spriteIdx == NO_SPRITE_FOUND) {

                            this->objects.setObjectNum(this->objects.getObjectNum() + 1);
                            spriteIdx = this->objects.getObjectNum() - 1;

                        }   

                        Sprite &sprite = this->objects.getSprite(spriteIdx);
                        sprite.setSprite((this->map.getTileX(rx) * TILE_SIZE) + 8, (this->map.getTileY(ry) * TILE_SIZE) + 8, 0, static_cast<Object>(object), true, true);

                    }

                } 

            }
            else {

                switch (bulletIdx) {
                    

                    // Did we bullet an enemy?  Test only id it is a player bullet ..

                    case 0 ... PLAYER_BULLET_MAX - 1:

                        for (uint8_t i = 0; i < this->objects.getObjectNum(); i++) {

                            auto &object = this->objects.getSprite(i);


                            // Did we hit an enemy?
                            
                            if (object.getActive() && object.isEnemy() && this->collision(object, bullet)) {

                                object.decHealth(bullet.getWeapon());
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

                        if (this->collision(this->player, bullet)) {

                            //sound shot, ouch!

                            if (this->shake < 3) {
                                this->shake = this->shake + 2;
                            }

                            this->player.decHealth(DAMAGE_BULLET);
                            bullet.setActive(false);

                        }

                        break;

                }

            }

        }

    }

}

void Game::updateGame() {
    
    const uint8_t offX[4] = { 1, 0,};
    const uint8_t offY[4] = { 0, 1 };

    if (player.getHealth() > 0) {

        if (Pokitto::Core::frameCount % TIMER_STEP == 0) { this->map.decTimer();  }
        if (this->map.getTimer() == 0) { player.setHealth(0); }
        this->playerMovement();

    }

    this->updateObjects(player.getHealth() <= 0);

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

    if (player.getHealth() <= 0) {

        this->player.decPuffIndex();

        if (this->player.getPuffIndex() == PLAYER_DEAD_DELAY || PC::buttons.pressed(BTN_A)) {
    
            gameState = GameState::Dead;

        }

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

        if (this->map. between(3, 3, 11, 11, ofx, ofy) && block == MapTiles::PressPlate_Up) {
            this->map.setBlock(relx,rely,MapTiles::PressPlate_Down);
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

            case Object::IceSpell:
                {
                    uint8_t inactiveBulletIdx = this->bullets.getInactivePlayerBullet();

                    if (inactiveBulletIdx != NO_INACTIVE_BULLET_FOUND) {

                        Bullet &bullet = this->bullets.getPlayerBullet(inactiveBulletIdx);
                        bullet.setBullet(x + xOffsets[static_cast<uint8_t>(direction)], y + yOffsets[static_cast<uint8_t>(direction)], direction, this->player.getWeapon());

                        uint8_t slot = this->player.getInventorySlot(this->player.getWeapon());
                        InventoryItem &inventoryItem = this->player.getInventoryItem(slot);

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

                            object.decHealth(Object::MauveSpell);

                        }

                    }
                    
                    uint8_t slot = this->player.getInventorySlot(this->player.getWeapon());
                    InventoryItem &inventoryItem = this->player.getInventoryItem(slot);

                    inventoryItem.quantity--;
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

        case MapTiles::ClosedChest_Key: 
            {
                this->map.setBlock(x, y, MapTiles::OpenChest); 
                // sound open chest


                // Find a matching Object in the sprites collecion that is disabled, otherwise add one ..

                uint8_t spriteIdx = this->objects.getFirstInactiveSpriteIndex((block == MapTiles::ClosedChest_Key ? Object::Key : Object::Chest));

                if (spriteIdx == NO_SPRITE_FOUND) {

                    this->objects.setObjectNum(this->objects.getObjectNum() + 1);
                    spriteIdx = this->objects.getObjectNum() - 1;

                }   

                Sprite &sprite = this->objects.getSprite(spriteIdx);
                sprite.setSprite((x * TILE_SIZE) + 8, (y * TILE_SIZE) + 8, 0, (block == MapTiles::ClosedChest_Key ? Object::Key : Object::Chest), true, false);

            }
            return true;

        case MapTiles::ClosedChest_Killer: 
            {
                this->map.setBlock(x, y, MapTiles::OpenChest); 
                // sound open chest


                // Find a matching Object in the sprites collecion that is disabled, otherwise add one ..

                uint8_t spriteIdx = this->objects.getFirstInactiveSpriteIndex((block == MapTiles::ClosedChest_Key ? Object::Key : Object::Chest));

                if (spriteIdx == NO_SPRITE_FOUND) {

                    this->objects.setObjectNum(this->objects.getObjectNum() + 1);
                    spriteIdx = this->objects.getObjectNum() - 1;

                }   

                Sprite &sprite = this->objects.getSprite(spriteIdx);
                sprite.setSprite((x * TILE_SIZE) + 8, (y * TILE_SIZE) + 8, HEALTH_CHEST, (block == MapTiles::ClosedChest_Key ? Object::Key : Object::Chest), true, false);
                sprite.setCountdown(0);
                sprite.setDirection(Direction::Down);
                this->map.setBlock(x, y, MapTiles::Empty); 

            }
            return true;

        case MapTiles::ClosedChest_Random: 
            {
                this->map.setBlock(x, y, MapTiles::OpenChest); 
                // sound open chest

                // random

                const uint8_t randomLimit[12] = { CHEST_RANDOM_COIN, CHEST_RANDOM_SACK, CHEST_RANDOM_BREAD, CHEST_RANDOM_CHICKEN, CHEST_RANDOM_TOOLS, CHEST_RANDOM_TONIC, CHEST_RANDOM_KEY, CHEST_RANDOM_ICE, CHEST_RANDOM_GREEN, CHEST_RANDOM_RED, CHEST_RANDOM_MAUVE, CHEST_RANDOM_END }; 
                const uint8_t randomItems[11] = {      Object::Coin, Object::SackOCash,      Object::Bread,      Object::Chicken,      Object::Tools,      Object::Tonic,      Object::Key, Object::IceSpell, Object::GreenSpell, Object::RedSpell, Object::MauveSpell, };


                uint8_t randObject = random(0, CHEST_RANDOM_END);
                uint8_t object = 0;

                for (uint8_t x = 0; x < 12; x++) {

                    if  (randObject <= randomLimit[x]) {

                        object = randomItems[x];
                        break;

                    }

                }


                // Find a matching Object in the sprites collecion that is disabled, otherwise add one ..

                uint8_t spriteIdx = this->objects.getFirstInactiveSpriteIndex(static_cast<Object>(object));

                if (spriteIdx == NO_SPRITE_FOUND) {

                    this->objects.setObjectNum(this->objects.getObjectNum() + 1);
                    spriteIdx = this->objects.getObjectNum() - 1;

                }   

                Sprite &sprite = this->objects.getSprite(spriteIdx);
                sprite.setSprite((x * TILE_SIZE) + 8, (y * TILE_SIZE) + 8, 0, static_cast<Object>(object), true, true);

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

            spriteAI_CheckForMove(map, player, sprite, location, 7);
            break;

        case Object::Eye:     

            spriteAI_UpdateFrame(sprite, 4, 2);
            spriteAI_CheckForMove(map, player, sprite, location, 7);
            break;

        case Object::Snake:
        case Object::BigSpider:   
        case Object::Bat: 
        case Object::Chest: 

            spriteAI_UpdateFrame(sprite, 4, 2);
            spriteAI_CheckForMove(map, player, sprite, location, 7);
            break;

        case Object::Necromancer: 
            {
// printf("lsd %i, frame %i\n",this->launchSkeletonDelay, sprite.getFrame());
                switch (sprite.getFrame()) {

                    case -100 ... -2:
                        sprite.incFrame();
                        break;

                    case -1:    // launch a Skeleton
                        {
                            sprite.incFrame();


                            // Find a matching Object in the sprites collecion that is disabled, otherwise add one ..

                            uint8_t spriteIdx = this->objects.getFirstInactiveSpriteIndex(Object::Skeleton);

                            if (spriteIdx == NO_SPRITE_FOUND) {

                                this->objects.setObjectNum(this->objects.getObjectNum() + 1);
                                spriteIdx = this->objects.getObjectNum() - 1;

                            }   

                            Sprite &sprite = this->objects.getSprite(spriteIdx);


                            // Make sure we can launch the skeleton in a clear spot and not on top of the player ..

                            const int8_t launchSkeleton_X[] = { 0, 13, 13, 13, 13, -13, -13, -13 };
                            const int8_t launchSkeleton_Y[] = { -13, -13, 0, 13, 13, 13, 0, -13 };
                            const int8_t directions[] = { 8, 9, 7, 10, 6, 11, 5, 4 };

                            for (uint8_t d = 0; d < 7; d++) {

                                int launchX = location.x + launchSkeleton_X[(static_cast<uint8_t>(this->launchSkeletonDirection) + directions[d]) % 8];
                                int launchY = location.y + launchSkeleton_Y[(static_cast<uint8_t>(this->launchSkeletonDirection) + directions[d]) % 8];

                                uint8_t width = spriteWidths[static_cast<uint8_t>(this->launchSkeletonDirection)];
                                uint8_t height = spriteHeights[static_cast<uint8_t>(this->launchSkeletonDirection)];
                                sprite.setSprite(launchX, launchY, HEALTH_SKELETON, Object::Skeleton, false, false);

                                if (map.isWalkable(launchX, launchY, this->launchSkeletonDirection, width, height) && !collision(this->player, sprite)) {

                                    sprite.setFrame(-47);
                                    sprite.setCountdown(0);
                                    sprite.setDirection(Direction::Down);
                                    sprite.setActive(true);
                                    break;

                                }

                            }

                        }
                        break;

                    case 0 ... 100:
                        {
                            spriteAI_UpdateFrame(sprite, 4, 2);
                            Direction direction = spriteAI_CheckForMove(map, player, sprite, location, 7);

                            if (direction != Direction::None && this->launchSkeletonDelay == 0) {


                                // Should the enemy summons a skeleton ?
// printf("adasdas\n");
                                sprite.setFrame(-59);
                                this->launchSkeletonDirection = direction;
                                this->launchSkeletonDelay = random(LAUNCH_SKELETON_DELAY_MIN, LAUNCH_SKELETON_DELAY_MAX);

                            }

                        }
                        break;

                }

            }
            break;

        case Object::Spider:   
            {
                spriteAI_UpdateFrame(sprite, 4, 2);
                Direction direction = spriteAI_CheckForMove(map, player, sprite, location, 7);

                if (direction != Direction::None) {


                    // Should the enemy shoot a bullet?

                    if (this->enemyBulletDelay == 0 && random(0, 4) == 0) {

                        const int32_t xOffsets[8] = { 0, 4, 4, 4, 0, -4, -4, -4 };
                        const int32_t yOffsets[8] = { -4, -4, 0, 4, 4, 4, 0, -4 };

                        uint8_t inactiveBulletIdx = this->bullets.getInactiveEnemyBullet();

                        if (inactiveBulletIdx != NO_INACTIVE_BULLET_FOUND) {

                            Bullet &bullet = this->bullets.getEnemyBullet(inactiveBulletIdx);
                            bullet.setBullet(sprite.getX() + xOffsets[static_cast<uint8_t>(direction)], sprite.getY() + yOffsets[static_cast<uint8_t>(direction)], direction, Object::SpiderWeb);
                            this->enemyBulletDelay = random(ENEMY_BULLET_DELAY_MIN, ENEMY_BULLET_DELAY_MAX);

                        }

                    }

                }

            }
            
            break;

        case Object::Skeleton:   
            {
                if (sprite.getFrame() < 0) {

                    sprite.incFrame();

                }
                else {

                    spriteAI_UpdateFrame(sprite ,4, 2);
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

                    switch (sprite.getType()) {

                        case Object::Necromancer:
                            if (PC::frameCount % 8 == 0) {
                                direction = this->spriteAI_UpdateEnemy(location, map, player, sprite);
                            }
                            break;

                        default:
                            direction = this->spriteAI_UpdateEnemy(location, map, player, sprite);
                            break;

                    }

                }
                break;

            default:

                switch (sprite.getType()) {

                    case Object::Necromancer: 
                        if (PC::frameCount % 4 == 0) {
                            direction = this->spriteAI_UpdateEnemy(location, map, player, sprite);
                        }
                        break;

                    default:
                        direction = this->spriteAI_UpdateEnemy(location, map, player, sprite);
                        break;

                }

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
