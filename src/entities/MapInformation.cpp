#include "MapInformation.h"
#include "../utils/Enums.h"

uint8_t MapInformation::getLevel() {
    return this->level;
}

uint16_t MapInformation::getWidth() {
    return this->width;
}

uint16_t MapInformation::getHeight() {
    return this->height;
}

uint16_t MapInformation::getTimer() {
    return this->timer;
}

bool MapInformation::getRandomLevel() {
    return this->randomLevel;
}

uint8_t MapInformation::getRandomLow() {
    return this->randomLow;
}

void MapInformation::setLevel(uint8_t level) {
    this->level = level;
}

void MapInformation::setWidth(uint16_t width) {
    this->width = width;
}

void MapInformation::setHeight(uint16_t height) {
    this->height = height;
}

void MapInformation::setTimer(uint16_t timer) {
    this->timer = timer;
}

void MapInformation::setRandomLevel(bool randomLevel) {
    this->randomLevel = randomLevel;
}

void MapInformation::setRandomLow(uint8_t randomLow) {
    this->randomLow = randomLow;
}

void MapInformation::decTimer() {
    //SJH 
    this->timer--;
}

MapTiles MapInformation::getBlock(int16_t x, int16_t y) {


    if ((x < 0) || (x >= this->width) || (y< 0) || (y >= this->height)) {
        return MapTiles::Fill;
    } 
    else {
        MapTiles Block = static_cast<MapTiles>(this->mapData[(x + (y * this->width))]);
        return Block;
    }

}

void MapInformation::setBlock(uint16_t x, uint16_t y, MapTiles block) {

    if ((x >= this->width) || (y >= this->height)) {
        return;
    }
    this->mapData[x + (y * (this->width))] = static_cast<uint8_t>(block);

}

void MapInformation::setBlock(uint16_t index, MapTiles block) {

    if (index > (this->height * this->width)) {
        return;
    }
    this->mapData[index] = static_cast<uint8_t>(block);

}

void MapInformation::swap(uint8_t & a, uint8_t & b) {

    uint8_t t = a;
    a = b;
    b = t;

}

bool MapInformation::between(uint8_t x, uint8_t y, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {

    if (x > x1)     swap(x, x1);
    if (y > y1)     swap(y, y1);
        
    return ((x <= x2) && (x2 <= x1) && (y <= y2) && (y2 <= y1));

}

int8_t MapInformation::getTileX(uint16_t x) {
    
    return (x / TILE_WIDTH);

}

uint8_t MapInformation::getTileY(uint16_t y) {
    
    return (y / TILE_HEIGHT);

}

uint8_t MapInformation::getTileXOffset(uint16_t x) {
    
    return (x % TILE_WIDTH);

}

uint8_t MapInformation::getTileYOffset(uint16_t y) {
    
    return (y % TILE_HEIGHT);

}

uint16_t MapInformation::getDistance(int x,int y,int x1,int y1) {
    
    uint16_t ret = (abs(this->getTileX(x) - this->getTileX(x1)) + abs(this->getTileY(y) - this->getTileY(y1))); 
    return ret;
    
}

uint8_t MapInformation::getOffset(uint8_t x, uint8_t y) {

    if ((x >= this->width) || (y >= this->height)) {
        return 0;
    }
    return (x + (y * (this->width)));

}

void MapInformation::clearMap() {

    for (uint32_t x = 0; x < MAP_SIZE; x ++) {

        this->mapData[x] = MapTiles::Fill;

    }

}

WalkType MapInformation::isWalkable(uint16_t x, uint16_t y, Direction direction, uint8_t width, uint8_t height) {

    MapTiles tile1 = MapTiles::Empty;
    MapTiles tile2 = MapTiles::Empty;
    int16_t xMod = x % 16;
    int16_t yMod = y % 16;

    uint8_t widthHalf = width / 2;
    uint8_t heightHalf = height / 2;
    
    WalkType walk = WalkType::Normal; 

    switch (direction) {

        case Direction::Up:
            // printf("Up (%i,%i) %i,%i > %i,%i > %i,%i .. ", x, y, this->getTileX(x), this->getTileY(y), this->getTileX(x - widthHalf), this->getTileY(y - heightHalf), this->getTileX(x - widthHalf+ 16), this->getTileY(y - heightHalf));        
            // printf("x=%i %% 16 = %i .. ", x, ((x - widthHalf) % 16) + width);        
            tile1 = this->getBlock(this->getTileX(x - widthHalf), this->getTileY(y - heightHalf));
            if (((x - widthHalf) % 16) + width > 16) tile2 = this->getBlock(this->getTileX(x - widthHalf + 16), this->getTileY(y - heightHalf));
            // printf("%i %i ", tile1, tile2);
            break;

        case Direction::Right:
            // printf("Right (%i,%i) %i,%i > %i,%i > %i,%i .. ", x, y, this->getTileX(x), this->getTileY(y), this->getTileX(x + widthHalf - 1), this->getTileY(y - heightHalf), this->getTileX(x + widthHalf - 1), this->getTileY(y - heightHalf + 16));        
            // printf("y=%i %% 16 = %i .. ", y, ((y - heightHalf) % 16) + height);        
            tile1 = this->getBlock(this->getTileX(x + widthHalf - 1), this->getTileY(y - heightHalf));
            if (((y - heightHalf) % 16) + height > 16) tile2 = this->getBlock(this->getTileX(x + widthHalf - 1), this->getTileY(y - heightHalf + 16)); 
            // printf("%i %i ", tile1, tile2);
            break;

        case Direction::Down:
            // printf("Down (%i,%i) %i,%i > %i,%i > %i,%i .. ", x, y, this->getTileX(x), this->getTileY(y), this->getTileX(x - widthHalf), this->getTileY(y + heightHalf - 1), this->getTileX(x - widthHalf+ 16), this->getTileY(y + heightHalf - 1));        
            // printf("y=%i %% 16 = %i .. ", y, ((x - widthHalf) % 16) + width);        
            tile1 = this->getBlock(this->getTileX(x - widthHalf), this->getTileY(y + heightHalf - 1));
            if (((x - widthHalf) % 16) + width > 16) tile2 = this->getBlock(this->getTileX(x - widthHalf + 16), this->getTileY(y + heightHalf - 1));
            // printf("%i %i ", tile1, tile2);
            break;

        case Direction::Left:
// if (width == 12) {
//             printf("Left (%i,%i) %i,%i > %i,%i > %i,%i .. ", x, y, this->getTileX(x), this->getTileY(y), this->getTileX(x - widthHalf), this->getTileY(y - heightHalf), this->getTileX(x - widthHalf), this->getTileY(y - heightHalf + 16));        
//             printf("y=%i %% 16 = %i .. ", y, ((y - heightHalf) % 16) + height);        
// }
            tile1 = this->getBlock(this->getTileX(x - widthHalf), this->getTileY(y - heightHalf));
            if (((y - heightHalf) % 16) + height > 16) tile2 = this->getBlock(this->getTileX(x - widthHalf), this->getTileY(y - heightHalf + 16));
// if (width == 12) {
//             printf("%i %i \n", tile1, tile2);
// }
            break;

            
    }

    switch (tile1) {

        case MapTiles::OpenDoor:
        case MapTiles::UpStairs:
        case MapTiles::DownStairs:
        case MapTiles::Empty:
        case MapTiles::OpenChest:
        case MapTiles::Rubble:
        case MapTiles::PressPlate:
        case MapTiles::DoorLHSOpen:
        case MapTiles::DoorRHSOpen:
        case MapTiles::DoorTOPOpen:
        case MapTiles::DoorBOTOpen:
        case MapTiles::SpearDoorLHSOpen:
        case MapTiles::SpearDoorRHSOpen:
        case MapTiles::SpearDoorTOPOpen:
        case MapTiles::SpearDoorBOTOpen:
        case MapTiles::WormHole_F0:
            walk = WalkType::Normal;
            break;

        case MapTiles::Shop03 ... MapTiles::Shop05:

            switch (direction) {

                case Direction::Up:
                    yMod = (y - widthHalf) % 16;
                    // printf("Shop1 U %i %i\n", xMod, yMod);
                    walk = ((yMod == 0) || (yMod > 8) ? WalkType::Normal : WalkType::Stop);
                    break;

                case Direction::Left:
                    xMod = (x - widthHalf) % 16;
                    yMod = (y - widthHalf) % 16;
                    // printf("Shop1 L %i %i\n", xMod, yMod);
                    walk = ((xMod > 10 && yMod <= 8) || (yMod > 8) ? WalkType::Normal : WalkType::Stop);
                    break;

                case Direction::Right:
                    xMod = (x + widthHalf) % 16;
                    yMod = (y - widthHalf) % 16;
                    // printf("Shop1 R %i %i\n", xMod, yMod);
                    walk = ((xMod <= 6 && yMod <= 8) || (yMod > 8) ? WalkType::Normal : WalkType::Stop);
                    break;

            }

            break;
            
        case MapTiles::Barrel:

            switch (direction) {

                case Direction::Left:
                    xMod = (x - widthHalf) % 16;
                    yMod = (y - widthHalf) % 16;
                    // printf("BAR1 L %i %i\n", xMod, yMod);
                    walk = ((xMod > 10) || (yMod == 0) ? WalkType::Normal : WalkType::Stop);
                    break;

                case Direction::Right:
                    xMod = (x + widthHalf) % 16;
                    yMod = (y - widthHalf) % 16;
                    // printf("BAR1 R %i %i\n", xMod, yMod);
                    walk = ((xMod < 6) || (yMod == 0) ? WalkType::Normal : WalkType::Stop);
                    break;

                case Direction::Up:
                    xMod = (x - widthHalf) % 16;
                    yMod = (y - widthHalf) % 16;
                    // printf("BAR1 U %i %i\n", xMod, yMod);
                    walk = ((xMod >= 12) || (yMod < 4) ? WalkType::Normal : WalkType::Stop);
                    break;

                case Direction::Down:
                    xMod = (x - widthHalf) % 16;
                    yMod = (y + widthHalf) % 16;
                    // printf("BAR1 D %i %i\n", xMod, yMod);
                    walk = ((xMod >= 12) || (yMod == 0) ? WalkType::Normal : WalkType::Stop);
                    break;
                
            }

            break;        

        case MapTiles::StraightTOP:
        case MapTiles::StraightBOT:
        case MapTiles::StraightTorchTOP_F0:
        case MapTiles::StraightTorchTOP_F1:
        case MapTiles::StraightTorchBOT_F0:
        case MapTiles::StraightTorchBOT_F1:

            switch (direction) {

                case Direction::Left:
                case Direction::Right:
                    walk = WalkType::Normal;
                    break;

                default:
                    walk = WalkType::Stop;
                    break;
                
            }

            break;

        case MapTiles::StraightLHS:
        case MapTiles::StraightTorchLHS_F0:
        case MapTiles::StraightTorchLHS_F1:
        case MapTiles::StraightRHS:
        case MapTiles::StraightTorchRHS_F0:
        case MapTiles::StraightTorchRHS_F1:

            switch (direction) {

                case Direction::Up:
                case Direction::Down:
                    walk = WalkType::Normal;
                    break;

                default:
                    walk = WalkType::Stop;
                    break;
                
            }

            break;

        case MapTiles::DoorTOP:
        case MapTiles::SpearDoorTOP:

            switch (direction) {
                
                case Direction::Down:
                    walk = WalkType::Stop;
                    break;

                case Direction::Up:
                    yMod = (y - widthHalf) % 16;
                    walk = ((yMod == 0) || (yMod > 6) ? WalkType::Normal : WalkType::Stop);
                    break;

                default:
                    walk = WalkType::Normal;
                    break;
                
            }

            break;

        case MapTiles::DoorBOT:
        case MapTiles::SpearDoorBOT:

            switch (direction) {

                case Direction::Up:
                    walk = WalkType::Stop;
                    break;

                case Direction::Down:
                    yMod = (y - widthHalf) % 16;
                    walk = ((yMod == 0) || (yMod > 6) ? WalkType::Normal : WalkType::Stop);
                    break;

                default:
                    walk = WalkType::Normal;
                    break;
                
            }

            break;

        case MapTiles::DoorLHS:
        case MapTiles::SpearDoorLHS:

            switch (direction) {

                case Direction::Left:
                    xMod = (x - widthHalf) % 16;
                    walk = ((xMod > 6) ? WalkType::Normal : WalkType::Stop);
                    break;

                case Direction::Right:
                    xMod = (y - widthHalf) % 16;
                    walk = ((xMod == 0) || (xMod > 6) ? WalkType::Normal : WalkType::Stop);
                    break;

                default:
                    walk = WalkType::Normal;
                    break;
                
            }

            break;

        case MapTiles::DoorRHS:
        case MapTiles::SpearDoorRHS:

            switch (direction) {

                case Direction::Left:
                    xMod = (x - widthHalf) % 16;
                    walk = ((xMod < 14) ? WalkType::Normal : WalkType::Stop);
                    break;

                case Direction::Right:
                    xMod = (x + widthHalf) % 16;
                    walk = ((xMod < 12) ? WalkType::Normal : WalkType::Stop);
                    break;

                default:
                    walk = WalkType::Normal;
                    break;
                
            }

            break;

        case MapTiles::CornerLL:

            switch (direction) {

                case Direction::Down:
                case Direction::Left:
                    walk = WalkType::Normal;
                    break;

                default:
                    walk = WalkType::Stop;
                    break;
                
            }

            break;

        case MapTiles::CornerLR:

            switch (direction) {

                case Direction::Down:
                case Direction::Right:
                    walk = WalkType::Normal;
                    break;

                default:
                    walk = WalkType::Stop;
                    break;
                
            }

            break;

        case MapTiles::CornerTL:

            switch (direction) {

                case Direction::Up:
                case Direction::Left:
                    walk = WalkType::Normal;
                    break;

                default:
                    walk = WalkType::Stop;
                    break;
                
            }

            break;

        case MapTiles::CornerTR:

            switch (direction) {

                case Direction::Up:
                case Direction::Right:
                    walk = WalkType::Normal;
                    break;

                default:
                    walk = WalkType::Stop;
                    break;
                
            }

            break;

        case MapTiles::TriangleTL:
            xMod = (x - widthHalf) % 16;
            yMod = (y - heightHalf) % 16;

            switch (direction) {

                case Direction::Left:
                    // printf("%i, %i > %i\n", xMod, yMod, xMod + yMod);
                    if (xMod + yMod >= 16) {
                        walk = WalkType::Normal;
                    }
                    else {
                        walk = WalkType::Stop;
                    }
                    break;

                case Direction::Up:
                    // printf("NULT:1 %i, %i > %i\n", xMod, yMod, xMod + yMod);
                    if (xMod + yMod >= 16) {
                        walk = WalkType::Normal;
                    }
                    else {
                        walk = WalkType::Stop;
                    }
                    break;

                default:
                    walk = WalkType::Normal;

            }
            break;

        case MapTiles::TriangleTR:

            switch (direction) {

                case Direction::Right:
                    xMod = (x + widthHalf) % 16;
                    yMod = (y + heightHalf) % 16;
                                // printf("UR-R1 %i, %i > %i\n", xMod - 2, yMod, xMod + yMod);
                    if (xMod - 2 < yMod) {
                        walk = WalkType::Normal;
                    }
                    else {
                        walk = WalkType::Stop;
                    }
                    break;

                case Direction::Up:
                    xMod = (x + widthHalf) % 16;
                    yMod = (y - heightHalf) % 16;
                    // printf("UR-U1 %i, %i > %i\n", xMod, yMod, xMod + yMod);
                    if (xMod!= 0 && xMod <= yMod) {
                        walk = WalkType::Normal;
                    }
                    else {
                        walk = WalkType::Stop;
                    }
                    break;

                default:
                    walk = WalkType::Normal;
                    break;

            }
            break;

        case MapTiles::TriangleLL:
            xMod = (x - widthHalf) % 16;
            yMod = (y + heightHalf) % 16;

            switch (direction) {

                case Direction::Left:
                    // printf("LL-R1 %i, %i > %i\n", xMod, yMod, xMod + yMod);
                    if (yMod != 0 && xMod >= yMod) {
                        walk = WalkType::Normal;
                    }
                    else {
                        walk = WalkType::Stop;
                    }
                    break;

                case Direction::Down:
                    // printf("LL-D1 %i, %i > %i\n", xMod, yMod, xMod + yMod);
                    if (xMod >= yMod) {
                        walk = WalkType::Normal;
                    }
                    else {
                        walk = WalkType::Stop;
                    }
                    break;

                default:
                    walk = WalkType::Normal;
                    break;

            }
            break;

        case MapTiles::TriangleLR:
            xMod = (x + widthHalf) % 16;
            yMod = (y + heightHalf) % 16;

            switch (direction) {

                case Direction::Right:
                    // printf("LR-R1 %i, %i > %i\n", xMod, yMod, xMod + yMod);
                    if (yMod != 0 && xMod + yMod <= 16) {
                        walk = WalkType::Normal;
                    }
                    else {
                        walk = WalkType::Stop;
                    }
                    break;

                case Direction::Down:
                    // printf("LR-D1 %i, %i > %i\n", xMod, yMod, xMod + yMod);
                    if (xMod != 0 && xMod + yMod <= 16) {
                        walk = WalkType::Normal;
                    }
                    else {
                        walk = WalkType::Stop;
                    }
                    break;

                default:
                    walk = WalkType::Normal;
                    break;

            }
            break;

        case MapTiles::SpiderWebTL:
            xMod = (x - widthHalf) % 16;
            yMod = (y - heightHalf) % 16;

            switch (direction) {

                case Direction::Left:
                case Direction::Right:
                    // printf("SWTL1_L %i, %i > %i\n", xMod, yMod, xMod + yMod);
                    if (xMod + yMod >= 18) {
                        walk = WalkType::Normal;
                    }
                    else {
                        walk = WalkType::Slow;
                    }
                    break;

                case Direction::Up:
                case Direction::Down:
                    // printf("SWTL1_U %i, %i > %i\n", xMod, yMod, xMod + yMod);
                    if (xMod + yMod >= 18) {
                        walk = WalkType::Normal;
                    }
                    else {
                        walk = WalkType::Slow;
                    }
                    break;

                default:
                    walk = WalkType::Normal;

            }
            break;

        case MapTiles::SpiderWebTR:

            switch (direction) {

                case Direction::Left:
                case Direction::Right:
                    xMod = (x + widthHalf) % 16;
                    yMod = (y - heightHalf) % 16;
                    // printf("SWTR1_R %i, %i > %i\n", xMod - 2, yMod, xMod + yMod);
                    if (xMod - 4 < yMod) {
                        walk = WalkType::Normal;
                    }
                    else {
                        walk = WalkType::Slow;
                    }
                    break;

                case Direction::Up:
                case Direction::Down:
                    xMod = (x + widthHalf) % 16;
                    yMod = (y - heightHalf) % 16;
                    // printf("SWTR1_U %i, %i > %i\n", xMod, yMod, xMod + yMod);
                    if (xMod!= 0 && xMod < yMod) {
                        walk = WalkType::Normal;
                    }
                    else {
                        walk = WalkType::Slow;
                    }
                    break;

                default:
                    walk = WalkType::Normal;
                    break;

            }
            break;

        case MapTiles::SpiderWebLL:
            xMod = (x - widthHalf) % 16;
            yMod = (y + heightHalf) % 16;

            switch (direction) {

                case Direction::Left:
                case Direction::Right:
                    // printf("LL-R1 %i, %i > %i\n", xMod, yMod, xMod + yMod);
                    if (yMod != 0 && xMod >= yMod) {
                        walk = WalkType::Normal;
                    }
                    else {
                        walk = WalkType::Slow;
                    }
                    break;

                case Direction::Up:
                case Direction::Down:
                    // printf("LL-D1 %i, %i > %i\n", xMod, yMod, xMod + yMod);
                    if (xMod >= yMod) {
                        walk = WalkType::Normal;
                    }
                    else {
                        walk = WalkType::Slow;
                    }
                    break;

                default:
                    walk = WalkType::Normal;
                    break;

            }
            break;

        case MapTiles::SpiderWebLR:
            xMod = (x + widthHalf) % 16;
            yMod = (y + heightHalf) % 16;

            switch (direction) {

                case Direction::Left:
                case Direction::Right:
                    // printf("LR-R1 %i, %i > %i\n", xMod, yMod, xMod + yMod);
                    if (yMod != 0 && xMod + yMod <= 16) {
                        walk = WalkType::Normal;
                    }
                    else {
                        walk = WalkType::Slow;
                    }
                    break;

                case Direction::Up:
                case Direction::Down:
                    // printf("LR-D1 %i, %i > %i\n", xMod, yMod, xMod + yMod);
                    if (xMod != 0 && xMod + yMod <= 16) {
                        walk = WalkType::Normal;
                    }
                    else {
                        walk = WalkType::Slow;
                    }
                    break;

                default:
                    walk = WalkType::Normal;
                    break;

            }
            break;

        default:
            walk = WalkType::Stop;
            break;
        
    }

    if (walk != WalkType::Stop) {

        switch (tile2) {

            case MapTiles::OpenDoor:
            case MapTiles::UpStairs:
            case MapTiles::DownStairs:
            case MapTiles::Empty:
            case MapTiles::OpenChest:
            case MapTiles::Rubble:
            case MapTiles::PressPlate:
            case MapTiles::DoorLHSOpen:
            case MapTiles::DoorRHSOpen:
            case MapTiles::DoorTOPOpen:
            case MapTiles::DoorBOTOpen:
            case MapTiles::SpearDoorLHSOpen:
            case MapTiles::SpearDoorRHSOpen:
            case MapTiles::SpearDoorTOPOpen:
            case MapTiles::SpearDoorBOTOpen:
            case MapTiles::WormHole_F0:
                // walk = WalkType::Normal;
                break;

            case MapTiles::StraightTOP:
            case MapTiles::StraightBOT:
            case MapTiles::StraightTorchTOP_F0:
            case MapTiles::StraightTorchTOP_F1:
            case MapTiles::StraightTorchBOT_F0:
            case MapTiles::StraightTorchBOT_F1:

                switch (direction) {

                    case Direction::Left:
                    case Direction::Right:
                        // walk = WalkType::Normal;
                        break;

                    default:
                        walk = WalkType::Stop;
                        break;
                    
                }

                break;

            case MapTiles::Shop03 ... MapTiles::Shop05:

                switch (direction) {

                    case Direction::Up:
                        yMod = (y - widthHalf) % 16;
                        // printf("Shop2 U %i %i\n", xMod, yMod);
                        walk = ((yMod == 0) || (yMod > 8) ? walk : WalkType::Stop);
                        break;

                    case Direction::Left:
                        xMod = (x - widthHalf) % 16;
                        yMod = (y + widthHalf) % 16;
                        // printf("Shop2 L %i %i\n", xMod, yMod);
                        walk = ((xMod > 10 && yMod <= 8) || (yMod > 8) ? walk : WalkType::Stop);
                        break;

                    case Direction::Right:
                        xMod = (x + widthHalf) % 16;
                        yMod = (y + widthHalf) % 16;
                        // printf("Shop2 R %i %i\n", xMod, yMod);
                        walk = ((xMod <= 6 && yMod <= 8) || (yMod > 8) ? walk : WalkType::Stop);
                        break;

                }

                break;

            case MapTiles::Barrel:

                switch (direction) {

                    case Direction::Left:
                        xMod = (x - widthHalf) % 16;
                        yMod = (y - widthHalf) % 16;
                        // printf("BAR2 L %i %i\n", xMod, yMod);
                        walk = ((xMod > 10) || (yMod == 8) ? walk : WalkType::Stop);
                        break;

                    case Direction::Right:
                        xMod = (x + widthHalf) % 16;
                        yMod = (y - widthHalf) % 16;
                        // printf("BAR2 R %i %i\n", xMod, yMod);
                        walk = ((xMod < 6) || (yMod == 8) ? walk : WalkType::Stop);
                        break;

                    case Direction::Up:
                        xMod = (x + widthHalf) % 16;
                        yMod = (y - widthHalf) % 16;
                        // printf("BAR2 U %i %i\n", xMod, yMod);
                        walk = ((xMod <= 4) || (yMod < 4) ? walk : WalkType::Stop);
                        break;

                    case Direction::Down:
                        xMod = (x + widthHalf) % 16;
                        yMod = (y + widthHalf) % 16;
                        // printf("BAR2 D %i %i\n", xMod, yMod);
                        walk = ((xMod <= 4) || (yMod < 4) ? walk : WalkType::Stop);
                        break;
                    
                }

                break;

            case MapTiles::StraightLHS:
            case MapTiles::StraightTorchLHS_F0:
            case MapTiles::StraightTorchLHS_F1:
            case MapTiles::StraightRHS:
            case MapTiles::StraightTorchRHS_F0:
            case MapTiles::StraightTorchRHS_F1:

                switch (direction) {

                    case Direction::Up:
                    case Direction::Down:
                        // walk = WalkType::Normal;
                        break;

                    default:
                        walk = WalkType::Stop;
                        break;
                    
                }

                break;
                
            case MapTiles::DoorTOP:
            case MapTiles::SpearDoorTOP:

                switch (direction) {
                
                    case Direction::Down:
                        walk = WalkType::Stop;
                        break;
                        
                    case Direction::Up:
                        yMod = (y - widthHalf) % 16;
                        walk = ((yMod == 0) || (yMod > 6) ? walk : WalkType::Stop);
                        break;

                    default:
                        // walk = WalkType::Normal;
                        break;
                    
                }

                break;

            case MapTiles::DoorBOT:
            case MapTiles::SpearDoorBOT:

                switch (direction) {

                    case Direction::Up:
                        walk = WalkType::Stop;
                        break;

                    case Direction::Down:
                        yMod = (y - widthHalf) % 16;
                        walk = ((yMod == 0) || (yMod > 6) ? walk : WalkType::Stop);
                        break;

                    default:
                        // walk = WalkType::Normal;
                        break;
                    
                }

                break;

            case MapTiles::DoorLHS:
            case MapTiles::SpearDoorLHS:

                switch (direction) {

                    case Direction::Left:
                        xMod = (x - widthHalf) % 16;
                        walk = ((xMod > 2) ? walk : WalkType::Stop);
                        break;

                    case Direction::Right:
                        xMod = (y - widthHalf) % 16;
                        walk = ((xMod == 0) || (xMod > 6) ? walk: WalkType::Stop);
                        break;
                        
                    default:
                        // walk = WalkType::Normal;
                        break;
                    
                }

                break;

            case MapTiles::DoorRHS:
            case MapTiles::SpearDoorRHS:

                switch (direction) {

                    case Direction::Left:
                        xMod = (x - widthHalf) % 16;
                        walk = ((xMod < 14) ? walk : WalkType::Stop);
                        break;

                    case Direction::Right:
                        xMod = (x + widthHalf) % 16;
                        walk = ((xMod < 12) ? walk : WalkType::Stop);
                        break;

                    default:
                        // walk = WalkType::Normal;
                        break;
                    
                }

                break;
                    
            case MapTiles::CornerLL:

                switch (direction) {

                    case Direction::Down:
                    case Direction::Left:
                        // walk = WalkType::Normal;
                        break;

                    default:
                        walk = WalkType::Stop;
                        break;
                    
                }

                break;

            case MapTiles::CornerLR:

                switch (direction) {

                    case Direction::Down:
                    case Direction::Right:
                        // walk = WalkType::Normal;
                        break;

                    default:
                        walk = WalkType::Stop;
                        break;
                    
                }

                break;

            case MapTiles::CornerTL:

                switch (direction) {

                    case Direction::Up:
                    case Direction::Left:
                        // walk = WalkType::Normal;
                        break;

                    default:
                        walk = WalkType::Stop;
                        break;
                    
                }

                break;

            case MapTiles::CornerTR:

                switch (direction) {

                    case Direction::Up:
                    case Direction::Right:
                        // walk = WalkType::Normal;
                        break;

                    default:
                        walk = WalkType::Stop;
                        break;
                    
                }

                break;

            case MapTiles::TriangleTL:
                    // walk = WalkType::Normal;
                    break;

            case MapTiles::TriangleTR:
                xMod = (x + widthHalf) % 16;
                yMod = (y - heightHalf) % 16;

                switch (direction) {

                    case Direction::Up:
                        // printf("UR-U2 %i, %i > %i\n", xMod, yMod, xMod + yMod);
                        if (xMod - 2 < yMod) {
                            // walk = WalkType::Normal;
                        }
                        else {
                            walk = WalkType::Stop;
                        }
                        break;

                    default:
                        // walk = WalkType::Normal;
                        break;

                }
                break;

            case MapTiles::TriangleLL:
                // printf("ll\n");
                xMod = (x - widthHalf) % 16;
                yMod = (y + heightHalf) % 16;

                switch (direction) {

                    case Direction::Left:
                        // printf("LL-L2 %i, %i > %i\n", xMod, yMod, xMod + yMod);
                        if (xMod >= yMod) {
                            // walk = WalkType::Normal;
                        }
                        else {
                            walk = WalkType::Stop;
                        }
                        break;

                    default:
                        // walk = WalkType::Normal;
                        break;

                }
                break;

            case MapTiles::TriangleLR:
                // printf("up\n");
                xMod = (x + widthHalf) % 16;
                yMod = (y + heightHalf) % 16;

                switch (direction) {

                    case Direction::Right:
                        // printf("LR-R2 %i, %i > %i\n", xMod, yMod, xMod + yMod);
                        if (xMod + yMod <= 16) {
                            // walk = WalkType::Normal;
                        }
                        else {
                            walk = WalkType::Stop;
                        }
                        break;

                    case Direction::Down:
                        // printf("LR-D2 %i, %i > %i\n", xMod, yMod, xMod + yMod);
                        if (xMod + yMod <= 16) {
                            // walk = WalkType::Normal;
                        }
                        else {
                            walk = WalkType::Stop;
                        }
                        break;

                    default:
                        // walk = WalkType::Normal;
                        break;

                }
                break;


            case MapTiles::SpiderWebTL:
                xMod = (x - widthHalf) % 16;
                yMod = (y - heightHalf) % 16;

                switch (direction) {

                    case Direction::Left:
                    case Direction::Right:
                        // printf("SWTL2_L %i, %i > %i\n", xMod, yMod, xMod + yMod);
                        if (xMod + yMod >= 18) {
                            walk = WalkType::Normal;
                        }
                        else {
                            walk = WalkType::Slow;
                        }
                        break;

                    default:
                        walk = WalkType::Normal;

                }
                break;

            case MapTiles::SpiderWebTR:

                switch (direction) {

                    case Direction::Left:
                    case Direction::Right:
                        xMod = (x + widthHalf) % 16;
                        yMod = (y - heightHalf) % 16;
                        // printf("SWTR2_R %i, %i > %i\n", xMod - 2, yMod, xMod + yMod);
                        if (xMod - 4 < yMod) {
                            walk = WalkType::Normal;
                        }
                        else {
                            walk = WalkType::Slow;
                        }
                        break;

                    default:
                        walk = WalkType::Normal;
                        break;

                }
                break;

            case MapTiles::SpiderWebLL:
                xMod = (x - widthHalf) % 16;
                yMod = (y + heightHalf) % 16;

                switch (direction) {

                    case Direction::Left:
                    case Direction::Right:
                        // printf("SWLL2_L %i, %i > %i\n", xMod, yMod, xMod + yMod);
                        if (yMod != 0 && xMod >= yMod) {
                            walk = WalkType::Normal;
                        }
                        else {
                            walk = WalkType::Slow;
                        }
                        break;

                    case Direction::Up:
                    case Direction::Down:
                        // printf("SWLL2_D %i, %i > %i\n", xMod, yMod, xMod + yMod);
                        if (xMod >= yMod) {
                            walk = WalkType::Normal;
                        }
                        else {
                            walk = WalkType::Slow;
                        }
                        break;

                    default:
                        walk = WalkType::Normal;
                        break;

                }
                break;

            case MapTiles::SpiderWebLR:
                xMod = (x + widthHalf) % 16;
                yMod = (y + heightHalf) % 16;

                switch (direction) {

                    case Direction::Left:
                    case Direction::Right:
                        // printf("SWLLR_R %i, %i > %i\n", xMod, yMod, xMod + yMod);
                        if (yMod != 0 && xMod + yMod <= 16) {
                            walk = WalkType::Normal;
                        }
                        else {
                            walk = WalkType::Slow;
                        }
                        break;

                    case Direction::Up:
                    case Direction::Down:
                        // printf("SWLLR_D %i, %i > %i\n", xMod, yMod, xMod + yMod);
                        if (xMod != 0 && xMod + yMod <= 16) {
                            walk = WalkType::Normal;
                        }
                        else {
                            walk = WalkType::Slow;
                        }
                        break;

                    default:
                        walk = WalkType::Normal;
                        break;

                }
                break;

            default:
                walk = WalkType::Stop;
                break;
            
        }

    }

    // printf(" -----> %i\n", walk);
    return walk;

    
}
