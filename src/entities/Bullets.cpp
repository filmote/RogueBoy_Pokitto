#include "Bullets.h"
#include "../images/Images.h"

Bullet & Bullets::getBullet(uint8_t index) {

    return this->bullets[index];
    
}

void Bullets::update() {

    this->frame++;
    this->frame = this->frame % 4;

    for (uint8_t j=0;j<6;j++) {

        auto &bullet = this->bullets[j];

        if (bullet.getActive()) {

            int16_t rx = bullet.getX();
            int16_t ry = bullet.getY();

            switch (bullet.getDirection()) {

                case Direction::Up: 
                    ry-=3; 
                    break;

                case Direction::UpRight: 
                    ry-=3; 
                    rx+=3; 
                    break;

                case Direction::Right: 
                    rx+=3; 
                    break;

                case Direction::DownRight: 
                    ry+=3; 
                    rx+=3; 
                    break;

                case Direction::Down: 
                    ry+=3; 
                    break;

                case Direction::DownLeft: 
                    ry+=3; 
                    rx-=3; 
                    break;

                case Direction::Left: 
                    rx-=3; 
                    break;

                case Direction::UpLeft: 
                    ry-=3; 
                    rx-=3; 
                    break;
            
            };

            bullet.setX(rx);
            bullet.setY(ry);

        }

    }

}

void Bullets::render(Player &player) {

    for (uint8_t j=0;j<6;j++) {

        auto bullet = this->bullets[j];

        if (bullet.getActive()) {

            int x = (player.getX() - bullet.getX());
            int y = (player.getY() - bullet.getY());

            PD::drawBitmap((CENTERX - 4) - x, (CENTERY - 4) - y, Images::Bullets[this->frame]);

        }

    }

}