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

            int x = (player.getX() - object.getX());
            int y = (player.getY() - object.getY());
            uint8_t frame = object.getFrame();
            uint8_t offset = object.getOffset();

            PD::drawBitmap((CENTERX-4) - x,(CENTERY-4) - y, Images::Sprites[frame + offset]);

        }

    }

}