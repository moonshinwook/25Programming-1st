#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 1. 포인터 복습
// int* numPtr = &a;	포인터 선언 방식 자료형(*), Ptr 구별을 위해, &(주소 연산자) 
// *number 주소에 저장된 값을 역참조. 

void Test1(int* xPtr, int* yPtr, int amountX, int amountY);
void Test2();
void inventorystatus();
void AddInventoryDate(int inventoryCount[], int index, int amount);

int main()
{
	//int a = 10;
	//scanf("%d", &a); // 정수로 선언된 a변수의 주소를 넘겨줘라.
	//printf("a의 값은 : %d\n", a);

	printf("Test1 예제 코드 구현\n");
	int playerX = 0;
	int playerY = 0;	
	int* playerXPtr = &playerX;
	int* playerYPtr = &playerY;
	Test1(playerXPtr, playerYPtr, 2, 5); 
	printf("playerX 값 : %d , playerY 값 : %d ", playerX, playerY);

	// 상수 지시 포인터가 왜 문법적으로 존재하는가?
	const double pi = 3.14;
	double* piPtr = &pi; // const 지정 시 *piPtr값 변환x
	(*piPtr) = (*piPtr) + 2; //pi 안에 들어있는 주소 
	printf("파이의 값 : %lf\n", pi);

	// 예제2. const int*로 선언된 포인터 변수는 그 값을 변경하지 못한다. 
	int boxX = 10;
	const int* boxXPtr = &boxX; // l-value가 const 개체를 지정합니다. 
	//(*boxXPtr) = (*boxXPtr) + 2; // 포인터에 저장되어 있는 값을 수정하지마세요. 상수 지시 포인터 const pointer

	// 예제3. 상수 포인터. 포인터(주소) 바뀌지 않는다.
	int box2 = 5;
	//const int* const boxXPtr = &box2; // -> 주소가 바뀌어버림
	printf("boxXptr가 가리키고 있는 값 : %d \n", *boxXPtr);

	// 예제4. 함수에 상수 포인터 / 상수 지시 포인터를 직접 사용해보기
	// 배열을 하나 선언 

	// inventory[0] , [1], [2]
	int inventory[3] = { 100, 10, 5 }; // 동전의 수, 레드 포션의 갯수, 약초의 수
	int inventory2[3] = { 100, 10, 5 };
	
	// 인벤토리의 배열 유저들의 배열 정보를 받는 함수? -> 아 게임에 참여하고 있는 모든 유저의 데이터를 출력하는 어떤 것...
	
	const char* inventoryText[3] = { "동전", "레드 포션", "약초" }; // 플레이어1, 2 같이 사용

	inventory[0] += 100;
	inventorystatus(inventory, inventoryText);

	//실습 예제1 
	// inventorystatus inventory. player1 인벤토리, player2인벤토리
	// player2가 현재 가지고 있는 인벤토리 데이터를 출력할 수 있게 만들어 보세요.
	AddInventoryDate(inventory2, 0, 40); // 첫번째 배열이니 0, 몇개를 증가시킬 것인가 40
	inventorystatus(inventory2, inventoryText);


	// 실습 예제2
	// 플레이어의 소유한 인벤토리를 변경시키는 함수를 만들어보세요.



	//for (int i = 0; i < 3; i++)
	//{
	//	printf("%s : %d개", inventoryText[i], inventory[i]);
	//}
	//printf("\n");

	//inventory[0] = 100;
	//inventory[0] = 10;
	//inventory[0] = 5;

	// 출력 -> 동전, 레드 포션, 약초

	int playerWallet = 100;
	printf("플레이어의 현재 소유 금액 : %d\n", playerWallet);
	Test2(&playerWallet);

	

	// 그래서 포인터를 playerWallet
}

// Test1함수를 보고 이 함수가 어떤 목적으로 사용이 될 건지 분석
// 첫번째 요소 : 주소를 전달받음 : 주소를 이용해서 무엇을 할 것인가? 정수형 주소를 - 이름이 x
// 주소에 저장되어 있는 값을 변경해서 사용하겠다. 5 -> amountX 더해서 이 더 한값으로 바꾸겠다. 

void Test1(int* xPtr, int* yPtr, int amountX, int amountY) // int x, int y로 실행 시 main에서 나온 0값이 나옴
{
	//int x = // main전달받은 playerX
	//int y = // main전달받은 playerY
	*xPtr = (*xPtr) + amountX;
	*yPtr = (*yPtr) + amountY;


}
void Test2(const int* playerWallet)
{
	// 플레이어가 가지고 있는 돈을 출력해줘. 

	//int a = 10;

	//playerWallet = &a;
	//playerWallet = *playerWallet + 1; // 돈버그 발생
	printf("플레이어의 현재 소유 금액 : %d\n", *playerWallet);
}

// 아이템의 현재 실시간 상황
void inventorystatus(const int inventoryCount[], const char* inventoryText[]) // 인자가 필요, 텍스트는 바뀌지 않지만 갯수는 달라진다. [] 띄어쓰기하면 오류 발생
{
	// int inventoryCount[] = main함수에 있는 int 배열을 넣겠다.
	// const char* inventoryText[] = main함수에 있는 const char* 배열을 넣겠다. 

	

	for (int i = 0; i < 3; i++)
	{
		printf("%s : %d개 \n", inventoryText[i], inventoryCount[i]);
	}
	printf("\n");

	// 주소(const char*) 동전 주소, 레드 포션 주소, 약초 주소 ... -> 주소가 하나만 필요한 것은 아니다. 그래서 *로 주소로 지칭  
}

void AddInventoryDate(int inventoryCount[], int index, int amount)
{
	// 몇번째 요소를 얼마만큼 증가시킬 것인가?
	//[index] -> 몇번째 요소
	//[amount] -> 얼마만큼

	inventoryCount[index] += amount;
}

//void Battle(플레이어의 인벤토리 주소, 0, 200)
//{
//	BattleEnd();
//}
//
//void BattleEnd(플레이어의 인벤토리 주소, 0, 200)
//{
//	AddInventoryDate(플레이어의 인벤토리 주소, 몇번째를, 얼마만큼);
//}
// 
// 
// const 포인터 왜 같이쓰는지? 바뀌지 말아야하는 변수에 쓰는 것
// 함수에서 어떻게 사용해야 하는가? 