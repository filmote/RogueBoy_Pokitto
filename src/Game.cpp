#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


void Game::setup(/*GameCookie *cookie*/) { 
    
//    this->cookie = cookie;
    map.setLevel(0);
    
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

