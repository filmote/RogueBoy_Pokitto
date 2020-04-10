#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

void Game::death() {

    PD::setCursor(0,0);
    PD::print("Scored: ");
    PD::print(this->points, 10);
    PD::print("\nGot To Level: ");
    PD::print(map.getLevel(), 10);

    if (PC::buttons.pressed(BTN_A) || PC::buttons.pressed(BTN_B)) {
        //sound.noTone(); 
        gameState = GameState::MainMenu; 
        map.setLevel(0); 
        this->points = 0; 
    }

}

void Game::win() {
    
    PD::setCursor(0,0);
    PD::print("WellDone!\n");
    PD::print("You Scored: ");
    PD::print(this->points, 10);

    if (PC::buttons.pressed(BTN_A) || PC::buttons.pressed(BTN_B)) { 
        //sound.noTone(); 
        gameState = GameState::MainMenu; 
        map.setLevel(0); 
        this->points = 0;
    }

}



void Game::endOfLevel() {

    int32_t padd = player.getCoins() * 5;    
    int32_t killp = player.getKills() * 10;
    int32_t pts = padd + killp + (this->map.getTimer()/10);

    this->renderEnviroment();
    this->renderHud();

    PD::setColor(15);
    PD::fillRectangle(10, 10, 90, 52);
    PD::drawBitmap(0, 0, Images::LevelSplash_Left);
    PD::drawBitmap(10, 0, Images::LevelSplash_Top);
    PD::drawBitmap(100, 0, Images::LevelSplash_Right);
    PD::drawBitmap(10, 62, Images::LevelSplash_Bottom);
    PD::setColor(4, 15);

    // PD::setCursor(9, 20);
    // PD::print("Level: ");
    // PD::print(map.getLevel(), 10);
    
    PD::setCursor(9, 20);
    PD::print("Kills");
    PD::drawBitmap(37, 21, Images::Colon);
    PD::setCursor(44, 20);
    this->printPaddedNumber(player.getKills(), 2);
    PD::print("  =");
    PD::setCursor(73, 20);
    this->printPaddedNumber(killp, 4);
    
    PD::setCursor(9, 28);
    PD::print("Coins");
    PD::drawBitmap(37, 29, Images::Colon);
    PD::setCursor(44, 28);
    this->printPaddedNumber(player.getCoins(), 2);
    PD::print("  =");
    PD::setCursor(73, 28);
    this->printPaddedNumber(padd, 4);
    
    PD::setCursor(9, 36);
    PD::print("Time Bonus");
    PD::drawBitmap(68, 37, Images::Colon);
    PD::setCursor(73, 36);
    this->printPaddedNumber(this->map.getTimer() / 10, 4);
    
    PD::setCursor(9, 44);
    PD::print("Level Pts");
    PD::drawBitmap(62, 45, Images::Colon);
    PD::setCursor(73, 44);
    this->printPaddedNumber(pts, 4);
    PD::setCursor(9, 52);
    PD::print("Total Pts");
    PD::drawBitmap(63, 53, Images::Colon);
    PD::setCursor(73, 52);
    this->printPaddedNumber(this->points + pts, 4);
    
    if ((PC::frameCount % 800 == 0) || (PC::buttons.pressed(BTN_A))) {  

        if (this->randomLevel) { this->mapRandomLow++; }
        gameState = GameState::LoadMap;
        this->points += pts;
    }

}

void Game::printPaddedNumber(int32_t number, uint8_t places) {

    if (places >= 5 && number < 10000) PD::print("0");
    if (places >= 4 && number < 1000) PD::print("0");
    if (places >= 3 && number < 100) PD::print("0");
    if (places >= 2 && number < 10) PD::print("0");
    PD::print(number, 10);

}