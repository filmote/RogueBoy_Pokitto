#include "Pokitto.h"
#include "Game.h"

void Game::updateMainMenu() {

    const uint8_t orbOffset[] = { 0, 1, 2, 1 };


    // Reset game details ..

    this->map.reset();
    this->player.reset();
    this->points = 0;
    

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

    if (PC::buttons.pressed(BTN_UP) && (this->titleScreenVars.mode > TitleScreenMode::Start || (this->cookieSaveGame->getLevel() != 255 && this->titleScreenVars.mode > TitleScreenMode::Resume))) {

        this->titleScreenVars.mode--;
        this->titleScreenVars.arrowCounter = -3;

    }

    if (PC::buttons.pressed(BTN_DOWN) && this->titleScreenVars.mode < TitleScreenMode::Help) {

        this->titleScreenVars.mode++;
        this->titleScreenVars.arrowCounter = 3;

    }
    else {

    }


    if (PC::buttons.pressed(BTN_A)) {


        // Select a random amount for each shop object?

        this->shopObjects[0].quantityLeft = random(INVENTORY_BREAD_MIN, INVENTORY_BREAD_MAX);
        this->shopObjects[1].quantityLeft = random(INVENTORY_CHICKEN_MIN, INVENTORY_CHICKEN_MAX);
        this->shopObjects[2].quantityLeft = random(INVENTORY_KEY_MIN, INVENTORY_KEY_MAX);
        this->shopObjects[3].quantityLeft = random(INVENTORY_TOOLS_MIN, INVENTORY_TOOLS_MAX);
        this->shopObjects[4].quantityLeft = random(INVENTORY_TONIC_MIN, INVENTORY_TONIC_MAX);
        this->shopObjects[5].quantityLeft = random(INVENTORY_ICE_SPELL_MIN, INVENTORY_ICE_SPELL_MAX);
        this->shopObjects[6].quantityLeft = random(INVENTORY_GREEN_SPELL_MIN, INVENTORY_GREEN_SPELL_MAX);
        this->shopObjects[7].quantityLeft = random(INVENTORY_RED_SPELL_MIN, INVENTORY_RED_SPELL_MAX);
        this->shopObjects[8].quantityLeft = random(INVENTORY_MAUVE_SPELL_MIN, INVENTORY_MAUVE_SPELL_MAX);
        

        switch (this->titleScreenVars.mode) {

            case TitleScreenMode::Resume:
                this->gameState = GameState::LoadMap;
                this->gameMode = GameMode::Resume;
                break;

            case TitleScreenMode::Start:
                this->gameState = GameState::LoadMap;
                this->gameMode = GameMode::Normal;
                break;

            case TitleScreenMode::HighScore:
                this->highScoreVariables.entryIdx = NO_HIGH_SCORE_EDIT;
                gameState = GameState::HighScore;
                break;

            case TitleScreenMode::Help:
                this->gameState = GameState::LoadMap;
                this->gameMode = GameMode::Help;
                break;

        }

    }


    // Draw screen ..

    PD::fillScreen(0);

    for (uint8_t x = 0; x < 110; x = x + 16) {

        PD::drawBitmap(x, 1, Images::BorderTOP);
        PD::drawBitmap(x, 58, Images::BorderBOT);

    }



    // PD::drawBitmap(19, 1, Images::PlayerTOP);
    // PD::drawBitmap(2, 17, Images::PlayerBOT);
    PD::drawBitmap(2, 2, Images::Player);
    PD::drawBitmap(66, 15, Images::DarkRitual);

    PD::drawBitmap(89, 69 + (this->titleScreenVars.arrowCounter < 0 ? -1 : 0), Images::ArrowUp);
    PD::drawBitmap(89, 83 + (this->titleScreenVars.arrowCounter > 0 ? 1 : 0), Images::ArrowDown);

    if (PC::frameCount % 128 <= 1) {
        PD::drawBitmap(22, 32, Images::Eyes_Closed);
    }
    else {
        PD::drawBitmap(22, 32, Images::Eyes_Open);
    }

    PD::drawBitmap(70 + (static_cast<uint8_t>(this->titleScreenVars.mode) > 0 ? 4 : 0), 74, Images::Title_Modes[static_cast<uint8_t>(this->titleScreenVars.mode)]);
    PD::drawBitmap(22, 56 + orbOffset[this->titleScreenVars.orbCounter], Images::Orb);



    printf("%i\n", fade);

}
