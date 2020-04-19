#pragma once

#include "Pokitto.h"
#include "../utils/Enums.h"
#include "Sprites_Consts.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


class Sprite {

    public:

        Sprite() {};

        uint16_t getX()                         { return this->x; }
        uint16_t getY()                         { return this->y; }
        uint8_t getWidth()                      { return this->width; }
        uint8_t getHeight()                     { return this->height; }
        int8_t getXOffset()                     { return this->xOffset; }
        int8_t getYOffset()                     { return this->yOffset; }
        uint8_t getFrame()                      { return this->frame; }
        uint8_t getQuantity()                   { return this->quantity; }
        uint8_t getPuffIndex()                  { return this->puffIndex; }
        Object getType()                        { return this->type; }
        Object getCarrying()                    { return this->carrying; }
        int16_t getHealth()                     { return this->health; }
        int16_t getHealthOrig()                 { return this->healthOrig; }
        bool getActive()                        { return this->active; }
        bool getRenderHealthBar()               { return this->renderHealthBar > 0; }
        uint8_t getCountdown()                  { return this->countdown; }

        void setActive(bool k)                  { this->active = k; }
        void setFrame(uint8_t frame)            { this->frame = frame;}
        void setQuantity(uint8_t quantity)      { this->quantity = quantity;}
        void setX(uint16_t x)                   { this->x = x; }
        void setY(uint16_t y)                   { this->y = y; }
        void setType(Object type)               { this->type = type; }
        void setCarrying(Object carrying)       { this->carrying = carrying; }
        void setCountdown(uint8_t countdown)    { this->countdown = countdown; }

        void decCountdown()                     { this->countdown--; }

        Rect getRect() {

            switch (this->type) {

                case Object::SpikeLHS:
                    return Rect { this->getX() - (this->getWidth() / 2),  this->getY() - (this->getHeight() / 2), spike_frameIdx[frame] * 2, this->getHeight() };

                case Object::SpikeRHS:
                    return Rect { this->getX() - (this->getWidth() / 2) + this->getWidth() - (spike_frameIdx[frame] * 2), this->getY() - (this->getHeight() / 2), spike_frameIdx[frame] * 2, this->getHeight() };

                case Object::FireTOP:

                    if (frame == 0) {

                        return Rect { this->getX() - (this->getWidth() / 2),  this->getY() - (this->getHeight() / 2), 2 };

                    }
                    else {

                        return Rect { this->getX() - (this->getWidth() / 2),  this->getY() - (this->getHeight() / 2), this->getWidth(), this->getHeight() };

                    }

                case Object::FireBOT:
                
                    if (frame == 0) {

                        return Rect { this->getX() - (this->getWidth() / 2),  this->getY() + (this->getHeight() / 2) - 2, this->getWidth(), 2 };

                    }
                    else {

                        return Rect { this->getX() - (this->getWidth() / 2),  this->getY() - (this->getHeight() / 2), this->getWidth(), this->getHeight() };

                    }
 
                default:
                    return Rect { this->getX() - (this->getWidth() / 2),  this->getY() - (this->getHeight() / 2), this->getWidth(), this->getHeight() };

            }

        }

        void update() { 
            
            if (this->renderHealthBar > 0) this->renderHealthBar--; 
            if (this->puffIndex > 0) this->puffIndex--; 
            
        }

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

        void setSprite(uint16_t x, uint16_t y, uint8_t health, Object type, bool active, bool enablePuff) {

            this->x = x;
            this->y = y;
            this->width = spriteWidths[static_cast<uint8_t>(type)];
            this->height = spriteHeights[static_cast<uint8_t>(type)];
            this->health = health;
            this->healthOrig = health;
            this->type = type;
            this->frame = 0;
            this->xOffset = spriteOffsets[static_cast<uint8_t>(type) * 2];
            this->yOffset = spriteOffsets[(static_cast<uint8_t>(type) * 2) + 1];
            this->active = active;
            this->carrying = Object::None;
            this->puffIndex = (enablePuff ? 10 : 0);

        };


        void damage(Object weapon) {

            switch (weapon) {

                case Object::FireBall:
                    this->health -= DAMAGE_FIREBALL;
                    break;

                case Object::IceSpell:
                    this->health -= DAMAGE_ICESPELL;
                    break;

                case Object::GreenSpell:
                    this->health -= DAMAGE_GREENSPELL;
                    break;

                case Object::RedSpell:
                    this->health -= DAMAGE_REDSPELL;
                    break;

                case Object::MauveSpell:
                    this->health = 0;
                    break;

            }
    
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
                case Object::NewEnemy:
                case Object::Snake:

                    return true;

                default:
                    return false;
                
            }
            
        }

    private:

        int8_t xOffset;
        int8_t yOffset;
        uint16_t x;
        uint16_t y;
        uint8_t width;
        uint8_t height;
        int16_t health;
        int16_t healthOrig;
        Object type;
        Object carrying = Object::None;
        uint8_t frame;
        uint8_t countdown = 50;
        bool active;
        uint8_t quantity;

        int8_t lastMoveX;
        int8_t lastMoveY;
        bool preventImmediatePickup;
        uint8_t renderHealthBar;
        uint8_t puffIndex = 0;

};


