#include "Bullets.h"
#include "../images/Images.h"

Bullet & Bullets::getBullet(uint8_t index) {

    return this->bullets[index];
    
}


void Bullets::render(Player &player) {

    for (uint8_t j=0;j<6;j++) {

        auto bullet = this->bullets[j];

        if (bullet.getActive()) {

            int x = (player.getX() - bullet.getX());
            int y = (player.getY() - bullet.getY());

            PD::drawBitmap((CENTERX - 4) - x, (CENTERY - 4) - y, Images::Bullets[bullet.getFrame()]);

        }

    }

}