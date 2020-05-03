#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


void Game::setup(GameCookie *cookie) { 
    
    this->cookie = cookie;
    map.setLevel(0);

    PS::playMusicStream("music/galaxy1.raw", 0);
    
}

void Game::loop(void) {
    
    PC::buttons.pollButtons();
    PD::clear();

    switch(gameState) {

        case GameState::SplashScreen: 
            splashScreen(); 
            break;

        case GameState::MainMenu: 
            updateMainMenu(); 
            break;

        case GameState::Game: 
            updateGame(this->gameMode); 
            break;

        case GameState::LoadMap: 
            nextLevelLoad(this->gameMode); 
            break;

        case GameState::EndOfLevel: 
            endOfLevel(); 
            break;

        case GameState::Inventory: 
            showInventory(); 
            break;

        case GameState::Dead: 
            death(); 
            break;

        case GameState::HighScore: 
            highScore(); 
            break;

        case GameState::WinState:  
            win(); 
            break;

        case GameState::Shop:  
            showShop(); 
            break;

        case GameState::AltarPieceAchieved:  
            showAltarPieceMessage();
            break;

        case GameState::Guide:  
            showGuide();
            break;

        case GameState::NeedRune:  
            showNeedRuneMessage();
            break;

        #ifdef DEBUG
            case GameState::MapDetails:  
                mapDetails(); 
                break;
        #endif

    }
	
}



