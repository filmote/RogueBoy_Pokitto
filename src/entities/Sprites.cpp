#include "Sprites.h"
#include "../images/Images.h"

Sprite & Sprites::getSprite(uint8_t index) {

    return this->objects[index];
    
}

uint8_t Sprites::getObjectNum() {

    return this->oNum;

}

void Sprites::setObjectNum(uint8_t oNum) {

    this->oNum = oNum;

}

void Sprites::render(Player &player) {

    for (uint8_t i = 0; i < this->oNum; i++) {

        auto &object = this->objects[i];

        if (object.getActive()) {

            int x = (CENTERX - PLAYER_SIZE_HALF) - (player.getX() - object.getX());
            int y = (CENTERY - PLAYER_SIZE_HALF) - (player.getY() - object.getY());
            uint8_t frame = object.getFrame();
            uint8_t offset = object.getOffset();
            Rotation rotation = object.getRotation();

            switch (object.getType()) {

                case Object::Coin:
                    PD::drawBitmap(x, y, Images::Coins[frame]);
                    break;

                case Object::Bat:
                    PD::drawBitmap(x, y, Images::Bats[frame]);
                    break;

                case Object::Spider:
                    PD::drawBitmap(x, y, Images::Spiders[static_cast<uint8_t>(rotation)]);
                    break;

                case Object::SackOCash:
                    PD::drawBitmap(x, y, Images::SackOCash);
                    break;

                case Object::Donut:
                    PD::drawBitmap(x, y, Images::Donut);
                    break;

                case Object::Key:
                    PD::drawBitmap(x, y, Images::Key);
                    break;

                case Object::Ham:
                    PD::drawBitmap(x, y, Images::Ham);
                    break;

                case Object::Floater:
                    PD::drawBitmap(x, y, Images::Floater);
                    break;

                case Object::Skull:
                    PD::drawBitmap(x, y, Images::Skull);
                    break;

                case Object::Spanner:
                    PD::drawBitmap(x, y, Images::Spanner);
                    break;

            }

        }

    }

}