#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

void Game::init(uint16_t x, uint16_t y, bool resetObjects) {

    //sound.tone(NOTE_C7H,150, NOTE_REST,100, NOTE_C6,150);
    player.init(x, y);

    for (uint8_t i = 0; i < 6; i++) {

        bullets.getPlayerBullet(i).kill();

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

bool Game::collision(Player &player, Sprite &object) {
    
    Rect objectRect = object.getRect();

    if (object.isEnemy()) {

        objectRect.x = objectRect.x - (this->levelStartDelay > 0 ? 2 : 1);
        objectRect.y = objectRect.y - (this->levelStartDelay > 0 ? 2 : 1);
        objectRect.width = objectRect.width + (this->levelStartDelay > 0 ? 4 : 2);
        objectRect.height = objectRect.height + (this->levelStartDelay > 0 ? 4 : 2);
        
    }

//Rect playerRect = player.getRect();
    // printf("PO %i { %i,%i,%i,%i }  { %i,%i,%i,%i }  = %i %i \n", object.getType(), playerRect.x, playerRect.y, playerRect.width, playerRect.height, objectRect.x, objectRect.y, objectRect.width, objectRect.height, collide(playerRect, objectRect), object.getCountdown());
    return collide(player.getRect(), objectRect);

}

bool Game::collision(Player &player, Bullet &bullet) {

// Rect playerRect = player.getRect();
// Rect objectRect = bullet.getRect();

// printf("PB { %i,%i,%i,%i }  { %i,%i,%i,%i }  = %i \n", playerRect.x, playerRect.y, playerRect.width, playerRect.height, objectRect.x, objectRect.y, objectRect.width, objectRect.height, collide(playerRect, objectRect));

    return collide(player.getRect(), bullet.getRect());

}



bool Game::collision(Sprite &object1, Sprite &object2) {

    return collide(object1.getRect(), object2.getRect());

}

bool Game::collision(Sprite &object, Bullet &bullet) {

    return collide(object.getRect(), bullet.getRect());

}

void Game::barrelBreak(MapInformation &map, uint8_t x, uint8_t y, Sprites &objects) {
    
    this->map.setBlock(x, y, MapTiles::Rubble);
    //sound.tone(NOTE_C3,50, NOTE_C2,50, NOTE_E3,150);
}

void Game::printPaddedNumber(int32_t number, uint8_t places) {

    if (places >= 5 && number < 10000) PD::print("0");
    if (places >= 4 && number < 1000) PD::print("0");
    if (places >= 3 && number < 100) PD::print("0");
    if (places >= 2 && number < 10) PD::print("0");
    PD::print(number, 10);

}

Direction Game::getNearestCardinalDirection(Direction direction, Axis axis) {

    switch (axis) {

        case Axis::XAxis:

            switch (direction) {

                case Direction::UpLeft:
                case Direction::Left:
                case Direction::DownLeft:

                    return Direction::Left;

                case Direction::Up:
                case Direction::Down:

                    return Direction::None;

                case Direction::UpRight:
                case Direction::Right:
                case Direction::DownRight:

                    return Direction::Right;
                
            }

            break;

        case Axis::YAxis:

            switch (direction) {

                case Direction::UpLeft:
                case Direction::Up:
                case Direction::UpRight:

                    return Direction::Up;

                case Direction::Left:
                case Direction::Right:

                    return Direction::None;

                case Direction::DownLeft:
                case Direction::Down:
                case Direction::DownRight:

                    return Direction::Down;
                
            }

            break;

    }

    return Direction::Up;

}