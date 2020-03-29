#pragma once

#include "Pokitto.h"
#include "Bullet.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


bool Bullet::getActive()                { return active;}
uint16_t Bullet::getX()                 { return x;}
uint16_t Bullet::getY()                 { return y;}
uint8_t Bullet::getFrame()              { return frame;}
Direction Bullet::getDirection()        { return direction;}

void Bullet::setX(uint16_t x)           { this->x = x;}
void Bullet::setY(uint16_t y)           { this->y = y;}
void Bullet::setActive(bool active)     { this->active = active;}

void Bullet::kill()                     { this->active = false;}

void Bullet::setBullet(uint16_t x, uint16_t y, Direction direction) { this->x = x; this->y = y; this->direction = direction; this->active = true;}

void Bullet::update() {

    this->frame++;
    this->frame = this->frame % 4;

        if (this->getActive()) {

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

}

