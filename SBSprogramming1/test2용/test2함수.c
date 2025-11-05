#include "test2함수.h"

// 변수
int player1Healthpoint = 30; // 전사의 체력 = ♥♥♥, 30 공격력 10
int player1Attack = 10;
int player2Healthpoint = 20; // 영희의 체력 = ♥♥, 20 공격력 15
int player2Attack = 15;
int Enemy1Healthpoint = 30; // 산적1 = ♥♥♥, 30 공격력 10
int Enemy1Attack = 10;
int Enemy2Healthpoint = 20; // 산적2 = ♥♥, 20 공격력 15
int Enemy2Attack = 10;
int BossHealthpoint = 40; // 산적 보스= ♥♥♥♥, 공격력 20
int BossAttack = 20;
int playerchoice = 0; // 플레이어 가위 바위 보 선택사항
int Enemychoice = 0; // 적 가위 바위 보 선택사항
int Character = 0; // 캐릭터 선택사항 
int* CharacterPtr = &Character; // 캐릭터 선택사항 포인터




// 모험을 시작합니다!
// 깊은 숲을 헤쳐나가세요.
// 캐릭터를 선택하시오. 
// 전사 = 1, 도적 = 2를 누르세요 
// 전사
// 공격 = 1, 강한 공격 = 2, 방어 = 3
// 도적
// 공격 = 1, 독칼 공격 = 2, 회피 = 3




// 캐릭터 선택 함수
void StartCharacterchoice() {
	*CharacterPtr; // Characterchoice 주소 역참조

	printf("전사 =1, 도적 = 2를 누르세요 : \n");
	scanf("%d", &Character);

	if (Character == 1)
	{
		printf(" 당신은 전사입니다. 체력 ♥♥♥(30) 공격력 10\n\n");

	}
	else if (Character == 2)
	{
		printf(" 당신은 도적입니다. 체력 ♥♥(20) 공격력 15\n\n");

	}
	else
	{
		printf(" 1 또는 2 를 입력해주세요.\n\n");
	}

	//캐릭터 선택에 따른 체력 및 공격력 명시
	if (Character == 1)
	{
		printf(" 당신은 전사입니다. 체력 ♥♥♥(%d) 공격력 %d, \n\n", player1Healthpoint, player1Attack);

	}
	else if (Character == 2)
	{
		printf(" 당신은 도적입니다. 체력 ♥♥(%d) 공격력 %d, \n\n", player2Healthpoint, player2Attack);

	}
}






void StartBattle() {

	srand(time(NULL)); // 난수 생성기 초기화 srand(time(NULL));를 매 턴에서 호출하면 같은 초 안에 입력하면 같은 난수가 나올 수 있습니다. 게임 시작 전에 한 번만 호출





	// 전투를 위한 while 루프
	while (player1Healthpoint > 0 || player2Healthpoint > 0 && Enemy1Healthpoint > 0) {
		printf("산적1이 나타났다!\n");
		// stage 1  적1 체력 ♥♥♥ 공격력 10
		printf("스테이지 1 시작!\n");
		printf("적 체력 ♥♥♥(30) 공격력 10\n");
		// 전사, 도적 선택에 맞춰 행동 선택사항 출력코드 
		if (CharacterPtr == 1) {
			printf("공격(1) 강한 공격(2) 방어(3) 중 해당 숫자를 입력하세요 : ");
			scanf("%d", &playerchoice);
		}
		else if (Character == 2)
		{
			printf("공격(1) 독칼 공격(2) 회피(3) 중 해당 숫자를 입력하세요 :  ");
			scanf("%d", &playerchoice);
		}

		//적 난수 생성
		int Enemychoice = rand() % 3 + 1; // 1~3 사이의 난수 생성 (1 = 공격, 2 = 방어, 3 = 회피)
		printf("적의 선택: %d\n\n", Enemychoice); // 변수를 computerchoice로 하였을 때 재정의되지 않고 출력이 됌!!

		// 플레이어 공격, 강한 공격, 독칼, 방어, 회피 vs 적의 공격, 방어, 회피에 대한 계산 
		if (Character == 1 && playerchoice <= 0 || playerchoice > 3)
		{
			printf("잘못 입력하였습니다.\n\n");
		}
		else if (Character == 1 && playerchoice == 1)
		{
			printf("비겼습니다.\n\n");
		}
		else if (Character == 1 || (playerchoice == 1 && Enemychoice == 3) || (playerchoice == 2 && Enemychoice == 1) || (playerchoice == 3 && Enemychoice == 2))
		{
			if (Character == 1) {
				printf("공격했습니다.\n\n");
				Enemy1Healthpoint = Enemy1Healthpoint - player1Attack;
			}
		}
		else
		{
			printf("공격 당했습니다.\n\n");
			player1Healthpoint = player1Healthpoint - Enemy1Attack;
			player2Healthpoint = player2Healthpoint - Enemy1Attack;
		}
	}
	printf("----------------------------------\n");

	// 게임 결과 판정 -> 수정 필요
	if (player1Healthpoint <= 0 || player2Healthpoint <= 0) {
		printf("게임 오버! 플레이어가 패배했습니다.\n");
	}
	else {
		printf("승리했습니다! 적을 물리쳤습니다.\n");
	}
}