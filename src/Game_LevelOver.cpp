#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;



void Game::win_Init() {

    this->winScreenVars.runeEOG[0].direction = Direction::Left;
    this->winScreenVars.runeEOG[0].delay = 10;
    this->winScreenVars.runeEOG[0].index = 0;
    this->winScreenVars.runeEOG[0].x = 46;

    this->winScreenVars.runeEOG[1].direction = Direction::Right;
    this->winScreenVars.runeEOG[1].delay = 25;
    this->winScreenVars.runeEOG[1].index = 0;
    this->winScreenVars.runeEOG[1].x = 38;

    this->winScreenVars.runeEOG[2].direction = Direction::Left;
    this->winScreenVars.runeEOG[2].delay = 45;
    this->winScreenVars.runeEOG[2].index = 0;
    this->winScreenVars.runeEOG[2].x = 46;

    this->winScreenVars.runeEOG[3].direction = Direction::Right;
    this->winScreenVars.runeEOG[3].delay = 65;
    this->winScreenVars.runeEOG[3].index = 0;
    this->winScreenVars.runeEOG[3].x = 38;

    this->winScreenVars.runeEOG[4].direction = Direction::Left;
    this->winScreenVars.runeEOG[4].delay = 80;
    this->winScreenVars.runeEOG[4].index = 0;
    this->winScreenVars.runeEOG[4].x = 46;

    this->winScreenVars.runeEOG[5].direction = Direction::Right;
    this->winScreenVars.runeEOG[5].delay = 105;
    this->winScreenVars.runeEOG[5].index = 0;
    this->winScreenVars.runeEOG[5].x = 38;

    this->winScreenVars.counter = 220;
    this->winScreenVars.yPos = 90;
    this->winScreenVars.mode = WinScreenMode::ShowAnim;
    
    this->gameState = GameState::WinState;

}

void Game::win() {

    const uint8_t coordsY[] = { 94, 86, 80, 74, 68, 62, 56, 48, 
                                42, 37, 32, 28, 24, 20, 17, 14, 
                                11,  9,  7,  6,  5,  5,  4,  4, 
                                 3,  3,  3,  3,  4,  4,  5,  5, 
                                 6,  7,  9, 11, 14, 17, 20, 24, 
                                28, 32, 37, 43, 48, 56, 62, 68, 
                                72, 67, 62, 57, 53, 49, 45, 42, 
                                39, 36, 33, 31, 29, 28, 27, 27, 
                                26, 26, 26, 26, 27, 27, 28, 29, 
                                31, 33, 36, 39 };


    switch (this->winScreenVars.mode) {

        case WinScreenMode::ShowAnim:
            {
                    
                for (uint8_t x = 0; x < 6; x++) {

                    auto &rune = this->winScreenVars.runeEOG[x];

                    if (rune.delay > 0) {

                        rune.delay--;

                    }
                    else {
                        
                        if (rune.index < 75) {
                            rune.x = rune.x + (rune.direction == Direction::Left ? -1 : 1);
                            rune.index++;
                        }

                    }

                }

                PD::drawBitmap(0, 36, Images::WallBackground_Ending);
                PD::drawBitmap(22, 2, Images::Player);

                if (PC::frameCount % 128 <= 1) {
                    PD::drawBitmap(42, 32, Images::Eyes_Closed);
                }
                else {
                    PD::drawBitmap(42, 32, Images::Eyes_Open);
                }

                for (uint8_t x = 0; x < 6; x++) {

                    auto &rune = this->winScreenVars.runeEOG[x];

                    if (rune.index < 20) {

                        PD::drawBitmap(rune.x, coordsY[rune.index], Images::LargeRunes[x]);

                    }

                }

                PD::drawBitmap(0, 78, Images::OpenBook);

                for (uint8_t x = 0; x < 6; x++) {

                    auto &rune = this->winScreenVars.runeEOG[x];

                    if (rune.index >= 20) {

                        PD::drawBitmap(rune.x, coordsY[rune.index], Images::LargeRunes[x]);

                    }

                }

            }

            this->winScreenVars.counter--;
            if (this->winScreenVars.counter == 0 || PC::buttons.pressed(BTN_A)) { 
                this->winScreenVars.counter = 740;
                this->winScreenVars.mode = WinScreenMode::ShowMessage;
            }
                
            break;

        case WinScreenMode::ShowMessage:

            if (PC::frameCount % 4 == 0) {
                this->winScreenVars.yPos--;
            }

            PD::setColor(6, 0);
            PD::setCursor(0, static_cast<uint16_t>(this->winScreenVars.yPos));
            PD::print(" A sdfsd sdf fdsfs3"); 
            PD::setCursor(0, this->winScreenVars.yPos + 9);
            PD::print(" 1 sdfsd sdf fdsfs"); 
            PD::setCursor(0, this->winScreenVars.yPos + 18);
            PD::print(" 2 sdfsd sdf fds fs"); 
            PD::setCursor(0, this->winScreenVars.yPos + 27);
            PD::print(" 3 sdfsd sdf fdsfs"); 
            PD::setCursor(0, this->winScreenVars.yPos + 36);
            PD::print(" 4 sdfsd sdd dsfsg"); 
            PD::setCursor(0, this->winScreenVars.yPos + 45);
            PD::print(" 5 sdfsd sdf fdsfs"); 
            PD::setCursor(0, this->winScreenVars.yPos + 54);
            PD::print(" 6 sdfsd sdsf ds fs"); 
            PD::setCursor(0, this->winScreenVars.yPos + 63);
            PD::print(" 7 sdfsd sdf fdsffs"); 
            PD::setCursor(0, this->winScreenVars.yPos + 72);
            PD::print(" 8 sdfsd sdf fdsfs"); 
            PD::setCursor(0, this->winScreenVars.yPos + 81);
            PD::print(" 9 sdfsd sdf fdsfs"); 

            PD::setColor(0, 0);
            PD::fillRect(0, 0, 110, 7);
            PD::drawBitmap(0, 78, Images::OpenBook);

            this->winScreenVars.counter--;
            if (this->winScreenVars.counter == 0 || PC::buttons.pressed(BTN_A)) { 
                this->winScreenVars.counter = 300;
                this->winScreenVars.mode = WinScreenMode::Score;
            }
            break;

        case WinScreenMode::Score:
            {
                this->renderEnviroment(0, 0);
                this->renderHud();
    
                PD::setColor(15);
                PD::fillRectangle(10, 10, 90, 52);
                PD::drawBitmap(0, 0, Images::LevelSplash_Left);
                PD::drawBitmap(10, 0, Images::LevelSplash_Top);
                PD::drawBitmap(100, 0, Images::LevelSplash_Right);
                PD::drawBitmap(10, 62, Images::LevelSplash_Bottom);
                PD::setColor(4, 15);
    
                uint32_t pts = this->printLevelSummary(20, this->map.getTimer()/10);
                
                if ((PC::frameCount % 800 == 0) || (PC::buttons.pressed(BTN_A))) {  
    
                    this->highScoreOrNot(pts);
                    //sound.noTone(); 
                    gameState = GameState::HighScore; 
    
                }
    
                PD::setColor(0, 0);
            }
            break;

    }

}

void Game::endOfLevel() {

    this->renderEnviroment(0, 0);
    this->renderHud();

    PD::setColor(15);
    PD::fillRectangle(10, 10, 90, 52);
    PD::drawBitmap(0, 0, Images::LevelSplash_Left);
    PD::drawBitmap(10, 0, Images::LevelSplash_Top);
    PD::drawBitmap(100, 0, Images::LevelSplash_Right);
    PD::drawBitmap(10, 62, Images::LevelSplash_Bottom);
    PD::setColor(4, 15);

    uint32_t pts = this->printLevelSummary(20, this->map.getTimer()/10);
    
    if ((PC::frameCount % 800 == 0) || (PC::buttons.pressed(BTN_A))) {  

        if (this->map.getRandomLevel()) { this->map.setRandomLow(this->map.getRandomLow() + 1); }
        gameState = GameState::LoadMap;
        this->points += pts;
    }

    PD::setColor(0, 0);

}
