#pragma once

#include "Pokitto.h"
#include "../utils/Enums.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

class Bullet {

    public:

        Bullet() {}  

        bool getActive()                { return active;}
        uint16_t getX()                 { return x;}
        uint16_t getY()                 { return y;}
        Direction getDirection()          { return direction;}

        void setX(uint16_t x)           { this->x = x;}
        void setY(uint16_t y)           { this->y = y;}
        void setActive(bool active)     { this->active = active;}

        void kill()                     { this->active = false;}

        void setBullet(uint16_t x, uint16_t y, Direction direction) { this->x = x; this->y = y; this->direction = direction; this->active = true;}

    private:

        uint16_t x;
        uint16_t y;
        Direction direction;
        bool active;

};
