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

            switch (bullet.getWeapon()) {

                case Object::FireBall:
                    PD::drawBitmap((CENTERX - 4) - x, (CENTERY - 4) - y, Images::Bullets[bullet.getFrame()]);
                    break;

                case Object::IceSpell:
                    PD::drawBitmap((CENTERX - 4) - x, (CENTERY - 4) - y, Images::Bullets[bullet.getFrame() + 4]);
                    break;

                case Object::GreenSpell:
                    PD::drawBitmap((CENTERX - 4) - x, (CENTERY - 4) - y, Images::Bullets[bullet.getFrame() + 8]);
                    break;

                case Object::YellowSpell:
                    PD::drawBitmap((CENTERX - 4) - x, (CENTERY - 4) - y, Images::Bullets[bullet.getFrame() + 12]);
                    break;
                    
            }

        }

    }

}