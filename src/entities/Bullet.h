#pragma once

#include "Pokitto.h"
#include "../utils/Enums.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

class Bullet {

    public:

        Bullet() {}  

        bool getActive();
        uint16_t getX();
        uint16_t getY();
        uint8_t getFrame();
        Weapon getWeapon();
        Direction getDirection();

        void setX(uint16_t x);
        void setY(uint16_t y);
        void setActive(bool active);
        void setWeapon(Weapon weapon);

        void setBullet(uint16_t x, uint16_t y, Direction direction, Weapon weapon);

        void update();
        void kill();

    private:

        uint16_t x;
        uint16_t y;
        Direction direction;
        bool active;
        uint8_t frame;
        Weapon weapon;

};
