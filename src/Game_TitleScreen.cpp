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
