#include "Game.h"
#include <stdbool.h>

// ex) ũ�� : 10		(0,0) (��Ģ : x �������� ���� ����, y �Ʒ� ���� ���� ����) �ܼ�â ���� ���
// CheckPlayerIsBoundary() -> bool, true false	<stdio.h>
// ��輱�� ��� ���ϴµ�? -> CalculateBoundary(���� ��ǥ, ���� ũ��) 


bool CheckPlayerIsBoundary()
{
	int mapX = CalculateBoundaryX(0);
	int mapY = CalculateBoundaryY(0);
	int playerX = 3; 
	int playerY = 5;

	// ���ǹ����� �������ΰ� �ƴѰ� üũ�غ�����

	if ((playerX >= 0  && playerX < mapX) 
		&& (playerY >=0 && playerY < mapY))// � ������ �� ���ΰ�? MAPSIZE X, Y player X Y ��
	{
		printf("�÷��̾ ��輱 �ȿ� �ֽ��ϴ�.\n");
		return true;
	}
	else
	{
		printf("�÷��̾ ��輱 �ȿ� �ֽ��ϴ�.\n");
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