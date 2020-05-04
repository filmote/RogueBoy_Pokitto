#include "Pokitto.h"
#include "Bullet.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


bool Bullet::getActive()                        { return active;}
uint16_t Bullet::getX()                         { return x;}
uint16_t Bullet::getY()                         { return y;}
uint8_t Bullet::getFrame()                      { return frame;}
Direction Bullet::getDirection()                { return direction;}
Object Bullet::getWeapon()                      { return weapon;}

void Bullet::setX(uint16_t x)                   { this->x = x;}
void Bullet::setY(uint16_t y)                   { this->y = y;}
void Bullet::setActive(bool active)             { this->active = active;}
void Bullet::setWeapon(Object weapon)           { this->weapon = weapon;}
void Bullet::setDirection(Direction direction)  { this->direction = direction;}

void Bullet::kill()                             { this->active = false;}

uint8_t Bullet::getWidth() {

    switch (this->weapon) {

        case Object::FireBall:
        case Object::IceSpell:
        case Object::GreenSpell:
        case Object::RedSpell:
        case Object::MauveSpell:

            return 4;

        case Object::SpiderWeb:

            switch (this->frame) {

                case 0:
                    return 6;

                case 1:
                    return 8;

                case 2 ... 5:
                    return 14;

            }

            break;

        default: return 4;

    } 

}

uint8_t Bullet::getHeight() {

    return this->getWidth();

}


void Bullet::setBullet(uint16_t x, uint16_t y, Direction direction, Object weapon) { 

    this->x = x; 
    this->y = y; 
    this->direction = direction; 
    this->active = true; 
    this->weapon = weapon; 
    this->frame = 0;
    this->lifeCountdown = BULLET_WEB_FRAMES;

}

Rect Bullet::getRect() {

    switch (this->weapon) {

        case Object::SpiderWeb:

            switch (this->frame) {

                case 0:
                    return Rect { this->getX() - 3, this->getY() - 3, 6, 6 };

                case 1:
                    return Rect { this->getX() - 4, this->getY() - 4, 8, 8 };

                case 2:
                    return Rect { this->getX() - 7, this->getY() - 7, 14, 14 };

                case 3:
                    return Rect { this->getX() - 5, this->getY() - 5, 10, 10 };

                case 4:
                    return Rect { this->getX() - 4, this->getY() - 4, 8, 8 };

                case 5:
                    return Rect { this->getX() - 3, this->getY() - 3, 6, 6 };

            }

            return Rect { this->getX() - (this->getWidth() / 2), this->getY() - (this->getHeight() / 2), this->getWidth(), this->getHeight() };


        default:

            return Rect { this->getX() - 2, this->getY() - 2, 4, 4 };

    }

}

void Bullet::update() {

    if (this->getActive()) {

        switch (this->weapon) {

            case Object::FireBall:
            case Object::IceSpell:
            case Object::GreenSpell:
            case Object::RedSpell:
            case Object::MauveSpell:

                this->frame++;
                this->frame = this->frame % 4;
                updatePosition();

                break;

            case Object::SpiderWeb:

                this->lifeCountdown--;

                switch (this->lifeCountdown) {

                    case BULLET_WEB_FRAMES - 1:
                        this->frame = 0;
                        updatePosition();
                        break;

                    case BULLET_WEB_FRAMES_DIV1 + 1 ... BULLET_WEB_FRAMES - 2:
                        updatePosition();
                        break;

                    case BULLET_WEB_FRAMES_DIV1:
                        this->frame = 1;
                        updatePosition();
                        break;

                    case BULLET_WEB_FRAMES_DIV2 + 1 ... BULLET_WEB_FRAMES_DIV1 - 1:
                        updatePosition();
                        break;

                    case BULLET_WEB_FRAMES_DIV2:
                        this->frame = 2;
                        updatePosition();
                        break;

                    case BULLET_WEB_FRAMES_DIV3 + 1 ... BULLET_WEB_FRAMES_DIV2 - 1:
                        updatePosition();
                        break;

                    case BULLET_WEB_FRAMES_DIV3:
                        this->frame = 3;
                        updatePosition();
                        break;

                    case BULLET_WEB_FRAMES_DIV4 + 1 ... BULLET_WEB_FRAMES_DIV3 - 1:
                        updatePosition();
                        break;

                    case BULLET_WEB_FRAMES_DIV4:
                        this->frame = 4;
                        updatePosition();
                        break;

                    case BULLET_WEB_FRAMES_DIV5 + 1 ... BULLET_WEB_FRAMES_DIV4 - 1:
                        updatePosition();
                        break;

                    case BULLET_WEB_FRAMES_DIV5:
                        this->frame = 5;
                        updatePosition();
                        break;

                    case 1 ... BULLET_WEB_FRAMES_DIV5 - 1:
                        updatePosition();
                        break;

                    case 0:
                        this->setActive(false);
                        break;

                }

                break;
    
        }

    }

}

void Bullet::updatePosition() {

    int16_t rx = this->getX();
    int16_t ry = this->getY();

    switch (this->getDirection()) {

        case Direction::Up: 
            ry-=3; 
            break;

        case Direction::UpRight: 
            ry-=3; 
            rx+=3; 
            break;

        case Direction::Right: 
            rx+=3; 
            break;

        case Direction::DownRight: 
            ry+=3; 
            rx+=3; 
            break;

        case Direction::Down: 
            ry+=3; 
            break;

        case Direction::DownLeft: 
            ry+=3; 
            rx-=3; 
            break;

        case Direction::Left: 
            rx-=3; 
            break;

        case Direction::UpLeft: 
            ry-=3; 
            rx-=3; 
            break;
    
    };

    this->setX(rx);
    this->setY(ry);

}
