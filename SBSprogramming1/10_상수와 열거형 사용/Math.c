#include "Math.h"

const static double PI; // �����̴�, �������� �Լ��� �ְ�, �������� ����ϴ� ������ �����ϰ� �ʹ�. 
						// ��� �ҽ����������� PI ���������� ����� ���ɼ��� �����.
						// 
void Test()
{
	double test = PI;
	printf("�׽�Ʈ ���� �� : %1f\n", PI);
}

// static �Լ� �ȿ� �����ϸ� � ���� �߻��ϳ���?
// ���� ������ ������ �����Ͱ� ������ �˴ϴ�.
// ���α׷��� ������ �� �����Ͱ� ������ �˴ϴ�.
// ���� ������ static�� �����ϴ� ������ �����ΰ���> -> �Լ� �ȿ����� �������� ����ϰڴ�. (�Լ��ȿ��� ������ ��ó�� ����Ѵ�. -> ��ġ(�Լ� ��, �Լ� ��)�� ���� ���������� ���)

void Test2()
{
	static int number = 1;
	int result = 0;
	for (int i = 0; i < 10; i++)
	{
		number += i;		//number = number + i;�� ����
	}
	result = number;
}

void CalculateCircleArea()
{
	// const double pi = 3.14;	// �� ���� ����Ǹ� �ȵǴ� ���̿��� 
	double radius = 2;
	printf("�������� ���̸� �Է����ּ��� : ");
	scanf("%1f", &radius);
	double circleArea = PI * radius * radius;
	printf("���� ���� : %lf\n", circleArea);
	// ���� ���̰� 2, 3, 4, 5.5 .....
}

void CalculateCircleDiameter() //double pi�� �������� ���� pi ������ ���� ���� ���� �� ������ ������ ���� ������ pi��ü�� ��� ����, ���� �Ұ�
{

	//const double pi = 3.14;	// �� ���� ����Ǹ� �ȵǴ� ���̿��� 
	double radius = 2;
	printf("�������� ���̸� �Է����ּ��� : ");
	scanf("%1f", &radius);
	double CircleDiameter = 2 * PI * radius;
	printf("���� ���� : %lf", CircleDiameter);
}

