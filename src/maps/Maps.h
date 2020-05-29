#pragma once

#include <stdint.h>

constexpr const uint8_t Map_01[] = 
{
	11, /*Width*/
	11, /*Height*/
	3, /*Player Start X*/
	2, /*Player Start Y*/
	200, /*Timer*/
	1, /*Out of Bounds Tile ID*/
	98, 24, 68, 24, 68, 24, 98, 24, 24, 24, 98,
	21, 0, 0, 0, 0, 0, 46, 0, 0, 0, 23,
	21, 10, 0, 0, 0, 0, 57, 0, 0, 0, 65,
	21, 0, 0, 0, 0, 0, 45, 0, 0, 0, 23,
	21, 0, 0, 0, 0, 0, 23, 22, 22, 22, 98,
	98, 22, 36, 0, 37, 22, 98, 38, 38, 38, 38,
	98, 24, 35, 0, 34, 24, 98, 24, 24, 24, 98,
	21, 0, 0, 0, 0, 0, 46, 0, 0, 87, 23,
	21, 0, 0, 4, 0, 0, 0, 0, 0, 0, 23,
	21, 0, 0, 0, 0, 0, 45, 17, 0, 0, 23,
	98, 22, 67, 22, 67, 22, 98, 22, 22, 22, 98,
	6, 
	32, 8, 2, 0,
	37, 8, 2, 0,
	8, 1, 9, 20,
	8, 5, 9, 20,
	3, 7, 3, 0,
	0, 2, 1, 0,
	1,
	1, 2, 6, 2,
};

constexpr const uint8_t Map_03[] = 
{
	11, /*Width*/
	13, /*Height*/
	4, /*Player Start X*/
	4, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	98, 24, 68, 24, 98, 38, 38, 38, 38, 38, 0,
	21, 0, 0, 0, 23, 38, 38, 38, 38, 38, 38,
	21, 97, 0, 0, 23, 38, 38, 38, 38, 38, 38,
	98, 48, 42, 47, 24, 68, 24, 24, 0, 38, 38,
	21, 4, 0, 0, 9, 0, 0, 84, 34, 24, 98,
	21, 0, 0, 0, 0, 0, 0, 0, 39, 0, 23,
	21, 11, 0, 0, 0, 0, 0, 37, 36, 0, 65,
	98, 22, 36, 59, 45, 59, 37, 98, 21, 0, 23,
	38, 38, 21, 0, 43, 0, 23, 38, 21, 0, 65,
	98, 24, 35, 0, 43, 3, 23, 38, 21, 11, 23,
	21, 0, 0, 0, 23, 22, 98, 38, 98, 22, 98,
	21, 8, 0, 0, 23, 38, 38, 38, 38, 38, 38,
	98, 22, 22, 22, 98, 38, 38, 38, 38, 38, 38,
	5, 
	21, 9, 6, 20,
	8, 3, 10, 20,
	3, 1, 1, 0,
	33, 3, 2, 60,
	12, 3, 11, 0,
	2,
	1, 6, 3, 7,
	9, 9, 5, 7,
};

constexpr const uint8_t Map_05_Shop[] = 
{
	11, /*Width*/
	19, /*Height*/
	5, /*Player Start X*/
	11, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	38, 38, 38, 38, 98, 24, 24, 24, 24, 24, 98,
	38, 38, 38, 38, 21, 0, 77, 78, 79, 0, 23,
	38, 38, 38, 38, 21, 0, 80, 81, 82, 4, 23,
	38, 38, 38, 38, 21, 4, 0, 0, 0, 0, 23,
	38, 38, 38, 38, 98, 22, 36, 0, 37, 22, 98,
	0, 24, 24, 24, 24, 98, 35, 0, 34, 24, 98,
	21, 0, 0, 0, 0, 46, 0, 0, 0, 0, 23,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23,
	21, 0, 0, 0, 0, 45, 0, 0, 0, 17, 23,
	98, 36, 0, 37, 22, 98, 22, 22, 22, 22, 98,
	98, 35, 16, 34, 24, 24, 24, 68, 24, 24, 98,
	21, 4, 4, 0, 0, 9, 4, 0, 4, 4, 23,
	66, 4, 0, 0, 0, 11, 0, 0, 0, 4, 65,
	21, 0, 0, 4, 0, 0, 0, 4, 0, 0, 23,
	98, 22, 22, 36, 59, 45, 59, 45, 59, 37, 98,
	38, 38, 38, 21, 0, 43, 0, 43, 0, 23, 38,
	38, 38, 38, 21, 0, 43, 0, 43, 0, 23, 38,
	38, 38, 38, 21, 11, 43, 8, 43, 11, 23, 38,
	38, 38, 38, 98, 22, 98, 22, 98, 22, 98, 38,
	6, 
	7, 4, 16, 1,
	7, 7, 7, 30,
	24, 7, 6, 60,
	34, 4, 6, 0,
	0, 1, 6, 0,
	0, 1, 7, 0,
	4,
	5, 12, 4, 14,
	8, 17, 6, 14,
	4, 17, 8, 14,
	8, 17, 2, 10,
};

constexpr const uint8_t Map_07[] = 
{
	9, /*Width*/
	12, /*Height*/
	1, /*Player Start X*/
	1, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	98, 24, 24, 24, 24, 98, 24, 24, 98,
	21, 9, 0, 0, 84, 46, 0, 0, 23,
	66, 0, 0, 0, 0, 4, 0, 0, 65,
	66, 0, 0, 0, 0, 45, 0, 0, 65,
	21, 97, 0, 0, 0, 43, 73, 0, 23,
	98, 48, 4, 47, 44, 98, 44, 44, 98,
	21, 0, 0, 0, 84, 43, 0, 73, 23,
	21, 96, 0, 0, 0, 43, 0, 0, 23,
	98, 44, 44, 44, 44, 35, 0, 0, 23,
	21, 0, 0, 0, 0, 0, 0, 0, 23,
	21, 3, 0, 0, 0, 0, 0, 28, 38,
	98, 22, 67, 22, 67, 22, 67, 38, 38,
	18, 
	0, 2, 2, 10,
	0, 2, 3, 10,
	0, 3, 3, 10,
	0, 3, 2, 10,
	3, 4, 7, 10,
	7, 4, 7, 50,
	7, 3, 7, 50,
	7, 2, 7, 50,
	6, 7, 4, 50,
	6, 7, 3, 50,
	6, 7, 2, 50,
	6, 7, 1, 50,
	0, 7, 1, 50,
	0, 7, 2, 50,
	35, 4, 7, 0,
	24, 5, 10, 60,
	11, 3, 9, 50,
	4, 4, 4, 0,
	2,
	6, 4, 7, 6,
	7, 6, 6, 4,
};

constexpr const uint8_t Map_09[] = 
{
	12, /*Width*/
	13, /*Height*/
	1, /*Player Start X*/
	1, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	98, 24, 68, 24, 68, 24, 24, 68, 24, 68, 24, 98,
	21, 9, 0, 0, 0, 0, 61, 0, 0, 0, 84, 23,
	21, 0, 0, 0, 4, 37, 44, 44, 48, 0, 37, 98,
	98, 44, 44, 44, 44, 35, 0, 40, 0, 0, 34, 98,
	21, 0, 0, 0, 0, 40, 0, 45, 0, 0, 8, 23,
	98, 22, 44, 44, 44, 36, 0, 34, 22, 22, 22, 98,
	38, 21, 0, 0, 8, 43, 0, 84, 23, 38, 38, 38,
	38, 66, 0, 47, 44, 35, 0, 0, 65, 38, 38, 38,
	38, 21, 0, 0, 0, 0, 0, 0, 23, 98, 24, 98,
	38, 98, 22, 22, 22, 36, 0, 47, 24, 35, 17, 23,
	38, 38, 38, 38, 38, 21, 0, 0, 0, 0, 0, 23,
	38, 38, 38, 38, 38, 21, 0, 0, 0, 0, 0, 23,
	38, 38, 38, 38, 38, 98, 22, 67, 22, 67, 22, 98,
	18, 
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
	36, 10, 11, 0,
	13, 6, 11, 0,
	24, 2, 8, 60,
	0,
};

constexpr const uint8_t Map_11_Shop[] = 
{
	13, /*Width*/
	11, /*Height*/
	2, /*Player Start X*/
	2, /*Player Start Y*/
	200, /*Timer*/
	1, /*Out of Bounds Tile ID*/
	98, 24, 24, 24, 98, 38, 38, 38, 38, 38, 38, 38, 38,
	21, 83, 9, 0, 23, 38, 38, 38, 38, 38, 38, 38, 38,
	66, 0, 0, 0, 65, 38, 38, 38, 38, 38, 38, 38, 38,
	21, 97, 0, 0, 23, 38, 38, 38, 38, 38, 38, 38, 38,
	98, 36, 0, 37, 98, 38, 98, 24, 68, 24, 68, 24, 98,
	38, 66, 0, 23, 38, 38, 21, 4, 77, 78, 79, 4, 23,
	38, 21, 0, 23, 38, 38, 21, 0, 80, 81, 82, 0, 23,
	38, 66, 0, 34, 24, 24, 35, 0, 0, 0, 0, 0, 23,
	38, 21, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 23,
	38, 98, 22, 22, 22, 22, 22, 22, 22, 22, 36, 3, 23,
	38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 98, 22, 98,
	4, 
	17, 2, 5, 0,
	18, 2, 6, 0,
	19, 4, 8, 0,
	20, 5, 8, 0,
	0,
};

constexpr const uint8_t Map_13[] = 
{
	11, /*Width*/
	12, /*Height*/
	3, /*Player Start X*/
	1, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	38, 38, 38, 24, 38, 38, 38, 38, 38, 38, 38,
	98, 24, 35, 9, 34, 24, 98, 24, 24, 98, 38,
	21, 0, 0, 0, 0, 11, 43, 83, 4, 23, 38,
	98, 44, 48, 59, 47, 44, 35, 4, 0, 23, 38,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 65, 38,
	98, 44, 48, 16, 47, 44, 36, 0, 4, 23, 38,
	21, 83, 0, 0, 0, 84, 43, 4, 4, 23, 38,
	21, 0, 0, 17, 0, 0, 43, 4, 11, 65, 38,
	98, 22, 67, 22, 67, 22, 21, 16, 16, 23, 38,
	38, 38, 38, 38, 38, 38, 21, 0, 0, 23, 38,
	38, 38, 38, 38, 38, 38, 21, 0, 8, 23, 38,
	38, 38, 38, 38, 38, 38, 98, 22, 22, 98, 38,
	8, 
	6, 7, 10, 10,
	7, 8, 9, 10,
	6, 7, 9, 10,
	7, 7, 10, 30,
	6, 7, 9, 30,
	7, 8, 9, 30,
	37, 5, 7, 0,
	2, 1, 7, 0,
	4,
	5, 2, 3, 3,
	8, 7, 8, 8,
	8, 7, 7, 8,
	8, 7, 3, 5,
};

constexpr const uint8_t Map_15[] = 
{
	12, /*Width*/
	12, /*Height*/
	1, /*Player Start X*/
	1, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	98, 24, 24, 24, 98, 24, 68, 24, 68, 24, 98, 38,
	21, 9, 0, 97, 43, 83, 0, 0, 0, 84, 23, 38,
	21, 0, 0, 37, 35, 0, 0, 45, 0, 0, 23, 38,
	98, 48, 4, 46, 83, 0, 28, 25, 0, 37, 98, 38,
	21, 0, 0, 0, 0, 0, 43, 0, 0, 34, 24, 98,
	21, 0, 0, 37, 44, 44, 35, 0, 0, 0, 84, 23,
	98, 22, 22, 25, 0, 0, 0, 0, 45, 0, 0, 65,
	38, 0, 25, 0, 0, 0, 0, 28, 24, 48, 0, 65,
	38, 21, 0, 0, 0, 0, 28, 25, 0, 0, 0, 23,
	38, 66, 0, 0, 37, 22, 25, 0, 0, 0, 37, 98,
	38, 21, 17, 0, 23, 21, 0, 0, 0, 37, 98, 38,
	38, 98, 22, 22, 98, 98, 22, 22, 22, 98, 38, 38,
	13, 
	3, 6, 10, 30,
	7, 2, 5, 30,
	7, 1, 5, 30,
	7, 1, 4, 30,
	8, 8, 1, 30,
	8, 9, 2, 30,
	6, 8, 9, 30,
	19, 3, 4, 0,
	2, 8, 10, 0,
	38, 5, 8, 0,
	24, 9, 8, 60,
	6, 2, 8, 40,
	8, 3, 9, 20,
	0,
};

constexpr const uint8_t Map_17_Shop[] = 
{
	12, /*Width*/
	16, /*Height*/
	1, /*Player Start X*/
	5, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	38, 38, 38, 38, 38, 98, 24, 24, 24, 24, 24, 0,
	38, 38, 38, 38, 38, 21, 0, 77, 78, 79, 0, 23,
	38, 38, 38, 38, 38, 21, 0, 80, 81, 82, 0, 23,
	38, 38, 38, 38, 38, 21, 0, 0, 0, 0, 0, 65,
	98, 24, 0, 98, 24, 24, 44, 44, 44, 48, 60, 23,
	21, 9, 23, 35, 0, 0, 39, 0, 0, 0, 0, 23,
	21, 0, 46, 0, 0, 37, 22, 22, 22, 36, 0, 65,
	21, 0, 0, 0, 47, 98, 0, 24, 24, 35, 0, 23,
	98, 36, 0, 45, 0, 23, 21, 83, 0, 0, 0, 23,
	98, 35, 0, 46, 0, 65, 66, 0, 0, 0, 0, 65,
	21, 0, 0, 0, 0, 23, 21, 0, 0, 0, 0, 23,
	66, 4, 45, 0, 47, 24, 24, 44, 44, 22, 22, 98,
	21, 0, 43, 0, 0, 0, 0, 0, 10, 23, 38, 38,
	66, 0, 23, 22, 36, 41, 37, 22, 22, 38, 38, 38,
	21, 0, 23, 38, 21, 3, 23, 38, 38, 38, 38, 38,
	98, 22, 98, 38, 98, 22, 98, 38, 38, 38, 38, 38,
	13, 
	3, 1, 14, 1,
	5, 4, 8, 30,
	6, 4, 8, 30,
	3, 4, 8, 1,
	1, 7, 9, 1,
	1, 8, 9, 1,
	1, 9, 9, 1,
	1, 10, 9, 1,
	19, 7, 5, 0,
	20, 8, 5, 0,
	17, 2, 8, 0,
	21, 7, 10, 20,
	24, 10, 8, 60,
	1,
	8, 12, 10, 4,
};

constexpr const uint8_t Map_19[] = 
{
	11, /*Width*/
	11, /*Height*/
	6, /*Player Start X*/
	9, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	98, 24, 24, 24, 98, 24, 24, 24, 24, 24, 98,
	21, 10, 0, 84, 43, 0, 0, 0, 0, 0, 23,
	21, 0, 0, 97, 43, 0, 37, 22, 36, 0, 65,
	98, 48, 0, 47, 35, 64, 34, 24, 21, 0, 23,
	21, 0, 0, 0, 58, 0, 0, 0, 43, 0, 65,
	98, 44, 44, 44, 48, 0, 0, 11, 43, 0, 23,
	21, 0, 0, 0, 62, 0, 0, 0, 43, 0, 65,
	21, 59, 47, 44, 44, 22, 44, 44, 35, 0, 23,
	21, 0, 0, 0, 84, 43, 83, 0, 0, 0, 65,
	21, 0, 0, 0, 17, 43, 9, 0, 0, 0, 23,
	98, 22, 22, 22, 22, 98, 22, 22, 22, 22, 98,
	11, 
	3, 2, 2, 30,
	8, 2, 2, 30,
	6, 6, 5, 30,
	7, 9, 4, 30,
	7, 6, 1, 30,
	19, 2, 8, 0,
	20, 2, 9, 0,
	17, 9, 7, 0,
	18, 9, 5, 0,
	10, 9, 9, 0,
	39, 7, 6, 0,
	5,
	7, 5, 5, 3,
	7, 5, 4, 4,
	7, 5, 4, 6,
	1, 1, 4, 6,
	1, 1, 1, 7,
};

constexpr const uint8_t Map_21_BossNecro[] = 
{
	14, /*Width*/
	13, /*Height*/
	2, /*Player Start X*/
	7, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	38, 38, 38, 38, 38, 38, 98, 24, 24, 24, 24, 24, 98, 0,
	38, 38, 38, 38, 38, 38, 21, 0, 0, 0, 0, 0, 23, 0,
	38, 38, 38, 38, 38, 38, 21, 0, 0, 0, 0, 0, 23, 0,
	38, 38, 38, 38, 38, 38, 21, 3, 0, 0, 0, 0, 23, 0,
	38, 38, 38, 38, 38, 38, 98, 22, 36, 0, 37, 22, 98, 0,
	98, 24, 68, 24, 98, 38, 0, 24, 21, 0, 65, 38, 38, 0,
	21, 83, 0, 0, 34, 68, 35, 8, 43, 0, 23, 38, 38, 0,
	66, 0, 9, 0, 39, 0, 0, 4, 43, 0, 34, 98, 38, 0,
	21, 0, 0, 0, 45, 0, 0, 37, 21, 0, 0, 23, 38, 0,
	98, 48, 4, 47, 0, 48, 41, 34, 24, 48, 0, 65, 38, 0,
	21, 0, 0, 0, 43, 0, 0, 0, 0, 0, 0, 23, 38, 0,
	21, 0, 0, 0, 23, 36, 0, 37, 67, 67, 22, 98, 38, 0,
	98, 22, 67, 22, 98, 98, 22, 98, 38, 38, 38, 38, 38, 0,
	19, 
	2, 2, 11, 20,
	7, 3, 10, 20,
	7, 1, 10, 20,
	8, 6, 7, 20,
	3, 1, 11, 20,
	8, 5, 8, 20,
	8, 6, 11, 20,
	7, 5, 10, 20,
	6, 8, 10, 20,
	5, 9, 8, 20,
	6, 10, 10, 20,
	18, 10, 9, 0,
	20, 9, 10, 0,
	23, 8, 2, 60,
	11, 11, 2, 50,
	0, 8, 1, 0,
	0, 10, 1, 0,
	10, 6, 11, 0,
	8, 9, 4, 20,
	0,
};

constexpr const uint8_t Map_23_Shop[] = 
{
	15, /*Width*/
	11, /*Height*/
	2, /*Player Start X*/
	8, /*Player Start Y*/
	200, /*Timer*/
	1, /*Out of Bounds Tile ID*/
	38, 38, 38, 98, 24, 68, 68, 68, 24, 98, 38, 38, 38, 38, 38,
	38, 38, 38, 21, 0, 0, 0, 0, 0, 23, 38, 38, 24, 38, 38,
	38, 38, 38, 21, 0, 77, 78, 79, 0, 34, 68, 25, 0, 26, 0,
	38, 38, 38, 21, 0, 80, 81, 82, 0, 0, 0, 0, 3, 0, 23,
	38, 38, 38, 21, 0, 0, 0, 0, 0, 37, 22, 27, 0, 28, 38,
	38, 38, 38, 98, 22, 36, 0, 37, 22, 98, 38, 38, 67, 38, 38,
	38, 38, 24, 38, 38, 66, 0, 65, 38, 38, 38, 38, 38, 38, 38,
	0, 25, 0, 26, 24, 35, 0, 23, 38, 38, 38, 38, 38, 38, 38,
	66, 0, 9, 0, 0, 0, 0, 65, 38, 38, 38, 38, 38, 38, 38,
	38, 27, 97, 28, 67, 67, 67, 98, 38, 38, 38, 38, 38, 38, 38,
	38, 38, 22, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38,
	3, 
	20, 4, 8, 0,
	20, 5, 8, 0,
	21, 6, 5, 20,
	0,
};

constexpr const uint8_t Map_25[] = 
{
	18, /*Width*/
	11, /*Height*/
	1, /*Player Start X*/
	2, /*Player Start Y*/
	200, /*Timer*/
	1, /*Out of Bounds Tile ID*/
	38, 38, 38, 98, 24, 68, 24, 68, 24, 68, 24, 68, 24, 98, 38, 38, 38, 38,
	98, 24, 24, 21, 8, 0, 0, 0, 0, 0, 0, 0, 84, 23, 24, 24, 24, 98,
	21, 9, 0, 43, 0, 0, 4, 37, 36, 0, 47, 48, 0, 43, 0, 0, 0, 23,
	66, 0, 0, 43, 0, 4, 4, 23, 21, 0, 0, 0, 0, 43, 96, 45, 0, 65,
	21, 0, 0, 46, 0, 37, 22, 0, 0, 22, 48, 0, 0, 34, 44, 35, 0, 23,
	21, 0, 0, 0, 0, 23, 0, 24, 24, 35, 0, 0, 0, 39, 0, 0, 0, 23,
	21, 0, 0, 45, 0, 23, 21, 0, 0, 0, 0, 47, 44, 36, 0, 37, 22, 98,
	66, 0, 0, 43, 0, 23, 21, 0, 37, 36, 0, 0, 0, 43, 0, 65, 38, 0,
	21, 0, 0, 46, 0, 34, 35, 0, 34, 24, 48, 0, 0, 43, 0, 34, 24, 98,
	21, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88, 43, 0, 0, 3, 23,
	98, 22, 22, 67, 22, 67, 22, 67, 22, 67, 22, 67, 22, 98, 22, 67, 22, 38,
	13, 
	6, 15, 2, 40,
	7, 14, 2, 30,
	8, 6, 1, 20,
	8, 4, 2, 20,
	8, 4, 6, 20,
	8, 4, 8, 20,
	18, 14, 8, 0,
	17, 14, 7, 0,
	19, 15, 5, 0,
	19, 8, 6, 0,
	19, 8, 9, 0,
	19, 8, 1, 0,
	15, 10, 7, 0,
	0,
};

constexpr const uint8_t Map_27[] = 
{
	11, /*Width*/
	12, /*Height*/
	4, /*Player Start X*/
	2, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	98, 24, 24, 24, 24, 98, 38, 38, 38, 38, 38,
	21, 4, 4, 4, 0, 34, 68, 24, 98, 24, 98,
	66, 4, 33, 4, 0, 0, 0, 84, 46, 3, 23,
	21, 4, 4, 0, 97, 45, 0, 0, 57, 0, 23,
	98, 22, 44, 44, 44, 21, 0, 47, 44, 44, 98,
	38, 21, 0, 0, 0, 43, 0, 4, 0, 0, 23,
	38, 66, 0, 45, 42, 34, 44, 44, 48, 0, 65,
	38, 21, 0, 43, 0, 4, 0, 0, 0, 0, 23,
	38, 66, 0, 34, 44, 36, 0, 47, 44, 44, 98,
	38, 21, 0, 0, 11, 43, 0, 0, 4, 8, 23,
	38, 98, 22, 22, 22, 98, 22, 22, 22, 22, 98,
	38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38,
	12, 
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
	2, 9, 3, 0,
	1,
	4, 9, 8, 3,
};

constexpr const uint8_t Map_29_Shop[] = 
{
	22, /*Width*/
	15, /*Height*/
	5, /*Player Start X*/
	9, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 98, 24, 24, 24, 24, 24, 24, 24, 24, 24, 98,
	38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 21, 83, 0, 0, 0, 0, 77, 78, 79, 0, 23,
	38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 21, 0, 0, 0, 45, 0, 80, 81, 82, 0, 23,
	38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 21, 3, 0, 0, 43, 0, 0, 0, 0, 0, 23,
	98, 24, 68, 24, 68, 24, 68, 24, 68, 24, 98, 98, 44, 44, 44, 21, 0, 0, 0, 0, 0, 23,
	21, 0, 0, 0, 0, 14, 0, 0, 0, 0, 23, 21, 0, 0, 0, 43, 0, 0, 47, 44, 44, 98,
	66, 0, 33, 0, 33, 0, 33, 0, 33, 0, 65, 21, 73, 45, 0, 43, 0, 0, 57, 0, 0, 23,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23, 98, 44, 35, 60, 34, 44, 44, 44, 48, 60, 23,
	66, 0, 33, 0, 33, 0, 33, 0, 33, 0, 65, 21, 10, 0, 0, 58, 0, 0, 0, 0, 0, 23,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 24, 44, 36, 0, 45, 10, 45, 0, 45, 10, 23,
	66, 0, 33, 0, 33, 0, 33, 0, 33, 0, 57, 0, 0, 43, 60, 34, 22, 35, 60, 34, 44, 98,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45, 10, 0, 43, 0, 0, 43, 0, 0, 0, 10, 23,
	66, 0, 33, 0, 33, 17, 33, 0, 33, 0, 43, 10, 0, 34, 48, 60, 46, 60, 47, 44, 44, 98,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43, 10, 0, 0, 0, 0, 0, 0, 0, 0, 73, 23,
	98, 22, 67, 22, 67, 22, 67, 22, 67, 22, 98, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 98,
	17, 
	1, 1, 13, 100,
	3, 1, 5, 100,
	1, 9, 5, 100,
	0, 9, 13, 100,
	21, 14, 3, 20,
	8, 3, 6, 20,
	8, 5, 6, 20,
	8, 7, 6, 20,
	8, 8, 7, 20,
	8, 8, 9, 20,
	8, 8, 11, 20,
	8, 7, 12, 20,
	8, 3, 12, 20,
	8, 2, 11, 20,
	8, 2, 9, 20,
	8, 2, 7, 20,
	8, 5, 12, 20,
	12,
	11, 11, 15, 12,
	11, 11, 18, 10,
	11, 12, 14, 10,
	16, 9, 12, 8,
	20, 9, 14, 7,
	20, 9, 20, 7,
	5, 5, 10, 10,
	12, 6, 20, 13,
	20, 13, 12, 6,
	11, 13, 17, 12,
	11, 13, 18, 10,
	16, 9, 18, 6,
};

constexpr const uint8_t Map_31[] = 
{
	12, /*Width*/
	11, /*Height*/
	6, /*Player Start X*/
	5, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	38, 38, 38, 38, 98, 24, 24, 98, 38, 38, 38, 38,
	98, 24, 24, 24, 21, 0, 84, 23, 24, 24, 24, 98,
	21, 0, 0, 0, 43, 0, 0, 43, 0, 0, 0, 23,
	21, 16, 16, 16, 43, 0, 0, 43, 16, 16, 16, 23,
	66, 0, 0, 0, 46, 0, 0, 46, 0, 0, 0, 65,
	21, 17, 0, 14, 53, 0, 0, 54, 14, 0, 17, 23,
	66, 0, 0, 0, 45, 0, 0, 45, 0, 0, 0, 65,
	21, 16, 16, 16, 43, 0, 0, 43, 16, 16, 16, 23,
	21, 0, 0, 0, 43, 0, 0, 43, 0, 0, 0, 23,
	98, 22, 22, 22, 21, 86, 97, 23, 22, 22, 22, 98,
	38, 38, 38, 38, 98, 22, 22, 98, 38, 38, 38, 38,
	14, 
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
	14, 5, 1, 0,
	24, 8, 8, 60,
	24, 10, 8, 60,
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

constexpr const uint8_t Map_33_BossCyclops[] = 
{
	13, /*Width*/
	14, /*Height*/
	7, /*Player Start X*/
	8, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	38, 38, 98, 24, 68, 24, 98, 38, 98, 24, 68, 24, 98,
	38, 38, 21, 0, 0, 84, 34, 24, 35, 0, 8, 0, 23,
	38, 38, 21, 88, 0, 0, 0, 14, 0, 0, 33, 42, 23,
	38, 38, 98, 36, 59, 33, 0, 0, 0, 33, 0, 0, 23,
	38, 38, 38, 66, 0, 0, 33, 0, 33, 0, 0, 37, 98,
	38, 38, 38, 66, 14, 0, 0, 33, 0, 0, 14, 65, 38,
	38, 38, 98, 35, 0, 0, 33, 8, 33, 0, 0, 65, 38,
	38, 38, 21, 0, 59, 33, 0, 0, 0, 33, 59, 34, 98,
	38, 38, 21, 0, 33, 0, 0, 9, 0, 61, 0, 0, 23,
	98, 24, 35, 0, 0, 37, 22, 22, 22, 36, 0, 10, 23,
	21, 0, 0, 0, 0, 23, 38, 38, 38, 98, 22, 22, 98,
	21, 0, 0, 0, 0, 23, 38, 38, 38, 38, 38, 38, 38,
	21, 3, 0, 0, 0, 23, 38, 38, 38, 38, 38, 38, 38,
	98, 22, 22, 22, 22, 98, 38, 38, 38, 38, 38, 38, 38,
	17, 
	7, 9, 5, 50,
	7, 10, 4, 50,
	8, 11, 1, 50,
	8, 11, 1, 50,
	6, 3, 1, 50,
	6, 3, 1, 50,
	6, 4, 4, 50,
	6, 5, 5, 50,
	21, 9, 5, 20,
	17, 3, 8, 0,
	20, 7, 4, 0,
	41, 1, 10, 120,
	1, 4, 12, 0,
	8, 3, 12, 20,
	8, 2, 12, 20,
	42, 1, 10, 120,
	21, 8, 2, 20,
	5,
	11, 9, 10, 7,
	11, 9, 9, 8,
	10, 5, 4, 3,
	4, 3, 4, 5,
	4, 5, 4, 7,
};

constexpr const uint8_t Map_35_Shop[] = 
{
	17, /*Width*/
	14, /*Height*/
	8, /*Player Start X*/
	2, /*Player Start Y*/
	200, /*Timer*/
	1, /*Out of Bounds Tile ID*/
	38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38,
	38, 38, 38, 38, 38, 38, 38, 38, 68, 38, 38, 38, 38, 38, 38, 38, 38,
	38, 38, 38, 38, 38, 38, 38, 25, 0, 26, 38, 38, 38, 38, 38, 38, 38,
	38, 38, 38, 38, 38, 38, 66, 0, 73, 97, 65, 38, 38, 38, 38, 38, 38,
	38, 38, 38, 38, 38, 38, 38, 27, 0, 28, 38, 38, 38, 38, 38, 38, 38,
	38, 38, 38, 38, 38, 24, 38, 38, 67, 38, 0, 24, 0, 38, 38, 38, 38,
	38, 38, 38, 38, 25, 0, 26, 24, 68, 24, 25, 0, 26, 0, 38, 38, 38,
	38, 38, 38, 21, 0, 73, 0, 0, 0, 0, 0, 73, 0, 23, 38, 38, 38,
	38, 38, 38, 38, 27, 0, 28, 22, 22, 22, 27, 0, 28, 38, 38, 38, 38,
	38, 38, 24, 38, 38, 22, 38, 68, 68, 68, 38, 22, 38, 38, 24, 38, 38,
	38, 25, 0, 26, 68, 24, 25, 77, 78, 79, 26, 24, 68, 25, 0, 26, 38,
	21, 0, 73, 0, 0, 0, 0, 80, 81, 82, 0, 0, 0, 0, 3, 0, 65,
	38, 27, 0, 28, 22, 67, 27, 0, 0, 0, 28, 67, 22, 27, 0, 28, 38,
	38, 38, 22, 38, 38, 38, 38, 67, 22, 67, 38, 38, 38, 38, 22, 38, 38,
	7, 
	6, 9, 7, 40,
	8, 6, 11, 20,
	8, 5, 11, 20,
	8, 11, 11, 20,
	8, 12, 11, 20,
	3, 5, 6, 0,
	4, 12, 7, 0,
	4,
	8, 3, 5, 7,
	5, 7, 8, 3,
	11, 7, 2, 11,
	2, 11, 11, 7,
};

constexpr const uint8_t Map_37[] = 
{
	14, /*Width*/
	20, /*Height*/
	3, /*Player Start X*/
	2, /*Player Start Y*/
	200, /*Timer*/
	1, /*Out of Bounds Tile ID*/
	38, 98, 24, 24, 24, 98, 38, 38, 38, 24, 24, 38, 38, 38,
	38, 21, 0, 0, 0, 23, 38, 38, 25, 0, 0, 26, 38, 38,
	38, 66, 0, 9, 0, 65, 38, 21, 0, 0, 0, 0, 23, 38,
	38, 21, 0, 0, 0, 23, 38, 21, 0, 0, 0, 0, 23, 38,
	38, 98, 36, 0, 37, 98, 38, 38, 27, 0, 0, 28, 38, 38,
	38, 38, 21, 0, 65, 38, 38, 38, 21, 0, 0, 23, 38, 38,
	98, 24, 35, 0, 34, 24, 0, 24, 35, 0, 0, 34, 24, 98,
	21, 83, 0, 0, 0, 0, 43, 0, 0, 0, 0, 0, 0, 23,
	21, 0, 0, 0, 0, 0, 46, 0, 33, 0, 0, 33, 0, 23,
	66, 0, 0, 0, 0, 0, 57, 0, 0, 0, 0, 0, 0, 65,
	21, 0, 0, 0, 0, 0, 45, 0, 33, 0, 0, 33, 0, 23,
	21, 19, 0, 0, 0, 87, 43, 0, 0, 0, 0, 0, 0, 23,
	98, 22, 22, 22, 22, 22, 0, 22, 36, 0, 0, 37, 22, 98,
	38, 38, 38, 38, 38, 38, 38, 38, 66, 0, 0, 65, 38, 38,
	38, 38, 24, 24, 0, 98, 24, 24, 35, 0, 0, 34, 24, 98,
	38, 25, 0, 0, 26, 35, 0, 0, 0, 0, 0, 0, 0, 23,
	21, 0, 0, 0, 0, 0, 0, 33, 0, 0, 0, 33, 0, 23,
	21, 0, 3, 0, 0, 0, 0, 0, 0, 33, 0, 0, 0, 23,
	38, 27, 0, 0, 28, 36, 86, 0, 0, 0, 0, 0, 85, 23,
	38, 38, 22, 22, 38, 98, 22, 67, 22, 67, 22, 67, 22, 98,
	33, 
	9, 5, 7, 0,
	11, 2, 15, 50,
	7, 3, 15, 30,
	7, 2, 16, 30,
	7, 3, 16, 30,
	7, 3, 17, 30,
	7, 3, 18, 30,
	0, 1, 16, 0,
	0, 1, 17, 0,
	0, 9, 1, 0,
	0, 10, 1, 0,
	21, 4, 11, 20,
	21, 2, 9, 20,
	8, 3, 6, 20,
	8, 8, 2, 20,
	8, 10, 2, 20,
	8, 11, 2, 20,
	8, 9, 2, 20,
	17, 9, 6, 0,
	17, 9, 13, 0,
	18, 10, 6, 0,
	18, 10, 13, 0,
	19, 5, 16, 0,
	20, 5, 17, 0,
	4, 12, 11, 0,
	6, 12, 8, 40,
	14, 11, 18, 0,
	0, 1, 8, 0,
	0, 1, 9, 0,
	0, 9, 3, 0,
	0, 10, 3, 0,
	0, 9, 16, 0,
	21, 12, 10, 20,
	1,
	1, 11, 6, 9,
};

constexpr const uint8_t Map_39[] = 
{
	12, /*Width*/
	11, /*Height*/
	2, /*Player Start X*/
	2, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	98, 24, 68, 24, 98, 24, 68, 24, 24, 68, 24, 98,
	21, 97, 0, 0, 43, 83, 0, 0, 0, 0, 10, 23,
	21, 0, 9, 0, 43, 0, 0, 45, 0, 0, 0, 23,
	98, 44, 48, 0, 43, 0, 47, 21, 0, 47, 44, 98,
	21, 0, 0, 0, 46, 0, 0, 43, 0, 0, 0, 23,
	21, 14, 0, 0, 16, 0, 0, 43, 0, 0, 0, 65,
	98, 44, 44, 44, 22, 44, 44, 24, 22, 48, 0, 23,
	21, 0, 0, 84, 46, 0, 0, 0, 46, 0, 0, 23,
	66, 0, 0, 0, 58, 0, 17, 0, 0, 0, 0, 65,
	21, 0, 0, 0, 45, 0, 0, 0, 45, 11, 0, 23,
	98, 22, 67, 22, 98, 22, 67, 22, 98, 22, 22, 98,
	18, 
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
	17, 5, 3, 0,
	18, 8, 3, 0,
	19, 7, 1, 0,
	13, 10, 4, 0,
	21, 1, 7, 20,
	21, 3, 9, 20,
	24, 1, 9, 60,
	3,
	10, 1, 4, 8,
	9, 9, 4, 8,
	1, 5, 4, 5,
};

constexpr const uint8_t Map_41_Shop[] = 
{
	14, /*Width*/
	19, /*Height*/
	5, /*Player Start X*/
	1, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	98, 24, 68, 24, 68, 24, 68, 24, 68, 24, 98, 38, 38, 38,
	21, 0, 0, 0, 0, 9, 0, 0, 0, 0, 23, 38, 38, 38,
	66, 0, 14, 0, 14, 0, 14, 0, 14, 0, 65, 38, 38, 38,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23, 38, 38, 38,
	66, 0, 14, 0, 14, 0, 14, 0, 14, 0, 65, 38, 38, 38,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23, 38, 38, 38,
	66, 0, 14, 0, 14, 0, 14, 0, 14, 0, 65, 38, 38, 38,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23, 38, 38, 38,
	98, 22, 67, 22, 36, 59, 37, 22, 67, 22, 98, 38, 38, 38,
	38, 38, 38, 38, 21, 0, 23, 98, 24, 24, 24, 24, 24, 98,
	38, 38, 38, 38, 21, 59, 23, 21, 0, 77, 78, 79, 0, 23,
	38, 38, 38, 38, 21, 0, 23, 21, 0, 80, 81, 82, 0, 23,
	38, 38, 38, 38, 21, 59, 23, 21, 0, 0, 0, 0, 0, 23,
	98, 24, 24, 24, 35, 0, 34, 35, 0, 47, 44, 48, 0, 23,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23,
	21, 0, 37, 22, 67, 22, 67, 22, 67, 22, 67, 22, 67, 98,
	21, 0, 23, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38,
	21, 3, 23, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38,
	98, 22, 98, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38,
	6, 
	7, 11, 14, 30,
	7, 1, 16, 30,
	8, 5, 13, 20,
	8, 5, 11, 20,
	8, 5, 9, 20,
	6, 9, 14, 40,
	3,
	4, 2, 5, 8,
	8, 4, 5, 10,
	2, 6, 5, 12,
};

constexpr const uint8_t Map_43[] = 
{
	17, /*Width*/
	21, /*Height*/
	3, /*Player Start X*/
	1, /*Player Start Y*/
	200, /*Timer*/
	1, /*Out of Bounds Tile ID*/
	98, 24, 68, 24, 68, 24, 98, 38, 98, 24, 68, 24, 68, 24, 98, 38, 38,
	21, 87, 0, 9, 0, 8, 23, 38, 21, 0, 0, 0, 0, 84, 23, 38, 38,
	66, 0, 0, 0, 0, 0, 23, 38, 21, 0, 0, 0, 0, 0, 34, 24, 98,
	21, 0, 0, 0, 0, 97, 23, 24, 24, 44, 48, 0, 0, 0, 39, 0, 23,
	66, 0, 0, 0, 0, 0, 43, 0, 0, 0, 0, 0, 0, 0, 45, 0, 65,
	21, 0, 0, 0, 0, 0, 43, 0, 0, 0, 45, 0, 0, 0, 43, 0, 23,
	98, 22, 36, 41, 37, 44, 35, 0, 0, 0, 23, 44, 44, 44, 35, 0, 23,
	38, 38, 66, 0, 43, 0, 0, 0, 0, 0, 43, 10, 0, 0, 39, 0, 23,
	38, 38, 21, 0, 43, 0, 0, 0, 0, 96, 43, 0, 0, 37, 36, 0, 65,
	38, 38, 66, 0, 34, 44, 48, 60, 47, 44, 35, 0, 0, 23, 21, 0, 23,
	38, 38, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 85, 23, 21, 73, 23,
	38, 38, 98, 22, 67, 22, 67, 22, 22, 67, 22, 67, 22, 98, 38, 22, 38,
	98, 24, 24, 24, 24, 24, 98, 38, 38, 38, 98, 24, 24, 24, 24, 24, 98,
	21, 73, 0, 0, 0, 19, 23, 38, 38, 38, 21, 0, 0, 0, 0, 84, 23,
	66, 0, 33, 0, 33, 0, 23, 24, 24, 24, 21, 0, 33, 0, 33, 0, 65,
	66, 0, 0, 0, 0, 0, 43, 0, 0, 0, 43, 0, 0, 0, 0, 0, 23,
	66, 0, 33, 0, 33, 0, 46, 0, 0, 0, 46, 0, 33, 0, 33, 0, 65,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 23,
	98, 22, 22, 22, 22, 36, 0, 0, 0, 0, 0, 37, 22, 22, 22, 22, 98,
	38, 38, 38, 38, 38, 21, 86, 0, 0, 0, 0, 23, 38, 38, 38, 38, 38,
	38, 38, 38, 38, 38, 98, 22, 67, 22, 67, 22, 98, 38, 38, 38, 38, 38,
	21, 
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
	10, 5, 5, 0,
	4, 15, 5, 0,
	3,
	15, 10, 1, 13,
	1, 13, 15, 10,
	11, 7, 7, 9,
};

constexpr const uint8_t Map_45[] = 
{
	20, /*Width*/
	19, /*Height*/
	2, /*Player Start X*/
	1, /*Player Start Y*/
	200, /*Timer*/
	1, /*Out of Bounds Tile ID*/
	98, 24, 24, 24, 24, 24, 38, 38, 38, 38, 38, 38, 38, 38, 24, 24, 24, 24, 24, 98,
	21, 9, 0, 0, 0, 0, 26, 38, 38, 38, 38, 38, 38, 25, 0, 0, 0, 0, 0, 23,
	21, 0, 0, 0, 0, 0, 0, 26, 38, 38, 38, 38, 25, 0, 0, 0, 0, 0, 0, 23,
	66, 0, 0, 37, 22, 27, 0, 0, 26, 24, 24, 25, 0, 0, 28, 22, 36, 0, 0, 65,
	21, 0, 0, 23, 38, 38, 27, 0, 0, 0, 0, 0, 0, 28, 38, 38, 21, 0, 0, 23,
	21, 0, 0, 23, 38, 38, 38, 27, 0, 0, 0, 0, 28, 38, 38, 38, 21, 0, 0, 23,
	21, 0, 0, 23, 38, 38, 38, 66, 0, 0, 0, 0, 65, 38, 38, 38, 21, 0, 0, 23,
	66, 0, 0, 34, 24, 24, 24, 35, 0, 0, 0, 0, 34, 24, 24, 24, 35, 0, 0, 65,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23,
	66, 0, 0, 37, 22, 22, 22, 36, 0, 0, 0, 0, 37, 22, 22, 22, 36, 0, 0, 65,
	21, 0, 0, 23, 38, 38, 38, 66, 0, 0, 0, 0, 65, 38, 38, 38, 21, 0, 0, 23,
	21, 0, 0, 23, 38, 38, 38, 25, 0, 0, 0, 0, 26, 38, 38, 38, 21, 0, 0, 23,
	21, 0, 0, 23, 38, 38, 25, 0, 0, 0, 0, 0, 0, 26, 38, 38, 21, 0, 0, 23,
	66, 0, 0, 34, 24, 25, 0, 0, 28, 22, 22, 27, 0, 0, 26, 24, 35, 0, 0, 65,
	21, 0, 0, 0, 0, 0, 0, 28, 38, 38, 38, 38, 27, 0, 0, 0, 0, 0, 0, 23,
	21, 0, 0, 0, 0, 0, 28, 38, 38, 38, 38, 38, 38, 27, 0, 0, 0, 0, 0, 23,
	21, 0, 0, 0, 0, 28, 38, 38, 38, 38, 38, 38, 38, 38, 27, 0, 0, 0, 3, 23,
	98, 22, 22, 22, 22, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 22, 22, 22, 22, 98,
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

constexpr const uint8_t Map_47[] = 
{
	21, /*Width*/
	19, /*Height*/
	1, /*Player Start X*/
	1, /*Player Start Y*/
	200, /*Timer*/
	1, /*Out of Bounds Tile ID*/
	98, 24, 24, 68, 24, 24, 68, 24, 24, 68, 24, 24, 68, 24, 24, 24, 98, 24, 68, 24, 98,
	21, 9, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 43, 0, 0, 0, 23,
	66, 0, 45, 0, 37, 44, 44, 44, 48, 0, 37, 44, 44, 44, 48, 0, 46, 0, 45, 0, 65,
	21, 0, 43, 0, 43, 0, 0, 0, 0, 0, 43, 0, 0, 0, 0, 0, 57, 0, 43, 0, 23,
	21, 4, 43, 0, 34, 44, 22, 44, 48, 0, 43, 0, 37, 44, 48, 0, 37, 44, 35, 0, 65,
	66, 0, 46, 0, 0, 0, 43, 0, 0, 0, 43, 0, 43, 0, 0, 0, 43, 0, 0, 0, 23,
	21, 0, 0, 0, 45, 0, 43, 59, 47, 44, 21, 0, 43, 0, 45, 0, 43, 0, 37, 44, 98,
	98, 44, 36, 0, 43, 97, 43, 0, 0, 0, 43, 0, 43, 0, 43, 0, 46, 60, 46, 73, 23,
	21, 10, 46, 0, 34, 44, 0, 44, 36, 63, 43, 0, 43, 0, 43, 0, 0, 0, 0, 0, 23,
	66, 0, 0, 0, 0, 0, 43, 0, 46, 0, 43, 0, 46, 0, 34, 44, 44, 22, 48, 0, 65,
	21, 0, 37, 44, 48, 0, 43, 0, 0, 0, 43, 0, 0, 0, 0, 0, 0, 43, 0, 0, 23,
	66, 0, 43, 10, 0, 0, 34, 44, 44, 44, 24, 44, 44, 44, 44, 48, 0, 43, 0, 47, 98,
	21, 73, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43, 0, 0, 23,
	98, 44, 0, 44, 44, 44, 44, 44, 44, 36, 0, 37, 44, 44, 44, 44, 44, 24, 22, 44, 98,
	21, 0, 43, 10, 0, 4, 0, 0, 0, 43, 0, 43, 0, 0, 0, 4, 0, 10, 43, 3, 23,
	21, 0, 43, 0, 0, 0, 0, 45, 42, 43, 0, 43, 42, 45, 0, 0, 0, 0, 43, 0, 23,
	66, 0, 46, 0, 0, 0, 0, 43, 0, 46, 0, 46, 0, 43, 0, 0, 0, 0, 46, 0, 65,
	21, 0, 58, 0, 0, 0, 0, 43, 0, 0, 0, 0, 0, 43, 0, 0, 0, 0, 57, 0, 23,
	98, 22, 22, 22, 67, 22, 22, 98, 22, 67, 22, 67, 22, 98, 22, 22, 67, 22, 22, 22, 98,
	25, 
	3, 17, 5, 0,
	8, 19, 12, 20,
	8, 18, 11, 20,
	8, 1, 14, 20,
	8, 5, 3, 20,
	3, 7, 9, 0,
	6, 16, 17, 40,
	6, 4, 17, 40,
	19, 13, 3, 0,
	20, 7, 12, 0,
	19, 13, 12, 0,
	21, 11, 7, 20,
	21, 7, 5, 20,
	7, 12, 1, 30,
	10, 17, 1, 0,
	21, 5, 17, 20,
	21, 15, 17, 20,
	8, 10, 17, 20,
	8, 10, 16, 20,
	19, 8, 12, 0,
	20, 14, 12, 0,
	8, 1, 9, 20,
	10, 11, 10, 0,
	2, 2, 6, 0,
	1, 8, 14, 0,
	7,
	3, 14, 18, 17,
	17, 14, 2, 17,
	1, 8, 16, 3,
	1, 8, 17, 7,
	1, 8, 9, 8,
	3, 11, 9, 8,
	1, 8, 7, 6,
};

constexpr const uint8_t Map_49_Altar[] = 
{
	15, /*Width*/
	15, /*Height*/
	3, /*Player Start X*/
	12, /*Player Start Y*/
	200, /*Timer*/
	1, /*Out of Bounds Tile ID*/
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	38, 38, 38, 38, 38, 24, 68, 24, 68, 24, 38, 38, 38, 38, 38,
	38, 38, 38, 38, 25, 0, 0, 0, 0, 0, 26, 38, 38, 38, 38,
	38, 38, 38, 66, 0, 0, 90, 91, 92, 0, 0, 65, 38, 38, 38,
	38, 38, 38, 66, 0, 0, 93, 94, 95, 0, 0, 65, 38, 38, 38,
	38, 38, 38, 38, 27, 0, 0, 0, 0, 0, 28, 38, 38, 38, 38,
	38, 38, 38, 38, 38, 22, 27, 0, 28, 22, 38, 38, 38, 38, 38,
	38, 38, 38, 38, 38, 38, 21, 0, 23, 38, 38, 38, 38, 38, 38,
	38, 38, 24, 24, 38, 38, 66, 0, 65, 38, 0, 24, 24, 0, 38,
	38, 25, 0, 0, 26, 68, 35, 60, 34, 68, 25, 0, 0, 26, 0,
	21, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23,
	38, 27, 0, 0, 28, 22, 67, 22, 67, 22, 27, 0, 10, 28, 38,
	38, 38, 22, 22, 38, 38, 38, 38, 38, 38, 38, 22, 22, 38, 38,
	9, 
	6, 12, 12, 40,
	6, 7, 7, 40,
	8, 5, 11, 20,
	8, 6, 12, 20,
	8, 7, 11, 20,
	8, 8, 12, 20,
	41, 13, 11, 120,
	6, 12, 10, 40,
	6, 12, 11, 40,
	1,
	12, 13, 7, 10,
};

constexpr const uint8_t numberOfMaps = 25;

constexpr const uint8_t* maps[numberOfMaps] = { Map_01,Map_03,Map_05_Shop,Map_07,Map_09,Map_11_Shop,Map_13,Map_15,Map_17_Shop,Map_19,Map_21_BossNecro,Map_23_Shop,Map_25,Map_27,Map_29_Shop,Map_31,Map_33_BossCyclops,Map_35_Shop,Map_37,Map_39,Map_41_Shop,Map_43,Map_45,Map_47,Map_49_Altar, };
