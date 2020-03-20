#pragma once

#include "Pokitto.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

struct MapInformation {

    uint16_t width = 15;
    uint16_t height = 15;
    uint8_t level = 0;
    uint8_t mapData[MAP_SIZE];

    uint8_t getBlock(uint16_t x, uint16_t y) {
        if ((x >= this->width) || (y >= this->height)) {
            return BLANK_WALL;
        } 
        else {
            uint8_t Block = this->mapData[(x + (y * this->width))];
            return Block;
        }
    }

    void setBlock(uint8_t x, uint8_t y, uint8_t block) {
        if ((x >= this->width) || (y >= this->height)) {
            return;
        }
        this->mapData[(x + (y * (this->width)))] = block;
    }

    void setBlock(uint16_t index, uint8_t block) {
        if (index > (this->height * this->width)) {
            return;
        }
        this->mapData[index] = block;
    }

};