
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 컴퓨터에게 명령을 내리기 위해서다. 
// 숫자만 읽을 수 있다. 
// 자료형 변수. 정수(1, 2, 4), 실수(4, 8)의 구분,몇 바이트씩 읽는가에 따라 타입 구분
// 메모리 안에 저장이 되어있다. 시작 주소를 알려주는 문법. 포인터.

 // 플레이어의 좌표 : int자료형 2개 저장할 수 있게 만들고 싶다.

typedef struct PlayerPos { // 구조체 안에 구조체를 정의하는 것은 불가능하다. 
	int x;
	int y;

}PlayerPos; // 변수선언x

typedef struct BattleEntity 
{
	int hp;
	int ad;
	int ap;
	int p_def;
	int m_def;
}BattleEntity;


typedef struct Player {
	PlayerPos pos;
	BattleEntity battleEntity;

	// 구조체. 
}Player;

// 포인터의 크기가 얼마인가요? 항상 8바이트

// Enemy 구조체 직접 선언
// Enemy 전투요소 추가

void PrintPos(PlayerPos p1);

int main()
{
	// 배열 : 같은 타입의 자료형을 배열을 사용해서 표현할 수 있다. 
	// 주소 한개로 어떻게 1 ~ n개까지 표현하는가
	// 배열을 포인터로 어떻게 설명할 수 있을까? 표현할 수 있을까?(상수 포인터)
	 
	// 구조체. 자료형 선언. 포인터. 배열. 
	
	// 구조체 
	// 사용자 정의 자료형 User Defined Type -> typedef 
	// x좌표 y좌표 

	printf("구조체 사용 이유 \n");
	int x = 0;
	int y = 0;

	PlayerPos p1 = { 10, 5}; // 초기화(Initialize)
	PrintPos(p1);

	Player player;
	PlayerPos startPos = { 0,0 };
	player.pos = startPos;
	BattleEntity battleEntity = { 1, 2, 3, 4, 5 }; // 구조체 안에서 순서대로 정의한 내용대로 대입
	player.battleEntity = battleEntity;

    printf("플레이어의 전투 요소 : %d, %d, %d, %d, %d", player.battleEntity.ad, player.battleEntity.ap, player.battleEntity.hp, player.battleEntity.m_def,
		player.battleEntity.p_def);

	// 플레이어 vs Enemy

	printf("구조체 포인터 사용 이유 \n");
	
	printf("구조체의 크기 : %d\n", sizeof(Player*)); // Player = 28바이트, Player* = 8바이트

	// 기능을 확장하기 위해서 player 구조체를 계속 추가한다. 예를 들어서 economy, battle, craft... -> 바이트 크기 증가 -> 과부하 발생의 원인(렉, 데이터 초과...)
	// 이를 위해 포인터로 하여 바이트 크기 줄이기.
}



// void Battle(Player player, Enemy enemy); 

void PrintPos(PlayerPos p1)
{
	printf("플레이어의 현재 위치 : [%d,%d]\n", p1.x, p1.y);
}