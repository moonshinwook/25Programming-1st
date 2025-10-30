#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> // gotoxy를 사용하기 위해 필요

/*
*  배열의 활용
*  2차원 배열
*  게임에서 적용
*/

// 플레이어 조작
// 

// 플레이어  :  !
const char PLAYER = '!'; // 문자의 크기가 1인 기호만 대체 가능 
// 몬스터    :  @
const char MONSTER = '@';
// 돈		:   $
const char MONEY = '$';
// 벽		:   #
const char WALL = '#';

#define MAPSIZE 20 // MAPSIZE를 전부 10으로 바꿔서 처리해라

// static은 main에서만 사용하게끔 하는 것, const는 변수값을 고정 MAPSIZE++; 출력할려고 하면 오류 발생

// STAGE별로 나눌려면 어떻게 처리해야 할까? -> 준비되어 있는 좌표들이 있다. 시작할 때 세팅을 출력하라.

// 플레이어의 이동을 할 수 있게 하는 코드 서치 후 대입
int playerX = 5;
int playerY = 5;

void drawMap() {
	int x, y;
	system("cls"); // Windows의 경우. Linux/macOS의 경우 system("clear"); 사용

	for (y = 0; y < MAPSIZE * 2; y++) {
		for (x = 0; x < MAPSIZE; x++) {
			if (x == playerX && y == playerY) {
				printf("P"); // 플레이어
			}
			else if (x == 0 || x == MAPSIZE - 1 || y == 0 || y == MAPSIZE * 2 - 1) {
				printf("#"); // 벽
			}
			else {
				printf("."); // 빈 공간
			}
		}
		printf("\n");
	}
}

void movePlayer() {
	char input;
	if (_kbhit()) { // 키 입력이 있는지 확인 (Windows)
		input = _getch(); // 키 입력 받기 (Windows)

		switch (input) {
		case 'w': // 위로 이동
			if (playerY > 1) playerY--;
			break;
		case 's': // 아래로 이동
			if (playerY < MAPSIZE * 2 - 2) playerY++;
			break;
		case 'a': // 왼쪽으로 이동
			if (playerX > 1) playerX--;
			break;
		case 'd': // 오른쪽으로 이동
			if (playerX < MAPSIZE - 2) playerX++;
			break;
		}
	}
}
int main()
{
	// Text로 출력을 해야한다 -> 문자로 이루어져있는 배열

	int monsterX = 7;
	int monsterY = 7;
	// 10 char저장할 수 있는데 첫번째 데이터 ! 저장하겠다. ''사이 스페이스바로 띄워서 공백문자 표현
	char STAGE[MAPSIZE][MAPSIZE * 2] =
	{
		//{'#','#','#','#','#','#','#','#','#','\0'}, // MAPSIZE 전체를 '#' 가득채운다.
		//{'#',' ',' ',' ',' ',' ',' ',' ','#','\0'}, // 첫번쨰와 마지막-1 '#', 마지막 '\0'
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

	// 이중 반복문을 사용하여 맵을 세팅한다.
	for (int y = 0; y < MAPSIZE; y++) // y의 배열
	{
		for (int x = 0; x < MAPSIZE * 2; x++) // x의 배열
		{
			// 패턴1
			if (y == 0 || y == MAPSIZE - 1) // or 조건으로 표현하면 좋겠다. ||
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

	// 게임 로직. 5Frame 후에 몬스터가 x방향으로 1움직였다. x+1
	
	//Initialize();
	//Setup();

	//while (1)
	//{
	//	// 게임이 실행되는 순서의 로직을 작성해야 한다.

	//	// 초기화 : 데이터가 없으면 기본 값으로 설정하고, 초기 값으로 설정한다.

	//	// 데이터가 변동 (게임 루프) Update

	//	//Update();
	//	//Render(); // 화면에 그려주세요.
	//	//Buffer(); // 움직이고 나면 잔상이 남습니다., 포인터의 개념을 배워야 합니다.
	//}

	// (3,5) 플레이어가 생성된다.
	STAGE[2][4] = PLAYER;
	// (5,7) 돈이 생성된다.
	STAGE[4][6] = MONEY;
	// (8,8) 몬스터가 생성된다.
	monsterX -= 6;
	STAGE[monsterY][monsterX] = MONSTER;
	// 세팅된 맵을 화면에 보이게 하라
	for (int h = 0; h < MAPSIZE; h++)
	{
		printf("%s\n", STAGE[h]);
	}


}