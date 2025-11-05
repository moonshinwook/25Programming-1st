#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Sample.h"

/*
*  열거형
*  - 상수 : 값을 고정시키겠다.
*  - const 변수 선언;
*  - #define PI 3.14
*/


/*
*  구조체
*
*/

// 열거형 : 0, 1, 2, 3, 4, 5, 6, 7, 8, 
//		   동전, 포션, ...


#define MONSTERCOUNT 10 // -> MONSTERCOUNT = 10으로 
#define MONSTERRACE 5

typedef enum RACE {
	ORC,
	HUMAN,
	UNDEAD,
	ANGEL,
	UNDEFINED = 100, // 개발 도중인 어떤 것, 정수로 저장된 타입이라 = 100이면 100+1인 형태로 정의된다.
	DEVIL
}Race;		// typedef을 붙여주면 전역변수를 타입을 뜻하게 됌.

typedef enum {					// 무명방식 (이름없이 사용) -> 코드의 간략화, enumarration(열거)의 준말
	SCORE,
	COIN,
	HEALTH
}GameText; // 열거형을 정의하고 TEXT를 전역변수로 하겠다

// #define 점수 = 0, 동전 = 1, 체력 = 2 사용하는 것이랑 enum 정의하는 것의 차이점이 무엇일까요? 

// 열거형 간결하게 사용하는 방법 typedef

// 조건문과 열거형을 같이 사용하는 패턴

int main()
{
	//enum GameText GameText = SCORE;

	// 상수는 값을 변경하지 못하게 하는 방법이다. 
	const int count = 10;
	printf("몬스터의 수 : %d\n", MONSTERCOUNT);
	printf("몬스터의 수 : %d\n", count);

	const char* Text[3] = { "점수", "동전", "체력" };
	const char* RaceName[3] = { "ORC", "HUMAN", "UNDEAD" };

	printf("%s\n", Text[SCORE]); // 숫자를 어떠한 의미를 가지도록 약속을 했다.
	printf("%s\n", RaceName[ORC]);



	enum GameText newGameText = SCORE;
	newGameText = HEALTH;
	//if (newGameText == SCORE)
	//{
	//	printf("점수를 출력하는 예제입니다.\n");
	//}
	//else if (newGameText == COIN)
	//{
	//	printf("동전을 출력하는 예제입니다.\n");
	//}
	//else if (newGameText == HEALTH)
	//{
	//	printf("체력을 출력하는 예제입니다.\n");
	//}
	//else

	Race race = ORC;

	switch (race) // 변수를 입력
	{
		case ORC: printf("나는 종족이 오크입니다.\n");
			break;
		case HUMAN:printf("나는 종족이 휴먼입니다.\n");
			break;

		default: race = UNDEFINED; // 변수에 정의되어 있지 않은 것에 대한 처리
			break;
	
	}

	JOB myJOB = JOBUNDEFINED;
	int baseHP = 0;
	int baseATK = 0;
	int* baseHPptr = &baseHP;
	int* baseATKptr = &baseATK;
	Selectjob(&myJOB); // 직업을 선택하는 함수
	SetplayerStat(myJOB, baseHPptr, baseATKptr);
	// JOB에 따라서 기본적인 체력과 공격력이 다르다. 
	// 직업에 따른 캐릭터 설정(myJOB); // int hp int atk스탯 정보  


}