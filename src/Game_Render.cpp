#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


void Game::renderObjects() {

    objects.render(player);
    bullets.render(player);

}

void Game::drawHealth() {
    
    #ifndef MAP_LARGE
    
        PD::setColor(0);
        PD::fillRect(0, 81, 63, 6);
        PD::drawBitmap(1, 82, Images::Health);
        PD::setColor(8);
        PD::drawRect(7, 82, 54, 4);
        PD::drawLine(9, 84, 9 + player.getHealth() / 2, 84);
        
    #else
    
        PD::setColor(0);
        PD::fillRect(0, 169, 63, 6);
        PD::drawBitmap(1, 170, Images::Health);
        PD::setColor(8);
        PD::drawRect(7, 170, 54, 4);
        PD::drawLine(9, 172, 9 + player.getHealth() / 2, 172);
    
    #endif

}


void Game::drawHolding() {
    
    #ifndef MAP_LARGE
    
        PD::setColor(6);
        PD::drawBitmap(82, 69, Images::Keys_Main);
        PD::drawBitmap(82, 79, Images::Coins_Main);
        PD::setCursor(94, 70);
        if (player.getInventoryCount(Object::Key) < 10)  PD::print("0");
        PD::print(player.getInventoryCount(Object::Key), 10);
        PD::setCursor(94, 80);
        if (player.getCoins() < 10) PD::print("0");
        PD::print(player.getCoins(), 10);
        PD::drawBitmap(82, 69, Images::Keys_Outline);
        PD::drawBitmap(82, 79, Images::Coins_Outline);
        
    #else
    
        PD::setColor(6);
        PD::drawBitmap(192, 157, Images::Keys_Main);
        PD::drawBitmap(192, 167, Images::Coins_Main);
        PD::setCursor(204, 158);
        if (player.getInventoryCount(Object::Key) < 10)  PD::print("0");
        PD::print(player.getInventoryCount(Object::Key), 10);
        PD::setCursor(204, 168);
        if (player.getCoins() < 10) PD::print("0");
        PD::print(player.getCoins(), 10);
        PD::drawBitmap(192, 157, Images::Keys_Outline);
        PD::drawBitmap(192, 167, Images::Coins_Outline);
    
    #endif

}

void Game::drawTime() {
    
    #ifndef MAP_LARGE

        PD::drawBitmap(74, 0,Images::Time_Main);
        PD::setColor(6);
        PD::setCursor(87,1);
    
        if (this->map.getTimer() < 100)    PD::print("0");
        if (this->map.getTimer() < 10)     PD::print("0");
    
        PD::print(map.getTimer(), 10);
        PD::drawBitmap(74, 0, Images::Time_Outline);
        
    #else

        PD::drawBitmap(184, 0,Images::Time_Main);
        PD::setColor(6);
        PD::setCursor(197,1);
    
        if (map.getTimer() < 100)    PD::print("0");
        if (map.getTimer() < 10)     PD::print("0");
    
        PD::print(this->map.getTimer(), 10);
        PD::drawBitmap(184, 0, Images::Time_Outline);
    
    #endif

}

void Game::drawLevel() {

    PD::setColor(0);
    PD::drawBitmap(0, 0, Images::Level_Main);
 
    PD::setColor(7);
    PD::setCursor(3,1);
    PD::print("L");
    PD::setCursor(10,1);

    if (map.getLevel() < 10) {
      PD::print("0");
    }

    PD::print(map.getLevel(), 10);
    PD::drawBitmap(0, 0, Images::Level_Outline);

}


void Game::drawHud() {
    
    this->drawHealth();
    this->drawHolding();
    this->drawTime();
    this->drawLevel();

}

void Game::renderEnviroment() {

    int tileX = this->map.getTileX(player.getX());
    int tileY = this->map.getTileY(player.getY());
    int offsetX = this->map.getTileXOffset(player.getX());
    int offsetY = this->map.getTileYOffset(player.getY());

    for (int i = -8; i < 7; i++) {
    
        for(int j = -8; j < 7; j++) {
            
            uint8_t block = this->map.getBlock(tileX + i, tileY + j);

            int drawX = (i * 16) + CENTERX - offsetX;
            int drawY = (j * 16) + CENTERY - offsetY;
            PD::drawBitmap(drawX, drawY, Images::Tiles[block]);

        }

    }

}

void Game::renderPlayer() {	
    
    if(!player.getMoving()) {
        PD::drawBitmap(CENTERX - 6, CENTERY - 6, Images::Players[0]);
    }
    else {

        if(Pokitto::Core::frameCount % 5 == 0) {
            player.incFrame();
        }

        PD::drawBitmap(CENTERX - 6, CENTERY - 6, Images::Players[player.getFrame()]);

    }

}