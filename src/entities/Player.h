#pragma once

#include "Pokitto.h"
#include "../utils/Enums.h"
#include "../utils/Structs.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


class Player {

    public:

        Player();

        uint16_t getX();
        uint16_t getY();
        const uint8_t getWidth();
        const uint8_t getHeight();
        Direction getDirection();
        int8_t getHealth();
        uint8_t getCoins();
        uint8_t getCoinsOverall();
        uint8_t getKills();
        uint8_t getFrame();
        bool getMoving();
        Object getWeapon();
        int8_t getPuffIndex();

        void setX(uint16_t x);
        void setY(uint16_t y);
        void setDirection(Direction direction);
        void setHealth(int8_t health);
        void setCoins(uint8_t coins);
        void setCoinsOverall(uint8_t coins);
        void setKills(uint8_t kills);
        void setFrame(uint8_t frame);
        void setMoving(bool moving);
        void setWeapon(Object weapon);

        void incFrame();
        void incCoins(uint8_t coins);
        void init(uint16_t x, uint16_t y);
        void decWeaponCount();
        void decPuffIndex();

        void incHealth(uint8_t amount);
        void decHealth(uint8_t amount);
        
        uint8_t getWeaponFrame();
        uint32_t getWeaponCount();
        Rect getRect();
        void reset();


        // Inventory methods

        InventoryItem & getInventoryItem(uint8_t index);
        InventoryItem & getActiveInventoryItem(uint8_t index);                  // index skips qty = 0 values
        uint8_t addInventoryItem(Object type, uint8_t qty);                     // returns slot used if success, NO_SLOT_FOUND if failed
        uint8_t decInventoryItem(Object type);                                  // returns slot used if success, NO_SLOT_FOUND if failed
        uint8_t getInventorySlot(Object type);                                  // returns slot used if success, NO_SLOT_FOUND if failed
        uint8_t getEmptySlot();                                                 // returns slot used if success, NO_SLOT_FOUND if failed
        uint8_t getInventoryCount();
        uint8_t getInventoryCount(Object type);
        uint8_t getActiveSlotCount();

    private:

        uint16_t x;
        uint16_t y;
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

        InventoryItem inventoryItems[MAX_INVENTORY_ITEMS];

};
