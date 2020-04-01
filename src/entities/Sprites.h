#pragma once

#include "Pokitto.h"
#include "Sprite.h"
#include "Player.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

class Sprites {

    public:

        Sprites() {};  

        Sprite & getSprite(uint8_t index);
        uint8_t getFirstInactiveSpriteIndex(Object type);
        uint8_t getObjectNum();

        void setObjectNum(uint8_t oNum);

        void update();
        void render(Player &player);
        void clearPreventImmediatePickup(Player &player);
        void renderHealthBar(uint32_t x, uint32_t y, uint8_t health);

    private:

        Sprite objects[MAXOBJECT];
        uint8_t oNum = 0;

};


