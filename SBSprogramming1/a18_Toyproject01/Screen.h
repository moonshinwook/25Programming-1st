#pragma once

#define MAPHEIGHT 25

void ScreenInit();
void ScreenFlipping();
void ScreenClear();
void ScreenPrint(int x, int y, char* string);
void ScreenRelease();
void SetColor(unsigned short color);