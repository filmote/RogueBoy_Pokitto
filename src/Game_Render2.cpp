#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


void Game::renderEnviroment_Top_Left(int x, int y, int drawX, int drawY) {

    switch (this->map.getBlock(x - 1, y - 1)) {

        case MapTiles::NewStraightRHS:
        case MapTiles::NewStraightLR:
        case MapTiles::NewEndTRL:
        // printf("a\n");
            PD::drawBitmap(drawX - 8, drawY, Images::NewCornerFillTR);
            break;

    }

}

void Game::renderEnviroment_Top_Right(int x, int y, int drawX, int drawY) {

    switch (this->map.getBlock(x + 1, y - 1)) {

        case MapTiles::NewStraightLHS:
        case MapTiles::NewStraightLR:
        case MapTiles::NewEndTRL:
        // printf("b\n");
            PD::drawBitmap(drawX + 16, drawY, Images::NewCornerFillTL);
            break;

    }

}

void Game::renderEnviroment_Bot_Left(int x, int y, int drawX, int drawY) {

    switch (this->map.getBlock(x - 1, y + 1)) {

        case MapTiles::NewStraightRHS:
        case MapTiles::NewStraightLR:
        case MapTiles::NewEndRBL:
        case MapTiles::NewCornerLR:
        // printf("c\n");
            PD::drawBitmap(drawX - 8, drawY + 8, Images::NewCornerFillLR);
            break;

    }

}


void Game::renderEnviroment_Bot_Right(int x, int y, int drawX, int drawY) {

    switch (this->map.getBlock(x + 1, y + 1)) {

        case MapTiles::NewStraightLHS:
        case MapTiles::NewStraightLR:
        case MapTiles::NewEndRBL:
        case MapTiles::NewCornerLL:
        // printf("d\n");
            PD::drawBitmap(drawX + 16, drawY + 8, Images::NewCornerFillLL);
            break;

    }

}
