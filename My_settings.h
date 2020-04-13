#define PROJ_BUTTONS_POLLING_ONLY


#define PROJ_SCREENMODE             2
#define CENTERX 55
#define CENTERY 36

#define DEBUG

#define TILE_WIDTH          16
#define TILE_HEIGHT         16
#define TILE_SIZE           16

#define PLAYER_SIZE         8
#define PLAYER_SIZE_HALF    4


#define MAXLEVEL            18
#define MAXOBJECT           200
#define MAXENVIROMENT       100

#define MAP_SIZE_X          45
#define MAP_SIZE_Y          45
#define MAP_SIZE            (MAP_SIZE_X * MAP_SIZE_Y)


#define NO_SLOT_FOUND       255
#define NO_SPRITE_FOUND     255
#define MAX_INVENTORY_ITEMS 5                   // Number of item types the player can hold
#define MAX_INVENTORY_COUNT 6                   // NUmber of items the player can hold, two of one type counts as two.
#define RANDOM_TILE_SIZE    9
#define HEALTH_BAR_DELAY    8

#define HEALTH_INC_BREAD    10
#define HEALTH_INC_CHICKEN  20
#define END_OF_OPTIONS      255
#define ICE_SPELL_DELAY     360
#define ICE_SPELL_DELAY_INC 30

#define DAMAGE_FIREBALL     10
#define DAMAGE_ICESPELL     10
#define DAMAGE_GREENSPELL   20
#define DAMAGE_YELLOWSPELL  30

#define TIMER_STEP          24
#define LEVEL_START_DELAY   100
#define COOKIE_INITIALISED  25
#define SHOP_PURCHASE_DELAY 48


/*
Bit 7       Blank segment.
Bit 6       Any Segment from the nominated Type.
Bit 5       Specify a specific segment (over two bytes, sgement type, index)
Bit 4 .. 0  Segment specification (range 0 - 31).
*/

#define BLANK_SEG   128
#define ANY_SEG     64
#define THIS_SEG    32
#define SEG_00      0
#define SEG_01      1
#define SEG_02      2
#define SEG_03      3
#define SEG_04      4
#define SEG_05      5
#define SEG_06      6
#define SEG_07      7
#define SEG_08      8
#define SEG_09      9
#define SEG_10      10
#define SEG_11      11
#define SEG_12      12
#define SEG_13      13
#define SEG_14      14
#define SEG_15      15