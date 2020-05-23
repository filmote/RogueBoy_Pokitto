#pragma once

#include "Pokitto.h"
#include "PokittoCookie.h"
#include "Structs.h"
#include "Enums.h"

class GameCookie : public Pokitto::Cookie {
    
    public:
    
    	uint8_t initialised;
        uint16_t score[5];
        uint8_t level[5];
		char score_Char[5][3];

        PlayerStatus playerStatus;
        uint8_t levelNo = 0;
        uint8_t definedMapLevel = 0;

	public:

		void initialise() {

			this->initialised = COOKIE_INITIALISED;

			this->score[0] = 50;
			this->score[1] = 40;
			this->score[2] = 30;
			this->score[3] = 20;
			this->score[4] = 10;

			for (uint8_t y = 0; y < 5; y++) {

				for (uint8_t x = 0; x < 3; x++) {
				
					this->score_Char[y][x] = 'A';
				
				}

				level[y] = 5 - y;

			}

            this->levelNo = 255;
			this->saveCookie();

		}

        void updateStatus(uint8_t level, uint8_t definedMapLevel, Player player) {

            this->levelNo = level;
            this->definedMapLevel = definedMapLevel;
            this->playerStatus = player.getPlayerStatus();

        }

        uint8_t getLevel() {

            return this->levelNo;
            
        }

        uint8_t getDefinedMapLevel() {

            return this->definedMapLevel;
            
        }

        PlayerStatus getPlayerStatus() {

            return this->playerStatus;
            
        }

};
