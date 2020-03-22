#include "Player.h"

Player::Player() {

   for (uint8_t index = 0; index < MAX_INVENTORY_ITEMS; index++) {

        auto & inventoryHolding = this->inventoryItems[index];
        inventoryHolding.index = index;

   }

}

uint16_t Player::getX() { 
    return this->x; 
}

uint16_t Player::getY() { 
    return this->y; 
}

Direction Player::getDirection() { 
    return this->direction; 
}

int8_t Player::getHealth() { 
    return this->health; 
}

uint8_t Player::getCoins() { 
    return this->coins; 
}

uint8_t Player::getKills() { 
    return this->kills; 
}

uint8_t Player::getFrame() { 
    return this->frame; 
}

bool Player::getMoving() { 
    return this->moving; 
}

void Player::setX(uint16_t x) { 
    this->x = x; 
}

void Player::setY(uint16_t y) { 
    this->y = y; 
}

void Player::setDirection(Direction direction) { 
    this->direction = direction; 
}

void Player::setHealth(int8_t health) { 
    this->health = health; 
    if (this->health > 100) this->health = 100; 
}

void Player::setCoins(uint8_t coins) { 
    this->coins = coins; 
}

void Player::setKills(uint8_t kills) { 
    this->kills = kills; 
}

void Player::setFrame(uint8_t frame) { 
    this->frame = frame;
}

void Player::setMoving(bool moving) { 
    this->moving = moving; 
}

void Player::incFrame() {
    
    this->frame++;
    this->frame %= 4;

}

void Player::init(uint16_t x, uint16_t y) {

    this->x = x;
    this->y = y;
    this->direction = Direction::Up;
    this->coins = 0;
    this->kills = 0;
    this->health = 100;
    this->moving = false;
    
    for (uint8_t i = 0; i < MAX_INVENTORY_ITEMS; i++) {

        auto & inventoryHolding = this->inventoryItems[i];
        inventoryHolding.quantity = 0;
printf("init\n");        
    }
    
}



InventoryItem & Player::getInventoryItem(uint8_t index) {

    auto & inventoryHolding = this->inventoryItems[index];

//    printf("Inc: %i, qty %i\n", inventoryHolding.type, inventoryHolding.quantity);

    return this->inventoryItems[index];

}

InventoryItem & Player::getActiveInventoryItem(uint8_t index) {

    uint8_t count = 0;

    for (uint8_t i = 0; i < MAX_INVENTORY_ITEMS; i++) {

        auto & inventoryHolding = this->inventoryItems[i];

        if (inventoryHolding.quantity > 0) {

            if (count == index) {

                return this->inventoryItems[i];

            } 

            count++;

        }

    }

    return this->inventoryItems[0]; // Default.

}


uint8_t Player::addInventoryItem(Object type) {

    uint8_t slot = NO_SLOT_FOUND;


    // Are we carrying the maximum items?

    if (getInventoryCount() == MAX_INVENTORY_COUNT) {

        return NO_SLOT_FOUND;

    }



    // Otherwise, do we have an existing slot with this item in it?

    slot = getInventorySlot(type);

    if (slot != NO_SLOT_FOUND) {

        InventoryItem & inventoryHolding = this->inventoryItems[slot];
        inventoryHolding.quantity++;
        return slot;

    }


    // Otherwise, is there and empty slot?

    slot = getEmptySlot();

    if (slot != NO_SLOT_FOUND) {
printf("add inv\n");
        InventoryItem & inventoryHolding = this->inventoryItems[slot];
        inventoryHolding.type = type;
        inventoryHolding.quantity = 1;
        return slot;

    }

    return NO_SLOT_FOUND;

}


uint8_t Player::decInventoryItem(Object type) {
printf("descInv\n");
    uint8_t slot = getInventorySlot(type);


    // Do we have an existing slot with this item in it?

    if (slot != NO_SLOT_FOUND) {

        InventoryItem & inventoryHolding = this->inventoryItems[slot];
        inventoryHolding.quantity--;
        return slot;

    }

    return NO_SLOT_FOUND;

}

// Get the slot number of the inventory item provided, return NO_SLOT_FOUND if not found ..

uint8_t Player::getInventorySlot(Object type) {

    bool found = false;
    uint8_t index = 0;

    for (index = 0; index < MAX_INVENTORY_ITEMS; index++) {

        auto & inventoryHolding = this->inventoryItems[index];

        if (inventoryHolding.type == type) {

            found = true;
            break;

        }

    }

    return (found ? index : NO_SLOT_FOUND);

}

// Get an empty inventory slot, return NO_SLOT_FOUND if none available ..

uint8_t Player::getEmptySlot() {

    bool found = false;
    uint8_t index = 0;

    for (index = 0; index < MAX_INVENTORY_ITEMS; index++) {

        auto & inventoryHolding = this->inventoryItems[index];

        if (inventoryHolding.quantity == 0) {

            found = true;
            break;

        }

    }

    return (found ? index : NO_SLOT_FOUND);

}


// Get a count of inventory items currently being held ..

uint8_t Player::getInventoryCount() {

    uint8_t count = 0;

    for (uint8_t index = 0; index < MAX_INVENTORY_ITEMS; index++) {

        auto & inventoryHolding = this->inventoryItems[index];

        if (inventoryHolding.quantity > 0) {

            count = count + inventoryHolding.quantity;

        }

    }

    return count;

}

uint8_t Player::getInventoryCount(Object type) {

    uint8_t count = 0;

    for (uint8_t index = 0; index < MAX_INVENTORY_ITEMS; index++) {

        auto & inventoryHolding = this->inventoryItems[index];

        if (inventoryHolding.type == type && inventoryHolding.quantity > 0) {

            count = count + inventoryHolding.quantity;

        }

    }

    return count;

}


// Get a count of active inventory slots ..

uint8_t Player::getActiveSlotCount() {

    uint8_t count = 0;

    for (uint8_t index = 0; index < MAX_INVENTORY_ITEMS; index++) {

        auto & inventoryHolding = this->inventoryItems[index];

        if (inventoryHolding.quantity > 0) {

            count++;

        }

    }

    return count;

}