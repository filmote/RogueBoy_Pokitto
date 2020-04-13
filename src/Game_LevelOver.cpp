#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


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

    this->renderEnviroment(0, 0);
    this->renderHud();

    PD::setColor(15);
    PD::fillRectangle(10, 10, 90, 52);
    PD::drawBitmap(0, 0, Images::LevelSplash_Left);
    PD::drawBitmap(10, 0, Images::LevelSplash_Top);
    PD::drawBitmap(100, 0, Images::LevelSplash_Right);
    PD::drawBitmap(10, 62, Images::LevelSplash_Bottom);
    PD::setColor(4, 15);

    uint32_t pts = this->printLevelSummary(20);
    
    if ((PC::frameCount % 800 == 0) || (PC::buttons.pressed(BTN_A))) {  

        if (this->map.getRandomLevel()) { this->map.setRandomLow(this->map.getRandomLow() + 1); }
        gameState = GameState::LoadMap;
        this->points += pts;
    }

}
