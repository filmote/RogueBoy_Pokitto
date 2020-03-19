#pragma once

#include "Pokitto.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


class Sprite {

    public:

        Sprite() {};

        uint16_t getX()                 { return this->x; }
        uint16_t getY()                 { return this->y; }
        uint8_t getOffset()             { return this->offset; }
        uint8_t getFrame()              { return this->frame; }
        uint8_t getType()               { return this->type; }
        int16_t getHealth()             { return this->health; }
        bool getActive()                { return this->active; }

        void setActive(bool k)          { this->active = k; }
        void setX(uint16_t x)           { this->x = x; }
        void setY(uint16_t y)           { this->y = y; }
        void setFrame(uint8_t frame)    { this->frame = frame;}

        void setSprite(uint16_t x, uint16_t y, uint8_t health, uint8_t type, uint8_t offset, bool active) {

            this->x = x;
            this->y = y;
            this->health = health;
            this->type = type;
            this->frame = 0;
            this->offset = offset;
            this->active = active;
            
        };

        void damage() {
    
            this->health -= 10;
    
            if (this->health <= 0) {
                this->active = false; 
                //sound.tone(NOTE_E5,50);
            }
    
        };

    private:

        uint8_t offset;
        uint16_t x;
        uint16_t y;
        int16_t health;
        uint8_t type;
        uint8_t frame;
        bool active;

};


