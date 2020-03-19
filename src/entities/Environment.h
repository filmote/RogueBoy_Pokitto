#pragma once

#include "Pokitto.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

class Environment{

    public:

        Environment() {}

        uint8_t finishX()   { return this->x1; }
        uint8_t finishY()   { return this->y1; }
        uint8_t getX()      { return this->x; }
        uint8_t getY()      { return this->y; }
        bool getActive()    { return this->active; }

        bool checkStart(uint8_t x, uint8_t y) { return (this->x == x && this->y == y); }

        void setEnv(uint8_t x, uint8_t y, uint8_t x1, uint8_t y1, bool active) {
            this->x = x; 
            this->y = y; 
            this->x1 = x1; 
            this->y1 = y1; 
            this->active = active;
        }

    private:

        uint8_t x;
        uint8_t y;
        uint8_t x1;
        uint8_t y1;
        bool active;
  
};