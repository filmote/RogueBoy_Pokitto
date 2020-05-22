#include "Pokitto.h"
#include <LibAudio>
#include "src/Game.h"
#include "src/utils/GameCookie.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;


Game game;
GameCookie cookie;
File mainThemeFile;

Audio::Sink<4, PROJ_AUD_FREQ> audio;

void init() {


    // Initialise pokitto ..

    cookie.begin("DarkRit", sizeof(cookie), (char*)&cookie);

    PD::loadRGBPalette(palettePico);   
    PD::persistence = true;
    PD::setColor(5);
    PD::setInvisibleColor(14);
    PC::setFrameRate(30);
    PD::setFont(fontKoubit);

    if (cookie.initialised != COOKIE_INITIALISED) {

        cookie.initialise();

    }

    // Kick off the random number generator ..
    
    srand(time(0));

    game.setup(&cookie);


    // if (mainThemeFile.openRO("music/darkrit1.raw")) {
    //     auto& music = Audio::play<2>(mainThemeFile);
    //     music.setLoop(true);
    // } 

}


void update() {

    game.loop();

}
//https://felipemanga.github.io/PokittoEmu/?url=https://github.com/filmote/RogueBoy_Pokitto/raw/master/RogueBoy_Pokitto.bin
/*
2 LeverPull.raw
3 OpenChest.raw
4 PickUpCoin.raw
*/