#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


void Game::renderObjects() {

    objects.render(player);
    bullets.render(player);

}

void Game::renderHud() {

    #ifndef LARGE_SCREEN

    PD::drawBitmap(0, 72, Images::Scoreboard);
    
    
    // Render current level ..

    PD::setColor(6, 14);
    PD::setCursor(10, 74);
    
    if (map.getLevel() < 10) {
      PD::print("0");
    }

    PD::print(map.getLevel(), 10);


    // Time ..

    PD::setCursor(39, 74);

    if (this->map.getTimer() < 100)    PD::print("0");
    if (this->map.getTimer() < 10)     PD::print("0");

    PD::print(map.getTimer(), 10);


    // Holdings ..

    PD::setCursor(74, 74);
    if (player.getInventoryCount(Object::Key) < 10)  PD::print("0");
    PD::print(player.getInventoryCount(Object::Key), 10);
    PD::setCursor(74, 80);
    if (player.getCoins() < 10) PD::print("0");
    PD::print(player.getCoins(), 10);


    // Health ..

    PD::setColor(8);
    PD::drawLine(8, 85, 8 + player.getHealth() / 2 + (player.getHealth() > 50 ? 1 : 0), 85);


    // Weapon ..

    switch (this->player.getWeapon()) {

        case Object::FireBall:
            PD::drawBitmap(93, 74, Images::Fireball);
            break;

        case Object::IceSpell:
            PD::drawBitmap(94, 75, Images::IceSpell_Scoreboard[this->player.getWeaponFrame()]);
            break;

        case Object::GreenSpell:
            {
                PD::drawBitmap(94, 75, Images::GreenSpell_Scoreboard);
                PD::setFont(font3x5);
                uint8_t items = this->player.getInventoryCount(Object::GreenSpell);
                PD::setColor(6);
                PD::setCursor(100,81);
                this->printPaddedNumber(items, 2);
                PD::setFont(fontKoubit);
            }
            break;

        case Object::YellowSpell:
            {
                PD::drawBitmap(94, 75, Images::YellowSpell_Scoreboard);
                PD::setFont(font3x5);
                uint8_t items = this->player.getInventoryCount(Object::YellowSpell);
                PD::setColor(6);
                PD::setCursor(100,81);
                this->printPaddedNumber(items, 2);
                PD::setFont(fontKoubit);
            }
            break;

        case Object::MauveSpell:
            {
                PD::drawBitmap(94, 75, Images::MauveSpell_Scoreboard);
                PD::setFont(font3x5);
                uint8_t items = this->player.getInventoryCount(Object::MauveSpell);
                PD::setColor(6);
                PD::setCursor(100,81);
                this->printPaddedNumber(items, 2);
                PD::setFont(fontKoubit);
            }
            break;

    }

    PD::setColor(6, 0);

    #endif

}

void Game::renderEnviroment(int8_t damageOffsetX, int8_t damageOffsetY) {

    int tileX = this->map.getTileX(player.getX());
    int tileY = this->map.getTileY(player.getY());
    int offsetX = this->map.getTileXOffset(player.getX());
    int offsetY = this->map.getTileYOffset(player.getY());

    for (int i = -8; i < 7; i++) {
    
        for(int j = -7; j < 7; j++) {
            
            uint8_t block = this->map.getBlock(tileX + i, tileY + j);

            int drawX = (i * 16) + CENTERX - offsetX + damageOffsetX;
            int drawY = (j * 16) + CENTERY - offsetY + damageOffsetY;

            switch (block) {

                case MapTiles::NewStraightTorchBOT_F0:
                case MapTiles::NewStraightTorchTOP_F0:
                case MapTiles::NewStraightTorchLHS_F0:
                case MapTiles::NewStraightTorchRHS_F0:
                    if (PC::frameCount % 16 < 8) { block = block + 4; }
                    break;

                case MapTiles::NewStraightTorchBOT_F1:
                case MapTiles::NewStraightTorchTOP_F1:
                case MapTiles::NewStraightTorchLHS_F1:
                case MapTiles::NewStraightTorchRHS_F1:
                    if (PC::frameCount % 16 < 8) { block = block - 4; }
                    break;

                case MapTiles::WormHole_F0:
                    block = block + (PC::frameCount % 20) / 5;
                    break;

                case MapTiles::NewStraightTOP:
                    this->renderEnviroment_Top_Left(tileX + i, tileY + j, drawX, drawY);
                    this->renderEnviroment_Top_Right(tileX + i, tileY + j, drawX, drawY);
                    break;

                case MapTiles::NewStraightBOT:
                    this->renderEnviroment_Bot_Left(tileX + i, tileY + j, drawX, drawY);
                    this->renderEnviroment_Bot_Right(tileX + i, tileY + j, drawX, drawY);
                    break;

                case MapTiles::NewStraightTB:
                    this->renderEnviroment_Top_Left(tileX + i, tileY + j, drawX, drawY);
                    this->renderEnviroment_Top_Right(tileX + i, tileY + j, drawX, drawY);
                    this->renderEnviroment_Bot_Left(tileX + i, tileY + j, drawX, drawY);
                    this->renderEnviroment_Bot_Right(tileX + i, tileY + j, drawX, drawY);
                    break;

                case MapTiles::NewStraightLHS:

                    switch (this->map.getBlock(tileX + i - 1, tileY + j - 1)) {

                        case MapTiles::NewCornerLL:
                            PD::drawBitmap(drawX, drawY - 8, Images::NewCornerFillLL);
                            break;

                    }                

                    switch (this->map.getBlock(tileX + i - 1, tileY + j + 1)) {

                        case MapTiles::NewCornerTL:
                            PD::drawBitmap(drawX, drawY + 16, Images::NewCornerFillTL);
                            break;

                    }                

                    break;

                case MapTiles::NewStraightRHS:

                    switch (this->map.getBlock(tileX + i + 1, tileY + j - 1)) {

                        case MapTiles::NewCornerLR:
                            PD::drawBitmap(drawX + 8, drawY - 8, Images::NewCornerFillLR);
                            break;

                    }                

                    switch (this->map.getBlock(tileX + i + 1, tileY + j + 1)) {

                        case MapTiles::NewCornerTR:
                            PD::drawBitmap(drawX + 8, drawY + 16, Images::NewCornerFillTR);
                            break;

                    }                

                    break;

                case MapTiles::NewEndTBL:
                    this->renderEnviroment_Top_Right(tileX + i, tileY + j, drawX, drawY);
                    this->renderEnviroment_Bot_Right(tileX + i, tileY + j, drawX, drawY);
                    break;

                case MapTiles::NewEndTRB:
                    this->renderEnviroment_Top_Left(tileX + i, tileY + j, drawX, drawY);
                    this->renderEnviroment_Bot_Left(tileX + i, tileY + j, drawX, drawY);
                    break;

                case MapTiles::NewEndTRL:

                    switch (this->map.getBlock(tileX + i - 1, tileY + j + 1)) {

                        case MapTiles::NewStraightTOP:
                        case MapTiles::NewStraightTB:
                            PD::drawBitmap(drawX, drawY + 16, Images::NewCornerFillTL);
                            break;

                    }

                    switch (this->map.getBlock(tileX + i + 1, tileY + j + 1)) {

                        case MapTiles::NewStraightTOP:
                        case MapTiles::NewStraightTB:
                            PD::drawBitmap(drawX + 16, drawY + 16, Images::NewCornerFillTR);
                            break;

                    }
                    break;

                case MapTiles::NewEndRBL:

                    switch (this->map.getBlock(tileX + i - 1, tileY + j - 1)) {

                        case MapTiles::NewStraightBOT:
                        case MapTiles::NewStraightTB:
                            PD::drawBitmap(drawX, drawY - 8, Images::NewCornerFillLL);
                            break;

                    }

                    switch (this->map.getBlock(tileX + i + 1, tileY + j - 1)) {

                        case MapTiles::NewStraightBOT:
                        case MapTiles::NewStraightTB:
                            PD::drawBitmap(drawX + 16, drawY - 8, Images::NewCornerFillLR);
                            break;

                    }
                    break;

                case MapTiles::NewCornerTL:

                    switch (this->map.getBlock(tileX + i - 1, tileY + j + 1)) {

                        case MapTiles::NewStraightTOP:
                        case MapTiles::NewStraightTB:
                        case MapTiles::NewCornerTL:
                        case MapTiles::NewEndTBL:
                            PD::drawBitmap(drawX, drawY + 16, Images::NewCornerFillTL);
                            break;

                    }

                    switch (this->map.getBlock(tileX + i, tileY + j + 1)) {

                        case MapTiles::NewStraightRHS:
                        case MapTiles::NewStraightLR:
                        case MapTiles::NewCornerLR:
                        case MapTiles::NewEndRBL:
                            PD::drawBitmap(drawX + 8, drawY + 8, Images::NewCornerFillLR);
                            break;

                    }
                    break;

                case MapTiles::NewCornerTR:

                    switch (this->map.getBlock(tileX + i + 1, tileY + j + 1)) {

                        case MapTiles::NewStraightTOP:
                        case MapTiles::NewStraightTB:
                        case MapTiles::NewEndTBL:
                            PD::drawBitmap(drawX + 8, drawY + 16, Images::NewCornerFillTR);
                            break;

                    }

                    switch (this->map.getBlock(tileX + i, tileY + j + 1)) {

                        case MapTiles::NewStraightLHS:
                        case MapTiles::NewStraightLR:
                        case MapTiles::NewCornerLL:
                        case MapTiles::NewEndRBL:
                            PD::drawBitmap(drawX, drawY + 8, Images::NewCornerFillLL);
                            break;

                    }
                    break;

                case MapTiles::NewCornerLL:

                    switch (this->map.getBlock(tileX + i + 1, tileY + j + 1)) {

                        case MapTiles::NewStraightLHS:
                        case MapTiles::NewStraightLR:
                        case MapTiles::NewCornerLL:
                        case MapTiles::NewEndRBL:
                            PD::drawBitmap(drawX + 16, drawY + 8, Images::NewCornerFillLL);
                            break;

                    }
                    break;

                case MapTiles::NewCornerLR:

                    switch (this->map.getBlock(tileX + i - 1, tileY + j + 1)) {

                        case MapTiles::NewStraightRHS:
                        case MapTiles::NewStraightLR:
                        case MapTiles::NewCornerLR:
                        case MapTiles::NewEndRBL:
                            PD::drawBitmap(drawX - 8, drawY + 8, Images::NewCornerFillLR);
                            break;

                    }
                    break;

                default:
                    break;

            }


            PD::drawBitmap(drawX, drawY, Images::Tiles[block]);

        }

    }

}

void Game::renderPlayer(int8_t damageOffsetX, int8_t damageOffsetY) {	
    
    if (!player.getMoving()) {

        PD::drawBitmap(CENTERX - 6 - damageOffsetX, CENTERY - 6 - damageOffsetY, Images::Players[static_cast<uint8_t>(player.getDirection()) * 2 + player.getFrame()]);

    }
    else {

        if(Pokitto::Core::frameCount % 5 == 0) {
            player.incFrame();
        }

        PD::drawBitmap(CENTERX - 6 - damageOffsetX, CENTERY - 6 - damageOffsetY, Images::Players[static_cast<uint8_t>(player.getDirection()) * 2 + player.getFrame()]);

    }

    if (this->shockwave > 0) {

        uint8_t offset = (this->shockwave == 1 ? 29 : 1 + ((9 - this->shockwave) * 4));
printf("showave %i %i %i\n", this->shockwave, 9 - this->shockwave, offset);
        PD::drawBitmap(CENTERX - 2 - damageOffsetX - offset, CENTERY - 4 - damageOffsetY - offset, Images::Pulse_TL[8 - this->shockwave]);
        PD::drawBitmap(CENTERX + 2 - damageOffsetX, CENTERY - 4 - damageOffsetY - offset, Images::Pulse_TR[8 - this->shockwave]);

        PD::drawBitmap(CENTERX - 2 - damageOffsetX - offset, CENTERY + 4 - damageOffsetY, Images::Pulse_TL[8 - this->shockwave], 0, 2);
        PD::drawBitmap(CENTERX + 2 - damageOffsetX, CENTERY + 4 - damageOffsetY, Images::Pulse_TR[8 - this->shockwave], 0, 2);
       
    }

}