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

        uint16_t getX();
        uint16_t getY();
        uint8_t getWidth();
        uint8_t getHeight();
        int8_t getXOffset();
        int8_t getYOffset();
        uint8_t getFrame();
        uint8_t getQuantity();
        uint8_t getPuffIndex();
        Object getType();
        Object getCarrying();
        int16_t getHealth();
        int16_t getHealthOrig();
        bool getActive();
        bool getRenderHealthBar();
        uint8_t getCountdown();
        bool getPreventImmediatePickup();

        void setActive(bool k);
        void setFrame(uint8_t frame);
        void setQuantity(uint8_t quantity);
        void setX(uint16_t x);
        void setY(uint16_t y);
        void setType(Object type);
        void setCarrying(Object carrying);
        void setCountdown(uint8_t countdown);
        void setPreventImmediatePickup(bool value);
        void setDirection(Direction direction);

        void decCountdown();
        Rect getRect();
        void update();
        void setPosition(uint16_t x, uint16_t y);
        void setSprite(uint16_t x, uint16_t y, uint8_t health, Object type, bool active, bool enablePuff);
        void damage(Object weapon);
        Direction getDirection();
        bool isEnemy();

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


