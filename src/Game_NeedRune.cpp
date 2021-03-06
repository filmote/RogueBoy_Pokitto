#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;


void Game::showNeedRuneMessage() {


    // Handle player actions ..

    if (PC::buttons.pressed(BTN_A)) {

        gameState = GameState::Game; 

    }



    // Rnder screen ..

    PD::fillScreen(0);
    this->renderEnvironment(!this->map.isBossLevel() && !this->map.isAltarLevel(), 0, 0);
    this->renderHud();
    PD::setColor(6);

    // PD::setColor(15);
    // PD::fillRect(21, 27, 70, 24);
    // PD::drawBitmap(15, 22, Images::MessagePanelTOP); 
    // PD::drawBitmap(15, 29, Images::MessagePanelLHS); 
    // PD::drawBitmap(88, 29, Images::MessagePanelRHS); 
    // PD::drawBitmap(15, 50, Images::MessagePanelBOT); 
    // PD::setColor(4, 15);
    // PD::setFont(font3x5);
    this->renderMessageBox();

    PD::setCursor(26, 30);
    PD::print("You have left a");
    PD::setCursor(24, 37);
    PD::print("rune behind, you");
    PD::setCursor(26, 44);
    PD::print("cannot proceed!");

    PD::setFont(fontKoubit);

}
