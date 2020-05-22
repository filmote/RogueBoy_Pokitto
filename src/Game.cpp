#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;



void Game::setup(GameCookie *cookie/*, Audio::Sink<4, PROJ_AUD_FREQ> *audio*/) { 
    
    this->cookie = cookie;
//    this->audio = audio;
    this->splashScreenVariables.buttonCounter = 16;
    map.setLevel(0);

    auto music = Audio::play<0>("music/darkrit1.raw"); 
    if (music) music->setLoop(true);
    
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

        case GameState::Puzzle_Init_Game:
            play_InitGame();
            break;

        case GameState::Puzzle_No_Selection:
            play_NoSelection();
            break;

        case GameState::Puzzle_Node_Selected:
            play_NodeSelected();
            break;

        case GameState::Puzzle_Game_Over:
            puzzleGameOver();
            break;

        #ifdef DEBUG
            case GameState::MapDetails:  
                mapDetails(); 
                break;
        #endif

    }
	
}



