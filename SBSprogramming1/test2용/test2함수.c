#include "test2함수.h"
// 변수
//int player1Healthpoint = 30; // 전사의 체력 = ♥♥♥, 30 공격력 10
//int player1Attack = 10;
//int player2Healthpoint = 20; // 영희의 체력 = ♥♥, 20 공격력 15
//int player2Attack = 15;
//int Enemy1Healthpoint = 30; // 산적1 = ♥♥♥, 30 공격력 10
//int Enemy1Attack = 10;
//int Enemy2Healthpoint = 20; // 산적2 = ♥♥, 20 공격력 15
//int Enemy2Attack = 10;
//int BossHealthpoint = 40; // 산적 보스= ♥♥♥♥, 공격력 20
//int BossAttack = 20;





// 모험을 시작합니다!
// 깊은 숲을 헤쳐나가세요.
// 캐릭터를 선택하시오. 
// 전사 = 1, 도적 = 2를 누르세요 
// 전사
// 공격 = 1, 강한 공격 = 2, 방어 = 3
// 도적
// 공격 = 1, 독칼 공격 = 2, 회피 = 3



void SetplayerStat(JOB selectCharacter, int* baseHPptr, int* baseATKptr, int* baseDEFptr, int* baseCTRptr, int* basePOISONptr) // 역참조를 활용해 주소 안에 저장되어 있는 값을 출력되도록 하는 코드
{


	printf("\n");
	switch (selectCharacter)
	{
	case UNDEFINED:
		printf("잘못 입력하였습니다\n");
		// 잘못 입력 시 다시 캐릭터 선택창으로 돌아가도록 해보기.
		break;
	case WARRIOR:
		*baseHPptr = 30;
		*baseATKptr = 10;
		*baseDEFptr = 5;
		printf("체력 ♥♥♥(%d) 공격력 (%d) 강한공격(%d x 1.5배), 방어력(%d) \n\n", *baseHPptr, *baseATKptr, *baseATKptr, *baseDEFptr); // 1입력에 따른 전사 스탯 정리
		break;
	case THIEF:
		*baseHPptr = 20;
		*baseATKptr = 15;
		*basePOISONptr = 3;
		*baseCTRptr = 5; // COUNTERATTACK(반격)
		printf("체력 ♥♥(%d) 공격력(%d), 독칼공격(%d), 회피반격(%d)\n\n", *baseHPptr, *baseATKptr, *basePOISONptr, *baseCTRptr); // 2 입력에 따른 도적 스탯 정리
		break;
	}



}

bool Debuff(ENEMY Enemy1, int* basePOISONptr)
{
	{
		if (Enemy1.hp - *basePOISONptr)
		{
			return true;
			Enemy1.hp - 5;
		}
		else
		{
			return false;
		}
	}
}

void StartBattle(JOB selectCharacter, int* baseHPptr, int* baseATKptr, int* baseDEFptr, int* baseCTRptr, int* basePOISONptr)
{
	srand(time(NULL)); // 난수 생성기 초기화 srand(time(NULL));를 매 턴에서 호출하면 같은 초 안에 입력하면 같은 난수가 나올 수 있습니다. 게임 시작 전에 한 번만 호출
	ENEMY Enemy1 = { 30, 10, 5 };  // 산적1 스탯정리, 구조체 호출

	int playerchoice = 0; // 플레이어 가위 바위 보 선택사항
	int Enemychoice = 0; // 적 가위 바위 보 선택사항

	printf("스테이지 1 시작!\n");
	printf("산적1이 나타났다!\n\n");
	printf("산적1 체력 ♥♥♥(%d) 공격력(%d) 방어력(%d)\n", Enemy1.hp, Enemy1.atk, Enemy1.def);
	printf("적의 선택 사항 : 공격 = 1, 방어 = 2, 회피 = 3\n\n");
	// 전투를 위한 while 루프
	while (*baseHPptr > 0 && Enemy1.hp > 0) {
		// stage 1  적1 체력 ♥♥♥ 공격력 10


		// 전사, 도적 선택에 맞춰 행동 선택사항 출력코드 
		if (selectCharacter == WARRIOR) {
			printf("공격(1) 강한 공격(2) 방어(3) 중 해당 숫자를 입력하세요 : ");
			scanf("%d", &playerchoice);
		}
		else if (selectCharacter == THIEF)
		{
			printf("공격(1) 독칼 공격(2) 회피(3) 중 해당 숫자를 입력하세요 :  ");
			scanf("%d", &playerchoice);
		}

		//적 난수 생성
		int Enemychoice = rand() % 3 + 1; // 1~3 사이의 난수 생성 (1 = 공격, 2 = 방어, 3 = 회피)
		printf("적의 선택: %d\n", Enemychoice); // 변수를 computerchoice로 하였을 때 재정의되지 않고 출력이 됌!!

		// 플레이어 공격, 강한 공격, 독칼, 방어, 회피 vs 적의 공격, 방어, 회피에 대한 계산 
			//전사
			//공격 강한 공격 방어 1 2 3

			//도적
			//공격 독칼공격 회피반격 1 2 3

			//산적1
			//공격 방어 회피 1 2 3

			//전사일 때
		{
			//1 vs 1 비김
			if (selectCharacter == WARRIOR && playerchoice == 1 && Enemychoice == 1) {
				printf("\n서로 공격하여 비겼습니다.\n");
			}
			else if (selectCharacter == WARRIOR && playerchoice == 1 && Enemychoice == 2)
			{
				//1 vs 2 산적1방어력 - 전사 공격력
				printf("\n공격하였습니다.\n");

				Enemy1.hp = Enemy1.hp + Enemy1.def - *baseATKptr;
			}
			else if (selectCharacter == WARRIOR && playerchoice == 1 && Enemychoice == 3)
			{
				char EnemyMiss = 'a' + (rand() % 5);
				//1 vs 3 회피 c가 나온 경우 회피
				if (EnemyMiss == 'c') {
					printf("a ~ e 중 나온 알파벳 : %c\n", EnemyMiss);
					printf("\n산적1은 회피하였습니다,\n");
				}
				//1 vs 3 회피 c외에 나온 경우 공격력 그대로
				else if (EnemyMiss != 'c') {
					printf("a ~ e 중 나온 알파벳 : %c\n", EnemyMiss);
					printf("\n산적1은 회피에 실패했습니다,\n");
					Enemy1.hp = Enemy1.hp - *baseATKptr;
				}
			}
			//2 vs 1 강한 공격 데미지, 산적1공격 데미지
			else if (selectCharacter == WARRIOR && playerchoice == 2 && Enemychoice == 1) {
				printf("\n산적1의 공격을 뚫고 강하게 공격하였습니다.\n");
				Enemy1.hp = Enemy1.hp - *baseATKptr * 1.5;
			}
			//2 vs 2 강한 공격 - 산적1 방어력
			else if (selectCharacter == WARRIOR && playerchoice == 2 && Enemychoice == 2)
			{
				printf("\n공격하였습니다.\n");
				Enemy1.hp = Enemy1.hp + Enemy1.def - *baseATKptr * 1.5;
			}
			else if (selectCharacter == WARRIOR && playerchoice == 2 && Enemychoice == 3)
			{
				char EnemyMiss = 'a' + (rand() % 5);
				//2 vs 3 회피 c가 나온 경우 회피
				if (EnemyMiss == 'c') {
					printf("a ~ e 중 나온 알파벳 : %c\n", EnemyMiss);
					printf("\n산적1은 회피하였습니다,\n");
				}
				//2 vs 3 회피 c외에 나온 경우 강한공격력 그대로
				else if (EnemyMiss != 'c') {
					printf("a ~ e 중 나온 알파벳 : %c\n", EnemyMiss);
					printf("\n산적1은 회피에 실패했습니다,\n");
					Enemy1.hp = Enemy1.hp - *baseATKptr * 1.5;
				}
			}
			//3 vs 1 전사 방어력 - 산적 1 공격력
			else if (selectCharacter == WARRIOR && playerchoice == 3 && Enemychoice == 1) {
				printf("\n산적1의 공격을 뚫고 강하게 공격하였습니다.\n");
				*baseHPptr = *baseHPptr - Enemy1.atk;
			}
			
			//3 vs 2 방어 방어 둘다 쫄아있다
			else if (selectCharacter == WARRIOR && playerchoice == 3 && Enemychoice == 2)
			{
				printf("\n둘 다 방어만 하면서 쫄았다.\n");
			}
			//3 vs 3 아무 일도 일어나지 않았다
			else if (selectCharacter == WARRIOR && playerchoice == 3 && Enemychoice == 3)
			{
				printf("\n아무 일도 일어나지 않았다.\n");
			}
		}

		if (selectCharacter == THIEF)
		{
			//1 vs 1 비김
			if (selectCharacter == THIEF && playerchoice == 1 && Enemychoice == 1) {
				printf("\n서로 공격하여 비겼습니다.\n");
			}
			else if (selectCharacter == THIEF && playerchoice == 1 && Enemychoice == 2)
			{
				//1 vs 2 산적1방어력 - 도적 공격력
				printf("\n공격하였습니다.\n");
				Enemy1.hp = Enemy1.hp + Enemy1.def - *baseATKptr;
			}
			else if (selectCharacter == THIEF && playerchoice == 1 && Enemychoice == 3)
			{
				char EnemyMiss = 'a' + (rand() % 5);
				//1 vs 3 회피 c가 나온 경우 회피
				if (EnemyMiss == 'c') {
					printf("a ~ e 중 나온 알파벳 : %c\n", EnemyMiss);
					printf("\n산적1은 회피하였습니다,\n");
				}
				//1 vs 3 회피 c외에 나온 경우 공격력 그대로
				else if (EnemyMiss != 'c') {
					printf("a ~ e 중 나온 알파벳 : %c\n", EnemyMiss);
					printf("\n산적1은 회피에 실패했습니다,\n");
					Enemy1.hp = Enemy1.hp - *baseATKptr;
				}
			}
			//2 vs 1 상태이상 중독, 산적1공격 데미지
			else if (selectCharacter == THIEF && playerchoice == 2 && Enemychoice == 1) {
				printf("\n독칼로 공격합니다.\n");
				printf("산적1에게 공격 받았습니다.\n");
				printf("산적 1은 중독에 걸렸습니다.\n");
				Enemy1.hp = Enemy1.hp - *basePOISONptr;
				*baseHPptr = *baseHPptr - Enemy1.atk;
			}
			//2 vs 2 상태이상 중독
			else if (selectCharacter ==THIEF && playerchoice == 2 && Enemychoice == 2)
			{
				printf("\n적의 빈틈에 독칼로 공격했습니다.\n");
				printf("산적 1은 중독에 걸렸습니다.\n");
				Enemy1.hp = Enemy1.hp - *basePOISONptr;
			}
			else if (selectCharacter == THIEF && playerchoice == 2 && Enemychoice == 3)
			{
				char THIEFMiss = 'a' + (rand() % 5);
				//2 vs 3 회피 c가 나온 경우 회피
				if (THIEFMiss == 'c') {
					printf("a ~ e 중 나온 알파벳 : %c\n", THIEFMiss);
					printf("\n산적1은 회피하였습니다,\n");
				}
				//2 vs 3 회피 c외에 나온 경우 강한공격력 그대로
				else if (THIEFMiss != 'c') {
					printf("a ~ e 중 나온 알파벳 : %c\n", THIEFMiss);
					printf("\n산적1은 회피에 실패했습니다,\n");
					printf("산적 1은 중독에 걸렸습니다.\n");
					Enemy1.hp = Enemy1.hp - *basePOISONptr;
				}
			}

			else if (selectCharacter == THIEF && playerchoice == 3 && Enemychoice == 1) {
				char THIEFMiss = 'a' + (rand() % 5);
				//3 vs 1 회피 c가 나온 경우 회피
				if (THIEFMiss == 'c') {
					printf("a ~ e 중 나온 알파벳 : %c\n", THIEFMiss);
					printf("\n도적은 회피하고 반격하였습니다,\n");
					Enemy1.hp = Enemy1.hp - *baseCTRptr;
				}
				//3 vs 1 회피 c외에 나온 경우 강한공격력 그대로
				else if (THIEFMiss != 'c') {
					printf("a ~ e 중 나온 알파벳 : %c\n", THIEFMiss);
					printf("\n도적은 회피에 실패했습니다,\n");
					*baseHPptr = *baseHPptr - Enemy1.atk;
				}
			}
			//3 vs 2 회피 방어 둘다 쫄아있다
			else if (selectCharacter == THIEF && playerchoice == 3 && Enemychoice == 2)
			{
				printf("아무 일도 일어나지 않았다.\n");
			}
			//3 vs 3 회피 회피 아무 일도 일어나지 않았다
			else if (selectCharacter == THIEF && playerchoice == 3 && Enemychoice == 3)
			{
				printf("서로 회피하고 난리다.\n");
			}
		}

		// 현재 체력 명시 코드
		if (playerchoice > 0 && playerchoice <= 3 && Enemychoice > 0 && Enemychoice <= 3)
		{
			if (selectCharacter == WARRIOR) {
				if (*baseHPptr == 30)
					printf("나의 체력 : ♥♥♥\n");
				else if (*baseHPptr > 20 && *baseHPptr < 30)
					printf("나의 체력 : ♥♥◐\n");
				else if (*baseHPptr == 20)
					printf("나의 체력 : ♥♥♡\n");
				else if (*baseHPptr > 10 && *baseHPptr < 20)
					printf("나의 체력 : ♥◐♡\n");
				else if (*baseHPptr == 10)
					printf("나의 체력 : ♥♡♡\n");
				else if (*baseHPptr > 0 && *baseHPptr < 10)
					printf("나의 체력 : ◐♡♡\n");
				else if (*baseHPptr <= 0)
					printf("나의 체력 : ♡♡♡\n");
			}

			if (selectCharacter == THIEF) {
				if (*baseHPptr == 20)
					printf("나의 체력 : ♥♥\n");
				else if (*baseHPptr > 10 && *baseHPptr < 20)
					printf("나의 체력 : ♥◐\n");
				else if (*baseHPptr == 10)
					printf("나의 체력 : ♥♡\n");
				else if (*baseHPptr > 0 && *baseHPptr < 10)
					printf("나의 체력 : ◐♡\n");
				else if (*baseHPptr <= 0)
					printf("나의 체력 : ♡♡\n");
			}

			if (Enemy1.hp == 30)
				printf("산적1의 체력 : ♥♥♥\n");
			else if (Enemy1.hp > 20 && Enemy1.hp < 30)
				printf("산적1의 체력 : ♥♥◐\n");
			else if (Enemy1.hp == 20)
				printf("산적1의 체력 : ♥♥♡\n");
			else if (Enemy1.hp > 10 && Enemy1.hp < 20)
				printf("산적1의 체력 : ♥◐♡\n");
			else if (Enemy1.hp == 10)
				printf("산적1의 체력 : ♥♡♡\n");
			else if (Enemy1.hp > 0 && Enemy1.hp < 10)
				printf("산적1의 체력 : ◐♡♡\n");
			else if (Enemy1.hp <= 0)
				printf("산적1의 체력 : ♡♡♡\n");
		}

		printf("-----------------------------------------------------------------\n");

		// 게임 결과 판정 -> 수정 필요
		if (baseHPptr <= 0 || baseHPptr <= 0) {
			printf("게임 오버! 플레이어가 패배했습니다.\n");
			break;     // Startbattle while반복문 탈출용
		}
		else if (baseHPptr > 0 && Enemy1.hp <= 0)
		{
			printf("승리했습니다! 적을 물리쳤습니다.\n");
			break;    // Startbattle while반복문 탈출용
		}
	}
}

// 스테이지 클리어 보상 
void StageReward(ENEMY Enemy1, int* baseHPptr, int* baseATKptr)
{
	if (Enemy1.hp <= 0 && *baseHPptr > 0); {
		int stagereward = 0;
		printf("스테이지 보상을 고르세요. \n");
		printf("1. 공격력 +4	2. 체력 회복 \n");
		scanf("%d", &stagereward);
		if (stagereward == 1)
		{
			*baseATKptr = *baseATKptr + 4;
			printf("공격력이 (%d)이(가) 되었습니다.\n", *baseATKptr);
		}
		else if (stagereward == 2)
		{
			*baseHPptr = *baseHPptr;
			printf("체력이 전부 회복되었습니다. 현재 체력 : (%d)\n", *baseHPptr);
		}
		else
		{
			printf("잘못된 입력입니다. 다시 입력하세요.\n");
		}
	}
}


	