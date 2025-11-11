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

void StartBattle(JOB selectCharacter, int* baseHPptr, int* baseATKptr, int* baseDEFptr, int* baseCTRptr, int* basePOISONptr)
{
	srand(time(NULL)); // 난수 생성기 초기화 srand(time(NULL));를 매 턴에서 호출하면 같은 초 안에 입력하면 같은 난수가 나올 수 있습니다. 게임 시작 전에 한 번만 호출
	ENEMY Enemy1 = { 30, 10, 5 };  // 산적1 스탯정리, 구조체 호출

	int playerchoice = 0; // 플레이어 가위 바위 보 선택사항
	int Enemychoice = 0; // 적 가위 바위 보 선택사항

	printf("스테이지 1 시작!\n");
	printf("산적1이 나타났다!\n");
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
		
		//if (Enemychoice == 1)
		//{
		//	printf("산적1은 공격을 선택했습니다.");
		//}
		//else if (Enemychoice == 2)
		//{
		//	printf("산적1은 방어를 선택했습니다.");
		//}
		//else if (Enemychoice == 3)
		//{
		//	printf("산적1은 회피를 선택했습니다.");
		//}



		// 플레이어 공격, 강한 공격, 독칼, 방어, 회피 vs 적의 공격, 방어, 회피에 대한 계산 
		if (playerchoice <= 0 || playerchoice > 3)
		{
			printf("잘못 입력하였습니다.\n\n");
		}
		else if (Enemychoice == 1 && playerchoice == 1) // 공격 vs 공격 
		{
			printf("서로 공격하여 비겼습니다.\n\n");
		}
		else if ((playerchoice == 1 && Enemychoice == 3) || (playerchoice == 1 && Enemychoice == 2)) // 공격 vs 회피 or 공격 vs 방어
		{
			printf("공격했습니다.\n\n");
			if (Enemychoice == 3) {
				int EnemyMiss = 'a' + (rand() % 8);   // 12.5% 회피율
				printf("%c\n", Enemychoice);

				if (EnemyMiss == 'c')
				{
					printf("산적1이 공격을 회피를 선택했습니다.\n\n");
				}
				else
				{
					printf("산적1 회피 실패...\n\n");
					Enemy1.hp = Enemy1.hp - *baseATKptr; // 적 회피 실패 시 체력 계산
				}
			}

			Enemy1.hp = Enemy1.hp + Enemy1.def - *baseATKptr; // 적 방어 시 체력 계산
		}
		else if ((selectCharacter == WARRIOR && playerchoice == 2 && Enemychoice == 3) || (playerchoice == 2 && Enemychoice == 1)) // 전사인 경우 2번 강공격 선택  vs 방어 or 회피
		{
			printf("강하게 공격했습니다.\n\n");
			Enemy1.hp = Enemy1.hp - *baseATKptr * 1.5; // 강공격에 대한 계산
			if (Enemychoice == 3) {
				int EnemyMiss = 'a' + (rand() % 8);   // 12.5% 회피율
				printf("%c\n", EnemyMiss);

				if (EnemyMiss == 'c')
				{
					printf("산적1이 공격을 회피를 선택했습니다.\n\n");
				}
				else
				{
					printf("산적1 회피 실패...\n\n");
					Enemy1.hp = Enemy1.hp - *baseATKptr * 1.5; // 적 회피 실패 시 체력 계산
				}
			}
			else if (selectCharacter == WARRIOR && playerchoice == 2 && Enemychoice == 2)
			{
				printf("둘 다 방어만 하면서 쫄아 있다...\n");
			}
			else if (selectCharacter == THIEF && playerchoice == 3 && Enemychoice == 1) // 적 공격 선택과 도적 회피반격 누른 경우
			{
				//char Evasion[] = {'a', 'b', 'c', 'd', 'e'}; // a b c d e 랜덤 뽑기 , c 가 나오는 경우 회피 나머지 꽝
				//Evasion[rand() % 5];
				//printf("%c\n", &Evasion);
				int playerMiss = 'a' + (rand() % 5);   // char 대신 int에 저장
				printf("%c\n", playerMiss);

				if (playerMiss == 'c')
				{
					printf("회피 성공!! 반격하였습니다.\n\n");
					Enemy1.hp = Enemy1.hp - *baseCTRptr;
				}
				else
				{
					printf("꽝 ㅠ . ㅠ 회피 실패...\n\n");
					*baseHPptr = *baseHPptr - Enemy1.atk;
				}
			}
			else if (selectCharacter == THIEF && playerchoice == 2 && Enemychoice == 1 || Enemychoice == 2 && Enemychoice == 2)
			{
				printf("적을 중독시켰습니다.");
				Enemy1.hp = Enemy1.hp - 5;
			}
			else if (selectCharacter == THIEF && playerchoice == 3 && Enemychoice == 3)
			{
				int playerMiss = 'a' + (rand() % 5);   // char 대신 int에 저장
				printf("%c\n", playerMiss);
				int EnemyMiss = 'a' + (rand() % 8);   // 12.5% 회피율
				printf("%c\n", EnemyMiss);

				if (playerMiss == 'c' && EnemyMiss != 'c')
				{
					printf("회피 성공!! 반격하였습니다.\n\n");
					Enemy1.hp = Enemy1.hp - *baseCTRptr;
				}
				else
				{
					printf("둘 다 회피할려고 발악 중이다...\n\n");
				}
			}
			else
			{
				printf("공격 당했습니다.\n\n");
				*baseHPptr = *baseHPptr - Enemy1.atk;
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

		//void StageReward(int* baseHPptr);
		//{

		//}
	}