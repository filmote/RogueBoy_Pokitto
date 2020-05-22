#include "Sprite.h"
#include "../sounds/Sounds.h"

uint16_t Sprite::getX()                             { return this->x; }
uint16_t Sprite::getY()                             { return this->y; }
uint8_t Sprite::getWidth()                          { return this->width; }
uint8_t Sprite::getHeight()                         { return this->height; }
int8_t Sprite::getXOffset()                         { return this->xOffset; }
int8_t Sprite::getYOffset()                         { return this->yOffset; }
int8_t Sprite::getFrame()                           { return this->frame; }
uint8_t Sprite::getQuantity()                       { return this->quantity; }
uint8_t Sprite::getPuffIndex()                      { return this->puffIndex; }
Object Sprite::getType()                            { return this->type; }
Object Sprite::getCarrying()                        { return this->carrying; }
int16_t Sprite::getHealth()                         { return this->health; }
int16_t Sprite::getHealthOrig()                     { return this->healthOrig; }
uint8_t Sprite::getCountdown()                      { return this->countdown; }
bool Sprite::getGuideText()                         { return this->guideText; }
bool Sprite::getActive()                            { return this->active; }
bool Sprite::getRenderHealthBar()                   { return this->renderHealthBar > 0; }
bool Sprite::getPreventImmediatePickup()            { return this->preventImmediatePickup; }

void Sprite::setActive(bool k)                      { this->active = k; }
void Sprite::setFrame(int8_t frame)                 { this->frame = frame;}
void Sprite::setQuantity(uint8_t quantity)          { this->quantity = quantity;}
void Sprite::setX(uint16_t x)                       { this->x = x; }
void Sprite::setY(uint16_t y)                       { this->y = y; }
void Sprite::setType(Object type)                   { this->type = type; }
void Sprite::setCarrying(Object carrying)           { this->carrying = carrying; }
void Sprite::setCountdown(uint8_t countdown)        { this->countdown = countdown; }
void Sprite::setPreventImmediatePickup(bool value)  { this->preventImmediatePickup = value; }
void Sprite::setGuideText(bool value)               { this->guideText = value; }

void Sprite::decCountdown() { 

    if (this->countdown > 0) this->countdown--; 

}

void Sprite::incFrame() { 

    this->frame++; 

}

Rect Sprite::getRect() {

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

void Sprite::update() { 
    
    if (this->renderHealthBar > 0) this->renderHealthBar--; 
    if (this->puffIndex > 0) this->puffIndex--; 
    
}

void Sprite::setPosition(uint16_t x, uint16_t y) {

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

void Sprite::setSprite(uint16_t x, uint16_t y, uint8_t health, Object type, bool active, bool enablePuff) {

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
    this->renderHealthBar = 0;
    this->countdown = 0;
    this->quantity = 0;
    this->lastMoveX = 0;
    this->lastMoveY = 0;
    this->preventImmediatePickup = 0;
    this->guideText = true;

};


void Sprite::decHealth(Object weapon) {

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
        Audio::play<1>(Sounds::sfx_Death3);
    }

    this->renderHealthBar = HEALTH_BAR_DELAY;

};

Direction Sprite::getDirection() {

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

bool Sprite::isEnemy() {
    
    switch (this->type) {

        case Object::Bat:
        case Object::Floater:
        case Object::Eye:
        case Object::Spider:
        case Object::BigSpider:
        case Object::Skeleton:
        case Object::Snake:
        case Object::Chest:
        case Object::Necromancer:
        case Object::Hobgoblin:
        case Object::Cyclop:
        case Object::Bull:
        case Object::Beholder:
        case Object::Boss04 ... Object::Boss05:
            return true;

        default:
            return false;
        
    }
    
}

bool Sprite::isSolidSprite() {
    
    switch (this->type) {

        case Object::Guide01 ... Object::Guide15:
            return true;

        default:
            return false;
        
    }
    
}

bool Sprite::isCarryable() {
    
    switch (this->type) {

        case Object::Coin:
        case Object::SackOCash:
        case Object::Bread:
        case Object::Key:
        case Object::Chicken:
        case Object::Tools:
        case Object::Tonic:
        case Object::IceSpell:
        case Object::GreenSpell:
        case Object::RedSpell:
        case Object::MauveSpell:
            return true;

        default:
            return false;
        
    }
    
}


// Get direction is calculated based on last lastMoveX, lastMoveY ..

void Sprite::setDirection(Direction direction) {

    const int8_t lastMovesX[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    const int8_t lastMovesY[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

    this->lastMoveX = lastMovesX[static_cast<uint8_t>(direction)]; 
    this->lastMoveY = lastMovesY[static_cast<uint8_t>(direction)];  

}
