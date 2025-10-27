// 프로젝트 
// 로그라이크 모험 게임 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // 함수 사용을 위한 헤더
#include <time.h> // 컴퓨터 난수 설정을 위한 헤더

// 플레이어와 게임 상태를 관리하는 구조체

// 함수 선언
void StartBattle();
void Characterchoice();
int main() {
    char RestartChoice;
    int Characterchoice = 0;

    // 게임 재시작을 위한 while 루프
    while (1) {
        printf("==================================\n");
        printf("          로그라이크 모험게임\n");
        printf("==================================\n");

        StartBattle(); // 게임 시작
        Characterchoice(); E0109

        printf("게임을 다시 시작하시겠습니까? : (Y / N)  ");
        scanf(" %c", & RestartChoice);

        // 입력 버퍼 비우기 (다음 입력에 영향 없도록)
        int c;
        while ((c = getchar()) != '\n' && c != EOF); //EOF -> 파일의 끝 표시: 프로그램이 파일을 순차적으로 읽어나갈 때 더 이상 읽을 데이터가 없다는 것을 알려주는 역할
                                                                                // != 같지 않다.

        // 'y'나 'Y'가 아니면 루프 종료
        if (RestartChoice != 'y' && RestartChoice != 'Y') {
            break;
        }
    }

    printf("\n게임을 종료합니다. 감사합니다!\n");
    return 0;
}


// 모험을 시작합니다!
// 깊은 숲을 헤쳐나가세요.
// 캐릭터를 선택하시오. 
// 전사 = 1, 도적 = 2를 누르세요 
// 전사
// 공격 = 1, 강한 공격 = 2,  방어 = 3
// 도적
// 공격 = 1, 독칼 공격 = 2, 회피 = 3

// 캐릭터 선택 함수
void Characterchoice(){
printf("철수 =1, 영희 = 2를 누르세요 : \n");
scanf("%d", &Characterchoice);

if (Characterchoice == 1)
{
    printf(" 당신은 철수입니다. 체력 ♥♥♥(30) 공격력 10\n\n");
   
}
else if (Characterchoice == 2)
{
    printf(" 당신은 영희입니다. 체력 ♥♥(20) 공격력 15\n\n");
    
}
else
{
    printf(" 1 또는 2 를 입력해주세요.\n\n");
}
    }






void StartBattle() {
    int Characterchoice = 0;
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
    int playerTurn = 1; // 플레이어 차례
    int playerchoice = 0; // 플레이어 가위 바위 보 선택사항
    int Enemychoice = 0; // 적 가위 바위 보 선택사항
    srand(time(NULL)); // 난수 생성기 초기화 srand(time(NULL));를 매 턴에서 호출하면 같은 초 안에 입력하면 같은 난수가 나올 수 있습니다. 게임 시작 전에 한 번만 호출


    //캐릭터 선택에 따른 체력 및 공격력 명시
    if (Characterchoice == 1)
    {
        printf(" 당신은 전사입니다. 체력 ♥♥♥(%d) 공격력 %d, \n\n", player1Healthpoint, player1Attack);

    }
    else if (Characterchoice == 2)
    {
        printf(" 당신은 도적입니다. 체력 ♥♥(%d) 공격력 %d, \n\n", player2Healthpoint, player2Attack);

    }


    // 전투를 위한 while 루프
    while (player1Healthpoint > 0 || player2Healthpoint  > 0 && Enemy1Healthpoint > 0) {
        printf("산적1이 나타났다!\n");
        // stage 1  적1 체력 ♥♥♥ 공격력 10
        printf("스테이지 1 시작!\n");
        printf("적 체력 ♥♥♥(30) 공격력 10\n");
        // 전사, 도적 선택에 맞춰 행동 선택사항 출력코드 
        if (Characterchoice == 1) {
            printf("공격(1) 강한 공격(2) 방어(3) 중 해당 숫자를 입력하세요 : ");
            scanf("%d", &playerchoice);
        }
        else if (Characterchoice == 2)
        {
            printf("공격(1) 독칼 공격(2) 회피(3) 중 해당 숫자를 입력하세요 :  ");
            scanf("%d", &playerchoice);
        }
      
        //적 난수 생성
        int Enemychoice = rand() % 3 + 1; // 1~3 사이의 난수 생성 (1 = 공격, 2 = 방어, 3 = 회피)
        printf("적의 선택: %d\n\n", Enemychoice); // 변수를 computerchoice로 하였을 때 재정의되지 않고 출력이 됌!!

        // 플레이어 공격, 강한 공격, 독칼, 방어, 회피 vs 적의 공격, 방어, 아무것도 못함에 대한 계산 
        if (Characterchoice == 1 && playerchoice <= 0 || playerchoice > 3)
        {
            printf("잘못 입력하였습니다.\n\n");
        }
        else if (Characterchoice == 1 && playerchoice == 1)
        {
            printf("비겼습니다.\n\n");
        }
        else if (Characterchoice == 1 || (playerchoice == 1 && Enemychoice == 3) || (playerchoice == 2 && Enemychoice == 1) || (playerchoice == 3 && Enemychoice == 2))
        {
            if (Characterchoice == 1) {
                printf("공격했습니다.\n\n");
                Enemy1Healthpoint = Enemy1Healthpoint - player1Attack;
            }
        }
        else
        {
            printf("패배했습니다.\n\n");
            player1Healthpoint = player1Healthpoint - Enemy1Attack;
            player2Healthpoint = player2Healthpoint - Enemy1Attack;
        }
    }
    printf("----------------------------------\n");

    // 게임 결과 판정
    if (player1Healthpoint <= 0 || player2Healthpoint <= 0) {
        printf("게임 오버! 플레이어가 패배했습니다.\n");
    }
    else {
        printf("승리했습니다! 적을 물리쳤습니다.\n");
    }
}

// 3 스테이지 구성 (스테이지 1, 스테이지 2, 보스)
// 배경 : 깊은 숲 속
// 각 스테이지 클리어 시 체력 전부 회복 공격력 0.4 증가템,  
// 스테이지1 클리어 시 스테이지 1 클리어, 스테이지 2 클리어, 보스를 물리쳤습니다. -> 게임 끝과 함께 프로그램 종료
// 전사, 도적 체력이 0이 되면 다시 캐릭터 선택부터 시작

// 캐릭터 정보
// 전사의 체력 = ♡♡♡, 30 공격력 10
// 도적의 체력 = ♡♡, 20 공격력 15
// 산적1 = ♡♡♡, 30 공격력 10
// 산적2 = ♡♡♡, 20 공격력 14
// 산적 보스 = ♡♡♡♡, 40 공격력 20 방어력 5 , 체력 20 이하일 때 페이즈 2 : 방어력 7.5로 up  
// 게임 내 최대체력 ♡♡♡♡가 최대
// 체력 표시 ♥, 데미지를 입은 체력 ♡, 반 체력 ◐ 

// 게임 흐름 
// 공격: 공격력만큼 데미지를 준다
// 강한 공격: 1.5배만큼 데미지를 준다, 강한 공격은 충전 필요 2턴에 한번 사용 가능 
// 독칼 공격:  공격력의 절반데미지 + 중독 부여 매턴 시작 시 1.5씩 데미지를 준다. 
// 회피: 공격을 피할 확률 12.5% 확률
// 방어: 4만큼 방어
// 스테이지 끝날 시 보상  1. 공격력 증가템 or 2. 체력 회복 요소(full 회복)
// 게임오버 playerHealthpoint = 0이면 다시 게임 캐릭터 선택으로 돌아감.
// 게임종료 = Esc or p 버튼
// 공격 vs 방어일때 방어 선택자 데미지 = 방어력 - 공격력
// 회피율 플레이어 20%
// 회피율 적 10%  

// 추가 요소 
// 스테이지 클리어 후 경로 2가지 중 하나 택일 왼쪽 = 1, 오른쪽 = 2 을 누르세요
// 상태이상 요소, 실명 -> 빗나감, 출혈 -> 0.1 승패 1번에 데미지 줌
// 스테이지 클리어 후 체력 풀회복, 아이템 선택창 만들기(아이템 공격력 증가 or 방어력 증가)    

// 체력에 대한 표현을 변수로 대체하여 표현 ex) healthpoint == 30 -> 30을 변수로 대체

