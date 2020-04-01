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

    PD::drawBitmap(93, 74, Images::Fireball);


    PD::setColor(6, 0);

}

void Game::renderEnviroment() {

    int tileX = this->map.getTileX(player.getX());
    int tileY = this->map.getTileY(player.getY());
    int offsetX = this->map.getTileXOffset(player.getX());
    int offsetY = this->map.getTileYOffset(player.getY());

    for (int i = -8; i < 7; i++) {
    
        for(int j = -4; j < 4; j++) {
            
            uint8_t block = this->map.getBlock(tileX + i, tileY + j);

            switch (block) {

                case MapTiles::NewStraightTorchBOT_F0:
                case MapTiles::NewStraightTorchTOP_F0:
                case MapTiles::NewStraightTorchLHS_F0:
                case MapTiles::NewStraightTorchRHS_F0:
                    if (PC::frameCount % 24 < 12) { block = block + 4; }
                    break;

                case MapTiles::NewStraightTorchBOT_F1:
                case MapTiles::NewStraightTorchTOP_F1:
                case MapTiles::NewStraightTorchLHS_F1:
                case MapTiles::NewStraightTorchRHS_F1:
                    if (PC::frameCount % 24 < 12) { block = block - 4; }
                    break;

                default:
                    break;

            }

            int drawX = (i * 16) + CENTERX - offsetX;
            int drawY = (j * 16) + CENTERY - offsetY;
            PD::drawBitmap(drawX, drawY, Images::Tiles[block]);

        }

    }

}

void Game::renderPlayer() {	
    
    if(!player.getMoving()) {
//        PD::drawBitmap(CENTERX - 6, CENTERY - 6, Images::Players[0]);
        PD::drawBitmap(CENTERX - 6, CENTERY - 6, Images::Players[static_cast<uint8_t>(player.getDirection()) * 2 + player.getFrame()]);

    }
    else {

        if(Pokitto::Core::frameCount % 5 == 0) {
            player.incFrame();
        }

        PD::drawBitmap(CENTERX - 6, CENTERY - 6, Images::Players[static_cast<uint8_t>(player.getDirection()) * 2 + player.getFrame()]);

    }

}