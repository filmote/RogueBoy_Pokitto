#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;


                              // A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z  0, 1  2  3  4  5  6  7  8  9 
const uint8_t charWidths[36] = { 4, 4, 4, 4, 4, 4, 5, 5, 1, 4, 5, 4, 6, 5, 4, 4, 5, 4, 4, 5, 5, 5, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 };

void Game::highScore() {


    // Handle player actions ..

    if (this->highScoreVariables.entryIdx == NO_HIGH_SCORE_EDIT) {

        if (PC::buttons.pressed(BTN_A)) {

            gameState = GameState::MainMenu; 
            map.setLevel(0); 
            this->points = 0; 

        }

    }
    else {

        if (PC::buttons.pressed(BTN_LEFT) && this->highScoreVariables.charIdx > 0) {
            this->highScoreVariables.charIdx--;
        }

        if (PC::buttons.pressed(BTN_RIGHT) && this->highScoreVariables.charIdx < 2) {
            this->highScoreVariables.charIdx++;
        }
            
        if (PC::buttons.pressed(BTN_UP) || (PC::buttons.repeat(BTN_UP, 1) && PC::frameCount % 4 == 0)) {

            switch (this->cookie->score_Char[this->highScoreVariables.entryIdx][this->highScoreVariables.charIdx]) {

                case 'A' ... 'Y':
                case '0' ... '8':
                    this->cookie->score_Char[this->highScoreVariables.entryIdx][this->highScoreVariables.charIdx] = this->cookie->score_Char[this->highScoreVariables.entryIdx][this->highScoreVariables.charIdx] + 1;
                    break;

                case 'Z':
                    this->cookie->score_Char[this->highScoreVariables.entryIdx][this->highScoreVariables.charIdx] = '0';
                    break;

                case '9':
                    this->cookie->score_Char[this->highScoreVariables.entryIdx][this->highScoreVariables.charIdx] = 'A';
                    break;

            }

        }

        if (PC::buttons.pressed(BTN_DOWN) || (PC::buttons.repeat(BTN_DOWN, 1) && PC::frameCount % 4 == 0)) {

            switch (this->cookie->score_Char[this->highScoreVariables.entryIdx][this->highScoreVariables.charIdx]) {

                case 'B' ... 'Z':
                case '1' ... '9':
                    this->cookie->score_Char[this->highScoreVariables.entryIdx][this->highScoreVariables.charIdx] = this->cookie->score_Char[this->highScoreVariables.entryIdx][this->highScoreVariables.charIdx] - 1;
                    break;

                case 'A':
                    this->cookie->score_Char[this->highScoreVariables.entryIdx][this->highScoreVariables.charIdx] = '9';
                    break;

                case '0':
                    this->cookie->score_Char[this->highScoreVariables.entryIdx][this->highScoreVariables.charIdx] = 'Z';
                    break;

            }

        }

        if (PC::buttons.pressed(BTN_A)) {

            this->cookie->saveCookie();
            this->highScoreVariables.entryIdx = NO_HIGH_SCORE_EDIT;

        }

    }


    // Rnder screen ..

    this->renderEnviroment(0, 0);
    this->renderHud();

    PD::setColor(15);
    PD::fillScreen(15);
    PD::drawBitmap(0, 0, Images::LevelSplash_UpperLeft);
    PD::drawBitmap(0, 16, Images::LevelSplash_Left);
    PD::drawBitmap(10, 0, Images::LevelSplash_Top);
    PD::drawBitmap(100, 0, Images::LevelSplash_UpperRight);
    PD::drawBitmap(100, 16, Images::LevelSplash_Right);
    PD::drawBitmap(10, 78, Images::LevelSplash_Bottom);
    PD::setColor(4, 15);
    
    PD::setCursor(24, 21);
    PD::print("High Scores");

    for (uint8_t y = 0; y < 5; y++) {

        uint8_t charPos = 13;

        for (uint8_t x = 0; x < 3; x++) {

            uint8_t charWidth = 0;

            switch (this->cookie->score_Char[y][x]) {

                case 'A' ... 'Z':
                    charWidth = charWidths[this->cookie->score_Char[y][x] - 65];
                    break;

                case '0' ... '9':
                    charWidth = charWidths[this->cookie->score_Char[y][x] - 48 + 26];
                    break;

            }
            
            PD::setCursor(charPos, 31 + (y * 9));
            PD::print(this->cookie->score_Char[y][x]);

            if (x == this->highScoreVariables.charIdx && y == this->highScoreVariables.entryIdx && PC::frameCount % 48 < 24) {

                PD::setColor(2);//9);
                PD::drawLine(charPos, 30 + (y * 9), charPos + charWidth, 30 + (y * 9));
                PD::drawLine(charPos, 38 + (y * 9), charPos + charWidth, 38 + (y * 9));
                PD::setColor(4, 15);

            }

            charPos = charPos + charWidth + 2;
            
        }

        PD::setCursor(41, 31 + (y * 9));
        PD::print("L");
        this->printPaddedNumber(this->cookie->level[y], 2);

        PD::setCursor(70, 31 + (y * 9));
        this->printPaddedNumber(this->cookie->score[y], 4);

    }

}
