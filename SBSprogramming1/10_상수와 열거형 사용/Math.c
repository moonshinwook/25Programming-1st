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
	int number2 = 1;
	number++; // number + number + 1;
	number2++;
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

