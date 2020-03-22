#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


void Game::showInventory() {


    // If the cursor > active inventory slots then decrease it ..

    if (this->inventoryMenu.mainCursor > player.getActiveSlotCount()) {

        this->inventoryMenu.mainCursor = player.getActiveSlotCount();

    }


    // Handle player actions ..

    if (PC::buttons.pressed(BTN_C)) {

        if (this->inventoryMenu.showActionMenu) {

            this->inventoryMenu.showActionMenu = false;
        }
        else {
    
            gameState = GameState::Game;

        }

    }

    if (!inventoryMenu.showActionMenu) {

        if (PC::buttons.pressed(BTN_C)) {
      
            gameState = GameState::Game;

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

        if (PC::buttons.pressed(BTN_C)) {

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
            
                        if (inventoryItem.quantity > 0) {
            
                            switch (inventoryItem.type) {
            
                                case Object::Key:
                                case Object::Spanner:
                                case Object::Potion:
                                    //sound do nothing
                                    break;
            
                                case Object::Donut:
                                    if (player.getHealth() < 100) {
                                        player.setHealth(player.getHealth() + 5); 
                                        inventoryItem.quantity--;  
                                        itemUsed = true;
                                        //sound health going up
                                    }
                                    else {
                                        //sound cannot use
                                    }
                                    break;
            
                                case Object::Ham:
                                    if (player.getHealth() < 100) {
                                        player.setHealth(player.getHealth() + 10); 
                                        inventoryItem.quantity--;  
                                        itemUsed = true;
                                        //sound health going up
                                    }
                                    else {
                                        //sound cannot use
                                    }
                                    break;
            
                            }
            
                            // Did we just use the last item ?  If so move cursor up.

                            if (itemUsed) {           
                                
                                if (inventoryItem.quantity == 0 && this->inventoryMenu.mainCursor > 0) this->inventoryMenu.mainCursor--;
                                this->inventoryMenu.showActionMenu = false;
                                
                            }
            
                        }
                        
                    }
                    
                    break;
                
                case 1:
                    {
                        // Find a matching Object in the sprites collecion that is disabled.

                        InventoryItem & inventoryItem = this->player.getActiveInventoryItem(this->inventoryMenu.mainCursor);
                        uint8_t spriteIdx = this->objects.getFirstInactiveSpriteIndex(inventoryItem.type);

                        if (spriteIdx != NO_SPRITE_FOUND) {

                            Sprite &sprite = this->objects.getSprite(spriteIdx);

                            uint8_t x = this->map.getTileX(this->player.getX());
                            uint8_t y = this->map.getTileY(this->player.getY());

                            sprite.setActive(true);
                            sprite.setX((x * TILE_SIZE) + 4);
                            sprite.setY((y * TILE_SIZE) + 4);
                            sprite.setPreventImmediatePickup(true);

                            inventoryItem.quantity--;


                            // Did we just use the last item ?  If so move cursor up.
                            
                            if (inventoryItem.quantity == 0 && this->inventoryMenu.mainCursor > 0) this->inventoryMenu.mainCursor--;
                            this->inventoryMenu.showActionMenu = false;

                        }

                    }
  
                    break;
                
                case 2:
                    this->inventoryMenu.showActionMenu = false;
                    break;
                
            }
            

        }

    }
    
    

    // Render Inventory ..

    PD::setColor(0);
    PD::fillRectangle(0, 0, 86, 72);
    PD::setColor(1);
    PD::drawRectangle(0, 0, 85, 71);
    PD::setColor(7);
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
    PD::setColor(7);
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

        PD::drawBitmap(5, 16 + (this->inventoryMenu.mainCursor * 9), Images::Arrow_Dark);

        PD::setColor(0);
        PD::fillRect(39, 5 + this->inventoryMenu.mainCursor * 9, 69, 47);
        PD::setColor(1);
        PD::drawRectangle(40, 6 + this->inventoryMenu.mainCursor * 9, 67, 45);
        PD::setColor(7);
        PD::setCursor(44, 9 + this->inventoryMenu.mainCursor * 9);
        PD::print("Actions");
        PD::setCursor(50, 20 + this->inventoryMenu.mainCursor * 9);
        PD::print("Use");
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

void Game::renderInventoryItem(InventoryItem inventoryItem) {

    PD::setColor(7);
    PD::print(object_Descs[static_cast<uint8_t>(inventoryItem.type)]);
    PD::setColor(5);
    PD::print(" x ");
    PD::print(inventoryItem.quantity, 10);
    PD::print("\n");

}