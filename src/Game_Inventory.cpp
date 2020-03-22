#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


void Game::showInventory() {


    // If the cursor > active inventory slots then decrease it ..

    if (this->inventoryCursor > player.getActiveSlotCount() - 1) {

        this->inventoryCursor = player.getActiveSlotCount() - 1;

    }


    // Handle player actions ..

    if (PC::buttons.pressed(BTN_C)) {

        gameState = GameState::Game;

    }

    if (PC::buttons.pressed(BTN_UP) && this->inventoryCursor > 0) {

        this->inventoryCursor--;

    }

    if (PC::buttons.pressed(BTN_DOWN) && this->inventoryCursor < player.getActiveSlotCount() - 1) {

        this->inventoryCursor++;

    }

    if (PC::buttons.pressed(BTN_A)) {

        InventoryItem & inventoryItem = this->player.getActiveInventoryItem(this->inventoryCursor);

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
                        //sound health going up
                    }
                    break;

                case Object::Ham:
                    if (player.getHealth() < 1000) {
                        player.setHealth(player.getHealth() + 10); 
                        inventoryItem.quantity--;  
                        //sound health going up
                    }
                    break;

            }

            // Did we just use the last item ?  If so move cursor up.

            if (inventoryItem.quantity == 0 && this->inventoryCursor > 0) this->inventoryCursor--;

        }

    }
    
    

    // Render Inventory ..

    PD::setCursor(0,0);
    PD::print("Inventory\n\n");

    for (uint8_t i = 0; i < MAX_INVENTORY_ITEMS; i++) {

        InventoryItem inventoryItem = this->player.getInventoryItem(i);

        if (inventoryItem.quantity > 0) {

            switch (inventoryItem.type) {

                case Object::Key:
                    PD::print("   Key x ");
                    PD::print(inventoryItem.quantity, 10);
                    PD::print("\n");
                    break;

                case Object::Donut:
                    PD::print("   Donut x ");
                    PD::print(inventoryItem.quantity, 10);
                    PD::print("\n");
                    break;

                case Object::Ham:
                    PD::print("   Ham x ");
                    PD::print(inventoryItem.quantity, 10);
                    PD::print("\n");
                    break;

                case Object::Spanner:
                    PD::print("   Spanner x ");
                    PD::print(inventoryItem.quantity, 10);
                    PD::print("\n");
                    break;

                
            }
 
        }

    }
    
    if (player.getInventoryCount() > 0) {

        if (this->player.getActiveInventoryItem(this->inventoryCursor).getCanEat()) {        

            PD::drawBitmap(0, 17 + this->inventoryCursor * 8, Images::Arrow);

        }
        else {
        
            PD::drawBitmap(0, 17 + this->inventoryCursor * 8, Images::Arrow_Dark);

        }

    }
    else {

        PD::print("You are not carrying anything.");

    }

}