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
// 철수의 체력 = ♡♡♡, 3 공격력 1
// 영희의 체력 = ♡♡, 2 공격력 1.5
// 적1 = ♡♡♡, 3 공격력 1
// 적2 = ♡♡♡, 2 공격력 1.5
// 보스= ♡♡♡♡, 공격력 2
// 게임 내 최대체력 ♡♡♡♡가 최대
// 체력 표시 ♥, 데미지를 입은 체력 

// 게임 흐름 : 가위 바위 보를 무엇을 내었는지 표현, 가위 바위 보 한판 후 이김, 짐, 비김 표현, 현재 체력, 현재 적 체력 명시 

// 추가 요소 
// 스테이지 클리어 후 경로 2가지 중 하나 택일 왼쪽 = 1, 오른쪽 = 2 을 누르세요
// 상태이상 요소, 실명 -> 빗나감, 출혈 -> 0.1 한게임당
// 스테이지 클리어 후 체력 풀회복, 아이템 선택창 만들기(아이템 공격력 증가 or 방어력 증가)    

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // 함수 사용을 위한 헤더
#include <time.h> // 컴퓨터 난수 설정을 위한 헤더
// #include <locale.h>   // 콘솔에 ♥/♡ 깨짐 방지 (윈도우면 필요) -> 아직 필요성 있는지 모름.

int main()
{
	// 'void' 는 함수가 ‘아무것도 반환하지 않는다’거나, 포인터가 ‘아무 자료형이나 받을 수 있다’는 뜻을 명시하는 키워드입니다.
	// 변수
	int Characterchoice = 0;
	float player1Healthpoint = 3; // 철수의 체력 = ♥♥♥, 3 공격력 1
	float player1Attack = 1;
	float player2Healthpoint = 2; // 영희의 체력 = ♥♥, 2 공격력 1.5
	float player2Attack = 1.5;
	float Enemy1Healthpoint = 3; // 적1 = ♥♥♥, 3 공격력 1
	float Enemy1Attackt = 1;
	float Enemy2Healthpoint = 2; // 적2 = ♥♥, 2 공격력 1.5
	float Enemy2Attack = 1.5;
	float BossHealthpoint = 4; // 보스= ♥♥♥♥, 공격력 2
	float BossAttack = 2;
	int playerchoice = 0; // 플레이어 가위 바위 보 선택사항
	int computerchoice = 0;
	char Life = '♥';
	char Emptyheart = '♡';




	// 게임 시작 시점
	printf("가위 바위 보 게임 시작!\n"); // 가위 바위 보 게임 시작!
	printf("캐릭터를 선택하시오\n");



	while (1)
	{
		// 캐릭터 선택
		printf("철수 =1, 영희 = 2를 누르세요 : \n");
		scanf("%d", &Characterchoice);
		
		if (Characterchoice == 1)
		{
			printf(" 당신은 철수입니다. 체력 ♥♥♥ 공격력 1.0\n\n");
			break;
		}
		else if (Characterchoice == 2)
		{
			printf(" 당신은 영희입니다. 체력 ♥♥ 공격력 1.5\n\n");
			break;
		}
		else
		{
			printf(" 1 또는 2 를 입력해주세요.\n\n");

		}
	}

	// stage 1  적1 체력 ♥♥♥ 공격력 1.0
	printf("스테이지 1 시작!\n");
	printf("적 체력 ♥♥♥ 공격력 1.0\n");
	if (Characterchoice == 1)
	{
		printf("철수 체력 ♥♥♥ 공격력 1.0\n\n");
	}
	else if (Characterchoice == 2)
	{
		printf(" 영희 체력 ♥♥ 공격력 1.5\n\n");
	}
	// 반복문이 필요하지 않을까? -> while반복문 투입 

	while (1)
	{
		printf("가위(1) 바위(2) 보(3) 중 해당 숫자를 입력하세요 : "); // -> 1, 2, 3을 눌러도 가위 바위 보에 대한 내용이 바뀌지 않음. 
		scanf("%d", &playerchoice);


		srand(time(NULL)); // 난수 생성기 초기화
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
			printf("승리했습니다.\n\n");
			Enemy1Healthpoint--;
		}
		else //값반환이 안됌
		{
			printf("패배했습니다.\n\n");
			player1Healthpoint--;
		}

		// 플레이어 체력이 0일 때 다시 시작지점으로 이동
		if (player1Healthpoint == 0 || player2Healthpoint == 0) // 플레이어 체력 0이되면 처음부터 게임 다시 시작
		{
			printf("체력이 없어 쓰러졌습니다. ");
			return 0;
		}
		else if (Enemy1Healthpoint == 0)
		{
			printf("스테이지 1을 클리어하였습니다.\n ");
		}
		
		// 체력 계산 및 Life가 나와야한다. 
		// o 승패 결과값이 출력이 안됌!-> 같은 값인데 비겼습니다가 아닌 패배했습니다가 나옴. -> rand 변수값을 computerchoice로 바꾸자 해결!






	}

	// stage 2  적2 체력 ♥♥ 공격력 1.5
	// 적2의 체력이 표현되어야 스테이지 2가 시작이 된다.
	if (Enemy1Healthpoint == 0)
	{
		printf("스테이지 2 시작!\n");
		printf("적 체력 ♥♥ 공격력 1.5\n");
	}

	if (player1Healthpoint == 0 || player2Healthpoint == 0) // 플레이어 체력 0이되면 처음부터 게임 다시 시작
	{
		printf("체력이 없어 쓰러졌습니다. ");
		return 0;
	}

	else if (Enemy1Healthpoint == 0 && Enemy2Healthpoint == 0)
	{
		printf("스테이지 1을 클리어하였습니다.\n ");

	}


	// stage 3  적1 체력 ♥♥♥♥ 공격력 2.0
	if (Enemy1Healthpoint == 0 && Enemy2Healthpoint == 0) // 스테이지 1 2 순차적으로 마무리했을 시 보스 스테이지로 이동
	{
		printf("보스 스테이지 시작!\n"); // 
		printf("보스 체력 ♥♥♥ 공격력 2.0\n");
	}

	if (player1Healthpoint == 0 || player2Healthpoint == 0) // 플레이어 체력 0이되면 처음부터 게임 다시 시작
	{
		printf("체력이 없어 쓰러졌습니다. ");
		return 0;
	}
	else if (Enemy1Healthpoint == 0 && Enemy2Healthpoint == 0 && BossHealthpoint == 0)
	{
		printf("보스를 클리어하였습니다.\n ");
		printf("게임을 완료하였습니다. 축하합니다!!\n ");
		printf("처음으로 돌아갑니다.\n ");
		return 0;
	}
}
// 가위 바위 보 로그라이크 Version 1. 0. 0. 10/23
// 가위 바위 보 로그라이크 Version 1. 0. 1. 10/24 -> 반복문 추가, 가위 바위 보 판정에 대한 내용 위치 수정, rand함수 변수를 computerchoice로 수정.
