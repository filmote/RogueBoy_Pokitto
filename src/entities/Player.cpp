#include "Player.h"

Player::Player() {

   for (uint8_t index = 0; index < MAX_INVENTORY_ITEMS; index++) {

        auto & inventoryHolding = this->inventoryItems[index];
        inventoryHolding.index = index;

   }

}

void Player::reset() { 

    this->x = 0;
    this->y = 0;
    this->direction = Direction::Up;;
    this->health = 0;
    this->coins = 0;
    this->coinsOverall = 0;
    this->kills = 0;
    this->moving = false;
    this->frame = 0;
    this->weapon = Object::FireBall;
    this->weaponCount = 0;
    this->puffIndex = 0;

    for (uint8_t x = 0; x < MAX_INVENTORY_ITEMS; x++) {
        inventoryItems[x].type = Object::None;
        inventoryItems[x].quantity = 0;
    }

}

void Player::incAltarPieces() {
    if (this->altarPieces < 7) this->altarPieces++;
}

uint16_t Player::getX() { 
    return this->x; 
}

uint16_t Player::getY() { 
    return this->y; 
}

const uint8_t Player::getWidth() { 
    return 10; 
}

const uint8_t Player::getHeight() { 
    return 12; 
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

uint8_t Player::getCoinsOverall() { 
    return this->coinsOverall; 
}

uint8_t Player::getKills() { 
    return this->kills; 
}

uint8_t Player::getAltarPieces() { 
    return this->altarPieces; 
}

uint8_t Player::getFrame() { 
    return this->frame; 
}

bool Player::getMoving() { 
    return this->moving; 
}

Object Player::getWeapon() { 
    return this->weapon; 
}

Rect Player::getRect() {
    return Rect { this->getX() - (this->getWidth() / 2), this->getY() - (this->getHeight() / 2), this->getWidth(), this->getHeight() };
}

int8_t Player::getPuffIndex() { 
    return this->puffIndex; 
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

void Player::incHealth(uint8_t amount) { 
    this->health = this->health + amount; 
    if (this->health > 100) this->health = 100; 
}

void Player::decHealth(uint8_t amount) { 
    this->health = this->health - amount; 
    if (this->health <= 0) this->puffIndex = 10;
}

void Player::setCoins(uint8_t coins) { 
    this->coins = coins; 
}

void Player::setCoinsOverall(uint8_t coins) { 
    this->coinsOverall = coins; 
}

void Player::setKills(uint8_t kills) { 
    this->kills = kills; 
}

void Player::setFrame(uint8_t frame) { 
    this->frame = frame;
}

void Player::incCoins(uint8_t coins) { 
    this->coins = this->coins + coins; 
    this->coinsOverall = this->coinsOverall + coins; 
}

void Player::setMoving(bool moving) { 
    this->moving = moving; 
}

void Player::setWeapon(Object weapon) { 
    
    this->weapon = weapon; 

    switch (weapon) {

        case Object::IceSpell:
            this->weaponCount = ICE_SPELL_DELAY;
            break;

        default: 
            break;

    }

}

void Player::decWeaponCount() {

    if (this->weaponCount > 0) {

        this->weaponCount--;

        if (this->weaponCount == 0) {

            this->weapon = Object::FireBall;

        }

    }

}

void Player::decPuffIndex() {

    if (this->puffIndex > PLAYER_DEAD_DELAY) this->puffIndex--;

}

uint8_t Player::getWeaponFrame() {

    return this->weaponCount / ICE_SPELL_DELAY_INC;
    
}

uint32_t Player::getWeaponCount() {

    return this->weaponCount;
    
}

void Player::incFrame() {
    
    this->frame++;
    this->frame %= 2;

}

void Player::init(uint16_t x, uint16_t y) {

    this->x = x;
    this->y = y;
    this->direction = Direction::Down;
    this->coins = 0;
    this->coinsOverall = 0;
    this->kills = 0;
    this->health = (this->health <= 0 ? 100 : this->health);
    this->moving = false;
    this->altarPieces = 0;
    
}


InventoryItem & Player::getInventoryItem(uint8_t index) {

    auto & inventoryHolding = this->inventoryItems[index];
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


uint8_t Player::addInventoryItem(Object type, uint8_t qty) {

    uint8_t slot = NO_SLOT_FOUND;


    // Are we carrying the maximum items?

    if (getInventoryCount() == MAX_INVENTORY_COUNT) {

        return NO_SLOT_FOUND;

    }



    // Otherwise, do we have an existing slot with this item in it?

    slot = getInventorySlot(type);

    if (slot != NO_SLOT_FOUND) {

        InventoryItem & inventoryHolding = this->inventoryItems[slot];
        inventoryHolding.quantity = inventoryHolding.quantity + qty;
        return slot;

    }


    // Otherwise, is there and empty slot?

    slot = getEmptySlot();

    if (slot != NO_SLOT_FOUND) {

        InventoryItem & inventoryHolding = this->inventoryItems[slot];
        inventoryHolding.type = type;
        inventoryHolding.quantity = qty;
        return slot;

    }

    return NO_SLOT_FOUND;

}


uint8_t Player::decInventoryItem(Object type) {

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

            switch (inventoryHolding.type) {

                case Object::IceSpell:
                case Object::GreenSpell:
                case Object::RedSpell:
                case Object::MauveSpell:
                    count = count + 1;
                    break;

                default:
                    count = count + inventoryHolding.quantity;
                    break;

            }

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