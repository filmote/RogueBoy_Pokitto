#include "Pokitto.h"
#include "src/Game.h"
#include "src/utils/GameCookie.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

Game game;
GameCookie cookie;

int main() {


    // Initialise pokitto ..

    cookie.begin("DarkRit", sizeof(cookie), (char*)&cookie);


    PC::begin();
    PD::loadRGBPalette(palettePico);   
    PD::persistence = true;
    PD::setColor(5);
    PD::setInvisibleColor(14);
    PC::setFrameRate(30);
    PD::setFont(fontKoubit);

    // #if POK_HIGH_RAM == HIGH_RAM_MUSIC
    // memset(buffers[0], 128, BUFFER_SIZE);
    // memset(buffers[1], 128, BUFFER_SIZE);
    // memset(buffers[2], 128, BUFFER_SIZE);
    // memset(buffers[3], 128, BUFFER_SIZE);
    // #else
    // memset(&(buffers[0]), 128, BUFFER_SIZE);
    // memset(&(buffers[1]), 128, BUFFER_SIZE);
    // memset(&(buffers[2]), 128, BUFFER_SIZE);
    // memset(&(buffers[3]), 128, BUFFER_SIZE);
    // #endif

    if (cookie.initialised != COOKIE_INITIALISED) {

        cookie.initialise();

    }

    // Kick off the random number generator ..
    
    srand(time(0));

    game.setup(&cookie);

    while( PC::isRunning() ) {

        if (!PC::update()) continue;

        // PC::sound.updateStream();
        game.loop();

    }
    
    return 0;
}
//https://felipemanga.github.io/PokittoEmu/?url=https://github.com/filmote/RogueBoy_Pokitto/raw/master/RogueBoy_Pokitto.bin