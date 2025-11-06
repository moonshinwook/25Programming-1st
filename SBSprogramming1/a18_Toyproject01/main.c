
// 포인터 공부 어떻게 하면 되나요? 
// 1. 정의해보기 포인터란 무엇인가? 왜 쓰는가? 
// 2. &, int*, *변수이름 각 연산자가 어떻게 쓰는가? 
// 예제 코드를 직접 구현해보기.
// 3. 포인터와 배열의 관계

// 4. 포인터와 구조체의 관계 - 아직 설명x 
// 5. 포인터를 매개변수로 사용하는 함수를 만들어보세요.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <conio.h> // 입출력 관련 헤더




void PlayerControl()
{

}

void Update()
{

}

void Render()
{

}

bool Quit()
{
	// 게임이 종료될 조건을 Bool 반환하는 함수로 만들어서
	int input = 0;
	//scanf("%d", &input);
	if (input == 5) // 조건이 만족하면 종료하라.
	{
		return true;
	}
	else {
		return false;
	}
}

// player좌표 구조체. x값과 y값을 수정할 수 있게 만들어보세요.

typedef struct PlayerPos
{
	int x;
	int y;
}playerPos;

PlayerPos playerPos = { 0,0 };

int main()
{

	while (1) //게임루프
	{
		// 로직
		// 조작하는 함수 playerhandle playercontrol
		// Update(갱신하다)
		// 렌더 (데이터 변경되면 그것을 실행하라)
		// 플레이어의 이동.

		// 키보드 화살표 방향키로 이동하기.

		unsigned char input = 0; // 화살표 225, char는 -128 127까지 표현되어서 unsigned char로 선언

		

		if (_kbhit()) // 키보드를 입력하면 true로 
		{
			input = _getch(); // conio.h에 있는 함수, <<< breaking point 엔터키를 칠때까지 기다려주는 

			if (input == 224 || input == 0)
			{
				if (input == 224 || input == 0) {
					input = _getch(); // 실제 방향키 코드 받기
					switch (input) {
					case 72: // 위쪽 화살표 (UP)
						playerPos.y--;
						break;
					case 80: // 아래쪽 화살표 (DOWN)
						playerPos.y++;
						break;
					case 75: // 왼쪽 화살표 (LEFT)
						playerPos.x--;
						break;
					case 77: // 오른쪽 화살표 (RIGHT)
						playerPos.x++;
						break;
					}
				}
				}
			}

		

		
		PlayerControl();
		Update();
		Render();

		if (Quit())
		{
			break;
		}

	}
}