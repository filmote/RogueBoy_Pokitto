#include "Pokitto.h"
#include "Game.h"
#include "utils/Enums.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


void Game::showInventory() {


    // Update timer ..

    /* Remove timer decrease,
    
    if (Pokitto::Core::frameCount % TIMER_STEP == 0) { this->map.decTimer();  }
    if (this->map.getTimer() == 0) { 
        
        player.setHealth(0); 
     
        if (player.getHealth() <= 0) {
            //PS::playSFX(Sounds::sfx_Death5, Sounds::sfx_Death5_length); 
            gameState = GameState::Dead;

        }
        
    }
    */


    // If the cursor > active inventory slots then decrease it ..

    if (this->inventoryMenu.mainCursor > player.getActiveSlotCount()) {

        this->inventoryMenu.mainCursor = player.getActiveSlotCount();

    }


    // Handle player actions ..

    switch (this->inventoryMenu.mode) {

        case InventoryMenuMode::Inventory:
                
            if (!inventoryMenu.showActionMenu) {

                if (PC::buttons.pressed(BTN_B)) {

                    gameState = GameState::Game;

                }

                if (PC::buttons.pressed(BTN_C)) {
            
                    this->inventoryMenu.mode = InventoryMenuMode::AltarPieces;

                }

                if (PC::buttons.pressed(BTN_UP) && this->inventoryMenu.mainCursor > 0) {

                    this->inventoryMenu.mainCursor--;

                }

                if (PC::buttons.pressed(BTN_DOWN) && this->inventoryMenu.mainCursor < player.getActiveSlotCount()) {

                    this->inventoryMenu.mainCursor++;

                }

                if (PC::buttons.pressed(BTN_A)) {

                    if (this->inventoryMenu.mainCursor < player.getActiveSlotCount()) {
                        this->inventoryMenu.showActionMenu = true;
                        this->inventoryMenu.actionCursor = 0;
                    }
                    else {

                        gameState = GameState::Game;

                    }

                }

            }
            else {

                if (PC::buttons.pressed(BTN_B) || PC::buttons.pressed(BTN_C)) {

                    this->inventoryMenu.showActionMenu = false;

                }

                if (PC::buttons.pressed(BTN_UP) && this->inventoryMenu.actionCursor > 0) {

                    this->inventoryMenu.actionCursor--;

                }

                if (PC::buttons.pressed(BTN_DOWN) && this->inventoryMenu.actionCursor < 3) {

                    this->inventoryMenu.actionCursor++;

                }

                if (PC::buttons.pressed(BTN_A)) {

                    switch (this->inventoryMenu.actionCursor) {
                    
                        case 0:
                            {
                                bool itemUsed = false;
                                InventoryItem & inventoryItem = this->player.getActiveInventoryItem(this->inventoryMenu.mainCursor);


                                // If the user selected 'put away' ..

                                if (inventoryItem.type == this->player.getWeapon()) {

                                    this->player.setWeapon(Object::FireBall);
                                    this->inventoryMenu.showActionMenu = false;

                                }
                                else {
                        
                                    if (inventoryItem.quantity > 0) {
                        
                                        switch (inventoryItem.type) {
                        
                                            case Object::IceSpell:

                                                this->player.setWeapon(Object::IceSpell);
                                                itemUsed = true;
                                                inventoryItem.quantity--;  
                                                break;
                        
                                            case Object::GreenSpell:
                                            case Object::RedSpell:
                                            case Object::MauveSpell:

                                                this->player.setWeapon(inventoryItem.type);
                                                itemUsed = true;
                                                break;
                        
                                            case Object::Key:
                                            case Object::Tools:
                                                {
                                                    // Try the surrounding blocks to see if it can be used ..

                                                    uint8_t x = this->map.getTileX(this->player.getX());
                                                    uint8_t y = this->map.getTileY(this->player.getY());
                                                    MapTiles block = this->map.getBlock(x, y);

                                                    itemUsed = this->interactWithBlock(x, y, block);

                                                    const int8_t xOffset[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
                                                    const int8_t yOffset[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

                                                    if (!itemUsed) {

                                                        for (uint8_t i = 0; i < 8; i++) {

                                                            block = this->map.getBlock(x + xOffset[i], y + yOffset[i]);
                                                            itemUsed = this->interactWithBlock(x + xOffset[i], y + yOffset[i], block);

                                                            if (itemUsed) break;

                                                        }

                                                    }

                                                }
                                                break;
                        
                                            case Object::Tonic:
                                                if (player.getHealth() < 100) {
                                                    player.incHealth(HEALTH_INC_TONIC); 
                                                    inventoryItem.quantity--;  
                                                    itemUsed = true;
                                                    //sound health going up
                                                }
                                                else {
                                                    PS::playSFX(Sounds::sfx_CannotPickUp, Sounds::sfx_CannotPickUp_length);
                                                }
                                                break;
                        
                                            case Object::Bread:
                                                if (player.getHealth() < 100) {
                                                    player.incHealth(HEALTH_INC_BREAD); 
                                                    inventoryItem.quantity--;  
                                                    itemUsed = true;
                                                    //sound health going up
                                                }
                                                else {
                                                    PS::playSFX(Sounds::sfx_CannotPickUp, Sounds::sfx_CannotPickUp_length);
                                                }
                                                break;
                        
                                            case Object::Chicken:
                                                if (player.getHealth() < 100) {
                                                    player.incHealth(HEALTH_INC_CHICKEN); 
                                                    inventoryItem.quantity--;  
                                                    itemUsed = true;
                                                    //sound health going up
                                                }
                                                else {
                                                    PS::playSFX(Sounds::sfx_CannotPickUp, Sounds::sfx_CannotPickUp_length);
                                                }
                                                break;
                        
                                        }
                        
                                        // Did we just use the last item ?  If so move cursor up.

                                        if (itemUsed) {           
                                            
                                            if (inventoryItem.quantity == 0 && this->inventoryMenu.mainCursor > 0) this->inventoryMenu.mainCursor--;
                                            this->inventoryMenu.showActionMenu = false;
                                            gameState = GameState::Game;
                                            
                                        }
                        
                                    }

                                }
                                
                            }
                            
                            break;
                        
                        case 1:
                            {
                                // Find a matching Object in the sprites collecion that is disabled, otherwise add one ..

                                InventoryItem & inventoryItem = this->player.getActiveInventoryItem(this->inventoryMenu.mainCursor);
                                uint8_t spriteIdx = this->objects.getFirstInactiveSpriteIndex(inventoryItem.type);

                                if (spriteIdx == NO_SPRITE_FOUND) {

                                    this->objects.setObjectNum(this->objects.getObjectNum() + 1);
                                    spriteIdx = this->objects.getObjectNum() - 1;

                                }   

                                Sprite &sprite = this->objects.getSprite(spriteIdx);
                                sprite.setSprite(this->map.getTileX(this->player.getX()), this->map.getTileY(this->player.getY()), 0, inventoryItem.type, true, false);

                                // uint8_t x = this->map.getTileX(this->player.getX());
                                // uint8_t y = this->map.getTileY(this->player.getY());

                                // sprite.setType(inventoryItem.type);
                                // sprite.setActive(true);
                                // sprite.setX((x * TILE_SIZE) + 4);
                                // sprite.setY((y * TILE_SIZE) + 4);
                                sprite.setPreventImmediatePickup(true);
                                sprite.setQuantity(inventoryItem.quantity);
                                // sprite.setCarrying(Object::None);

                                switch (inventoryItem.type) {

                                    case Object::GreenSpell:
                                    case Object::RedSpell:
                                        inventoryItem.quantity = 0;
                                        this->player.setWeapon(Object::FireBall);
                                        break;

                                    default:
                                        inventoryItem.quantity--;
                                        break;

                                }


                                // Did we just use the last item ?  If so move cursor up.
                                
                                if (inventoryItem.quantity == 0 && this->inventoryMenu.mainCursor > 0) this->inventoryMenu.mainCursor--;
                                this->inventoryMenu.showActionMenu = false;

                            }
        
                            break;
                        
                        case 2:
                            this->inventoryMenu.showActionMenu = false;
                            break;
                        
                    }
                    

                }

            }

            break;

        case InventoryMenuMode::AltarPieces:

            if (PC::buttons.pressed(BTN_A) || PC::buttons.pressed(BTN_B) || PC::buttons.pressed(BTN_C)) {
        
                this->gameState = GameState::Game;
                
            }

            break;

    }
    

    // // Work out arrow direction ..

    // Direction rot = Direction::Up;

    // if (this->player.getX() / TILE_SIZE > this->eolXTile) { // Left

    //     if (this->player.getY() / TILE_SIZE > this->eolYTile) {

    //         rot = Direction::UpLeft;

    //     }
    //     else if (this->player.getY() / TILE_SIZE == this->eolYTile) {

    //         rot = Direction::Left;

    //     }
    //     else if (this->player.getY() / TILE_SIZE < this->eolYTile) {

    //         rot = Direction::DownLeft;

    //     }

    // }
    // else if (this->player.getX() / TILE_SIZE == this->eolXTile) { // Up / down

    //     if (this->player.getY() / TILE_SIZE > this->eolYTile) {

    //         rot = Direction::Up;

    //     }
    //     else if (this->player.getY() / TILE_SIZE < this->eolYTile) {

    //         rot = Direction::Down;

    //     }

    // }
    // else if (this->player.getX() / TILE_SIZE < this->eolXTile) { // Right

    //     if (this->player.getY() / TILE_SIZE > this->eolYTile) {

    //         rot = Direction::UpRight;

    //     }
    //     else if (this->player.getY() / TILE_SIZE == this->eolYTile) {

    //         rot = Direction::Right;

    //     }
    //     else if (this->player.getY() / TILE_SIZE < this->eolYTile) {

    //         rot = Direction::DownRight;

    //     }

    // }


    // Render screen ..

    switch (this->inventoryMenu.mode) {

        case InventoryMenuMode::Inventory:
            {    
                this->renderEnviroment(0, 0);
                this->renderHud();
                // PD::drawBitmap(92, 74, Images::Directions[static_cast<uint8_t>(rot)]);
                PD::setColor(0);
                PD::fillRectangle(0, 0, 88, 73);
                PD::setColor(9);
                PD::drawRectangle(0, 0, 85, 71);
                PD::setColor(4);
                PD::drawLine(1, 72, 86, 72);
                PD::drawLine(86, 1, 86, 72);
                PD::setColor(6);
                PD::setCursor(4, 3);
                PD::print("Inventory\n\n");

                uint8_t items = 0;

                if (player.getInventoryCount() > 0) {

                    for (uint8_t i = 0; i < MAX_INVENTORY_ITEMS; i++) {

                        InventoryItem inventoryItem = this->player.getInventoryItem(i);

                        if (inventoryItem.quantity > 0) {

                            PD::setCursor(10, 14 + (items * 9));
                            items++;

                            renderInventoryItem(inventoryItem);
                
                        }

                    }

                }
                else {

                    PD::setCursor(10, 14);
                    PD::print("Empty !");       

                }

                PD::setCursor(10, 62);
                PD::setColor(6);
                PD::print("Go Back");

                if (!this->inventoryMenu.showActionMenu) {

                    if (this->inventoryMenu.mainCursor < player.getActiveSlotCount()) {
                        PD::drawBitmap(3, 15 + (this->inventoryMenu.mainCursor * 9), Images::Arrow);
                    }
                    else {
                        PD::drawBitmap(3, 63, Images::Arrow);
                    }

                }
                else {

                    PD::drawBitmap(3, 15 + (this->inventoryMenu.mainCursor * 9), Images::Arrow_Dark);

                    PD::setColor(0);
                    PD::fillRect(39, 5 + this->inventoryMenu.mainCursor * 9, 72, 48);
                    PD::setColor(9);
                    PD::drawRectangle(40, 6 + this->inventoryMenu.mainCursor * 9, 67, 45);
                    PD::setColor(4);
                    PD::drawLine(41, 52 + this->inventoryMenu.mainCursor * 9, 108, 52 + this->inventoryMenu.mainCursor * 9);
                    PD::drawLine(108, 7 + this->inventoryMenu.mainCursor * 9, 108, 52 + this->inventoryMenu.mainCursor * 9);

                    PD::setColor(6);
                    PD::setCursor(44, 9 + this->inventoryMenu.mainCursor * 9);
                    PD::print("Actions");
                    PD::setCursor(50, 20 + this->inventoryMenu.mainCursor * 9);

                    InventoryItem & inventoryItem = this->player.getActiveInventoryItem(this->inventoryMenu.mainCursor);

                    if (inventoryItem.type == this->player.getWeapon()) {
                        PD::print("Put Away");
                    }
                    else {
                        PD::print("Use");
                    }

                    PD::setCursor(50, 29 + this->inventoryMenu.mainCursor * 9);
                    PD::print("Drop");
                    PD::setCursor(50, 41 + this->inventoryMenu.mainCursor * 9);
                    PD::print("Go Back");

                    switch (this->inventoryMenu.actionCursor) {

                        case 0:
                            PD::drawBitmap(43, 21 + (this->inventoryMenu.mainCursor * 9), Images::Arrow);
                            break;

                        case 1:
                            PD::drawBitmap(43, 30 + (this->inventoryMenu.mainCursor * 9), Images::Arrow);
                            break;

                        case 2:
                            PD::drawBitmap(43, 42 + (this->inventoryMenu.mainCursor * 9), Images::Arrow);
                            break;
                            
                    }
                
                }

            }

            break;

        case InventoryMenuMode::AltarPieces:

            this->renderEnviroment(0, 0);
            this->renderHud();
            // PD::drawBitmap(92, 74, Images::Directions[static_cast<uint8_t>(rot)]);

            PD::setColor(15);
            PD::fillRect(22, 8, 70, 60);

            PD::drawBitmap(15, 1, Images::AltarTOP);
            PD::drawBitmap(14, 8, Images::AltarLHS);
            PD::drawBitmap(88, 8, Images::AltarRHS);
            PD::drawBitmap(16, 64, Images::AltarBOT);

            PD::drawBitmap(33, 15, this->player.getAltarPieces() >= 1 ? Images::Rune_Red_00 : Images::Rune_Grey_00);
            PD::drawBitmap(50, 15, this->player.getAltarPieces() >= 2 ? Images::Rune_Red_01 : Images::Rune_Grey_01);
            PD::drawBitmap(67, 15, this->player.getAltarPieces() >= 3 ? Images::Rune_Red_02 : Images::Rune_Grey_02);
            PD::drawBitmap(33, 43, this->player.getAltarPieces() >= 4 ? Images::Rune_Red_03 : Images::Rune_Grey_03);
            PD::drawBitmap(50, 43, this->player.getAltarPieces() >= 5 ? Images::Rune_Red_04 : Images::Rune_Grey_04);
            PD::drawBitmap(67, 43, this->player.getAltarPieces() >= 6 ? Images::Rune_Red_05 : Images::Rune_Grey_05);

            // PD::drawBitmap(25 + (this->player.getAltarPieces() < 1 ? 8 : 0), 7 + (this->player.getAltarPieces() < 1 ? 8 : 0), this->player.getAltarPieces() >= 1 ? Images::Rune_Red_00 : Images::Rune_Grey_00);
            // PD::drawBitmap(42 + (this->player.getAltarPieces() < 2 ? 8 : 0), 7 + (this->player.getAltarPieces() < 2 ? 8 : 0), this->player.getAltarPieces() >= 2 ? Images::Rune_Red_01 : Images::Rune_Grey_01);
            // PD::drawBitmap(59 + (this->player.getAltarPieces() < 3 ? 8 : 0), 7 + (this->player.getAltarPieces() < 3 ? 8 : 0), this->player.getAltarPieces() >= 3 ? Images::Rune_Red_02 : Images::Rune_Grey_02);
            // PD::drawBitmap(25 + (this->player.getAltarPieces() < 4 ? 8 : 0), 35 + (this->player.getAltarPieces() < 4 ? 8 : 0), this->player.getAltarPieces() >= 4 ? Images::Rune_Red_03 : Images::Rune_Grey_03);
            // PD::drawBitmap(42 + (this->player.getAltarPieces() < 5 ? 8 : 0), 35 + (this->player.getAltarPieces() < 5 ? 8 : 0), this->player.getAltarPieces() >= 5 ? Images::Rune_Red_04 : Images::Rune_Grey_04);
            // PD::drawBitmap(59 + (this->player.getAltarPieces() < 6 ? 8 : 0), 35 + (this->player.getAltarPieces() < 6 ? 8 : 0), this->player.getAltarPieces() >= 6 ? Images::Rune_Red_05 : Images::Rune_Grey_05);

            break;



    }

}

void Game::renderInventoryItem(InventoryItem inventoryItem) {

    PD::setColor(6);
    PD::print(object_Descs[static_cast<uint8_t>(inventoryItem.type)]);
    PD::setColor(5);
    PD::print(" x ");
    PD::print(inventoryItem.quantity, 10);
    PD::print("\n");

}