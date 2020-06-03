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
	98, 22, 36, 0, 37, 22, 98, 0, 38, 0, 38,
	98, 24, 35, 0, 34, 24, 98, 24, 24, 24, 98,
	21, 0, 0, 0, 0, 0, 46, 0, 0, 87, 23,
	21, 0, 0, 4, 0, 0, 0, 0, 0, 0, 23,
	21, 0, 0, 0, 0, 0, 45, 17, 0, 0, 23,
	98, 22, 67, 22, 67, 22, 98, 22, 22, 22, 98,
	5, 
	8, 1, 9, 20,
	8, 5, 9, 20,
	3, 7, 3, 0,
	0, 2, 1, 0,
	32, 8, 2, 0,
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
	98, 24, 68, 24, 98, 0, 38, 0, 38, 38, 0,
	21, 0, 0, 0, 23, 0, 38, 38, 0, 38, 0,
	21, 0, 0, 0, 23, 38, 0, 0, 38, 0, 0,
	98, 48, 42, 47, 24, 68, 24, 24, 0, 38, 38,
	21, 4, 0, 0, 9, 0, 0, 84, 34, 24, 98,
	21, 0, 0, 0, 0, 0, 0, 0, 39, 0, 23,
	21, 11, 0, 0, 97, 0, 0, 37, 36, 0, 65,
	98, 22, 36, 59, 45, 59, 37, 98, 21, 0, 23,
	0, 38, 21, 0, 43, 0, 23, 38, 21, 0, 65,
	98, 24, 35, 0, 43, 3, 23, 0, 21, 11, 23,
	21, 0, 0, 0, 23, 22, 98, 38, 98, 22, 98,
	21, 8, 0, 0, 23, 38, 0, 38, 0, 38, 0,
	98, 22, 22, 22, 98, 0, 38, 0, 38, 0, 38,
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
	38, 38, 0, 38, 98, 24, 24, 24, 24, 24, 98,
	38, 0, 38, 0, 21, 83, 77, 78, 79, 84, 23,
	0, 38, 0, 0, 21, 4, 80, 81, 82, 4, 23,
	38, 0, 0, 38, 21, 0, 0, 0, 0, 0, 23,
	0, 38, 0, 38, 98, 22, 36, 0, 37, 22, 98,
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
	38, 0, 0, 21, 0, 43, 0, 43, 0, 23, 0,
	0, 0, 38, 21, 0, 43, 0, 43, 0, 23, 38,
	38, 38, 0, 21, 11, 43, 8, 43, 11, 23, 0,
	38, 0, 38, 98, 22, 98, 22, 98, 22, 98, 38,
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
	21, 3, 0, 0, 0, 0, 0, 88, 23,
	98, 22, 67, 22, 67, 22, 67, 22, 98,
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
	10, 4, 4, 0,
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
	38, 21, 0, 0, 8, 43, 0, 84, 23, 0, 38, 0,
	0, 66, 0, 47, 44, 35, 0, 0, 65, 38, 0, 38,
	38, 21, 0, 0, 0, 0, 0, 0, 23, 98, 24, 98,
	0, 98, 22, 22, 22, 36, 0, 47, 24, 35, 17, 23,
	38, 0, 38, 0, 38, 21, 0, 0, 0, 0, 0, 23,
	0, 38, 38, 0, 0, 21, 0, 0, 0, 0, 0, 23,
	0, 38, 0, 38, 38, 98, 22, 67, 22, 67, 22, 98,
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
	15, /*Width*/
	15, /*Height*/
	7, /*Player Start X*/
	12, /*Player Start Y*/
	1, /*Timer*/
	1, /*Out of Bounds Tile ID*/
	0, 0, 0, 0, 0, 38, 0, 0, 38, 0, 0, 0, 0, 0, 0,
	38, 0, 98, 68, 68, 68, 68, 68, 68, 68, 68, 68, 98, 0, 0,
	0, 0, 21, 83, 0, 0, 77, 78, 79, 0, 0, 84, 23, 0, 38,
	0, 0, 21, 4, 5, 5, 80, 81, 82, 5, 5, 4, 23, 0, 0,
	66, 26, 35, 4, 0, 0, 0, 0, 0, 0, 0, 4, 34, 25, 65,
	66, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 65,
	66, 28, 67, 59, 67, 36, 0, 0, 0, 37, 67, 59, 67, 27, 65,
	0, 0, 4, 4, 4, 66, 0, 0, 0, 65, 4, 4, 4, 0, 0,
	0, 0, 4, 4, 4, 66, 60, 60, 60, 65, 4, 4, 4, 0, 0,
	38, 0, 4, 4, 4, 66, 0, 0, 0, 65, 4, 4, 4, 0, 0,
	0, 0, 0, 0, 0, 25, 0, 14, 0, 26, 0, 0, 0, 0, 0,
	0, 38, 0, 0, 66, 4, 0, 0, 0, 4, 65, 0, 0, 38, 0,
	0, 0, 0, 0, 21, 0, 0, 9, 0, 0, 23, 0, 38, 0, 0,
	0, 0, 38, 0, 66, 86, 0, 0, 0, 85, 65, 0, 0, 0, 0,
	0, 0, 0, 0, 98, 67, 67, 67, 67, 67, 98, 0, 0, 0, 0,
	0, 
	3,
	7, 10, 6, 8,
	7, 10, 7, 8,
	7, 10, 8, 8,
};

constexpr const uint8_t Map_13_Necro[] = 
{
	25, /*Width*/
	26, /*Height*/
	12, /*Player Start X*/
	2, /*Player Start Y*/
	250, /*Timer*/
	1, /*Out of Bounds Tile ID*/
	0, 0, 0, 0, 0, 0, 0, 0, 0, 98, 68, 68, 68, 68, 68, 98, 0, 0, 0, 0, 0, 0, 38, 0, 0,
	0, 0, 38, 0, 0, 38, 0, 85, 86, 66, 83, 0, 0, 0, 84, 65, 85, 86, 0, 38, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 84, 83, 66, 0, 0, 9, 0, 0, 65, 84, 83, 0, 0, 0, 0, 0, 38, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 38, 0, 0, 0, 0, 66, 99, 0, 0, 0, 99, 65, 0, 0, 0, 0, 0, 38, 0, 0, 0,
	0, 0, 38, 0, 0, 0, 85, 86, 0, 98, 36, 0, 0, 0, 37, 98, 0, 85, 86, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 38, 0, 84, 83, 0, 0, 66, 10, 0, 97, 65, 0, 0, 84, 83, 0, 38, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 98, 36, 59, 37, 98, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 98, 68, 68, 68, 68, 68, 68, 68, 68, 68, 35, 0, 34, 68, 68, 68, 68, 68, 68, 68, 68, 68, 98, 0,
	0, 66, 84, 83, 84, 83, 84, 83, 84, 83, 84, 83, 0, 84, 83, 84, 83, 84, 83, 84, 83, 84, 83, 65, 0,
	0, 66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65, 0,
	0, 66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65, 0,
	0, 66, 0, 0, 0, 37, 36, 100, 0, 0, 99, 0, 0, 0, 0, 99, 0, 85, 37, 36, 100, 0, 0, 65, 0,
	0, 66, 86, 0, 0, 34, 35, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 84, 34, 35, 100, 0, 85, 65, 0,
	0, 66, 83, 0, 0, 84, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 84, 65, 0,
	0, 66, 0, 0, 0, 0, 99, 0, 37, 36, 100, 0, 0, 0, 37, 36, 100, 0, 99, 0, 0, 0, 0, 65, 0,
	0, 66, 86, 0, 0, 0, 0, 0, 34, 35, 100, 90, 92, 0, 34, 35, 100, 0, 0, 0, 0, 0, 85, 65, 0,
	0, 66, 83, 0, 0, 0, 0, 0, 0, 0, 0, 93, 95, 0, 0, 0, 0, 0, 0, 0, 0, 0, 84, 65, 0,
	0, 66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65, 0,
	0, 66, 86, 0, 0, 0, 90, 92, 0, 0, 0, 0, 0, 0, 0, 0, 90, 92, 0, 0, 0, 0, 85, 65, 0,
	0, 66, 83, 0, 0, 0, 93, 95, 0, 0, 0, 0, 0, 0, 0, 0, 93, 95, 0, 0, 0, 0, 84, 65, 0,
	0, 66, 0, 0, 0, 85, 86, 0, 0, 0, 99, 0, 0, 0, 0, 99, 0, 0, 85, 86, 0, 0, 0, 65, 0,
	0, 66, 0, 0, 0, 84, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 84, 83, 0, 0, 0, 65, 0,
	0, 66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65, 0,
	0, 66, 86, 0, 0, 0, 0, 0, 0, 0, 0, 58, 3, 57, 0, 10, 0, 0, 0, 0, 0, 0, 85, 65, 0,
	0, 98, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 98, 0,
	32, 
	16, 5, 23, 40,
	16, 11, 23, 40,
	16, 11, 18, 40,
	23, 12, 18, 60,
	16, 13, 18, 40,
	16, 15, 23, 40,
	16, 1, 23, 40,
	17, 2, 12, 0,
	17, 2, 15, 0,
	17, 2, 18, 0,
	18, 22, 12, 0,
	18, 22, 15, 0,
	18, 22, 18, 0,
	16, 3, 22, 40,
	16, 13, 22, 40,
	16, 20, 11, 40,
	16, 4, 11, 40,
	16, 12, 14, 40,
	17, 2, 21, 0,
	18, 22, 21, 0,
	20, 14, 24, 0,
	20, 10, 24, 0,
	20, 19, 11, 0,
	20, 18, 11, 0,
	20, 6, 11, 0,
	20, 5, 11, 0,
	19, 14, 17, 0,
	19, 15, 17, 0,
	19, 8, 17, 0,
	19, 9, 17, 0,
	7, 20, 18, 30,
	7, 4, 18, 30,
	4,
	15, 24, 13, 24,
	15, 24, 12, 23,
	15, 24, 11, 24,
	11, 6, 12, 7,
};

constexpr const uint8_t Map_15[] = 
{
	11, /*Width*/
	12, /*Height*/
	3, /*Player Start X*/
	1, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	38, 0, 38, 24, 38, 38, 0, 38, 0, 38, 38,
	98, 24, 35, 9, 34, 24, 98, 24, 24, 98, 38,
	21, 0, 0, 0, 0, 11, 43, 83, 88, 23, 0,
	98, 44, 48, 59, 47, 44, 35, 4, 0, 23, 38,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 65, 0,
	98, 44, 48, 16, 47, 44, 36, 0, 4, 23, 38,
	21, 83, 0, 0, 0, 84, 43, 4, 4, 23, 38,
	21, 0, 0, 17, 0, 0, 43, 4, 11, 65, 0,
	98, 22, 67, 22, 67, 22, 21, 16, 16, 23, 38,
	38, 0, 0, 38, 38, 0, 21, 0, 0, 23, 0,
	0, 38, 38, 0, 38, 38, 21, 0, 8, 23, 38,
	38, 0, 38, 38, 0, 38, 98, 22, 22, 98, 38,
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

constexpr const uint8_t Map_17[] = 
{
	12, /*Width*/
	12, /*Height*/
	1, /*Player Start X*/
	1, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	98, 24, 24, 24, 98, 24, 68, 24, 68, 24, 98, 0,
	21, 9, 0, 97, 43, 83, 0, 0, 0, 84, 23, 38,
	21, 0, 0, 37, 35, 0, 0, 45, 0, 0, 23, 0,
	98, 48, 4, 46, 83, 0, 28, 25, 0, 37, 98, 38,
	21, 0, 0, 0, 0, 0, 43, 0, 0, 34, 24, 98,
	21, 0, 0, 37, 44, 44, 35, 0, 0, 0, 84, 23,
	98, 22, 22, 25, 0, 0, 0, 0, 45, 0, 0, 65,
	38, 0, 25, 0, 0, 0, 0, 28, 24, 48, 0, 65,
	0, 21, 0, 0, 0, 0, 28, 25, 0, 0, 0, 23,
	38, 66, 0, 0, 37, 22, 25, 0, 0, 0, 37, 98,
	0, 21, 17, 0, 23, 21, 0, 0, 0, 37, 98, 38,
	38, 98, 22, 22, 98, 98, 22, 22, 22, 98, 38, 0,
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

constexpr const uint8_t Map_19_Shop[] = 
{
	12, /*Width*/
	16, /*Height*/
	1, /*Player Start X*/
	5, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	38, 0, 38, 0, 38, 98, 24, 24, 24, 24, 24, 0,
	0, 0, 38, 38, 0, 21, 83, 77, 78, 79, 84, 23,
	0, 38, 0, 38, 38, 21, 99, 80, 81, 82, 99, 23,
	38, 38, 38, 0, 38, 21, 0, 0, 0, 0, 0, 65,
	98, 24, 0, 98, 24, 24, 44, 44, 44, 48, 60, 23,
	21, 9, 23, 35, 0, 0, 39, 0, 0, 0, 0, 23,
	21, 0, 46, 0, 0, 37, 22, 22, 22, 36, 0, 65,
	21, 0, 0, 0, 47, 98, 0, 24, 24, 35, 0, 23,
	98, 36, 0, 45, 0, 23, 21, 83, 0, 0, 0, 23,
	98, 35, 0, 46, 0, 65, 66, 0, 0, 0, 0, 65,
	21, 0, 0, 0, 0, 23, 21, 0, 0, 0, 0, 23,
	66, 4, 45, 0, 47, 24, 24, 44, 44, 22, 22, 98,
	21, 0, 43, 0, 0, 0, 0, 0, 10, 23, 38, 38,
	66, 0, 23, 22, 36, 41, 37, 22, 22, 38, 0, 0,
	21, 0, 23, 38, 21, 3, 23, 0, 38, 38, 0, 0,
	98, 22, 98, 0, 98, 22, 98, 38, 0, 38, 38, 0,
	12, 
	3, 1, 14, 1,
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

constexpr const uint8_t Map_21[] = 
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
	21, 8, 0, 0, 58, 0, 0, 0, 43, 0, 65,
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

constexpr const uint8_t Map_23[] = 
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
	17, 5, 3, 0,
	18, 8, 3, 0,
	19, 7, 1, 0,
	13, 10, 4, 0,
	21, 1, 7, 20,
	21, 3, 9, 20,
	24, 1, 9, 60,
	8, 9, 7, 20,
	3,
	10, 1, 4, 8,
	9, 9, 4, 8,
	1, 5, 4, 5,
};

constexpr const uint8_t Map_25_Shop[] = 
{
	15, /*Width*/
	11, /*Height*/
	2, /*Player Start X*/
	8, /*Player Start Y*/
	200, /*Timer*/
	1, /*Out of Bounds Tile ID*/
	0, 0, 38, 98, 24, 68, 68, 68, 24, 98, 38, 0, 38, 38, 0,
	0, 0, 0, 21, 88, 88, 88, 88, 88, 23, 0, 38, 24, 38, 38,
	0, 38, 38, 21, 60, 77, 78, 79, 60, 34, 68, 25, 0, 26, 0,
	38, 0, 0, 21, 0, 80, 81, 82, 0, 0, 0, 0, 3, 0, 23,
	38, 38, 0, 21, 0, 0, 0, 0, 0, 37, 22, 27, 0, 28, 38,
	0, 0, 38, 98, 22, 36, 0, 37, 22, 98, 38, 38, 67, 38, 0,
	38, 38, 24, 38, 38, 66, 0, 65, 38, 38, 38, 0, 38, 0, 38,
	0, 25, 0, 26, 24, 35, 0, 23, 0, 0, 38, 38, 38, 0, 38,
	66, 0, 9, 0, 0, 0, 0, 65, 38, 38, 38, 38, 0, 0, 0,
	38, 27, 97, 28, 67, 67, 67, 98, 38, 38, 0, 0, 38, 38, 0,
	0, 38, 22, 38, 0, 38, 0, 38, 0, 0, 38, 0, 0, 0, 0,
	3, 
	20, 4, 8, 0,
	20, 5, 8, 0,
	21, 6, 5, 20,
	0,
};

constexpr const uint8_t Map_27_Cyclops[] = 
{
	20, /*Width*/
	19, /*Height*/
	12, /*Player Start X*/
	13, /*Player Start Y*/
	250, /*Timer*/
	1, /*Out of Bounds Tile ID*/
	0, 0, 0, 99, 0, 0, 98, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 98, 0, 0,
	99, 0, 0, 38, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65, 0, 0,
	0, 0, 0, 0, 0, 99, 66, 0, 37, 67, 67, 67, 67, 67, 67, 36, 0, 65, 99, 0,
	38, 0, 99, 98, 68, 68, 35, 60, 34, 68, 68, 98, 87, 98, 68, 35, 0, 34, 98, 0,
	0, 0, 0, 66, 83, 0, 0, 0, 0, 0, 84, 65, 87, 66, 14, 0, 0, 99, 65, 0,
	98, 24, 24, 35, 0, 33, 100, 0, 0, 33, 100, 34, 24, 35, 0, 0, 0, 0, 65, 0,
	66, 0, 0, 58, 0, 0, 0, 0, 0, 0, 0, 57, 0, 0, 0, 0, 0, 0, 65, 0,
	66, 0, 37, 36, 0, 33, 100, 0, 0, 33, 100, 37, 22, 36, 0, 0, 33, 59, 65, 0,
	66, 0, 65, 66, 86, 0, 0, 14, 0, 0, 85, 65, 87, 66, 0, 0, 57, 3, 65, 0,
	66, 0, 65, 0, 67, 67, 36, 59, 37, 67, 67, 98, 87, 98, 67, 67, 67, 67, 98, 0,
	66, 0, 65, 99, 0, 98, 35, 0, 34, 24, 68, 68, 24, 24, 98, 0, 99, 0, 0, 0,
	66, 0, 65, 0, 99, 66, 10, 0, 0, 0, 0, 0, 0, 97, 23, 0, 0, 38, 0, 0,
	66, 0, 34, 68, 68, 35, 0, 0, 0, 0, 0, 0, 0, 4, 65, 0, 0, 0, 0, 38,
	66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 4, 65, 0, 99, 0, 0, 0,
	66, 0, 0, 0, 0, 99, 37, 67, 27, 0, 0, 4, 4, 4, 23, 0, 0, 0, 0, 0,
	98, 67, 67, 67, 67, 67, 98, 0, 98, 22, 67, 67, 22, 22, 98, 0, 0, 38, 0, 0,
	0, 38, 0, 0, 38, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 38, 0, 0, 0, 0, 0, 38, 0, 0, 99, 0, 0, 38, 0, 0, 0, 0,
	0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	4, 
	42, 7, 6, 120,
	2, 1, 6, 0,
	8, 1, 9, 20,
	8, 11, 1, 20,
	9,
	6, 11, 7, 9,
	6, 11, 11, 6,
	6, 11, 7, 3,
	6, 11, 3, 6,
	7, 8, 7, 9,
	7, 8, 11, 6,
	7, 8, 7, 3,
	14, 4, 16, 8,
	14, 4, 17, 7,
};

constexpr const uint8_t Map_29[] = 
{
	18, /*Width*/
	11, /*Height*/
	1, /*Player Start X*/
	2, /*Player Start Y*/
	200, /*Timer*/
	1, /*Out of Bounds Tile ID*/
	38, 0, 38, 98, 24, 68, 24, 68, 24, 68, 24, 68, 24, 98, 38, 0, 38, 0,
	98, 24, 24, 21, 8, 0, 0, 0, 0, 0, 0, 0, 84, 23, 24, 24, 24, 98,
	21, 9, 0, 43, 0, 0, 4, 37, 36, 0, 47, 48, 0, 43, 0, 0, 0, 23,
	66, 0, 0, 43, 0, 4, 4, 23, 21, 0, 0, 0, 0, 43, 96, 45, 0, 65,
	21, 0, 0, 46, 0, 37, 22, 98, 0, 22, 48, 0, 0, 34, 44, 35, 0, 23,
	21, 0, 0, 0, 0, 23, 98, 24, 24, 35, 0, 0, 0, 39, 0, 0, 0, 23,
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

constexpr const uint8_t Map_31[] = 
{
	11, /*Width*/
	12, /*Height*/
	4, /*Player Start X*/
	2, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	98, 24, 24, 24, 24, 98, 38, 0, 0, 38, 38,
	21, 4, 4, 4, 0, 34, 68, 24, 98, 24, 98,
	66, 4, 33, 4, 0, 0, 0, 84, 46, 3, 23,
	21, 4, 4, 0, 97, 45, 0, 0, 57, 0, 23,
	98, 22, 44, 44, 44, 21, 0, 47, 44, 44, 98,
	38, 21, 0, 0, 0, 43, 0, 4, 0, 0, 23,
	0, 66, 0, 45, 42, 34, 44, 44, 48, 0, 65,
	38, 21, 0, 43, 0, 4, 0, 0, 0, 0, 23,
	0, 66, 0, 34, 44, 36, 0, 47, 44, 44, 98,
	38, 21, 0, 0, 11, 43, 0, 0, 4, 8, 23,
	0, 98, 22, 22, 22, 98, 22, 22, 22, 22, 98,
	38, 0, 38, 38, 0, 38, 38, 0, 0, 38, 0,
	11, 
	6, 8, 5, 20,
	6, 8, 5, 20,
	7, 7, 9, 20,
	7, 7, 9, 20,
	7, 7, 9, 20,
	18, 2, 6, 0,
	17, 2, 7, 0,
	19, 7, 7, 0,
	20, 8, 7, 0,
	2, 9, 3, 0,
	21, 2, 9, 20,
	1,
	4, 9, 8, 3,
};

constexpr const uint8_t Map_33_Shop[] = 
{
	22, /*Width*/
	15, /*Height*/
	5, /*Player Start X*/
	9, /*Player Start Y*/
	255, /*Timer*/
	37, /*Out of Bounds Tile ID*/
	0, 38, 0, 0, 98, 0, 0, 38, 0, 38, 38, 98, 24, 24, 24, 24, 24, 24, 24, 24, 24, 98,
	38, 0, 0, 38, 0, 38, 38, 38, 0, 0, 38, 21, 83, 0, 0, 0, 0, 77, 78, 79, 84, 23,
	38, 0, 38, 0, 0, 0, 0, 38, 38, 38, 0, 21, 0, 0, 0, 45, 0, 80, 81, 82, 5, 23,
	38, 0, 38, 38, 0, 38, 0, 38, 0, 38, 38, 21, 3, 0, 0, 43, 0, 0, 0, 0, 0, 23,
	98, 24, 68, 24, 68, 24, 68, 24, 68, 24, 98, 98, 44, 44, 44, 21, 0, 0, 4, 4, 4, 23,
	21, 0, 0, 0, 0, 14, 0, 0, 0, 0, 23, 21, 0, 0, 0, 43, 0, 0, 47, 44, 44, 98,
	66, 0, 33, 0, 33, 0, 33, 0, 33, 0, 65, 21, 73, 45, 0, 43, 0, 0, 57, 0, 0, 23,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23, 98, 44, 35, 60, 34, 44, 44, 44, 48, 60, 23,
	66, 0, 33, 0, 33, 0, 33, 0, 33, 0, 65, 21, 10, 0, 0, 58, 0, 0, 0, 0, 0, 23,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 24, 44, 36, 0, 45, 10, 45, 0, 45, 10, 23,
	66, 0, 33, 0, 33, 0, 33, 0, 33, 0, 57, 0, 0, 43, 60, 34, 22, 35, 60, 34, 44, 98,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45, 10, 0, 43, 0, 0, 43, 0, 0, 0, 10, 23,
	66, 0, 33, 0, 33, 17, 33, 0, 33, 0, 43, 10, 0, 34, 48, 60, 46, 60, 47, 44, 44, 98,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43, 19, 0, 0, 0, 0, 0, 0, 0, 0, 73, 23,
	98, 22, 67, 22, 67, 22, 67, 22, 67, 22, 98, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 98,
	17, 
	1, 1, 13, 100,
	3, 1, 5, 100,
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
	9, 9, 5, 0,
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

constexpr const uint8_t Map_35[] = 
{
	17, /*Width*/
	21, /*Height*/
	3, /*Player Start X*/
	1, /*Player Start Y*/
	200, /*Timer*/
	1, /*Out of Bounds Tile ID*/
	98, 24, 68, 24, 68, 24, 98, 38, 98, 24, 68, 24, 68, 24, 98, 38, 0,
	21, 87, 0, 9, 0, 8, 23, 38, 21, 0, 0, 0, 0, 84, 23, 0, 38,
	66, 0, 0, 0, 0, 0, 23, 38, 21, 0, 0, 0, 0, 0, 34, 24, 98,
	21, 0, 0, 0, 0, 97, 23, 24, 24, 44, 48, 0, 0, 0, 39, 0, 23,
	66, 0, 0, 0, 0, 0, 43, 0, 0, 0, 0, 0, 0, 0, 45, 0, 65,
	21, 0, 0, 0, 0, 0, 43, 0, 0, 0, 45, 0, 0, 0, 43, 0, 23,
	98, 22, 36, 41, 37, 44, 35, 0, 0, 0, 23, 44, 44, 44, 35, 0, 23,
	0, 38, 66, 0, 43, 0, 0, 0, 0, 0, 43, 10, 0, 0, 39, 0, 23,
	38, 0, 21, 0, 43, 0, 0, 0, 0, 96, 43, 0, 0, 37, 36, 0, 65,
	0, 38, 66, 0, 34, 44, 48, 60, 47, 44, 35, 0, 0, 23, 21, 0, 23,
	38, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 85, 23, 21, 73, 23,
	38, 38, 98, 22, 67, 22, 67, 22, 22, 67, 22, 67, 22, 98, 38, 22, 38,
	98, 24, 24, 24, 24, 24, 98, 38, 0, 38, 98, 24, 24, 24, 24, 24, 98,
	21, 73, 0, 0, 0, 19, 23, 0, 38, 0, 21, 0, 0, 0, 0, 84, 23,
	66, 0, 33, 0, 33, 0, 23, 24, 24, 24, 21, 0, 33, 0, 33, 0, 65,
	66, 0, 0, 0, 0, 0, 43, 0, 0, 0, 43, 0, 0, 0, 0, 0, 23,
	66, 0, 33, 0, 33, 0, 46, 0, 0, 0, 46, 0, 33, 0, 33, 0, 65,
	21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 23,
	98, 22, 22, 22, 22, 36, 0, 0, 0, 0, 0, 37, 22, 22, 22, 22, 98,
	38, 0, 0, 38, 0, 21, 86, 0, 0, 0, 0, 23, 38, 38, 0, 0, 38,
	0, 0, 38, 0, 38, 98, 22, 67, 22, 67, 22, 98, 38, 0, 38, 38, 0,
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

constexpr const uint8_t Map_37[] = 
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

constexpr const uint8_t Map_39_Shop[] = 
{
	17, /*Width*/
	14, /*Height*/
	8, /*Player Start X*/
	2, /*Player Start Y*/
	200, /*Timer*/
	1, /*Out of Bounds Tile ID*/
	0, 0, 0, 0, 0, 0, 38, 0, 38, 38, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 38, 0, 0, 38, 0, 38, 68, 38, 38, 0, 0, 0, 0, 38, 0,
	0, 0, 0, 0, 0, 38, 38, 25, 0, 26, 38, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 38, 0, 0, 66, 0, 73, 97, 65, 0, 38, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 38, 0, 27, 0, 28, 38, 0, 0, 0, 0, 0, 0,
	38, 0, 0, 38, 38, 24, 38, 38, 67, 38, 0, 24, 0, 38, 0, 38, 0,
	0, 38, 0, 38, 25, 0, 26, 24, 68, 24, 25, 0, 26, 0, 0, 0, 0,
	0, 0, 0, 21, 0, 73, 0, 0, 0, 0, 0, 73, 0, 23, 0, 38, 0,
	0, 0, 0, 38, 27, 0, 28, 22, 22, 22, 27, 0, 28, 38, 0, 0, 0,
	38, 38, 24, 38, 38, 22, 38, 68, 68, 68, 38, 22, 38, 38, 24, 38, 38,
	38, 25, 0, 26, 68, 24, 25, 77, 78, 79, 26, 24, 68, 25, 0, 26, 38,
	21, 0, 73, 0, 0, 0, 0, 80, 81, 82, 0, 0, 0, 0, 3, 0, 65,
	38, 27, 0, 28, 22, 67, 27, 0, 0, 0, 28, 67, 22, 27, 0, 28, 38,
	0, 38, 22, 38, 0, 0, 38, 67, 22, 67, 38, 38, 0, 38, 22, 38, 0,
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

constexpr const uint8_t Map_41_Beholder[] = 
{
	15, /*Width*/
	15, /*Height*/
	1, /*Player Start X*/
	1, /*Player Start Y*/
	250, /*Timer*/
	1, /*Out of Bounds Tile ID*/
	98, 68, 68, 68, 0, 0, 0, 0, 84, 83, 98, 68, 68, 68, 98,
	66, 9, 0, 0, 26, 68, 68, 68, 98, 0, 21, 0, 0, 0, 65,
	66, 0, 14, 0, 0, 57, 0, 0, 65, 0, 21, 0, 0, 0, 65,
	66, 97, 0, 0, 28, 67, 36, 0, 26, 0, 21, 0, 0, 0, 65,
	0, 27, 0, 28, 0, 0, 25, 0, 0, 26, 0, 36, 60, 37, 98,
	0, 66, 0, 65, 0, 25, 0, 0, 0, 0, 26, 35, 0, 23, 0,
	99, 21, 0, 23, 66, 0, 0, 0, 0, 0, 0, 0, 0, 65, 0,
	0, 66, 0, 65, 66, 0, 85, 33, 100, 0, 0, 0, 0, 23, 0,
	99, 21, 0, 23, 66, 0, 33, 100, 0, 0, 0, 0, 0, 65, 0,
	0, 66, 0, 65, 66, 0, 0, 0, 0, 0, 0, 0, 0, 26, 0,
	98, 35, 59, 34, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 26,
	21, 0, 0, 0, 34, 25, 0, 0, 0, 0, 0, 0, 0, 0, 28,
	21, 0, 0, 0, 58, 0, 0, 0, 0, 0, 0, 0, 4, 4, 26,
	21, 0, 0, 0, 37, 36, 86, 0, 0, 0, 0, 0, 4, 3, 28,
	98, 22, 22, 22, 98, 98, 22, 22, 22, 22, 27, 28, 27, 28, 0,
	11, 
	6, 12, 2, 40,
	6, 12, 1, 40,
	6, 12, 3, 40,
	6, 2, 12, 40,
	41, 10, 10, 120,
	6, 2, 11, 40,
	6, 2, 13, 40,
	21, 4, 4, 20,
	6, 10, 4, 40,
	4, 6, 9, 0,
	10, 13, 1, 0,
	4,
	2, 2, 2, 10,
	2, 2, 5, 2,
	2, 2, 4, 12,
	2, 2, 12, 4,
};

constexpr const uint8_t Map_43_Altar[] = 
{
	15, /*Width*/
	15, /*Height*/
	7, /*Player Start X*/
	13, /*Player Start Y*/
	250, /*Timer*/
	1, /*Out of Bounds Tile ID*/
	0, 0, 24, 68, 24, 68, 24, 68, 24, 68, 24, 68, 24, 0, 0,
	0, 25, 0, 0, 0, 57, 0, 0, 0, 58, 0, 0, 0, 26, 0,
	66, 0, 0, 0, 0, 57, 90, 91, 92, 58, 0, 0, 0, 0, 65,
	66, 59, 59, 59, 59, 99, 93, 94, 95, 99, 59, 59, 59, 59, 65,
	98, 36, 86, 0, 0, 0, 0, 0, 0, 0, 0, 0, 85, 37, 98,
	0, 98, 36, 0, 0, 33, 100, 0, 0, 33, 100, 0, 37, 98, 0,
	0, 0, 66, 0, 99, 0, 0, 0, 0, 0, 99, 0, 65, 0, 0,
	0, 38, 21, 0, 0, 33, 100, 0, 0, 33, 100, 0, 23, 0, 38,
	0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65, 38, 0,
	0, 0, 21, 99, 0, 33, 100, 0, 0, 33, 100, 99, 23, 0, 0,
	38, 0, 66, 86, 0, 0, 0, 0, 0, 0, 0, 85, 65, 0, 0,
	0, 0, 98, 67, 67, 36, 0, 0, 0, 37, 67, 67, 98, 0, 38,
	0, 0, 0, 90, 92, 66, 0, 0, 0, 65, 90, 92, 0, 0, 0,
	0, 38, 0, 93, 95, 0, 27, 9, 28, 0, 93, 95, 0, 0, 0,
	0, 0, 38, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0,
	10, 
	32, 10, 2, 0,
	32, 11, 2, 0,
	32, 12, 2, 0,
	32, 13, 2, 0,
	32, 4, 2, 0,
	32, 3, 2, 0,
	32, 2, 2, 0,
	32, 1, 2, 0,
	8, 11, 1, 20,
	8, 3, 1, 20,
	0,
};

constexpr const uint8_t numberOfMaps = 22;

constexpr const uint8_t* maps[numberOfMaps] = { Map_01,Map_03,Map_05_Shop,Map_07,Map_09,Map_11_Shop,Map_13_Necro,Map_15,Map_17,Map_19_Shop,Map_21,Map_23,Map_25_Shop,Map_27_Cyclops,Map_29,Map_31,Map_33_Shop,Map_35,Map_37,Map_39_Shop,Map_41_Beholder,Map_43_Altar, };
