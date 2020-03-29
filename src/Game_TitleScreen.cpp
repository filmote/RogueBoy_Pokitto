#include "Pokitto.h"
#include "Game.h"

void Game::updateMainMenu() {

    PD::drawBitmap(0,0, Images::Logo);

    if (PC::buttons.pressed(BTN_A)) {
        gameState = GameState::LoadMap;
    }

}
