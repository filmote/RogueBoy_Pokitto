
#pragma once

#include "Pokitto.h"
#include "Bullet.h"
#include "Player.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

class Bullets {

    public:

        Bullets() {}  

        Bullet & getBullet(uint8_t index);
        void render(Player &player);


    private:

        Bullet bullets[6];

};
