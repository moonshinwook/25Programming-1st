// 2025-10-22
// ���� ���� ��
// �ǽ� ��ǥ : �ٸ� �̴� ���� ���� �����ϰ� �ڵ带 �ۼ��غ��� ��

#include <stdio.h>
#include <stdbool.h>

// (1)���� ���� �� ������ �ѱ۷� ǥ���غ�����
// - ����, ��ǻ��,  
// ����, ����, �� �߿��� �ϳ��� �������ּ���. 
// ��� : ��ǻ�Ͱ� ������ �´°� ���� ����� �޶�����. 

/*
*  ���α׷� ȥ�ڼ� �ۼ��� �� �����ϴ� ����
*  1. �ѱ۷� ���� � ���� ������ �� �ּ����� ǥ���غ�����.
*  2. �ѱ۷� ǥ���� ������ ��ǻ�Ϳ��� ��� ������� ���� �ۼ��� �غ�����.
*  2-1. Ư���� ����, ����� �����ͼ� ����Ѵ�, ������ ���� �κ�
*  2-2. ����� �ؼ� ����� �������Ѻ���
*/

/*
*  ������ �¸��ϸ� ������ ������ 1�� ����, ��ǻ�Ͱ� �¸��ϸ� ��ǻ���� ������ 1�� ������Ű����.
*  �ݺ��ؼ� ����ϰ� �ʹ�. ������ �¸��ϸ� ������ ������ 1�� ����, ��ǻ�Ͱ� �¸��ϸ� ��ǻ���� ������ 1�� ������Ű����.
*
*  ���װ� �ִ� �� ����. ��ǻ�Ͱ� ������ �´��� �˰� �ʹ�. <- �ݿ�. ��ǻ�Ϳ� �÷��̾��� �ൿ�� �߷��ϴ� �ڵ带 ��������.
*  Hint -> playerChoice, computerChoice�� ���̵��� �ؾ��Ѵ�.
*/

/*
*  ���� ���� levelup system
*/

/*
*  ���� ���߱� ����
*/

/*
*  ���������������� �ϼ��ϱ� ���� �ʿ��� ���� ����
*  1. ������ �Է� ����� ����.
*  2. ��ǻ�Ͱ� ������ ����� ����մϴ� -> ������ �ο�
*  3. ���ھ�. => �ݺ�. 3�� ���� ����ϸ� �¸��Ѵ�. -> ������ �ƴ� ��������� ?
*  4. ������ �ο�, 3������������ �������� 3���� �� ���� 
*  5. ĳ���� ���� 2����, ���� �ɷ� ������ ���� 
*  6. 
*  7. �������� 10���� BOSS ���� 
*  8. BOSS�� �̱�� ����� 2�� ����.
*  ������ ���� �۾� ����Ʈ.
*  -> ���� ������ �� �ִ� ����
*/

int main()
{
	// ���ǹ� ��� �׽�Ʈ 
	// ����Ŭ�� ����� ���� ����.
	bool value = 5 < 3; // ���̸� value, ���ڰ� 0�̸� ������ �����̴�, ���ڰ� 1�̸� ������ ���̴�. -> ���̸� ���� �����̸� ����x

	// if(); ����Ŭ���� ����������


	if (true) // ���̸� ���� �����̸� ����x, '==' �� ���� '!=' ���� �ʴ�
	{
		printf("������ ����Ǿ���!\n");//������ ����
	}


	printf("���� ���� �� ����!\n");

	// �÷��̾ ������ ����� ����
	// 1. ���� 2. ���� 3. �� (������ ���) 
	int playerChoice = 1; // �÷��̾�� ������ �����߽��ϴ�. 
	int computerChoice = 1; // ��ǻ�͵� ������ �����߽��ϴ�. 
	int playerScore = 0;
	int compueterScore = 0;
	// ���� -> �̰��, ����, ����.
	// ���� - ���� -> ��  "1" -> "3" 
	// ���� - ���� -> ���� "1" -> "1" 
	// ���� - ���� -> ���� "1" -> "2" 

	if (playerChoice == 1 && computerChoice == 3) // && AND����
	{
		// ������ ������ ������ 1�� ������Ű�� �� -> playerScore
		playerScore = playerScore + 1;
		printf("������ �¸��߽��ϴ�.\n");
	}
	else if (playerChoice == 1 && computerChoice == 1)
	{
		printf("������ �����ϴ�.\n");

	}
	else if (playerChoice == 1 && computerChoice == 2)
	{
		compueterScore = compueterScore + 1;
		printf("������ �й��߽��ϴ�.\n");
	}
	else
	{
		// computerChoice���� 0���� �۰ų� ���ų�, 3���� ū ���
		if (computerChoice <= 0 && computerChoice > 3)
			printf("���ܰ� �߻��߽��ϴ�\n");
	}

	// �÷��̾ ���� -> 
	if (playerChoice == 2 && computerChoice == 1) // && AND����
	{
		playerScore = playerScore + 1;
		printf("������ �¸��߽��ϴ�.\n");
	}
	else if (playerChoice == 2 && computerChoice == 2)
	{
		printf("������ �����ϴ�.\n");

	}
	else if (playerChoice == 2 && computerChoice == 3)
	{
		compueterScore = compueterScore + 1;
		printf("������ �й��߽��ϴ�.\n");
	}
	else
	{
		// computerChoice���� 0���� �۰ų� ���ų�, 3���� ū ���
		if (computerChoice <= 0 && computerChoice > 3)
			printf("���ܰ� �߻��߽��ϴ�\n");
	}

	// �÷��̾ �� -> 
	if (playerChoice == 3 && computerChoice == 2)
	{
		playerScore = playerScore + 1;
		printf("������ �¸��߽��ϴ�.\n");
	}
	else if (playerChoice == 3 && computerChoice == 3)
	{
		printf("������ �����ϴ�.\n");

	}
	else if (playerChoice == 3 && computerChoice == 1)
	{
		compueterScore = compueterScore + 1;
		printf("������ �й��߽��ϴ�.\n");
	}
	else
	{
		// computerChoice���� 0���� �۰ų� ���ų�, 3���� ū ���
		if (computerChoice <= 0 && computerChoice > 3)
			printf("���ܰ� �߻��߽��ϴ�\n");
	}

	//if ((playerChoice == 1 && computerChoice == 3) || (playerChoice == 2 && computerChoice == 1) || (playerChoice == 3 && computerChoice == 2))
	//{
	//	printf("playerPoint : %d", +1);
	//}

	// �÷��̾��� ���� ���

	const char* playerCharacter = "����";		// ���ڸ� ������ �� �ִ� ����, ������
	const char* computerCharacter = "��";		// 

	if (playerChoice == 1)
	{
		playerCharacter = "����";
	}
	else if (playerChoice == 2)
	{
		playerCharacter = "����";
	}
	else if (playerChoice == 3)
	{
		playerCharacter = "��";
	}

	if (computerCharacter == 1)
	{
		computerCharacter = "����";
	}
	else if (computerCharacter == 2)
	{
		computerCharacter = "����";
	}
	else if (computerCharacter == 3)
	{
		computerCharacter = "��";
	}

	printf("���� 1 = ����, ���� 2 = ����, ���� 3 = ��\n");
	if (playerChoice == 1)
		printf("�÷��̾��� ���� = %s, ��ǻ���� ���� : %s\n", playerCharacter, computerCharacter);
	if (playerChoice == 2)
		printf("�÷��̾��� ���� = %d, ��ǻ���� ���� : %d\n", playerCharacter, computerCharacter);
	if (playerChoice == 3)
		printf("�÷��̾��� ���� = %d, ��ǻ���� ���� : %d\n", playerCharacter, computerCharacter);

	// �÷��̾��� ���� vs ��ǻ���� ���� ��� 
	//printf("����� ���� : %d\n", playerScore);  ������ �ۼ��غ� ��
	//printf("��ǻ���� ���� : %d\n", compueterScore); ������ �ۼ��غ� ��
	printf("�÷��̾��� ���� : %d vs ��ǻ���� ���� : %d\n", playerScore, compueterScore);


}