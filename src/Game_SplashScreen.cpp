#include "Game.h"
#include "Pokitto.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void Game::splashScreen() { 

    //if (PC::buttons.pressed(BTN_A))  { this->gameState = GameState::MainMenu; }


    auto justPressed = PC::buttons.pressed(BTN_A) || PC::buttons.pressed(BTN_B) || PC::buttons.pressed(BTN_C);

    if (justPressed > 0) {

        if (this->splashScreenVariables.mode == SplashScreenMode::PPOT) {

            this->splashScreenVariables.mode = SplashScreenMode::Dreamer;
            
        }
        else {

            this->gameState = GameState::MainMenu; 

        }

    }
    
    if (PC::frameCount % 12 == 0) {

        splashScreenVariables.counter++;
        
        if (splashScreenVariables.counter == 4) {
            
            splashScreenVariables.counter = 0;
            
        }
        
    }
  

    //  Render the state ..

    switch (this->splashScreenVariables.mode) {

        case SplashScreenMode::PPOT:
            PD::drawBitmap(22, 27, Images::Ppot_Full);
            PD::drawBitmap(32, 38, Images::Ppot[splashScreenVariables.counter]);

            if (splashScreenVariables.counter < 2) PD::drawBitmap(82, 36, Images::Ppot_Arrow);
            break;

        case SplashScreenMode::Dreamer:
            PD::drawBitmap(28, 17, Images::Dreamer2345_Base);
            if (PC::frameCount % 128 <= 1) {
                PD::drawBitmap(43, 36, Images::Dreamer2345_Eye);
            }
            break;

    }

}
