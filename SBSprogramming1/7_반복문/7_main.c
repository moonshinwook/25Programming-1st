/*
* �н� ��ǥ: for �ݺ����� while�ݺ����� ���� �����ϱ�
* �ǽ� ��ǥ: ���� �ð��� �����ߴ� �ڵ带 �ݺ������� ǥ���ϱ�
*
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
int main()
{
	// �ݺ��� �� �ִ� Ƚ���� ���� �Է� �޾Ƽ� ����ϱ�
	//scanf (c���� ����ϴ� ���) 
	// c++ �Է� �޴� �Լ�
	// csharp, py, java ... Unreal, Unity

	// 1. for�ݺ��� (��� ����)
	int num1 = 97;
	int loopCount = 15;
	printf("�ݺ��� �Լ��� �ۼ����ּ��� : ");					 // �Է��� �ޱ� ���� �ܼ�â�� ���������Ÿ���.
	scanf("%d", &loopCount); // loopCount �ּ� ��ĭ ��� ����Ǿ��ִ�. &(������)
	for (int i = 0; i < loopCount; i++) //������ ������ �� {} �Լ� �ݺ� ++ -> 1���ϱ�

	{
		//num1 = num1 + 1;
		printf("%c ", num1 + i);	// a	b	c	d
		printf("%d ", i);	//	1	2	3	4
	}


	// 0 ~ 9 [ 10 ] �ݺ��ϰ� ���� ���ڷ� �ٲ㺸����
	// ���� �������ڷ� �ۼ� �� �������ڸ� ������ ��ü�Ͽ� �ٲ㺸��

	// 2. while�ݺ���
	// while( �ݺ��� ���� ���̸�) �߰�ȣ�� �ڵ带 �����϶�.
	printf("\n ========================== while�ݺ��� ======================= \n");
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
	// ���� ���� ���

	srand(time(NULL)); // ���� ������ �ʱ�ȭ
	int randomValue = rand() % 3 + 1; // 1~100 ���	
	printf("���� �� : %d \n", randomValue);
}

