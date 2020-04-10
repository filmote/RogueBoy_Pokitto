#pragma once

#include "Pokitto.h"
#include "Enums.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

struct Cell {

    uint8_t segment;
    uint8_t variation;
    bool isBlank;
    
};

struct Point {

    int16_t x;
    int16_t y;

};


struct Rect {

    int16_t x;
    int16_t y;
    uint8_t width;
    uint8_t height;

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

            case Object::Bread:
            case Object::Chicken:
                return true;

            default:
                return false;

        }

    }

};


static inline bool collide(Rect rect1, Rect rect2) {
    return !(rect2.x                >= rect1.x + rect1.width  ||
                rect2.x + rect2.width  <= rect1.x                ||
                rect2.y                >= rect1.y + rect1.height ||
                rect2.y + rect2.height <= rect1.y);
}