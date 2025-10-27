#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "ModifystatValue.h" // 헤더파일 가져오기
// 컴퓨터야 특정 데이터를 저장하는 공간을 만들어라. "메모리"
// 0또는1 이외는 컴퓨터가 알아들을 수 없다. 프로그래밍 언어를 배우는 이유.

/*
*  변수, 함수
*  변수가 왜 필요합니까? 변수를 저장하는 자료형을 지정을 해줬습니다.
*  함수가 왜 필요합니까? 명령어를 작성 statement(명령문) 세미클론 명령이 끝났다 라는 사실을 알린다.
*
*  개발을 할 때 한글로 먼저(Pseudo code: 자연어(한글)로 표현하는 방식) 표현하라.
*  명령문은 한 줄로 표현을 못합니다. -> 코드를 해석하기도 힘들고, 반복적으로 사용하는 코드를 표현하기 힘들다.
*/

/*
*  세미클론 -> 명령문이 종료되는 것을 표현한다. 코드의 끝을 표현한다.
*  중괄호   -> 범위(scope)를 표현한다. {	  } 넓은 의미 : 단일로 표현을 하기 어려운 부분을 하나의 의미로 표현하기 위함.
*  함수 -> 명령문들의 집합. 범위를 표현해야 한다. 함수의 head -> 함수를 구분하기 위한 표현 방식
*  변수 -> (자료형) 변수이름; 변수에도 중괄호를 사용할 수 있을까? -> 변수를 범위로 표현해야 하는 경우가 있을까? => 배열 int[] nums = {1, 2, 3, 4, 5};
*
*
*/

void StatDevideFunc();

int ReturnStatAmount();

void ModifystatValue(int baseAmount);
/*
*  함수 내부의 데이터를(스택 영역) 함수 밖에 사용할 수 있게 만들자.
*
*
*/





int main()
{
	// 코드를 넘겨준다. 
	int INT = 1;
	int DEX = 1; // 실제 저장이 필요한 값들
	int LUK = 1;
	int STR = 1;

	StatDevideFunc();

	printf("main함수 안에 있는 num의 값: %d\n", LUK);

	// 코드를 분석
	// 반복되고 있는 형태를 관찰해보세요.

	// 상수, 리터널, 열거형 

	for (int i = 0; i < ? ; i++)
	{
		ModifystatValue(?); //방법 구현 필요. 밑의 4개를 하나로 표현 -> 줄이기 작업 중
	}

	//ModifystatValue(INT); //한 번에 표현하고 싶음
	//ModifystatValue(DEX);
	//ModifystatValue(LUK);
	//ModifystatValue(STR);

	// 면접 질문 : 코드 개선 경험에 대해 말해보세요. -> 24줄의 코드를 3줄로 표현해보았습니다. (숫자를 표현해보는 걸 추천)
	// 작업에 대한 보고: 1주일 목적 중에서 어느 정도 작업을 하였는가? -> 진척도를 %로 표현해보기.
	


	// 한 함수로 표현해보기. -> 헤더 파일을 응용해서 해보면 되지 않을까?

	//int modifyINT = ReturnStatAmount(INT, 1);
	//printf("전투에 사용될 INT 스탯 : %d\n", modifyINT); // 가위 바위 보 보상에 따른 공격력 증가 함수로 활용 가능하지 않을까??

	//int modifyDEX = ReturnStatAmount(DEX, 1);
	//printf("전투에 사용될 DEX 스탯 : %d\n", modifyDEX); // 전투에만 필요한 것들은 함수로 표현 

	//int modifyLUK = ReturnStatAmount(LUK, 1);
	//printf("전투에 사용될 LUK 스탯 : %d\n", modifyLUK);

	//int modifySTR = ReturnStatAmount(STR, 1);
	//printf("전투에 사용될 STR 스탯 : %d\n", modifySTR);

	//컨트롤 K + 컨트롤 C -> 주석처리 단축키
}

void ModifystatValue(int baseAmount)
{
	int modifyValue = ReturnStatAmount(baseAmount, 1);
	printf("전투에 사용될 INT 스탯 : %d\n", modifyValue);
}

// 실습과제 : 8줄의 코드를 함수로 변경해보세요.

// Q1: main에도 LUK Func에도 LUK이 있다. 컴퓨터가 같은 이름을 구별을 할까? 

// Q1-2: 이름이 전혀 겹치지 않게 만들면 되는거 아닌가요? -> Player, Enemy 이름이 같더라도 사용할 수 있게 만들 수 없을까? -> 지역을 표현.

// Q2: StatDevideFunc함수를 만났을 때 Local이 변경이 되어서 StatDevideFunc의 변수를 표현하고 있다. 함수가 종료가 되었을 때 LUK 사라졌다.

// main() 'LUK = 1'		StatDevideFunc 'LUK = 3' 스택 / 힙 영역  // stack over Flow
// 스택 영역은 사라질 때 가지고 있는 데이터를 모두 소멸시킵니다. 쌓인 데이터를 지우지 않으면 어떤 일이 일어날까요? 블루스크린 컴퓨터에 문제가 생겼을 때 자동으로 불러오는 시스템(보안 기능)
// 코드 지워야지.	 영역이 종료되면 자동으로 메모리를 비워준다.
// 장단점 : 장점) 메모리 관리가 수월하게 컴퓨터 영역을 만들었구나 - 단점) 메모리에 저장해두었다가 사용할 수는 없을까? => 합 영역 구조체??(Struct)




// 함수를 정의하는 단계 
void StatDevideFunc() // 들여쓰기를 자동으로 하는 명령어. (ctlr + k) + (ctlr + d)
{
	// 가중치 플레이어의 레벨, 아이템 등등을 가졌을 때 추가적인 스탯을 준다. => 일시적으로 메모리를 저장해두었다가 지우고 싶다.

	// alt 누른 상태로 드래그한 영역을 화살표 위아래로 움직이기
	int LUK;
	//'scanf("%d", &LUK);
	//printf("num의 값 : %d\n", LUK);

	StatDevideFunc(); // 재귀 함수 -> 계속 반복


	// 코드가 끝날 때 LUK에 할당되어 있는 메모리를 컴퓨터에 비워줘 명령어.
	// 반복문, 조건문, 함수 => 코드를 구현할 수 있다. 
	// 스탯 시스템. 포인트5 -> STR, INT, LUK, DEX 선택해서 스탯을 부여한다. 
	// <- 세미클론이 없다. for반복문 for(int i=0; i<10; i++);{ } 
}	// 중괄호가 코드의 끝을 표현하기 때문에 ;을 붙이지 않는다. 


int ReturnStatAmount(int baseAmount, int itemstatAmount)
{
	int result = 0;
	//게임에 레벨 (Ease, Normal, Hard)	
	int levelCount = 1;
	// if Easy 1, Normal 2, Hard 3
	int itemWeight = 10;
	//장착한 아이템 따른 스탯 
	// 랜덤으로 주사위 굴림을 통한 결과 값을 반환한다. 
	int stat = 10;

	result = levelCount * (itemstatAmount * 10) + baseAmount;

	return result;
}
