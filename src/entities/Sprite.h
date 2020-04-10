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
        uint8_t getWidth()              { return this->width; }
        uint8_t getHeight()             { return this->height; }
        int8_t getOffset()              { return this->offset; }
        uint8_t getFrame()              { return this->frame; }
        Object getType()                { return this->type; }
        int16_t getHealth()             { return this->health; }
        int16_t getHealthOrig()         { return this->healthOrig; }
        bool getActive()                { return this->active; }
        bool getRenderHealthBar()       { return this->renderHealthBar > 0; }

        void setActive(bool k)          { this->active = k; }
        void setFrame(uint8_t frame)    { this->frame = frame;}
        void setX(uint16_t x)           { this->x = x; }
        void setY(uint16_t y)           { this->y = y; }
        void setType(Object type)       { this->type = type; }

        void decHealthBarCounter()      { if (this->renderHealthBar > 0) this->renderHealthBar--; }

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

        void setSprite(uint16_t x, uint16_t y, uint8_t health, Object type, int8_t offset, bool active) {

            this->x = x;
            this->y = y;
            this->width = this->widths[static_cast<uint8_t>(type)];
            this->height = this->heights[static_cast<uint8_t>(type)];;
            this->health = health;
            this->healthOrig = health;
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

            this->renderHealthBar = HEALTH_BAR_DELAY;
    
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
                case Object::BigSpider:

                    return true;

                default:
                    return false;
                
            }
            
        }

    private:

        int8_t offset;
        uint16_t x;
        uint16_t y;
        uint16_t width;
        uint16_t height;
        int16_t health;
        int16_t healthOrig;
        Object type;
        uint8_t frame;
        bool active;

        int8_t lastMoveX;
        int8_t lastMoveY;
        bool preventImmediatePickup;
        uint8_t renderHealthBar;

        const uint8_t widths[13] =  { 
            8,  /* Coin */
            8,  /* SackOfCash */
            8,  /* Bread */
            8,  /* Key */
            8,  /* Chicken */
            8,  /* Floater */
            10, /* Skull */
            8,  /* Spider */
            8,  /* Bat */
            12, /* Spanner */
            8,  /* Potion */
            16, /* BigSpider */
            13, /* IceSpell */
        };

        const uint8_t heights[13] = { 
            8,  /* Coin */
            8,  /* SackOfCash */
            8,  /* Bread */
            8,  /* Key */
            8,  /* Chicken */
            8,  /* Floater */  
            9,  /* Skull */
            8,  /* Spider */
            8,  /* Bat */
            12, /* Spanner */
            8,  /* Potion */
            16, /* BigSpider */
            11, /* IceSpell */
        };
};


