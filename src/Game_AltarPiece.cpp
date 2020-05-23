#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;


void Game::showAltarPieceMessage() {


    // Handle player actions ..

    if (PC::buttons.pressed(BTN_A)) {

        gameState = GameState::Game; 

    }



    // Rnder screen ..

    PD::fillScreen(0);
    this->renderHud();
    this->renderEnviroment(0, 0);
    PD::setColor(6);

    PD::setColor(15);
    PD::fillRect(21, 27, 70, 24);
    PD::drawBitmap(15, 22, Images::MessagePanelTOP); 
    PD::drawBitmap(15, 29, Images::MessagePanelLHS); 
    PD::drawBitmap(88, 29, Images::MessagePanelRHS); 
    PD::drawBitmap(15, 50, Images::MessagePanelBOT); 
    PD::setColor(4, 15);
    PD::setFont(font3x5);


    PD::setCursor(24, 30);
    PD::print("Congratulations!");
    PD::setCursor(26, 37);
    PD::print("You have found");
    PD::setCursor(25, 44);
    PD::print("an altar piece.");

    PD::setFont(fontKoubit);

}
