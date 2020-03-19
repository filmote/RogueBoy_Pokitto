#include "Pokitto.h"
#include "Game.h"

void Game::updateMainMenu() {

    PD::drawBitmap(0,0, Images::Logo);

    if (showarrow) {
        PD::drawBitmap(20,55,Images::Arrow);
    }
    
    if (PC::buttons.pressed(BTN_A)) {
        gameState = GameState::LoadMap;
    }

    if (PC::frameCount % 30 == 0) {
        showarrow = !showarrow;
    }

}


void Game::TitleText() {
  if (PC::buttons.pressed(BTN_A)) {
    //sound.tone(NOTE_C4,500); 
    showarrow = 0; gameState = GameState::MainMenu; 
  }
//  if (!Audio) {
      PD::setCursor(0, 0);
      uint8_t i = 0;
      while(i < 151) {
          // if(ard.nextFrame()) {
          //   ard.pollButtons();

            // if (Pokitto::Core::frameCount % 5 == 0) {
            // PD::print((char)pgm_read_uint8_t(&TitleSequenceText[i]));
            // if ((pgm_read_uint8_t(&TitleSequenceText[i]) != 32)&&(pgm_read_uint8_t(&TitleSequenceText[i]) != 13))
            //   {
            //   //sound.tone(NOTE_C5,150);
            //   }
            // i++;
            // }

            // ard.display();
            
            if (PC::buttons.pressed(BTN_A)) {break;}
          }
      //}
//      Audio = true; 
      showarrow = 0;
  // }
  // else {
  //     for(uint8_t i = 0; i < 151; i++) {
  //         PD::print((char)TitleSequenceText[i]);
  //     }
  //     PD::drawBitmap(0,64-showarrow,Logo);
  //     showarrow++;
  //     if (showarrow >= 64) { 
  //       //sound.tone(NOTE_D2H,150);
  //       Audio = true; 
  //       showarrow = 0; 
  //       gameState = GameState::MainMenu;
  //     }
  // }
}