#include "Pokitto.h"
#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


void Game::setup(/*GameCookie *cookie*/) { 
    
//    this->cookie = cookie;
    Level = 0;
    
}

void Game::loop(void) {
    
    PC::buttons.pollButtons();
    PD::clear();

    switch(gameState) {

        case GameState::TextTitle: 
            TitleText(); 
            break;

        case GameState::MainMenu: 
            UpdateMainMenu(); 
            break;

        case GameState::Game: 
            UpdateGame(); 
            break;

        case GameState::LoadMap: 
            nextLevelLoad(); 
            break;

        case GameState::MapEnding: 
            MapEnding(); 
            break;

        case GameState::Dead: 
            Death(); 
            break;

        case GameState::WinState:  
            win(); 
            break;

    }
	
}


void Game::Death() {
  //sprites.drawOverwrite(CENTERX-7,CENTERY-7,Flowers,0);
  PD::setCursor(0,0);
  PD::print("SCORED:");
  PD::print(this->points, 10);
  PD::print("\nGot To Level:");
  PD::print(Level, 10);
  if (PC::buttons.pressed(BTN_A) || PC::buttons.pressed(BTN_B)) {
    //sound.noTone(); 
    gameState = GameState::MainMenu; Level = 0; this->points = 0; gameType = true;}
  }

void Game::win() {
  //sprites.drawSelfMasked(CENTERX-7,CENTERY-7,Ardu,0);
  PD::setCursor(0,0);
  PD::print("WellDone!\n");
  PD::print("YOU SCORED:");
  PD::print(this->points, 10);
  if (PC::buttons.pressed(BTN_A) || PC::buttons.pressed(BTN_B)) { 
    //sound.noTone(); 
    gameState = GameState::MainMenu; Level = 0; this->points = 0;
  }
}


void Game::DrawHealth() {

    PD::setColor(0);
    PD::fillRect(0, 81, 63, 6);
    PD::drawBitmap(1, 82, Images::Health);
    PD::setColor(8);
    PD::drawRect(7, 82, 54, 4);
    PD::drawLine(9, 84, 9 + player.getHealth() / 2, 84);

}


void Game::DrawHolding() {
  //sprites.drawExternalMask(98, 43 ,slots,SlotsMask, 0,0);

    PD::setColor(6);
    PD::drawBitmap(82, 69, Images::Keys_Main);
    PD::drawBitmap(82, 79, Images::Coins_Main);
    PD::setCursor(94, 70);
    if (player.getKeys() < 10)     PD::print("0");
    PD::print(player.getKeys(), 10);
    PD::setCursor(94, 80);
    if (player.getCoins() < 10)     PD::print("0");
    PD::print(player.getCoins(), 10);
    PD::drawBitmap(82, 69, Images::Keys_Outline);
    PD::drawBitmap(82, 79, Images::Coins_Outline);

}

void Game::DrawTime() {

    PD::drawBitmap(74, 0,Images::Time_Main);
    PD::setColor(6);
    PD::setCursor(87,1);

    if (Timer < 100)    PD::print("0");
    if (Timer < 10)     PD::print("0");

    PD::print(Timer, 10);
    PD::drawBitmap(74, 0, Images::Time_Outline);

}

void Game::DrawHud() {
  DrawHealth();
  DrawHolding();
  DrawTime();

    PD::setColor(0);
    PD::drawBitmap(0, 0, Images::Level_Main);
 
    PD::setColor(7);
    PD::setCursor(3,1);
      PD::print("L");
    PD::setCursor(10,1);

    if (Level < 10) {
      PD::print("0");
    }

    PD::print(Level, 10);
    PD::drawBitmap(0, 0, Images::Level_Outline);
}

void Game::RenderEnviroment()
{
  int tileX = getTileX(player.getX());
  int tileY = getTileY(player.getY());
  int offsetX = getTileXOffset(player.getX());
  int offsetY = getTileYOffset(player.getY());
    
  for (int i = -8; i < 8; i++)
  {
    for(int j = -8; j < 8; j++)
    {
      uint8_t block = getBlock(MAP_HEIGHT, MAP_WIDTH, tileX + i, tileY + j);
      
      int drawX = (i * 16) + CENTERX - offsetX;
      int drawY = (j * 16) + CENTERY - offsetY;
      PD::drawBitmap(drawX, drawY, Images::Tiles[block]);
    }
  }
}

void Game::RenderPlayer() {	
	const uint8_t PlayerFrames[] = { 0, 1, 0, 2 };
  if(!player.getMoving())
  {
    PD::drawBitmap(CENTERX - 4, CENTERY - 4, Images::Sprites[0]);
  }
  else
  {
    if(Pokitto::Core::frameCount % 5 == 0)
    {
      player.incFrame();
    }
    PD::drawBitmap(CENTERX - 4, CENTERY - 4, Images::Sprites[PlayerFrames[player.getFrame()]]);
  }
}