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

#define MAPH (MAPSIZE)
#define MAPW (MAPSIZE*2 - 1) //#define �� ��ũ�� ��� ���� �����Դϴ�.�� ������ ����, �ڵ� ���� MAPH�� MAPW�� ���� ������ ������ ��ġȯ���մϴ�.

// �� �׸���(���ڿ��� �� �پ�)
void render(char STAGE[MAPH][MAPW + 1]) {
	system("cls"); // �ܼ� ȭ���� ��� ���� (Clear Screen)
	for (int y = 0; y < MAPH; y++) { //���� ������(y��)�� ��ȸ
		printf("%s\n", STAGE[y]); //�� ���� ���ڿ��� �� �پ� ���
	}
}
void PlayerMove(playerXPtr, playerYPtr);

int main()
{
	// �� ����: ���δ� ǥ�ù��� MAPW + ���ڿ����Ṯ��('\0') 1ĭ
	char STAGE[MAPH][MAPW + 1]; // ��ũ��

	// 1) �ܰ� ���� ���� �������� �ʱ�ȭ
	for (int y = 0; y < MAPH; y++) {
		for (int x = 0; x < MAPW; x++) {
			if (y == 0 || y == MAPH - 1 || x == 0 || x == MAPW - 1) {
				STAGE[y][x] = WALL;     // �ٱ� �׵θ�
			}
			else {
				STAGE[y][x] = ' ';      // ���� ��ĭ
			}
		}
		STAGE[y][MAPW] = '\0';          // �� �� ���ڿ� ����
	}

	// Text�� ����� �ؾ��Ѵ� -> ���ڷ� �̷�����ִ� �迭

	int monsterX = 7;
	int monsterY = 7;
	// 10 char������ �� �ִµ� ù��° ������ ! �����ϰڴ�. ''���� �����̽��ٷ� ����� ���鹮�� ǥ��
	//char STAGE[MAPSIZE][MAPSIZE * 2] =
	//{
	//	//{'#','#','#','#','#','#','#','#','#','\0'}, // MAPSIZE ��ü�� '#' ����ä���.
	//	//{'#',' ',' ',' ',' ',' ',' ',' ','#','\0'}, // ù������ ������-1 '#', ������ '\0'
	//	//{'#',' ',' ',' ',' ',' ',' ',' ','#','\0'},
	//	//{'#',' ',' ',' ',' ',' ',' ',' ','#','\0'},
	//	//{'#',' ',' ',' ','!',' ',' ',' ','#','\0'},
	//	//{'#',' ',' ',' ',' ',' ',' ',' ','#','\0'},
	//	//{'#',' ',' ',' ',' ',' ',' ',' ','#','\0'},
	//	//{'#',' ',' ',' ',' ',' ',' ',' ','#','\0'},
	//	//{'#',' ',' ',' ',' ',' ',' ',' ','#','\0'},
	//	//{'#','#','#','#','#','#','#','#','#','\0'}
	//	""
	//};


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

	//// (3,5) �÷��̾ �����ȴ�.
	//STAGE[2][4] = PLAYER;
	 
	STAGE[playerY][playerX] = PLAYER;

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
	render(STAGE);

	//_kbhit()�� _getch()�� C���� Ű���� �Է��� �ǽð����� ó���� �� ���� ����ϴ� �Լ��Դϴ�.
	// �� �� ǥ�� C �Լ��� �ƴϰ�, MS - DOS / Windows�� �ܼ� �Լ���, <conio.h> ������Ͽ� ��� ����.

	int playerX = 5;
	int playerY = 5;

	int* playerXPtr = &playerX;
	int* playerYPtr = &playerY;

	PlayerMove(playerXPtr, playerYPtr);

	while (1) {
		// �Է��� ���� ���� ó��(WASD �̵�, ESC ����)
		if (_kbhit()) { 
			int ch = _getch();
			if (ch == 27) break; // ESC

			int nx = playerX;
			int ny = playerY;

			if (ch == 'w' || ch == 'W') ny--;
			else if (ch == 's' || ch == 'S') ny++;
			else if (ch == 'a' || ch == 'A') nx--;
			else if (ch == 'd' || ch == 'D') nx++;

			// 4) �̵� ���� ���� üũ
			//    - �迭 ���: 1 ~ MAPW-2, 1 ~ MAPH-2
			//    - ��(#)�� ��� �Ұ�
			if (nx >= 1 && nx <= MAPW - 2 &&
				ny >= 1 && ny <= MAPH - 2 &&
				STAGE[ny][nx] != WALL)
			{
				// (����) ������ ó��: ���̸� �԰� �����
				if (STAGE[ny][nx] == MONEY) {
					// ���� ���� ���� ������ ���⿡ �߰� ����
					printf("���� �ֿ���!\n");
				}
				// �����ͻ����δ� (5,5)
				// ���ʹ� (5,5)�� ������ ������ ���� ���������� �� @�� �ٽ� �׸���� ��ɾ ���� ������ ����� ��ó�� ���δ�. ��, ���� �����ʹ� �������� �����δ� ��õ��� �ʴ� ��Ȳ.
				// �÷��̾ �׸��� ������ �ڸ��� �������� �̵��ϴ� ����
				
				// ���� �ڸ� ����� �� �ڸ��� �̵�
				STAGE[playerY][playerX] = ' ';
				playerX = nx;
				playerY = ny;
				STAGE[playerY][playerX] = PLAYER;
			}

			render(STAGE);
		}

		// �ʹ� ������ �ʰ� ������ ����
		Sleep(16); // �� 60fps Sleep()�� ���α׷��� ��� ���߰�(�Ͻ� ����) �ϴ� �Լ��Դϴ�. ��, ���� �ð� ���� CPU ������ ���߰� �����ԡ� �ϴ� �Լ�����.
	}

	return 0;

	
}
void PlayerMove(int* plyerX, int* plyerY)
{
	// windows.h kbhit()
	// �Է¹��� �ڵ带 PlayerMove() -> main�Լ����� ���� ����Ǵ� ���� �޵��� ������. 
	// ���ǹ��� ����� �ָ� ���� x�� ���� �ٲ���


	*plyerX = *plyerX + 1;

	// scanf
	// 'w'    -> Y +1
	// 'S'    -> Y -1
	// 'D'    -> X -1
	// 'A'    -> X +1



}