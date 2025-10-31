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

#define MAPH (MAPSIZE)
#define MAPW (MAPSIZE*2 - 1) //#define 은 매크로 상수 정의 구문입니다.→ 컴파일 전에, 코드 안의 MAPH와 MAPW를 각각 오른쪽 값으로 “치환”합니다.

// 맵 그리기(문자열로 한 줄씩)
void render(char STAGE[MAPH][MAPW + 1]) {
	system("cls"); // 콘솔 화면을 모두 지움 (Clear Screen)
	for (int y = 0; y < MAPH; y++) { //맵의 세로줄(y축)을 순회
		printf("%s\n", STAGE[y]); //각 줄의 문자열을 한 줄씩 출력
	}
}
void PlayerMove(playerXPtr, playerYPtr);

int main()
{
	// 맵 버퍼: 가로는 표시문자 MAPW + 문자열종료문자('\0') 1칸
	char STAGE[MAPH][MAPW + 1]; // 맵크기

	// 1) 외곽 벽과 내부 공백으로 초기화
	for (int y = 0; y < MAPH; y++) {
		for (int x = 0; x < MAPW; x++) {
			if (y == 0 || y == MAPH - 1 || x == 0 || x == MAPW - 1) {
				STAGE[y][x] = WALL;     // 바깥 테두리
			}
			else {
				STAGE[y][x] = ' ';      // 내부 빈칸
			}
		}
		STAGE[y][MAPW] = '\0';          // 각 줄 문자열 종료
	}

	// Text로 출력을 해야한다 -> 문자로 이루어져있는 배열

	int monsterX = 7;
	int monsterY = 7;
	// 10 char저장할 수 있는데 첫번째 데이터 ! 저장하겠다. ''사이 스페이스바로 띄워서 공백문자 표현
	//char STAGE[MAPSIZE][MAPSIZE * 2] =
	//{
	//	//{'#','#','#','#','#','#','#','#','#','\0'}, // MAPSIZE 전체를 '#' 가득채운다.
	//	//{'#',' ',' ',' ',' ',' ',' ',' ','#','\0'}, // 첫번쨰와 마지막-1 '#', 마지막 '\0'
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

	//// (3,5) 플레이어가 생성된다.
	//STAGE[2][4] = PLAYER;
	 
	STAGE[playerY][playerX] = PLAYER;

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
	render(STAGE);

	//_kbhit()와 _getch()는 C언어에서 키보드 입력을 실시간으로 처리할 때 자주 사용하는 함수입니다.
	// 둘 다 표준 C 함수는 아니고, MS - DOS / Windows용 콘솔 함수로, <conio.h> 헤더파일에 들어 있음.

	int playerX = 5;
	int playerY = 5;

	int* playerXPtr = &playerX;
	int* playerYPtr = &playerY;

	PlayerMove(playerXPtr, playerYPtr);

	while (1) {
		// 입력이 있을 때만 처리(WASD 이동, ESC 종료)
		if (_kbhit()) { 
			int ch = _getch();
			if (ch == 27) break; // ESC

			int nx = playerX;
			int ny = playerY;

			if (ch == 'w' || ch == 'W') ny--;
			else if (ch == 's' || ch == 'S') ny++;
			else if (ch == 'a' || ch == 'A') nx--;
			else if (ch == 'd' || ch == 'D') nx++;

			// 4) 이동 가능 여부 체크
			//    - 배열 경계: 1 ~ MAPW-2, 1 ~ MAPH-2
			//    - 벽(#)은 통과 불가
			if (nx >= 1 && nx <= MAPW - 2 &&
				ny >= 1 && ny <= MAPH - 2 &&
				STAGE[ny][nx] != WALL)
			{
				// (선택) 아이템 처리: 돈이면 먹고 지우기
				if (STAGE[ny][nx] == MONEY) {
					// 점수 증가 같은 로직을 여기에 추가 가능
					printf("돈을 주웠다!\n");
				}
				// 데이터상으로는 (5,5)
				// 몬스터는 (5,5)를 가지고 있지만 현재 덧씌워졌을 때 @를 다시 그리라는 명령어가 없기 때문에 사라진 것처럼 보인다. 즉, 몬스터 데이터는 남았지만 눈으로는 명시되지 않는 상황.
				// 플레이어를 그리면 몬스터의 자리에 덧씌워서 이동하는 원리
				
				// 이전 자리 지우고 새 자리로 이동
				STAGE[playerY][playerX] = ' ';
				playerX = nx;
				playerY = ny;
				STAGE[playerY][playerX] = PLAYER;
			}

			render(STAGE);
		}

		// 너무 빠르지 않게 프레임 조절
		Sleep(16); // 약 60fps Sleep()은 프로그램을 잠시 멈추게(일시 정지) 하는 함수입니다. 즉, 일정 시간 동안 CPU 실행을 멈추고 “쉬게” 하는 함수예요.
	}

	return 0;

	
}
void PlayerMove(int* plyerX, int* plyerY)
{
	// windows.h kbhit()
	// 입력받은 코드를 PlayerMove() -> main함수에서 값이 변경되는 것을 받도록 만들어라. 
	// 조건문만 만들어 주면 언제 x의 값이 바뀔지


	*plyerX = *plyerX + 1;

	// scanf
	// 'w'    -> Y +1
	// 'S'    -> Y -1
	// 'D'    -> X -1
	// 'A'    -> X +1



}