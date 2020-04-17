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

void Sprites::render(Player &player, bool showEnemies) {

    for (uint8_t i = 0; i < this->oNum; i++) {

        auto &object = this->objects[i];

        if (object.getActive()) {

            int x = (CENTERX - PLAYER_SIZE_HALF) - (player.getX() - object.getX());
            int y = (CENTERY - PLAYER_SIZE_HALF) - (player.getY() - object.getY());
            
            uint8_t frame = object.getFrame();
            int8_t offset = object.getOffset();
            Direction direction = object.getDirection();

            this->renderSprite(object.getType(), x, y, offset, direction, frame, showEnemies, object.getRenderHealthBar(), 10 * object.getHealth() / object.getHealthOrig());


            // Render puff ?

            uint8_t puffIndex = object.getPuffIndex();
            if (puffIndex > 0) {
// printf("puff %i\n", puffIndex);
                PD::drawBitmap(x - 4, y - 4, Images::Puff[(10 - puffIndex) / 2]);

            }

        }

    }

}

void Sprites::renderSprite(Object type, int x, int y) {

    int8_t offset = spriteOffsets[static_cast<uint8_t>(type)];

    this->renderSprite(type, x, y, offset, Direction::Up, 0, false, false, 0);

}


void Sprites::renderSprite(Object type, int x, int y, int8_t offset, Direction direction, uint8_t frame, bool showEnemies, bool renderHealth, int healthValue ) {

    switch (type) {

        case Object::Coin:
            PD::drawBitmap(x + offset, y + offset, Images::Coins[frame]);
            break;

        case Object::Bat:
            if (showEnemies) {
                PD::drawBitmap(x + offset, y + offset, Images::Bats[frame]);
                if (renderHealth) { this->renderHealthBar(x + 6, y - 6, healthValue); }
            }
            break;

        case Object::Spider:
            if (showEnemies) {
                PD::drawBitmap(x + offset, y + offset, Images::Spiders[(static_cast<uint8_t>(direction) * 2) + frame]);
                if (renderHealth) { this->renderHealthBar(x + 6, y - 6, healthValue); }
            }
            break;

        case Object::BigSpider:
            if (showEnemies) {
                PD::drawBitmap(x + offset, y + offset, Images::BigSpiders[(static_cast<uint8_t>(direction) * 2) + frame]);
                if (renderHealth) { this->renderHealthBar(x + 6, y - 6, healthValue); }
            }
            break;

        case Object::Skull:
            if (showEnemies) {
                if (renderHealth) { this->renderHealthBar(x + 6, y - 6, healthValue); }
                PD::drawBitmap(x + offset, y + offset, Images::Skull);
            }
            break;

        case Object::NewEnemy:
            if (showEnemies) {
                PD::drawBitmap(x + offset, y + offset, Images::NewEnemys[(static_cast<uint8_t>(direction))]);
                if (renderHealth) { this->renderHealthBar(x + 6, y - 6, healthValue); }
            }
            break;

        case Object::SackOCash:
            PD::drawBitmap(x + offset, y + offset, Images::SackOCash);
            break;

        case Object::Bread:
            PD::drawBitmap(x + offset, y + offset, Images::Bread);
//                    PD::drawBitmap(x, y, Images::Bread);
            break;

        case Object::Key:
            PD::drawBitmap(x + offset, y + offset, Images::Key);
            break;

        case Object::Chicken:
            PD::drawBitmap(x + offset, y + offset, Images::Chicken);
            break;

        case Object::Floater:
            if (renderHealth) { this->renderHealthBar(x + 6, y - 6, healthValue); }
            PD::drawBitmap(x + offset, y + offset, Images::Floater);
            break;

        case Object::Tools:
            PD::drawBitmap(x + offset, y + offset, Images::Tools);
            break;

        case Object::Tonic:
            PD::drawBitmap(x + offset, y + offset, Images::Tonic);
            break;

        case Object::IceSpell:
            PD::drawBitmap(x + offset, y + offset, Images::IceSpell[frame]);
            break;

        case Object::GreenSpell:
            PD::drawBitmap(x + offset, y + offset, Images::GreenSpell);
            break;

        case Object::YellowSpell:
            PD::drawBitmap(x + offset, y + offset, Images::YellowSpell);
            break;

        case Object::MauveSpell:
            PD::drawBitmap(x + offset, y + offset, Images::MauveSpell);
            break;

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