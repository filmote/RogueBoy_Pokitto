#pragma once

#include "Pokitto.h"
#include "Enums.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

struct Point {

    int16_t x;
    int16_t y;

};

struct InventoryMenu {

    uint8_t mainCursor = 0;
    uint8_t actionCursor = 0;
    bool showActionMenu = false;

};

struct InventoryItem {

    uint8_t index;      // Ordinal index in collection.
    Object type;
    uint8_t quantity;

    bool getCanEat() {

        switch (type) {

            case Object::Donut:
            case Object::Ham:
                return true;

            default:
                return false;

        }

    }

};
