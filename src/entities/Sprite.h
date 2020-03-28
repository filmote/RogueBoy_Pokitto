#pragma once

#include "Pokitto.h"
#include "../utils/Enums.h"

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
        Object getType()                { return this->type; }
        int16_t getHealth()             { return this->health; }
        bool getActive()                { return this->active; }

        void setActive(bool k)          { this->active = k; }
        void setFrame(uint8_t frame)    { this->frame = frame;}
        void setX(uint16_t x)           { this->x = x; }
        void setY(uint16_t y)           { this->y = y; }

        void setPosition(uint16_t x, uint16_t y) {

            if (this->x != x && this->y != y) { // Moving diagonally.
                
                this->lastMoveX = x - this->x; 
                this->lastMoveY = y - this->y;    

            }
            else if (this->x == x && this->y != y) { // Moving vertically. 

                this->lastMoveX = 0; 
                this->lastMoveY = y - this->y;    

            }
            else if (this->x != x && this->y == y) { // Moving horizontally. 

                this->lastMoveX = x - this->x; 
                this->lastMoveY = 0;    

            }

            this->x = x; 
            this->y = y; 

        }

        void setSprite(uint16_t x, uint16_t y, uint8_t health, Object type, uint8_t offset, bool active) {

            this->x = x;
            this->y = y;
            this->health = health;
            this->type = type;
            this->frame = 0;
            this->offset = offset;
            this->active = active;
            
        };

        void damage() {
   printf("health : %i\n", health); 
            this->health -= 10;
    
            if (this->health <= 0) {
                this->active = false; 
                //sound.tone(NOTE_E5,50);
            }
    
        };

        Direction getDirection() {

            switch (this->lastMoveX) {

                case -1:

                    switch (this->lastMoveY) {

                        case -1:    return Direction::UpLeft;
                        case  0:    return Direction::Left;
                        case  1:    return Direction::DownLeft;
                    }
                    
                    return Direction::Up;

                case 0:

                    switch (this->lastMoveY) {

                        case -1:    return Direction::Up;
                        case  0:    return Direction::Up;
                        case  1:    return Direction::Down;

                    }
                    
                    return Direction::Up;

                case 1:

                    switch (this->lastMoveY) {

                        case -1:    return Direction::UpRight;
                        case  0:    return Direction::Right;
                        case  1:    return Direction::DownRight;

                    }
                    
                    return Direction::Up;

            }

            return Direction::Up;

        };

        void setPreventImmediatePickup(bool value) {

             this->preventImmediatePickup = value;

        }

        bool getPreventImmediatePickup() {

            return this->preventImmediatePickup;
        }


        bool isEnemy() {
            
            switch (this->type) {

                case Object::Bat:
                case Object::Floater:
                case Object::Skull:
                case Object::Spider:

                    return true;

                default:
                    return false;
                
            }
            
        }

    private:

        uint8_t offset;
        uint16_t x;
        uint16_t y;
        int16_t health;
        Object type;
        uint8_t frame;
        bool active;

        int8_t lastMoveX;
        int8_t lastMoveY;
        bool preventImmediatePickup;

};


