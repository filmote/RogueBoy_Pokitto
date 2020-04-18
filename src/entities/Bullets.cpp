#include "Bullets.h"
#include "../images/Images.h"

Bullet & Bullets::getBullet(uint8_t index) {

    return this->bullets[index];
    
}

Bullet & Bullets::getPlayerBullet(uint8_t index) {

    return this->bullets[index];
    
}

Bullet & Bullets::getEnemyBullet(uint8_t index) {

    return this->bullets[PLAYER_BULLET_MAX + index];
    
}


uint8_t Bullets::getInactivePlayerBullet() {

    for (uint8_t j = 0; j < PLAYER_BULLET_MAX; j++) {

        auto bullet = this->bullets[j];

        if (!bullet.getActive()) {

            return j;

        }

    }

    return NO_INACTIVE_BULLET_FOUND;

}

uint8_t Bullets::getInactiveEnemyBullet() {

    for (uint8_t j = PLAYER_BULLET_MAX; j < PLAYER_BULLET_MAX + ENEMY_BULLET_MAX; j++) {

        auto bullet = this->bullets[j];

        if (!bullet.getActive()) {

            return j - PLAYER_BULLET_MAX;

        }

    }

    return NO_INACTIVE_BULLET_FOUND;

}

void Bullets::render(Player &player) {

    for (uint8_t j = 0; j < PLAYER_BULLET_MAX + ENEMY_BULLET_MAX; j++) {

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

                case Object::RedSpell:
                    PD::drawBitmap((CENTERX - 4) - x, (CENTERY - 4) - y, Images::Bullets[bullet.getFrame() + 12]);
                    break;
                    
            }

        }

    }

}