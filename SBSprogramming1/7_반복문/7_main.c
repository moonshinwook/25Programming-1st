/*
* 학습 목표: for 반복문과 while반복문의 문법 이해하기
* 실습 목표: 지난 시간에 구현했던 코드를 반복문으로 표현하기
*
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
int main()
{
	// 반복할 수 있는 횟수를 직접 입력 받아서 사용하기
	//scanf (c언어에서 사용하는 방식) 
	// c++ 입력 받는 함수
	// csharp, py, java ... Unreal, Unity

	// 1. for반복문 (사용 예시)
	int num1 = 97;
	int loopCount = 15;
	printf("반복할 함수를 작성해주세요 : ");					 // 입력을 받기 위해 콘솔창이 깜빡깜빡거린다.
	scanf("%d", &loopCount); // loopCount 주소 몇칸 어떻게 저장되어있다. &(덮어씌우기)
	for (int i = 0; i < loopCount; i++) //조건을 만족할 시 {} 함수 반복 ++ -> 1더하기

	{
		//num1 = num1 + 1;
		printf("%c ", num1 + i);	// a	b	c	d
		printf("%d ", i);	//	1	2	3	4
	}


	// 0 ~ 9 [ 10 ] 반복하고 싶은 숫자로 바꿔보세요
	// 먼저 고정숫자로 작성 후 고정숫자를 변수로 대체하여 바꿔보기

	// 2. while반복문
	// while( 반복할 조건 참이면) 중괄호를 코드를 실행하라.
	printf("\n ========================== while반복문 ======================= \n");
	int num2 = 97;
	int j = 0;
	while (j < loopCount)
	{
		printf("%c ", num2 + j);
		printf("%d ", j);
		j++;

	}
	printf("\n");
	num2 = 97;
	j = 0;

	while (true)
	{
		printf("%c ", num2 + j);
		printf("%d ", j);
		j++;
		if (j >= loopCount)
		{
			break;
		}
	}
	// 랜덤 숫자 출력

	srand(time(NULL)); // 난수 생성기 초기화
	int randomValue = rand() % 3 + 1; // 1~100 출력	
	printf("랜덤 값 : %d \n", randomValue);
}

