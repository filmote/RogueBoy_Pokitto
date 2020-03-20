#pragma once

#include "Pokitto.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

struct Point {

    int16_t x;
    int16_t y;

};

struct MapInformation {

    uint16_t width;
    uint16_t height;
    uint8_t level;

};