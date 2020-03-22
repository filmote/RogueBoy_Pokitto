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

    int padd = player.getCoins() * 5;    
    int killp = player.getKills() * 10;

    PD::setCursor(0,0);
    PD::print("Level: ");
    PD::print(map.getLevel(), 10);
    PD::print("\nKills: ");
    PD::print(player.getKills(), 10);
    PD::print("\nCoins: ");
    PD::print(player.getCoins(), 10);
    PD::print("\nTime Bonus: ");
    PD::print(this->map.getTimer() / 10);
    PD::print("\nLevel Points: ");
    PD::print(padd + killp + (this->map.getTimer()/10), 10);
    
    PD::print("\nTotal Points: ");
    PD::print(this->points+padd+killp+(this->map.getTimer()/10), 10);
    
    if ((PC::frameCount % 240 == 0) || (PC::buttons.pressed(BTN_A))) {
        gameState = GameState::LoadMap;
        this->points += padd + killp + (this->map.getTimer()/10);
    }

}