#include "Game.h"
#include <stdbool.h>

// ex) 크기 : 10		(0,0) (규칙 : x 오른쪽이 양의 방향, y 아래 쪽이 양의 방향) 콘솔창 왼쪽 상단
// CheckPlayerIsBoundary() -> bool, true false	<stdio.h>
// 경계선을 어떻게 구하는데? -> CalculateBoundary(시작 좌표, 맵의 크기) 


bool CheckPlayerIsBoundary()
{
	int mapX = CalculateBoundaryX(0);
	int mapY = CalculateBoundaryY(0);
	int playerX;
	int playerY;

	// 조건문으로 범위안인가 아닌가 체크해보세요

	return false;
}

int CalculateBoundary(int MapOriginX)
{
	return 0;
}
int CalculateBoundary(int MapOriginY)
{
	return 0;
}