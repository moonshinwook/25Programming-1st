// ��ǥ: ����� ��Ʃ������� ǥ���� �� �ִ� �α׶���ũ ���� ���� �� ���� �����.

// �ڵ� �帧
// ���� ���� �� ���� ����!
// ĳ���͸� �����Ͻÿ�. 
// ö�� = 1, ���� = 2�� �������� 
// ���� = 1, ���� = 2, �� = 3

// 3�������� ���� (�������� 1, �������� 2, ����)
// �� �������� Ŭ���� �� ü�� ���� ȸ��, ������ ȸ���� or ���ݷ� 0.4 ������ 
// ��������1 Ŭ���� �� �������� 1 Ŭ����, �������� 2 Ŭ����, ������ �����ƽ��ϴ�. -> ���� ���� �Բ� ���α׷� ����
// ö��, ���� ü���� 0�� �Ǹ� �ٽ� ĳ���� ���ú��� ����

// ĳ���� ����
// ö���� ü�� = ������, 3 ���ݷ� 1
// ������ ü�� = ����, 2 ���ݷ� 1.5
// ��1 = ������, 3 ���ݷ� 1
// ��2 = ������, 2 ���ݷ� 1.5
// ����= ��������, ���ݷ� 2
// ���� �� �ִ�ü�� ���������� �ִ�
// ü�� ǥ�� ��, �������� ���� ü�� 

// ���� �帧 : ���� ���� ���� ������ �������� ǥ��, ���� ���� �� ���� �� �̱�, ��, ��� ǥ��, ���� ü��, ���� �� ü�� ��� 

// �߰� ��� 
// �������� Ŭ���� �� ��� 2���� �� �ϳ� ���� ���� = 1, ������ = 2 �� ��������
// �����̻� ���, �Ǹ� -> ������, ���� -> 0.1 �Ѱ��Ӵ�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // �Լ� ����� ���� ���
#include <time.h> // ��ǻ�� ���� ������ ���� ���
// #include <locale.h>   // �ֿܼ� ��/�� ���� ���� (������� �ʿ�) -> ���� �ʿ伺 �ִ��� ��.

int main()
{
	// 'void' �� �Լ��� ���ƹ��͵� ��ȯ���� �ʴ´١��ų�, �����Ͱ� ���ƹ� �ڷ����̳� ���� �� �ִ١��� ���� ����ϴ� Ű�����Դϴ�.
	// ����
	int Characterchoice = 0;
	float player1Healthpoint = 3; // ö���� ü�� = ������, 3 ���ݷ� 1
	float player1Attack = 1;
	float player2Healthpoint = 2; // ������ ü�� = ����, 2 ���ݷ� 1.5
	float player2Attack = 1.5;
	float Enemy1Healthpoint = 3; // ��1 = ������, 3 ���ݷ� 1
	float Enemy1Attackt = 1;
	float Enemy2Healthpoint = 2; // ��2 = ����, 2 ���ݷ� 1.5
	float Enemy2Attack = 1.5;
	float BossHealthpoint = 4; // ����= ��������, ���ݷ� 2
	float BossAttack = 2;
	int playerchoice = 0; // �÷��̾� ���� ���� �� ���û���
	int computerchoice = 0; // ��ǻ�� ���� ���� �� ���û���
	char Life = '��';
	char Emptyheart = '��';




	// ���� ���� ����
	printf("���� ���� �� ���� ����!\n"); // ���� ���� �� ���� ����!
	printf("ĳ���͸� �����Ͻÿ�\n");



	while (1)
	{
		// ĳ���� ����
		printf("ö�� =1, ���� = 2�� �������� : \n");
		scanf("%d", &Characterchoice);
		
		if (Characterchoice == 1)
		{
			printf(" ����� ö���Դϴ�. ü�� ������ ���ݷ� 1.0\n\n");
			break;
		}
		else if (Characterchoice == 2)
		{
			printf(" ����� �����Դϴ�. ü�� ���� ���ݷ� 1.5\n\n");
			break;
		}
		else
		{
			printf(" 1 �Ǵ� 2 �� �Է����ּ���.\n\n");

		}
	}

	//���� ���� �� ���� �� ü�� ��� �ڵ�

	if (playerchoice <= 0 || playerchoice > 3)
	{
		printf("�߸� �Է��Ͽ����ϴ�.\n");
	}
	else if (playerchoice == computerchoice)
	{
		printf("�����ϴ�.\n");
	}
	else if ((playerchoice == 1 && computerchoice == 3) || (playerchoice == 2 && computerchoice == 1) || (playerchoice == 3 && computerchoice == 2))
	{
		printf("�¸��߽��ϴ�.\n");
		Enemy1Healthpoint--;
	}
	else
	{
		printf("������ �й��߽��ϴ�.\n");
		player1Healthpoint--;
	}

	// stage 1  ��1 ü�� ������ ���ݷ� 1.0
	printf("�������� 1 ����!\n");
	printf("�� ü�� ������ ���ݷ� 1.0\n");
	if (Characterchoice == 1)
	{
		printf(" ö�� ü�� ������ ���ݷ� 1.0\n");
	}
	else if (Characterchoice == 2)
	{
		printf(" ���� ü�� ���� ���ݷ� 1.5\n");
	}
	printf("����(1) ����(2) ��(3) �� �ش� ���ڸ� �Է��ϼ��� : "); // -> 1, 2, 3�� ������ ���� ���� ���� ���� ������ �ٲ��� ����. 
	scanf("%d", &playerchoice);

	srand(time(NULL)); // ���� ������ �ʱ�ȭ
	int radomchoice = rand() % 3 + 1; // 1~3 ������ ���� ���� (1 = ����, 2 = ����, 3 = ��)
	radomchoice == computerchoice;
	printf("���� ����: %d\n", radomchoice);


	if (player1Healthpoint == 0 || player2Healthpoint == 0) // �÷��̾� ü�� 0�̵Ǹ� ó������ ���� �ٽ� ����
	{
		printf("ü���� ���� ���������ϴ�. ");
		return 0;
	}
	else if (Enemy1Healthpoint == 0)
	{
		printf("�������� 1�� Ŭ�����Ͽ����ϴ�.\n ");

	}
	// stage 2  ��2 ü�� ���� ���ݷ� 1.5
	if (Enemy1Healthpoint == 0)
	{
		printf("�������� 2 ����!\n");
		printf("�� ü�� ���� ���ݷ� 1.5\n");
	}

	if (player1Healthpoint == 0 || player2Healthpoint == 0) // �÷��̾� ü�� 0�̵Ǹ� ó������ ���� �ٽ� ����
	{
		printf("ü���� ���� ���������ϴ�. ");
		return 0;
	}

	else if (Enemy1Healthpoint == 0 && Enemy2Healthpoint == 0)
	{
		printf("�������� 1�� Ŭ�����Ͽ����ϴ�.\n ");

	}
	// stage 3  ��1 ü�� �������� ���ݷ� 2.0
	if (Enemy1Healthpoint == 0 && Enemy2Healthpoint == 0) // �������� 1 2 ���������� ���������� �� ���� ���������� �̵�
	{
		printf("���� �������� ����!\n"); // 
		printf("���� ü�� ������ ���ݷ� 2.0\n");
	}

	if (player1Healthpoint == 0 || player2Healthpoint == 0) // �÷��̾� ü�� 0�̵Ǹ� ó������ ���� �ٽ� ����
	{
		printf("ü���� ���� ���������ϴ�. ");
		return 0;
	}
	else if (Enemy1Healthpoint == 0 && Enemy2Healthpoint == 0 && BossHealthpoint == 0)
	{
		printf("������ Ŭ�����Ͽ����ϴ�.\n ");
		printf("������ �Ϸ��Ͽ����ϴ�. �����մϴ�!!\n ");
		printf("ó������ ���ư��ϴ�.\n ");
		return 0;
	}
}
// ���� ���� �� �α׶���ũ Version 1. 0. 0. 10/23