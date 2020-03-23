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

void MapInformation::decTimer() {
    this->timer--;
}

MapTiles MapInformation::getBlock(int16_t x, int16_t y) {


    if ((x < 0) || (x >= this->width) || (y< 0) || (y >= this->height)) {
        return MapTiles::Grass;
    } 
    else {
        MapTiles Block = static_cast<MapTiles>(this->mapData[(x + (y * this->width))]);
        return Block;
    }

}

void MapInformation::setBlock(uint8_t x, uint8_t y, MapTiles block) {

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


bool MapInformation::isWalkable(uint16_t x, uint16_t y) {
    
    MapTiles p[4];
    bool walk = true; 

    p[0] = (this->getBlock(this->getTileX(x-4), this->getTileY(y-4)));
    p[1] = (this->getBlock(this->getTileX(x+3), this->getTileY(y-4)));
    p[2] = (this->getBlock(this->getTileX(x-4), this->getTileY(y+3)));
    p[3] = (this->getBlock(this->getTileX(x+3), this->getTileY(y+3)));

    for (uint8_t i=0; i<4;i++) {

        if (!((p[i] == MapTiles::OpenDoor) || (p[i] == MapTiles::UpStairs) || (p[i] == MapTiles::DownStairs) || (p[i] == MapTiles::Empty) || (p[i] == MapTiles::OpenChest) || (p[i] == MapTiles::Rubble) || (p[i] == MapTiles::PressPlate))) {
            walk = false;
            break;
        }

    }

    return walk;
    
}