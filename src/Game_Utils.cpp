#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

void Game::init(uint16_t x, uint16_t y, bool resetObjects) {

    //sound.tone(NOTE_C7H,150, NOTE_REST,100, NOTE_C6,150);
    player.init(x, y);

    for (uint8_t i = 0; i < 6; i++) {

        bullets.getBullet(i).kill();

    }

    if (resetObjects) {
        
        for (uint8_t i = 0; i < MAXOBJECT; i++) {

            auto & object = this->objects.getSprite(i);
            object.setActive(false);

        }

    }

    this->map.setTimer(255);

}

bool Game::intersect(uint16_t min0, uint16_t max0, uint16_t min1, uint16_t max1) {

    return ((max0 > min1) && (min0 < max1));

}

// bool Game::collision(uint16_t x, uint16_t y, uint16_t x1, uint16_t y1) {

//     return (this->intersect(x, x + 8, x1, x1 + 8) && this->intersect(y, y + 8, y1, y1 + 8));

// }


bool Game::collision(Player &player, Sprite &enemy, bool touching) {
  
    Rect playerRect = { player.getX() - (player.getWidth() / 2), player.getY() - (player.getHeight() / 2), player.getWidth(), player.getHeight() };
    Rect enemyRect =  { enemy.getX() - (enemy.getWidth() / 2) - (touching ? 1 : 0), enemy.getY() - (enemy.getHeight() / 2) - (touching ? 1 : 0), enemy.getWidth() + (touching ? 2 : 0), enemy.getHeight() + (touching ? 2 : 0) };

    return collide(playerRect, enemyRect);

}

bool Game::collision(Sprite &object1, Sprite &object2) {
  
    Rect object1Rect = { object1.getX() - (object1.getWidth() / 2), object1.getY() - (object1.getHeight() / 2), object1.getWidth(), object1.getHeight() };
    Rect object2Rect =  { object2.getX() - (object2.getWidth() / 2), object2.getY() - (object2.getHeight() / 2), object2.getWidth(), object2.getHeight() };

    return collide(object1Rect, object2Rect);

}

bool Game::collision(Sprite &object, Bullet &bullet) {
  
    Rect objectRect = { object.getX() - (object.getWidth() / 2), object.getY() - (object.getHeight() / 2), object.getWidth(), object.getHeight() };
    Rect bulletRect =  { bullet.getX() - 2, bullet.getY() - 2, 4, 4 };

    return collide(objectRect, bulletRect);

}

void Game::barrelBreak(MapInformation &map, uint8_t x, uint8_t y, Sprites &objects) {
    
    this->map.setBlock(x, y, MapTiles::Rubble);
    dropItem(x, y, false, this->objects);
    //sound.tone(NOTE_C3,50, NOTE_C2,50, NOTE_E3,150);
}
