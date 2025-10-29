#include "Game.h"
#include <stdbool.h>

// ex) 크기 : 10		(0,0) (규칙 : x 오른쪽이 양의 방향, y 아래 쪽이 양의 방향) 콘솔창 왼쪽 상단
// CheckPlayerIsBoundary() -> bool, true false	<stdio.h>
// 경계선을 어떻게 구하는데? -> CalculateBoundary(시작 좌표, 맵의 크기) 


bool CheckPlayerIsBoundary()
{
	int mapX = CalculateBoundaryX(0);
	int mapY = CalculateBoundaryY(0);
	int playerX = 3; 
	int playerY = 5;

	// 조건문으로 범위안인가 아닌가 체크해보세요

	if ((playerX >= 0  && playerX < mapX) 
		&& (playerY >=0 && playerY < mapY))// 어떤 조건일 때 참인가? MAPSIZE X, Y player X Y 비교
	{
		printf("플레이어가 경계선 안에 있습니다.\n");
		return true;
	}
	else
	{
		printf("플레이어가 경계선 안에 있습니다.\n");
		return false;
	}
}

int CalculateBoundaryX(int MapOriginX)
{
	return MapOriginX + MAPSIZE;
}
int CalculateBoundaryY(int MapOriginY)
{
	return MapOriginY + MAPSIZE;
}