#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> // gotoxy�� ����ϱ� ���� �ʿ�

/*
*  �迭�� Ȱ��
*  2���� �迭
*  ���ӿ��� ����
*/

// �÷��̾� ����
// 

// �÷��̾�  :  !
const char PLAYER = '!'; // ������ ũ�Ⱑ 1�� ��ȣ�� ��ü ���� 
// ����    :  @
const char MONSTER = '@';
// ��		:   $
const char MONEY = '$';
// ��		:   #
const char WALL = '#';

#define MAPSIZE 20 // MAPSIZE�� ���� 10���� �ٲ㼭 ó���ض�

// static�� main������ ����ϰԲ� �ϴ� ��, const�� �������� ���� MAPSIZE++; ����ҷ��� �ϸ� ���� �߻�

// STAGE���� �������� ��� ó���ؾ� �ұ�? -> �غ�Ǿ� �ִ� ��ǥ���� �ִ�. ������ �� ������ ����϶�.

// �÷��̾��� �̵��� �� �� �ְ� �ϴ� �ڵ� ��ġ �� ����
int playerX = 5;
int playerY = 5;

void drawMap() {
	int x, y;
	system("cls"); // Windows�� ���. Linux/macOS�� ��� system("clear"); ���

	for (y = 0; y < MAPSIZE * 2; y++) {
		for (x = 0; x < MAPSIZE; x++) {
			if (x == playerX && y == playerY) {
				printf("P"); // �÷��̾�
			}
			else if (x == 0 || x == MAPSIZE - 1 || y == 0 || y == MAPSIZE * 2 - 1) {
				printf("#"); // ��
			}
			else {
				printf("."); // �� ����
			}
		}
		printf("\n");
	}
}

void movePlayer() {
	char input;
	if (_kbhit()) { // Ű �Է��� �ִ��� Ȯ�� (Windows)
		input = _getch(); // Ű �Է� �ޱ� (Windows)

		switch (input) {
		case 'w': // ���� �̵�
			if (playerY > 1) playerY--;
			break;
		case 's': // �Ʒ��� �̵�
			if (playerY < MAPSIZE * 2 - 2) playerY++;
			break;
		case 'a': // �������� �̵�
			if (playerX > 1) playerX--;
			break;
		case 'd': // ���������� �̵�
			if (playerX < MAPSIZE - 2) playerX++;
			break;
		}
	}
}
int main()
{
	// Text�� ����� �ؾ��Ѵ� -> ���ڷ� �̷�����ִ� �迭

	int monsterX = 7;
	int monsterY = 7;
	// 10 char������ �� �ִµ� ù��° ������ ! �����ϰڴ�. ''���� �����̽��ٷ� ����� ���鹮�� ǥ��
	char STAGE[MAPSIZE][MAPSIZE * 2] =
	{
		//{'#','#','#','#','#','#','#','#','#','\0'}, // MAPSIZE ��ü�� '#' ����ä���.
		//{'#',' ',' ',' ',' ',' ',' ',' ','#','\0'}, // ù������ ������-1 '#', ������ '\0'
		//{'#',' ',' ',' ',' ',' ',' ',' ','#','\0'},
		//{'#',' ',' ',' ',' ',' ',' ',' ','#','\0'},
		//{'#',' ',' ',' ','!',' ',' ',' ','#','\0'},
		//{'#',' ',' ',' ',' ',' ',' ',' ','#','\0'},
		//{'#',' ',' ',' ',' ',' ',' ',' ','#','\0'},
		//{'#',' ',' ',' ',' ',' ',' ',' ','#','\0'},
		//{'#',' ',' ',' ',' ',' ',' ',' ','#','\0'},
		//{'#','#','#','#','#','#','#','#','#','\0'}
		""
	};

	// ���� �ݺ����� ����Ͽ� ���� �����Ѵ�.
	for (int y = 0; y < MAPSIZE; y++) // y�� �迭
	{
		for (int x = 0; x < MAPSIZE * 2; x++) // x�� �迭
		{
			// ����1
			if (y == 0 || y == MAPSIZE - 1) // or �������� ǥ���ϸ� ���ڴ�. ||
			{
				if (x == MAPSIZE * 2 - 1)
				{
					STAGE[y][x] = '\0';
				}
				else
				{
					STAGE[y][x] = WALL;
				}
			}
			else
			{
				if (x == MAPSIZE * 2 - 1)
				{
					STAGE[y][x] = '\0';
				}
				else if (x == 0 || x == MAPSIZE * 2 - 2)
				{
					STAGE[y][x] = WALL;
				}
				else
				{
					STAGE[y][x] = ' ';
				}
			}
		}
	}

	// ���� ����. 5Frame �Ŀ� ���Ͱ� x�������� 1��������. x+1
	
	//Initialize();
	//Setup();

	//while (1)
	//{
	//	// ������ ����Ǵ� ������ ������ �ۼ��ؾ� �Ѵ�.

	//	// �ʱ�ȭ : �����Ͱ� ������ �⺻ ������ �����ϰ�, �ʱ� ������ �����Ѵ�.

	//	// �����Ͱ� ���� (���� ����) Update

	//	//Update();
	//	//Render(); // ȭ�鿡 �׷��ּ���.
	//	//Buffer(); // �����̰� ���� �ܻ��� �����ϴ�., �������� ������ ����� �մϴ�.
	//}

	// (3,5) �÷��̾ �����ȴ�.
	STAGE[2][4] = PLAYER;
	// (5,7) ���� �����ȴ�.
	STAGE[4][6] = MONEY;
	// (8,8) ���Ͱ� �����ȴ�.
	monsterX -= 6;
	STAGE[monsterY][monsterX] = MONSTER;
	// ���õ� ���� ȭ�鿡 ���̰� �϶�
	for (int h = 0; h < MAPSIZE; h++)
	{
		printf("%s\n", STAGE[h]);
	}


}