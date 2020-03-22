#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


void Game::showInventory() {


    // If the cursor > active inventory slots then decrease it ..

    if (this->inventoryMenu.mainCursor > player.getActiveSlotCount() - 1) {

        this->inventoryMenu.mainCursor = player.getActiveSlotCount() - 1;

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

        if (PC::buttons.pressed(BTN_UP) && this->inventoryMenu.mainCursor > 0) {

            this->inventoryMenu.mainCursor--;

        }

        if (PC::buttons.pressed(BTN_DOWN) && this->inventoryMenu.mainCursor < player.getActiveSlotCount() - 1) {

            this->inventoryMenu.mainCursor++;

        }

        if (PC::buttons.pressed(BTN_A)) {

            this->inventoryMenu.showActionMenu = true;
            this->inventoryMenu.actionCursor = 0;

        }

    }
    else {

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
                                    //sound do nothing
                                    break;
            
                                case Object::Donut:
                                    if (player.getHealth() < 1000) {
                                        player.setHealth(player.getHealth() + 5); 
                                        inventoryItem.quantity--;  
                                        itemUsed = true;
                                        //sound health going up
                                    }
                                    break;
            
                                case Object::Ham:
                                    if (player.getHealth() < 1000) {
                                        player.setHealth(player.getHealth() + 10); 
                                        inventoryItem.quantity--;  
                                        itemUsed = true;
                                        //sound health going up
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
    PD::fillRectangle(1, 1, 87, 67);
    PD::setColor(1);
    PD::drawRectangle(2, 2, 85, 65);
    PD::setColor(7);
    PD::setCursor(6,5);
    PD::print("Inventory");

    uint8_t items = 0;

    for (uint8_t i = 0; i < MAX_INVENTORY_ITEMS; i++) {

        InventoryItem inventoryItem = this->player.getInventoryItem(i);

        if (inventoryItem.quantity > 0) {

            PD::setCursor(12, 17 + (items * 9));
            items++;

            switch (inventoryItem.type) {

                case Object::Key:
                    PD::print("Key x ");
                    PD::print(inventoryItem.quantity, 10);
                    PD::print("\n");
                    break;

                case Object::Donut:
                    PD::print("Donut x ");
                    PD::print(inventoryItem.quantity, 10);
                    PD::print("\n");
                    break;

                case Object::Ham:
                    PD::print("Ham x ");
                    PD::print(inventoryItem.quantity, 10);
                    PD::print("\n");
                    break;

                case Object::Spanner:
                    PD::print("Spanner x ");
                    PD::print(inventoryItem.quantity, 10);
                    PD::print("\n");
                    break;
                
            }
 
        }

    }
    
    if (player.getInventoryCount() > 0) {

        // if (this->player.getActiveInventoryItem(this->inventoryMenu.mainCursor).getCanEat()) {        

        //     PD::drawBitmap(6, 12 + this->inventoryMenu.mainCursor * 8, Images::Arrow);

        // }
        // else {
        
        //     PD::drawBitmap(6, 21 + this->inventoryMenu.mainCursor * 8, Images::Arrow_Dark);

        // }

        if (!this->inventoryMenu.showActionMenu) {

            PD::drawBitmap(5, 18 + (this->inventoryMenu.mainCursor * 9), Images::Arrow);

        }
        else {

            PD::drawBitmap(5, 18 + (this->inventoryMenu.mainCursor * 9), Images::Arrow_Dark);

            PD::setColor(0);
            PD::fillRect(39, 11 + this->inventoryMenu.mainCursor * 8, 69, 49);
            PD::setColor(1);
            PD::drawRectangle(40, 12 + this->inventoryMenu.mainCursor * 8, 67, 47);
            PD::setColor(7);
            PD::setCursor(44, 15 + this->inventoryMenu.mainCursor * 8);
            PD::print("Actions");
            PD::setCursor(50, 27 + this->inventoryMenu.mainCursor * 8);
            PD::print("Use");
            PD::setCursor(50, 36 + this->inventoryMenu.mainCursor * 8);
            PD::print("Drop");
            PD::setCursor(50, 49 + this->inventoryMenu.mainCursor * 8);
            PD::print("Go Back");

            switch (this->inventoryMenu.actionCursor) {

                case 0:
                    PD::drawBitmap(44, 27 + (this->inventoryMenu.mainCursor * 9), Images::Arrow);
                    break;

                case 1:
                    PD::drawBitmap(44, 36 + (this->inventoryMenu.mainCursor * 9), Images::Arrow);
                    break;

                case 2:
                    PD::drawBitmap(44, 49 + (this->inventoryMenu.mainCursor * 9), Images::Arrow);
                    break;
                    
            }

        }

    }
    else {

        PD::print("You are not carrying anything.");

    }

}