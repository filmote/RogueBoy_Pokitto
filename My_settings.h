#define PROJ_BUTTONS_POLLING_ONLY

#define _MAP_LARGE

#ifndef MAP_LARGE
    #define PROJ_SCREENMODE             2
    #define CENTERX 55
    #define CENTERY 44
#else
    #define PROJ_SCREENMODE             15
    #define CENTERX 110
    #define CENTERY 88
#endif

#define TILE_WIDTH          16
#define TILE_HEIGHT         16
#define TILE_SIZE           16

#define PLAYER_SIZE         8
#define PLAYER_SIZE_HALF    4


#define MAXLEVEL            18
#define MAXOBJECT           50
#define MAXENVIROMENT       50

#define MAP_SIZE            1600


#define NO_SLOT_FOUND       255
#define NO_SPRITE_FOUND     255
#define MAX_INVENTORY_ITEMS 5                   // Number of item types the player can hold
#define MAX_INVENTORY_COUNT 6                   // NUmber of items the player can hold, two of one type counts as two.