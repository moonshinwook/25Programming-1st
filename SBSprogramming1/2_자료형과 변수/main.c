/*
* ��¥	: 2025 - 10 - 16
* �н���ǥ : �ڷ����� ����
* �ǽ���ǥ : ���� ������ �м��ؼ� �ڷ����� �����Ѵ�.
*/

// �ڷ��� Data Type
// Data : ����, �׸�, ��ȣ ���ǵǾ� ���� ���� ������
// ��ǻ�Ϳ��� ����� ������ �ʹ�. 
// ����ų(����),	ų�� ���ھ� ����(�Ҽ����� ���� ���� = ����), ���� ����(�Ҽ����� �ִ� ���� = �Ҽ�)
// �̹��� 1920 x 1080, �Ҹ�(����)

// �ڷ���� Ư¡�� ���� ���¸� �з��� �ߴ�. Type 
// �ڷ��� : ����, ����, �Ǽ�, 

// �ڷ����� �̿��ϴ� ���
// (� Ÿ��) "�̸�" variable ����
// �Լ��� ����ϴ� ���
// int :������ ǥ���ϴ� Ÿ��
// flaot :�Ǽ�
// char :���� "H e l l o" 
// string ���ڿ�

#include <stdio.h>

int main()
{
	// ����ų ���� ȭ�鿡 ����ϰ� �ʹ�. 
	printf("����ų \n"); 
	// �������� ������� ���ھ ����ϰ� �ʹ�. 
	printf("10 vs 25\n");
	// è�Ǿ��� ������ �ִ� ������ ȭ�鿡 ����ϰ� �ʹ�. 
	int level = 18;

	int GarenfirstLevelHP = 690; 
	float GarengrowthHP = 98;
	int GarenfirstLevelMP = 0;
	float GarengrowthMP = 0;
	int Garenfirstatteck = 69;
	float Garengrowthatteck = 4;
	float Garrenfirstatteckspeed = 0.625;
	float Garrengrowthatteckspeed = 3.65;
	int GarenfirstHealthrecoveryper5seconds = 5;
	float GarenfirstgrowthHealthrecoveryper5seconds = 0;




	// %d, %s 

	printf(" ������ 1�� ���� ���� \n");
	printf(" AD : 10 \n ");
	printf(" ü�� : %f \n", GarenfirstLevelHP + (level - 1) * GarengrowthHP);
	printf(" ���� ü�� : %f \n", GarenfirstLevelHP + (level - 1) * GarengrowthHP);
	printf(" ���� ���� : %f \n ", GarenfirstLevelMP + (level - 1) * GarengrowthMP);
	printf(" ���ݷ� : %f \n", Garenfirstatteck + (level - 1) * Garengrowthatteck);		//69 + 4(���緹�� - 1)
	printf(" ���� �ӵ� : %f \n", Garrenfirstatteckspeed +(level - 1) * Garrengrowthatteckspeed / 100);
	printf(" 5�ʴ� ü��ȸ�� : %f \n", GarenfirstHealthrecoveryper5seconds + (level - 1) * GarenfirstgrowthHealthrecoveryper5seconds);
	printf(" 5�ʴ� ����ȸ�� : 0 \n");
	printf(" ���� : 38 (+4) \n");
	printf(" ���� ���׷� : 32 (+1) \n");
	printf(" �̵��ӵ� : 340 \n");
	printf(" �����Ÿ� : 175 \n"); 

	// �� ������ ��ǻ�Ͱ� ���� ���ϴ� ��������� ������ �߳���? 
	// ���� vs ���� �� �ؾ��Ѵ�. 

	// ����1. 5������ ���� ������ ������ ��� �ǳ���? 

	// ����2. �ٸ� è�Ǿ����ε� ���� ������� ������ ǥ���غ�����. 


	// ����3. �м��غ��� ���� ������ ������ �ϳ� �����ɴϴ�. 
	// ���� ǥ�� 

	// �ǽ�. ���׿��극���� ����. 

	// ���� �Լ��� �������� ����ϴ� �ϳ��� ���� 
	// ���ӿ��� ����� �� �ִ� ���� ��� 
	// �ޱ׸����� �� ������ �(�ܼ� ������ �)

	// step 1~10
	// step1 ĳ������ �߻� ��ġ ���� (0,0)���� ���� 
	// step2 ��ġ���� ��ȭ�� a,b �������� ��ȭ�� ���� �޶���
	// step3 a, b�� ���� ���������� ǥ���Ͽ� �ܼ�ȭ
	// 
	// Result
	// printf
	// 
	

	// ����ġ : 
	// �̴Ͼ� óġ : ����ġ ȹ�� ����
	// ����		:	������ �������� ����ġ�� ���� ȹ����Ѿ� �Ѵ�. 


	// �̴Ͼ��� ����ġ�� �ð��� �������� ���� �ְ� �ұ�? 
	// -> è�Ǿ��� �׿��µ��� ����ġ�� �ش�. ������ ����. 

	// ����ġ�� ������ ũ�� ȹ���ؾ� �ϸ� ����ġ �䱸���� ũ�� �ϰ� ����.
	// � ������� ũ�� �ұ��? �������� ������ ����� ���� ���������� �ٲ� �� ������ MagicNumber�� ��쿡�� �밡�� �ʿ�.
	// 1���� 10 2���� 30 3���� 60 4���� MagicNumber(������ ������ġ��)
	// step 1 ~ 10

	// ������ �ǵ�� 10������ �뷱���� ���� Ȥ�� <- 10���� ��� ó������..
	// 10���� Debug -> ������ �ǵ��� ����� �޶��°�? 

	//����뿡�� �ߴ����� �ſ� �߿�!! �ߴ����� ���� ����(������ ����)

}