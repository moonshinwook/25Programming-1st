#include "Math.h"

const static double PI; // 정적이다, 여러개의 함수가 있고, 공통으로 사용하는 변수를 선언하고 싶다. 
						// 모든 소스페이지에서 PI 전역변수를 사용할 가능성이 생긴다.
						// 
void Test()
{
	double test = PI;
	printf("테스트 파이 값 : %1f\n", PI);
}

// static 함수 안에 선언하면 어떤 일이 발생하나요?
// 스택 영역과 별개로 데이터가 저장이 됩니다.
// 프로그램이 시작할 때 데이터가 저장이 됩니다.
// 지역 변수에 static을 선언하는 이유는 무엇인가요> -> 함수 안에서만 정적으로 사용하겠다. (함수안에서 전역인 거처럼 사용한다. -> 위치(함수 밖, 함수 안)에 따라 국부적으로 사용)

void Test2()
{
	static int number = 1;
	int number2 = 1;
	number++; // number + number + 1;
	number2++;
}

void CalculateCircleArea()
{
	// const double pi = 3.14;	// 이 값은 변경되면 안되는 값이에요 
	double radius = 2;
	printf("반지름의 길이를 입력해주세요 : ");
	scanf("%1f", &radius);
	double circleArea = PI * radius * radius;
	printf("원의 넓이 : %lf\n", circleArea);
	// 원의 넓이가 2, 3, 4, 5.5 .....
}

void CalculateCircleDiameter() //double pi를 선언했을 때는 pi 변수에 대한 값을 만들 수 있으나 선언을 하지 않으면 pi자체만 사용 가능, 변경 불가
{

	//const double pi = 3.14;	// 이 값은 변경되면 안되는 값이에요 
	double radius = 2;
	printf("반지름의 길이를 입력해주세요 : ");
	scanf("%1f", &radius);
	double CircleDiameter = 2 * PI * radius;
	printf("원의 지름 : %lf", CircleDiameter);
}

