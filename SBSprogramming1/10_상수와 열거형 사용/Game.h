#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>


const static int MAPSIZE = 10;
//int PlayerX = 3;
//int PlayerY = 5;
//int MapOriginX;
//int MapOriginY;


bool CheckPlayerIsBoundary();				// <stdbool.h>
int  CalculateBoundary(int MapOriginX);
int  CalculateBoundary(int MapOriginY);