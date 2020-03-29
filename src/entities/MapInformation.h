#pragma once

#include "Pokitto.h"
#include "../utils/Enums.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

class MapInformation {

    public:

        MapTiles getBlock(int16_t x, int16_t y);
        uint8_t getLevel();
        uint16_t getWidth();
        uint16_t getHeight();
        uint16_t getTimer();
        int8_t getTileX(uint16_t x);
        uint8_t getTileY(uint16_t y);
        uint8_t getTileXOffset(uint16_t x);
        uint8_t getTileYOffset(uint16_t y);
        uint16_t getDistance(int x,int y,int x1,int y1);
        uint8_t getOffset(uint8_t x, uint8_t y);

        void setLevel(uint8_t level);
        void setWidth(uint16_t width);
        void setHeight(uint16_t height);
        void setTimer(uint16_t timer);
        void setBlock(uint8_t x, uint8_t y, MapTiles block);
        void setBlock(uint16_t index, MapTiles block);
        bool between(uint8_t x, uint8_t y, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
        bool isWalkable(uint16_t x, uint16_t y, Direction direction, uint8_t width, uint8_t height);

        void decTimer();


    private:       

        void swap(uint8_t & a, uint8_t & b);

    private:       

        uint16_t width = 15;
        uint16_t height = 15;
        uint16_t timer = 255;
        uint8_t level = 0;
        uint8_t mapData[MAP_SIZE];

};