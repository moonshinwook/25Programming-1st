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
// ö���� ü�� = ������, 30 ���ݷ� 10
// ������ ü�� = ����, 20 ���ݷ� 15
// ��1 = ������, 30 ���ݷ� 10
// ��2 = ������, 20 ���ݷ� 15
// ����= ��������, 40 ���ݷ� 20
// ���� �� �ִ�ü�� ���������� �ִ�
// ü�� ǥ�� ��, �������� ���� ü�� ��, �� ü�� �� 

// ���� �帧 : ���� ���� ���� ������ �������� ǥ��, ���� ���� �� ���� �� �̱�, ��, ��� ǥ��, ���� ü��, ���� �� ü�� ��� 

// �߰� ��� 
// �������� Ŭ���� �� ��� 2���� �� �ϳ� ���� ���� = 1, ������ = 2 �� ��������
// �����̻� ���, �Ǹ� -> ������, ���� -> 0.1 ���� 1���� ������ ��
// �������� Ŭ���� �� ü�� Ǯȸ��, ������ ����â �����(������ ���ݷ� ���� or ���� ����)    

// ü�¿� ���� ǥ���� ������ ��ü�Ͽ� ǥ�� ex) healthpoint == 30 -> 30�� ������ ��ü

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // �Լ� ����� ���� ���
#include <time.h> // ��ǻ�� ���� ������ ���� ���
#include <locale.h>   // �ֿܼ� ��/�� ���� ���� (������� �ʿ�) -> ���� �ʿ伺 �ִ��� ��. -> ANSI(CP949)�� ������ϹǷ� �п������� ���ڵ� ��İ� ���� �ʾ� 
// �ٸ� ������� ����� ���� -> if �ݺ������� ���� ���� �� ���ڷ� ��Ʈ ǥ�� 
// �����ڵ� ���� �ʿ��Ͽ� ����

int main()
{
	// 'void' �� �Լ��� ���ƹ��͵� ��ȯ���� �ʴ´١��ų�, �����Ͱ� ���ƹ� �ڷ����̳� ���� �� �ִ١��� ���� ����ϴ� Ű�����Դϴ�.
	// ����
		// �ý����� �⺻ �����Ϸ� ����
	// setlocale(LC_ALL, ""); ��Ʈ ���� ���� �ڵ忴��

	int Characterchoice = 0;
	int player1Healthpoint = 30; // ö���� ü�� = ������, 3 ���ݷ� 1
	int player1Attack = 10;
	int player2Healthpoint = 20; // ������ ü�� = ����, 2 ���ݷ� 1.5
	int player2Attack = 15;
	int Enemy1Healthpoint = 30; // ��1 = ������, 3 ���ݷ� 1
	int Enemy1Attack = 10;
	int Enemy2Healthpoint = 20; // ��2 = ����, 2 ���ݷ� 1.5
	int Enemy2Attack = 10;
	int BossHealthpoint = 40; // ����= ��������, ���ݷ� 2
	int BossAttack = 20;

	char Selectreward = 0; //�������� Ŭ���� ���� ���û���
	int Attackboost = 4; // �������� Ŭ���� ���� 


	int playerchoice = 0; // �÷��̾� ���� ���� �� ���û���
	int computerchoice = 0; // �� ���� ���� �� ���û���


	//char Life = '��';
	//char Emptyheart = '��';	// ���� �����ڵ�� �������� ���� �����̶� ����
	//char Halfheart = '��';



	// ���� ���� ����
	// if(player1Healthpoint == 0 || player2Healthpoint == 0) �ý��� ������� �ٷ� ����� ���ư����ϴ� �ý��� �ʿ�
	printf("���� ���� �� ���� ����!\n"); // ���� ���� �� ���� ����!
	printf("ĳ���͸� �����Ͻÿ�\n");

	srand(time(NULL)); // ���� ������ �ʱ�ȭ srand(time(NULL));�� �� �Ͽ��� ȣ���ϸ� ���� �� �ȿ� �Է��ϸ� ���� ������ ���� �� �ֽ��ϴ�. ���� ���� ���� �� ���� ȣ��
	while (1) // ��ü while�� ���� ����
	{
		// �ٽ� ���α׷��� ������ �� �� �ʱ�ȭ
		player1Healthpoint = 30; // ö���� ü�� = ������, 30 ���ݷ� 10
		player1Attack = 10;
		player2Healthpoint = 20; // ������ ü�� = ����, 20 ���ݷ� 15
		player2Attack = 15;
		Enemy1Healthpoint = 30; // ��1 = ������, 30 ���ݷ� 10
		Enemy1Attack = 10;
		Enemy2Healthpoint = 20; // ��2 = ����, 20 ���ݷ� 15
		Enemy2Attack = 15;
		BossHealthpoint = 40; // ����= ��������, 40 ���ݷ� 20
		BossAttack = 20;

		// ĳ���� ����
		printf("ö�� =1, ���� = 2�� �������� : \n");
		scanf("%d", &Characterchoice);

		if (Characterchoice == 1)
		{
			printf(" ����� ö���Դϴ�. ü�� ������(30) ���ݷ� 10\n\n");
			break;
		}
		else if (Characterchoice == 2)
		{
			printf(" ����� �����Դϴ�. ü�� ����(20) ���ݷ� 15\n\n");
			break;
		}
		else
		{
			printf(" 1 �Ǵ� 2 �� �Է����ּ���.\n\n");
		}
	}

	// stage 1  ��1 ü�� ������ ���ݷ� 10
	printf("�������� 1 ����!\n");
	printf("�� ü�� ������(30) ���ݷ� 10\n");
	if (Characterchoice == 1)
	{
		printf("ö�� ü�� ������ ���ݷ� 10\n\n");
	}
	else if (Characterchoice == 2)
	{
		printf("���� ü�� ����(20) ���ݷ� 15\n\n");
	}
	// �ݺ����� �ʿ����� ������? -> while�ݺ��� ���� 

	while (1)
	{

		printf("����(1) ����(2) ��(3) �� �ش� ���ڸ� �Է��ϼ��� : "); // -> 1, 2, 3�� ������ ���� ���� ���� ���� ������ �ٲ��� ����. 
		scanf("%d", &playerchoice);


		
		int computerchoice = rand() % 3 + 1; // 1~3 ������ ���� ���� (1 = ����, 2 = ����, 3 = ��)
		printf("���� ����: %d\n\n", computerchoice); // ������ computerchoice�� �Ͽ��� �� �����ǵ��� �ʰ� ����� ��!!

		// ���� ���ñ����� ����� �Ǵµ� ���� ���� ��°� ü�� ��� �� ����� ������ �ʴ� ��Ȳ 

			//���� ���� �� ���� �� ü�� ��� �ڵ�
		// ���� = 1 ���� = 2 �� = 3
		if (playerchoice <= 0 || playerchoice > 3)
		{
			printf("�߸� �Է��Ͽ����ϴ�.\n\n");
		}
		else if (playerchoice == computerchoice)
		{
			printf("�����ϴ�.\n\n");
		}
		else if ((playerchoice == 1 && computerchoice == 3) || (playerchoice == 2 && computerchoice == 1) || (playerchoice == 3 && computerchoice == 2))
		{
			if (Characterchoice == 1) {
				printf("�¸��߽��ϴ�.\n\n");
				Enemy1Healthpoint = Enemy1Healthpoint - player1Attack;
			}
			else if (Characterchoice == 2) {
				printf("�¸��߽��ϴ�.\n\n");
				Enemy1Healthpoint = Enemy1Healthpoint - player2Attack;
			}
		}
		else
		{
			printf("�й��߽��ϴ�.\n\n");
			player1Healthpoint = player1Healthpoint - Enemy1Attack; 
			player2Healthpoint = player2Healthpoint - Enemy1Attack;
		}

		// ü�� ��� �ڵ�
		// �÷��̾�1 ü�� ǥ�� -> ���� �Ҽ������� �غ��� 
		if (Characterchoice == 1 && player1Healthpoint == 30) { //  ü�� 30
			printf("ö�� ü�� ������\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint > 20 && player1Healthpoint < 30) { //  ü�� 2x
			printf("ö�� ü�� ������\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint == 20) { //  ü�� 20
			printf("ö�� ü�� ������\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint > 10 && player1Healthpoint < 20) { //  ü�� x
			printf("ö�� ü�� ���Ģ�\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint == 10) { // ü�� 10
			printf("ö�� ü�� ������\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint > 0 && player1Healthpoint < 10) { //  x
			printf("ö�� ü�� �Ģ���\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint <= 0) {// ü�� 0 // -> �� �� ���� ��ȯ���� ������? -> else if���� else�� ��ħ -> else if�� �ٽ�
			printf("ö�� ü�� ������\n");

			// �÷��̾� ü���� 0�� �� �ٽ� ������������ �̵�
			if (player1Healthpoint == 0) // �÷��̾� ü�� 0�̵Ǹ� ó������ ���� �ٽ� ����
			{
				printf("ü���� ���� ���������ϴ�. ");
				printf("�������� 1 ����!! �� . ��\n ");
				system("pause");
				return 0;
			}
		}
		// �÷��̾�2 ü�� ǥ��
		if (Characterchoice == 2 && player2Healthpoint == 20) { // ü��20
			printf("���� ü�� ����\n");
		}
		else if (Characterchoice == 2 && player2Healthpoint > 10 && player2Healthpoint < 20) { //  ü�� 1x
			printf("���� ü�� ����\n");
		}
		else if (Characterchoice == 2 && player2Healthpoint == 10) { // ü�� 10
			printf("���� ü�� ����\n");
		}
		else if (Characterchoice == 2 && player2Healthpoint > 0 && player2Healthpoint < 10) { //  ü�� x
			printf("���� ü�� �Ģ�\n");
		}
		else if (Characterchoice == 2 && player2Healthpoint <= 0) { // ü�� 0 
			printf("���� ü�� ����\n");
			// �÷��̾� ü���� 0�� �� �ٽ� ������������ �̵�
			if (player2Healthpoint == 0) // �÷��̾� ü�� 0�̵Ǹ� ó������ ���� �ٽ� ����
			{
				printf("ü���� ���� ���������ϴ�. ");
				printf("�������� 1 ����!! �� . ��\n ");
				system("pause");
				return 0;
			}
		}
		// ��1 ü�� ǥ��
		if (Enemy1Healthpoint == 30) { //  ü�� 30
			printf("�� ü�� ������\n");
		}
		else if (Enemy1Healthpoint > 20 && Enemy1Healthpoint < 30) { //  ü�� 2x
			printf("�� ü�� ������\n");
		}
		else if (Enemy1Healthpoint == 20) { //  ü�� 20
			printf("�� ü�� ������\n");
		}
		else if (Enemy1Healthpoint > 10 && Enemy1Healthpoint < 20) { //  ü�� 1x
			printf("�� ü�� ���Ģ�\n");
		}
		else if (Enemy1Healthpoint == 10) { // ü�� 10
			printf("�� ü�� ������\n");
		}
		else if (Enemy1Healthpoint > 0 && Enemy1Healthpoint < 10) { //  ü�� x
			printf("�� ü�� �Ģ���\n");	
		}
		else if (Enemy1Healthpoint <= 0) { // ü�� 0 
			printf("�� ü�� ������\n");
		}

		// Ŭ���� ����
		if (Enemy1Healthpoint == 0)
		{
			printf("�������� 1�� Ŭ�����Ͽ����ϴ�.\n ");
			printf("Ŭ���� ���� \n");
			printf("ü���� ���� ȸ���մϴ�.\n\n");
			printf("a. ���ݷ� ���� + 0.4  b. ������ �Ǹ���� \n");
			printf("Ŭ���� ������ �����ϼ���(a �Ǵ� b �Է�) : \n");
			scanf("%c", &Selectreward);
		}

		if (Enemy1Healthpoint == 0 && Characterchoice == 1 && Selectreward == 'a') //��1 ü���� 0�̸� ��������2 ����, 97 = a
		{
			player1Healthpoint = 30;		// ������ ü�� ȸ���� �ʿ�.
			printf("ö���� ü�� ������ ���ݷ� : %d \n", player1Attack + Attackboost);
		}
		else if (Enemy1Healthpoint == 0 && Characterchoice == 2 && Selectreward == 'a') //��1 ü���� 0�̸� ��������2 ����
		{
			player2Healthpoint = 20;		// ������ ü�� ȸ���� �ʿ�.
			printf("������ ü�� ���� ���ݷ� : %d \n", player2Attack + Attackboost);
		}
		// �Ǹ���㿡 ���� ������ �߰� �ο���Ȳ �ʿ�.


		// ü�� ��� �� Life�� ���;��Ѵ�. 
		// o ���� ������� ����� �ȉ�!-> ���� ���ε� �����ϴٰ� �ƴ� �й��߽��ϴٰ� ����. -> rand �������� computerchoice�� �ٲ��� �ذ�!

		printf("\n");
		// stage 2  ��2 ü�� ���� ���ݷ� 15 
		if (Enemy1Healthpoint == 0 && Enemy2Healthpoint == 20) //��1 ü���� 0�̸� ��������2 ����
		{
			printf("�������� 2 ����!\n");
			printf("�� ü�� ���� ���ݷ� 1.5\n");
		}

		// ���� = 1 ���� = 2 �� = 3
		if (playerchoice <= 0 || playerchoice > 3)
		{
			printf("�߸� �Է��Ͽ����ϴ�.\n\n");
		}
		else if (playerchoice == computerchoice)
		{
			printf("�����ϴ�.\n\n");
		}
		else if ((playerchoice == 1 && computerchoice == 3) || (playerchoice == 2 && computerchoice == 1) || (playerchoice == 3 && computerchoice == 2))
		{
			if (Characterchoice == 1) {
				printf("�¸��߽��ϴ�.\n\n");
				Enemy1Healthpoint = Enemy2Healthpoint - player1Attack;
			}
			else if (Characterchoice == 2) {
				printf("�¸��߽��ϴ�.\n\n");
				Enemy1Healthpoint = Enemy2Healthpoint - player2Attack;
			}
		}
		else
		{
			printf("�й��߽��ϴ�.\n\n");
			player1Healthpoint = player1Healthpoint - Enemy2Attack; // -> �÷��̾� ü�� ����� �ȵǴ� ���� �߻�!
			player2Healthpoint = player2Healthpoint - Enemy2Attack;
		}
		// �÷��̾�1 ü�� ǥ��
		if (Characterchoice == 1 && player1Healthpoint == 30 && Enemy1Healthpoint == 0) { //  ü�� 30
			printf("ö�� ü�� ������\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint > 20 && player1Healthpoint < 30 && Enemy1Healthpoint == 0) { //  ü�� 2x
			printf("ö�� ü�� ������\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint == 20 && Enemy1Healthpoint == 0) { //  ü�� 20
			printf("ö�� ü�� ������\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint > 10 && player1Healthpoint < 20 && Enemy1Healthpoint == 0) { //  ü�� 1x
			printf("ö�� ü�� ���Ģ�\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint == 10 && Enemy1Healthpoint == 0) { // ü�� 10
			printf("ö�� ü�� ������\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint > 0 && player1Healthpoint < 10 && Enemy1Healthpoint == 0) { //  ü�� 1x
			printf("ö�� ü�� �Ģ���\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint == 0 && Enemy1Healthpoint == 0) { // ü�� 0 
			printf("ö�� ü�� ������\n");
		}
		// �÷��̾�2 ü�� ǥ��
		if (Characterchoice == 2 && player2Healthpoint == 20 && Enemy1Healthpoint == 0) { // ü�� 20
			printf("���� ü�� ����\n");
		}
		else if (Characterchoice == 2 && player2Healthpoint > 10 && player2Healthpoint < 20 && Enemy1Healthpoint == 0) { //  ü�� 1x
			printf("���� ü�� ����\n");
		}
		else if (Characterchoice == 2 && player2Healthpoint == 10 && Enemy1Healthpoint == 0) { // ü�� 10
			printf("���� ü�� ����\n");
		}
		else if (Characterchoice == 2 && player2Healthpoint > 0 && player2Healthpoint < 10 && Enemy1Healthpoint == 0) { //  ü�� 1x
			printf("���� ü�� �Ģ�\n");
		}
		else if (Characterchoice == 2 && player2Healthpoint == 0 && Enemy1Healthpoint == 0) { // ü�� 0 
			printf("���� ü�� ����\n");
		}
		// ��2 ü�� ǥ��
		if (Enemy1Healthpoint == 0 && Enemy2Healthpoint == 20) { // ü�� 20
			printf("�� ü�� ����\n");
		}
		else if (Enemy1Healthpoint == 0 && Enemy2Healthpoint > 10 && Enemy2Healthpoint < 20) { //  ü�� 1x
			printf("�� ü�� ����\n");
		}
		else if (Enemy1Healthpoint == 0 && Enemy2Healthpoint == 10) { // ü�� 10
			printf("�� ü�� ����\n");
		}
		else if (Enemy1Healthpoint == 0 && Enemy2Healthpoint > 0 && Enemy2Healthpoint < 10) { //  ü�� 1x
			printf("�� ü�� �Ģ�\n");
		}
		else if (Enemy1Healthpoint == 0 && Enemy2Healthpoint == 0) { // ü�� 0 
			printf("�� ü�� ����\n");
		}

		if (player1Healthpoint <= 0 || player2Healthpoint <= 0 && Enemy1Healthpoint <= 0) // �÷��̾� ü�� 0�̵Ǹ� ó������ ���� �ٽ� ����
		{
			printf("ü���� ���� ���������ϴ�. ");
			printf("�������� 2 ����!! �� . ��\n ");
			system("pause");
			return 0;
		}


		else if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0)
			// Ŭ���� ����
			if (Enemy1Healthpoint <= 0)
			{
				printf("�������� 2�� Ŭ�����Ͽ����ϴ�.\n ");
				printf("Ŭ���� ���� \n");
				printf("ü���� ���� ȸ���մϴ�.\n\n");
				printf("a. ���ݷ� ���� + 0.4   b. ������ �Ǹ���� \n");
				printf("Ŭ���� ������ �����ϼ���(1 �Ǵ� 2 �Է�) : \n");
				scanf("%c", &Selectreward);
			}

		if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0 && Characterchoice == 1) //��1 ü���� 0�̸� ��������2 ����
		{
			player1Healthpoint = 30;		// ������ ü�� ȸ���� �ʿ�.
			printf("ö���� ü�� ������ ���ݷ� : %d \n", player1Attack + Attackboost);
		}
		else if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0 && Characterchoice == 2) //��1 ü���� 0�̸� ��������2 ����
		{
			player2Healthpoint = 20;		// ������ ü�� ȸ���� �ʿ�.
			printf("������ ü�� ���� ���ݷ� : %d \n", player2Attack + Attackboost);
		}


		// stage 3  ��1 ü�� �������� ���ݷ� 2.0
		if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0 && BossHealthpoint == 40) // �������� 1 2 ���������� ���������� �� ���� ���������� �̵�
		{
			printf("���� �������� ����!\n"); // 
			printf("���� ü�� �������� ���ݷ� 2.0\n");
		}
		// �÷��̾�1 ü�� ǥ��
		if (Characterchoice == 1 && player1Healthpoint <= 30 && Enemy1Healthpoint <= 0 && Enemy2Healthpoint == 0) { //  ü�� 30
			printf("ö�� ü�� ������\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint > 20 && player1Healthpoint < 30 && Enemy1Healthpoint == 0 && Enemy2Healthpoint == 0) { //  ü�� 20x
			printf("ö�� ü�� ������\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint == 20 && Enemy1Healthpoint <= 0 && Enemy2Healthpoint == 0) { //  ü�� 20
			printf("ö�� ü�� ������\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint > 10 && player1Healthpoint < 20 && Enemy1Healthpoint == 0 && Enemy2Healthpoint == 0) { //  ü�� 1x
			printf("ö�� ü�� ���Ģ�\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint == 10 && Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0) { // ü�� 10
			printf("ö�� ü�� ������\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint > 0 && player1Healthpoint < 10 && Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0) { //  ü�� x
			printf("ö�� ü�� �Ģ���\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint == 0 && Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0) { // ü�� 0 
			printf("ö�� ü�� ������\n");
		}
		// �÷��̾�2 ü�� ǥ��
		if (Characterchoice == 2 && player2Healthpoint == 20 && Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0) { // ü�� 20
			printf("���� ü�� ����\n");
		}
		else if (Characterchoice == 2 && player2Healthpoint > 10 && player2Healthpoint < 20 && Enemy1Healthpoint == 0 && Enemy2Healthpoint == 0) { //  ü�� 1x
			printf("���� ü�� ����\n");
		}
		else if (Characterchoice == 2 && player2Healthpoint == 10 && Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0) { // ü�� 1
			printf("���� ü�� ����\n");
		}
		else if (Characterchoice == 2 && player2Healthpoint > 0 && player2Healthpoint < 10 && Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0) { //  ü�� x
			printf("���� ü�� �Ģ�\n");
		}
		else if (Characterchoice == 2 && player2Healthpoint == 0 && Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0) { // ü�� 0 
			printf("���� ü�� ����\n");
		}
		// ���� ü�� ǥ��
		if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0 && BossHealthpoint == 40) {// ü�� 40
			printf("��������\n");
		}
		else if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0 && BossHealthpoint > 30 && BossHealthpoint < 40) { //  ü�� 3x
			printf("ü�� ��������\n");
		}
		else if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0 && BossHealthpoint == 30) { //  ü�� 30
			printf("ü�� ��������\n");
		}
		else if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0 && BossHealthpoint > 20 && BossHealthpoint < 30) { //  ü�� 2x
			printf("ü�� �����Ģ�\n");
		}
		else if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0 && BossHealthpoint == 20) { //  ü�� 20
			printf("ü�� ��������\n");
		}
		else if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0 && BossHealthpoint > 10 && BossHealthpoint < 20) { //  ü�� 1x
			printf("ü�� ���Ģ���\n");
		}
		else if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0 && BossHealthpoint == 10) { // ü�� 10
			printf("ü�� ��������\n");
		}
		else if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0 && BossHealthpoint == 10 && BossHealthpoint > 0) { //  ü�� x
			printf("ü�� �Ģ�����\n");
		}
		else if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0 && BossHealthpoint == 0) { // ü�� 0 
			printf("ü�� ��������\n");
		}
		if (player1Healthpoint <= 0 || player2Healthpoint <= 0 && Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0) // �÷��̾� ü�� 0�̵Ǹ� ó������ ���� �ٽ� ����
		{
			printf("ü���� ���� ���������ϴ�. ");
			printf("���� �������� ����!! �� . ��\n ");
			return 0;
		}
		else if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0 && BossHealthpoint <= 0)
		{
			printf("������ Ŭ�����Ͽ����ϴ�.\n ");
			printf("������ �Ϸ��Ͽ����ϴ�. �����մϴ�!!\n ");
			printf("ó�� �������� ���ư��ϴ�.\n ");
			system("pause");
			return 0;
		}
	}
}








// ���� ���� �� �α׶���ũ Version 1. 0. 0. 10/23
// ���� ���� �� �α׶���ũ Version 1. 0. 1. 10/24 -> �ݺ��� �߰�, ���� ���� �� ������ ���� ���� ��ġ ����, rand�Լ� ������ computerchoice�� ����, while�� �ȿ� �������� 3�� ����.
// ���� ���� �� �α׶���ũ Version 1. 0. 2. 10/26 -> ü�� ǥ�� ���ǹ� �߰�, ���� ���� �� ���� �ڵ� ��ġ ����, ������� ���Ͽ� �������� 1 ���� ����� 2, ���� �������� �ѹ��� ����
																				  // -> �÷��̾� ü�� ����� ���� int�� ���� �ο�
