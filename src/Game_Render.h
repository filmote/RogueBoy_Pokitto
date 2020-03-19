#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


// void Game::DrawHealth() {
//   //sprites.drawOverwrite(0, 56, HealthBar, 0);
//   float Drawn = (static_cast<float>(player.getHealth()) / 100)*42;
// //  ard.drawFastHLine(9,59,Drawn,BLACK);
// }


// void Game::DrawHolding() {
//   //sprites.drawExternalMask(98, 43 ,slots,SlotsMask, 0,0);
//   PD::setCursor(108,45);
//   PD::print(player.getKeys());
//   PD::setCursor(108,55);
//   PD::print(player.getCoins());
// }

// void Game::DrawTime() {
//   //sprites.drawOverwrite(90, -6 ,TimeSlot,0);
//   PD::setCursor(102,1);
//   PD::print(Timer);
// }

// void Game::DrawHud() {
//   DrawHealth();
//   DrawHolding();
//   DrawTime();
//   PD::setCursor(0,0);
//   PD::print("L:");
//   PD::print(Level, 10);
// }

// void Game::RenderEnviroment()
// {
//   int tileX = getTileX(player.getX());
//   int tileY = getTileY(player.getY());
//   int offsetX = getTileXOffset(player.getX());
//   int offsetY = getTileYOffset(player.getY());
    
//   for (int i = -8; i < 8; i++)
//   {
//     for(int j = -8; j < 8; j++)
//     {
//       uint8_t block = getBlock(MAP_HEIGHT, MAP_WIDTH, tileX + i, tileY + j);
      
//       int drawX = (i * 16) + CENTERX - offsetX;
//       int drawY = (j * 16) + CENTERY - offsetY;
//       PD::drawBitmap(drawX, drawY, Images::Tiles[block]);
//     }
//   }
// }

// void Game::RenderPlayer() {	
// 	const uint8_t PlayerFrames[] = { 0, 1, 0, 2 };
//   if(!player.getMoving())
//   {
//     PD::drawBitmap(CENTERX - 4, CENTERY - 4, Images::Sprites[0]);
//   }
//   else
//   {
//     if(Pokitto::Core::frameCount % 5 == 0)
//     {
//       player.incFrame();
//     }
//     PD::drawBitmap(CENTERX - 4, CENTERY - 4, Images::Sprites[PlayerFrames[player.getFrame()]]);
//   }
// }