// 목표: 비쥬얼 스튜디오에서 표현할 수 있는 로그라이크 가위 바위 보 게임 만들기.

// 코드 흐름
// 가위 바위 보 게임 시작!
// 캐릭터를 선택하시오. 
// 철수 = 1, 영희 = 2를 누르세요 
// 가위 = 1, 바위 = 2, 보 = 3

// 3스테이지 구성 (스테이지 1, 스테이지 2, 보스)
// 각 스테이지 클리어 시 체력 전부 회복, 아이템 회복템 or 공격력 0.4 증가템 
// 스테이지1 클리어 시 스테이지 1 클리어, 스테이지 2 클리어, 보스를 물리쳤습니다. -> 게임 끝과 함께 프로그램 종료
// 철수, 영희 체력이 0이 되면 다시 캐릭터 선택부터 시작

// 캐릭터 정보
// 철수의 체력 = ♡♡♡, 30 공격력 10
// 영희의 체력 = ♡♡, 20 공격력 15
// 적1 = ♡♡♡, 30 공격력 10
// 적2 = ♡♡♡, 20 공격력 15
// 보스= ♡♡♡♡, 40 공격력 20
// 게임 내 최대체력 ♡♡♡♡가 최대
// 체력 표시 ♥, 데미지를 입은 체력 ♡, 반 체력 ◐ 

// 게임 흐름 : 가위 바위 보를 무엇을 내었는지 표현, 가위 바위 보 한판 후 이김, 짐, 비김 표현, 현재 체력, 현재 적 체력 명시 

// 추가 요소 
// 스테이지 클리어 후 경로 2가지 중 하나 택일 왼쪽 = 1, 오른쪽 = 2 을 누르세요
// 상태이상 요소, 실명 -> 빗나감, 출혈 -> 0.1 승패 1번에 데미지 줌
// 스테이지 클리어 후 체력 풀회복, 아이템 선택창 만들기(아이템 공격력 증가 or 방어력 증가)    

// 체력에 대한 표현을 변수로 대체하여 표현 ex) healthpoint == 30 -> 30을 변수로 대체

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // 함수 사용을 위한 헤더
#include <time.h> // 컴퓨터 난수 설정을 위한 헤더
#include <locale.h>   // 콘솔에 ♥/♡ 깨짐 방지 (윈도우면 필요) -> 아직 필요성 있는지 모름. -> ANSI(CP949)로 맞춰야하므로 학원에서의 인코딩 방식과 맞지 않아 
// 다른 방식으로 사용할 예정 -> if 반복문으로 조건 부합 시 문자로 하트 표현 
// 유니코드 저장 필요하여 보류

int main()
{
	// 'void' 는 함수가 ‘아무것도 반환하지 않는다’거나, 포인터가 ‘아무 자료형이나 받을 수 있다’는 뜻을 명시하는 키워드입니다.
	// 변수
		// 시스템의 기본 로케일로 설정
	// setlocale(LC_ALL, ""); 하트 깨짐 방지 코드였음

	int Characterchoice = 0;
	int player1Healthpoint = 30; // 철수의 체력 = ♥♥♥, 3 공격력 1
	int player1Attack = 10;
	int player2Healthpoint = 20; // 영희의 체력 = ♥♥, 2 공격력 1.5
	int player2Attack = 15;
	int Enemy1Healthpoint = 30; // 적1 = ♥♥♥, 3 공격력 1
	int Enemy1Attack = 10;
	int Enemy2Healthpoint = 20; // 적2 = ♥♥, 2 공격력 1.5
	int Enemy2Attack = 10;
	int BossHealthpoint = 40; // 보스= ♥♥♥♥, 공격력 2
	int BossAttack = 20;

	char Selectreward = 0; //스테이지 클리어 보상 선택사항
	int Attackboost = 4; // 스테이지 클리어 보상 


	int playerchoice = 0; // 플레이어 가위 바위 보 선택사항
	int computerchoice = 0; // 적 가위 바위 보 선택사항


	//char Life = '♥';
	//char Emptyheart = '♡';	// 현재 유니코드로 저장하지 않을 예정이라 보류
	//char Halfheart = '◐';



	// 게임 시작 시점
	// if(player1Healthpoint == 0 || player2Healthpoint == 0) 시스템 종료없이 바로 여기로 돌아가야하는 시스템 필요
	printf("가위 바위 보 게임 시작!\n"); // 가위 바위 보 게임 시작!
	printf("캐릭터를 선택하시오\n");

	srand(time(NULL)); // 난수 생성기 초기화 srand(time(NULL));를 매 턴에서 호출하면 같은 초 안에 입력하면 같은 난수가 나올 수 있습니다. 게임 시작 전에 한 번만 호출
	while (1) // 전체 while로 묶은 상태
	{
		// 다시 프로그램을 돌렸을 때 값 초기화
		player1Healthpoint = 30; // 철수의 체력 = ♥♥♥, 30 공격력 10
		player1Attack = 10;
		player2Healthpoint = 20; // 영희의 체력 = ♥♥, 20 공격력 15
		player2Attack = 15;
		Enemy1Healthpoint = 30; // 적1 = ♥♥♥, 30 공격력 10
		Enemy1Attack = 10;
		Enemy2Healthpoint = 20; // 적2 = ♥♥, 20 공격력 15
		Enemy2Attack = 15;
		BossHealthpoint = 40; // 보스= ♥♥♥♥, 40 공격력 20
		BossAttack = 20;

		// 캐릭터 선택
		printf("철수 =1, 영희 = 2를 누르세요 : \n");
		scanf("%d", &Characterchoice);

		if (Characterchoice == 1)
		{
			printf(" 당신은 철수입니다. 체력 ♥♥♥(30) 공격력 10\n\n");
			break;
		}
		else if (Characterchoice == 2)
		{
			printf(" 당신은 영희입니다. 체력 ♥♥(20) 공격력 15\n\n");
			break;
		}
		else
		{
			printf(" 1 또는 2 를 입력해주세요.\n\n");
		}
	}

	// stage 1  적1 체력 ♥♥♥ 공격력 10
	printf("스테이지 1 시작!\n");
	printf("적 체력 ♥♥♥(30) 공격력 10\n");
	if (Characterchoice == 1)
	{
		printf("철수 체력 ♥♥♥ 공격력 10\n\n");
	}
	else if (Characterchoice == 2)
	{
		printf("영희 체력 ♥♥(20) 공격력 15\n\n");
	}
	// 반복문이 필요하지 않을까? -> while반복문 투입 

	while (1)
	{

		printf("가위(1) 바위(2) 보(3) 중 해당 숫자를 입력하세요 : "); // -> 1, 2, 3을 눌러도 가위 바위 보에 대한 내용이 바뀌지 않음. 
		scanf("%d", &playerchoice);


		
		int computerchoice = rand() % 3 + 1; // 1~3 사이의 난수 생성 (1 = 가위, 2 = 바위, 3 = 보)
		printf("적의 선택: %d\n\n", computerchoice); // 변수를 computerchoice로 하였을 때 재정의되지 않고 출력이 됌!!

		// 적의 선택까지는 출력이 되는데 이후 판정 출력과 체력 계산 후 출력이 나오지 않는 상황 

			//가위 바위 보 판정 및 체력 계산 코드
		// 가위 = 1 바위 = 2 보 = 3
		if (playerchoice <= 0 || playerchoice > 3)
		{
			printf("잘못 입력하였습니다.\n\n");
		}
		else if (playerchoice == computerchoice)
		{
			printf("비겼습니다.\n\n");
		}
		else if ((playerchoice == 1 && computerchoice == 3) || (playerchoice == 2 && computerchoice == 1) || (playerchoice == 3 && computerchoice == 2))
		{
			if (Characterchoice == 1) {
				printf("승리했습니다.\n\n");
				Enemy1Healthpoint = Enemy1Healthpoint - player1Attack;
			}
			else if (Characterchoice == 2) {
				printf("승리했습니다.\n\n");
				Enemy1Healthpoint = Enemy1Healthpoint - player2Attack;
			}
		}
		else
		{
			printf("패배했습니다.\n\n");
			player1Healthpoint = player1Healthpoint - Enemy1Attack; 
			player2Healthpoint = player2Healthpoint - Enemy1Attack;
		}

		// 체력 출력 코드
		// 플레이어1 체력 표현 -> 고정 소수점으로 해보기 
		if (Characterchoice == 1 && player1Healthpoint == 30) { //  체력 30
			printf("철수 체력 ♥♥♥\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint > 20 && player1Healthpoint < 30) { //  체력 2x
			printf("철수 체력 ♥♥◐\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint == 20) { //  체력 20
			printf("철수 체력 ♥♥♡\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint > 10 && player1Healthpoint < 20) { //  체력 x
			printf("철수 체력 ♥◐♡\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint == 10) { // 체력 10
			printf("철수 체력 ♥♡♡\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint > 0 && player1Healthpoint < 10) { //  x
			printf("철수 체력 ◐♡♡\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint <= 0) {// 체력 0 // -> 왜 이 값이 반환되지 않을까? -> else if에서 else로 고침 -> else if로 다시
			printf("철수 체력 ♡♡♡\n");

			// 플레이어 체력이 0일 때 다시 시작지점으로 이동
			if (player1Healthpoint == 0) // 플레이어 체력 0이되면 처음부터 게임 다시 시작
			{
				printf("체력이 없어 쓰러졌습니다. ");
				printf("스테이지 1 실패!! ㅠ . ㅠ\n ");
				system("pause");
				return 0;
			}
		}
		// 플레이어2 체력 표현
		if (Characterchoice == 2 && player2Healthpoint == 20) { // 체력20
			printf("영희 체력 ♥♥\n");
		}
		else if (Characterchoice == 2 && player2Healthpoint > 10 && player2Healthpoint < 20) { //  체력 1x
			printf("영희 체력 ♥◐\n");
		}
		else if (Characterchoice == 2 && player2Healthpoint == 10) { // 체력 10
			printf("영희 체력 ♥♡\n");
		}
		else if (Characterchoice == 2 && player2Healthpoint > 0 && player2Healthpoint < 10) { //  체력 x
			printf("영희 체력 ◐♡\n");
		}
		else if (Characterchoice == 2 && player2Healthpoint <= 0) { // 체력 0 
			printf("영희 체력 ♡♡\n");
			// 플레이어 체력이 0일 때 다시 시작지점으로 이동
			if (player2Healthpoint == 0) // 플레이어 체력 0이되면 처음부터 게임 다시 시작
			{
				printf("체력이 없어 쓰러졌습니다. ");
				printf("스테이지 1 실패!! ㅠ . ㅠ\n ");
				system("pause");
				return 0;
			}
		}
		// 적1 체력 표현
		if (Enemy1Healthpoint == 30) { //  체력 30
			printf("적 체력 ♥♥♥\n");
		}
		else if (Enemy1Healthpoint > 20 && Enemy1Healthpoint < 30) { //  체력 2x
			printf("적 체력 ♥♥◐\n");
		}
		else if (Enemy1Healthpoint == 20) { //  체력 20
			printf("적 체력 ♥♥♡\n");
		}
		else if (Enemy1Healthpoint > 10 && Enemy1Healthpoint < 20) { //  체력 1x
			printf("적 체력 ♥◐♡\n");
		}
		else if (Enemy1Healthpoint == 10) { // 체력 10
			printf("적 체력 ♥♡♡\n");
		}
		else if (Enemy1Healthpoint > 0 && Enemy1Healthpoint < 10) { //  체력 x
			printf("적 체력 ◐♡♡\n");	
		}
		else if (Enemy1Healthpoint <= 0) { // 체력 0 
			printf("적 체력 ♡♡♡\n");
		}

		// 클리어 보상
		if (Enemy1Healthpoint == 0)
		{
			printf("스테이지 1을 클리어하였습니다.\n ");
			printf("클리어 보상 \n");
			printf("체력을 전부 회복합니다.\n\n");
			printf("a. 공격력 증가 + 0.4  b. 아이템 실명딱밤 \n");
			printf("클리어 보상을 선택하세요(a 또는 b 입력) : \n");
			scanf("%c", &Selectreward);
		}

		if (Enemy1Healthpoint == 0 && Characterchoice == 1 && Selectreward == 'a') //적1 체력이 0이면 스테이지2 시작, 97 = a
		{
			player1Healthpoint = 30;		// 영희의 체력 회복이 필요.
			printf("철수의 체력 ♥♥♥ 공격력 : %d \n", player1Attack + Attackboost);
		}
		else if (Enemy1Healthpoint == 0 && Characterchoice == 2 && Selectreward == 'a') //적1 체력이 0이면 스테이지2 시작
		{
			player2Healthpoint = 20;		// 영희의 체력 회복이 필요.
			printf("영희의 체력 ♥♥ 공격력 : %d \n", player2Attack + Attackboost);
		}
		// 실명딱밤에 대한 아이템 추가 부여상황 필요.


		// 체력 계산 및 Life가 나와야한다. 
		// o 승패 결과값이 출력이 안됌!-> 같은 값인데 비겼습니다가 아닌 패배했습니다가 나옴. -> rand 변수값을 computerchoice로 바꾸자 해결!

		printf("\n");
		// stage 2  적2 체력 ♥♥ 공격력 15 
		if (Enemy1Healthpoint == 0 && Enemy2Healthpoint == 20) //적1 체력이 0이면 스테이지2 시작
		{
			printf("스테이지 2 시작!\n");
			printf("적 체력 ♥♥ 공격력 1.5\n");
		}

		// 가위 = 1 바위 = 2 보 = 3
		if (playerchoice <= 0 || playerchoice > 3)
		{
			printf("잘못 입력하였습니다.\n\n");
		}
		else if (playerchoice == computerchoice)
		{
			printf("비겼습니다.\n\n");
		}
		else if ((playerchoice == 1 && computerchoice == 3) || (playerchoice == 2 && computerchoice == 1) || (playerchoice == 3 && computerchoice == 2))
		{
			if (Characterchoice == 1) {
				printf("승리했습니다.\n\n");
				Enemy1Healthpoint = Enemy2Healthpoint - player1Attack;
			}
			else if (Characterchoice == 2) {
				printf("승리했습니다.\n\n");
				Enemy1Healthpoint = Enemy2Healthpoint - player2Attack;
			}
		}
		else
		{
			printf("패배했습니다.\n\n");
			player1Healthpoint = player1Healthpoint - Enemy2Attack; // -> 플레이어 체력 계산이 안되는 문제 발생!
			player2Healthpoint = player2Healthpoint - Enemy2Attack;
		}
		// 플레이어1 체력 표현
		if (Characterchoice == 1 && player1Healthpoint == 30 && Enemy1Healthpoint == 0) { //  체력 30
			printf("철수 체력 ♥♥♥\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint > 20 && player1Healthpoint < 30 && Enemy1Healthpoint == 0) { //  체력 2x
			printf("철수 체력 ♥♥◐\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint == 20 && Enemy1Healthpoint == 0) { //  체력 20
			printf("철수 체력 ♥♥♡\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint > 10 && player1Healthpoint < 20 && Enemy1Healthpoint == 0) { //  체력 1x
			printf("철수 체력 ♥◐♡\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint == 10 && Enemy1Healthpoint == 0) { // 체력 10
			printf("철수 체력 ♥♡♡\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint > 0 && player1Healthpoint < 10 && Enemy1Healthpoint == 0) { //  체력 1x
			printf("철수 체력 ◐♡♡\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint == 0 && Enemy1Healthpoint == 0) { // 체력 0 
			printf("철수 체력 ♡♡♡\n");
		}
		// 플레이어2 체력 표현
		if (Characterchoice == 2 && player2Healthpoint == 20 && Enemy1Healthpoint == 0) { // 체력 20
			printf("영희 체력 ♥♥\n");
		}
		else if (Characterchoice == 2 && player2Healthpoint > 10 && player2Healthpoint < 20 && Enemy1Healthpoint == 0) { //  체력 1x
			printf("영희 체력 ♥◐\n");
		}
		else if (Characterchoice == 2 && player2Healthpoint == 10 && Enemy1Healthpoint == 0) { // 체력 10
			printf("영희 체력 ♥♡\n");
		}
		else if (Characterchoice == 2 && player2Healthpoint > 0 && player2Healthpoint < 10 && Enemy1Healthpoint == 0) { //  체력 1x
			printf("영희 체력 ◐♡\n");
		}
		else if (Characterchoice == 2 && player2Healthpoint == 0 && Enemy1Healthpoint == 0) { // 체력 0 
			printf("영희 체력 ♡♡\n");
		}
		// 적2 체력 표현
		if (Enemy1Healthpoint == 0 && Enemy2Healthpoint == 20) { // 체력 20
			printf("적 체력 ♥♥\n");
		}
		else if (Enemy1Healthpoint == 0 && Enemy2Healthpoint > 10 && Enemy2Healthpoint < 20) { //  체력 1x
			printf("적 체력 ♥◐\n");
		}
		else if (Enemy1Healthpoint == 0 && Enemy2Healthpoint == 10) { // 체력 10
			printf("적 체력 ♥♡\n");
		}
		else if (Enemy1Healthpoint == 0 && Enemy2Healthpoint > 0 && Enemy2Healthpoint < 10) { //  체력 1x
			printf("적 체력 ◐♡\n");
		}
		else if (Enemy1Healthpoint == 0 && Enemy2Healthpoint == 0) { // 체력 0 
			printf("적 체력 ♡♡\n");
		}

		if (player1Healthpoint <= 0 || player2Healthpoint <= 0 && Enemy1Healthpoint <= 0) // 플레이어 체력 0이되면 처음부터 게임 다시 시작
		{
			printf("체력이 없어 쓰러졌습니다. ");
			printf("스테이지 2 실패!! ㅠ . ㅠ\n ");
			system("pause");
			return 0;
		}


		else if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0)
			// 클리어 보상
			if (Enemy1Healthpoint <= 0)
			{
				printf("스테이지 2을 클리어하였습니다.\n ");
				printf("클리어 보상 \n");
				printf("체력을 전부 회복합니다.\n\n");
				printf("a. 공격력 증가 + 0.4   b. 아이템 실명딱밤 \n");
				printf("클리어 보상을 선택하세요(1 또는 2 입력) : \n");
				scanf("%c", &Selectreward);
			}

		if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0 && Characterchoice == 1) //적1 체력이 0이면 스테이지2 시작
		{
			player1Healthpoint = 30;		// 영희의 체력 회복이 필요.
			printf("철수의 체력 ♥♥♥ 공격력 : %d \n", player1Attack + Attackboost);
		}
		else if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0 && Characterchoice == 2) //적1 체력이 0이면 스테이지2 시작
		{
			player2Healthpoint = 20;		// 영희의 체력 회복이 필요.
			printf("영희의 체력 ♥♥ 공격력 : %d \n", player2Attack + Attackboost);
		}


		// stage 3  적1 체력 ♥♥♥♥ 공격력 2.0
		if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0 && BossHealthpoint == 40) // 스테이지 1 2 순차적으로 마무리했을 시 보스 스테이지로 이동
		{
			printf("보스 스테이지 시작!\n"); // 
			printf("보스 체력 ♥♥♥♥ 공격력 2.0\n");
		}
		// 플레이어1 체력 표현
		if (Characterchoice == 1 && player1Healthpoint <= 30 && Enemy1Healthpoint <= 0 && Enemy2Healthpoint == 0) { //  체력 30
			printf("철수 체력 ♥♥♥\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint > 20 && player1Healthpoint < 30 && Enemy1Healthpoint == 0 && Enemy2Healthpoint == 0) { //  체력 20x
			printf("철수 체력 ♥♥◐\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint == 20 && Enemy1Healthpoint <= 0 && Enemy2Healthpoint == 0) { //  체력 20
			printf("철수 체력 ♥♥♡\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint > 10 && player1Healthpoint < 20 && Enemy1Healthpoint == 0 && Enemy2Healthpoint == 0) { //  체력 1x
			printf("철수 체력 ♥◐♡\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint == 10 && Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0) { // 체력 10
			printf("철수 체력 ♥♡♡\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint > 0 && player1Healthpoint < 10 && Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0) { //  체력 x
			printf("철수 체력 ◐♡♡\n");
		}
		else if (Characterchoice == 1 && player1Healthpoint == 0 && Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0) { // 체력 0 
			printf("철수 체력 ♡♡♡\n");
		}
		// 플레이어2 체력 표현
		if (Characterchoice == 2 && player2Healthpoint == 20 && Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0) { // 체력 20
			printf("영희 체력 ♥♥\n");
		}
		else if (Characterchoice == 2 && player2Healthpoint > 10 && player2Healthpoint < 20 && Enemy1Healthpoint == 0 && Enemy2Healthpoint == 0) { //  체력 1x
			printf("영희 체력 ♥◐\n");
		}
		else if (Characterchoice == 2 && player2Healthpoint == 10 && Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0) { // 체력 1
			printf("영희 체력 ♥♡\n");
		}
		else if (Characterchoice == 2 && player2Healthpoint > 0 && player2Healthpoint < 10 && Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0) { //  체력 x
			printf("영희 체력 ◐♡\n");
		}
		else if (Characterchoice == 2 && player2Healthpoint == 0 && Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0) { // 체력 0 
			printf("영희 체력 ♡♡\n");
		}
		// 보스 체력 표현
		if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0 && BossHealthpoint == 40) {// 체력 40
			printf("♥♥♥♥\n");
		}
		else if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0 && BossHealthpoint > 30 && BossHealthpoint < 40) { //  체력 3x
			printf("체력 ♥♥♥◐\n");
		}
		else if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0 && BossHealthpoint == 30) { //  체력 30
			printf("체력 ♥♥♥♡\n");
		}
		else if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0 && BossHealthpoint > 20 && BossHealthpoint < 30) { //  체력 2x
			printf("체력 ♥♥◐♡\n");
		}
		else if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0 && BossHealthpoint == 20) { //  체력 20
			printf("체력 ♥♥♡♡\n");
		}
		else if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0 && BossHealthpoint > 10 && BossHealthpoint < 20) { //  체력 1x
			printf("체력 ♥◐♡♡\n");
		}
		else if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0 && BossHealthpoint == 10) { // 체력 10
			printf("체력 ♥♡♡♡\n");
		}
		else if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0 && BossHealthpoint == 10 && BossHealthpoint > 0) { //  체력 x
			printf("체력 ◐♡♡♡\n");
		}
		else if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0 && BossHealthpoint == 0) { // 체력 0 
			printf("체력 ♡♡♡♡\n");
		}
		if (player1Healthpoint <= 0 || player2Healthpoint <= 0 && Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0) // 플레이어 체력 0이되면 처음부터 게임 다시 시작
		{
			printf("체력이 없어 쓰러졌습니다. ");
			printf("보스 스테이지 실패!! ㅠ . ㅠ\n ");
			return 0;
		}
		else if (Enemy1Healthpoint <= 0 && Enemy2Healthpoint <= 0 && BossHealthpoint <= 0)
		{
			printf("보스를 클리어하였습니다.\n ");
			printf("게임을 완료하였습니다. 축하합니다!!\n ");
			printf("처음 시작으로 돌아갑니다.\n ");
			system("pause");
			return 0;
		}
	}
}








// 가위 바위 보 로그라이크 Version 1. 0. 0. 10/23
// 가위 바위 보 로그라이크 Version 1. 0. 1. 10/24 -> 반복문 추가, 가위 바위 보 판정에 대한 내용 위치 수정, rand함수 변수를 computerchoice로 수정, while문 안에 스테이지 3개 넣음.
// 가위 바위 보 로그라이크 Version 1. 0. 2. 10/26 -> 체력 표현 조건문 추가, 가위 바위 보 판정 코드 위치 수정, 디버깅을 위하여 스테이지 1 따로 묶어둠 2, 보스 스테이지 한번에 묶기
																				  // -> 플레이어 체력 계산을 위해 int로 변수 부여
