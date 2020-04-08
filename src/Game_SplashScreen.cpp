#include "Game.h"
#include "Pokitto.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void Game::splashScreen() { 

    if (PC::buttons.pressed(BTN_A))  { this->gameState = GameState::MainMenu; }


    auto justPressed = PC::buttons.pressed(BTN_A) || PC::buttons.pressed(BTN_B) || PC::buttons.pressed(BTN_C);

    if (justPressed > 0) {

        this->gameState = GameState::MainMenu; 

    }
    
    if (PC::frameCount % 12 == 0) {
        
        splashScreenCounter++;
        
        if (splashScreenCounter == 4) {
            
            splashScreenCounter = 0;
            
        }
        
    }
  

    //  Render the state ..

    PD::drawBitmap(44, 54, Images::Ppot_Full);
    PD::drawBitmap(64, 76, Images::Ppot[splashScreenCounter]);

    if (splashScreenCounter < 2) PD::drawBitmap(163, 72, Images::Ppot_Arrow);

}
