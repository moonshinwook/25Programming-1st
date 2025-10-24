
// 함수 추출법

// 이름에 이유가 있다 Function - 수학 시간
// 함수가 무엇일까? 처리 절차를 거치면 어떤 결과값이 반환되는 기능
// 함수를 왜 쓸까? 어떤 두 수를 더했는지 결과값에 출력할 수 있도록 수정해줘. 

// 반환값 함수 이름 (매개 변수); Head <<
//{ body 본문 }						<<

// 

// 메인 함수. 
// 프로그램을 시작과 끝을 표현하는 기능을 하고 있다. 

// 함수를 먼저 생성하고 - 생성한 함수를 사용
// 번환타입 + 함수이름 (매개 변수); - 작업을 통해서만 함수가 생성된다. 

// 함수를 표현하는 방식에는 4가지 유형
// 반환값 x 인자값 x
// 반환값 o 인자값 x
// 반환값 x 인자값 o
// 반환값 o 인자값 o
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Math.h" // 헤더파일 가져오기


// Minus
// Multiply
// Divide


int main()
{
	int num1 = 6;
	int num2 = 0;

	Add(num1, num2); // statement ( 명령'문') Add함수를 num1, num2를 인자로서 실행하라. 
	Add(3, 5);		 // Add함수를  3 -> num1, 5 -> num2 Add함수를 실행하라

	Minus(num1, num2);

	Multiply(num1, num2);

	Divide(num1, num2);

	// 플레이어가 낸 가위 바위 보에 해당하는 숫자를 출력하고 싶다.
	int playerchoice = SelectPlayerBehavior(); // 1 가위, 2 바위, 3 보
	printf("플레이어의 선택 값 : %d", playerchoice);
	// 캐릭터의 초기 스텟 설정
	Selectcharacter(10);

	// 함수 안에서는 코드가 잘 실행이 된거 같은데 main 다른 코드는 영향을 끼치지 않는다.

	// scanf 입력받은 값을 사칙연산으로 처리하는 코드 만들 수 있다. 
	
	return 0; // int main이 있었기 때문에 0을 적는다. 게임에서 종료기능 만들고 싶어요. return을 하도록 만들면 된다. 어떤 숫자를 입력하면 프로그램을 종료하겠다. 
}

// 캐릭터를 선택해서 스텟을 분배한다던가 하는 함수
// Dice, STR, DEX, INT, LUK 분배 

/*
*  반환값이 void 함수를 왜 사용할까? 
*  반환값이 없더라도 코드를 수정할 수 있는가? 주소의 개념을 이해하면									-Value vs -Reference
*  함수 안에서만 코드가 실행이 되고 실제로는 변경이 안되는 기능이 필요하다. (ex) UI 다음 레벨을 보여주는 기능이 실제로 장비의 성능을 변경시키면? 
* 
*/

// 스탯 포인트를 분배해서 STR, DEX, INT, LUK 잘 출력이 되도록 만들어보세요
// startpoint 보다 넘는 값을 실행해서는 안됩니다. 
// 분배한 스탯이 main에서도 사용될려면 어떻게 해야할까? <고민>
void Selectcharacter(int startpoint)
{
	printf("%d 스탯 포인트를 분배해주세요\n");
	printf("STR : 0 DEX : 1 INT = 2 LUK = 3\n");
	int selectNumber = 0;
	int remainpoint = startpoint;
	int spendpoint;
	int STR = 0;
	int DEX = 0;
	int INT = 0;
	int LUK = 0;
	scanf("%d", &selectNumber);
	if(selectNumber == 0)
	{
		scanf("%d", &selectNumber);

		remainpoint = remainpoint - spendpoint;
		STR = STR - spendpoint;
	}

}

int SelectPlayerBehavior()
{
	// 가위, 바위, 보, 슈퍼 가위

	int num = 0;
	scanf("%d", &num);

	if(num == 1)
	return 1; // 가위
	else if(num == 2) 
	return 2; // 바위
	else if(num == 3) 
	return 3; // 보
}

