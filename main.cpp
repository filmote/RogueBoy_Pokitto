#include "Pokitto.h"
#include "src/Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

Game game;

int main() {

    PC::begin();
    PD::loadRGBPalette(palettePico);   
    PD::persistence = true;
    PD::setColor(5);
    PD::setInvisibleColor(14);
    PC::setFrameRate(30);
    PD::setFont(fontKoubit);

    // Kick off the random number generator ..
    
    srand(time(0));

    game.setup();

    while( PC::isRunning() ) {

        if (!PC::update()) continue;
        game.loop();

    }
    
    return 0;
}
//https://felipemanga.github.io/PokittoEmu/?url=https://github.com/filmote/RogueBoy_Pokitto/raw/master/RogueBoy_Pokitto.bin