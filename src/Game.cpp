#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


void Game::setup(/*GameCookie *cookie*/) { 
    
//    this->cookie = cookie;
    map.level = 0;
    
}

void Game::loop(void) {
    
    PC::buttons.pollButtons();
    PD::clear();

    switch(gameState) {


        case GameState::MainMenu: 
            updateMainMenu(); 
            break;

        case GameState::Game: 
            updateGame(); 
            break;

        case GameState::LoadMap: 
            nextLevelLoad(); 
            break;

        case GameState::mapEnding: 
            mapEnding(); 
            break;

        case GameState::Dead: 
            death(); 
            break;

        case GameState::WinState:  
            win(); 
            break;

    }
	
}


void Game::drawHealth() {

    PD::setColor(0);
    PD::fillRect(0, 81, 63, 6);
    PD::drawBitmap(1, 82, Images::Health);
    PD::setColor(8);
    PD::drawRect(7, 82, 54, 4);
    PD::drawLine(9, 84, 9 + player.getHealth() / 2, 84);

}


void Game::drawHolding() {

    PD::setColor(6);
    PD::drawBitmap(82, 69, Images::Keys_Main);
    PD::drawBitmap(82, 79, Images::Coins_Main);
    PD::setCursor(94, 70);
    if (player.getKeys() < 10) PD::print("0");
    PD::print(player.getKeys(), 10);
    PD::setCursor(94, 80);
    if (player.getCoins() < 10) PD::print("0");
    PD::print(player.getCoins(), 10);
    PD::drawBitmap(82, 69, Images::Keys_Outline);
    PD::drawBitmap(82, 79, Images::Coins_Outline);

}

void Game::drawTime() {

    PD::drawBitmap(74, 0,Images::Time_Main);
    PD::setColor(6);
    PD::setCursor(87,1);

    if (this->timer < 100)    PD::print("0");
    if (this->timer < 10)     PD::print("0");

    PD::print(this->timer, 10);
    PD::drawBitmap(74, 0, Images::Time_Outline);

}

void Game::drawHud() {

    this->drawHealth();
    this->drawHolding();
    this->drawTime();

    PD::setColor(0);
    PD::drawBitmap(0, 0, Images::Level_Main);
 
    PD::setColor(7);
    PD::setCursor(3,1);
    PD::print("L");
    PD::setCursor(10,1);

    if (map.level < 10) {
      PD::print("0");
    }

    PD::print(map.level, 10);
    PD::drawBitmap(0, 0, Images::Level_Outline);

}

void Game::renderEnviroment() {

    int tileX = getTileX(player.getX());
    int tileY = getTileY(player.getY());
    int offsetX = getTileXOffset(player.getX());
    int offsetY = getTileYOffset(player.getY());

    for (int i = -8; i < 8; i++) {
    
        for(int j = -8; j < 8; j++) {
            
            uint8_t block = getBlock(map, tileX + i, tileY + j);

            int drawX = (i * 16) + CENTERX - offsetX;
            int drawY = (j * 16) + CENTERY - offsetY;
            PD::drawBitmap(drawX, drawY, Images::Tiles[block]);

        }

    }

}

void Game::renderPlayer() {	

    const uint8_t PlayerFrames[] = { 0, 1, 0, 2 };
    
    if(!player.getMoving()) {
        PD::drawBitmap(CENTERX - 4, CENTERY - 4, Images::Sprites[0]);
    }
    else {

        if(Pokitto::Core::frameCount % 5 == 0) {
            player.incFrame();
        }

        PD::drawBitmap(CENTERX - 4, CENTERY - 4, Images::Sprites[PlayerFrames[player.getFrame()]]);

    }

}