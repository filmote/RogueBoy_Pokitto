#include "Sprites.h"
#include "../images/Images.h"

Sprite & Sprites::getSprite(uint8_t index) {

    return this->objects[index];
    
}


uint8_t Sprites::getFirstInactiveSpriteIndex(Object type) {

    for (uint8_t i = 0; i < this->oNum; i++) {

        auto &object = this->objects[i];

        if (object.getType() == type && !object.getActive()) {

            return i;

        }

    }

    return NO_SPRITE_FOUND;
        
}

uint8_t Sprites::getObjectNum() {

    return this->oNum;

}

void Sprites::setObjectNum(uint8_t oNum) {
 
    this->oNum = oNum;

}

void Sprites::renderHealthBar(uint32_t x, uint32_t y, uint8_t health) {

    PD::drawBitmap(x, y, Images::HealthBar);
    PD::setColor(8);
    PD::drawLine(x + 2, y + 1, x + 2 + health, y + 1);

}

void Sprites::render(Player &player) {

    for (uint8_t i = 0; i < this->oNum; i++) {

        auto &object = this->objects[i];

        if (object.getActive()) {

            int x = (CENTERX - PLAYER_SIZE_HALF) - (player.getX() - object.getX());
            int y = (CENTERY - PLAYER_SIZE_HALF) - (player.getY() - object.getY());
            
            uint8_t frame = object.getFrame();
            int8_t offset = object.getOffset();
            Direction direction = object.getDirection();

            switch (object.getType()) {

                case Object::Coin:
                    PD::drawBitmap(x + offset, y + offset, Images::Coins[frame]);
                    break;

                case Object::Bat:
                    PD::drawBitmap(x + offset, y + offset, Images::Bats[frame]);
                    if (object.getRenderHealthBar()) { this->renderHealthBar(x + 6, y - 6, 10 * object.getHealth() / object.getHealthOrig()); }
                    break;

                case Object::Spider:
                    PD::drawBitmap(x + offset, y + offset, Images::Spiders[(static_cast<uint8_t>(direction) * 2) + frame]);
                    if (object.getRenderHealthBar()) { this->renderHealthBar(x + 6, y - 6, 10 * object.getHealth() / object.getHealthOrig()); }
                    break;

                case Object::BigSpider:
                    PD::drawBitmap(x + offset, y + offset, Images::BigSpiders[(static_cast<uint8_t>(direction) * 2) + frame]);
                    if (object.getRenderHealthBar()) { this->renderHealthBar(x + 6, y - 6, 10 * object.getHealth() / object.getHealthOrig()); }
                    break;

                case Object::SackOCash:
                    PD::drawBitmap(x + offset, y + offset, Images::SackOCash);
                    break;

                case Object::Donut:
                   PD::drawBitmap(x + offset, y + offset, Images::Donut);
//                    PD::drawBitmap(x, y, Images::Donut);
                    break;

                case Object::Key:
                    PD::drawBitmap(x + offset, y + offset, Images::Key);
                    break;

                case Object::Ham:
                    PD::drawBitmap(x + offset, y + offset, Images::Ham);
                    break;

                case Object::Floater:
                    if (object.getRenderHealthBar()) { this->renderHealthBar(x + 6, y - 6, 10 * object.getHealth() / object.getHealthOrig()); }
                    PD::drawBitmap(x + offset, y + offset, Images::Floater);
                    break;

                case Object::Skull:
                    if (object.getRenderHealthBar()) { this->renderHealthBar(x + 6, y - 6, 10 * object.getHealth() / object.getHealthOrig()); }
                    PD::drawBitmap(x + offset, y + offset, Images::Skull);
                    break;

                case Object::Spanner:
                    PD::drawBitmap(x + offset, y + offset, Images::Spanner);
                    break;

                case Object::Potion:
                    PD::drawBitmap(x + offset, y + offset, Images::Potion);
                    break;

            }

        }

    }

}


void Sprites::clearPreventImmediatePickup(Player &player) {

    uint8_t playerX = player.getX() / TILE_WIDTH;
    uint8_t playerY = player.getY() / TILE_HEIGHT;

    for (uint8_t i = 0; i < this->oNum; i++) {

        auto &object = this->objects[i];

        uint8_t objectX = object.getX() / TILE_WIDTH;
        uint8_t objectY = object.getY() / TILE_HEIGHT;    

        if (object.getPreventImmediatePickup() && (playerX != objectX || playerY != objectY)) {

            object.setPreventImmediatePickup(false);

        }

    }

}