#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>
// 포인터(pointer) : 가르키다
// 컴퓨터 프로그래밍에서 포인터 : (주소) 가르키다
// 주소는 무엇인가? 
// 택배. 위치를 알고 싶다. 한국. 부산. 서면. 어떤길. 건물맞은편...-> 위치에 대한 부연설명이 필요함.
// 컴퓨터. 데이터에 대한 위치를 알고 싶다. RAM a10 b10 가져오세요. 010101010 주소.
// 컴퓨터의 주소는 16진수로 저장이 되어 있다. 
// 포인터도 16진수로 저장이 되어 있다.
// 컴퓨터는 왜 16진수로 저장할까요?

// 0x00 : 0F  ->  00001111 => 1byte

void Add(int* value); // void 함수 선언
void Minus(double* valuePtr);
void PlayerMove(int* PlayerX, int* PlayerY);

enum { MAX_X = 40, MAX_Y = 20 };  // 경계 상수

// 콘솔 커서 이동
static void gotoxy(int x, int y) {
	COORD pos = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 화면 지우기
static void ClearScreen(void) {
	system("cls");
}

// 플레이어 그리기
static void DrawPlayer(int x, int y) {
	gotoxy(x, y);
	putchar('@');
}


int main()
{
	int a = 10; // a이름에 int저료형을 저장하겠다. -> 4바이트의 정수로 데이터 저장
	Add(&a); // a주소를 가져오겠다 선언

	//scanf("%d", &a); // & (주소연산자)
	printf("&a의 컴퓨터가 보고 있는 숫자 : %p\n", &a);

	// 포인터 선언.

	int* aPtr = &a; // pointer -> ptr 축약어, '*' : 포인터 선언 주소를 저장할 수 있게 되었다. 16진수 읽는 방법이 잘못되었다.
	int value = *aPtr;     // 역참조 연산자 (*)
	printf("value 값 : %d\n", value);

	// 포인터는 포인터 타입으로 사용해야 한다.
	// Value타입과 pointer(주소)를 구분해서 사용해야 한다.

	char b = 'b'; // 컴퓨터는 'b'를 %d출력 시 숫자로 출력이 된다.
	// printf("b를 숫자로 출력해 : %d\n", b);
	char* bPtr = &b; // bPtr char주소를 저장하는 포인터 (변수) 
	bPtr = &a;       // bPtr 주소변수에 a의 주소를 저장하라.

	printf("bPtr의 값 : %d\n", *bPtr); // 16진수값을 10진수로 표현하니까 -> *를 &로 해버리면 이상하게 출력됌.

	// (1) 포인터 주소를 선언할 수 있다.
	// (2) 주소를 이용해서 주소에 저장된 값을 불러올 수 있다.
	// (3) 변수에 저장된 주소를 사용할 수 있다. 

	// double 저장할 수 있는 c변수를 선언하고, 
	// (1), (2), (3)을 이용해서 cPtr 이용하여 값을 출력해보세요.

	double c = 1.11;
	double* cPtr = &c;
	Minus(cPtr); // & 주소 연산자는 실수가 많이 나옴 -> Ptr을 붙여서 사용하는 편
	printf("cPtr에 저장된 값 : %.2lf\n", *cPtr); // %lf 이용

	// 포인터에 대한 깊은 이해
	// (1) 포인터도 변수다. 포인터에 다른 주소를 저장할 수 있다.

	//*cPtr = 0.1;

	//cPtr = &b; // cPtr, 주소를 저장하는데 실수의 주소를 읽어온다. , bPtr 정수의 주소를 읽어온다.
	//printf("cPtr에 저장된 값 : %d\n", *cPtr); // %lf 이용 char는 정수를 표현하는 타입. -> %d 



	// 01010101 (1.m) * 2^n
	// 컴퓨터의 눈에는 0,1밖에 안보인다. 자료형을 선언해서 컴퓨터가 어떻게 해석할지 정해준다.

	// Pointer 주소를 저장하는 녀석이 => 자료형에 대한 주소다.
	// int* numPtr;  주소를 저장하는 녀석이다. + 시작점[AA AA AA AA]
	// int a = 10;		0110
	// double *doblePtr; doublePtr = &a;	시작점[00 00 00 00 00 A]
	// 주소를 알고 그 주소에서 어디까지 해석해야 하는지에 대한 정보를 알고 있으면, 
	// 컴퓨터에서 정보를 가져올 수 있다.
	// (1) 함부로 다른 타입의 주소를 넘겨주면 예측할 수 없는 오류가 발생할 수 있다.
	// (2) 정수의 주소를 넘겨받아서 비트를 이용해서 코드를 짜는 예제. 

	// 포인터에 const를 사용하면 -> 포인터 주소를 변경하지 못하게 막을 수 있을까?



	// *포인터 변수 -> 포인터 가르키고 있는 값을 변경하지 못하게 막을 수 있을까?

	// 포인터를 왜 사용하는가? 
	int PlayerX = 5;
	int PlayerY = 5;


	PlayerMove(&PlayerX, &PlayerY);

}

void Add(int* value) // 1개 보다 많으면? a가 저장하고 있는 주소를 가져와라
{
	*value += 3; // value주소에 저장되어 있는 값을 3 더하라.

	value += 3; // value = value + 3
}

void Minus(double* valuePtr)
{
	*valuePtr -= 1;

}


// Player x,y 좌표
// 메인 함수에서 실행이 된다.
// 함수에서 변경하고 그 변경된 값을 메인에 있는 값에도 변경이 되도록 하고 싶다.
void PlayerMove(int * PlayerX, int * PlayerY)
{
	char input;

	ClearScreen();
	DrawPlayer(*PlayerX, *PlayerY);

	while (1)
	{
		printf("\n이동 (WASD) 입력 (q: 종료): ");
		// 앞에 공백: 이전 개행 등 공백 문자 무시
		if (scanf(" %c", &input) != 1) continue;

		int oldX = *PlayerX, oldY = *PlayerY;

		if (input == 'w' || input == 'W') {
			if (*PlayerY > 0) (*PlayerY)--;
		}
		else if (input == 's' || input == 'S') {
			if (*PlayerY < MAX_Y) (*PlayerY)++;
		}
		else if (input == 'a' || input == 'A') {
			if (*PlayerX > 0) (*PlayerX)--;
		}
		else if (input == 'd' || input == 'D') {
			if (*PlayerX < MAX_X) (*PlayerX)++;
		}
		else if (input == 'q' || input == 'Q') {
			printf("게임을 종료합니다.\n");
			return;
		}
		else {
			printf("잘못된 입력입니다.\n");
			continue;
		}

		// 좌표가 바뀐 경우만 리프레시
		if (oldX != *PlayerX || oldY != *PlayerY) {
			ClearScreen();
			DrawPlayer(*PlayerX, *PlayerY);
		}
	}
}
