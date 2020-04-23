#include "Pokitto.h"
#include "Game.h"

void Game::updateMainMenu() {

    const uint8_t orbOffset[] = { 0, 1, 2, 1 };


    // Reset game details ..

    this->map.reset();
    this->player.reset();
    

    if (PC::frameCount % 24 == 0) {

        this->titleScreenVars.orbCounter++;
        if (this->titleScreenVars.orbCounter > 3) this->titleScreenVars.orbCounter = 0;
    
    }

    switch (this->titleScreenVars.arrowCounter) {

        case -3 ... -1:
            this->titleScreenVars.arrowCounter++;
            break;

        case 1 ... 3:
            this->titleScreenVars.arrowCounter--;
            break;

    }



    // Handle player actions ..

    if (PC::buttons.pressed(BTN_UP) && this->titleScreenVars.mode == TitleScreenMode::HighScore) {

        this->titleScreenVars.mode = TitleScreenMode::Start;
        this->titleScreenVars.arrowCounter = -3;

    }

    if (PC::buttons.pressed(BTN_DOWN) && this->titleScreenVars.mode == TitleScreenMode::Start) {

        this->titleScreenVars.mode = TitleScreenMode::HighScore;
        this->titleScreenVars.arrowCounter = 3;

    }
    else {

    }


    if (PC::buttons.pressed(BTN_A)) {

        if (this->titleScreenVars.mode == TitleScreenMode::Start) {
            gameState = GameState::LoadMap;
        }
        else {
            this->highScoreVariables.entryIdx = NO_HIGH_SCORE_EDIT;
            gameState = GameState::HighScore;
        }

    }


    // Draw screen ..

    PD::fillScreen(0);

    for (uint8_t x = 0; x < 110; x = x + 16) {

        PD::drawBitmap(x, 1, Images::BorderTOP);
        PD::drawBitmap(x, 58, Images::BorderBOT);

    }

    PD::drawBitmap(19, 1, Images::PlayerTOP);
    PD::drawBitmap(2, 17, Images::PlayerBOT);
    PD::drawBitmap(68, 15, Images::DarkRitual);

    PD::drawBitmap(89, 69 + (this->titleScreenVars.arrowCounter < 0 ? -1 : 0), Images::ArrowUp);
    PD::drawBitmap(89, 83 + (this->titleScreenVars.arrowCounter > 0 ? 1 : 0), Images::ArrowDown);

    if (PC::frameCount % 128 <= 1) {
        PD::drawBitmap(22, 32, Images::Eyes_Closed);
    }
    else {
        PD::drawBitmap(22, 32, Images::Eyes_Open);
    }

    if (this->titleScreenVars.mode == TitleScreenMode::Start) {
        PD::drawBitmap(74, 74, Images::Start);
    }
    else {
        PD::drawBitmap(74, 74, Images::Score);
    }

    PD::drawBitmap(22, 56 + orbOffset[this->titleScreenVars.orbCounter], Images::Orb);

}
