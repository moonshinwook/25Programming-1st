
// 포인터 공부 어떻게 하면 되나요? 
// 1. 정의해보기 포인터란 무엇인가? 왜 쓰는가? 
// 2. &, int*, *변수이름 각 연산자가 어떻게 쓰는가? 
// 예제 코드를 직접 구현해보기.
// 3. 포인터와 배열의 관계

// 4. 포인터와 구조체의 관계 - 아직 설명x 
// 5. 포인터를 매개변수로 사용하는 함수를 만들어보세요.

// 배열구현까지 완료가 되셨다면. 같은 몬스터 N개 구현이 가능해졌다. -> 별피하기 
// 별이 떨어지는데, 별마다 특징을 다르게 하고 싶다. -> 객체. 다른 특징을 보유하게 하고 싶다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <conio.h> // 입출력 관련 헤더
#include <Windows.h> // 키보드 입력 
#include "Screen.h"

void GoToXY(int x, int y);


typedef struct PlayerPos
{
	int x;
	int y;
}PlayerPos;
// 타입 선언 -> typedef 
PlayerPos playerPos = { 0,0 }; // 전역변수로 선언

PlayerPos ePos = { 5,5 };  // 구조체의 이름을 COORD 공용적인 이름으로 

// 외부에서 받아오는 코드 : 

void PlayerControl(input)
{
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
					if (playerPos.y >= MAPHEIGHT)
					{
						playerPos.y = MAPHEIGHT;
					}
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
}

void Update()
{
	// 플레이어 이외에 이동하는 코드

	ePos.x++;   // 화면 밖으로 이동하면 문제가 발생한다. 데이터 로직상으로 막아보세요. 조건문
	
	if (ePos.x >= 30)
	{
		ePos.x = 0;
	}
	
	//ePos.y--;
	

	Sleep(50); // 
}

void Render() // 전역변수 없는 경우 ()안에 PlayerPos playerPos 선언 필요
{
	//system("cls"); // 잔상 지우기
	//GoToXY(playerPos.x, playerPos.y);
	//printf("!");
	ScreenClear();
	ScreenPrint(playerPos.x, playerPos.y, "!");
	ScreenPrint(ePos.x, ePos.y, "#");
	ScreenFlipping();
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
	else 
	{
		return false;
	}
}

// player좌표 구조체. x값과 y값을 수정할 수 있게 만들어보세요.


void GoToXY(int x, int y) // 공용으로 쓰기 위해 int x, int y 선언
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{	
	unsigned char input = 0; // 화살표 225, char는 -128 127까지 표현되어서 unsigned char로 선언

	// 화면을 2개 만들어 주세요.
	ScreenInit();

	while (1) //게임루프
	{
		// 로직
		// 조작하는 함수 playerhandle playercontrol
		// Update(갱신하다)
		// 렌더 (데이터 변경되면 그것을 실행하라)
		// 플레이어의 이동.
		// 키보드 화살표 방향키로 이동하기
		PlayerControl();
		Update();
		Render();
		//_getch(); //입력 대기
		if (Quit())
		{
			break;
		}
	}
}


// 개발 노트

// 플레이어의 조작을 해서 화면에 움직이게 구현함 (데이터) - (화면 출력)
// 버그    -> 이전에 있던 위치가 계속 남아있다. 잔상이 남는다
// 해야할일 -> 각 기능을 함수에 넣기
// system("cls") 화면을 없애도록 수정 -> 화면이 깜빡거리는 문제가 발생
// '화면버퍼' - 화면0 <-, 화면1<- 
// 커서를 통한 입력에서 1p 2p 플레이어 동시 입력을 받는 경우 충돌 발생이 있어 다른 방법을 생각하는 것이 필요. -> 공용 서버 활용을 통한 입력을 실시간 화면에 출력 등등...
