
// �Լ� �����

// �̸��� ������ �ִ� Function - ���� �ð�
// �Լ��� �����ϱ�? ó�� ������ ��ġ�� � ������� ��ȯ�Ǵ� ���
// �Լ��� �� ����? � �� ���� ���ߴ��� ������� ����� �� �ֵ��� ��������. 

// ��ȯ�� �Լ� �̸� (�Ű� ����); Head <<
//{ body ���� }						<<

// 

// ���� �Լ�. 
// ���α׷��� ���۰� ���� ǥ���ϴ� ����� �ϰ� �ִ�. 

// �Լ��� ���� �����ϰ� - ������ �Լ��� ���
// ��ȯŸ�� + �Լ��̸� (�Ű� ����); - �۾��� ���ؼ��� �Լ��� �����ȴ�. 

// �Լ��� ǥ���ϴ� ��Ŀ��� 4���� ����
// ��ȯ�� x ���ڰ� x
// ��ȯ�� o ���ڰ� x
// ��ȯ�� x ���ڰ� o
// ��ȯ�� o ���ڰ� o
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Math.h" // ������� ��������


// Minus
// Multiply
// Divide


int main()
{
	int num1 = 6;
	int num2 = 0;

	Add(num1, num2); // statement ( ���'��') Add�Լ��� num1, num2�� ���ڷμ� �����϶�. 
	Add(3, 5);		 // Add�Լ���  3 -> num1, 5 -> num2 Add�Լ��� �����϶�

	Minus(num1, num2);

	Multiply(num1, num2);

	Divide(num1, num2);

	// �÷��̾ �� ���� ���� ���� �ش��ϴ� ���ڸ� ����ϰ� �ʹ�.
	int playerchoice = SelectPlayerBehavior(); // 1 ����, 2 ����, 3 ��
	printf("�÷��̾��� ���� �� : %d", playerchoice);
	// ĳ������ �ʱ� ���� ����
	Selectcharacter(10);

	// �Լ� �ȿ����� �ڵ尡 �� ������ �Ȱ� ������ main �ٸ� �ڵ�� ������ ��ġ�� �ʴ´�.

	// scanf �Է¹��� ���� ��Ģ�������� ó���ϴ� �ڵ� ���� �� �ִ�. 
	
	return 0; // int main�� �־��� ������ 0�� ���´�. ���ӿ��� ������ ����� �;��. return�� �ϵ��� ����� �ȴ�. � ���ڸ� �Է��ϸ� ���α׷��� �����ϰڴ�. 
}

// ĳ���͸� �����ؼ� ������ �й��Ѵٴ��� �ϴ� �Լ�
// Dice, STR, DEX, INT, LUK �й� 

/*
*  ��ȯ���� void �Լ��� �� ����ұ�? 
*  ��ȯ���� ������ �ڵ带 ������ �� �ִ°�? �ּ��� ������ �����ϸ�									-Value vs -Reference
*  �Լ� �ȿ����� �ڵ尡 ������ �ǰ� �����δ� ������ �ȵǴ� ����� �ʿ��ϴ�. (ex) UI ���� ������ �����ִ� ����� ������ ����� ������ �����Ű��? 
* 
*/

// ���� ����Ʈ�� �й��ؼ� STR, DEX, INT, LUK �� ����� �ǵ��� ��������
// startpoint ���� �Ѵ� ���� �����ؼ��� �ȵ˴ϴ�. 
// �й��� ������ main������ ���ɷ��� ��� �ؾ��ұ�? <���>
void Selectcharacter(int startpoint)
{
	printf("%d ���� ����Ʈ�� �й����ּ���\n");
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
	// ����, ����, ��, ���� ����

	int num = 0;
	scanf("%d", &num);

	if(num == 1)
	return 1; // ����
	else if(num == 2) 
	return 2; // ����
	else if(num == 3) 
	return 3; // ��
}

