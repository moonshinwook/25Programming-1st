#include <stdio.h>
#include <Math.h>

void Add(int num1, int num2) 
{
	int result = num1 + num2;
	printf("두 수를 더한 값 : %d + %d = %d\n", num1, num2, result); // -> 하나로 표현하고 싶다
}

void Minus(int num1, int num2)
{
	int result2 = num1 - num2;
	printf("두 수를 뺀 값 : %d - %d = %d\n", num1, num2, result2);
}

void Multiply(int num1, int num2)
{
	int result3 = num1 * num2;
	printf("두 수를 곱한 값 : %d x %d = %d\n", num1, num2, result3);
}

void Divide(int num1, int num2)
{
	if (num2 == 0) {
		// (1) 코드를 더이상 실행하지 않고 종료해주세요.
		// (2) 뒤에 있는 값으로 반환한다.  
		return; // 종료 
	}

	int result4 = num1 / num2;
	printf("두 수를 나눈 값 : %d / %d = %d\n", num1, num2, result4);
}