#include <stdio.h>
#include <Math.h>

void Add(int num1, int num2) 
{
	int result = num1 + num2;
	printf("�� ���� ���� �� : %d + %d = %d\n", num1, num2, result); // -> �ϳ��� ǥ���ϰ� �ʹ�
}

void Minus(int num1, int num2)
{
	int result2 = num1 - num2;
	printf("�� ���� �� �� : %d - %d = %d\n", num1, num2, result2);
}

void Multiply(int num1, int num2)
{
	int result3 = num1 * num2;
	printf("�� ���� ���� �� : %d x %d = %d\n", num1, num2, result3);
}

void Divide(int num1, int num2)
{
	if (num2 == 0) {
		// (1) �ڵ带 ���̻� �������� �ʰ� �������ּ���.
		// (2) �ڿ� �ִ� ������ ��ȯ�Ѵ�.  
		return; // ���� 
	}

	int result4 = num1 / num2;
	printf("�� ���� ���� �� : %d / %d = %d\n", num1, num2, result4);
}