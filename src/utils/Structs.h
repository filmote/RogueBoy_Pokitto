#pragma once

#include "Pokitto.h"
#include "Enums.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

struct ShopObject {

    Object object;
    uint16_t price;
    uint8_t quantityLeft;

};

struct ShopVariables {

    uint8_t upperIndex = 0;
    uint8_t itemIndex = 0;
    uint8_t counter = 0;
    ShopMessage message = ShopMessage::None;

};

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

struct InventoryMenuVariables {

    InventoryMenuMode mode;
    uint8_t mainCursor = 0;
    uint8_t actionCursor = 0;
    bool showActionMenu = false;

};

struct HighScoreVariables {

    uint8_t charIdx = 2;
    uint8_t entryIdx = 1;

};

struct SplashScreenVariables {

    uint8_t counter = 0;
    uint8_t buttonCounter = 0;
    SplashScreenMode mode = SplashScreenMode::PPOT;

};

struct TitleScreenVars {

    int8_t arrowCounter = 0;
    uint8_t orbCounter = 0;
    TitleScreenMode mode = TitleScreenMode::Start;

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


struct PlayerStatus {

    // uint16_t x;
    // uint16_t y;
    Direction direction;
    int8_t health;
    uint8_t coins;
    uint8_t coinsOverall;
    uint8_t kills;
    bool moving;
    uint8_t frame;
    Object weapon = Object::FireBall;
    uint32_t weaponCount;
    int8_t puffIndex = 0;
    uint8_t altarPieces = 0;

    InventoryItem inventoryItems[MAX_INVENTORY_ITEMS];

};