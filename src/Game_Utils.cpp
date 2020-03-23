#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

void Game::init(uint16_t x, uint16_t y) {

    //sound.tone(NOTE_C7H,150, NOTE_REST,100, NOTE_C6,150);
    player.init(x, y);

    for (uint8_t i = 0; i < 6; i++) {

        bullets.getBullet(i).kill();

    }

    for (uint8_t i = 0; i < MAXOBJECT; i++) {

        auto & object = this->objects.getSprite(i);
        object.setActive(false);

    }

    this->map.setTimer(255);

}

bool Game::intersect(uint16_t min0, uint16_t max0, uint16_t min1, uint16_t max1) {

    return ((max0 > min1) && (min0 < max1));

}

bool Game::collision(uint16_t x, uint16_t y, uint16_t x1, uint16_t y1) {

    return (this->intersect(x, x + 8, x1, x1 + 8) && this->intersect(y, y + 8, y1, y1 + 8));

}


void Game::barrelBreak(MapInformation map, uint8_t x, uint8_t y, Sprites &objects) {
    
    this->map.setBlock(x, y, MapTiles::Rubble);
    dropItem(x, y, false, this->objects);
    //sound.tone(NOTE_C3,50, NOTE_C2,50, NOTE_E3,150);
}
