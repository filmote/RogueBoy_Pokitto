#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

#define SHOP_ITEMS_TOP          10
#define SHOP_ITEMS_SPACING      11
#define SHOP_ITEMS_ICON_LEFT    10
#define SHOP_ITEMS_DESC_LEFT    23
#define SHOP_ITEMS_COST_LEFT    80


void Game::showShop() {


    // Update timer ..

    if (Pokitto::Core::frameCount % TIMER_STEP == 0) { this->map.decTimer();  }
    if (this->map.getTimer() == 0) { 
        
        player.setHealth(0); 
     
        if (player.getHealth() <= 0) {
           //sound.tones(DeathNotes); 
            gameState = GameState::Dead;

        }
        
    }

    if (PC::buttons.pressed(BTN_A)) {

        if (this->shopMessage == ShopMessage::None) {

            ShopObject &shopObject = this->shopObjects[this->shopUpperIndex + this->shopItemIndex];

            if (shopObject.quantityLeft == 0) {

                this->shopMessage = ShopMessage::OutOfStock;

            }
            else if (shopObject.price > this->player.getCoinsOverall()) {

                this->shopMessage = ShopMessage::NotEnoughGold;

            }
            else {
            
                uint8_t slot = this->player.addInventoryItem(shopObject.object, 1);

                if (slot == NO_SLOT_FOUND) {

                    this->shopMessage = ShopMessage::InventoryFull;

                }
                else {
printf("paid %i i %i = ", this->player.getCoinsOverall(), shopObject.price);
                    this->player.setCoinsOverall(this->player.getCoinsOverall() - shopObject.price);
                    shopObject.quantityLeft = shopObject.quantityLeft - 1;
printf("%i\n", this->player.getCoinsOverall());
                    
                }

            }

        }
        else {

           this->shopMessage = ShopMessage::None;

        }

    }


    if (PC::buttons.pressed(BTN_C)) {
        gameState = GameState::Game;
    }

    if (PC::buttons.pressed(BTN_UP)) {

        switch (this->shopUpperIndex) {

            case 0:
                if (this->shopItemIndex > 0) {
                    this->shopItemIndex--;
                }
                break;

            default:
                if (this->shopItemIndex > 2) {
                    this->shopItemIndex--;
                } 
                else {
                    this->shopUpperIndex--;
                }
                break;

        }
      
    }

    if (PC::buttons.pressed(BTN_DOWN)) {

        switch (this->shopUpperIndex) {

            case 0 ... 1:
                if (this->shopItemIndex < 2) {
                    this->shopItemIndex++;
                }
                else {
                    this->shopUpperIndex++;
                }
                break;

            default:
                if (this->shopItemIndex < 4) {
                    this->shopItemIndex++;
                }
                break;
                
        }

    }





    //this->renderEnviroment(0, 0);
    PD::setColor(15, 0);
    this->renderHud();
    PD::setColor(6);


    for (uint8_t i = this->shopUpperIndex, j = 0; i < this->shopUpperIndex + 5; i++, j++) {

        ShopObject shopObject = this->shopObjects[i];

        this->objects.renderSprite(shopObject.object, SHOP_ITEMS_ICON_LEFT, SHOP_ITEMS_TOP + (j * SHOP_ITEMS_SPACING));
        PD::setCursor(SHOP_ITEMS_DESC_LEFT, SHOP_ITEMS_TOP + 1 + (j * SHOP_ITEMS_SPACING));
        PD::print(object_Descs[static_cast<uint8_t>(shopObject.object)]);

        if (shopObject.quantityLeft != 0) {
            PD::setCursor(SHOP_ITEMS_COST_LEFT + (shopObject.price < 10 ? 6 : 0), SHOP_ITEMS_TOP + 1 + (j * SHOP_ITEMS_SPACING));
            PD::print("$ ");
            PD::print(shopObject.price);
        }
        else {

            PD::drawBitmap(76, SHOP_ITEMS_TOP + 2 + (j * SHOP_ITEMS_SPACING), Images::SoldOut);

        }

    }

    PD::setColor(5);
    PD::drawRect(SHOP_ITEMS_ICON_LEFT - 3, SHOP_ITEMS_TOP - 2 + (this->shopItemIndex * SHOP_ITEMS_SPACING), 98, 12 );

    if (this->shopMessage != ShopMessage::None) { 
        
        PD::setColor(4, 15);
        PD::drawBitmap(15, 22, Images::MessagePanel); 
        PD::setFont(font3x5);

        switch (this->shopMessage) {

            case ShopMessage::NotEnoughGold:
                PD::setCursor(27, 30);
                PD::print("You do not have");
                PD::setCursor(29, 37);
                PD::print("enough gold to");
                PD::setCursor(42, 44);
                PD::print("buy that!");
                break;

            case ShopMessage::OutOfStock:
                PD::setCursor(25, 30);
                PD::print("We are currently");
                PD::setCursor(27, 37);
                PD::print("out of stock of");
                PD::setCursor(38, 44);
                PD::print("that item!");
                break;

            case ShopMessage::InventoryFull:
                PD::setCursor(25, 30);
                PD::print("You are carrying");
                PD::setCursor(23, 37);
                PD::print("more than you can");
                PD::setCursor(42, 44);
                PD::print("handle!");
                break;                
                
        }

        PD::setFont(fontKoubit);

    }


    PD::setColor(15, 0);

}
