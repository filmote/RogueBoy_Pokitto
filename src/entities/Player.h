#pragma once

#include "Pokitto.h"
#include "../utils/Enums.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


class Player {

    public:

        uint16_t getX()                             { return this->x; }
        uint16_t getY()                             { return this->y; }
        Direction getDirection()                    { return this->direction; }
        int8_t getHealth()                          { return this->health; }
        uint8_t getCoins()                          { return this->coins; }
        uint8_t getKills()                          { return this->kills; }
        uint8_t getKeys()                           { return this->keys; }
        uint8_t getFrame()                          { return this->frame; }
        bool getMoving()                            { return this->moving; }

        void setX(uint16_t x)                       { this->x = x; }
        void setY(uint16_t y)                       { this->y = y; }
        void setDirection(Direction direction)      { this->direction = direction; }
        void setHealth(int8_t health)               { this->health = health; if (this->health > 100) this->health = 100; }
        void setCoins(uint8_t coins)                { this->coins = coins; }
        void setKills(uint8_t kills)                { this->kills = kills; }
        void setKeys(uint8_t keys)                  { this->keys = keys; }
        void setFrame(uint8_t frame)                { this->frame = frame;}
        void setMoving(bool moving)                 { this->moving = moving; }

        void incFrame() {
            this->frame++;
            this->frame %= 4;
        }

        void init(uint16_t x, uint16_t y) {
            this->x = x;
            this->y = y;
            this->direction = Direction::Up;
            this->coins = 0;
            this->keys = 0;
            this->kills = 0;
            this->health = 100;
            this->moving = false;
        }

    private:

        uint16_t x;
        uint16_t y;
        Direction direction;
        int8_t health;
        uint8_t keys;
        uint8_t coins;
        uint8_t kills;
        bool moving;
        uint8_t frame;
};
