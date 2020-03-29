#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


void Game::renderObjects() {

    objects.render(player);
    bullets.render(player);

}

// void Game::drawHealth() {

//     PD::setColor(0);
//     PD::fillRect(0, 81, 63, 6);
//     PD::drawBitmap(1, 82, Images::Health);
//     PD::setColor(8);
//     PD::drawRect(7, 82, 54, 4);
//     PD::drawLine(9, 84, 9 + player.getHealth() / 2, 84);

// }


// void Game::drawHolding() {

//     PD::setColor(6);
//     PD::drawBitmap(82, 69, Images::Keys_Main);
//     PD::drawBitmap(82, 79, Images::Coins_Main);
//     PD::setCursor(94, 70);
//     if (player.getInventoryCount(Object::Key) < 10)  PD::print("0");
//     PD::print(player.getInventoryCount(Object::Key), 10);
//     PD::setCursor(94, 80);
//     if (player.getCoins() < 10) PD::print("0");
//     PD::print(player.getCoins(), 10);
//     PD::drawBitmap(82, 69, Images::Keys_Outline);
//     PD::drawBitmap(82, 79, Images::Coins_Outline);

// }

// void Game::drawTime() {

//     PD::drawBitmap(74, 0,Images::Time_Main);
//     PD::setColor(6);
//     PD::setCursor(87,1);

//     if (this->map.getTimer() < 100)    PD::print("0");
//     if (this->map.getTimer() < 10)     PD::print("0");

//     PD::print(map.getTimer(), 10);
//     PD::drawBitmap(74, 0, Images::Time_Outline);

// }

// void Game::drawLevel() {

//     PD::setColor(0);
//     PD::drawBitmap(0, 0, Images::Level_Main);
 
//     PD::setColor(7);
//     PD::setCursor(3,1);
//     PD::print("L");
//     PD::setCursor(10,1);

//     if (map.getLevel() < 10) {
//       PD::print("0");
//     }

//     PD::print(map.getLevel(), 10);
//     PD::drawBitmap(0, 0, Images::Level_Outline);

// }


void Game::renderHud() {
    
    // this->drawHealth();
    // this->drawHolding();
    // this->drawTime();
    // this->drawLevel();

    PD::drawBitmap(0, 72, Images::Scoreboard);
    
    
    // Render current level ..

    PD::setColor(6, 14);
    PD::setCursor(10, 74);
    
    if (map.getLevel() < 10) {
      PD::print("0");
    }

    PD::print(map.getLevel(), 10);


    // Time ..

    PD::setCursor(39, 74);

    if (this->map.getTimer() < 100)    PD::print("0");
    if (this->map.getTimer() < 10)     PD::print("0");

    PD::print(map.getTimer(), 10);


    // Holdings ..

    PD::setCursor(74, 74);
    if (player.getInventoryCount(Object::Key) < 10)  PD::print("0");
    PD::print(player.getInventoryCount(Object::Key), 10);
    PD::setCursor(74, 80);
    if (player.getCoins() < 10) PD::print("0");
    PD::print(player.getCoins(), 10);


    // Health ..

    PD::setColor(8);
    PD::drawLine(8, 85, 8 + player.getHealth() / 2 + (player.getHealth() > 50 ? 1 : 0), 85);


    PD::setColor(6, 0);

}

void Game::renderEnviroment() {

    int tileX = this->map.getTileX(player.getX());
    int tileY = this->map.getTileY(player.getY());
    int offsetX = this->map.getTileXOffset(player.getX());
    int offsetY = this->map.getTileYOffset(player.getY());

    for (int i = -8; i < 7; i++) {
    
        for(int j = -4; j < 4; j++) {
            
            uint8_t block = this->map.getBlock(tileX + i, tileY + j);

            int drawX = (i * 16) + CENTERX - offsetX;
            int drawY = (j * 16) + CENTERY - offsetY;
            PD::drawBitmap(drawX, drawY, Images::Tiles[block]);

        }

    }

}

void Game::renderPlayer() {	
    
    if(!player.getMoving()) {
//        PD::drawBitmap(CENTERX - 6, CENTERY - 6, Images::Players[0]);
        PD::drawBitmap(CENTERX - 6, CENTERY - 6, Images::Players[static_cast<uint8_t>(player.getDirection()) * 2 + player.getFrame()]);

    }
    else {

        if(Pokitto::Core::frameCount % 5 == 0) {
            player.incFrame();
        }

        PD::drawBitmap(CENTERX - 6, CENTERY - 6, Images::Players[static_cast<uint8_t>(player.getDirection()) * 2 + player.getFrame()]);

    }

}