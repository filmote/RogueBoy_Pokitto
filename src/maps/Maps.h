#pragma once

#include <stdint.h>

constexpr const uint8_t MAP_1[] = 
{
	6, /*Width*/
	6, /*Height*/
	1, /*Player Start X*/
	1, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	0, 24, 24, 24, 24, 0,
	21, 9, 0, 0, 0, 23,
	21, 0, 0, 0, 0, 23,
	21, 0, 0, 0, 0, 23,
	21, 0, 0, 0, 3, 23,
	0, 22, 22, 22, 22, 0,
	4, 
	0, 2, 2, 0,
	0, 3, 2, 0,
	0, 3, 3, 0,
	0, 2, 3, 0,
	0,
};

constexpr const uint8_t MAP_2[] = 
{
	9, /*Width*/
	7, /*Height*/
	1, /*Player Start X*/
	1, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	0, 24, 24, 24, 68, 24, 24, 24, 0,
	21, 9, 0, 0, 0, 0, 0, 84, 23,
	21, 0, 0, 0, 4, 4, 0, 0, 23,
	66, 0, 0, 0, 8, 4, 0, 4, 65,
	21, 4, 0, 0, 0, 0, 0, 4, 23,
	21, 4, 4, 0, 0, 0, 0, 17, 23,
	0, 22, 22, 22, 67, 22, 22, 22, 0,
	0, 
	0,
};

constexpr const uint8_t MAP_3[] = 
{
	11, /*Width*/
	8, /*Height*/
	4, /*Player Start X*/
	1, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	0, 24, 24, 68, 24, 68, 24, 24, 0, 38, 38,
	21, 4, 0, 0, 9, 0, 0, 84, 34, 24, 0,
	21, 0, 0, 0, 0, 0, 0, 0, 39, 0, 23,
	21, 11, 0, 0, 0, 0, 0, 37, 36, 0, 65,
	0, 22, 36, 59, 45, 59, 37, 0, 21, 0, 23,
	38, 38, 21, 0, 43, 0, 23, 38, 21, 0, 65,
	38, 38, 21, 8, 43, 3, 23, 38, 21, 11, 23,
	38, 38, 0, 22, 0, 22, 0, 38, 0, 22, 0,
	2, 
	8, 3, 5, 20,
	21, 9, 3, 20,
	2,
	1, 3, 3, 4,
	9, 6, 5, 4,
};

constexpr const uint8_t MAP_4[] = 
{
	11, /*Width*/
	9, /*Height*/
	5, /*Player Start X*/
	1, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	0, 24, 24, 68, 24, 24, 24, 68, 24, 24, 0,
	21, 4, 4, 0, 0, 9, 4, 0, 4, 4, 23,
	66, 4, 0, 0, 0, 11, 0, 0, 0, 4, 65,
	21, 0, 0, 4, 0, 0, 0, 4, 0, 0, 23,
	0, 36, 4, 45, 59, 45, 59, 45, 59, 37, 0,
	38, 21, 0, 43, 0, 43, 0, 43, 0, 23, 38,
	38, 21, 0, 43, 0, 43, 0, 43, 0, 23, 38,
	38, 21, 17, 43, 11, 43, 8, 43, 11, 23, 38,
	38, 0, 22, 0, 22, 0, 22, 0, 22, 0, 38,
	1, 
	7, 4, 6, 1,
	4,
	5, 2, 4, 4,
	8, 7, 6, 4,
	4, 7, 8, 4,
	8, 7, 2, 4,
};

constexpr const uint8_t MAP_5[] = 
{
	12, /*Width*/
	12, /*Height*/
	1, /*Player Start X*/
	1, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	0, 24, 68, 24, 68, 24, 24, 68, 24, 68, 24, 0,
	21, 9, 0, 0, 0, 0, 61, 0, 0, 0, 84, 23,
	21, 0, 0, 0, 4, 37, 44, 44, 48, 0, 37, 0,
	0, 44, 44, 44, 44, 35, 0, 40, 0, 0, 34, 0,
	21, 0, 0, 0, 0, 40, 0, 45, 0, 0, 8, 23,
	0, 22, 44, 44, 44, 36, 0, 34, 22, 22, 22, 0,
	38, 21, 0, 0, 8, 43, 0, 84, 23, 38, 38, 38,
	38, 66, 0, 47, 44, 35, 0, 0, 65, 38, 38, 38,
	38, 21, 0, 0, 0, 0, 0, 0, 23, 0, 24, 0,
	38, 0, 22, 22, 22, 36, 0, 47, 24, 35, 17, 23,
	38, 38, 38, 38, 38, 21, 0, 0, 0, 0, 0, 23,
	38, 38, 38, 38, 38, 0, 22, 67, 22, 67, 22, 0,
	16, 
	5, 6, 7, 30,
	8, 7, 7, 20,
	8, 7, 8, 20,
	8, 6, 8, 20,
	8, 5, 8, 20,
	8, 4, 8, 20,
	7, 8, 3, 20,
	7, 9, 4, 20,
	8, 8, 4, 20,
	2, 9, 3, 20,
	1, 2, 4, 20,
	1, 3, 4, 20,
	1, 4, 4, 20,
	3, 1, 4, 20,
	17, 6, 9, 0,
	19, 3, 8, 0,
	0,
};

constexpr const uint8_t Map_Shop[] = 
{
	13, /*Width*/
	11, /*Height*/
	2, /*Player Start X*/
	2, /*Player Start Y*/
	200, /*Timer*/
	1, /*Out of Bounds Tile ID*/
	0, 24, 24, 24, 0, 38, 38, 38, 38, 38, 38, 38, 38,
	21, 83, 9, 0, 23, 38, 38, 38, 38, 38, 38, 38, 38,
	66, 0, 0, 0, 65, 38, 38, 38, 38, 38, 38, 38, 38,
	21, 0, 0, 0, 23, 38, 38, 38, 38, 38, 38, 38, 0,
	0, 36, 0, 37, 0, 38, 0, 24, 68, 24, 68, 24, 0,
	38, 66, 0, 23, 38, 38, 21, 4, 77, 78, 79, 4, 23,
	38, 21, 0, 23, 38, 38, 21, 0, 80, 81, 82, 0, 23,
	38, 66, 0, 34, 24, 24, 35, 0, 0, 0, 0, 0, 23,
	38, 21, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 23,
	38, 0, 22, 22, 22, 22, 22, 22, 22, 22, 36, 3, 23,
	38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 0, 22, 0,
	4, 
	17, 2, 5, 0,
	18, 2, 6, 0,
	19, 4, 8, 0,
	20, 5, 8, 0,
	0,
};

constexpr const uint8_t MAP_6[] = 
{
	11, /*Width*/
	12, /*Height*/
	3, /*Player Start X*/
	1, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	38, 38, 38, 24, 38, 38, 38, 38, 38, 38, 38,
	38, 24, 35, 9, 34, 24, 0, 24, 24, 0, 38,
	21, 4, 0, 0, 0, 11, 43, 83, 4, 23, 38,
	0, 44, 48, 59, 47, 44, 35, 4, 0, 23, 38,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 65, 38,
	0, 44, 48, 16, 47, 44, 36, 0, 4, 23, 38,
	21, 83, 0, 0, 0, 84, 43, 4, 4, 23, 38,
	21, 0, 0, 17, 0, 0, 43, 4, 11, 65, 38,
	0, 22, 67, 22, 67, 22, 21, 16, 16, 23, 38,
	38, 38, 38, 38, 38, 38, 21, 0, 0, 23, 38,
	38, 38, 38, 38, 38, 38, 21, 0, 8, 23, 38,
	38, 38, 38, 38, 38, 38, 0, 22, 22, 38, 38,
	6, 
	6, 7, 10, 10,
	7, 8, 9, 10,
	6, 7, 9, 10,
	7, 7, 10, 30,
	6, 7, 9, 30,
	7, 8, 9, 30,
	4,
	5, 2, 3, 3,
	8, 7, 8, 8,
	8, 7, 7, 8,
	8, 7, 3, 5,
};

constexpr const uint8_t MAP_7[] = 
{
	12, /*Width*/
	12, /*Height*/
	1, /*Player Start X*/
	1, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	0, 24, 24, 24, 0, 24, 68, 24, 68, 24, 0, 38,
	21, 9, 0, 0, 43, 83, 0, 0, 0, 84, 23, 38,
	21, 0, 0, 37, 35, 0, 0, 45, 0, 0, 23, 38,
	0, 48, 4, 46, 83, 0, 28, 25, 0, 37, 0, 38,
	21, 0, 0, 0, 0, 0, 43, 0, 0, 34, 24, 0,
	21, 0, 0, 37, 44, 44, 35, 0, 0, 0, 84, 23,
	0, 22, 22, 25, 0, 0, 0, 0, 45, 0, 0, 65,
	38, 0, 25, 0, 0, 0, 0, 28, 24, 48, 0, 65,
	38, 21, 0, 0, 0, 0, 28, 25, 0, 0, 0, 23,
	38, 66, 0, 0, 37, 22, 25, 0, 0, 0, 37, 0,
	38, 21, 17, 0, 23, 21, 0, 0, 0, 37, 0, 38,
	38, 0, 22, 22, 0, 0, 22, 22, 22, 0, 38, 38,
	11, 
	3, 6, 10, 30,
	7, 2, 5, 30,
	7, 1, 5, 30,
	7, 1, 4, 30,
	8, 8, 1, 30,
	8, 9, 2, 30,
	6, 8, 9, 30,
	5, 3, 9, 30,
	5, 2, 8, 30,
	5, 9, 8, 30,
	19, 3, 4, 0,
	0,
};

constexpr const uint8_t MAP_8[] = 
{
	12, /*Width*/
	12, /*Height*/
	1, /*Player Start X*/
	1, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	0, 24, 0, 0, 24, 24, 24, 24, 24, 24, 24, 0,
	21, 9, 23, 35, 0, 0, 39, 0, 0, 0, 0, 23,
	21, 0, 46, 0, 0, 37, 22, 22, 22, 36, 0, 65,
	21, 0, 0, 0, 47, 0, 0, 24, 24, 35, 0, 23,
	0, 36, 0, 45, 0, 23, 21, 83, 0, 0, 0, 23,
	0, 35, 0, 46, 0, 65, 66, 0, 0, 0, 0, 65,
	21, 0, 0, 0, 0, 23, 21, 0, 0, 0, 0, 23,
	66, 4, 45, 0, 47, 24, 0, 22, 22, 22, 22, 0,
	21, 0, 43, 0, 0, 0, 23, 38, 38, 38, 38, 38,
	66, 0, 23, 22, 36, 41, 23, 38, 38, 38, 38, 38,
	21, 0, 23, 38, 21, 3, 23, 38, 38, 38, 38, 38,
	0, 22, 0, 38, 0, 22, 0, 38, 38, 38, 38, 38,
	13, 
	3, 1, 10, 1,
	5, 4, 4, 30,
	6, 4, 4, 30,
	3, 4, 4, 1,
	5, 10, 4, 100,
	1, 7, 5, 1,
	1, 8, 5, 1,
	1, 9, 5, 1,
	1, 10, 5, 1,
	19, 7, 1, 0,
	20, 8, 1, 0,
	17, 2, 4, 0,
	21, 7, 6, 20,
	0,
};

constexpr const uint8_t MAP_9[] = 
{
	11, /*Width*/
	11, /*Height*/
	6, /*Player Start X*/
	9, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	0, 24, 24, 24, 0, 24, 24, 24, 24, 24, 0,
	21, 10, 0, 84, 43, 0, 0, 0, 0, 0, 23,
	21, 0, 0, 0, 43, 0, 37, 22, 36, 0, 65,
	0, 48, 0, 47, 35, 64, 34, 24, 21, 0, 23,
	21, 0, 0, 0, 58, 0, 0, 0, 43, 0, 65,
	0, 44, 44, 44, 48, 0, 0, 11, 43, 0, 23,
	21, 0, 0, 0, 62, 0, 0, 0, 43, 0, 65,
	21, 59, 47, 44, 44, 22, 44, 44, 35, 0, 23,
	21, 0, 0, 0, 84, 43, 83, 0, 0, 0, 65,
	21, 0, 0, 0, 17, 43, 9, 0, 0, 0, 23,
	0, 22, 22, 22, 22, 0, 22, 22, 22, 22, 0,
	9, 
	3, 2, 2, 30,
	8, 2, 2, 30,
	6, 6, 5, 30,
	7, 9, 4, 30,
	7, 6, 1, 30,
	19, 2, 8, 0,
	20, 2, 9, 0,
	17, 9, 7, 0,
	18, 9, 5, 0,
	5,
	7, 5, 5, 3,
	7, 5, 4, 4,
	7, 5, 4, 6,
	1, 1, 4, 6,
	1, 1, 1, 7,
};

constexpr const uint8_t MAP_10[] = 
{
	9, /*Width*/
	9, /*Height*/
	1, /*Player Start X*/
	1, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	0, 24, 24, 24, 24, 0, 24, 24, 0,
	21, 9, 0, 0, 84, 46, 0, 0, 23,
	66, 0, 0, 0, 0, 4, 0, 0, 65,
	66, 0, 0, 0, 0, 45, 0, 0, 65,
	21, 0, 0, 0, 17, 43, 3, 0, 23,
	0, 48, 4, 47, 44, 0, 22, 22, 0,
	21, 0, 0, 0, 84, 23, 38, 38, 38,
	21, 0, 0, 0, 0, 23, 38, 38, 38,
	0, 22, 67, 67, 22, 0, 38, 38, 38,
	15, 
	0, 2, 2, 10,
	0, 2, 3, 10,
	0, 3, 3, 10,
	0, 3, 2, 10,
	3, 4, 7, 10,
	7, 4, 7, 50,
	7, 3, 7, 50,
	7, 2, 7, 50,
	7, 1, 7, 50,
	6, 7, 4, 50,
	6, 7, 3, 50,
	6, 7, 2, 50,
	6, 7, 1, 50,
	0, 7, 1, 50,
	0, 7, 2, 50,
	0,
};

constexpr const uint8_t Map_Shop2[] = 
{
	15, /*Width*/
	11, /*Height*/
	2, /*Player Start X*/
	8, /*Player Start Y*/
	200, /*Timer*/
	1, /*Out of Bounds Tile ID*/
	38, 38, 38, 0, 24, 68, 68, 68, 24, 0, 38, 38, 38, 38, 38,
	38, 38, 38, 21, 0, 0, 0, 0, 0, 23, 38, 0, 24, 0, 38,
	38, 38, 38, 21, 0, 77, 78, 79, 0, 34, 68, 25, 0, 26, 0,
	38, 38, 38, 21, 0, 80, 81, 82, 0, 0, 0, 0, 3, 0, 23,
	38, 38, 38, 21, 0, 0, 0, 0, 0, 37, 22, 27, 0, 28, 0,
	38, 38, 38, 0, 22, 36, 0, 37, 22, 0, 38, 0, 67, 0, 38,
	38, 0, 24, 0, 38, 66, 0, 65, 38, 38, 38, 38, 38, 38, 38,
	0, 25, 0, 26, 24, 35, 0, 23, 38, 38, 38, 38, 38, 38, 38,
	66, 0, 9, 0, 0, 0, 0, 65, 38, 38, 38, 38, 38, 38, 38,
	0, 27, 0, 28, 67, 67, 67, 0, 38, 38, 38, 38, 38, 38, 38,
	38, 0, 22, 0, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38,
	3, 
	20, 4, 8, 0,
	20, 5, 8, 0,
	21, 6, 5, 20,
	0,
};

constexpr const uint8_t MAP_11[] = 
{
	12, /*Width*/
	8, /*Height*/
	2, /*Player Start X*/
	2, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	0, 24, 68, 24, 0, 38, 0, 24, 0, 24, 0, 38,
	21, 83, 0, 0, 34, 68, 35, 8, 43, 3, 23, 38,
	66, 0, 9, 0, 39, 0, 0, 4, 43, 0, 34, 0,
	21, 0, 0, 0, 45, 0, 0, 37, 21, 0, 0, 23,
	0, 48, 4, 47, 0, 48, 41, 34, 24, 48, 0, 65,
	21, 0, 0, 0, 43, 0, 0, 0, 0, 0, 0, 23,
	21, 0, 0, 0, 23, 36, 0, 37, 67, 67, 22, 0,
	0, 22, 67, 22, 0, 0, 22, 0, 38, 38, 38, 38,
	13, 
	2, 2, 6, 20,
	7, 3, 5, 20,
	7, 1, 5, 20,
	8, 6, 2, 20,
	3, 1, 6, 20,
	8, 5, 3, 20,
	8, 6, 6, 20,
	7, 5, 5, 20,
	6, 8, 5, 20,
	5, 9, 3, 20,
	6, 10, 5, 20,
	18, 10, 4, 0,
	20, 9, 5, 0,
	0,
};

constexpr const uint8_t MAP_12[] = 
{
	4, /*Width*/
	12, /*Height*/
	1, /*Player Start X*/
	1, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	0, 24, 24, 0,
	21, 0, 11, 23,
	66, 0, 11, 23,
	21, 0, 11, 23,
	66, 0, 11, 23,
	21, 0, 37, 0,
	66, 59, 23, 0,
	21, 59, 34, 0,
	66, 59, 0, 23,
	21, 59, 37, 0,
	21, 17, 23, 38,
	0, 22, 0, 38,
	3, 
	3, 2, 8, 40,
	8, 2, 8, 40,
	8, 2, 8, 40,
	4,
	2, 4, 1, 8,
	2, 2, 1, 7,
	2, 2, 1, 6,
	2, 4, 1, 9,
};

constexpr const uint8_t MAP_13[] = 
{
	11, /*Width*/
	12, /*Height*/
	4, /*Player Start X*/
	2, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	0, 24, 24, 24, 24, 0, 38, 38, 38, 38, 38,
	21, 4, 4, 4, 0, 34, 68, 24, 0, 24, 0,
	66, 4, 33, 4, 0, 0, 0, 84, 46, 3, 23,
	21, 4, 4, 0, 0, 33, 0, 0, 57, 0, 23,
	0, 22, 44, 44, 44, 36, 0, 47, 44, 44, 0,
	38, 21, 0, 0, 0, 43, 0, 4, 0, 0, 23,
	38, 66, 0, 45, 42, 34, 44, 44, 48, 0, 65,
	38, 21, 0, 43, 0, 4, 0, 0, 0, 0, 23,
	38, 66, 0, 34, 44, 36, 0, 47, 44, 44, 0,
	38, 21, 0, 0, 11, 43, 0, 0, 4, 8, 23,
	38, 0, 22, 22, 22, 0, 22, 22, 22, 22, 0,
	38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38,
	11, 
	6, 8, 5, 20,
	6, 8, 5, 20,
	7, 7, 9, 20,
	7, 7, 9, 20,
	7, 7, 9, 20,
	8, 2, 9, 20,
	5, 2, 9, 20,
	18, 2, 6, 0,
	17, 2, 7, 0,
	19, 7, 7, 0,
	20, 8, 7, 0,
	1,
	4, 9, 8, 3,
};

constexpr const uint8_t MAP_14[] = 
{
	11, /*Width*/
	11, /*Height*/
	5, /*Player Start X*/
	5, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	0, 24, 68, 24, 68, 24, 68, 24, 68, 24, 0,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23,
	66, 0, 33, 0, 33, 0, 33, 0, 33, 0, 65,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23,
	66, 0, 33, 0, 33, 0, 33, 0, 33, 0, 65,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23,
	66, 0, 33, 0, 33, 0, 33, 0, 33, 0, 65,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23,
	66, 0, 33, 0, 33, 17, 33, 0, 33, 0, 65,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23,
	0, 22, 67, 22, 67, 22, 67, 22, 67, 22, 0,
	15, 
	8, 8, 3, 100,
	8, 7, 2, 100,
	8, 5, 2, 100,
	8, 3, 2, 100,
	8, 2, 3, 100,
	8, 2, 5, 100,
	8, 2, 7, 100,
	8, 3, 8, 100,
	1, 1, 9, 100,
	8, 7, 8, 100,
	8, 8, 7, 100,
	8, 8, 5, 100,
	3, 1, 1, 100,
	1, 9, 1, 100,
	0, 9, 9, 100,
	0,
};

constexpr const uint8_t MAP_15[] = 
{
	12, /*Width*/
	11, /*Height*/
	6, /*Player Start X*/
	5, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	38, 38, 38, 38, 0, 24, 24, 0, 38, 38, 38, 38,
	0, 24, 24, 24, 21, 0, 84, 23, 24, 24, 24, 0,
	21, 0, 0, 0, 43, 0, 0, 43, 0, 0, 0, 23,
	21, 16, 16, 16, 43, 0, 0, 43, 16, 16, 16, 23,
	66, 0, 0, 0, 46, 0, 0, 46, 0, 0, 0, 65,
	21, 17, 0, 14, 53, 0, 0, 54, 14, 0, 17, 23,
	66, 0, 0, 0, 45, 0, 0, 45, 0, 0, 0, 65,
	21, 16, 16, 16, 43, 0, 0, 43, 16, 16, 16, 23,
	21, 0, 0, 0, 43, 0, 0, 43, 0, 0, 0, 23,
	0, 22, 22, 22, 21, 86, 0, 23, 22, 22, 22, 0,
	38, 38, 38, 38, 0, 22, 22, 0, 38, 38, 38, 38,
	14, 
	5, 9, 8, 50,
	5, 10, 8, 50,
	5, 8, 8, 50,
	7, 8, 2, 50,
	7, 9, 2, 50,
	7, 10, 2, 50,
	8, 3, 2, 50,
	8, 2, 2, 50,
	8, 1, 2, 50,
	6, 1, 8, 50,
	6, 2, 8, 50,
	6, 3, 8, 50,
	3, 2, 2, 50,
	3, 9, 8, 50,
	14,
	3, 5, 4, 5,
	8, 5, 7, 5,
	8, 5, 8, 7,
	8, 5, 9, 7,
	8, 5, 10, 7,
	8, 5, 8, 3,
	8, 5, 9, 3,
	8, 5, 10, 3,
	3, 5, 3, 7,
	3, 5, 3, 3,
	3, 5, 2, 3,
	3, 5, 1, 3,
	3, 5, 2, 7,
	3, 5, 1, 7,
};

constexpr const uint8_t Map_Shop3[] = 
{
	17, /*Width*/
	14, /*Height*/
	8, /*Player Start X*/
	2, /*Player Start Y*/
	200, /*Timer*/
	1, /*Out of Bounds Tile ID*/
	38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38,
	38, 38, 38, 38, 38, 38, 38, 0, 68, 0, 38, 38, 38, 38, 38, 38, 38,
	38, 38, 38, 38, 38, 38, 0, 25, 0, 26, 0, 38, 38, 38, 38, 38, 38,
	38, 38, 38, 38, 38, 38, 66, 0, 73, 0, 65, 38, 38, 38, 38, 38, 38,
	38, 38, 38, 38, 38, 38, 0, 27, 0, 28, 0, 38, 38, 38, 38, 38, 38,
	38, 38, 38, 38, 0, 24, 0, 38, 67, 38, 0, 24, 0, 38, 38, 38, 38,
	38, 38, 38, 0, 25, 0, 26, 24, 68, 24, 25, 0, 26, 0, 38, 38, 38,
	38, 38, 38, 21, 0, 73, 0, 0, 0, 0, 0, 73, 0, 23, 38, 38, 38,
	38, 38, 38, 0, 27, 0, 28, 22, 22, 22, 27, 0, 28, 0, 38, 38, 38,
	38, 0, 24, 38, 0, 22, 0, 68, 68, 68, 0, 22, 0, 38, 24, 0, 38,
	0, 25, 0, 26, 68, 24, 25, 77, 78, 79, 26, 24, 68, 25, 0, 26, 0,
	21, 0, 73, 0, 0, 0, 0, 80, 81, 82, 0, 0, 0, 0, 3, 0, 65,
	0, 27, 0, 28, 22, 67, 27, 0, 0, 0, 28, 67, 22, 27, 0, 28, 0,
	38, 0, 22, 0, 38, 38, 0, 67, 22, 67, 0, 38, 38, 0, 22, 0, 38,
	0, 
	4,
	8, 3, 5, 7,
	5, 7, 8, 3,
	11, 7, 2, 11,
	2, 11, 11, 7,
};

constexpr const uint8_t MAP_16[] = 
{
	11, /*Width*/
	11, /*Height*/
	5, /*Player Start X*/
	8, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	0, 24, 68, 24, 0, 38, 38, 24, 68, 24, 0,
	21, 0, 0, 84, 34, 24, 35, 0, 8, 0, 23,
	21, 88, 0, 0, 0, 14, 0, 0, 33, 42, 23,
	0, 36, 59, 33, 0, 0, 0, 33, 0, 0, 23,
	38, 66, 0, 0, 33, 0, 33, 0, 0, 37, 0,
	38, 66, 14, 0, 0, 33, 0, 0, 14, 65, 38,
	0, 35, 0, 0, 33, 8, 33, 0, 0, 65, 38,
	21, 0, 59, 33, 0, 0, 0, 33, 59, 34, 0,
	21, 0, 33, 0, 0, 9, 0, 61, 0, 0, 23,
	21, 3, 0, 37, 22, 22, 22, 36, 0, 10, 23,
	0, 22, 22, 0, 38, 38, 38, 0, 22, 22, 0,
	12, 
	7, 7, 5, 50,
	7, 8, 4, 50,
	8, 9, 1, 50,
	8, 9, 1, 50,
	5, 6, 2, 50,
	6, 1, 1, 50,
	6, 1, 1, 50,
	6, 2, 4, 50,
	6, 3, 5, 50,
	21, 7, 5, 20,
	17, 1, 8, 0,
	20, 5, 4, 0,
	5,
	9, 9, 8, 7,
	9, 9, 7, 8,
	8, 5, 2, 3,
	2, 3, 2, 5,
	2, 5, 2, 7,
};

constexpr const uint8_t MAP_17[] = 
{
	12, /*Width*/
	11, /*Height*/
	2, /*Player Start X*/
	2, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	0, 24, 68, 24, 0, 24, 68, 24, 24, 68, 24, 0,
	21, 0, 0, 0, 43, 83, 0, 0, 0, 0, 10, 23,
	21, 0, 9, 0, 43, 0, 0, 45, 0, 0, 0, 23,
	0, 44, 48, 0, 43, 0, 47, 21, 0, 47, 44, 0,
	21, 0, 0, 0, 46, 0, 0, 43, 0, 0, 0, 23,
	21, 14, 0, 0, 16, 0, 0, 43, 0, 0, 0, 65,
	0, 44, 44, 44, 22, 44, 44, 24, 22, 48, 0, 23,
	21, 0, 0, 84, 46, 0, 0, 0, 46, 0, 0, 23,
	66, 0, 0, 0, 58, 0, 17, 0, 0, 0, 0, 65,
	21, 0, 0, 0, 45, 0, 0, 0, 45, 11, 0, 23,
	0, 22, 67, 22, 0, 22, 67, 22, 0, 22, 22, 0,
	17, 
	3, 10, 8, 50,
	3, 2, 8, 50,
	7, 5, 7, 50,
	7, 7, 9, 50,
	6, 8, 4, 50,
	6, 6, 2, 50,
	8, 1, 4, 50,
	8, 2, 5, 50,
	8, 10, 8, 50,
	8, 9, 7, 50,
	5, 9, 7, 50,
	5, 1, 7, 30,
	5, 3, 9, 30,
	5, 1, 9, 30,
	17, 5, 3, 0,
	18, 8, 3, 0,
	19, 7, 1, 0,
	3,
	10, 1, 4, 8,
	9, 9, 4, 8,
	1, 5, 4, 5,
};

constexpr const uint8_t MAP_18[] = 
{
	11, /*Width*/
	10, /*Height*/
	5, /*Player Start X*/
	1, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	0, 24, 68, 24, 68, 24, 68, 24, 68, 24, 0,
	21, 0, 0, 0, 0, 9, 0, 0, 0, 0, 23,
	66, 0, 14, 0, 14, 0, 14, 0, 14, 0, 65,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23,
	66, 0, 14, 0, 14, 0, 14, 0, 14, 0, 65,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23,
	66, 0, 14, 0, 14, 0, 14, 0, 14, 0, 65,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23,
	0, 22, 67, 22, 36, 17, 37, 22, 67, 22, 0,
	38, 38, 38, 38, 0, 22, 0, 38, 38, 38, 38,
	0, 
	3,
	8, 2, 5, 8,
	2, 4, 5, 8,
	8, 6, 5, 8,
};

constexpr const uint8_t Map133[] = 
{
	17, /*Width*/
	21, /*Height*/
	3, /*Player Start X*/
	1, /*Player Start Y*/
	200, /*Timer*/
	1, /*Out of Bounds Tile ID*/
	0, 24, 68, 24, 68, 24, 0, 38, 0, 24, 68, 24, 68, 24, 0, 38, 38,
	21, 87, 0, 9, 0, 8, 23, 38, 21, 0, 0, 0, 0, 84, 23, 38, 38,
	66, 0, 0, 0, 0, 0, 23, 38, 21, 0, 0, 0, 0, 0, 34, 24, 0,
	21, 0, 0, 0, 0, 0, 23, 24, 24, 44, 48, 0, 0, 0, 39, 0, 23,
	66, 0, 0, 0, 0, 0, 43, 0, 0, 0, 0, 0, 0, 0, 45, 0, 65,
	21, 0, 0, 0, 0, 0, 43, 0, 0, 0, 45, 0, 0, 0, 43, 0, 23,
	0, 22, 36, 41, 37, 44, 35, 0, 0, 0, 23, 44, 44, 44, 35, 0, 23,
	38, 38, 66, 0, 43, 0, 0, 0, 0, 0, 43, 10, 0, 0, 39, 0, 23,
	38, 38, 21, 0, 43, 0, 0, 0, 0, 0, 43, 0, 0, 37, 36, 0, 65,
	38, 38, 66, 0, 34, 44, 48, 60, 47, 44, 35, 0, 0, 23, 21, 0, 23,
	38, 38, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 85, 23, 21, 73, 23,
	38, 38, 0, 22, 67, 22, 67, 22, 22, 67, 22, 67, 22, 0, 38, 22, 38,
	0, 24, 24, 24, 24, 24, 0, 38, 38, 38, 0, 24, 24, 24, 24, 24, 0,
	21, 73, 0, 0, 0, 19, 23, 38, 38, 38, 21, 0, 0, 0, 0, 84, 23,
	66, 0, 33, 0, 33, 0, 23, 24, 24, 24, 21, 0, 33, 0, 33, 0, 65,
	66, 0, 0, 0, 0, 0, 43, 0, 0, 0, 43, 0, 0, 0, 0, 0, 23,
	66, 0, 33, 0, 33, 0, 46, 0, 0, 0, 46, 0, 33, 0, 33, 0, 65,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 23,
	0, 22, 22, 22, 22, 36, 0, 0, 0, 0, 0, 37, 22, 22, 22, 22, 0,
	38, 38, 38, 38, 38, 21, 86, 0, 0, 0, 0, 23, 38, 38, 38, 38, 38,
	38, 38, 38, 38, 38, 0, 22, 67, 22, 67, 22, 0, 38, 38, 38, 38, 38,
	19, 
	11, 8, 15, 50,
	7, 7, 15, 30,
	7, 7, 16, 30,
	7, 8, 16, 30,
	7, 9, 16, 30,
	7, 9, 15, 30,
	4, 7, 4, 0,
	8, 5, 7, 20,
	8, 5, 8, 20,
	1, 10, 19, 0,
	9, 9, 1, 0,
	21, 11, 13, 20,
	21, 15, 3, 20,
	8, 9, 2, 20,
	8, 10, 2, 20,
	8, 10, 1, 20,
	3, 13, 5, 0,
	6, 11, 8, 40,
	6, 1, 5, 40,
	3,
	15, 10, 1, 13,
	1, 13, 15, 10,
	11, 7, 7, 9,
};

constexpr const uint8_t Map22[] = 
{
	20, /*Width*/
	19, /*Height*/
	2, /*Player Start X*/
	1, /*Player Start Y*/
	200, /*Timer*/
	1, /*Out of Bounds Tile ID*/
	0, 24, 24, 24, 24, 24, 0, 38, 38, 38, 38, 38, 38, 0, 24, 24, 24, 24, 24, 0,
	21, 9, 0, 0, 0, 0, 26, 0, 38, 38, 38, 38, 0, 25, 0, 0, 0, 0, 0, 23,
	21, 0, 0, 0, 0, 0, 0, 26, 0, 38, 38, 0, 25, 0, 0, 0, 0, 0, 0, 23,
	66, 0, 0, 37, 22, 27, 0, 0, 26, 24, 24, 25, 0, 0, 28, 22, 36, 0, 0, 65,
	21, 0, 0, 23, 38, 0, 27, 0, 0, 0, 0, 0, 0, 28, 0, 38, 21, 0, 0, 23,
	21, 0, 0, 23, 38, 38, 0, 27, 0, 0, 0, 0, 28, 0, 38, 38, 21, 0, 0, 23,
	21, 0, 0, 23, 38, 38, 38, 66, 0, 0, 0, 0, 65, 38, 38, 38, 21, 0, 0, 23,
	66, 0, 0, 34, 24, 24, 24, 35, 0, 0, 0, 0, 34, 24, 24, 24, 35, 0, 0, 65,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23,
	66, 0, 0, 37, 22, 22, 22, 36, 0, 0, 0, 0, 37, 22, 22, 22, 36, 0, 0, 65,
	21, 0, 0, 23, 38, 38, 38, 66, 0, 0, 0, 0, 65, 38, 38, 38, 21, 0, 0, 23,
	21, 0, 0, 23, 38, 38, 0, 25, 0, 0, 0, 0, 26, 0, 38, 38, 21, 0, 0, 23,
	21, 0, 0, 23, 38, 0, 25, 0, 0, 0, 0, 0, 0, 26, 0, 38, 21, 0, 0, 23,
	66, 0, 0, 34, 24, 25, 0, 0, 28, 22, 22, 27, 0, 0, 26, 24, 35, 0, 0, 65,
	21, 0, 0, 0, 0, 0, 0, 28, 0, 38, 38, 0, 27, 0, 0, 0, 0, 0, 0, 23,
	21, 0, 0, 0, 0, 0, 28, 0, 38, 38, 38, 38, 0, 27, 0, 0, 0, 0, 0, 23,
	21, 0, 0, 0, 0, 28, 0, 38, 38, 38, 38, 38, 38, 0, 27, 0, 0, 0, 3, 23,
	0, 22, 22, 22, 22, 0, 38, 38, 38, 38, 38, 38, 38, 38, 0, 22, 22, 22, 22, 0,
	56, 
	17, 17, 4, 0,
	17, 17, 11, 0,
	17, 1, 11, 0,
	17, 1, 4, 0,
	18, 2, 4, 0,
	18, 2, 11, 0,
	18, 18, 11, 0,
	18, 18, 4, 0,
	0, 14, 9, 0,
	0, 14, 8, 0,
	0, 5, 9, 0,
	0, 5, 8, 0,
	0, 17, 5, 0,
	0, 18, 5, 0,
	0, 17, 12, 0,
	0, 18, 12, 0,
	0, 2, 12, 0,
	0, 1, 12, 0,
	0, 1, 5, 0,
	0, 2, 5, 0,
	17, 1, 6, 0,
	17, 1, 13, 0,
	17, 17, 13, 0,
	17, 17, 6, 0,
	18, 18, 6, 0,
	18, 18, 13, 0,
	18, 2, 13, 0,
	18, 2, 6, 0,
	21, 1, 8, 20,
	21, 18, 9, 20,
	7, 6, 3, 30,
	7, 13, 14, 30,
	11, 10, 8, 50,
	8, 17, 1, 20,
	8, 18, 1, 20,
	8, 18, 2, 20,
	8, 1, 16, 20,
	8, 1, 17, 20,
	8, 2, 17, 20,
	7, 9, 10, 30,
	7, 10, 6, 30,
	12, 4, 17, 0,
	7, 11, 9, 30,
	7, 9, 7, 30,
	7, 10, 10, 30,
	20, 4, 9, 0,
	20, 6, 9, 0,
	20, 13, 9, 0,
	20, 15, 9, 0,
	19, 4, 8, 0,
	19, 6, 8, 0,
	19, 13, 8, 0,
	19, 15, 8, 0,
	0, 14, 9, 0,
	0, 14, 9, 0,
	6, 5, 1, 40,
	0,
};

constexpr const uint8_t Altar[] = 
{
	15, /*Width*/
	15, /*Height*/
	3, /*Player Start X*/
	12, /*Player Start Y*/
	200, /*Timer*/
	1, /*Out of Bounds Tile ID*/
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	38, 38, 38, 38, 0, 24, 68, 24, 68, 24, 0, 38, 38, 38, 38,
	38, 38, 38, 0, 25, 0, 0, 0, 0, 0, 26, 0, 38, 38, 38,
	38, 38, 38, 66, 0, 0, 90, 91, 92, 0, 0, 65, 38, 38, 38,
	38, 38, 38, 66, 0, 0, 93, 94, 95, 0, 0, 65, 38, 38, 38,
	38, 38, 38, 0, 27, 0, 0, 0, 0, 0, 28, 0, 38, 38, 38,
	38, 38, 38, 38, 0, 22, 27, 0, 28, 22, 0, 38, 38, 38, 38,
	38, 38, 38, 38, 38, 38, 21, 0, 23, 38, 38, 38, 38, 38, 38,
	38, 0, 24, 24, 0, 38, 66, 0, 65, 38, 0, 24, 24, 0, 38,
	0, 25, 0, 0, 26, 68, 35, 0, 34, 68, 25, 0, 0, 26, 0,
	21, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23,
	0, 27, 0, 0, 28, 22, 67, 22, 67, 22, 27, 0, 0, 28, 0,
	38, 0, 22, 22, 0, 38, 38, 38, 38, 38, 0, 22, 22, 0, 38,
	7, 
	21, 11, 11, 20,
	6, 12, 12, 40,
	6, 7, 7, 40,
	8, 5, 11, 20,
	8, 6, 12, 20,
	8, 7, 11, 20,
	8, 8, 12, 20,
	0,
};

constexpr const uint8_t numberOfMaps = 24;

constexpr const uint8_t* maps[numberOfMaps] = { MAP_1,MAP_2,MAP_3,MAP_4,MAP_5,Map_Shop,MAP_6,MAP_7,MAP_8,MAP_9,MAP_10,Map_Shop2,MAP_11,MAP_12,MAP_13,MAP_14,MAP_15,Map_Shop3,MAP_16,MAP_17,MAP_18,Map133,Map22,Altar, };
